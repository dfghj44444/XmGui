#include ".\..\UI\anw_Base.h"
#include "ID_GmTool.h"
#include "../Main/General.h"

void CALLBACK OnGUIEvent_Tutorial(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

//=================================================================================================================
//=================================================================================================================
// ctor/dtor
yb_GmToolUIControl::yb_GmToolUIControl()
{
	m_pGmToolMng = NULL;
	m_nEditNoticeIndex = -1;
	m_bNoticeStart = false;
	m_bNoticeEnd = true;
}
yb_GmToolUIControl::~yb_GmToolUIControl()
{		
	ANW_SAFE_DEREF(m_pGmToolMng);
	FreeChatUserList();
}

bool yb_GmToolUIControl::loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename)
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
	//(*pManager)->setEventCallback(OnGUIEvent_Tutorial);

	return true;
}

bool yb_GmToolUIControl::loadUI_All(){

	if(loadUI(&m_pGmToolMng, L"GmTool.sav") == false ) return false;
	return true;
}

void yb_GmToolUIControl::SetNoticeWindowVisible(bool bshow )
{
	for( int i = ID_GMTOOL_PASSIVITYBN; i<= ID_GMTOOL_CHANNELSELECT_STATIC ; i++)
	{
		ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( i );
		if( pControl == NULL) continue;	
		pControl->setVisible(bshow);
	}
}

void yb_GmToolUIControl::SetCharacterWindowVisible(bool bshow )
{
	for( int i = ID_GMTOOL_SEARCH_COMBO; i<= ID_GMTOOL_CHATINPUT_BN_TEXT ; i++)
	{
		ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( i );
		if( pControl == NULL) continue;	
		pControl->setVisible(bshow);

	}
}

void yb_GmToolUIControl::SetGmOptionWindowVisible(bool bshow )
{
	for( int i = ID_GMTOOL_NoViewChar_CHECK; i<= ID_GMTOOL_NoViewChar_CHECK ; i++)
	{
		ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( i );
		if( pControl == NULL) continue;	
		pControl->setVisible(bshow);
	}
}
void	yb_GmToolUIControl::SetGmMenuButtonVisible(bool bshow)
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_GMMENUBUTTON );
	pControl->setVisible(bshow);	
}
void	yb_GmToolUIControl::SetGmMainButtonvisible( bool bshow )
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_MAINBUTTON );
	pControl->setVisible(bshow);
	pControl->setEnabled(bshow);
}

void yb_GmToolUIControl::SetBgView(bool bshow )
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_NOTICEBG );
	pControl->setVisible(bshow);
}

void yb_GmToolUIControl::SetBgAlpha(int nAlpha )
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_NOTICEBG );
	if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName() )
	{
		ANW::StatusUI_Rect* pRect = pControl->getRectByOrdinal( 0 );
		if( NULL != pRect )
		{
			for( int n = 0 ; n < STATUSUI_NUML_STATES ; ++n )
			{
				if( n == 0 ) continue;
				ANW::StatusUI_RectItem* pRectItem = (ANW::StatusUI_RectItem*)pRect->getControlRect((ANW::STATUSUI_CONTROL_STATE)n);
				if( pRectItem )
				{
					pRectItem->setAlpha(nAlpha);
				}
			}
		}
	}
}

bool yb_GmToolUIControl::IsNoticeView()
{
	
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_PASSIVITYBN );
		
	return pControl->getVisible();

}
bool yb_GmToolUIControl::IsCharacterView()
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_SEARCH_COMBO );

	return pControl->getVisible();

}
bool yb_GmToolUIControl::IsGmOptionView()
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_NoViewChar_CHECK );
	return pControl->getVisible();
}

bool yb_GmToolUIControl::IsGmMenuView()
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_GMMENUBUTTON );
	return pControl->getVisible();
}


void	yb_GmToolUIControl::SetNoticeText( int nIndex, char *pszNoticeText )
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer(ID_GMTOOL_NOTICECHECK1_BN + nIndex);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName())
	{
		ANW::StatusUI_CheckBox* pCheckBox = (ANW::StatusUI_CheckBox*)pControl;
		ANW::StatusUI_Rect* pRect = pCheckBox->getRectByOrdinal( 2 );

		if( NULL != pRect )
		{
			for( int n = 0 ; n < STATUSUI_NUML_STATES ; ++n )
			{
				//if( n == 0 ) continue;
				ANW::StatusUI_RectItemText* pRectItemText = (ANW::StatusUI_RectItemText*)pRect->getControlRect((ANW::STATUSUI_CONTROL_STATE)n);
				if( pRectItemText )
				{
					pRectItemText->setTextData(pszNoticeText);
				}
			}
		}

	}
}

wchar_t*	yb_GmToolUIControl::CharToWChar(const char* pstrSrc)
{
	ANW_ASSERT(pstrSrc);
	int nLen = strlen(pstrSrc) + 1;

	wchar_t* pwstr = (LPWSTR) malloc( sizeof(wchar_t)*nLen);
	mbstowcs(pwstr,pstrSrc,nLen);

	return pwstr;
}

void	yb_GmToolUIControl::SetEditNotice( char *pszNoticeText )
{
	ANW::StatusUI_IMEEditBox_Target* pIMEBoxT = 0;
	pIMEBoxT = (ANW::StatusUI_IMEEditBox_Target*)m_pGmToolMng->findControlPointer( ID_GMTOOL_AUTONOTICE_EDIT );
	
	CStringW	strTemp;
	strTemp = pszNoticeText;

	if(pIMEBoxT->getRTTI()->getName() == ANW::StatusUI_IMEEditBox_Target::RTTI.getName())
	{
		
		pIMEBoxT->SetText(strTemp);
		
	}
}

