#include ".\..\UI\anw_Base.h"
#include "ID_Tutorial.h"
#include "../Main/General.h"

void CALLBACK OnGUIEvent_Tutorial(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

//=================================================================================================================
//=================================================================================================================
// ctor/dtor
yb_TutorialUIControl::yb_TutorialUIControl()
{
	m_pTutorial_MsgBox = 0;
	m_pTuturial_OkCancel = 0;
	m_pTuturial_Title = 0;
	m_pQuestRewardWindow = 0;
	m_pBackGroundMain = 0;
	m_pBackGroundMiniMap= 0;
	m_pBackGroundEnergy = 0;
	m_bDrawRightMsgBox = false;
	m_bDrawLeftMsgBox = false;
	m_nPreTutorNum  = 0;
}
yb_TutorialUIControl::~yb_TutorialUIControl()
{		
	ANW_SAFE_DEREF(m_pTutorial_MsgBox);
	ANW_SAFE_DEREF(m_pTuturial_OkCancel);
	ANW_SAFE_DEREF(m_pTuturial_Title);
	ANW_SAFE_DEREF(m_pQuestRewardWindow);
	ANW_SAFE_DEREF(m_pBackGroundMain);
	ANW_SAFE_DEREF(m_pBackGroundMiniMap);
	ANW_SAFE_DEREF(m_pBackGroundEnergy);
}

bool yb_TutorialUIControl::loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename)
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

bool yb_TutorialUIControl::loadUI_All(){

	if(loadUI(&m_pTutorial_MsgBox, L"FaceMsgbox.sav") == false ) return false;

	if(loadUI(&m_pTuturial_OkCancel, L"tutorialokcancel.sav") == false ) return false;

	if(loadUI(&m_pTuturial_Title, L"tutorialTitle.sav") == false ) return false;
	if(loadUI(&m_pQuestRewardWindow, L"QuestGiveWindow.sav") == false ) return false;

	if(loadUI(&m_pBackGroundMain, L"tutGroundMain.sav") == false ) return false;
	if(loadUI(&m_pBackGroundMiniMap, L"tutGroundMiniMap.sav") == false ) return false;
	if(loadUI(&m_pBackGroundEnergy, L"tutGroundEnergy.sav") == false ) return false;

	return true;
}

void yb_TutorialUIControl::setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback)
{	
	if(m_pTutorial_MsgBox)						{m_pTutorial_MsgBox->setEventCallback(pCallback);}
	if(m_pTuturial_OkCancel)						{m_pTuturial_OkCancel->setEventCallback(pCallback);}
	if(m_pTuturial_Title)						{m_pTuturial_OkCancel->setEventCallback(pCallback);}
	if(m_pQuestRewardWindow)						{m_pTuturial_OkCancel->setEventCallback(pCallback);}
	if(m_pBackGroundMain)						{m_pTutorial_MsgBox->setEventCallback(pCallback);}
	if(m_pBackGroundMiniMap)						{m_pTuturial_OkCancel->setEventCallback(pCallback);}
	if(m_pBackGroundEnergy)						{m_pTuturial_OkCancel->setEventCallback(pCallback);}
}

void yb_TutorialUIControl::RightMsgBoxInit()			
{
	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();
	ANW::StatusUI_Button* pControl1 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARMSGBOX  ) ;
	pControl1->setPosition(1024,626,0);

	ANW::StatusUI_ListBox_Target  *pControlList = ( ANW::StatusUI_ListBox_Target* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_LISTBOX  ) ;
	pControlList->setPosition(1024 + 168.0f,665.f,0.f);
	ANW::StatusUI_Button *pControl2 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARMSGNEXTBN  ) ;
	pControl2->setVisible(false);

	ANW::StatusUI_TextButton *pTextButton = ( ANW::StatusUI_TextButton* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_MYNAME_STATIC  ) ;
	pTextButton->setPosition(1024 + 680.0f,630.0f,0);
}

void yb_TutorialUIControl::RightCharImgInit()			
{
	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();
	ANW::StatusUI_Button* pControl1 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARFACEBOX  ) ;
	pControl1->setPosition(1024 + 748.0f,500.0f,0);
}

void yb_TutorialUIControl::LeftMsgBoxInit()			
{
	ANW::StatusUI_Button* pControl1 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERMSGBOX  ) ;
	pControl1->setPosition(-1024 ,125,0);

	
	ANW::StatusUI_Button *pControl2 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERNEXTBN  ) ;
	pControl2->setVisible(false);

	ANW::StatusUI_ListBox_Target  *pControlList = ( ANW::StatusUI_ListBox_Target* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_LISTBOX2 ) ;
	pControlList->setPosition(-1024 + 267,165.0f,0.f);
	

	ANW::StatusUI_TextButton *pTextButton = ( ANW::StatusUI_TextButton* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERNAME_STATIC  ) ;
	pTextButton->setPosition(-1024 + 271.0f ,126.0f,0);
}

