#include "stdafx.h"

//static CDXEngine* g_pD3DApp = NULL;

CDXEngine::CDXEngine()
{
	m_wScreenWidth		= 1024;
	m_wScreenHeight		= 768;

//	g_pD3DApp			= this;
	m_pD3D              = NULL;
    m_pd3dDevice        = NULL;
    m_hWnd              = NULL;

	m_pTexRenderTarget	= NULL;
	m_pSurRenderTarget	= NULL;
	m_pSurBaseRenderTarget = NULL;

	m_bDisplayMode		= DX_WINDOWS;
// 	m_bDisplayMode		= DX_FULLSCREEN;

	m_strWindowTitle    = _T("D3D9 Application");

	ZeroMemory(m_rtFlip, sizeof(m_rtFlip) );

	m_d3dEnumeration.AppUsesDepthBuffer = true;
}
CDXEngine::~CDXEngine()
{
	DeleteAll();
}

VOID CDXEngine::DeleteAll()
{
	SAFE_RELEASE( m_pTexRenderTarget );
	SAFE_RELEASE( m_pSurRenderTarget );
	SAFE_RELEASE( m_pSurBaseRenderTarget );

	SAFE_RELEASE( m_pd3dDevice );
	SAFE_RELEASE( m_pD3D );
}


//-----------------------------------------------------------------------------
// Name: ConfirmDeviceHelper()
// Desc: Static function used by D3DEnumeration
//-----------------------------------------------------------------------------
bool CDXEngine::ConfirmDeviceHelper( D3DCAPS9* pCaps, VertexProcessingType vertexProcessingType, 
                         D3DFORMAT adapterFormat, D3DFORMAT backBufferFormat )
{
    DWORD dwBehavior;

    if (vertexProcessingType == SOFTWARE_VP)
        dwBehavior = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    else if (vertexProcessingType == MIXED_VP)
        dwBehavior = D3DCREATE_MIXED_VERTEXPROCESSING;
    else if (vertexProcessingType == HARDWARE_VP)
        dwBehavior = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    else if (vertexProcessingType == PURE_HARDWARE_VP)
        dwBehavior = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;
    else
        dwBehavior = 0; // TODO: throw exception
    
//    return SUCCEEDED( g_pD3DApp->ConfirmDevice( pCaps, dwBehavior, adapterFormat, backBufferFormat ) );
	return true;
}


//-----------------------------------------------------------------------------
// Name: CreateDXEngine()
// Desc: DirectX
//-----------------------------------------------------------------------------
HRESULT CDXEngine::CreateDXEngine( HWND hWnd, WORD wWidth, WORD wHeigth, BYTE bDisplayMode )
{
	HRESULT hr = NULL;

	m_hWnd			= hWnd;
	m_wScreenWidth  = wWidth;
	m_wScreenHeight = wHeigth;
	m_bDisplayMode  = bDisplayMode;

	// Create the Direct3D object
    m_pD3D = Direct3DCreate9( D3D_SDK_VERSION );
    if( m_pD3D == NULL )
      return DisplayErrorMsg( D3DAPPERR_NODIRECT3D, MSGERR_APPMUSTEXIT );

	// Build a list of Direct3D adapters, modes and devices. The
    // ConfirmDevice() callback is used to confirm that only devices that
    // meet the app's requirements are considered.
    m_d3dEnumeration.SetD3D( m_pD3D );
	m_d3dEnumeration.ConfirmDeviceCallback = ConfirmDeviceHelper;
	if( FAILED( hr = m_d3dEnumeration.Enumerate() ) )
    {
        SAFE_RELEASE( m_pD3D );
        return DisplayErrorMsg( hr, MSGERR_APPMUSTEXIT );
    }

	GetClientRect( m_hWnd, &m_rcWindowClient );

	if( FAILED( hr = ChooseInitialD3DSettings() ) )
    {
        SAFE_RELEASE( m_pD3D );
        return DisplayErrorMsg( hr, MSGERR_APPMUSTEXIT );
    }

	// Initialize the 3D environment for the app
    if( FAILED( hr = Initialize3DEnvironment() ) )
    {
        SAFE_RELEASE( m_pD3D );
        return DisplayErrorMsg( hr, MSGERR_APPMUSTEXIT );
    }

	return S_OK;
}


