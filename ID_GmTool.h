
#ifndef _YB_GMTOOL_ID_H_
#define _YB_GMTOOL_ID_H_

#include <vector>

typedef enum YB_GMTOOLL_ID{
	ID_GMTOOL_NOTICEBUTTON = 0,
	ID_GMTOOL_NOTICEBUTTON_TEXT,
	ID_GMTOOL_CHARBUTTON,
	ID_GMTOOL_CHARBUTTON_TEXT,
	ID_GMTOOL_SERVERSELECTBUTTON,
	ID_GMTOOL_SERVERSELECTBUTTON_TEXT,
	ID_GMTOOL_GMOPTIONBUTTON,
	ID_GMTOOL_GMOPTIONBUTTON_TEXT,
	ID_GMTOOL_GMMENUBUTTON,
	ID_GMTOOL_GMMENUBUTTON_TEXT,
	ID_GMTOOL_NOTICEBG,
	ID_GMTOOL_PASSIVITYBN,
	ID_GMTOOL_PASSIVITYBN_TEXT,
	ID_GMTOOL_AUTONOTICEBN,
	ID_GMTOOL_AUTONOTICEBN_TEXT,
	ID_GMTOOL_PASSIVITYNOTICE_EDIT,
	ID_GMTOOL_AUTONOTICE_EDIT,
	ID_GMTOOL_NOTICECHECK1_BN,
	ID_GMTOOL_NOTICECHECK2_BN,
	ID_GMTOOL_NOTICECHECK3_BN,
	ID_GMTOOL_NOTICECHECK4_BN,
	ID_GMTOOL_NOTICECHECK5_BN,
	ID_GMTOOL_NOTICECHECK6_BN,
	ID_GMTOOL_NOTICETEXTVIEW1_BN,
	ID_GMTOOL_NOTICETEXTVIEW2_BN,
	ID_GMTOOL_NOTICETEXTVIEW3_BN,
	ID_GMTOOL_NOTICETEXTVIEW4_BN,
	ID_GMTOOL_NOTICETEXTVIEW5_BN,
	ID_GMTOOL_NOTICETEXTVIEW6_BN,
	ID_GMTOOL_NOTICETEXTVIEW1_BN_TEXT,
	ID_GMTOOL_NOTICETEXTVIEW2_BN_TEXT,
	ID_GMTOOL_NOTICETEXTVIEW3_BN_TEXT,
	ID_GMTOOL_NOTICETEXTVIEW4_BN_TEXT,
	ID_GMTOOL_NOTICETEXTVIEW5_BN_TEXT,
	ID_GMTOOL_NOTICETEXTVIEW6_BN_TEXT,
	ID_GMTOOL_STARTYEAR_COMBO,
	ID_GMTOOL_STARTMONTH_COMBO,
	ID_GMTOOL_STARTDAY_COMBO,
	ID_GMTOOL_STARTHOUR_COMBO,
	ID_GMTOOL_STARTMINUTE_COMBO,
	ID_GMTOOL_ENDYEAR_COMBO,
	ID_GMTOOL_ENDMONTH_COMBO,
	ID_GMTOOL_ENDDAY_COMBO,
	ID_GMTOOL_ENDHOUR_COMBO,
	ID_GMTOOL_ENDMINUTE_COMBO,
	ID_GMTOOL_INTERVAL_COMBO,
	ID_GMTOOL_SERVERSELECT_COMBO,
	ID_GMTOOL_CHANNELSELECT_COMBO,

	ID_GMTOOL_NOTICESTART_STATIC,
	ID_GMTOOL_STARTYEAR_STATIC,
	ID_GMTOOL_STARTMONTH_STATIC,
	ID_GMTOOL_STARTDAY_STATIC,
	ID_GMTOOL_STARTHOUR_STATIC,
	ID_GMTOOL_STARTMINUTE_STATIC,
	ID_GMTOOL_NOTICEEND_STATIC,
	ID_GMTOOL_INTERVAL_STATIC,
	ID_GMTOOL_SERVERSELECT_STATIC,
	ID_GMTOOL_SERVER_STATIC,
	ID_GMTOOL_CHANNELSELECT_STATIC,

	//캐릭터
	ID_GMTOOL_SEARCH_COMBO,
	ID_GMTOOL_CHARSEARCH_EDIT,
	ID_GMTOOL_CHARSEARCH_BN,
	ID_GMTOOL_CHARSEARCH_TEXT,
	ID_GMTOOL_CHARINFO1_STATIC,
	ID_GMTOOL_CHARINFO2_STATIC,
	ID_GMTOOL_CHARINFO3_STATIC,
	ID_GMTOOL_CHARINFO4_STATIC,
	ID_GMTOOL_CHARINFO5_STATIC,
	ID_GMTOOL_CHARINFO6_STATIC,
	ID_GMTOOL_NOCHAT_STATIC,
	ID_GMTOOL_NOCHATTIME_EDIT,
	ID_GMTOOL_NOCHATTIMESETUP_BN,
	ID_GMTOOL_NOCHATTIMESETUP_TEXT,
	ID_GMTOOL_NOCHATTIME_STATIC,
	ID_GMTOOL_GAMEOUT_BN,
	ID_GMTOOL_GAMEOUTBN_TEXT,
	ID_GMTOOL_CHAT_LISTBOX,
	ID_GMTOOL_USERLIST_COMBO,
	ID_GMTOOL_CHAT_EDIT,
	ID_GMTOOL_CHATINPUT_BN,
	ID_GMTOOL_CHATINPUT_BN_TEXT,

	//GM옵션
	ID_GMTOOL_NoViewChar_CHECK,
	
	//메인버튼
	ID_GMTOOL_MAINBUTTON,
};