void yb_TutorialUIControl::LeftCharImgInit()			
{
	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();
	ANW::StatusUI_Button* pControl1 = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERCHARBOX  ) ;
	pControl1->setPosition(-1024 ,0.0f,0.f);
}

void yb_TutorialUIControl::ProcessRightMsgbox( INT nElapsedTime )		
{
	FLOAT fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();

	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARMSGBOX  ) ;
	D3DXVECTOR3 vTempPos = pControl->getPosition();

	if( vTempPos.x <= 0 ) 
	{
		vTempPos.x = 0;
		fMove = 0;
	}
	pControl->setPosition( D3DXVECTOR3( vTempPos.x - fMove, vTempPos.y, vTempPos.z ) );
	fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	ANW::StatusUI_ListBox_Target* pControlList = ( ANW::StatusUI_ListBox_Target* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_LISTBOX  ) ;
	D3DXVECTOR3 vTempPos2 = pControlList->getPosition();
	if( vTempPos2.x <= 168.0f ) 
	{
		vTempPos2.x = 168.0f;
		fMove = 0;

	}
	pControlList->setPosition( D3DXVECTOR3( vTempPos2.x - fMove , vTempPos2.y  , vTempPos2.z ) );
	fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	ANW::StatusUI_TextButton* pControlTextButton = ( ANW::StatusUI_TextButton* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_MYNAME_STATIC  ) ;
	vTempPos = pControlTextButton->getPosition();
	if( vTempPos.x <= 670.0f) 
	{
		vTempPos.x = 670.0f;
		fMove = 0;

	}
	pControlTextButton->setPosition( D3DXVECTOR3( vTempPos.x - fMove , vTempPos.y  , vTempPos.z ) );
}

void yb_TutorialUIControl::ProcessRightCharImg( INT nElapsedTime )			
{
	FLOAT fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;

	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();
	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARFACEBOX  ) ;
	D3DXVECTOR3 vTempPos = pControl->getPosition();


	if( vTempPos.x <= 748 ) 
	{
		vTempPos.x = 748;
		fMove = 0;
		ANW::StatusUI_Button *pConBtn = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORCHARMSGNEXTBN  ) ;
		pConBtn->setVisible(TRUE);

		

	}
	pControl->setPosition( D3DXVECTOR3( vTempPos.x - fMove, vTempPos.y , vTempPos.z ) );
}

void yb_TutorialUIControl::ProcessLeftMsgbox( INT nElapsedTime )		
{
	FLOAT fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();

	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERMSGBOX  ) ;
	D3DXVECTOR3 vTempPos = pControl->getPosition();

	if( vTempPos.x >= 0 ) 
	{
		vTempPos.x = 0;
		fMove = 0;
	}
	pControl->setPosition( D3DXVECTOR3( vTempPos.x + fMove, vTempPos.y , vTempPos.z ) );
	fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	ANW::StatusUI_ListBox_Target* pControlList = ( ANW::StatusUI_ListBox_Target* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_LISTBOX2  ) ;
	vTempPos = pControlList->getPosition();
	if( vTempPos.x >= 270 ) 
	{
		vTempPos.x = 270;
		fMove = 0;

	}
	pControlList->setPosition( D3DXVECTOR3( vTempPos.x + fMove , vTempPos.y  , vTempPos.z ) );
	fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;
	ANW::StatusUI_TextButton* pControlTextButton = ( ANW::StatusUI_TextButton* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERNAME_STATIC  ) ;
	vTempPos = pControlTextButton->getPosition();
	if( vTempPos.x >= 271.0f) 
	{
		vTempPos.x = 271.0f;
		fMove = 0;

	}
	pControlTextButton->setPosition( D3DXVECTOR3( vTempPos.x + fMove , vTempPos.y  , vTempPos.z ) );
}


void yb_TutorialUIControl::ProcessLeftCharImg( INT nElapsedTime )			
{
	FLOAT fMove = ( FLOAT( nElapsedTime ) / 1000.0f ) * 1500;

	//ANW::StatusUI_Manager* pControlMng = m_pTutorialUI->GetUiMngTutorial();
	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERCHARBOX  ) ;
	D3DXVECTOR3 vTempPos = pControl->getPosition();


	if( vTempPos.x >= 0 ) 
	{
		vTempPos.x = 0;
		fMove = 0;
		ANW::StatusUI_Button *pConBtn = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer( ID_TUTORIAL_OTHERNEXTBN  ) ;
		pConBtn->setVisible(TRUE);

	}
	pControl->setPosition( D3DXVECTOR3( vTempPos.x + fMove, vTempPos.y , vTempPos.z ) );
}