bool CDXEngine::FindBestWindowedMode( bool bRequireHAL, bool bRequireREF )
{
	// Get display mode of primary adapter (which is assumed to be where the window 
    // will appear)
    D3DDISPLAYMODE primaryDesktopDisplayMode;
    m_pD3D->GetAdapterDisplayMode(0, &primaryDesktopDisplayMode);

	 for( UINT iai = 0; iai < m_d3dEnumeration.m_pAdapterInfoList->Count(); iai++ )
    {
        D3DAdapterInfo* pAdapterInfo = (D3DAdapterInfo*)m_d3dEnumeration.m_pAdapterInfoList->GetPtr(iai);

        for( UINT idi = 0; idi < pAdapterInfo->pDeviceInfoList->Count(); idi++ )
        {
            D3DDeviceInfo* pDeviceInfo = (D3DDeviceInfo*)pAdapterInfo->pDeviceInfoList->GetPtr(idi);

            if (bRequireHAL && pDeviceInfo->DevType != D3DDEVTYPE_HAL)
                continue;

            if (bRequireREF && pDeviceInfo->DevType != D3DDEVTYPE_REF)
                continue;

            for( UINT idc = 0; idc < pDeviceInfo->pDeviceComboList->Count(); idc++ )
            {
                D3DDeviceCombo* pDeviceCombo = (D3DDeviceCombo*)pDeviceInfo->pDeviceComboList->GetPtr(idc);
                bool bAdapterMatchesBB = (pDeviceCombo->BackBufferFormat == pDeviceCombo->AdapterFormat);

                if (!pDeviceCombo->IsWindowed)
                    continue;

                if (pDeviceCombo->AdapterFormat != primaryDesktopDisplayMode.Format)
                    continue;

                // If we haven't found a compatible DeviceCombo yet, or if this set
                // is better (because it's a HAL, and/or because formats match better),
                // save it
                if( m_d3dDisplayInfo.pDeviceCombo == NULL || 
                    m_d3dDisplayInfo.pDeviceCombo->DevType != D3DDEVTYPE_HAL && pDeviceCombo->DevType == D3DDEVTYPE_HAL ||
                    pDeviceCombo->DevType == D3DDEVTYPE_HAL && bAdapterMatchesBB )
                {
					m_d3dDisplayInfo.pAdapterInfo	= pAdapterInfo;
					m_d3dDisplayInfo.pDeviceInfo	= pDeviceInfo;
					m_d3dDisplayInfo.pDeviceCombo	= pDeviceCombo;

                    if( pDeviceCombo->DevType == D3DDEVTYPE_HAL && bAdapterMatchesBB )
                    {
                        // This windowed device combo looks great -- take it
                        goto EndWindowedDeviceComboSearch;
                    }
                    // Otherwise keep looking for a better windowed device combo
                }
            }
        }
    }
EndWindowedDeviceComboSearch:
    if ( m_d3dDisplayInfo.pDeviceCombo == NULL )
        return false;

//    primaryDesktopDisplayMode.Format = D3DFMT_A8R8G8B8;
	m_d3dDisplayInfo.primaryDesktopDisplayMode	= primaryDesktopDisplayMode;
	m_d3dDisplayInfo.WindowWidth				= m_wScreenWidth;
	m_d3dDisplayInfo.WindowHeight				= m_wScreenHeight;
												 
	m_d3dDisplayInfo.DepthStencilBufferFormat	= FindDepthFormat_D3D(m_d3dDisplayInfo.pDeviceCombo->AdapterOrdinal, primaryDesktopDisplayMode.Format, 0);//*(D3DFORMAT*)m_d3dDisplayInfo.pDeviceCombo->pDepthStencilFormatList->GetPtr(0);
	m_d3dDisplayInfo.Windowed_MultisampleType	= *(D3DMULTISAMPLE_TYPE*)m_d3dDisplayInfo.pDeviceCombo->pMultiSampleTypeList->GetPtr(0);
	m_d3dDisplayInfo.Windowed_MultisampleQuality = 0;
	m_d3dDisplayInfo.Windowed_VertexProcessingType = *(VertexProcessingType*)m_d3dDisplayInfo.pDeviceCombo->pVertexProcessingTypeList->GetPtr(0);
	m_d3dDisplayInfo.Windowed_PresentInterval	= *(UINT*)m_d3dDisplayInfo.pDeviceCombo->pPresentIntervalList->GetPtr(0);

	return true;
}


