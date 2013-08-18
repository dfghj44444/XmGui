/*
file : ID_Loading.cpp
*/

//#include ".\__header\Engine\anw_dxengine.h"
#include ".\__header\UISource\anw_Base.h"
#include "ID_Loading.h"

static yb_Loading* g_pMainControl = 0;

///////////////////////////////////////////////////////////////////////////////
// ctor/dtor
yb_Loading::yb_Loading()
{
	m_pStatusUI_Loading = 0;
	
	g_pMainControl = this;
}
yb_Loading::~yb_Loading()
{
	ANW_SAFE_DEREF(m_pStatusUI_Loading);

	g_pMainControl = 0;
}
// ctor/dtor
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// callback
void yb_Loading::setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback)
{
	if(m_pStatusUI_Loading)	{m_pStatusUI_Loading->setEventCallback(pCallback);}
}
// callback
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// load files
bool yb_Loading::loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename)
{
	// deref
	ANW_SAFE_DEREF((*pManager));

	// create ui manager
	ANW_NEW(*pManager, ANW::StatusUI_Manager);
	if(*pManager == 0)
	{
		ANW_ASSERT(0);
		return false;
	}

	// create and open load file-stream
	ANW::IStreamFile* pLoadFile;
	ANW_NEW(pLoadFile, ANW::IStreamFile);
	if(pLoadFile == 0)
	{
		ANW_ASSERT(0);
		return false;
	}
	if(pLoadFile->openReadFile(strFilename) == false)
	{
		ANW_ASSERT(0);
		return false;
	}

	// load file
	if((*pManager)->loadFile(*pLoadFile) == false)
	{
		ANW_ASSERT(0);
		return false;
	}

	// close and delete load file-stream
	pLoadFile->closeFile();
	ANW_DEL(pLoadFile);

	// ref
	ANW_SAFE_REF((*pManager));
	(*pManager)->setEventCallback(OnGUIEvent_LoadingUIControl);

	return true;
}

bool yb_Loading::loadUi_Loading( CStringW strFilename )
{
	return loadUI(&m_pStatusUI_Loading, strFilename );
}
bool yb_Loading::loadUI_All(){
	
	if(loadUI(&m_pStatusUI_Loading, L"Loading.sav") == false ) return false;
	return true;
}
// load files
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// render
void yb_Loading::renderLoading( IDirect3DDevice9* pDevice )
{
	m_pStatusUI_Loading->render(pDevice);
}
// render
///////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////
// 접속상태
void yb_Loading::showConnection( bool bFlag, int nOrdinal )
{
	if( nOrdinal >= 7 && nOrdinal < 0 ) return;

	if( m_pStatusUI_Loading )
	{
		m_pStatusUI_Loading->setControlVisibility( ID_MAINGAME_CONNECTION00 + nOrdinal, bFlag );
		m_pStatusUI_Loading->setControlVisibility( ID_MAINGAME_CONNECTION_NAME00 + nOrdinal, bFlag );
	}
}
void yb_Loading::setConnectionName( int nOrdinal, CStringW strIn )
{
	if( nOrdinal >= 7 && nOrdinal < 0 ) return;

	if( m_pStatusUI_Loading )
	{
		ANW::StatusUI_TextButton* pTaget = (ANW::StatusUI_TextButton*)m_pStatusUI_Loading->findControlPointer( ID_MAINGAME_CONNECTION_NAME00+nOrdinal );
		if( pTaget->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			CStringW strBut = L"[ ";
			strBut += strIn;
			strBut += L" ]";			
			pTaget->setRectItemText( strBut );
		}
	}

}
void yb_Loading::setConnectionPercent( int nOrdinal, int nValue )
{
	if( nOrdinal >= 7 && nOrdinal < 0 ) return;
	if( m_pStatusUI_Loading )
	{
		ANW::StatusUI_TextButton* pTaget = (ANW::StatusUI_TextButton*)m_pStatusUI_Loading->findControlPointer( ID_MAINGAME_CONNECTION00+nOrdinal );
		if( pTaget->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			char szBuf[64];
			sprintf( szBuf, "%d %%", nValue );			
			pTaget->setRectItemText( szBuf );
		}
	}
}
// 접속상태
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// 로딩
void yb_Loading::setLoadingInit()
{
	if( m_pStatusUI_Loading )
	{
		ANW::StatusUI_ProgressBar* pProgress = (ANW::StatusUI_ProgressBar*)m_pStatusUI_Loading->findControlPointer( ID_LOADING_PROGRESS );

		if( pProgress->getRTTI()->getName() == ANW::StatusUI_ProgressBar::RTTI.getName() )
		{
			pProgress->setProgressInitial( 0 );
		}

	}
}
void yb_Loading::setLoadingProgressBar( float fCurrentValue )
{
	if( m_pStatusUI_Loading )
	{
		ANW::StatusUI_ProgressBar* pProgress = (ANW::StatusUI_ProgressBar*)m_pStatusUI_Loading->findControlPointer( ID_LOADING_PROGRESS );

		if( pProgress->getRTTI()->getName() == ANW::StatusUI_ProgressBar::RTTI.getName() )
		{
			pProgress->setProgressCurrent( fCurrentValue );
		}

	}
}
// 로딩
//////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// callback
void CALLBACK OnGUIEvent_LoadingUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext)
{
	if(pControl)
	{	
	}
}
// callback
///////////////////////////////////////////////////////////////////////////////