void yb_TutorialUIControl::ShowOkCancelBox( bool bShow )
{
	ANW::StatusUI_Button* pControl;
	if( bShow)
	{
		pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer(ID_TUTORCHARMSGNEXTBN);
		if(pControl)
		{
			pControl->setHotkey(9999);
			pControl->enableFocus(false);
		}
		pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNEXTBN);
		if(pControl)
		{
			pControl->setHotkey(9999);
			pControl->enableFocus(false);
		}

	}
	else
	{
		pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer(ID_TUTORCHARMSGNEXTBN);
		if(pControl)
		{
			pControl->enableFocus(true);
			pControl->setHotkey(VK_RETURN);
		}
		pControl = ( ANW::StatusUI_Button* )m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNEXTBN);
		if(pControl)
		{
			pControl->enableFocus(true);
			pControl->setHotkey(VK_RETURN);
		}
	}

	pControl = ( ANW::StatusUI_Button* )m_pTuturial_OkCancel->findControlPointer( ID_TUTORIAL_OKCANCELBOX ) ;
	pControl->setVisible( bShow );
	pControl = ( ANW::StatusUI_Button* )m_pTuturial_OkCancel->findControlPointer( ID_TUTORIAL_OKCANCELBOX_OK ) ;
	pControl->setVisible( bShow );
	pControl->setHotkey(VK_RETURN);
	pControl->enableFocus(true);
	pControl = ( ANW::StatusUI_Button* )m_pTuturial_OkCancel->findControlPointer( ID_TUTORIAL_OKCANCELBOX_CANCEL ) ;
	pControl->setVisible( bShow );
	ANW::StatusUI_TextButton *pConText = ( ANW::StatusUI_TextButton* )m_pTuturial_OkCancel->findControlPointer( ID_TUTORIAL_OKCANCELBOX_TEXT  ) ;
	pConText->setVisible( bShow );
}

void yb_TutorialUIControl::ShowTitleImg( bool bShow ,int nCharIndex)
{
	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTuturial_Title->findControlPointer( ID_TUTORIAL_TITLE ) ;
	pControl->setVisible( bShow );

	int nTitleImgIndex = nCharIndex;

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
					float fUV[8];
					
					if( nTitleImgIndex == 0 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = 0.5f/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = 0.5f/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = 96.f/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = 96.f/ 1024.f;
					}
					else if( nTitleImgIndex == 1 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = 195.5f/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = 195.5f/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = (195.f + 96.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = (195.f + 96.f)/ 1024.f;
					}
					else if( nTitleImgIndex == 2 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = 389.5f/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] =  389.5f/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = ( 389.5f + 96.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = ( 389.5f + 96.f)/ 1024.f;
					}
					else if( nTitleImgIndex == 3 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = 583.5f/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = 583.5f/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = (583.5f + 96.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = (583.5f + 96.f)/ 1024.f;
					}
					

					pRectItem->setTexCoords( fUV );
				}
			}
		}
	}
}

void yb_TutorialUIControl::ShowTitleEndImg( bool bShow ,int nCharIndex )
{
	ANW::StatusUI_Button* pControl = ( ANW::StatusUI_Button* )m_pTuturial_Title->findControlPointer( ID_TUTORIAL_TITLEEND ) ;
	pControl->setVisible( bShow );

	int nTitleImgIndex = nCharIndex;

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
					float fUV[8];

					if( nTitleImgIndex == 0 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] =96.5f/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = 96.5f/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = (96.f + 96.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = (96.f + 96.f)/ 1024.f;
					}
					else if( nTitleImgIndex == 1 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = (195.5f + 95.f)/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = (195.5f + 95.f)/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = (195.f + 96.f + 95.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = (195.f + 96.f+ 95.f)/ 1024.f;
					}
					else if( nTitleImgIndex == 2 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = (389.5f + 95.f)/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] =  (389.5f + 95.f)/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = ( 389.5f + 96.f+ 95.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = ( 389.5f + 96.f+ 95.f)/ 1024.f;
					}
					else if( nTitleImgIndex == 3 )
					{
						fUV[ 0 ] = 0.5f / 1024.f;					fUV[ 1 ] = (583.5f+ 95.f)/ 1024.f;
						fUV[ 2 ] = 489.f/ 1024.f;			fUV[ 3 ] = (583.5f+ 95.f)/ 1024.f;
						fUV[ 4 ] = 489.f/ 1024.f;			fUV[ 5 ] = (583.5f + 96.f+ 95.f)/ 1024.f;
						fUV[ 6 ] = 0.5f/ 1024.f;					fUV[ 7 ] = (583.5f + 96.f+ 95.f)/ 1024.f;
					}


					pRectItem->setTexCoords( fUV );
				}
			}
		}
	}
}