//--------------------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------------------
D3DFORMAT CDXEngine::FindDepthFormat_D3D( INT nAdapter, D3DFORMAT d3dfColor, INT nDepthBits )
{
	if ( nDepthBits == 0 ) {
		if ( d3dfColor == D3DFMT_X8R8G8B8 || d3dfColor == D3DFMT_A8R8G8B8) nDepthBits = 32;
		else nDepthBits = 16;
	}

	INT nCnt = 7;
	static D3DFORMAT ad3df16BitsTable[] = { D3DFMT_D16,   D3DFMT_D15S1, D3DFMT_D16_LOCKABLE, D3DFMT_D32,     D3DFMT_D24X8, D3DFMT_D24S8, D3DFMT_D24X4S4      };
	static D3DFORMAT ad3df24BitsTable[] = { D3DFMT_D24X8, D3DFMT_D24S8, D3DFMT_D24X4S4,      D3DFMT_D32,     D3DFMT_D16,   D3DFMT_D15S1, D3DFMT_D16_LOCKABLE };
	static D3DFORMAT ad3df32BitsTable[] = { D3DFMT_D32,   D3DFMT_D24X8, D3DFMT_D24S8,        D3DFMT_D24X4S4, D3DFMT_D16,   D3DFMT_D15S1, D3DFMT_D16_LOCKABLE };

	D3DFORMAT *pd3dfDepthTable = &ad3df32BitsTable[0];
	if ( nDepthBits < 21 ) pd3dfDepthTable = &ad3df16BitsTable[0];
	else if( nDepthBits < 28) pd3dfDepthTable = &ad3df24BitsTable[0];

	for( INT i = 0; i < 7; ++i)
	{
		D3DFORMAT d3dfDepth = pd3dfDepthTable[i];

		HRESULT hr = m_pD3D->CheckDeviceFormat( 0, m_d3dDisplayInfo.pDeviceInfo->DevType, d3dfColor, D3DUSAGE_DEPTHSTENCIL, D3DRTYPE_SURFACE, d3dfDepth );
		if ( hr != D3D_OK ) continue;

		hr = m_pD3D->CheckDepthStencilMatch( 0, m_d3dDisplayInfo.pDeviceInfo->DevType, d3dfColor, d3dfColor, d3dfDepth );
		if ( hr == D3D_OK ) return d3dfDepth;
	} 

	return D3DFMT_UNKNOWN; 
}


//-----------------------------------------------------------------------------
// Name: ChooseInitialD3DSettings()
// Desc: 
//-----------------------------------------------------------------------------
HRESULT CDXEngine::ChooseInitialD3DSettings()
{
	//bool bFoundFullscreen = FindBestFullscreenMode( false, false );
    bool bFoundWindowed = FindBestWindowedMode( false, false );

    //if( !bFoundFullscreen && !bFoundWindowed )
	if( !bFoundWindowed )
        return D3DAPPERR_NOCOMPATIBLEDEVICES;

    return S_OK;
}


