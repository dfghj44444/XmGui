
#ifndef _YB_TUTORIAL_ID_H_
#define _YB_TUTORIAL_ID_H_

typedef enum YB_TUTORIAL_ID{

	//======================================================================================================================//
	// 로비 백그라운드 - 시작
	//======================================================================================================================//	
	
	// 에너지
	ID_TUTORIAL_MYENERGY_BACKGROUND = 507,					// MY 에너지 백그라운드
	ID_TUTORIAL_MYENERGY_FACE,							// 얼굴
	ID_TUTORIAL_MYENERGY_LV,							// 레벨
	ID_TUTORIAL_MYENERGY_NAME,							// 이름
	ID_TUTORIAL_MYENERGY_ENERGY,						// 에너지바
	ID_TUTORIAL_MYENERGY_STAMINA,						// 스테미나
	ID_TUTORIAL_REAL_ENERGY_MY_1,							// 상단
	ID_TUTORIAL_REAL_ENERGY_MY_1_S,							// 스테미너
	ID_TUTORIAL_REAL_ENERGY_MY_1_ALPHA,						// 상단
	ID_TUTORIAL_REAL_ENERGY_MY_1_ALPHA_S,					// 스테미너

	// 타겟
	ID_TUTORIAL_TAGET_BACKGROUND1 = 517,						// 백그라운드
	//ID_TUTORIAL_TAGET_BACKGROUND2,
	ID_TUTORIAL_TAGET_LV,								// 레벨
	ID_TUTORIAL_TAGET_NAEM,								// 이름
	//ID_TUTORIAL_TAGET_ENERGY,							// 에너지
	//ID_TUTORIAL_REAL_ENERGY_TAGET,							// 타겟
	//ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA,						// 타겟

	// 일반
	ID_TUTORIAL_TAGET_BACKGROUND_GENERAL = 528,						// 에너지 바
	ID_TUTORIAL_TAGET_ENERGY_GENERAL,							// 에너지	
	ID_TUTORIAL_REAL_ENERGY_TAGET_GENERAL,							// 실시간
	ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA_GENERAL,					// 알파

	ID_TUTORIAL_MAIN_MENU_INFORMATION = 561,					// 캐릭정보
	ID_TUTORIAL_MAIN_MENU_SKILL_CONTROL,				// 무공창
	ID_TUTORIAL_MAIN_MENU_FRIEND_CONTROL,				// 친구관리
	ID_TUTORIAL_MAIN_MENU_PETSONSHOP,					// 개인상점
	ID_TUTORIAL_MAIN_MENU_SYSTEM,						// 시스템
	ID_TUTORIAL_MAIN_MENU_GUILD,						// 길드
	ID_TUTORIAL_MAIN_MENU_QUEST,						// 퀘스트
	ID_TUTORIAL_MAIN_MENU_MYBAG,						// 내가방	
	ID_TUTORIAL_MAIN_MENU_CHSHSHOP,

	ID_TUTORIAL_TUTORIALGROUND1,						// 아래백그라운드	
	ID_TUTORIAL_BACKGROUND2,							// 경험치 백그라운드
	ID_TUTORIAL_MODE_BATTLE,

	//ID_TUTORIAL_LEVEL,									// 레벨표시
	//ID_TUTORIAL_NAME,									// 자신이름

	ID_TUTORIAL_ENERGY = 602,									// 에너지
	ID_TUTORIAL_STAMINA,								// 스테미너

	
	// 실시간 에너지바
	ID_TUTORIAL_REAL_ENERGY_MY_2,							// 하단
	ID_TUTORIAL_REAL_ENERGY_MY_2_S,							// 스테미너
	ID_TUTORIAL_REAL_ENERGY_MY_2_ALPHA,						// 하단
	ID_TUTORIAL_REAL_ENERGY_MY_2_ALPHA_S,					// 스테미너	
	

	ID_TUTORCHARMSGBOX = 50000,
	ID_TUTORCHARFACEBOX,
	ID_TUTORCHARMSGNEXTBN,
// 	ID_TUTORCHARMSGTEXT,
// 	ID_TUTORCHARMSGTEXT2,
// 	ID_TUTORCHARMSGTEXT3,
	ID_TUTORIAL_OTHERMSGBOX,
	ID_TUTORIAL_OTHERCHARBOX,
	ID_TUTORIAL_OTHERNEXTBN,
	ID_TUTORIAL_LISTBOX,
	ID_TUTORIAL_LISTBOX2,

	ID_TUTORIAL_OKCANCELBOX,
	ID_TUTORIAL_OKCANCELBOX_OK,
	ID_TUTORIAL_OKCANCELBOX_CANCEL,
	ID_TUTORIAL_OKCANCELBOX_TEXT,

	ID_TUTORIAL_TITLE,
	
	ID_TUTORIAL_MYNAME_STATIC,
	ID_TUTORIAL_OTHERNAME_STATIC,
	ID_TUTORIAL_TITLEEND,

	ID_TUTORIAL_KEY_RIGHT,
	ID_TUTORIAL_KEY_RIGHT2,
	ID_TUTORIAL_KEY_UP,
	ID_TUTORIAL_KEY_DOWN,
	ID_TUTORIAL_KEY_E,
	ID_TUTORIAL_KEY_W,
	ID_TUTORIAL_KEY_PLUS,
	ID_TUTORIAL_SKILLNAME,
	ID_TUTORIAL_DESC_LIST,
	ID_TUTORIAL_HELPBG,
// 	ID_TUTORIAL_OTHERMSGTEXT,
// 	ID_TUTORIAL_OTHERMSGTEXT2,
// 	ID_TUTORIAL_OTHERMSGTEXT3,
	ID_QUEST_GIVE_WINDOW_BG,
	ID_QUEST_GIVE_WINDOW_ITEMIMG1,
	ID_QUEST_GIVE_WINDOW_ITEMIMG2,
	ID_QUEST_GIVE_WINDOW_ITEMIMG3,
	ID_QUEST_GIVE_WINDOW_ITEMIMG4,

	ID_QUEST_GIVE_WINDOW_GOLD,
	ID_QUEST_GIVE_WINDOW_EXP,
	ID_QUEST_GIVE_WINDOW_ITEMNAME1,
	ID_QUEST_GIVE_WINDOW_ITEMNAME2,
	ID_QUEST_GIVE_WINDOW_ITEMNAME3,
	ID_QUEST_GIVE_WINDOW_ITEMNAME4,
	ID_QUEST_GIVE_WINDOW_OK,
};