void yb_TutorialUIControl::SetOkFocus()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_OK);
	if(pControl)
	{
		pControl->enableFocus(true);
		pControl->setHotkey(VK_RETURN);
		m_pTuturial_OkCancel->setFocus(pControl);
	}
	pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_CANCEL);
	if(pControl)
	{
		pControl->setHotkey(9999);
	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORCHARMSGNEXTBN);
	if(pControl)
	{
		pControl->setHotkey(9999);
	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNEXTBN);
	if(pControl)
	{
		pControl->setHotkey(9999);
	}
}

void yb_TutorialUIControl::SetCancelFocus()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_CANCEL);
	if(pControl)
	{
		pControl->enableFocus(true);
		pControl->setHotkey(VK_RETURN);
		m_pTuturial_OkCancel->setFocus(pControl);
	}
	pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_OK);
	if(pControl)
	{
		pControl->setHotkey(9999);
	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORCHARMSGNEXTBN);
	if(pControl)
	{
		pControl->setHotkey(9999);

	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNEXTBN);
	if(pControl)
	{
		pControl->setHotkey(9999);
	}
}

void yb_TutorialUIControl::SetNextBnFocus()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_CANCEL);
	if(pControl)
	{
		pControl->enableFocus(false);
		pControl->setHotkey(9999);
	}
	pControl = m_pTuturial_OkCancel->findControlPointer(ID_TUTORIAL_OKCANCELBOX_OK);
	if(pControl)
	{
		pControl->enableFocus(false);
		pControl->setHotkey(9999);
	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORCHARMSGNEXTBN);
	if(pControl)
	{
		//pControl->enableFocus(true);
		//pControl->setHotkey(VK_RETURN);
		//m_pTuturial_OkCancel->setFocus(pControl);

	}
	pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNEXTBN);
	if(pControl)
	{
		pControl->enableFocus(true);
		pControl->setHotkey(VK_RETURN);
		m_pTutorial_MsgBox->setFocus(pControl);
	}
}

void yb_TutorialUIControl::SetRightMsgText( char *pszText)
{
	ANW::StatusUI_Control* pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_LISTBOX);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true, "\0",pszText, D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
	}
}

void yb_TutorialUIControl::SetLeftMsgText(  char *pszText)
{
	ANW::StatusUI_Control* pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_LISTBOX2);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",pszText, D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
	}

}

void yb_TutorialUIControl::SetRightCharName( char *pszText)
{


	ANW::StatusUI_Control* pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_MYNAME_STATIC);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(pszText);
		
	}
}

void yb_TutorialUIControl::SetLeftCharName( char *pszText)
{


	ANW::StatusUI_Control* pControl = m_pTutorial_MsgBox->findControlPointer(ID_TUTORIAL_OTHERNAME_STATIC);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(pszText);

	}
}

bool yb_TutorialUIControl::IsOkCancelBox()
{
	ANW::StatusUI_TextButton *pControl = ( ANW::StatusUI_TextButton* )m_pTuturial_OkCancel->findControlPointer( ID_TUTORIAL_OKCANCELBOX ) ;
	return pControl->getVisible();
}

wchar_t* yb_TutorialUIControl::CharToWChar(const char* pstrSrc)
{
	ANW_ASSERT(pstrSrc);
	int nLen = strlen(pstrSrc) + 1;

	wchar_t* pwstr = (LPWSTR) malloc( sizeof(wchar_t)*nLen);
	mbstowcs(pwstr,pstrSrc,nLen);

	return pwstr;
}

void yb_TutorialUIControl::HideTutHelp()
{
	for( int i = ID_TUTORIAL_KEY_RIGHT; i <= ID_TUTORIAL_HELPBG;i++)
	{
		ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(i);
		//if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
		//{
		//	ANW::StatusUI_Button* pTextButton = (ANW::StatusUI_Button*)pControl;
			pControl->setVisible(false);

		//}
	}
}