HRESULT CDXEngine::Initialize3DEnvironment()
{
	HRESULT hr;

    D3DAdapterInfo* pAdapterInfo = m_d3dDisplayInfo.pAdapterInfo;
    D3DDeviceInfo* pDeviceInfo = m_d3dDisplayInfo.pDeviceInfo;

	BuildPresentParamsFromSettings();

	if( pDeviceInfo->Caps.PrimitiveMiscCaps & D3DPMISCCAPS_NULLREFERENCE )
    {
        // Warn user about null ref device that can't render anything
        DisplayErrorMsg( D3DAPPERR_NULLREFDEVICE, 0 );
    }

	DWORD behaviorFlags;
    if (m_d3dDisplayInfo.Windowed_VertexProcessingType == SOFTWARE_VP)
        behaviorFlags = D3DCREATE_SOFTWARE_VERTEXPROCESSING;
    else if (m_d3dDisplayInfo.Windowed_VertexProcessingType == MIXED_VP)
        behaviorFlags = D3DCREATE_MIXED_VERTEXPROCESSING;
    else if (m_d3dDisplayInfo.Windowed_VertexProcessingType == HARDWARE_VP)
        behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING;
    else if (m_d3dDisplayInfo.Windowed_VertexProcessingType == PURE_HARDWARE_VP)
        behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;
    else
        behaviorFlags = 0; // TODO: throw exception

   // behaviorFlags = D3DCREATE_MIXED_VERTEXPROCESSING;

#ifndef _DEBUG_VS_
	// D3DXCreateEffectFromFile(...) 
	// Vertext Shader : D3DXSHADER_FORCE_VS_SOFTWARE_NOOPT, Pixel Shader : D3DXSHADER_FORCE_PS_SOFTWARE_NOOPT
	behaviorFlags = D3DCREATE_HARDWARE_VERTEXPROCESSING | D3DCREATE_PUREDEVICE;
#endif

#ifdef _DEBUG_PS_
	// Pixel Shader : Referance Device
	pDeviceInfo->DevType = D3DDEVTYPE_REF;
#endif
	//m_d3dDisplayInfo.pDeviceCombo->AdapterOrdinal

	// Create the device
    hr = m_pD3D->CreateDevice( m_d3dDisplayInfo.pDeviceCombo->AdapterOrdinal, pDeviceInfo->DevType,
                               m_hWnd, behaviorFlags, &m_d3dpp,
                               &m_pd3dDevice );

	if( SUCCEEDED(hr) )
	{
		// Store device Caps
		m_pd3dDevice->GetDeviceCaps( &m_d3dCaps );
		m_dwCreateFlags = behaviorFlags;

		m_pd3dDevice->SetDialogBoxMode(TRUE);

		// Store render target surface desc
		LPDIRECT3DSURFACE9 pBackBuffer = NULL;
		m_pd3dDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer );
		pBackBuffer->GetDesc( &m_d3dsdBackBuffer );
		pBackBuffer->Release();

		//// Render Target 
		//if ( FAILED( D3DXCreateTexture(m_pd3dDevice, m_d3dDisplayInfo.WindowWidth, m_d3dDisplayInfo.WindowHeight, 0, D3DUSAGE_RENDERTARGET, D3DFMT_A32B32G32R32F, D3DPOOL_DEFAULT, &m_pTexRenderTarget ) ) )
		//	D3DXCreateTexture(m_pd3dDevice, m_d3dDisplayInfo.WindowWidth, m_d3dDisplayInfo.WindowHeight, 0, D3DUSAGE_RENDERTARGET, m_d3dDisplayInfo.pDeviceCombo->AdapterFormat, D3DPOOL_DEFAULT, &m_pTexRenderTarget );

		//m_pTexRenderTarget->GetSurfaceLevel( 0, &m_pSurRenderTarget );

		return S_OK;
	}

	return hr;
}