//void CALLBACK OnGUIEvent_TutorialUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

class yb_TutorialUIControl
{
protected:
	ANW::StatusUI_Manager*	m_pTutorial_MsgBox;
	ANW::StatusUI_Manager*  m_pTuturial_OkCancel;
	ANW::StatusUI_Manager*  m_pTuturial_Title;
	ANW::StatusUI_Manager*  m_pQuestRewardWindow;


	ANW::StatusUI_Manager*		m_pBackGroundMain;
	ANW::StatusUI_Manager*		m_pBackGroundMiniMap;
	ANW::StatusUI_Manager*		m_pBackGroundEnergy;

protected:
	bool				loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename);
public:

	bool	m_bDrawRightMsgBox;
	bool	m_bDrawLeftMsgBox;
	INT		m_nPreTutorNum;

	bool				loadUI_All();
	ANW::StatusUI_Manager* GetUiMngTutorial(){ return m_pTutorial_MsgBox;}
	void render(IDirect3DDevice9* pDevice);
	void				setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback);

	void				FrameMove( DWORD dwDTime );

	void RightMsgBoxInit();
	void RightCharImgInit();
	void ProcessRightMsgbox( INT nElapsedTime );
	void ProcessRightCharImg( INT nElapsedTime );

	void LeftMsgBoxInit();
	void LeftCharImgInit();
	void ProcessLeftMsgbox( INT nElapsedTime );
	void ProcessLeftCharImg( INT nElapsedTime );

	BOOL				IsRightFaceMsgBox() { return m_bDrawRightMsgBox;}
	void				SetRightFaceMsgBox( bool bShow ) { m_bDrawRightMsgBox = bShow;}
	BOOL				IsLeftFaceMsgBox() { return m_bDrawLeftMsgBox;}
	void				SetLeftFaceMsgBox( bool bShow ) { m_bDrawLeftMsgBox = bShow;}

	void				ShowOkCancelBox( bool bShow );
	void				ShowTitleImg( bool bShow ,int nCharIndex = 0);
	void				ShowTitleEndImg( bool bShow ,int nCharIndex = 0);
	bool				IsOkCancelBox( void );

	void				SetOkFocus();
	void				SetCancelFocus();
	void				SetNextBnFocus();

	void				SetRightMsgText(char *pszText);
	void				SetLeftMsgText(char *pszText);
	wchar_t*			CharToWChar(const char* pstrSrc);
	void				SetRightCharName(char *pszName );
	void				SetLeftCharName(char *pszName );
	void				SetHelpShow( int nTutoriolNum ,int nChar);
	void				HideTutHelp();
	void				ShowHelpMove();
	void				ShowHelpRun();
	void				ShowHelpJump();
	void				ShowHelpAttack1();
	void				ShowHelpAttack2( int nChar = 0);
	void				ShowHelpAttack3();
	void				ShowHelpAttack4();
	void				ShowHelpAttack5();
	void				ShowHelpPickUp();

	void				SetQuestRewardWindowShow( bool bShow );
	void				SetQuestMoney( int nMoney );
	void				SetQuestExp( int nExp );
	void				SetQuestItem(int nIndex,char *szItemImgName,char *szItemName);
	void				SetQuestItemVisible(int nIndex,bool bShow);
	void				SetQuestItemAllVisible(bool bShow);

	void				SetShowMainUi( bool bShow );

	VOID				setMyLv_Name( const int& nLv, const CStringW& strName , const int& nOrdinal);	// 레벨 이름
	VOID				SetMyExp( const UINT& nMax, const UINT& nCurr );			// EXP
	VOID				SetMyStamina( const int&nMax, const int& nCurr, const UINT& nNow );			// 스테미너
	VOID				SetMyEnergy( const UINT&nMax, const UINT& nCurr, const UINT& nNow );			// 에너지
	VOID				SetTownInit();

	VOID				SetBufVisible( const int& nOrdinal, const int& nBufOrdinal, const bool& bFlag );
	VOID				SetRegenTime_Visible( const int& nOrdinal, const bool& bFlag );

	void				SetChatWindowShow( bool bShow  );

	// 타겟 에너지
	VOID				SetTagetEnergyVisible( const bool& bFlag );									// 타겟에너지 활성&비활성
	VOID				SetTagetLv_Name( const int nLevel, const CStringW& strName );				// 타겟 레벨 이름
	VOID				SetTagetEnergy( const UINT& nMax, const UINT& nCur, const UINT& nNow );		// 타겟에너지

	VOID				SetWorldMap( bool bShow );


public:

	yb_TutorialUIControl();
	~yb_TutorialUIControl();


}; // class yb_TutorialUIControl

#endif // _YB_TUTORIAL_ID_H_