void yb_TutorialUIControl::ShowHelpMove()
{
	

	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_RIGHT);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"이동 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[→] 를 눌러 이동하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpRun()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_RIGHT);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_RIGHT2);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f + 44.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"달리기 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[→]+[→] 를 눌러 이동하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpJump()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_W);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"점프 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[W] 를 눌러 절벽을 뛰어넘으십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpAttack1()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_E);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"공격 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[E] 를 눌러 적을 공격하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpAttack2( int nChar )
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_DOWN);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_UP);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f + 44.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_PLUS);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(401.f,63.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_E);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(426.f ,51.f,0.f);
	}
	
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		if( nChar == 1)
			pTextButton->setRectItemText(L"회피 연습");
		else
			pTextButton->setRectItemText(L"강타 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		if( nChar == 1)
			pListBoxT->addItem(true,"\0",L"[↓][↑]+[E] 를 눌러 적을 회피하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		else
			pListBoxT->addItem(true,"\0",L"[↓][↑]+[E] 를 눌러 적을 공격하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpAttack3()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_UP);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_DOWN);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f + 44.f,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_PLUS);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(401.f,63.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_E);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(426.f ,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"제압 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[↑][↓]+[E] 를 눌어 적을 제압하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpAttack4()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_RIGHT);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}
// 	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_DOWN);
// 	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
// 	{
// 		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
// 		pButton->setVisible(true);
// 		pButton->setPosition(310.f + 44.f,51.f,0.f);
// 	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_PLUS);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(401.f,63.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_RIGHT2);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(426.f ,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"돌진 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[→][→] 를 눌어 돌진하여 적을 공격하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpAttack5()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_W);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}
	// 	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_DOWN);
	// 	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	// 	{
	// 		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
	// 		pButton->setVisible(true);
	// 		pButton->setPosition(310.f + 44.f,51.f,0.f);
	// 	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_PLUS);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(401.f,63.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_E);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(426.f ,51.f,0.f);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"필살기 연습");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[W]+[E] 를 눌러 필살기를 사용하십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}

void yb_TutorialUIControl::ShowHelpPickUp()
{
	ANW::StatusUI_Control* pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_KEY_E);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
		pButton->setPosition(310.f,51.f,0.f);
	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_HELPBG);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName())
	{
		ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
		pButton->setVisible(true);
	}
	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_SKILLNAME);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
		pTextButton->setRectItemText(L"아이템줍기");
		pTextButton->setVisible(true);
	}

	pControl = m_pTuturial_Title->findControlPointer(ID_TUTORIAL_DESC_LIST);
	if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
	{
		ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
		pListBoxT->removeAllItems();
		pListBoxT->addItem(true,"\0",L"[E] 를 눌러 아이템을 주우십시오.", D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 255, 255), 0);
		pListBoxT->setVisible(true);
	}

}


void yb_TutorialUIControl::SetHelpShow( int nTutoriolNum ,int nChar )
{
	if(m_nPreTutorNum == nTutoriolNum ) return;

	m_nPreTutorNum = nTutoriolNum;
	
	switch( nTutoriolNum )
	{
	case TUT_MOVE:
		{
			HideTutHelp();
			ShowHelpMove();

		}
		break;
	case TUT_RUN:
		{
			HideTutHelp();
			ShowHelpRun();
		}
		break;
	case TUT_JUMP:
		{
			HideTutHelp();
			ShowHelpJump();
		}
		break;
	case TUT_ATTACK1:
		{
			HideTutHelp();
			ShowHelpAttack1();
		}
		break;
	case TUT_ATTACK2:
		{
			HideTutHelp();
			ShowHelpAttack2(nChar);
		}
		break;
	case TUT_ATTACK3:
		{
			HideTutHelp();
			ShowHelpAttack3();
		}
		break;
	case TUT_ATTACK4:
		{
			HideTutHelp();
			ShowHelpAttack4();
		}
		break;
	case TUT_PICKUP:
		{
			HideTutHelp();
			ShowHelpPickUp();
		}
		break;
	case TUT_ATTACK5:
		{
			HideTutHelp();
			ShowHelpAttack5();
		}
		break;
	default:
		{
			//HideTutHelp();
		}
	
	}
}

void yb_TutorialUIControl::SetShowMainUi( bool bShow )
{
	m_pBackGroundMain->setVisible(bShow);
	m_pBackGroundMiniMap->setVisible(bShow);
	m_pBackGroundEnergy->setVisible(bShow);


}

void yb_TutorialUIControl::SetChatWindowShow( bool bShow  )
{
/*
	if( m_pBackGroundMain )
	{
		for(int i = ID_TUTORIAL_CHATTING_MENU_BG; i<= ID_TUTORIAL_CHATTING_BUTTON_TYPECHICE4; i++)
		{
			ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pBackGroundMain->findControlPointer( i );
			if( pControl == NULL) 
				continue;

			pControl->setVisible(bShow);
			pControl->setEnabled(bShow);
		}

	}
*/

}