void CDXEngine::BuildPresentParamsFromSettings()
{
	m_d3dpp.Windowed               = ( m_bDisplayMode & DX_WINDOWS );
    m_d3dpp.BackBufferCount        = 1;
    m_d3dpp.MultiSampleType        = m_d3dDisplayInfo.Windowed_MultisampleType;
    m_d3dpp.MultiSampleQuality     = m_d3dDisplayInfo.Windowed_MultisampleQuality;
    m_d3dpp.SwapEffect             = D3DSWAPEFFECT_DISCARD; //D3DSWAPEFFECT_COPY;

	m_d3dpp.EnableAutoDepthStencil = m_d3dEnumeration.AppUsesDepthBuffer;
    m_d3dpp.hDeviceWindow          = m_hWnd;

	if( m_d3dEnumeration.AppUsesDepthBuffer )
	{
		m_d3dpp.Flags = D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL | D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;
        m_d3dpp.AutoDepthStencilFormat = m_d3dDisplayInfo.DepthStencilBufferFormat;
    }
    else
        m_d3dpp.Flags              = 0;

	m_d3dpp.BackBufferWidth  = m_d3dDisplayInfo.WindowWidth;
    m_d3dpp.BackBufferHeight = m_d3dDisplayInfo.WindowHeight;
    m_d3dpp.BackBufferFormat = m_d3dDisplayInfo.pDeviceCombo->BackBufferFormat;
    m_d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;

	if ( m_bDisplayMode & DX_WINDOWS ) m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
	//else							   m_d3dpp.PresentationInterval = m_d3dDisplayInfo.Windowed_PresentInterval;
	else m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	//m_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;
}


void CDXEngine::SetPosTrans()
{
	GetClientRect(m_hWnd, &m_rcWindowClient);
	ClientToScreen(m_hWnd, (LPPOINT)&m_rcWindowClient);
	ClientToScreen(m_hWnd, (LPPOINT)&m_rcWindowClient+1);
}


void CDXEngine::SetFlipRgn(RECT* rtFlip)
{
	memcpy(m_rtFlip, rtFlip, sizeof(m_rtFlip) );
}


void CDXEngine::SetFlipRect(RECT rtFlip, INT nIdx)
{
	memcpy(&m_rtFlip[nIdx], &rtFlip, sizeof(rtFlip) );
}


void CDXEngine::Flip()
{
	//RECT SouRect, DesRect, FlipRect;
	RECT DesRect, FlipRect;
	HRESULT hResult = NULL;

	for (int i = 0; i < 5; i++)
	{
		if ( ( (m_rtFlip[i].right - m_rtFlip[i].left) > 0 ) && ( (m_rtFlip[i].bottom - m_rtFlip[i].top) > 0 ) )
			CopyRect(&FlipRect, &m_rtFlip[i]);
		else
			continue;

		DesRect.left   = m_rcWindowClient.left + FlipRect.left;
		DesRect.top    = m_rcWindowClient.top  + FlipRect.top;
		DesRect.right  = DesRect.left + (FlipRect.right  - FlipRect.left);
		DesRect.bottom = DesRect.top  + (FlipRect.bottom - FlipRect.top);

		hResult = m_pd3dDevice->Present( &DesRect, &FlipRect, NULL, NULL );
	}
}

LPDIRECT3DSURFACE9 CDXEngine::GetBackSurface()
{
	LPDIRECT3DSURFACE9 pBackBuffer = NULL;
	HRESULT hRet = m_pd3dDevice->GetBackBuffer( 0, 0, D3DBACKBUFFER_TYPE_MONO, &pBackBuffer );
	return pBackBuffer;
}


//--------------------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------------------
VOID CDXEngine::ChangeRenderTarget( BOOL fClear )
{
	m_pd3dDevice->GetRenderTarget( 0, &m_pSurBaseRenderTarget );

	m_pd3dDevice->SetRenderTarget( 0, m_pSurRenderTarget );
	if ( fClear ) m_pd3dDevice->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB( 255, 255, 255 ), 1.0f, 0L );
}


//--------------------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------------------
VOID CDXEngine::RestoreRenderTarget( VOID )
{
	m_pd3dDevice->SetRenderTarget( 0, m_pSurBaseRenderTarget );
	SAFE_RELEASE( m_pSurBaseRenderTarget );
}


