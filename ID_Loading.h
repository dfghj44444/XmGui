/*
file : ID_Loading.h
*/

#ifndef _YB_LOADING_ID_H_
#define _YB_LOADING_ID_H_

// loading
typedef enum YB_LOADING_ID{	

	ID_LOADING_PROGRESS		=		100000,	
	ID_LOADING_ILUST,
	

	// 접속상태
	ID_MAINGAME_CONNECTION_NAME00=	11000,
	ID_MAINGAME_CONNECTION_NAME01=	11001,
	ID_MAINGAME_CONNECTION_NAME02=	11002,
	ID_MAINGAME_CONNECTION_NAME03=	11003,
	ID_MAINGAME_CONNECTION_NAME04=	11004,
	ID_MAINGAME_CONNECTION_NAME05=	11005,
	ID_MAINGAME_CONNECTION_NAME06=	11006,
	ID_MAINGAME_CONNECTION00=	12000,
	ID_MAINGAME_CONNECTION01=	12001,
	ID_MAINGAME_CONNECTION02=	12002,
	ID_MAINGAME_CONNECTION03=	12003,
	ID_MAINGAME_CONNECTION04=	12004,
	ID_MAINGAME_CONNECTION05=	12005,
	ID_MAINGAME_CONNECTION06=	12006,
};




void CALLBACK OnGUIEvent_LoadingUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

class yb_Loading
{
protected:
	ANW::StatusUI_Manager*	m_pStatusUI_Loading;


// CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL01,		"단축스킬 1",		'1',		D3DXVECTOR3(359.0f, 188.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL02,		"단축스킬 2",		'2',		D3DXVECTOR3(359.0f, 211.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL03,		"단축스킬 3",		'3',		D3DXVECTOR3(359.0f, 234.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL04,		"단축스킬 4",		'4',		D3DXVECTOR3(359.0f, 257.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL05,		"단축스킬 5",		'5',		D3DXVECTOR3(359.0f, 280.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL06,		"단축스킬 6",		'6',		D3DXVECTOR3(359.0f, 303.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL07,		"단축스킬 7",		'7',		D3DXVECTOR3(359.0f, 326.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL08,		"단축스킬 8",		'8',		D3DXVECTOR3(359.0f, 349.0f, 0) );
// 	CreateKey( ID_LOBBY_OPTION_SHOTCUT_SKILL09,		"단축스킬 9",		'9',		D3DXVECTOR3(359.0f, 372.0f, 0) );
// 	CreateKey( ID_L
	// load
	bool				loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename);

public:

	yb_Loading();
	~yb_Loading();

	// set callback
	void				setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback);

	// load	
	bool				loadUi_Loading( CStringW strFilename );
	bool				loadUI_All();

	// render	
	void				renderLoading( IDirect3DDevice9* pDevice );

	// 접속상태
	void				showConnection( bool bFlag, int nOrdinal );
	void				setConnectionName( int nOrdinal, CStringW strIn );
	void				setConnectionPercent( int nOrdinal, int nValue );

	// 로 딩
	void				setLoadingInit();
	void				setLoadingProgressBar( float fCurrentValue );

}; // class yb_Loading

#endif // _YB_LOADING_ID_H_