VOID yb_TutorialUIControl::setMyLv_Name( const int& nLv, const CStringW& strName , const int& nOrdinal)							// 레벨 이름
{
	if( m_pBackGroundEnergy )
	{
		ANW::StatusUI_TextButton* pControl = (ANW::StatusUI_TextButton*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_MYENERGY_LV );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			CHAR szLv[64];
			sprintf( szLv, "%d", nLv );
			pControl->setRectItemText( szLv );
			pControl->setVisible(true);
		}
		pControl = (ANW::StatusUI_TextButton*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_MYENERGY_NAME );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			pControl->setVisible(true);
			pControl->setRectItemText( strName );
		}

		m_pBackGroundEnergy->setControlVisibility(ID_TUTORIAL_MYENERGY_BACKGROUND, true );		
	}
	{	
		ANW::StatusUI_Button_SharedRect* pControl = (ANW::StatusUI_Button_SharedRect*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_MYENERGY_FACE );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button_SharedRect::RTTI.getName() )
		{
			pControl->setCharRectID( nOrdinal );
			pControl->setVisible( true );
		}
	}

}

VOID yb_TutorialUIControl::SetMyExp( const UINT& nMax, const UINT& nCurr )				// EXP
{
	/*
	if( m_pBackGroundMain )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundMain->findControlPointer( ID_TUTORIAL_EXP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			pControl->setEnergy( nMax, nCurr );
		}

	}
	*/
}

VOID yb_TutorialUIControl::SetMyStamina( const int&nMax, const int& nCurr, const UINT& nNow )			// 스테미너
{
	// 하단
	if( m_pBackGroundMain )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundMain->findControlPointer(ID_TUTORIAL_STAMINA);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			pControl->setEnergy( nMax, nCurr );
		}

		ANW::StatusUI_SubEnergy* pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundMain->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_2_S );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergy( nMax, nCurr, nNow );
		}
		pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundMain->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_2_ALPHA_S );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergyAlpha( nMax, nCurr, nNow );
		}
	}

	// 상단
	if( m_pBackGroundEnergy )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundEnergy->findControlPointer(ID_TUTORIAL_MYENERGY_STAMINA);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			pControl->setVisible(true);
			pControl->setEnergy( nMax, nCurr );
		}
		ANW::StatusUI_SubEnergy* pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_1_S );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergy( nMax, nCurr, nNow );
		}
		pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_1_ALPHA_S );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergyAlpha( nMax, nCurr, nNow );
		}
	}
}
VOID yb_TutorialUIControl::SetMyEnergy( const UINT&nMax, const UINT& nCurr, const UINT& nNow )			// 에너지
{
	// 하단
	if( m_pBackGroundMain )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundMain->findControlPointer(ID_TUTORIAL_ENERGY);

		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName())
		{
			pControl->setEnergy( nMax, nCurr );
		}

		ANW::StatusUI_SubEnergy* pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundMain->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_2 );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergy( nMax, nCurr, nNow );
		}

		pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundMain->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_2_ALPHA );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergyAlpha( nMax, nCurr, nNow );
		}

	}

	// 상단
	if( m_pBackGroundEnergy )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundEnergy->findControlPointer(ID_TUTORIAL_MYENERGY_ENERGY);

		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName())
		{
			pControl->setVisible(true);
			pControl->setEnergy( nMax, nCurr );
		}

		ANW::StatusUI_SubEnergy* pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_1 );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergy( nMax, nCurr, nNow );
		}

		pRealControl = ( ANW::StatusUI_SubEnergy* )m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_MY_1_ALPHA );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergyAlpha( nMax, nCurr, nNow );
		}
	}
}

VOID yb_TutorialUIControl::SetTownInit()												// 마을일 경우 백그라운드 초기화
{
	/*
	// 에너지,, 파티 타겟 내정보
		if( m_pBackGroundEnergy )
		{
			for( int i = ID_TUTORIAL_TAGET_BACKGROUND1; i <= ID_TUTORIAL_PARTY_STAMINA3; ++i )
			{
				m_pBackGroundEnergy->setControlVisibility(i,false);
			}
	
			m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_TAGET, false );
			m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA, false );		
			m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_PARTY_1, false );
			m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_PARTY_2, false );
			m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_PARTY_3, false );
		}
		// 시계
		if( m_pBackGroundMiniMap )
		{
			m_pBackGroundMiniMap->setControlVisibility(ID_TUTORIAL_MINIMAP_TIME_BACKGROUND1, false);
			m_pBackGroundMiniMap->setControlVisibility(ID_TUTORIAL_MINIMAP_TIME_BACKGROUND2, false);
			m_pBackGroundMiniMap->setControlVisibility(ID_TUTORIAL_MINIMAP_TIME, false);
		}
	
		if( m_pBackGroundMain )
		{
			// 기본스킬
			for( int  i = ID_TUTORIAL_SKILLICON_MAINGAME_POS01; i <= ID_TUTORIAL_SKILLICON_MAINGAME_POS20; ++i )
			{
				ANW::StatusUI_Shared_SkillIcon* pControl = (ANW::StatusUI_Shared_SkillIcon*)m_pBackGroundMain->findControlPointer(i);
				if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
				{				
					pControl->setUseCoolTime(false);
					pControl->setUseStockCount(false);
					pControl->setUseTextHotKey(false);
					pControl->setSkillEnabled( true );
	
	
					pControl->setRectID(-1);
					pControl->setVisible(true);
				}
			}
			// 팀전스킬
			for( int i = ID_TUTORIAL_SKILLICON_MAINGAME_POSA; i <= ID_TUTORIAL_SKILLICON_MAINGAME_POSDD; ++i )
			{
				ANW::StatusUI_Shared_SkillIcon* pControl = (ANW::StatusUI_Shared_SkillIcon*)m_pBackGroundMain->findControlPointer(i);
				if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
				{
					pControl->setUseCoolTime(false);
					pControl->setUseStockCount(false);
					pControl->setUseTextHotKey(false);
					pControl->setSkillEnabled( true );
	
					pControl->setRectID(-1);
					pControl->setVisible(true);
					pControl->setEnabled(false);
				}
			}
		}
	
		// 버프, 부활시간
		for( int i = 0 ;i <5; ++i )
		{
			for( int j = 0;j < 5; ++j)
				SetBufVisible(i, j, false );
	
			SetRegenTime_Visible(i, false);
		}*/
	

}