//--------------------------------------------------------------------------------------------------
// 
//--------------------------------------------------------------------------------------------------
HRESULT CDXEngine::ValidateDevice( VOID )
{
	HRESULT hr;

	if ( FAILED( hr = m_pd3dDevice->TestCooperativeLevel() ) )
	{
		if ( hr == D3DERR_DEVICELOST ) return E_FAIL;	// Alt + Tab 
			

		if ( hr == D3DERR_DEVICENOTRESET )	// Alt + Tab
		{
			m_pfLostDevice();

			if ( FAILED( hr = m_pd3dDevice->Reset( &m_d3dpp ) ) ) return E_FAIL;

			m_pfResetDevice();
		}
	}

	return S_OK;	
}


//--------------------------------------------------------------------------------------------------
// Desc : Toggle Screen Mode ( Window or FullScreen )
//--------------------------------------------------------------------------------------------------
HRESULT CDXEngine::ToggleScreenMode( VOID )
{
	// Get the rect of the window
	m_bDisplayMode = ( m_bDisplayMode == DX_WINDOWS ) ? DX_FULLSCREEN : DX_WINDOWS;

	if ( m_bDisplayMode == DX_WINDOWS )
	{
		SetWindowLong( m_hWnd, GWL_EXSTYLE, WS_EX_WINDOWEDGE );
		SetWindowLong( m_hWnd, GWL_STYLE,   WS_CAPTION | WS_POPUP | WS_CLIPCHILDREN );

		DWORD dwXpos = (GetSystemMetrics(SM_CXSCREEN) - m_wScreenWidth) / 2;
		DWORD dwYpos = (GetSystemMetrics(SM_CYSCREEN) - m_wScreenHeight + GetSystemMetrics( SM_CYSIZE ) ) / 2;

		SetWindowPos( m_hWnd, HWND_NOTOPMOST, dwXpos, dwYpos,
			m_wScreenWidth + (GetSystemMetrics( SM_CXEDGE ) * 2) + 2,
			m_wScreenHeight + GetSystemMetrics( SM_CYSIZE ) + (GetSystemMetrics( SM_CYEDGE ) * 4) - 1, SWP_FRAMECHANGED | SWP_SHOWWINDOW );
	}
	else
	{
		SetWindowLong( m_hWnd, GWL_STYLE, WS_POPUP | WS_CLIPCHILDREN | WS_VISIBLE );
		SetWindowPos( m_hWnd, HWND_TOP, 0, 0, m_wScreenWidth, m_wScreenHeight, SWP_FRAMECHANGED | SWP_SHOWWINDOW );
	}

	BuildPresentParamsFromSettings();

	m_pfLostDevice();

	if(FAILED(m_pd3dDevice->Reset(&m_d3dpp))) return E_FAIL;

	m_pfResetDevice();

	return S_OK;
}

