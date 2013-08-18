/*
file : ID_Lobby.cpp
*/

//r#include ".\__header\Engine\anw_dxengine.h"
#include "./__header/UISource/\anw_Base.h"
#include "ID_Lobby.h"
#include <time.h>
#include "ID_Lobby.h"


#define LOADUI( x, y)	if( 0 == x ){	if( false == loadUI(&x, y) )	{ ANW_ASSERT(0);} }


///////////////////////////////////////////////////////////////////////////////
// ctor/dtor
yb_LobbyUIControl::yb_LobbyUIControl()
{
	m_pUiTest_1 = 0;
	m_pUiTest_2 = 0;
}
yb_LobbyUIControl::~yb_LobbyUIControl()
{
	ANW_SAFE_DEREF( m_pUiTest_1 );
	ANW_SAFE_DEREF( m_pUiTest_2 );
}
// ctor/dtor
///////////////////////////////////////////////////////////////////////////////

//=================================================================================================================================//
// -START- : SET CALLBACK
//=================================================================================================================================//
void yb_LobbyUIControl::setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback)
{
	if(m_pUiTest_1)						{m_pUiTest_1->setEventCallback(pCallback);}
	if(m_pUiTest_2)						{m_pUiTest_2->setEventCallback(pCallback);}
}

bool yb_LobbyUIControl::loadUI_All()
{
	if(loadUI(&m_pUiTest_1,						 L"MyBag1.sav") == false ) 		return false;
	if(loadUI(&m_pUiTest_2,						 L"PersonShop.sav") == false ) 		return false;
	return true;
}
//=================================================================================================================================//
// -END- : SET CALLBACK
//=================================================================================================================================//

//=================================================================================================================================//
// -START- : framemove
//=================================================================================================================================//
void yb_LobbyUIControl::FrameMove(DWORD dwElapsedTime)
{
	if(m_pUiTest_1 && m_pUiTest_1->getVisible())		{	m_pUiTest_1->FrameMove(dwElapsedTime);	}
	if(m_pUiTest_2 && m_pUiTest_2->getVisible())		{	m_pUiTest_2->FrameMove(dwElapsedTime);	}
}	
//=================================================================================================================================//
// -End- : framemove
//=================================================================================================================================//

//=================================================================================================================================//
// -START- : render
//=================================================================================================================================//
void yb_LobbyUIControl::render(IDirect3DDevice9* pDevice)
{
	if(m_pUiTest_1 && m_pUiTest_1->getVisible())		{	m_pUiTest_1->render(pDevice);	}
	if(m_pUiTest_2 && m_pUiTest_2->getVisible())		{	m_pUiTest_2->render(pDevice);	}
}
//=================================================================================================================================//
// -END- : render
//=================================================================================================================================//

bool yb_LobbyUIControl::loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename)
{
	// deref
	ANW_SAFE_DEREF((*pManager));

	// create ui manager
	ANW_MAN_NEW(*pManager, ANW::StatusUI_Manager, strFilename );
	if(*pManager == 0)	{ANW_ASSERT(0);	return false;}

	// create and open load file-stream
	ANW::IStreamFile* pLoadFile;
	ANW_MAN_NEW(pLoadFile, ANW::IStreamFile, strFilename);
	if(pLoadFile == 0)	{ANW_ASSERT(0);	return false;}
	if(pLoadFile->openReadFile(strFilename) == false)	{ANW_ASSERT(0); return false;}

	// load file`
	if((*pManager)->loadFile(*pLoadFile) == false)	{ANW_ASSERT(0);return false;}

	// close and delete load file-stream
	pLoadFile->closeFile();
	ANW_DEL(pLoadFile); 

	// ref
	ANW_SAFE_REF((*pManager));

	(*pManager)->setEventCallback(OnGUIEvent_LobbyUIControl);

	return true;
}

//=================================================================================================================================//
// -END- : load files
//=================================================================================================================================//

///////////////////////////////////////////////////////////////////////////////
// callback
void CALLBACK OnGUIEvent_LobbyUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext)
{
	CHAR szBuffer[512], szTime[128];
	_tzset();
	_strtime(szTime);				
	sprintf(szBuffer, "%s=====ID : %d ... EVENT : %d \n\n", szTime, nControlID, nEvent );
	::OutputDebugStringA(szBuffer);
}
// callback
///////////////////////////////////////////////////////////////////////////////