VOID yb_TutorialUIControl::SetBufVisible( const int& nOrdinal, const int& nBufOrdinal, const bool& bFlag )
{
	/*
	if(m_pBackGroundEnergy)
	{
		int nControlID = ID_TUTORIAL_BUFF_CHAR00_00;

		nControlID = nControlID + nOrdinal*5 + nBufOrdinal;

		m_pBackGroundEnergy->setControlVisibility( nControlID, bFlag );
	}
	*/
}

VOID yb_TutorialUIControl::SetRegenTime_Visible( const int& nOrdinal, const bool& bFlag )						// 0 == 자신 1~3 == 파티원 활성 비활성
{
	/*
	if(m_pBackGroundEnergy)
	{
		int nControlID = ID_TUTORIAL_CHAR0_REGENTIME;		
		nControlID = nControlID + nOrdinal;
		ANW::StatusUI_Control* pControl = m_pBackGroundEnergy->findControlPointer(nControlID);
		if(pControl)
		{
			pControl->setVisible(bFlag);
		}
	}
	*/
}


VOID yb_TutorialUIControl::SetTagetEnergyVisible( const bool& bFlag )									// 타겟에너지 활성&비활성
{
	if( m_pBackGroundEnergy )
	{
		for( int i = ID_TUTORIAL_TAGET_BACKGROUND1; i <= ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA_GENERAL; ++i )
		{
			m_pBackGroundEnergy->setControlVisibility( i , false);
		}

		m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_TAGET_BACKGROUND_GENERAL , bFlag);
		m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_TAGET_ENERGY_GENERAL , bFlag);
		m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_TAGET_GENERAL , bFlag);
		m_pBackGroundEnergy->setControlVisibility( ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA_GENERAL , bFlag);
	}
}

VOID yb_TutorialUIControl::SetTagetLv_Name( const int nLevel, const CStringW& strName )				// 타겟 레벨 이름
{
	if( m_pBackGroundEnergy )
	{
		CHAR szBuf[32];
		sprintf( szBuf, "%d", nLevel );
		m_pBackGroundEnergy->setTextButton_Text( ID_TUTORIAL_TAGET_LV, szBuf );
		m_pBackGroundEnergy->setTextButton_Text( ID_TUTORIAL_TAGET_NAEM, strName );
	}
}

VOID yb_TutorialUIControl::SetTagetEnergy( const UINT& nMax, const UINT& nCur, const UINT& nNow )						// 타겟에너지
{
	if( m_pBackGroundEnergy )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_TAGET_ENERGY_GENERAL );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			pControl->setEnergy( nMax, nCur );
		}

		ANW::StatusUI_SubEnergy* pRealControl = (ANW::StatusUI_SubEnergy*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_TAGET_GENERAL );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergy( nMax, nCur, nNow );
		}

		pRealControl = (ANW::StatusUI_SubEnergy*)m_pBackGroundEnergy->findControlPointer( ID_TUTORIAL_REAL_ENERGY_TAGET_AlPHA_GENERAL );
		if( pRealControl && pRealControl->getRTTI()->getName() == ANW::StatusUI_SubEnergy::RTTI.getName() )
		{
			pRealControl->setProgressEnergyAlpha( nMax, nCur, nNow );
		}
	}
}