struct UserData
{
	char szUserName[256];
};

//void CALLBACK OnGUIEvent_TutorialUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

class yb_GmToolUIControl
{
protected:
	ANW::StatusUI_Manager*	m_pGmToolMng;
	int					m_nNoticeStartYear;
	int					m_nNoticeStartMonth;
	int					m_nNoticeStartDay;
	int					m_nNoticeStartHour;
	int					m_nNoticeStartMinute;
	int					m_nNoticeEndYear;
	int					m_nNoticeEndMonth;
	int					m_nNoticeEndDay;
	int					m_nNoticeEndHour;
	int					m_nNoticeEndMinute;
	int					m_nNoticeIntervalTime;

	bool				m_bNoticeStart;
	bool				m_bNoticeEnd;
	std::vector<UserData>	m_vUserList;

protected:
	bool				loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename);
public:

	bool				loadUI_All();
	ANW::StatusUI_Manager* GetUiMngGm(){ return m_pGmToolMng;}
	void render(IDirect3DDevice9* pDevice);
	void				setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback);

	void				FrameMove(DWORD dwElapsedTime);

	void				SetGmToolButtonVisible( bool bShow );
	void				SetNoticeWindowVisible(bool bshow);
	void				SetCharacterWindowVisible(bool bshow);
	void				SetGmOptionWindowVisible(bool bshow);
	
	void				SetGmMenuButtonVisible(bool bshow);
	void				SetGmMainButtonvisible( bool bshow );
	void				SetBgView( bool bshow );
	void				SetBgAlpha( int nAlpha );
	bool				IsNoticeView();
	bool				IsCharacterView();
	bool				IsGmOptionView();
	bool				IsGmMenuView();
	bool				IsGmToolButtonView();
public:
	void				SetNoticeText( int nIndex, char *pszNoticeText );
	void				SetEditNotice( char *pszNoticeText );
	wchar_t*			CharToWChar(const char* pstrSrc);
	void				GetNoticeComboBoxData();

	int					GetNoticeStartYear(){ return m_nNoticeStartYear;}
	int					GetNoticeStartMonth(){ return m_nNoticeStartMonth;}
	int					GetNoticeStartDay(){ return m_nNoticeStartDay;}
	int					GetNoticeStartMinute(){ return m_nNoticeStartMinute;}
	int					GetNoticeEndYear(){ return m_nNoticeEndYear;}
	int					GetNoticeEndMonth(){ return m_nNoticeEndMonth;}
	int					GetNoticeEndDay(){ return m_nNoticeEndDay;}
	int					GetNoticeEndMinute(){ return m_nNoticeEndMinute;}
	int					GetIntervalTime(){ return m_nNoticeIntervalTime;}

	void				SetNoticeStart( bool bStart ) { m_bNoticeStart = bStart;}
	bool				GetNoticeStart(){ return m_bNoticeStart;}
	void				SetNoticeEnd( bool bEnd ) { m_bNoticeEnd = bEnd;}
	bool				GetNoticeEnd(){ return m_bNoticeEnd;}

	void				SetUserNo( char *pUserNo );
	void				SetCharName( char *pCharName );
	void				SetCharNo( char *pCharNo );
	void				SetConnectStatus( char *pConnect );
	void				SetCharPosionStatus( char *pCharPosion );
	void				SetBanInfo( char *pBanInfo);
	void				SetCharInfoInit();
	int					GetCharacterSearchIndex();	
	
	int					GetCharacterListIndex();
	void				GetCharacterListText(CStringA& strOut);

	void				chat_addMessage(CStringW strName, CStringW strText, DWORD colorNormal, DWORD colorSelected, void* pData);
	void				chat_clearChat();
	void				addComboUserName(CStringW strIn);
	void				AddComboUserClear();
	void				AddCharUser( char *username );
	void				FreeChatUserList();
	bool				IsChatUserName( char *username );
public:
	int					m_nEditNoticeIndex;

	yb_GmToolUIControl();
	~yb_GmToolUIControl();


}; // class yb_GmToolUIControl

#endif // _YB_GMTOOL_ID_H_