void yb_GmToolUIControl::GetNoticeComboBoxData()
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_STARTYEAR_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeStartYear = 2008 + pTarget->getSelectedIndex();
			}
		}

		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_STARTMONTH_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeStartMonth = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_STARTDAY_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeStartDay = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_STARTHOUR_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeStartHour = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_STARTMINUTE_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeStartMinute = 1 + pTarget->getSelectedIndex();
			}
		}

		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_ENDYEAR_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeEndYear = 2008 + pTarget->getSelectedIndex();
			}
		}

		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_ENDMONTH_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeEndMonth = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_ENDDAY_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeEndDay = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_ENDHOUR_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeEndHour = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_ENDMINUTE_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeEndMinute = 1 + pTarget->getSelectedIndex();
			}
		}
		pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_INTERVAL_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				m_nNoticeIntervalTime = 1 + pTarget->getSelectedIndex();
			}
		}
	}
}

void yb_GmToolUIControl::SetUserNo( char *pUserNo )
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO1_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pUserNo);
}

void yb_GmToolUIControl::SetCharName( char *pCharName )
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO2_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pCharName);
}

void yb_GmToolUIControl::SetCharNo( char *pCharNo )
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO3_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pCharNo);
}

void yb_GmToolUIControl::SetConnectStatus( char *pConnect )
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO4_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pConnect);
}

void yb_GmToolUIControl::SetCharPosionStatus( char *pCharPosion )
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO5_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pCharPosion);
}

void yb_GmToolUIControl::SetBanInfo( char *pBanInfo)
{
	ANW::StatusUI_Control* pControl = NULL;		

	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARINFO6_STATIC );			
	ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	pTextButton->setRectItemText(pBanInfo);
}

void yb_GmToolUIControl::SetCharInfoInit()
{
	SetUserNo("");
	SetCharName("");
	SetCharNo("");
	SetConnectStatus("");
	SetCharPosionStatus("");
	SetBanInfo("");
}

int yb_GmToolUIControl::GetCharacterSearchIndex()											
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_SEARCH_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				return pTarget->getSelectedIndex();
			}
		}
	}
	return -1;
}

int yb_GmToolUIControl::GetCharacterListIndex()											
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_USERLIST_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				return pTarget->getSelectedIndex();
			}
		}
	}
	return -1;
}

void yb_GmToolUIControl::GetCharacterListText(CStringA& strOut)
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_USERLIST_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				strOut = pTarget->getSelectedItem()->strText;
			}
		}
	}
}

void yb_GmToolUIControl::chat_addMessage(CStringW strName, CStringW strText, DWORD colorNormal, DWORD colorSelected, void* pData)
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_Control* pControl = 0;		

		pControl = m_pGmToolMng->findControlPointer(ID_GMTOOL_CHAT_LISTBOX);
		if(pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->addItem( true, strName, strText, colorNormal, colorSelected, pData);
		}
	}
}

void yb_GmToolUIControl::chat_clearChat()
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer(ID_GMTOOL_CHAT_LISTBOX);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->removeAllItems();
		}
	}
}

void yb_GmToolUIControl::addComboUserName(CStringW strIn)
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_USERLIST_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				pTarget->addItem(strIn.GetBuffer(), 0);
			}
		}
	}
}

void yb_GmToolUIControl::AddComboUserClear()
{
	if(m_pGmToolMng)
	{
		ANW::StatusUI_ComboBox* pTarget = (ANW::StatusUI_ComboBox*)m_pGmToolMng->findControlPointer(ID_GMTOOL_USERLIST_COMBO);
		if(pTarget)
		{
			if(pTarget->getRTTI()->getName() == ANW::StatusUI_ComboBox::RTTI.getName())
			{
				pTarget->removeAllItems();
			}
		}
	}
}

void	yb_GmToolUIControl::AddCharUser( char *username )
{
	UserData pUserName;
	strcpy(pUserName.szUserName ,username);
	m_vUserList.push_back(pUserName);
}

bool	yb_GmToolUIControl::IsChatUserName( char *username )
{
	for( int i = 0; i< m_vUserList.size();i++)
	{
		if(!strcmp(m_vUserList[i].szUserName,username))
			return true;
	}
	return false;
}

void yb_GmToolUIControl::FreeChatUserList()
{
	m_vUserList.clear();
}

bool yb_GmToolUIControl::IsGmToolButtonView()
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_NOTICEBUTTON );
	return pControl->getVisible();
}

void yb_GmToolUIControl::SetGmToolButtonVisible( bool bShow )
{
	ANW::StatusUI_Control* pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_NOTICEBUTTON );
	pControl->setVisible(bShow);
	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_CHARBUTTON );
	pControl->setVisible(bShow);
	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_SERVERSELECTBUTTON );
	pControl->setVisible(bShow);
	pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_GMOPTIONBUTTON );
	pControl->setVisible(bShow);
	//pControl = m_pGmToolMng->findControlPointer( ID_GMTOOL_GMMENUBUTTON );
	//pControl->setVisible(bShow);
	
}


void yb_GmToolUIControl::setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback)
{	
	if(m_pGmToolMng)						{m_pGmToolMng->setEventCallback(pCallback);}
}

void yb_GmToolUIControl::FrameMove(DWORD dwElapsedTime)			
{
	if(m_pGmToolMng)						{m_pGmToolMng->FrameMove( dwElapsedTime );}
}

void yb_GmToolUIControl::render(IDirect3DDevice9* pDevice)
{
	if(m_pGmToolMng && m_pGmToolMng->getVisible())
		m_pGmToolMng->render(pDevice);
}