VOID yb_TutorialUIControl::SetWorldMap( bool bShow )
{
	
	/*
	if( m_pBackGroundMain )
		{
			for(int i = ID_TUTORIAL_MINIMAP; i<= ID_TUTORIAL_MINIMAP_TIME; i++)
			{
				ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pBackGroundMiniMap->findControlPointer( i );
				if( pControl == NULL) 
					continue;
	
				pControl->setVisible(bShow);
			}
		}
	
		if( m_pBackGroundMain )
		{
			for(int i = ID_TUTORIAL_WORLDMAP_BACKGROUND; i<= ID_TUTORIAL__CHANNEL; i++)
			{
				ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pBackGroundMain->findControlPointer( i );
				if( pControl == NULL) 
					continue;
	
				pControl->setVisible(bShow);
			}
		}*/
	
}

void	yb_TutorialUIControl::SetQuestRewardWindowShow( bool bShow )
{
	if( m_pQuestRewardWindow )
	{
		m_pQuestRewardWindow->setVisible( bShow );
	}
}
void	yb_TutorialUIControl::SetQuestMoney( int nMoney )
{
	if( m_pQuestRewardWindow )
	{
		ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_GOLD );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
		{
			ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
			char szbuf[1024];
			sprintf(szbuf,"%d",nMoney);
			pTextButton->setRectItemText(szbuf);

		}
	}
}
void	yb_TutorialUIControl::SetQuestExp( int nExp )
{
	if( m_pQuestRewardWindow )
	{
		ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_EXP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
		{
			ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
			char szbuf[1024];
			sprintf(szbuf,"%d",nExp);
			pTextButton->setRectItemText(szbuf);

		}
	}	
}
void	yb_TutorialUIControl::SetQuestItem(int nIndex,char *szItemImgName,char *szItemName)
{
	ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME1 + nIndex );
	if(pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)pControl;
	
		pTextButton->setRectItemText(szItemName);

	}

	pControl = ( ANW::StatusUI_Button* )m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_EXP + nIndex ) ;

	wchar_t *wszbuf = CharToWChar(szItemImgName);

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
					pRectItem->setTexture(wszbuf);
				}
			}
		}
	}
	SAFE_DELETE(wszbuf);
}

void yb_TutorialUIControl::SetQuestItemVisible(int nIndex,bool bShow)
{
	ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME1 + nIndex );
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMIMG1 + nIndex );
	pControl->setVisible(bShow);
}

void yb_TutorialUIControl::SetQuestItemAllVisible(bool bShow)
{
	ANW::StatusUI_Control* pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME1);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME2);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME3);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMNAME4);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMIMG1);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMIMG2);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMIMG3);
	pControl->setVisible(bShow);
	pControl = (ANW::StatusUI_Control*)m_pQuestRewardWindow->findControlPointer( ID_QUEST_GIVE_WINDOW_ITEMIMG4);
	pControl->setVisible(bShow);
}

void yb_TutorialUIControl::FrameMove(DWORD dwDTime)			
{
	if(m_pBackGroundMain)						{m_pBackGroundMain->FrameMove(dwDTime);}
	if(m_pBackGroundMiniMap)						{m_pBackGroundMiniMap->FrameMove(dwDTime);}
	if(m_pBackGroundEnergy)						{m_pBackGroundEnergy->FrameMove(dwDTime);}
	if(m_pQuestRewardWindow)						{m_pQuestRewardWindow->FrameMove(dwDTime);}

	if(m_pTutorial_MsgBox)						{m_pTutorial_MsgBox->FrameMove(dwDTime);}
	if(m_pTuturial_OkCancel)						{m_pTuturial_OkCancel->FrameMove(dwDTime);}
	if(m_pTuturial_Title)						{m_pTuturial_Title->FrameMove(dwDTime);}
	
}

void yb_TutorialUIControl::render(IDirect3DDevice9* pDevice)
{
	if(m_pBackGroundMain && m_pBackGroundMain->getVisible())
		m_pBackGroundMain->render(pDevice);
	if(m_pBackGroundMiniMap && m_pBackGroundMiniMap->getVisible())
		m_pBackGroundMiniMap->render(pDevice);
	if(m_pBackGroundEnergy && m_pBackGroundEnergy->getVisible())
		m_pBackGroundEnergy->render(pDevice);
	if(m_pQuestRewardWindow && m_pQuestRewardWindow->getVisible())
		m_pQuestRewardWindow->render(pDevice);

	if(m_pTutorial_MsgBox && m_pTutorial_MsgBox->getVisible())
		m_pTutorial_MsgBox->render(pDevice);
	if(m_pTuturial_OkCancel && m_pTuturial_OkCancel->getVisible())
		m_pTuturial_OkCancel->render(pDevice);
	if(m_pTuturial_Title && m_pTuturial_Title->getVisible())
		m_pTuturial_Title->render(pDevice);

}

// void CALLBACK OnGUIEvent_Tutorial(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext)
// {
// 	if(pControl)
// 	{	
// 	}
// }