//-----------------------------------------------------------------------------
// Name: DisplayErrorMsg()
// Desc: Displays error messages in a message box
//-----------------------------------------------------------------------------
HRESULT CDXEngine::DisplayErrorMsg( HRESULT hr, DWORD dwType )
{
    static bool s_bFatalErrorReported = false;
    TCHAR strMsg[512];

    // If a fatal error message has already been reported, the app
    // is already shutting down, so don't show more error messages.
    if( s_bFatalErrorReported )
        return hr;

    switch( hr )
    {
        case D3DAPPERR_NODIRECT3D:
            _tcscpy( strMsg, _T("Could not initialize Direct3D. You may\n")
                             _T("want to check that the latest version of\n")
                             _T("DirectX is correctly installed on your\n")
                             _T("system.  Also make sure that this program\n")
                             _T("was compiled with header files that match\n")
                             _T("the installed DirectX DLLs.") );
            break;

        case D3DAPPERR_NOCOMPATIBLEDEVICES:
            _tcscpy( strMsg, _T("Could not find any compatible Direct3D\n")
                             _T("devices.") );
            break;

        case D3DAPPERR_NOWINDOWABLEDEVICES:
            _tcscpy( strMsg, _T("This sample cannot run in a desktop\n")
                             _T("window with the current display settings.\n")
                             _T("Please change your desktop settings to a\n")
                             _T("16- or 32-bit display mode and re-run this\n")
                             _T("sample.") );
            break;

        case D3DAPPERR_NOHARDWAREDEVICE:
            _tcscpy( strMsg, _T("No hardware-accelerated Direct3D devices\n")
                             _T("were found.") );
            break;

        case D3DAPPERR_HALNOTCOMPATIBLE:
            _tcscpy( strMsg, _T("This sample requires functionality that is\n")
                             _T("not available on your Direct3D hardware\n")
                             _T("accelerator.") );
            break;

        case D3DAPPERR_NOWINDOWEDHAL:
            _tcscpy( strMsg, _T("Your Direct3D hardware accelerator cannot\n")
                             _T("render into a window.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_NODESKTOPHAL:
            _tcscpy( strMsg, _T("Your Direct3D hardware accelerator cannot\n")
                             _T("render into a window with the current\n")
                             _T("desktop display settings.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_NOHALTHISMODE:
            _tcscpy( strMsg, _T("This sample requires functionality that is\n")
                             _T("not available on your Direct3D hardware\n")
                             _T("accelerator with the current desktop display\n")
                             _T("settings.\n")
                             _T("Press F2 while the app is running to see a\n")
                             _T("list of available devices and modes.") );
            break;

        case D3DAPPERR_MEDIANOTFOUND:
        //case HRESULT_FROM_WIN32( ERROR_FILE_NOT_FOUND ):
            _tcscpy( strMsg, _T("Could not load required media." ) );
            break;

        case D3DAPPERR_RESETFAILED:
            _tcscpy( strMsg, _T("Could not reset the Direct3D device." ) );
            break;

        case D3DAPPERR_NONZEROREFCOUNT:
            _tcscpy( strMsg, _T("A D3D object has a non-zero reference\n")
                             _T("count (meaning things were not properly\n")
                             _T("cleaned up).") );
            break;

        case D3DAPPERR_NULLREFDEVICE:
            _tcscpy( strMsg, _T("Warning: Nothing will be rendered.\n")
                             _T("The reference rendering device was selected, but your\n")
                             _T("computer only has a reduced-functionality reference device\n")
                             _T("installed.  Install the DirectX SDK to get the full\n")
                             _T("reference device.\n") );
            break;

        case E_OUTOFMEMORY:
            _tcscpy( strMsg, _T("Not enough memory.") );
            break;

        case D3DERR_OUTOFVIDEOMEMORY:
            _tcscpy( strMsg, _T("Not enough video memory.") );
            break;

        case D3DERR_DRIVERINTERNALERROR:
            _tcscpy( strMsg, _T("A serious problem occured inside the display driver.") );
            dwType = MSGERR_APPMUSTEXIT;
            break;

        default:
            _tcscpy( strMsg, _T("Generic application error. Enable\n")
                             _T("debug output for detailed information.") );
    }

    if( MSGERR_APPMUSTEXIT == dwType )
    {
        s_bFatalErrorReported = true;
        _tcscat( strMsg, _T("\n\nThis sample will now exit.") );
        MessageBox( NULL, strMsg, m_strWindowTitle, MB_ICONERROR|MB_OK );

        // Close the window, which shuts down the app
        if( m_hWnd )
            SendMessage( m_hWnd, WM_CLOSE, 0, 0 );
    }
    else
    {
        if( MSGWARN_SWITCHEDTOREF == dwType )
            _tcscat( strMsg, _T("\n\nSwitching to the reference rasterizer,\n")
                             _T("a software device that implements the entire\n")
                             _T("Direct3D feature set, but runs very slowly.") );
        MessageBox( NULL, strMsg, m_strWindowTitle, MB_ICONWARNING|MB_OK );
    }

    return hr;
}

