#ifndef _DXENGINE_H_
#define _DXENGINE_H_

#include <d3d9.h>
#include "D3DEnumer.h"

//-----------------------------------------------------------------------------
// Error codes
//-----------------------------------------------------------------------------
enum APPMSGTYPE { MSG_NONE, MSGERR_APPMUSTEXIT, MSGWARN_SWITCHEDTOREF };

#define D3DAPPERR_NODIRECT3D          0x82000001
#define D3DAPPERR_NOWINDOW            0x82000002
#define D3DAPPERR_NOCOMPATIBLEDEVICES 0x82000003
#define D3DAPPERR_NOWINDOWABLEDEVICES 0x82000004
#define D3DAPPERR_NOHARDWAREDEVICE    0x82000005
#define D3DAPPERR_HALNOTCOMPATIBLE    0x82000006
#define D3DAPPERR_NOWINDOWEDHAL       0x82000007
#define D3DAPPERR_NODESKTOPHAL        0x82000008
#define D3DAPPERR_NOHALTHISMODE       0x82000009
#define D3DAPPERR_NONZEROREFCOUNT     0x8200000a
#define D3DAPPERR_MEDIANOTFOUND       0x8200000b
#define D3DAPPERR_RESETFAILED         0x8200000c
#define D3DAPPERR_NULLREFDEVICE       0x8200000d

typedef VOID  (* pfLostDevice)(VOID);
typedef VOID  (* pfResetDevice)(VOID);

struct DISPLAY_INFO
{
	D3DAdapterInfo*			pAdapterInfo;
    D3DDeviceInfo*			pDeviceInfo;
    D3DDeviceCombo*			pDeviceCombo;

	D3DDISPLAYMODE			primaryDesktopDisplayMode;
	D3DFORMAT				DepthStencilBufferFormat;

	D3DMULTISAMPLE_TYPE		Windowed_MultisampleType;
    DWORD					Windowed_MultisampleQuality;
    VertexProcessingType	Windowed_VertexProcessingType;
    UINT					Windowed_PresentInterval;

	int						WindowWidth;
	int						WindowHeight;

	DISPLAY_INFO()
	{
		pAdapterInfo = NULL;
		pDeviceInfo	 = NULL;
		pDeviceCombo = NULL;

		WindowWidth	 = 0;
		WindowHeight = 0;
	};
};



class CDXEngine
{
protected:

	CD3DEnumeration			m_d3dEnumeration;	
	DISPLAY_INFO			m_d3dDisplayInfo;														

	LPDIRECT3D9				m_pD3D;
	LPDIRECT3DDEVICE9		m_pd3dDevice;
	D3DPRESENT_PARAMETERS	m_d3dpp;
	DWORD					m_dwWindowStyle;
	D3DCAPS9				m_d3dCaps;
	D3DSURFACE_DESC			m_d3dsdBackBuffer;
	DWORD					m_dwCreateFlags;

	TCHAR*					m_strWindowTitle;
	VOID					(*m_pfLostDevice)(VOID);
	VOID					(*m_pfResetDevice)(VOID);

public:

	HWND					m_hWnd;																	
	BYTE					m_bDisplayMode;															
	RECT					m_rcWindowClient;														
	RECT					m_rtFlip[5];															
	WORD					m_wScreenWidth;															
	WORD					m_wScreenHeight;															
	LPDIRECT3DTEXTURE9		m_pTexRenderTarget;															
	LPDIRECT3DSURFACE9		m_pSurRenderTarget;															
	LPDIRECT3DSURFACE9		m_pSurBaseRenderTarget;														

protected:

	// Overridable functions for the 3D scene created by the app
    virtual HRESULT			ConfirmDevice(D3DCAPS9*,DWORD,D3DFORMAT,D3DFORMAT) { return S_OK; }
	D3DFORMAT				FindDepthFormat_D3D( INT nAdapter, D3DFORMAT d3dfColor, INT nDepthBits );
	bool					FindBestWindowedMode( bool bRequireHAL, bool bRequireREF );
    HRESULT					ChooseInitialD3DSettings();
	HRESULT					Initialize3DEnvironment();
	void					BuildPresentParamsFromSettings();
	//bool    FindBestFullscreenMode( bool bRequireHAL, bool bRequireREF );

public:
	CDXEngine();																						// Create
	~CDXEngine();																						// Destroy


	VOID					DeleteAll();																
	HRESULT					DisplayErrorMsg(HRESULT hr, DWORD dwType);									
	HRESULT					CreateDXEngine(HWND hWnd, WORD wWidth, WORD wHeigth, BYTE bDisplayMode);	

	// Internal functions to manage and render the 3D scene
	static bool				ConfirmDeviceHelper(D3DCAPS9* pCaps, VertexProcessingType vertexProcessingType, D3DFORMAT adapterFormat, D3DFORMAT backBufferFormat);

	void					SetPosTrans();
	void					Flip();
	void					SetFlipRgn(RECT* rtFlip);
	void					SetFlipRect(RECT rtFlip, INT nIdx = 0);

	LPDIRECT3DSURFACE9		GetBackSurface();

	VOID					ChangeRenderTarget(BOOL fClear = TRUE);
	VOID					RestoreRenderTarget(VOID);
	HRESULT					ValidateDevice(VOID);
	HRESULT					ToggleScreenMode(VOID);

	inline HWND				GetMainWnd(VOID)								{return m_hWnd;							}
	inline LPDIRECT3DDEVICE9 GetDevice(VOID)								{return m_pd3dDevice;					}
	inline RECT				GetFlipIdx(INT nIdx)							{return m_rtFlip[nIdx];					}
	inline RECT*			GetFlipRgn(VOID)								{return m_rtFlip;						}
	inline LPDIRECT3DTEXTURE9 GetTexRenderTarget()							{return m_pTexRenderTarget;				}
	inline LPDIRECT3DSURFACE9 GetSurRenderTarget()							{return m_pSurRenderTarget;				}
	inline LPDIRECT3DSURFACE9 GetSurBaseRenderTarget()						{return m_pSurBaseRenderTarget;			}
	inline DWORD			GetVertexShaderVersion()						{return m_d3dCaps.VertexShaderVersion;	}
	inline DWORD			GetPixelShaderVersion()							{return m_d3dCaps.PixelShaderVersion;	}
	inline VOID				SetLostDevice(pfLostDevice pLostDevice)			{m_pfLostDevice = pLostDevice;			}
	inline VOID				SetResetDevice(pfResetDevice pResetDevice)		{m_pfResetDevice = pResetDevice;		}
};

#endif

extern CDXEngine* g_pxD3d;
