/*
file : ID_Maingame.cpp
*/

//r#include ".\__header\Engine\anw_dxengine.h"
#include ".\__header\UISource\anw_Base.h"
#include "ID_Maingame.h"

static yb_MainUIControl* g_pMainControl = 0;

//=================================================================================================================
//=================================================================================================================
// ctor/dtor
yb_MainUIControl::yb_MainUIControl()
{
	m_pStatusUI_Main	= 0;
	m_pStatusUI_Char	= 0;
	m_pStatusUI_Dash	= 0;
	m_pStatusUI_Result_BackGround_1	= 0;
	m_pStatusUI_Result_BackGround_2	= 0;
	m_pStatusUI_Result_Fild = 0;
	m_pStatusUI_Result_VS = 0;
	m_pStatusUI_Result_KILL = 0;
	m_pStatusUI_Result_QUEST_1 = 0;
	m_pStatusUI_Result_QUEST_2 = 0;


	m_pStatusUI_Story	= 0;
	m_pModal_ExitQuestion	= 0;
	m_uDashBoardIndex	= 0;
	m_nGameMode = PW_GAME_BATTLE;
	m_pModal_Resurrection = 0;
	m_pStatusUI_Key		= 0;
	m_pModal_Question	= 0;
	m_pModal_Leaving	= 0;

	m_pGameMyBag			= NULL;



	g_pMainControl = this;
}
yb_MainUIControl::~yb_MainUIControl()
{	
	ANW_SAFE_DEREF(m_pStatusUI_Char);
	ANW_SAFE_DEREF(m_pStatusUI_Dash);
	ANW_SAFE_DEREF(m_pStatusUI_Result_BackGround_1);
	ANW_SAFE_DEREF(m_pStatusUI_Result_BackGround_2);
	ANW_SAFE_DEREF(m_pStatusUI_Result_Fild);
	ANW_SAFE_DEREF(m_pStatusUI_Result_VS);
	ANW_SAFE_DEREF(m_pStatusUI_Result_KILL);
	ANW_SAFE_DEREF(m_pGameMyBag);
	ANW_SAFE_DEREF(m_pStatusUI_Result_QUEST_1);
	ANW_SAFE_DEREF(m_pStatusUI_Result_QUEST_2);
	ANW_SAFE_DEREF(m_pModal_ExitQuestion);
	ANW_SAFE_DEREF(m_pStatusUI_Story);
	ANW_SAFE_DEREF(m_pModal_Resurrection);
	ANW_SAFE_DEREF(m_pStatusUI_Key);
	ANW_SAFE_DEREF(m_pModal_Question);
	ANW_SAFE_DEREF(m_pStatusUI_Main);
	ANW_SAFE_DEREF(m_pModal_Leaving);


	g_pMainControl = 0;
}

void yb_MainUIControl::GameAllEnable( const bool& bFlag )
{
	if( m_pStatusUI_Main )	{m_pStatusUI_Main->setEnabled( bFlag ); }
	if( m_pStatusUI_Char )	{m_pStatusUI_Char->setEnabled( bFlag ); }
	if( m_pStatusUI_Dash )	{m_pStatusUI_Dash->setEnabled( bFlag ); }
	if( m_pStatusUI_Result_BackGround_1 )	{m_pStatusUI_Result_BackGround_1->setEnabled( bFlag ); }
	if( m_pStatusUI_Result_BackGround_2 )	{m_pStatusUI_Result_BackGround_2->setEnabled( bFlag ); }
	if( m_pStatusUI_Result_Fild )	{m_pStatusUI_Result_Fild->setEnabled(bFlag);	}
	if( m_pStatusUI_Result_VS )		{m_pStatusUI_Result_VS->setEnabled(bFlag);}
	if( m_pStatusUI_Result_KILL )	{m_pStatusUI_Result_KILL->setEnabled(bFlag);}
	if( m_pStatusUI_Result_QUEST_1 )	{m_pStatusUI_Result_QUEST_1->setEnabled(bFlag);}
	if( m_pStatusUI_Result_QUEST_2 )	{m_pStatusUI_Result_QUEST_2->setEnabled(bFlag);}
	if( m_pStatusUI_Story )	{m_pStatusUI_Story->setEnabled( bFlag ); }
	if( m_pModal_ExitQuestion )	{m_pModal_ExitQuestion->setEnabled( bFlag ); }
	if( m_pModal_Resurrection )	{m_pModal_Resurrection->setEnabled( bFlag ); }
	if( m_pStatusUI_Key )	{m_pStatusUI_Key->setEnabled( bFlag ); }
	if( m_pModal_Question )	{m_pModal_Question->setEnabled( bFlag ); }
	if( m_pModal_Leaving )	{m_pModal_Leaving->setEnabled(bFlag);}
	if( NULL != m_pGameMyBag )
	{
		m_pGameMyBag->setVisible( false );
		m_pGameMyBag->setEnabled( bFlag );
	}
}
// ctor/dtor
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// setCallback
void yb_MainUIControl::setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback)
{
	if(m_pStatusUI_Main)	{m_pStatusUI_Main->setEventCallback(pCallback);}
	if(m_pStatusUI_Char)	{m_pStatusUI_Char->setEventCallback(pCallback);}
	if(m_pStatusUI_Dash)	{m_pStatusUI_Dash->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_BackGround_1)	{m_pStatusUI_Result_BackGround_1->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_BackGround_2)	{m_pStatusUI_Result_BackGround_2->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_Fild)	{m_pStatusUI_Result_Fild->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_VS)	{m_pStatusUI_Result_VS->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_KILL)	{m_pStatusUI_Result_KILL->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_QUEST_1){m_pStatusUI_Result_QUEST_1->setEventCallback(pCallback);}
	if(m_pStatusUI_Result_QUEST_2){m_pStatusUI_Result_QUEST_2->setEventCallback(pCallback);}
	if(m_pModal_ExitQuestion)	{m_pModal_ExitQuestion->setEventCallback(pCallback);}
	if(m_pStatusUI_Story)	{m_pStatusUI_Story->setEventCallback(pCallback);}	
	if(m_pModal_Resurrection){m_pModal_Resurrection->setEventCallback(pCallback);}
	if(m_pStatusUI_Key)		{m_pStatusUI_Key->setEventCallback(pCallback);}
	if(m_pModal_Question)	{m_pModal_Question->setEventCallback(pCallback);}
	if(m_pModal_Leaving)	{m_pModal_Leaving->setEventCallback(pCallback);}
	if( NULL != m_pGameMyBag )		
		m_pGameMyBag->setEventCallback( pCallback ); 
}
// setCallback
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// load files
bool yb_MainUIControl::loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename)
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
	(*pManager)->setEventCallback(OnGUIEvent_MainUIControl);

	return true;
}
bool yb_MainUIControl::loadUI_Main( void )					{	return loadUI( &m_pStatusUI_Main, L"main.sav" );}
bool yb_MainUIControl::loadUI_Char( void )					{	return loadUI( &m_pStatusUI_Char, L"Char.sav" );}
bool yb_MainUIControl::loadUI_Dash( void )					{	return loadUI( &m_pStatusUI_Dash, L"Dash.sav" );}
bool yb_MainUIControl::loadUI_Result_BackGround_1( void )	{	return loadUI( &m_pStatusUI_Result_BackGround_1, L"ResultBackGround1.sav" );}
bool yb_MainUIControl::loadUI_Result_BackGround_2( void )	{	return loadUI( &m_pStatusUI_Result_BackGround_2, L"ResultBackGround2.sav" );}
bool yb_MainUIControl::loadUI_Result_Fild( void )			{	return loadUI( &m_pStatusUI_Result_Fild, L"ResultFild.sav");}
bool yb_MainUIControl::loadUI_Result_VS( void )				{	return loadUI( &m_pStatusUI_Result_VS, L"ResultVS.sav");}
bool yb_MainUIControl::loadUI_Result_KILL( void )			{	return loadUI( &m_pStatusUI_Result_KILL, L"ResultKILL.sav");}
bool yb_MainUIControl::loadUI_Result_QUEST_1( void )		{	return loadUI( &m_pStatusUI_Result_QUEST_1, L"ResultQuest_1.sav");}
bool yb_MainUIControl::loadUI_Result_QUEST_2( void )		{	return loadUI( &m_pStatusUI_Result_QUEST_2, L"ResultQuest_2.sav");}
bool yb_MainUIControl::loadUI_Modal_ExitQuestion( void )	{	return loadUI( &m_pModal_ExitQuestion, L"GameExitQuestion.sav" );}
bool yb_MainUIControl::loadUI_StoryMain( void )				{	return loadUI( &m_pStatusUI_Story, L"Storymain.sav" );}
bool yb_MainUIControl::loadUI_Modal_Resurrection( void )	{	return loadUI( &m_pModal_Resurrection, L"Resurrection.sav" );}
bool yb_MainUIControl::loadUI_Key( void )					{	return loadUI( &m_pStatusUI_Key, L"GameKey.sav" );}
bool yb_MainUIControl::loadUI_Modal_Question( void )		{	return loadUI( &m_pModal_Question, L"GameQuestion.sav");}
bool yb_MainUIControl::loadUI_Modal_Leaving( void )			{	return loadUI( &m_pModal_Leaving, L"Leaving.sav");}
bool yb_MainUIControl::loadUI_Bag( void )					{	return loadUI( &m_pGameMyBag, L"GameMybag.sav");}

void yb_MainUIControl::loadUI_AllInitVisual( void )
{
	m_pModal_ExitQuestion->setVisible(false);
	m_pModal_Resurrection->setVisible(false);
	m_pStatusUI_Key->setVisible(false);
	m_pModal_Question->setVisible(false);
	m_pModal_Leaving->setVisible(false);
}

bool yb_MainUIControl::loadUI_All( void )
{	
	if ( loadUI_Main() == false )					return false;
	if ( loadUI_Char() == false )					return false;
	if ( loadUI_Dash() == false )					return false;
	if ( loadUI_Result_BackGround_1() == false )	return false;	
	if ( loadUI_Result_BackGround_2() == false )	return false;	
	if ( loadUI_Result_Fild() == false )			return false;
	if ( loadUI_Result_VS() == false )				return false;
	if ( loadUI_Result_KILL() == false )			return false;
	if ( loadUI_Modal_ExitQuestion() == false )		return false;
	if ( loadUI_StoryMain() == false )				return false;
	if ( loadUI_Modal_Resurrection() == false )		return false;
	if ( loadUI_Key() == false )					return false;
	if ( loadUI_Modal_Question() == false )			return false;
	if ( loadUI_Modal_Leaving() == false )			return false;	
	if ( loadUI_Bag() == false )					return false;

	loadUI_AllInitVisual();

	return true;
}
// load files
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// render
void yb_MainUIControl::render(IDirect3DDevice9* pDevice)
{
	if(pDevice == 0) {return;}

	if( m_pGameMyBag && true == m_pGameMyBag->getVisible() )		{	m_pGameMyBag->render( pDevice ); }

	if(m_pStatusUI_Main)	{m_pStatusUI_Main->render(pDevice);}	
	if(m_pStatusUI_Char)	{m_pStatusUI_Char->render(pDevice);}
	if(m_pStatusUI_Dash)	{m_pStatusUI_Dash->render(pDevice);}

	if(m_pStatusUI_Key)									{if( g_pStaticEngine->getModal() == m_pStatusUI_Key ){m_pStatusUI_Key->render(pDevice);}}
	if(m_pModal_ExitQuestion)							{if(g_pStaticEngine->getModal() == m_pModal_ExitQuestion){m_pModal_ExitQuestion->render(pDevice);}}
	if(m_pModal_Resurrection)							
	{
		if(g_pStaticEngine->getModal() == m_pModal_Resurrection )
		{
			m_pModal_Resurrection->render(pDevice);
		}
	}
	if(m_pModal_Question)								{if(g_pStaticEngine->getModal() == m_pModal_Question){m_pModal_Question->render(pDevice);}}
	if(m_pModal_Leaving)								{if(g_pStaticEngine->getModal() == m_pModal_Leaving){m_pModal_Leaving->render(pDevice);}}

}
void yb_MainUIControl::StoryRender( IDirect3DDevice9* pDevice)
{
	if(pDevice == 0) {return;}

	if( m_pGameMyBag && true == m_pGameMyBag->getVisible() )		{	m_pGameMyBag->render( pDevice ); }

	if(m_pStatusUI_Char)	 { m_pStatusUI_Char->render(pDevice);}
	if(m_pStatusUI_Dash)	 { m_pStatusUI_Dash->render(pDevice);}
	if(m_pStatusUI_Story)	 { m_pStatusUI_Story->render(pDevice);}
	if(m_pStatusUI_Key)		 { m_pStatusUI_Key->render(pDevice);}
	if(m_pModal_Resurrection){ m_pModal_Resurrection->render(pDevice);};

	if(m_pStatusUI_Key)									{if( g_pStaticEngine->getModal() == m_pStatusUI_Key ){m_pStatusUI_Key->render(pDevice);}}
	if(m_pModal_ExitQuestion)							{if(g_pStaticEngine->getModal() == m_pModal_ExitQuestion){m_pModal_ExitQuestion->render(pDevice);}}
	if(m_pModal_Question)								{if(g_pStaticEngine->getModal() == m_pModal_Question){m_pModal_Question->render(pDevice);}}
	if(m_pModal_Leaving)								{if(g_pStaticEngine->getModal() == m_pModal_Leaving){m_pModal_Leaving->render(pDevice);}}


}
void yb_MainUIControl::renderResult(IDirect3DDevice9* pDevice)
{
	if( m_pStatusUI_Result_BackGround_1 )	{		m_pStatusUI_Result_BackGround_1->render(pDevice);	}


	if( m_pStatusUI_Result_Fild && m_pStatusUI_Result_Fild->getVisible() )		
	{
		m_pStatusUI_Result_Fild->render(pDevice);			
	}

	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if( m_pStatusUI_Result_VS )				{		m_pStatusUI_Result_VS->render(pDevice);				}
	}
	else if( GetGameMode() == PW_GAME_STORY )
	{
		if( m_pStatusUI_Result_KILL )			{		m_pStatusUI_Result_KILL->render(pDevice);			}
	}
	else if( GetGameMode() == PW_GAME_QUEST )
	{
		if( m_pStatusUI_Result_QUEST_1 )			{	m_pStatusUI_Result_QUEST_1->render(pDevice);		}
		if( m_pStatusUI_Result_QUEST_2 )			{	m_pStatusUI_Result_QUEST_2->render(pDevice);		}
	}


	if( m_pStatusUI_Result_BackGround_2 )	{		m_pStatusUI_Result_BackGround_2->render(pDevice);	}
}

// render
//=================================================================================================================
//=================================================================================================================


void yb_MainUIControl::ShowMyBag( )
{
	if( m_pGameMyBag )
	{
		if( m_pGameMyBag->getVisible() )
		{
			m_pGameMyBag->setVisible( false ); 	
		}
		else 
		{
			m_pGameMyBag->setVisible( true ); 	
		}
	}

}


//=================================================================================================================
//=================================================================================================================
// set exp, time, money
void yb_MainUIControl::setExp(unsigned int uExp)
{	
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_EXP_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_02_M::RTTI.getName())
				{
					ANW::StatusUI_Button_02_M* pMyControl = (ANW::StatusUI_Button_02_M*)pControl;
					pMyControl->setFontNum(uExp);
				}
			}
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_EXP_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_02_M::RTTI.getName())
				{
					ANW::StatusUI_Button_02_M* pMyControl = (ANW::StatusUI_Button_02_M*)pControl;
					pMyControl->setFontNum(uExp);
				}
			}
		}
	}
}
void yb_MainUIControl::setMoney(unsigned int uMoney)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MONEY_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_02_M::RTTI.getName())
				{
					ANW::StatusUI_Button_02_M* pMyControl = (ANW::StatusUI_Button_02_M*)pControl;
					pMyControl->setFontNum(uMoney);
				}
			}
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MONEY_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_02_M::RTTI.getName())
				{
					ANW::StatusUI_Button_02_M* pMyControl = (ANW::StatusUI_Button_02_M*)pControl;
					pMyControl->setFontNum(uMoney);
				}
			}
		}
	}
}
void yb_MainUIControl::setTime(unsigned int uMinute, unsigned int uSecond)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_TIME_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_Time::RTTI.getName())
				{
					ANW::StatusUI_Button_Time* pMyControl = (ANW::StatusUI_Button_Time*)pControl;
					pMyControl->setFontMinute(uMinute);
					pMyControl->setFontSecond(uSecond);
				}
			}
		}
	}
	else if( GetGameMode() == PW_GAME_QUEST)
	{
		if(m_pStatusUI_Story)
		{
			m_pStatusUI_Story->setControlVisibility( ID_MAINGAME_TIME_VALUE, false );
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			m_pStatusUI_Story->setControlVisibility( ID_MAINGAME_TIME_VALUE, true );

			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_TIME_VALUE);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_Time::RTTI.getName())
				{
					ANW::StatusUI_Button_Time* pMyControl = (ANW::StatusUI_Button_Time*)pControl;
					pMyControl->setFontMinute(uMinute);
					pMyControl->setFontSecond(uSecond);
				}
			}
		}
	}
}
void yb_MainUIControl::setExpProgressbar( float nMax, float fCurr )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer( ID_MAINGAME_EXP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			if( fCurr <= 0 || nMax <= 0 )
			{
				pControl->setEnergy( 0, 0 );
			}
			else
			{
				pControl->setEnergy( (int)nMax, (int)fCurr );
			}

		}
	}
}

void yb_MainUIControl::setRunProgressbar( float nMax, float fCurr )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Button_Stamina* pCharStamina = (ANW::StatusUI_Button_Stamina*)m_pStatusUI_Char->findControlPointer( ID_MAINGAME_RUN );
		if( pCharStamina )
		{
			if(pCharStamina->getRTTI()->getName() == ANW::StatusUI_Button_Stamina::RTTI.getName())
			{

				float fTemp = ( static_cast<float>(fCurr) / static_cast<float>(nMax) )  * 100;
				int m_uNum1 = 0;
				int m_uNum2 = 0;
				m_uNum1 = (int)fTemp;				
				if( m_uNum1 == 0 && fTemp > 0 )
					m_uNum1 = 1;

				if( m_uNum1 >= 100 )										m_uNum2 = 20;
				else if( m_uNum1 < 100 && m_uNum1 >= 95 )					m_uNum2 = 19;
				else if( m_uNum1 < 95 && m_uNum1 >= 90 )					m_uNum2 = 19;
				else if( m_uNum1 < 90 && m_uNum1 >= 85 )					m_uNum2 = 18;
				else if( m_uNum1 < 85 && m_uNum1 >= 80 )					m_uNum2 = 17;
				else if( m_uNum1 < 80 && m_uNum1 >= 75 )					m_uNum2 = 16;
				else if( m_uNum1 < 75 && m_uNum1 >= 70 )					m_uNum2 = 15;
				else if( m_uNum1 < 70 && m_uNum1 >= 65 )					m_uNum2 = 14;
				else if( m_uNum1 < 65 && m_uNum1 >= 60 )					m_uNum2 = 13;
				else if( m_uNum1 < 60 && m_uNum1 >= 55 )					m_uNum2 = 12;
				else if( m_uNum1 < 55 && m_uNum1 >= 50 )					m_uNum2 = 11;
				else if( m_uNum1 < 50 && m_uNum1 >= 45 )					m_uNum2 = 10;
				else if( m_uNum1 < 45 && m_uNum1 >= 40 )					m_uNum2 = 9;
				else if( m_uNum1 < 40 && m_uNum1 >= 35 )					m_uNum2 = 8;
				else if( m_uNum1 < 35 && m_uNum1 >= 30 )					m_uNum2 = 7;
				else if( m_uNum1 < 30 && m_uNum1 >= 25 )					m_uNum2 = 6;
				else if( m_uNum1 < 25 && m_uNum1 >= 20 )					m_uNum2 = 5;
				else if( m_uNum1 < 20 && m_uNum1 >= 15 )					m_uNum2 = 4;
				else if( m_uNum1 < 15 && m_uNum1 >= 10 )					m_uNum2 = 3;
				else if( m_uNum1 < 10 && m_uNum1 >= 5 )						m_uNum2 = 2;
				else if( m_uNum1 < 5 && m_uNum1 >= 1 )						m_uNum2 = 1;

				pCharStamina->setFontNum( m_uNum2 );
			}
		}
	}
}
// set exp, time, money
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// character setting
void yb_MainUIControl::hideAllChar()
{
	if(m_pStatusUI_Char)
	{
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHARLEFT_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR0, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR1, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR2, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR3, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR_CENTER_TEXT, false);

		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_REGENTIME, false);

		ANW::StatusUI_TextButton* pButton = 0;		
		for( int i = 0; i < 4; ++i )
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0BALLOON_NAME+i);
			if( pButton && pButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				if( i == 0 )
					pButton->setFontColor( D3DCOLOR_ARGB(255,0,255,0));
				else
					pButton->setFontColor( D3DCOLOR_ARGB(255,255,255,255));

			}
		}
	}
}
void yb_MainUIControl::hideAllEnemy()
{
	if(m_pStatusUI_Char)
	{
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHARRIGHT_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_BOSS_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_BOSS_ENERGY, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY0, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY1, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY2, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY3, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY4, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_BACKLIGHT, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3BALLOON, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3BALLOON_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3BALLOON_NAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ATTACKTAGET, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ATTACKTAGET_FRAME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ATTACKTAGET_NAME, false);

		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_REGENTIME, false);
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_REGENTIME, false);



		ANW::StatusUI_TextButton* pButton = 0;
		pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ATTACKTAGET_NAME);
		if( pButton && pButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			pButton->setFontColor( D3DCOLOR_ARGB(255,255,0,0));
		}
		pButton = 0;
		for( int i = 0; i < 4; ++i )
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0BALLOON_NAME+i);
			if( pButton && pButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pButton->setFontColor( D3DCOLOR_ARGB(255,255,0,0));
			}
		}


	}
}
void yb_MainUIControl::showChar(unsigned int nOrdinal, bool bFlag)
{
	if(m_pStatusUI_Char)
	{
		if(nOrdinal == 0)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHARLEFT_FRAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR0, bFlag);
		}
		else if(nOrdinal == 1)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR1, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1_FRAME, bFlag);
		}
		else if(nOrdinal == 2)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR2, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2_FRAME, bFlag );
		}
		else if(nOrdinal == 3)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_CHAR3, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3_FRAME, bFlag );
		}
	}
}
void yb_MainUIControl::showEnemy(unsigned int nOrdinal, bool bFlag)
{
	if(m_pStatusUI_Char)
	{
		if(nOrdinal == 0)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHARRIGHT_FRAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY0, bFlag);
		}
		else if(nOrdinal == 1)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY1, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1_FRAME, bFlag );
		}
		else if(nOrdinal == 2)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY2, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2_FRAME, bFlag );
		}
		else if(nOrdinal == 3)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY3, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3_FRAME, bFlag );
		}
		else if(nOrdinal == 4)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_ENERGY, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY4, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY4_FRAME, bFlag );
		}
	}
}
void yb_MainUIControl::showCharBalloon( int nOrdinal, bool bFlag )
{
	if(m_pStatusUI_Char)
	{
		if(nOrdinal == 0)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0BALLOON, bFlag);

		}
		else if(nOrdinal == 1)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR1BALLOON, bFlag);
		}
		else if(nOrdinal == 2)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR2BALLOON, bFlag);
		}
		else if(nOrdinal == 3)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR3BALLOON, bFlag);
		}
	}
}
void yb_MainUIControl::showEnemyBalloon( int nOrdinal, bool bFlag )
{
	if(m_pStatusUI_Char)
	{
		if(nOrdinal == 0)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0BALLOON, bFlag);

		}
		else if(nOrdinal == 1)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY1BALLOON, bFlag);
		}
		else if(nOrdinal == 2)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY2BALLOON, bFlag);
		}
		else if(nOrdinal == 3)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3BALLOON_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY3BALLOON, bFlag);
		}
	}
}
void yb_MainUIControl::showAttackTagetBalloon( int nOrdinal, bool bFlag )
{
	if(m_pStatusUI_Char)
	{
		if(nOrdinal == 0)
		{
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ATTACKTAGET_NAME, bFlag);
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ATTACKTAGET, bFlag);

		}		
	}
}
void yb_MainUIControl::setCharName(unsigned int nOrdinal, int nLv, CStringW strName)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_TextButton* pButton = 0;
		ANW::StatusUI_TextButton* pBallonButton = 0;
		if(nOrdinal == 0)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0BALLOON_NAME);
		}
		else if(nOrdinal == 1)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1BALLOON_NAME);
		}
		else if(nOrdinal == 2)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2BALLOON_NAME);
		}
		else if(nOrdinal == 3)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3BALLOON_NAME);
		}
		if(pButton)
		{
			if( pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName() 
				|| pBallonButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			char szBuf[68];
			CStringW strBuf;
			sprintf( szBuf, "Lv.%d ", nLv);
			strBuf = szBuf;
			strBuf += strName;
			pButton->setRectItemText(strBuf);
			pBallonButton->setRectItemText( strName );
		}
	}
}
void yb_MainUIControl::setEnemyName(unsigned int nOrdinal, int nLv, CStringW strName)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_TextButton* pButton = 0;
		ANW::StatusUI_TextButton* pBallonButton = 0;
		if(nOrdinal == 0)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0_NAME);

		}
		else if(nOrdinal == 1)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0BALLOON_NAME);
			if(pBallonButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
			{
				pBallonButton->setRectItemText(strName);
			}

		}
		else if(nOrdinal == 2)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1BALLOON_NAME);	
			if(pBallonButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
			{
				pBallonButton->setRectItemText(strName);
			}
		}
		else if(nOrdinal == 3)
		{
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3_NAME);
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2BALLOON_NAME);	
			if(pBallonButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
			{
				pBallonButton->setRectItemText(strName);
			}
		}
		else if(nOrdinal == 4)
		{

			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY4_NAME);			
			pBallonButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3BALLOON_NAME);	
			if(pBallonButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
			{
				pBallonButton->setRectItemText(strName);
			}
		}
		if(pButton)
		{
			if(pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}			
			char szBuf[68];
			CStringW strBuf;
			sprintf( szBuf, "Lv.%d ", nLv);
			strBuf = szBuf;
			strBuf += strName;
			pButton->setRectItemText(strBuf);
		}
	}
}
void yb_MainUIControl::setCharName(unsigned int nOrdinal, int nLv, char* strName)
{
	ANW_ASSERT(strName);
	if(strName == 0)	{return;}
	CStringW strW = strName;
	setCharName(nOrdinal, nLv, strW);
}
void yb_MainUIControl::setEnemyName(unsigned int nOrdinal, int nLv, char* strName)
{
	ANW_ASSERT(strName);
	if(strName == 0)	{return;}
	CStringW strW = strName;
	setEnemyName(nOrdinal, nLv, strW);
}
void yb_MainUIControl::setCharEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_Button_SharedRect* pSharedRect = 0;
		ANW::StatusUI_MainEnergy* pSubEnergy = 0;
		ANW::StatusUI_Button_Energy* pCharEnergy = 0;	
		ANW::StatusUI_TextButton* pCharEnergyText = 0;

		if(nOrdinal == 0)
		{
			pCharEnergy = (ANW::StatusUI_Button_Energy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0_ENERGY);			
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR0);
			pCharEnergyText = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR_ENERGY_TEXT);
		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR1);
		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR2);
		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR3);
		}
		if(pSubEnergy)
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_MainEnergy::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			pSubEnergy->setEnergy(uMax, uCurrent);
		}
		if(pSharedRect)
		{
			if(pSharedRect->getRTTI()->getName() != ANW::StatusUI_Button_SharedRect::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			bool bFlag = false;
			float fCurrent = (float)uCurrent, fMax = (float)uMax;
			if(fCurrent * 3.3f > fMax) bFlag = true;
			pSharedRect->setEnergyFull(bFlag);
		}
		if( pCharEnergy )
		{
			if(pCharEnergy->getRTTI()->getName() == ANW::StatusUI_Button_Energy::RTTI.getName())
			{

				float fTemp = ( static_cast<float>(uCurrent) / static_cast<float>(uMax) )  * 100;
				int m_uNum1 = 0;
				int m_uNum2 = 0;
				m_uNum1 = (int)fTemp;				
				if( (int)fTemp == 0 && uCurrent > 0 )
					m_uNum1 = 1;

				if( pCharEnergyText )
				{
					if(pCharEnergyText->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName())
					{
						char szBuf[64];
						CStringW strEnergy;
						sprintf( szBuf, "%d%%", m_uNum1 );
						strEnergy = szBuf;
						pCharEnergyText->setRectItemText( strEnergy );
					}
				}	

				if( m_uNum1 >= 100 )										m_uNum2 = 21;
				else if( m_uNum1 < 100 && m_uNum1 >= 95 )					m_uNum2 = 20;
				else if( m_uNum1 < 95 && m_uNum1 >= 90 )					m_uNum2 = 19;
				else if( m_uNum1 < 90 && m_uNum1 >= 85 )					m_uNum2 = 18;
				else if( m_uNum1 < 85 && m_uNum1 >= 80 )					m_uNum2 = 17;
				else if( m_uNum1 < 80 && m_uNum1 >= 75 )					m_uNum2 = 16;
				else if( m_uNum1 < 75 && m_uNum1 >= 70 )					m_uNum2 = 15;
				else if( m_uNum1 < 70 && m_uNum1 >= 65 )					m_uNum2 = 14;
				else if( m_uNum1 < 65 && m_uNum1 >= 60 )					m_uNum2 = 13;
				else if( m_uNum1 < 60 && m_uNum1 >= 55 )					m_uNum2 = 12;
				else if( m_uNum1 < 55 && m_uNum1 >= 50 )					m_uNum2 = 11;
				else if( m_uNum1 < 50 && m_uNum1 >= 45 )					m_uNum2 = 10;
				else if( m_uNum1 < 45 && m_uNum1 >= 40 )					m_uNum2 = 9;
				else if( m_uNum1 < 40 && m_uNum1 >= 35 )					m_uNum2 = 8;
				else if( m_uNum1 < 35 && m_uNum1 >= 30 )					m_uNum2 = 7;
				else if( m_uNum1 < 30 && m_uNum1 >= 25 )					m_uNum2 = 6;
				else if( m_uNum1 < 25 && m_uNum1 >= 20 )					m_uNum2 = 5;
				else if( m_uNum1 < 20 && m_uNum1 >= 15 )					m_uNum2 = 4;
				else if( m_uNum1 < 15 && m_uNum1 >= 10 )					m_uNum2 = 3;
				else if( m_uNum1 < 10 && m_uNum1 >= 5 )						m_uNum2 = 2;
				else if( m_uNum1 < 5 && m_uNum1 >= 1 )						m_uNum2 = 1;

				pCharEnergy->setFontNum( m_uNum2 );
			}
		}

	}
}
void yb_MainUIControl::setEnemyEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_Button_SharedRect* pSharedRect = 0;
		ANW::StatusUI_MainEnergy* pSubEnergy = 0;
		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0_ENERGY);			
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY0);
		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY1);
		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY2);
		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY3);
		}
		else if(nOrdinal == 4)
		{
			pSubEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY4_ENERGY);
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY4);
		}

		if(pSubEnergy)
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_MainEnergy::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			pSubEnergy->setEnergy(uMax, uCurrent);
		}
		if(pSharedRect)
		{
			if(pSharedRect->getRTTI()->getName() != ANW::StatusUI_Button_SharedRect::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			bool bFlag = false;
			float fCurrent = (float)uCurrent, fMax = (float)uMax;
			if(fCurrent * 3.3f > fMax) bFlag = true;
			pSharedRect->setEnergyFull(bFlag);
		}
	}
}
void yb_MainUIControl::setCharBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;		

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0BALLOON);			
		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1BALLOON);			
		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2BALLOON);			
		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3BALLOON);			
		}

		if( pSubEnergy )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() )

			{
				ANW_ASSERT(0);
				return;
			}			
			pSubEnergy->setEnergy(uMax, uCurrent);			
		}		
	}
}
void yb_MainUIControl::setCharBalloonPos( unsigned int nOrdinal, float fX, float fY )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;
		ANW::StatusUI_TextButton* pButton = 0;

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR0BALLOON_NAME);			

		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR1BALLOON_NAME);			

		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR2BALLOON_NAME);			

		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR3BALLOON_NAME);			
		}

		if( pSubEnergy && pButton )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() ||
				pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			pSubEnergy->setPosition( fX, fY, 1.0f );
			pButton->setPosition(fX-56, fY-13, 1.0f );
		}		
	}
}
void yb_MainUIControl::setEnemyBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;		

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0BALLOON);


		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1BALLOON);

		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2BALLOON);

		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3BALLOON);			
		}

		if( pSubEnergy )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() )

			{
				ANW_ASSERT(0);
				return;
			}			
			pSubEnergy->setEnergy(uMax, uCurrent);
		}		
	}
}
void yb_MainUIControl::setEnemyBalloonPos( unsigned int nOrdinal, float fX, float fY )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;
		ANW::StatusUI_TextButton* pButton = 0;

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY0BALLOON_NAME);			
		}		
		else if(nOrdinal == 1)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY1BALLOON_NAME);
		}
		else if(nOrdinal == 2)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY2BALLOON_NAME);
		}
		else if(nOrdinal == 3)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3BALLOON);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ENEMY3BALLOON_NAME);
		}

		if( pSubEnergy && pButton )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() ||
				pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			pSubEnergy->setPosition( fX, fY, 1.0f );
			pButton->setPosition( fX-56, fY-13, 1.0f );			
		}		
	}
}
void yb_MainUIControl::setAttackTagetBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent, CStringW strName )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;
		ANW::StatusUI_TextButton* pButton = 0;

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ATTACKTAGET);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ATTACKTAGET_NAME);
		}		

		if( pSubEnergy && pButton )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() ||
				pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}			
			pButton->setRectItemText( strName );
			pSubEnergy->setEnergy(uMax, uCurrent);
		}		
	}
}
void yb_MainUIControl::setAttackTagetBalloonPos( unsigned int nOrdinal, float fX, float fY )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_SubEnergy* pSubEnergy = 0;
		ANW::StatusUI_TextButton* pButton = 0;

		if(nOrdinal == 0)
		{
			pSubEnergy = (ANW::StatusUI_SubEnergy*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ATTACKTAGET);
			pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_ATTACKTAGET_NAME);
		}		

		if( pSubEnergy && pButton )
		{
			if(pSubEnergy->getRTTI()->getName() != ANW::StatusUI_SubEnergy::RTTI.getName() ||
				pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			pSubEnergy->setPosition( fX, fY, 1.0f );
			pButton->setPosition( fX-56, fY-13, 1.0f );			
		}		
	}
}
void yb_MainUIControl::showCharDie( int nOrdinal, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR0_DIE+nOrdinal, bFlag );		
	}
}

void yb_MainUIControl::showEnemyDie( int nOrdinal, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_DIE+nOrdinal, bFlag );
	}
}

void yb_MainUIControl::showBossEnergy( bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_ENEMY0_NAME, bFlag);
		m_pStatusUI_Char->setControlVisibility( ID_MAINGAME_BOSS_FRAME, bFlag );
		m_pStatusUI_Char->setControlVisibility( ID_MAINGAME_BOSS_ENERGY, bFlag );
		m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_SHARED_POS_ENEMY0, bFlag);

	}
}
void yb_MainUIControl::setBossEnergy( unsigned int uMax, unsigned int uCurrent )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_MainEnergy* pEnergy = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Char->findControlPointer( ID_MAINGAME_BOSS_ENERGY );
		if( pEnergy )
		{
			if( pEnergy->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
			{
				pEnergy->setEnergy(uMax, uCurrent);
			}
		}


	}
}

void yb_MainUIControl::setCharFace(unsigned int nOrdinal, int nFaceOrdinal, bool bMonster)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_Button_SharedRect* pSharedRect = 0;
		if(nOrdinal == 0)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR0);
		}
		if(nOrdinal == 1)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR1);
		}
		else if(nOrdinal == 2)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR2);
		}
		else if(nOrdinal == 3)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_CHAR3);
		}
		if(pSharedRect)
		{
			if(pSharedRect->getRTTI()->getName() != ANW::StatusUI_Button_SharedRect::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}

			if(bMonster == true)
			{
				pSharedRect->setEnemyRectID(nFaceOrdinal);
			}
			else
			{
				pSharedRect->setCharRectID(nFaceOrdinal);
			}
		}
	}
}
void yb_MainUIControl::setEnemyFace(unsigned int nOrdinal, int nFaceOrdinal, bool bMonster)
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_Button_SharedRect* pSharedRect = 0;
		if(nOrdinal == 0)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY0);
		}
		if(nOrdinal == 1)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY1);
		}
		else if(nOrdinal == 2)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY2);
		}
		else if(nOrdinal == 3)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY3);
		}
		else if(nOrdinal == 4)
		{
			pSharedRect = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_SHARED_POS_ENEMY4);
		}
		if(pSharedRect)
		{
			if(pSharedRect->getRTTI()->getName() != ANW::StatusUI_Button_SharedRect::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}

			if(bMonster == true)
			{
				pSharedRect->setEnemyRectID(nFaceOrdinal);
			}
			else
			{
				pSharedRect->setCharRectID(nFaceOrdinal);
			}


		}
	}
}
void yb_MainUIControl::showRegenTime(bool bChar, int nOrdinal, bool bFlag)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_MAINGAME_CHAR0_REGENTIME;
		if(bChar == false)
		{
			nControlID = ID_MAINGAME_ENEMY0_REGENTIME;
		}
		nControlID = nControlID + nOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			pControl->setVisible(bFlag);
		}
	}
}
void yb_MainUIControl::setRegenTime(bool bChar, int nOrdinal, unsigned int uCurTime)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_MAINGAME_CHAR0_REGENTIME;
		if(bChar == false)
		{
			nControlID = ID_MAINGAME_ENEMY0_REGENTIME;
		}
		nControlID = nControlID + nOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			if(nOrdinal == 0)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_04_G::RTTI.getName())
				{
					ANW::StatusUI_Button_04_G* pButton = (ANW::StatusUI_Button_04_G*)pControl;
					pButton->setFontNum(uCurTime);
				}
			}
			else
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_03_B::RTTI.getName())
				{
					ANW::StatusUI_Button_03_B* pButton = (ANW::StatusUI_Button_03_B*)pControl;
					pButton->setFontNum(uCurTime);
				}
			}
		}
	}
}
void yb_MainUIControl::showCenterRegenTime( bool bFlag )
{
	if(m_pStatusUI_Char)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR_CENTER);
		if(pControl)
		{
			pControl->setVisible(bFlag);
		}
	}
}
void yb_MainUIControl::setCenterRegenTime(unsigned int uCurTime)
{
	if(m_pStatusUI_Char)
	{		
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR_CENTER);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_05_G::RTTI.getName())
			{				
				ANW::StatusUI_Button_05_G* pButton = (ANW::StatusUI_Button_05_G*)pControl;
				pButton->setFontNum(uCurTime);
				//m_pStatusUI_Char->setControlEnabled()

			}				
		}	
	}
}
void yb_MainUIControl::setConterRegen( bool bFlag, unsigned int cCurTime )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_TextButton* pButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Char->findControlPointer(ID_MAINGAME_CHAR_CENTER_TEXT);
		if(pButton)
		{
			if(pButton->getRTTI()->getName() != ANW::StatusUI_TextButton::RTTI.getName())
			{
				ANW_ASSERT(0);
				return;
			}
			m_pStatusUI_Char->setControlVisibility(ID_MAINGAME_CHAR_CENTER_TEXT, bFlag);

			int nTemp = cCurTime % 10;
//			CStringW strBuf = g_xGeneral.GetString( STRING_TABLE::STABLE_UI, 5);
			switch( nTemp )
			{

			case 0:	pButton->setRectItemText( L"부활 대기중.");				break;
			case 1:	pButton->setRectItemText( L"부활 대기중..");				break;
			case 2:	pButton->setRectItemText( L"부활 대기중.");				break;
			case 3:	pButton->setRectItemText( L"부활 대기중....");				break;
			case 4:	pButton->setRectItemText( L"부활 대기중...");				break;
			case 5:	pButton->setRectItemText( L"부활 대기중..");				break;
			case 6:	pButton->setRectItemText( L"부활 대기중.");				break;
			case 7:	pButton->setRectItemText( L"부활 대기중....");				break;
			case 8:	pButton->setRectItemText( L"부활 대기중...");				break;
			case 9:	pButton->setRectItemText( L"부활 대기중..");				break;

			
			}
		}
	}
}
void yb_MainUIControl::setEffect( int nOrdinal, float fX, float fY, unsigned int uDamage, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Button_EH* pButton = (ANW::StatusUI_Button_EH*)m_pStatusUI_Char->findControlPointer( ID_MAINGAME_EFFECT + nOrdinal);
		if( pButton && pButton->getRTTI()->getName() == ANW::StatusUI_Button_EH::RTTI.getName() )
		{
			if( uDamage <= 0 )
			{
				pButton->setVisible( false );
			}
			else
			{
				pButton->setVisible( bFlag );
				pButton->setPosition( fX, fY, -1.0f);
				pButton->setFontNum( uDamage );
			}
		}
	}
}
void yb_MainUIControl::setBufIcon(bool bChar, int nOrdinal, int nBufOrdinal, int nIconID)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_BUFF_CHAR01_01;
		if(bChar == false)
		{
			nControlID = ID_BUFF_ENEMY01_01;
		}
		nControlID = nControlID + nOrdinal*10 + nBufOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_Buff::RTTI.getName())
			{
				ANW::StatusUI_Button_Buff* pButton = (ANW::StatusUI_Button_Buff*)pControl;
				pButton->setRectID(nIconID + ID_BUFFICON_START);
			}
		}
	}
}
void yb_MainUIControl::setBufOnOff(bool bChar, int nOrdinal, int nBufOrdinal, bool bFlag)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_BUFF_CHAR01_01;
		if(bChar == false)
		{
			nControlID = ID_BUFF_ENEMY01_01;
		}
		nControlID = nControlID + nOrdinal*10 + nBufOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			pControl->setVisible(bFlag);
		}
	}
}
void yb_MainUIControl::setBufCoolTime(bool bChar, int nOrdinal, int nBufOrdinal, unsigned int uCoolTime)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_BUFF_CHAR01_01;
		if(bChar == false)
		{
			nControlID = ID_BUFF_ENEMY01_01;
		}
		nControlID = nControlID + nOrdinal*10 + nBufOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_Buff::RTTI.getName())
			{
				ANW::StatusUI_Button_Buff* pButton = (ANW::StatusUI_Button_Buff*)pControl;
				pButton->set_CoolTime(uCoolTime);
			}
		}
	}
}
void yb_MainUIControl::setBufUseCoolTime(bool bChar, int nOrdinal, int nBufOrdinal, bool bFlag)
{
	if(m_pStatusUI_Char)
	{
		int nControlID = ID_BUFF_CHAR01_01;
		if(bChar == false)
		{
			nControlID = ID_BUFF_ENEMY01_01;
		}
		nControlID = nControlID + nOrdinal*10 + nBufOrdinal;

		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer(nControlID);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_Buff::RTTI.getName())
			{
				ANW::StatusUI_Button_Buff* pButton = (ANW::StatusUI_Button_Buff*)pControl;
				pButton->setUse_CoolTime(bFlag);
			}
		}
	}
}
void yb_MainUIControl::setCharDie( int nOrdinal, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		int nControlID = ID_MAINGAME_CHAR0_DIE + nOrdinal;
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( nControlID );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName() )
		{
			ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
			pButton->setVisible( bFlag );
		}
	}
}
void yb_MainUIControl::setCharBackLight(int nOrdinal, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		int nContorlID = ID_MAINGAME_CHAR0_BACKLIGHT + nOrdinal;
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( nContorlID );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName() )
		{
			ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
			pButton->setVisible( bFlag );
		}
	}
}
void yb_MainUIControl::setEnemyBackLight( int nOrdinal, bool bFlag )
{
	if( m_pStatusUI_Char )
	{
		int nControlID = ID_MAINGAME_ENEMY0_BACKLIGHT+nOrdinal;
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( nControlID );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button::RTTI.getName() )
		{
			ANW::StatusUI_Button* pButton = (ANW::StatusUI_Button*)pControl;
			pButton->setVisible( bFlag );
		}

	}
}
// character setting
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// minimap setting
void yb_MainUIControl::addMonsterPos(float fU, float fV)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
				{
					ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
					pMyControl->addMonsterPos(fU, fV);
				}
			}
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName())
				{
					ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
					pMyControl->addMonsterPos(fU, fV);
				}
			}
		}
	}
}
void yb_MainUIControl::addBluePos(float fU, float fV)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
				{
					ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
					pMyControl->addBluePos(fU, fV);
				}
			}
		}
	}
	else
	{
		if( m_pStatusUI_Story )
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_MINIMAP_FRAME );
			if( pControl )
			{
				if( pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName() )
				{
					ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
					pMyControl->addPlayerPos( fU, fV );
				}
			}

		}
	}
}
void yb_MainUIControl::addRedPos(float fU, float fV)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
				{
					ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
					pMyControl->addRedPos(fU, fV);
				}
			}
		}
	}
	else
	{
		if( m_pStatusUI_Story )
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_MINIMAP_FRAME );

			if( pControl )
			{
				if( pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName() )
				{
					ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
					pMyControl->addPlayerPos( fU, fV );
				}
			}

		}
	}

}
void yb_MainUIControl::addPlayerPos( float fU, float fV )
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_MINIMAP_FRAME );

		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName() )
			{
				ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
				pMyControl->addPlayerPos( fU, fV );
			}
		}

	}
}
void yb_MainUIControl::AddPlayerMovePos(const float& fU, const float& fV )
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_MINIMAP_FRAME );

		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName() )
			{
				ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
				pMyControl->addPlayerMovePos( fU, fV );
			}
		}

	}
}
void yb_MainUIControl::clearAllPos()
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
				{
					ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
					pMyControl->clearAllPos();
				}
			}
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName())
				{
					ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
					pMyControl->clearAllPos();
				}
			}
		}
	}
}
void yb_MainUIControl::setMistStatus(BOOL m0, BOOL m1, BOOL m2, BOOL m3, BOOL m4, BOOL m5, BOOL m6)
{
	if(m_pStatusUI_Main)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
			{
				ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
				pMyControl->setMapStatus(m0, m1, m2, m3, m4, m5, m6);
			}
		}
	}
}
void yb_MainUIControl::setProgressStatus(int m0, int m1, int m2, int m3, int m4, int m5, int m6)
{
	if(m_pStatusUI_Main)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
		if(pControl)
		{			
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
			{
				ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
				pMyControl->setProgressStatus(m0, m1, m2, m3, m4, m5, m6);				
			}
		}
	}
}
void yb_MainUIControl::setMinimap(CStringW filename)
{
	if( GetGameMode() == PW_GAME_BATTLE )
	{
		if(m_pStatusUI_Main)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Main->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap::RTTI.getName())
				{
					ANW::StatusUI_Minimap* pMyControl = (ANW::StatusUI_Minimap*)pControl;
					pMyControl->setMapTexture(filename);
				}
			}
		}
	}
	else
	{
		if(m_pStatusUI_Story)
		{
			ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MINIMAP_FRAME);
			if(pControl)
			{
				if(pControl->getRTTI()->getName() == ANW::StatusUI_Minimap_Story::RTTI.getName())
				{
					ANW::StatusUI_Minimap_Story* pMyControl = (ANW::StatusUI_Minimap_Story*)pControl;
					pMyControl->setMapTexture(filename);
				}
			}
		}
	}
}
void yb_MainUIControl::setTotalMap(CStringW strfilename)
{
	if(m_pStatusUI_Story)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_TOTALMAP);
		if(pControl)
		{
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Totalmap::RTTI.getName())
			{
				ANW::StatusUI_Totalmap* pMyControl = (ANW::StatusUI_Totalmap*)pControl;
				pMyControl->setMapTexture(strfilename);
			}
		}
	}
}
void yb_MainUIControl::setTotalMapShow( bool bFlag )
{
	if( m_pStatusUI_Story )
	{		
		m_pStatusUI_Story->setControlVisibility( ID_MAINGAME_TOTALMAP, bFlag );
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MENU_MINIMAP);
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
			{
				ANW::StatusUI_CheckBox* pTaget = (ANW::StatusUI_CheckBox*)pControl;
				pTaget->setChecked( bFlag );
			}
		}
	}
}

bool yb_MainUIControl::GetButtonCheckMini()
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MENU_MINIMAP);
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
			{
				ANW::StatusUI_CheckBox* pTaget = (ANW::StatusUI_CheckBox*)pControl;
				return pTaget->getChecked();
			}
		}
	}
	return false;
}
bool yb_MainUIControl::GetButtonCheckQuest()
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer(ID_MAINGAME_MENU_QUESTLIST);
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
			{
				ANW::StatusUI_CheckBox* pTaget = (ANW::StatusUI_CheckBox*)pControl;
				return pTaget->getChecked();
			}
		}
	}
	return false;
}

void yb_MainUIControl::SetCurrentPos( int nIndex )
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_TOTALMAP );
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_Totalmap::RTTI.getName() )
			{
				ANW::StatusUI_Totalmap* pTaget = (ANW::StatusUI_Totalmap*)pControl;
				pTaget->SetCuttentIndex( nIndex );				
			}
		}
	}
}
void yb_MainUIControl::SetAfterPos( int nSlot, int nIndex )
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_TOTALMAP );
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_Totalmap::RTTI.getName() )
			{
				ANW::StatusUI_Totalmap* pTaget = (ANW::StatusUI_Totalmap*)pControl;
				pTaget->SetAfterIndex( nSlot, nIndex );
			}
		}
	}
}
void yb_MainUIControl::ClearTotalMap()
{
	if( m_pStatusUI_Story )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Story->findControlPointer( ID_MAINGAME_TOTALMAP );
		if( pControl )
		{
			if( pControl->getRTTI()->getName() == ANW::StatusUI_Totalmap::RTTI.getName() )
			{
				ANW::StatusUI_Totalmap* pTaget = (ANW::StatusUI_Totalmap*)pControl;
				pTaget->ClearIndex();
			}
		}
	}
}

// minimap setting
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// dashboard setting
void yb_MainUIControl::clearDashboard()
{
	if(m_pStatusUI_Dash)
	{
		for(int i = ID_SKILLICON_MAINGAME_POS01; i<= ID_SKILLICON_MAINGAME_POS20; i++)
		{
			ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(i);
			if(pIcon)
			{
				if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
				{
					pIcon->setVisible(true);
					pIcon->setUseCoolTime( false );
					pIcon->setUseStockCount( false );					
					pIcon->setUseHotKey( false );
					pIcon->setRectID( ID_SKILLICON_START-1);
				}
			}
		}
	}
}
void yb_MainUIControl::setIcon(unsigned int uOrdinal, bool bShow, int nSkill_ID, bool bShowHotkey, unsigned int uHotkey, bool bShowCooltime, unsigned int uCooltime, bool bShowStockCount, unsigned int uStockCount)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setVisible(bShow);
				pIcon->setUseHotKey(bShowHotkey);
				pIcon->setHotkey(uHotkey);
				pIcon->setUseCoolTime(bShowCooltime);
				pIcon->setCoolTime(uCooltime);
				pIcon->setUseStockCount(bShowStockCount);
				pIcon->setStockCount(uStockCount);
			}
		}
	}
}
void yb_MainUIControl::setIconVisibility(unsigned int uOrdinal, bool bShow)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{				
				pIcon->setVisible(bShow);
			}
		}
	}
}
bool yb_MainUIControl::getIconVisibility( unsigned int uOrdinal )
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{				
				return pIcon->getVisible();
			}
		}
	}
	return false;
}
void yb_MainUIControl::setIconID(unsigned int uOrdinal, int nID)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{				
				pIcon->setRectID(ID_SKILLICON_START + nID);
			}
		}
	}
}
void yb_MainUIControl::setHotkeyVisibility(unsigned int uOrdinal, bool bShow)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setUseHotKey(bShow);
			}
		}
	}
}
void yb_MainUIControl::setHotkeyValue(unsigned int uOrdinal, char szHotkey)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				CStringW strBuf = szHotkey;
				pIcon->setTextHotkey(strBuf);
				pIcon->setHotkey( (UINT) szHotkey );
			}
		}
	}
}
void yb_MainUIControl::setHotkey(unsigned int uOrdinal, bool bShow, char szHotkey)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				CStringW strBuf = szHotkey;
				switch( szHotkey )
				{
				case VK_F1:		pIcon->setTextHotkey("F1"); break;
				case VK_F2:		pIcon->setTextHotkey("F2"); break;
				case VK_F3:		pIcon->setTextHotkey("F3"); break;
				case VK_F4:		pIcon->setTextHotkey("F4"); break;
				case VK_F5:		pIcon->setTextHotkey("F5"); break;
				case VK_F6:		pIcon->setTextHotkey("F6"); break;
				case VK_F7:		pIcon->setTextHotkey("F7"); break;
				case VK_F8:		pIcon->setTextHotkey("F8"); break;
				case VK_F9:		pIcon->setTextHotkey("F9"); break;
				case VK_F10:	pIcon->setTextHotkey("F10"); break;
				case VK_F11:	pIcon->setTextHotkey("F11"); break;
				case VK_F12:	pIcon->setTextHotkey("F12"); break;
				default :pIcon->setTextHotkey(strBuf); break;
				}				
				pIcon->setUseTextHotKey(bShow);				
				pIcon->setHotkey( (UINT) szHotkey );
			}
		}
	}
}
void yb_MainUIControl::setCooltimeVisibility(unsigned int uOrdinal, bool bShow)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setUseCoolTime(bShow);
			}
		}
	}
}
void yb_MainUIControl::setCooltimeValue(unsigned int uOrdinal, unsigned int uCooltime)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setCoolTime(uCooltime);
			}
		}
	}
}
void yb_MainUIControl::setCooltime(unsigned int uOrdinal, bool bShow, unsigned int uCooltime)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{

				pIcon->setUseCoolTime(bShow);
				pIcon->setCoolTime(uCooltime);

			}
		}
	}
}
void yb_MainUIControl::setStockCountVisibility(unsigned int uOrdinal, bool bShow)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setUseStockCount(bShow);
			}
		}
	}
}
void yb_MainUIControl::setStockCountValue(unsigned int uOrdinal, unsigned int uStockCount)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setStockCount(uStockCount);
			}
		}
	}
}
void yb_MainUIControl::setStockCount(unsigned int uOrdinal, bool bShow, unsigned int uStockCount)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pIcon->setUseStockCount(bShow);
				pIcon->setStockCount(uStockCount);
			}
		}
	}
}
void yb_MainUIControl::setDashBoardIndex(unsigned int uDashBoardIndex)
{
	m_uDashBoardIndex = uDashBoardIndex;
	if(m_pStatusUI_Dash)
	{
		//		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_DASHBOARD_SELECTION);
		//		if(pControl->getRTTI()->getName() == ANW::StatusUI_Button_NState::RTTI.getName())
		//		{
		//			ANW::StatusUI_Button_NState* pButton_Nstate = (ANW::StatusUI_Button_NState*)pControl;
		//			pButton_Nstate->setCurrentButtonIndex(m_uDashBoardIndex);
		//		}
	}
}
unsigned int yb_MainUIControl::getDashBoardIndex()
{
	return m_uDashBoardIndex;
}
void yb_MainUIControl::enableSkillIcon(unsigned uOrdinal, bool bFlag)
{
	if(m_pStatusUI_Dash)
	{
		int nCurrent = ID_SKILLICON_MAINGAME_POS01 + (int)uOrdinal;
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(nCurrent);
		if(pIcon)
		{
			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				if( true == bFlag )
				{					
					pIcon->setSkillEnabled(bFlag);
				}
				else if( false == bFlag )
				{
					if( pIcon->getRectID() >= ID_SKILLICON_START )
						pIcon->setSkillEnabled(bFlag);
				}
			}
		}
	}
}
int yb_MainUIControl::GetCurrentSlotRectID( int nOrdinal )
{
	if( m_pStatusUI_Dash )
	{
		int nRet = -1;
		ANW::StatusUI_Shared_SkillIcon* pSkillReceiver = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer(ID_SKILLICON_MAINGAME_POS01 + nOrdinal);
		if((pSkillReceiver)&& pSkillReceiver->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
		{
			nRet = pSkillReceiver->getRectID() - ID_SKILLICON_START;
		}
		return nRet;
	}
	return -1;
}
// dashboard setting
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// dashboard selection hotkey
void yb_MainUIControl::setDashBoardSelectHotKey(unsigned int uHotKey)
{
	if(m_pStatusUI_Dash)
	{
		//		ANW::StatusUI_Button_NState* pIcon = (ANW::StatusUI_Button_NState*)m_pStatusUI_Dash->findControlPointer(ID_DASHBOARD_SELECTION);
		//		if(pIcon)
		//		{
		//			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Button_NState::RTTI.getName())
		//			{
		//				pIcon->setHotkey(uHotKey);
		//			}
		//		}
	}
}
unsigned int yb_MainUIControl::getDashBoardSelectHotKey()
{
	if(m_pStatusUI_Dash)
	{
		//		ANW::StatusUI_Button_NState* pIcon = (ANW::StatusUI_Button_NState*)m_pStatusUI_Dash->findControlPointer(ID_DASHBOARD_SELECTION);
		//		if(pIcon)
		//		{
		//			if(pIcon->getRTTI()->getName() == ANW::StatusUI_Button_NState::RTTI.getName())
		//			{
		//				return pIcon->getHotkey();
		//			}
		//		}
	}
	return 0;
}
// dashboard selection hotkey
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// chat message
void yb_MainUIControl::addMessage(CStringW strText, DWORD colorNormal, DWORD colorSelected, void* pData)
{
	if(m_pStatusUI_Dash)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_MESSAGEBOX_01);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->addItem(false, strText, colorNormal, colorSelected, pData);
		}
	}
}
void yb_MainUIControl::addMessage(WCHAR* strText, DWORD colorNormal, DWORD colorSelected, void* pData)
{
	CStringW nText = strText;
	addMessage(nText, colorNormal, colorSelected, pData);
}
void yb_MainUIControl::addMessage(char* strText, DWORD colorNormal, DWORD colorSelected, void* pData)
{
	CStringW nText = strText;
	addMessage(nText, colorNormal, colorSelected, pData);
}
void yb_MainUIControl::scrollMessageBox(int nAmount)
{
	if(m_pStatusUI_Dash)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_MESSAGEBOX_01);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->scrollPage(nAmount);
		}
	}
}
void yb_MainUIControl::scrollHome()
{
	if(m_pStatusUI_Dash)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_MESSAGEBOX_01);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->setHome();
		}
	}
}
void yb_MainUIControl::scrollEnd()
{
	if(m_pStatusUI_Dash)
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_MESSAGEBOX_01);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName())
		{
			ANW::StatusUI_ListBox_Target* pListBoxT = (ANW::StatusUI_ListBox_Target*)pControl;
			pListBoxT->setEnd();
		}
	}
}
void yb_MainUIControl::focusChat(bool bFlag)
{
	if(m_pStatusUI_Dash)
	{
		if(bFlag == false)
		{
			m_pStatusUI_Dash->setNextFocus();
			return;
		}

		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_CHAT_BAR);
		if(pControl)
		{
			m_pStatusUI_Dash->setFocus(pControl);
		}
	}
}
void yb_MainUIControl::ChatClear()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_MESSAGEBOX_01);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName() )
		{
			ANW::StatusUI_ListBox_Target* pListBox = (ANW::StatusUI_ListBox_Target*)pControl;
			if( pListBox && pListBox->getRTTI()->getName() == ANW::StatusUI_ListBox_Target::RTTI.getName() )
			{
				pListBox->removeAllItems();
			}
		}
		pControl = m_pStatusUI_Dash->findControlPointer(ID_MAINGAME_CHAT_BAR);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_IMEEditBox_Target::RTTI.getName() )
		{
			ANW::StatusUI_IMEEditBox_Target* pIMEBoxT = (ANW::StatusUI_IMEEditBox_Target*)pControl;
			if(pIMEBoxT && pIMEBoxT->getRTTI()->getName() == ANW::StatusUI_IMEEditBox_Target::RTTI.getName())
			{			
				pIMEBoxT->ClearText();
			}
		}
	}


}
// chat message
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
// START - result 결과창
//=================================================================================================================
void yb_MainUIControl::Show_Result_FildWindow( const bool& bFlag )				// 활성 비활성
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setVisible( bFlag );	}
}

void yb_MainUIControl::Set_Result_Fild_Text_00( const CStringW&	strIn )		// 몬서터킬
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_00, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Text_01( const CStringW&	strIn )		// 난이토 캐릭터 수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_01, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Text_02( const CStringW&	strIn )		// 부활 횟수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_02, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Text_03( const CStringW&	strIn )		// 평균점수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_03, strIn );	}
}

void yb_MainUIControl::Set_Result_Fild_Text_04( const CStringW&	strIn )		// 점령지역
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_04, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Text_05( const CStringW&	strIn )		// 사냥결과, 전장결과, 퀘스트 결과
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_05, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Text_06( const CStringW&	strIn )		// 남은시간
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_06, strIn );	}
}

// 값
void yb_MainUIControl::Set_Result_Fild_Value_00( const CStringW&	strIn )		// 몬서터킬
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_07, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_01( const CStringW&	strIn )		// 난이토 캐릭터 수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_08, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_02( const CStringW&	strIn )		// 부활 횟수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_09, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_03( const CStringW&	strIn )		// 평균점수
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_10, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_03_Visible( const bool& bFlag )		// 평균점수 활성 비활성
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setControlVisibility( ID_GAMERESULT_FILED_10, bFlag );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_03_Progress( const int nMax, const int& nCurrent)		//평균점수 프로그래스바
{
	if( m_pStatusUI_Result_Fild )
	{
		ANW::StatusUI_MainEnergy* pControl = (ANW::StatusUI_MainEnergy*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_PROGRESS);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_MainEnergy::RTTI.getName() )
		{
			pControl->setEnergy(nMax, nCurrent);
		}
	}
}
void yb_MainUIControl::Set_Result_Fild_Value_03_Progress_Visible( const bool& bFlag )		//평균점수 프로그래스바 활성비활성
{
	if( m_pStatusUI_Result_Fild )
	{
		m_pStatusUI_Result_Fild->setControlVisibility( ID_GAMERESULT_PROGRESS, bFlag );
	}
}
void yb_MainUIControl::Set_Result_Fild_Value_04( const CStringW&	strIn )		// 점령지역
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_11, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_05( const CStringW&	strIn )		// 사냥결과, 전장결과, 퀘스트 결과
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_12, strIn );	}
}
void yb_MainUIControl::Set_Result_Fild_Value_06( const CStringW&	strIn )		// 남은시간
{
	if( m_pStatusUI_Result_Fild )	{		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_13, strIn );	}
}
// 추가 경험치
void yb_MainUIControl::Set_Result_Fild_ExpStatus( const bool& bFlag1, const bool& bFlag2, const bool& bFlag3 )			// 아이템, PC방, 이벤트
{
	if( m_pStatusUI_Result_Fild )
	{
		ANW::StatusUI_CheckBox* pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_ITEM1);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag1 );
		}
		pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_PC1);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag2 );
		}
		pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_EVENT1);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag3 );
		}
	}
}
// 추가 금전
void yb_MainUIControl::Set_Result_Fild_GoldStatus( const bool& bFlag1, const bool& bFlag2, const bool& bFlag3 )			// 아이템, PC방, 이벤트
{
	if( m_pStatusUI_Result_Fild )
	{
		ANW::StatusUI_CheckBox* pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_ITEM2);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag1 );
		}
		pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_PC2);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag2 );
		}
		pControl = (ANW::StatusUI_CheckBox*)m_pStatusUI_Result_Fild->findControlPointer(ID_GAMERESULT_FILED_EVENT2);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_CheckBox::RTTI.getName() )
		{
			pControl->setChecked( bFlag3 );
		}
	}
}

void yb_MainUIControl::Set_Result_Fild_GOLD( const int& nGold )			// 획득금전
{
	if( m_pStatusUI_Result_Fild )	
	{
		char szBuf[128];
		CStringW strGold;
		sprintf( szBuf, "%d", nGold ); strGold = szBuf;
		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_GOLD, strGold );	
	}
}
void yb_MainUIControl::Set_Result_Fild_EXP( const int& nExp )			// 획득경험치
{
	if( m_pStatusUI_Result_Fild )	
	{
		char szBuf[128];
		CStringW strExp;
		sprintf( szBuf, "%d", nExp ); strExp = szBuf;
		m_pStatusUI_Result_Fild->setTextButton_Text( ID_GAMERESULT_FILED_EXP, strExp );	
	}
}

// 전장모드
void yb_MainUIControl::Show_Result_VSWindow( const bool& bFlag )					// 활성&비활성
{
	if( m_pStatusUI_Result_VS )
	{
		m_pStatusUI_Result_VS->setVisible( bFlag );
	}
}
void yb_MainUIControl::Set_Result_VS_FaceVisible( const int& nOrdinal, const bool& bFlag )			// 캐릭터 얼굴 -1 = 초기화 
{
	if( m_pStatusUI_Result_VS )
	{		
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_SHAREDFACE_00+i, bFlag );

			}
		}
		else if( (nOrdinal >=0) && (nOrdinal < 4) )
		{	
			m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_SHAREDFACE_00+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_VS_Face( const int& nPosOrdinal, const int& nOrdinal )		// 캐릭터 얼굴
{
	if( (nPosOrdinal < 0) || (nPosOrdinal > 3) )	{	return;	}
	if( (nOrdinal < 0) || (nOrdinal > 3) )	{	return;	}

	if( m_pStatusUI_Result_VS )
	{
		ANW::StatusUI_Button_SharedRect* pControl = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Result_VS->findControlPointer( ID_GAMERESULT_VS_SHAREDFACE_00 + nPosOrdinal );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button_SharedRect::RTTI.getName() )
		{
			pControl->SetReCharRectID( nOrdinal );
		}
	}
}
void yb_MainUIControl::Set_Result_VS_NameVisible( const int& nOrdinal, const bool& bFlag )				// 캐릭터 이름 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_VS )
	{		
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_CHARNAME_00+i, bFlag );

			}
		}
		else if( (nOrdinal >=0) && (nOrdinal < 4) )
		{			
			m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_CHARNAME_00+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_VS_Name( const int& nOrdinal, const CStringW& strName )		// 캐릭터 이름
{
	if( m_pStatusUI_Result_VS )
	{
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_CHARNAME_00 + nOrdinal, strName );
	}
}
void yb_MainUIControl::Set_Result_VS_ItemVisible( const int& nOrdinal, const bool& bFlag )				// 아이템 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_VS )
	{		
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_OBTAINEDITEM_00+i, bFlag );	
			}
		}
		else if( (nOrdinal >=0) && (nOrdinal < 4) )
		{			
			m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_OBTAINEDITEM_00+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_VS_ItemStatus( const int& nOrdinal, ANW::QUEST_SLOT_STATUS eStatus )				// 아이템 스테이트 QSS_YES = 있음, QSS_NONE = 없음
{
	if( m_pStatusUI_Result_VS )
	{
		ANW::StatusUI_QuestItem* pSlot = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_VS->findControlPointer( ID_GAMERESULT_VS_OBTAINEDITEM_00 + nOrdinal );
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName()))
		{
			pSlot->setSlotStatus(eStatus);
		}
	}
}
void yb_MainUIControl::Set_Result_VS_Item( const int& nOrdinal, const CStringW& strFileName )	// 아이템
{
	if( m_pStatusUI_Result_VS )
	{
		ANW::StatusUI_QuestItem* pSlot = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_VS->findControlPointer( ID_GAMERESULT_VS_OBTAINEDITEM_00 + nOrdinal );
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName()))
		{
			pSlot->getFileIcon()->setTexture( strFileName );
		}
	}
}

void yb_MainUIControl::Set_Result_VS_SkillItemVisible( const int& nOrdinal, const bool& bFlag )			// 스킬아이템 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_VS )
	{		
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_SKILLPOS_00+i, bFlag );
			}
		}
		else if( (nOrdinal >=0) && (nOrdinal < 4) )
		{	
			m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_SKILLPOS_00+nOrdinal, bFlag );		
		}
	}
}
void yb_MainUIControl::Set_Result_VS_SkillItem( const int& nOrdinal, const int& nSkillIndex )				// 스킬아이템
{
	if( m_pStatusUI_Result_VS )
	{
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Result_VS->findControlPointer( ID_GAMERESULT_VS_SKILLPOS_00 + nOrdinal );
		if( pIcon && pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
		{
			pIcon->setRectID( ID_SKILLICON_START + nSkillIndex );
		}
	}
}
void yb_MainUIControl::Set_Result_VS_ItemNameVisible( const int& nOrdinal, const bool& bFlag )			// 아이템 이름 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_VS )
	{		
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_ITEMNAME_00+i, bFlag );	
			}
		}
		else if( (nOrdinal >=0) && (nOrdinal < 4) )
		{			
			m_pStatusUI_Result_VS->setControlVisibility( ID_GAMERESULT_VS_ITEMNAME_00+nOrdinal, bFlag );	
		}
	}
}
void yb_MainUIControl::Set_Result_VS_ItemName( const int& nOrdinal, const CStringW& strName )				// 아이템 이름
{
	if( m_pStatusUI_Result_VS )
	{
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_ITEMNAME_00 + nOrdinal, strName );
	}
}

void yb_MainUIControl::Set_Result_VS_Record( const int& nV, const int& nS, const int&nP)					// 전승패
{
	if( m_pStatusUI_Result_VS )
	{
		char szBuf[64];
		CStringW strBuf;
		sprintf( szBuf, "%d", nV );
		strBuf = szBuf;
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_V, strBuf );
		sprintf( szBuf, "%d", nS );
		strBuf = szBuf;
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_S, strBuf );
		sprintf( szBuf, "%d", nP );
		strBuf = szBuf;
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_P, strBuf );
	}
}
void yb_MainUIControl::Set_Result_VS_Point( const int& nValue )											// 전장점수
{
	if( m_pStatusUI_Result_VS )
	{
		char szBuf[64];
		CStringW strBuf;
		sprintf( szBuf, "%d", nValue );
		strBuf = szBuf;
		m_pStatusUI_Result_VS->setTextButton_Text( ID_GAMERESULT_VS_POINT, strBuf );
	}
}
// 사냥모드
void yb_MainUIControl::Show_Result_KillWindow( const bool& bFlag )		// 활성 비활성
{
	if( m_pStatusUI_Result_KILL )
	{
		m_pStatusUI_Result_KILL->setVisible( bFlag );
	}
}
void yb_MainUIControl::Set_Result_KILL_FaceVisible( const int& nOrdinal, const bool& bFlag )				// 캐릭터 얼굴 -1 초기화
{
	if( m_pStatusUI_Result_KILL )
	{
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_SHAREDFACE_00 + i, false );
			}
		}
		else if( (nOrdinal >= 0) && (nOrdinal < 4) )
		{
			m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_SHAREDFACE_00 + nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_Face( const int& nPosOrdinal, const int& nOrdinal )					// 캐릭터 얼굴
{
	if( m_pStatusUI_Result_KILL )
	{
		ANW::StatusUI_Button_SharedRect* pControl = (ANW::StatusUI_Button_SharedRect*)m_pStatusUI_Result_KILL->findControlPointer( ID_GAMERESULT_KILL_SHAREDFACE_00 + nPosOrdinal );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_Button_SharedRect::RTTI.getName() )
		{
			pControl->SetReCharRectID( nOrdinal );
		}
	}
}

void yb_MainUIControl::Set_Result_KILL_NameVisible( const int& nOrdinal, const bool& bFlag )				// 캐릭터 이름 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_KILL )
	{
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_CHARNAME_00+i, false );
			}
		}
		else if( nOrdinal >= 0 && nOrdinal < 4 )
		{
			m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_CHARNAME_00+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_Name( const int& nOrdinal, const CStringW& strName )					// 캐릭터 이름
{
	if( m_pStatusUI_Result_KILL )
	{
		m_pStatusUI_Result_KILL->setTextButton_Text( ID_GAMERESULT_KILL_CHARNAME_00+nOrdinal, strName );
	}
}

void yb_MainUIControl::Set_Result_KILL_ItemVisible( const int& nOrdinal, const bool& bFlag )				// 아이템 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_KILL )
	{
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_KILL->setControlVisibility(ID_GAMERESULT_KILL_OBTAINEDITEM_00+i, false);
			}
		}
		else if( nOrdinal >= 0 && nOrdinal < 4 )
		{
			m_pStatusUI_Result_KILL->setControlVisibility(ID_GAMERESULT_KILL_OBTAINEDITEM_00+nOrdinal, bFlag);
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_ItemStatus( const int& nOrdinal, ANW::QUEST_SLOT_STATUS eStatus )	// 아이템 스테이트 QSS_YES = 있음, QSS_NONE = 없음
{
	if( m_pStatusUI_Result_KILL )
	{
		ANW::StatusUI_QuestItem* pSlot = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_KILL->findControlPointer( ID_GAMERESULT_KILL_OBTAINEDITEM_00 + nOrdinal );
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName()))
		{
			pSlot->setSlotStatus(eStatus);
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_Item( const int& nOrdinal, const CStringW& strFileName )				// 아이템
{
	if( m_pStatusUI_Result_KILL )
	{
		ANW::StatusUI_QuestItem* pControl = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_KILL->findControlPointer( ID_GAMERESULT_KILL_OBTAINEDITEM_00+nOrdinal );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName() )
		{
			pControl->getFileIcon()->setTexture( strFileName );
		}
	}
}

void yb_MainUIControl::Set_Result_KILL_SkillItemVisible( const int& nOrdinal, const bool& bFlag )			// 스킬아이템 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_KILL )
	{
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_KILL->setControlVisibility(ID_GAMERESULT_KILL_SKILLPOS_00+i, false);
			}
		}
		else if( nOrdinal >= 0 && nOrdinal < 4 )
		{
			m_pStatusUI_Result_KILL->setControlVisibility(ID_GAMERESULT_KILL_SKILLPOS_00+nOrdinal, bFlag);
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_SkillItem( const int& nOrdinal, const int& nSkillIndex )				// 스킬아이템
{
	if( m_pStatusUI_Result_KILL )
	{
		ANW::StatusUI_Shared_SkillIcon* pIcon = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Result_KILL->findControlPointer( ID_GAMERESULT_KILL_SKILLPOS_00 + nOrdinal );
		if( pIcon && pIcon->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
		{
			pIcon->setRectID( ID_SKILLICON_START + nSkillIndex );
		}
	}
}

void yb_MainUIControl::Set_Result_KILL_ItemNameVisible( const int& nOrdinal, const bool& bFlag )			// 아이템 이름 활성 비활성 -1 초기화
{
	if( m_pStatusUI_Result_KILL )
	{
		if( -1 == nOrdinal )
		{
			for( int i = 0; i < 4; ++i )
			{
				m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_ITEMNAME_00 + i, false );
			}
		}
		else if( nOrdinal >= 0 && nOrdinal < 4 )
		{
			m_pStatusUI_Result_KILL->setControlVisibility( ID_GAMERESULT_KILL_ITEMNAME_00+ nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_KILL_ItemName( const int& nOrdinal, const CStringW& strName )				// 아이템 이름	
{
	if( m_pStatusUI_Result_KILL )
	{
		m_pStatusUI_Result_KILL->setTextButton_Text( ID_GAMERESULT_KILL_ITEMNAME_00+nOrdinal, strName );
	}
}

// 퀘스트_1
void yb_MainUIControl::Show_Result_Quest_1_Windos( const bool& bFlag1, const bool& bFlag2 )				// bFlag1 = 활성비활성 bFlag2 = 퀘스트숫자 true = 1개, false = 2개
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setVisible( bFlag1 );

		if( false == bFlag2 )
		{
			m_pStatusUI_Result_QUEST_1->setPos(D3DXVECTOR3( 0.0f, -120.0f, 0.0f ));
		}
		else if( true == bFlag2 && m_pStatusUI_Result_QUEST_1->getPos() == D3DXVECTOR3( 0.0f, -120.0f, 0.0f ) )
		{
			m_pStatusUI_Result_QUEST_1->setPos(D3DXVECTOR3( 0.0f, 120.0f, 0.0f ));
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_1_Name( const CStringW& strName )									// 퀘스트 이름
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setTextButton_Text( ID_GAMERESULT_QUEST_NAME, strName );
	}
}
void yb_MainUIControl::Set_Result_Quest_1_MIssionVisible( const int& nOrdinal, const bool& bFlag )		// -1 초기화
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		if( -1 == nOrdinal )
		{
			for( int i = ID_GAMERESULT_QUEST_MISSION1; i<= ID_GAMERESULT_QUEST_MISSION3; ++i)
			{
				m_pStatusUI_Result_QUEST_1->setControlVisibility( i, false );
			}		
		}
		else
		{
			m_pStatusUI_Result_QUEST_1->setControlVisibility( ID_GAMERESULT_QUEST_MISSION1+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_1_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag )	// strIn = 내용, bflag = 완료했는가? -1 초기화
{ 
	if( m_pStatusUI_Result_QUEST_1 )
	{		
		m_pStatusUI_Result_QUEST_1->setTextButton_Text( ID_GAMERESULT_QUEST_MISSION1+nOrdinal, strIn );

		ANW::StatusUI_TextButton* pControl = (ANW::StatusUI_TextButton*)m_pStatusUI_Result_QUEST_1->findControlPointer( ID_GAMERESULT_QUEST_MISSION1+nOrdinal );		
		if( true == bFlag )
		{			
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 255, 255 ) );
			}
		}
		else if( false == bFlag )
		{
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 0, 0 ) );
			}
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_1_Restult( const CStringW& strIn )								// 수행결과
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setTextButton_Text( ID_GAMERESULT_QUEST_RESULT, strIn );
	}
}
void yb_MainUIControl::Set_Result_Quest_1_ItemVisible( const bool& bFlag )								// 아이템 활성 비활성
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setControlVisibility(ID_GAMERESULT_QUEST_GIVE_IMAGE, bFlag);
	}
}
void yb_MainUIControl::Set_Result_Quest_1_ItemStatus( ANW::QUEST_SLOT_STATUS eStatus )					// 아이템 스테이트 QSS_YES = 있음, QSS_NONE = 없음
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		ANW::StatusUI_QuestItem* pControl = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_QUEST_1->findControlPointer(ID_GAMERESULT_QUEST_GIVE_IMAGE);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName() )
		{
			pControl->setSlotStatus( eStatus );
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_1_Item( const CStringW& strFileName )							// 아이템
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		ANW::StatusUI_QuestItem* pControl = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_QUEST_1->findControlPointer(ID_GAMERESULT_QUEST_GIVE_IMAGE);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName() )
		{
			pControl->getFileIcon()->setTexture(strFileName);
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_1_ItemNameVisible( const bool& bFlag )							// 아이템 이름 활성비활성
{	
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setControlVisibility(ID_GAMERESULT_QUEST_GIVE_NAME, bFlag );
	}
}
void yb_MainUIControl::Set_Result_Quest_1_ItemName( const CStringW& strItemName )							// 아이템 이름
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setTextButton_Text(ID_GAMERESULT_QUEST_GIVE_NAME, strItemName);
	}
}
void yb_MainUIControl::Set_Result_Quest_1_Exp( const CStringW& strExp )									// 보상 경험치
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setTextButton_Text( ID_GAMERESULT_QUEST_GIVE_EXP, strExp );
	}
}
void yb_MainUIControl::Set_Result_Quest_1_Gold( const CStringW& strExp )									// 보상 금전
{
	if( m_pStatusUI_Result_QUEST_1 )
	{
		m_pStatusUI_Result_QUEST_1->setTextButton_Text( ID_GAMERESULT_QUEST_GIVE_GOLD, strExp );
	}
}

// 퀘스트_2
void yb_MainUIControl::Show_Result_Quest_2_Windos( const bool& bFlag )				//  황성비활성
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setVisible( bFlag );		
	}
}
void yb_MainUIControl::Set_Result_Quest_2_Name( const CStringW& strName )									// 퀘스트 이름
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text( ID_GAMERESULT_QUEST_NAME_2, strName );
	}
}
void yb_MainUIControl::Set_Result_Quest_2_MIssionVisible( const int& nOrdinal, const bool& bFlag )		// -1 초기화
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		if( -1 == nOrdinal )
		{
			for( int i = ID_GAMERESULT_QUEST_MISSION1_2; i<= ID_GAMERESULT_QUEST_MISSION3_2; ++i)
			{
				m_pStatusUI_Result_QUEST_2->setControlVisibility( i, false );
			}		
		}
		else
		{
			m_pStatusUI_Result_QUEST_2->setControlVisibility( ID_GAMERESULT_QUEST_MISSION1_2+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_2_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag )	// ordinal = 0,1,2 : strIn = 내용, bflag = 완료했는가?
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text( ID_GAMERESULT_QUEST_MISSION1_2+nOrdinal, strIn );

		ANW::StatusUI_TextButton* pControl = (ANW::StatusUI_TextButton*)m_pStatusUI_Result_QUEST_2->findControlPointer( ID_GAMERESULT_QUEST_MISSION1_2+nOrdinal );		
		if( true == bFlag )
		{			
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 255, 255 ) );
			}
		}
		else if( false == bFlag )
		{
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 0, 0 ) );
			}
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_2_Restult( const CStringW& strIn )								// 수행결과
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text( ID_GAMERESULT_QUEST_RESULT_2, strIn );
	}
}
void yb_MainUIControl::Set_Result_Quest_2_ItemVisible( const bool& bFlag )								// 아이템 활성 비활성
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setControlVisibility(ID_GAMERESULT_QUEST_GIVE_IMAGE_2, bFlag);
	}
}
void yb_MainUIControl::Set_Result_Quest_2_ItemStatus( ANW::QUEST_SLOT_STATUS eStatus )					// 아이템 스테이트 QSS_YES = 있음, QSS_NONE = 없음
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		ANW::StatusUI_QuestItem* pControl = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_QUEST_2->findControlPointer(ID_GAMERESULT_QUEST_GIVE_IMAGE_2);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName() )
		{
			pControl->setSlotStatus( eStatus );
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_2_Item( const CStringW& strFileName )							// 아이템
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		ANW::StatusUI_QuestItem* pControl = (ANW::StatusUI_QuestItem*)m_pStatusUI_Result_QUEST_2->findControlPointer(ID_GAMERESULT_QUEST_GIVE_IMAGE_2);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_QuestItem::RTTI.getName() )
		{
			pControl->getFileIcon()->setTexture(strFileName);
		}
	}
}
void yb_MainUIControl::Set_Result_Quest_2_ItemNameVisible( const bool& bFlag )							// 아이템 이름 활성비활성
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setControlVisibility(ID_GAMERESULT_QUEST_GIVE_NAME_2, bFlag );
	}
}
void yb_MainUIControl::Set_Result_Quest_2_ItemName( const CStringW& strItemName )							// 아이템 이름
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text(ID_GAMERESULT_QUEST_GIVE_NAME_2, strItemName);
	}
}
void yb_MainUIControl::Set_Result_Quest_2_Exp( const CStringW& strExp )									// 보상 경험치
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text( ID_GAMERESULT_QUEST_GIVE_EXP_2, strExp );
	}
}
void yb_MainUIControl::Set_Result_Quest_2_Gold( const CStringW& strExp )									// 보상 금전
{
	if( m_pStatusUI_Result_QUEST_2 )
	{
		m_pStatusUI_Result_QUEST_2->setTextButton_Text( ID_GAMERESULT_QUEST_GIVE_GOLD_2, strExp );
	}
}
//=================================================================================================================
// END - result 결과창
//=================================================================================================================



//=================================================================================================================
// START - 퀘스트
//=================================================================================================================
void yb_MainUIControl::Set_Quest_MIssionVisible( const int& nOrdinal, const bool& bFlag )		// -1 초기화
{
	if( m_pStatusUI_Story )
	{
		if( -1 == nOrdinal )
		{
			for( int i = ID_GAME_QUEST_MISSION1; i<= ID_GAME_QUEST_MISSION3; ++i)
			{
				m_pStatusUI_Story->setControlVisibility( i, false );
			}		
		}
		else
		{
			m_pStatusUI_Story->setControlVisibility( ID_GAME_QUEST_MISSION1+nOrdinal, bFlag );
		}
	}
}
void yb_MainUIControl::Set_Quest_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag )	// nOrdinal ; 0,1,2 strIn = 내용, bflag = 완료했는가?
{
	if( m_pStatusUI_Story )
	{		
		m_pStatusUI_Story->setTextButton_Text( ID_GAME_QUEST_MISSION1+nOrdinal, strIn );

		ANW::StatusUI_TextButton* pControl = (ANW::StatusUI_TextButton*)m_pStatusUI_Story->findControlPointer( ID_GAME_QUEST_MISSION1+nOrdinal );		
		if( true == bFlag )
		{			
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 255, 255 ) );
			}
		}
		else if( false == bFlag )
		{
			if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
			{
				pControl->setFontColor( D3DCOLOR_ARGB( 255, 255, 0, 0 ) );
			}
		}
	}
}
//=================================================================================================================
// END - 퀘스트
//=================================================================================================================


//=================================================================================================================
// START - 강제 퇴장
//=================================================================================================================
VOID yb_MainUIControl::DoModal_GameLeaving(CStringW strIn, int posX, int posY )
{
	if(m_pModal_Leaving)
	{
		m_pModal_Leaving->setPos( static_cast<float>(posX), static_cast<float>(posY), 0);
		// Modal설정

		m_pModal_Leaving->setTextButton_Text(ID_LEAVING_MSG1, strIn );
		g_pStaticEngine->setModal(m_pModal_Leaving);
	}
}
//=================================================================================================================
// END - 강제 퇴장
//=================================================================================================================



//=================================================================================================================
//=================================================================================================================
// 게임설명서 게임중 텍스트 표시
void yb_MainUIControl::setGameHelpMessage( bool bFlag, CStringW strIn )
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_TextButton* pTextButton = (ANW::StatusUI_TextButton*)m_pStatusUI_Dash->findControlPointer( ID_MAINGAME_HELP_MESSAGE );
		if( pTextButton->getRTTI()->getName() == ANW::StatusUI_TextButton::RTTI.getName() )
		{
			pTextButton->setVisible( bFlag );
			pTextButton->setRectItemText( strIn );
		}		
	}
}
// 게임설명서 게임중 텍스트 표시
//=================================================================================================================
//=================================================================================================================


//=================================================================================================================
//=================================================================================================================
// Modal
void yb_MainUIControl::DoModal_GameExitQuestion( CStringW strIn, int posX, int posY )
{	
	if(m_pModal_ExitQuestion)
	{
		m_pModal_ExitQuestion->setPos( static_cast<float>(posX), static_cast<float>(posY), 0);
		// Modal설정

		m_pModal_ExitQuestion->setTextButton_Text(ID_MODAL_MSG, strIn );
		g_pStaticEngine->setModal(m_pModal_ExitQuestion);
	}
}

// 부활
void yb_MainUIControl::ShowResurrection( bool bShow, int nItemCount )
{
	m_pModal_Resurrection->setVisible( bShow );
	//g_pStaticEngine->setModal(m_pModal_Resurrection);
	//m_pModal_Resurrection->setControlEnabled( ID_GAMERESURRECTION_OK, true );
	//m_pModal_Resurrection->setControlEnabled( ID_GAMERESURRECTION_CENCLE, true );

	//if( 0 == nItemCount )
	//	m_pModal_Resurrection->setControlEnabled( ID_GAMERESURRECTION_OK, false );

	ANW::StatusUI_TextButton* pTxt= (ANW::StatusUI_TextButton*)m_pModal_Resurrection->findControlPointer( ID_GAMERESURRECTION_MSG2 );

	pTxt->setFontColor(D3DCOLOR_ARGB( 255, 255, 255, 255 ) );

	CHAR szBuf[ 128 ]={0,};
	sprintf( szBuf, " X %d 개", nItemCount );
	m_pModal_Resurrection->setTextButton_Text(ID_GAMERESURRECTION_MSG2, szBuf);

}
void yb_MainUIControl::SetResurrectionTime( unsigned int nTime )
{
	CHAR szBuf[ 128 ]={0,};
	sprintf( szBuf, "남은시간 : %d 초", nTime );
	m_pModal_Resurrection->setTextButton_Text( ID_GAMERESURRECTION_MSG3, szBuf );

	if( nTime <= 0 )
		ShowResurrection( false );
}

// Game_Question
void yb_MainUIControl::DoModal_GameQuestion( const CStringW& strIn )
{
	if( m_pModal_Question )
	{
		m_pModal_Question->setPos( 415.0f, 286.0f, 0.0f );
		m_pModal_Question->setTextButton_Text( ID_MODAL_QUESTION_MSG, strIn );
		g_pStaticEngine->setModal( m_pModal_Question );
	}
}
// Modal
//=================================================================================================================
//=================================================================================================================



//=================================================================================================================
//=================================================================================================================
// 툴팁

int	yb_MainUIControl::getItemIndexNumber()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->getItemIndex();
		}
	}
	return -1;
}
bool yb_MainUIControl::getMouseIn_Out()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->getMouseIn();
		}
	}
	return false;
}
bool yb_MainUIControl::getMouseIn_Out( const int& nID )
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag ->findControlPointer( nID );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->getMouseIn();
		}
	}
	return false;
}

void yb_MainUIControl::setShowToolTip( bool nFlag )
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setVisible( nFlag );
		}

	}
}
void yb_MainUIControl::setShowToolTip( const int& nID, bool nFlag )		// 내가방용
{	
	if( m_pGameMyBag ) 	
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTooltip = (ANW::StatusUI_ToolTip*)pControl;
			return pTooltip->setVisible( nFlag );
		}
	}
}

void yb_MainUIControl::removeToolTipList()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->removeList();
		}

	}
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->removeList();
		}

	}
}
void yb_MainUIControl::setToolTipNoMessage()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setNomalMessage();
		}

	}
}

/* 게임안에서의 창고 툴팁 처리 부분 */

void yb_MainUIControl::myBagToolTip_ItemNumber( int nID, int nValue, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ItemNumber( nValue, color );
		}
	}
}

void yb_MainUIControl::myBagToolTip_InAttack( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_InAttack( nValue1, nValue2, color );
		}
	}
}
void yb_MainUIControl::myBagToolTip_LongAttack( int nID,int nValue1, int nValue2, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_LongAttack( nValue1, nValue2, color );
		}
	}
}


void yb_MainUIControl::myBagToolTip_PhyAttack( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_PhyAttack( nValue1, nValue2, color );
		}
	}
}

void yb_MainUIControl::myBagToolTip_Level(int nID, int nValue1, int nValue2, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Level( nValue1, nValue2, color );
		}
	}		
}

void yb_MainUIControl::myBagToolTip_Power( int nID,CStringW strIn , COLORREF color)										// 사용세력
{	
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Power( strIn, color );
		}
	}
}
// tooltip information( item )
void yb_MainUIControl::myBagToolTip_AddPoint( int nID, int nValue, COLORREF color)	
{	
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_AddPoint( nValue, color );
		}
	}	
}
void yb_MainUIControl::myBagToolTip_HardRestor( int nID, int nValue, COLORREF color)
{

	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_HardRestor( nValue, color );
		}
	}
}
void yb_MainUIControl::myBagToolTip_Hard( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Hard( nValue1, nValue2, color );
		}
	}		
}

void yb_MainUIControl::myBagToolTip_Character(int nID, CStringW strIn, COLORREF color)
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Character( strIn, color );
		}
	}
}

void yb_MainUIControl::myBagToolTip_ItemName(int nID, CStringW strIn, COLORREF color )
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer(nID);
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_SkillName( strIn, color );
		}
	}
}

int yb_MainUIControl::getItemIndexNumber(int nID )
{
	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTooltip = (ANW::StatusUI_ToolTip*)pControl;
			return pTooltip->getItemIndex();
		}
	}
	return -1;
}

void yb_MainUIControl::myBagToolTip_ItemBeefUpOption1( int nID, CStringW strIn, COLORREF color)
{	
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ItemBeefUpOption1( strIn, color );
		}
	}
}
void yb_MainUIControl::myBagToolTip_ItemBeefUpOption2( int nID, CStringW strIn, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ItemBeefUpOption2( strIn, color );
		}
	}	
}

void yb_MainUIControl::myBagToolTip_ItemExplanation( int nID, CStringW strIn, COLORREF color)
{

	if( NULL != m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_SkillExplanation( strIn, color );
		}
	}
}

void yb_MainUIControl::ToolTip_ItemName(CStringW strIn, COLORREF color )
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_ItemName( strIn, color );
		}

	}
}
void yb_MainUIControl::ToolTip_ItemName(const char* strIn, COLORREF color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_ItemName( strBuf, color );

}
void yb_MainUIControl::ToolTip_ItemName(const WCHAR* strIn, COLORREF color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_ItemName( strBuf, color );
}
void yb_MainUIControl::ToolTip_Step(int nValue, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Step( nValue, color );
		}

	}
}
void yb_MainUIControl::ToolTip_Character(CStringW strIn, COLORREF color )
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Character( strIn, color );
		}
	}
}
void yb_MainUIControl::ToolTip_Character(const char* strIn, COLORREF color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Character( strBuf, color );
}
void yb_MainUIControl::ToolTip_Character(const WCHAR* strIn, COLORREF color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Character( strBuf, color );
}

void yb_MainUIControl::ToolTip_Level( int nValue,  COLORREF color )
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Level( nValue, color );
		}
	}
}

void yb_MainUIControl::ToolTip_Oder(CStringW strIn, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Oder( strIn, color );
		}
	}
}
void yb_MainUIControl::ToolTip_Oder(const char* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Oder( strBuf, color );
}
void yb_MainUIControl::ToolTip_Oder(const WCHAR* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Oder( strBuf, color );
}
void yb_MainUIControl::ToolTip_Embarkation(CStringW strIn, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Embarkation( strIn, color );
		}
	}
}
void yb_MainUIControl::ToolTip_Embarkation(const char* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Embarkation( strBuf, color );
}
void yb_MainUIControl::ToolTip_Embarkation(const WCHAR* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Embarkation( strBuf, color );
}
void yb_MainUIControl::ToolTip_Arms(CStringW strIn, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_Arms( strIn, color );
		}
	}
}
void yb_MainUIControl::ToolTip_Arms(const char* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Arms( strBuf, color );
}
void yb_MainUIControl::ToolTip_Arms(const WCHAR* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_Arms( strBuf, color );
}
void yb_MainUIControl::ToolTip_ConsumptionLife(int nValue, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_ConsumptionLife( nValue, color );
		}
	}
}
void yb_MainUIControl::ToolTip_ConsumptionPoint(int nValue, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_ConsumptionPoint( nValue, color );
		}
	}
}
void yb_MainUIControl::ToolTip_AgainTime(int nValue, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_AgainTime( nValue, color );
		}
	}
}
void yb_MainUIControl::ToolTip_BeefUpStep(int nValue, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_BeefUpStep( nValue, color );
		}
	}
}
void yb_MainUIControl::ToolTip_ItemExplanation(CStringW strIn, COLORREF color)
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			return pToolTip->setShop_SkillExplanation( strIn, color );
		}
	}
}
void yb_MainUIControl::ToolTip_ItemExplanation(const char* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_ItemExplanation( strBuf, color );

}
void yb_MainUIControl::ToolTip_ItemExplanation(const WCHAR* strIn, COLORREF color)
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	ToolTip_ItemExplanation( strBuf, color );
}

ANW::StatusUI_Control*	yb_MainUIControl::getContorl()
{
	if( m_pStatusUI_Dash )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Dash->findControlPointer( ID_GAMETOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pTaget = (ANW::StatusUI_ToolTip*)pControl;
			return pTaget->getControl();
		}
	}
	return NULL;
}


bool yb_MainUIControl::getBufMouseIn_Out()
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( ID_GAMEBUFTOOLTIP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTaget = (ANW::StatusUI_ToolTip*)pControl;
			bool temp = pTaget->getMouseIn();
			return pTaget->getMouseIn();

		}
	}
	return false;
}
void yb_MainUIControl::removeBufToolTipList()
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( ID_GAMEBUFTOOLTIP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTaget = (ANW::StatusUI_ToolTip*)pControl;
			pTaget->removeList();
		}
	}
}
void yb_MainUIControl::setBufShowToolTip( bool nFlag )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( ID_GAMEBUFTOOLTIP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTaget = (ANW::StatusUI_ToolTip*)pControl;
			return pTaget->setVisible( nFlag );
		}
	}
}
void yb_MainUIControl::BufToolTip_Explanation( const CStringW& strIn, const int& nLine, const COLORREF& color )
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( ID_GAMEBUFTOOLTIP );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName() )
		{
			ANW::StatusUI_ToolTip* pTaget = (ANW::StatusUI_ToolTip*)pControl;
			pTaget->BufSkillExplanation( strIn, nLine, color );
		}
	}
}
void yb_MainUIControl::BufToolTip_Explanation(const char* strIn, const int& nLine, const COLORREF& color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	BufToolTip_Explanation( strBuf, nLine, color );
}
void yb_MainUIControl::BufToolTip_Explanation(const WCHAR* strIn, const int& nLine, const COLORREF& color )
{
	ANW_ASSERT(strIn);
	CStringW strBuf = strIn;
	BufToolTip_Explanation( strBuf, nLine, color );
}

int yb_MainUIControl::getBufItemIndexNumber()
{
	if( m_pStatusUI_Char )
	{
		ANW::StatusUI_Control* pControl = m_pStatusUI_Char->findControlPointer( ID_GAMEBUFTOOLTIP );
		if(pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName())
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			int nBufItemIndexNum = 0;
			switch( pToolTip->getItemIndex() )
			{
			case 0:			nBufItemIndexNum = 0;break;
			case 1:			nBufItemIndexNum = 1;break;
			case 2:			nBufItemIndexNum = 2;break;
			case 3:			nBufItemIndexNum = 3;break;
			case 4:			nBufItemIndexNum = 4;break;
			case 5:			nBufItemIndexNum = 5;break;
			case 10:		nBufItemIndexNum = 0;break;
			case 11:		nBufItemIndexNum = 1;break;
			case 12:		nBufItemIndexNum = 2;break;
			case 13:		nBufItemIndexNum = 3;break;
			case 14:		nBufItemIndexNum = 4;break;
			case 15:		nBufItemIndexNum = 5;break;
			case 20:		nBufItemIndexNum = 0;break;
			case 21:		nBufItemIndexNum = 1;break;
			case 22:		nBufItemIndexNum = 2;break;
			case 23:		nBufItemIndexNum = 3;break;
			case 24:		nBufItemIndexNum = 4;break;
			case 25:		nBufItemIndexNum = 5;break;
			case 30:		nBufItemIndexNum = 0;break;
			case 31:		nBufItemIndexNum = 1;break;
			case 32:		nBufItemIndexNum = 2;break;
			case 33:		nBufItemIndexNum = 3;break;
			case 34:		nBufItemIndexNum = 4;break;
			case 35:		nBufItemIndexNum = 5;break;
			case 40:		nBufItemIndexNum = 0;break;
			case 41:		nBufItemIndexNum = 1;break;
			case 42:		nBufItemIndexNum = 2;break;
			case 43:		nBufItemIndexNum = 3;break;
			case 44:		nBufItemIndexNum = 4;break;
			case 45:		nBufItemIndexNum = 5;break;
			case 100:		nBufItemIndexNum = 0;break;
			case 101:		nBufItemIndexNum = 1;break;
			case 102:		nBufItemIndexNum = 2;break;
			case 103:		nBufItemIndexNum = 3;break;
			case 104:		nBufItemIndexNum = 4;break;
			case 105:		nBufItemIndexNum = 5;break;
			case 110:		nBufItemIndexNum = 0;break;
			case 111:		nBufItemIndexNum = 1;break;
			case 112:		nBufItemIndexNum = 2;break;
			case 113:		nBufItemIndexNum = 3;break;
			case 114:		nBufItemIndexNum = 4;break;
			case 115:		nBufItemIndexNum = 5;break;
			case 120:		nBufItemIndexNum = 0;break;
			case 121:		nBufItemIndexNum = 1;break;
			case 122:		nBufItemIndexNum = 2;break;
			case 123:		nBufItemIndexNum = 3;break;
			case 124:		nBufItemIndexNum = 4;break;
			case 125:		nBufItemIndexNum = 5;break;
			case 130:		nBufItemIndexNum = 0;break;
			case 131:		nBufItemIndexNum = 1;break;
			case 132:		nBufItemIndexNum = 2;break;
			case 133:		nBufItemIndexNum = 3;break;
			case 134:		nBufItemIndexNum = 4;break;
			case 135:		nBufItemIndexNum = 5;break;
			case 140:		nBufItemIndexNum = 0;break;
			case 141:		nBufItemIndexNum = 1;break;
			case 142:		nBufItemIndexNum = 2;break;
			case 143:		nBufItemIndexNum = 3;break;
			case 144:		nBufItemIndexNum = 4;break;
			case 145:		nBufItemIndexNum = 5;break;
			case 150:		nBufItemIndexNum = 0;break;
			case 151:		nBufItemIndexNum = 1;break;
			case 152:		nBufItemIndexNum = 2;break;
			case 153:		nBufItemIndexNum = 3;break;
			case 154:		nBufItemIndexNum = 4;break;
			case 155:		nBufItemIndexNum = 5;break;	
			}
			return nBufItemIndexNum;
		}
	}
	return -1;
}

// 툴팁
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// TeamSkill 팀스킬 Start
void yb_MainUIControl::SetTeamSkill_Clean()
{
	if( m_pStatusUI_Dash )
	{
		for( int i = ID_SKILLICON_MAINGAME_POSA; i < ID_SKILLICON_MAINGAME_POSD+1; ++i )
		{
			ANW::StatusUI_Shared_SkillIcon* pTaget = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer( i );
			if( pTaget && pTaget->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
			{
				pTaget->setVisible( true );
				//				pTaget->setRectID( ID_TEAMSKILLICON_START-1 );
				pTaget->setRectID( -1 );
			}

		}
	}
}
void yb_MainUIControl::SetTeamSkill_Show(int nSlot, bool bFlag )
{
	if( m_pStatusUI_Dash )
	{
		int nCurrentID = ID_SKILLICON_MAINGAME_POSA + nSlot;
		ANW::StatusUI_Shared_SkillIcon* pTaget = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer( nCurrentID );
		if( pTaget && pTaget->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
		{
			pTaget->setVisible( bFlag );
		}
	}
}
void yb_MainUIControl::SetTeamSkill_Icon( int nSlot, int nSkillIndex )
{
	if( m_pStatusUI_Dash )
	{
		int nCurrentID = ID_SKILLICON_MAINGAME_POSA + nSlot;
		ANW::StatusUI_Shared_SkillIcon* pTaget = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer( nCurrentID );
		if( pTaget && pTaget->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
		{
			pTaget->setRectID( ID_TEAMSKILLICON_START + nSkillIndex );
		}
	}
}
void yb_MainUIControl::SetTeamSkill_IconClean( const int& nSlot )
{
	if( m_pStatusUI_Dash )
	{
		int nCurrentID = ID_SKILLICON_MAINGAME_POSA + nSlot;
		ANW::StatusUI_Shared_SkillIcon* pTaget = (ANW::StatusUI_Shared_SkillIcon*)m_pStatusUI_Dash->findControlPointer( nCurrentID );
		if( pTaget && pTaget->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName() )
		{
			pTaget->setRectID(0);
		}
	}
}

// TeamSkill 팀스킬	End
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================
//=================================================================================================================
// Option option 옵션
void yb_MainUIControl::ShowGameKeyState( bool bFlag )
{
	if( m_pStatusUI_Key )
	{		
		g_pStaticEngine->setModal( m_pStatusUI_Key );
	}
	switch( Get_Option_SelectKey() )
	{
	case ID_MAINGAME_OPTION_GAME_KEY:		Show_Option_GameKey( bFlag );			break;
	case ID_MAINGAME_OPTION_SKILL_KEY:		Show_Option_Skill( bFlag );				break;
	case ID_MAINGAME_OPTION_COMSKILL_KEY:	Show_Option_ComSkill( bFlag );			break;
	}
}
int yb_MainUIControl::Get_Option_SelectKey()
{
	if( m_pStatusUI_Key )
	{
		int nID = -1;
		nID = m_pStatusUI_Key->getSelectedRadio( ID_MAINGAME_OPTION_RADIO_GROUP );
		if( nID > 0 )
			return nID;
	}

	return -1;
}
void yb_MainUIControl::Show_Option_GameKey( bool bFlag )
{
	if( m_pStatusUI_Key )
	{
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_JUMP, bFlag );
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_ATTACK,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_CHANGEWEAPON,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_RIDEPET,	bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_MOVEUP,	bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_MOVEDOWN,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_MOVERIGHT,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_MOVELEFT,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_TEAMSKILL1,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_TEAMSKILL2,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_TEAMSKILL3,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_TEAMSKILL4,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SELOURTEAM,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SELLEFTOPP,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SELNEAROPP,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SELRIGHTOPP,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SHOWINFO,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_KEY_SHOWHELP,bFlag);
	}
}
void yb_MainUIControl::Show_Option_Skill( bool bFlag )
{
	if( m_pStatusUI_Key )
	{
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL01,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL02,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL03,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL04,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL05,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL06,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL07,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL08,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL09,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_SKILL10,bFlag);
	}
}
void yb_MainUIControl::Show_Option_ComSkill( bool bFlag )
{
	if( m_pStatusUI_Key )
	{
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL01,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL02,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL03,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL04,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL05,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL06,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL07,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL08,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL09,bFlag);
		m_pStatusUI_Key->setControlVisibility(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL10,bFlag);
	}
}

// 키보드
void yb_MainUIControl::option_KB_setJump(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_JUMP, wParam);}}
void yb_MainUIControl::option_KB_setAttack(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_ATTACK, wParam);}}
void yb_MainUIControl::option_KB_setChangeWeapon(WPARAM wParam){if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_CHANGEWEAPON, wParam);}}
void yb_MainUIControl::option_KB_setRidePet(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_RIDEPET, wParam);}}
void yb_MainUIControl::option_KB_setMoveUp(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_MOVEUP, wParam);}}
void yb_MainUIControl::option_KB_setMoveDown(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_MOVEDOWN, wParam);}}
void yb_MainUIControl::option_KB_setMoveRight(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_MOVERIGHT, wParam);}}
void yb_MainUIControl::option_KB_setMoveLeft(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_MOVELEFT, wParam);}}
void yb_MainUIControl::option_KB_setTeamSkill1(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_TEAMSKILL1, wParam);}}
void yb_MainUIControl::option_KB_setTeamSkill2(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_TEAMSKILL2, wParam);}}
void yb_MainUIControl::option_KB_setTeamSkill3(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_TEAMSKILL3, wParam);}}
void yb_MainUIControl::option_KB_setTeamSkill4(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_TEAMSKILL4, wParam);}}
void yb_MainUIControl::option_KB_setSelectOurTeam(WPARAM wParam){if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SELOURTEAM, wParam);}}
void yb_MainUIControl::option_KB_setSelectNearEnemy(WPARAM wParam){if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SELNEAROPP, wParam);}}
void yb_MainUIControl::option_KB_setSelectLeftEnemy(WPARAM wParam){if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SELLEFTOPP, wParam);}}
void yb_MainUIControl::option_KB_setSelectRightEnemy(WPARAM wParam){if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SELRIGHTOPP, wParam);}}
void yb_MainUIControl::option_KB_setShowInfo(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SHOWINFO, wParam);}}
void yb_MainUIControl::option_KB_setShowHelp(WPARAM wParam)	{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_KEY_SHOWHELP, wParam);}}
// 단축스킬
void yb_MainUIControl::option_SC_setSkill01(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL01, wParam);}}
void yb_MainUIControl::option_SC_setSkill02(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL02, wParam);}}
void yb_MainUIControl::option_SC_setSkill03(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL03, wParam);}}
void yb_MainUIControl::option_SC_setSkill04(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL04, wParam);}}
void yb_MainUIControl::option_SC_setSkill05(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL05, wParam);}}
void yb_MainUIControl::option_SC_setSkill06(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL06, wParam);}}
void yb_MainUIControl::option_SC_setSkill07(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL07, wParam);}}
void yb_MainUIControl::option_SC_setSkill08(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL08, wParam);}}
void yb_MainUIControl::option_SC_setSkill09(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL09, wParam);}}
void yb_MainUIControl::option_SC_setSkill10(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_SKILL10, wParam);}}
// 공통단축스킬
void yb_MainUIControl::option_SC_setComSkill01(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL01, wParam);}}
void yb_MainUIControl::option_SC_setComSkill02(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL02, wParam);}}
void yb_MainUIControl::option_SC_setComSkill03(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL03, wParam);}}
void yb_MainUIControl::option_SC_setComSkill04(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL04, wParam);}}
void yb_MainUIControl::option_SC_setComSkill05(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL05, wParam);}}
void yb_MainUIControl::option_SC_setComSkill06(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL06, wParam);}}
void yb_MainUIControl::option_SC_setComSkill07(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL07, wParam);}}
void yb_MainUIControl::option_SC_setComSkill08(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL08, wParam);}}
void yb_MainUIControl::option_SC_setComSkill09(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL09, wParam);}}
void yb_MainUIControl::option_SC_setComSkill10(WPARAM wParam)		{if(m_pStatusUI_Key)	{m_pStatusUI_Key->setButtonKeyboardKey(ID_MAINGAME_OPTION_SHOTCUT_COMSKILL10, wParam);}}
// Option option 옵션
//=================================================================================================================
//=================================================================================================================

//=================================================================================================================================//
// -START- : 내가방
//=================================================================================================================================//

void yb_MainUIControl::myBagToolTip_DesBeefUp( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_DesBeefUp(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_ComBeefUp( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ComBeefUp(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_DefBeefUp( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_DefBeefUp(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_ProBeefUp( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ProBeefUp(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_AttSpeed( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_AttSpeed(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_MovSpeed( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_MovSpeed(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_Pat( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Pat(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_AddAttack( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_AddAttack(nValue,color);
		}
	}
}
void yb_MainUIControl::myBagToolTip_ResTime(int nID, int fValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_ResTime( fValue, color );
		}
	}
}

void yb_MainUIControl::myBagToolTip_AddExp(const int& nID, const int& fValue, const COLORREF& color)								// 추가경험처
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_AddExp( fValue, color );
		}
	}
}

void yb_MainUIControl::myBagToolTip_AddGold(const int& nID, const int& fValue, const COLORREF& color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_AddGold( fValue, color );
		}
	}
}


/* */

void yb_MainUIControl::myBagToolTip_PhyDefense( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_PhyDefense( nValue1, nValue2, color );
		}
	}		
}
void yb_MainUIControl::myBagToolTip_InDefense( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_InDefense( nValue1, nValue2, color );
		}
	}		
}
void yb_MainUIControl::myBagToolTip_LongDefense( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_LongDefense( nValue1, nValue2, color );
		}
	}		
}
void yb_MainUIControl::myBagToolTip_NonBeefUp( int nID, int nValue, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_NonBeefUp(nValue,color);
		}
	}
}



void yb_MainUIControl::myBagToolTip_Life( int nID, int nValue1, int nValue2, COLORREF color)
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_Control* pControl = m_pGameMyBag->findControlPointer( nID );
		if( pControl->getRTTI()->getName() == ANW::StatusUI_ToolTip::RTTI.getName()) 
		{
			ANW::StatusUI_ToolTip* pToolTip = (ANW::StatusUI_ToolTip*)pControl;
			pToolTip->setBag_Life( nValue1, nValue2, color );
		}
	}
}


void yb_MainUIControl::myBag_Init()
{
	if( m_pGameMyBag )
	{
		for( int i = 0; i < 25; ++i )
		{		
			ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + i);
			if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
			{
				pSlot->setVisible( false );
			}
		}
	}
}
void yb_MainUIControl::myBag_setItemTexture(int nOrdinal, CStringW strTexture)
{	
	if((m_pGameMyBag)&&(nOrdinal >= 0)&&(nOrdinal < 25))
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
		{
			pSlot->setVisible( true );
			pSlot->getFileIcon()->setTexture( strTexture );
		}
	}
}
void yb_MainUIControl::myBag_setIsIconUsable(int nOrdinal, bool bFlag)	
{
	if((m_pGameMyBag)&&(nOrdinal >= 0)&&(nOrdinal < 25))
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
		{
			pSlot->Set_ItemImpossibility( !bFlag );
		}
	}
}
void yb_MainUIControl::myBag_showButtonAll(int nOrdinal, bool bFlag)	
{
	if((m_pGameMyBag)&&(nOrdinal >= 0)&&(nOrdinal < 25))	
	{
		m_pGameMyBag->setMyBag1_IsPCBANG(ID_MYBAG_SLOT_002 + nOrdinal, bFlag);
	}
}

void yb_MainUIControl::myBag_setIsUsing(int nOrdinal, bool bFlag)	
{
	if((m_pGameMyBag)&&(nOrdinal >= 0)&&(nOrdinal < 25))
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
		{
			pSlot->Set_ItemUse( bFlag );
		}
	}
}

void yb_MainUIControl::myBag_setGoldText(const CStringW& strIn )						// 골드 표시
{
	if( m_pGameMyBag )
	{
		m_pGameMyBag->setTextButton_Text( ID_MYBAG_RADIOBUTTON_GOLD2, strIn);
	}
}
bool yb_MainUIControl::myBag_GetMouseMove()
{
	if( m_pGameMyBag )
	{
		if(  m_pGameMyBag->getVisible() )
		{		
			return *(m_pGameMyBag->GetMyBag());
		}
	}

	return false;
}
BOOL yb_MainUIControl::myBag_GetIconMove(const int& nOrdingl)											// 아이콘이 움직이고있는가?
{	
	if( m_pGameMyBag )
	{
		ANW::StatusUI_FileIcon_Slot* pControl = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002+nOrdingl);
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName() )
		{			
			return pControl->Get_IconMove();
		}		
	}
	return false;
}
void yb_MainUIControl::myBag_Show_ReceiverSlot( const bool& bFlag )					// 소모성아이템 활성 비활성
{
	if( m_pGameMyBag )
	{
		// 백그라운드
		m_pGameMyBag->setControlVisibility( ID_MYBAG_RECEIVER_BACKGROUND2, bFlag );

		// 슬롯
		for( int i = ID_MYBAG_RECEIVER_SLOT002; i <= ID_MYBAG_RECEIVER_SLOT032; ++i )
		{
			m_pGameMyBag->setControlVisibility( i, bFlag );
		}		
	}
}
void yb_MainUIControl::myBag_Set_ReeciverFileName( const int& nOrdinal, const CStringW& strFileName )	// 슬롯에 아이콘 채우기
{
	if( m_pGameMyBag )
	{
		ANW::StatusUI_FileIcon_SlotReceiver* pControl = (ANW::StatusUI_FileIcon_SlotReceiver*)m_pGameMyBag->findControlPointer( ID_MYBAG_RECEIVER_SLOT002 +nOrdinal );
		if( pControl && pControl->getRTTI()->getName() == ANW::StatusUI_FileIcon_SlotReceiver::RTTI.getName() )
		{
			pControl->getFileIcon()->setTexture( strFileName );
		}
	}
}


void yb_MainUIControl::myBag_setSelectedGroup(unsigned int uSel)
{
	if(m_pGameMyBag == 0)	return;

	int nInput = -1;
	switch(uSel)
	{
	case 0: nInput = ID_MYBAG_RADIOBUTTON_EQUIPMENT2; break;
	case 1: nInput = ID_MYBAG_RADIOBUTTON_CONSUMPTION2; break;		
	case 2: nInput = ID_MYBAG_RADIOBUTTON_STUFF12; break;
	case 3: nInput = ID_MYBAG_RADIOBUTTON_STUFF22; break;	
	default: break;
	}
	m_pGameMyBag->clearRadio(ID_MYBAG_RADIOBUTTON_GROUP2, nInput);
}
int yb_MainUIControl::myBag_GetSelectedGroup()
{
	/*
	if(m_pGameMyBag)
	{
	int nID = m_pShop1->getSelectedRadio(ID_MYBAG_RADIOBUTTON_GROUP2);
	int nRet = -1;
	switch(nID)
	{
	case ID_MYBAG_RADIOBUTTON_EQUIPMENT2:		nRet = 0;	break;
	case ID_MYBAG_RADIOBUTTON_CONSUMPTION2:		nRet = 1;	break;
	case ID_MYBAG_RADIOBUTTON_STUFF12:			nRet = 2;	break;
	case ID_MYBAG_RADIOBUTTON_STUFF22:			nRet = 3;	break;
	default: break;
	}
	return nRet;
	}*/
	return -1;
}
void yb_MainUIControl::myBag_SlotSetting( const int& nOrdinal )
{
	if( m_pGameMyBag )
	{
		int nID = -1;
		switch( nOrdinal )
		{
		case 0: nID = ID_MYBAG_RADIOBUTTON_EQUIPMENT2;		break;	// 장비
		case 1: nID = ID_MYBAG_RADIOBUTTON_CONSUMPTION2;		break;	// 소모
		case 2: nID = ID_MYBAG_RADIOBUTTON_STUFF12;			break;	// 재료1
		case 3: nID = ID_MYBAG_RADIOBUTTON_STUFF22;			break;	// 재료2
		default: break;
		}

		m_pGameMyBag->clearRadio( ID_MYBAG_RADIOBUTTON_GROUP2, nID );
	}
}
VOID yb_MainUIControl::myBag_SetItemClick( int nOrdinal, bool bFlag )					// 아이템 클릭
{
	if(( m_pGameMyBag )&&(nOrdinal >= 0)&&(nOrdinal < 25))
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
		{
			pSlot->Set_ItemClick( bFlag );
		}
	}
}

VOID yb_MainUIControl::myBag_ShowItemCount( const INT& nOrdinal, const BOOL& bFlag )						// 아이템 갯수 활성 비활성
{
	if(m_pGameMyBag)
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = 0;
		if( nOrdinal == -1 )
		{			
			for( int i = ID_MYBAG_SLOT_002; i <= ID_MYBAG_SLOT_242; ++i )
			{
				pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer( i );
				if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
				{
					pSlot->Show_ItemCount( false );
				}
			}
		}
		else
		{
			pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
			if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
			{
				pSlot->Show_ItemCount( bFlag );
			}
		}

	}
}
VOID yb_MainUIControl::myBag_SetItemCount( const INT& nOrdinal, const INT& nCount )	// 아이템 갯수 카운트
{
	if((m_pGameMyBag)&&(nOrdinal >= 0)&&(nOrdinal < 25))
	{
		ANW::StatusUI_FileIcon_Slot* pSlot = (ANW::StatusUI_FileIcon_Slot*)m_pGameMyBag->findControlPointer(ID_MYBAG_SLOT_002 + nOrdinal);
		if((pSlot)&&(pSlot->getRTTI()->getName() == ANW::StatusUI_FileIcon_Slot::RTTI.getName()))
		{
			pSlot->Set_ItemCount( nCount );
		}
	}
}

//=================================================================================================================
//=================================================================================================================
// callback
void CALLBACK OnGUIEvent_MainUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext)
{
	if(pControl)
	{
		ANW::StatusUI_Shared_SkillIcon* pSkill_Icon;
		ANW::StatusUI_IMEEditBox_Target* pIMEBoxT;
		//		ANW::StatusUI_Button_NState* pButton_Nstate;
		switch(nEvent)
		{
			// 대쉬보드 셋(A, B, C, D) 변경
		case ANW::SET_BUTTON_NSTATE_CLICKED:
			if(g_pMainControl)
			{
				unsigned int uDashBoardIndex = g_pMainControl->getDashBoardIndex();
				uDashBoardIndex++;
				if(uDashBoardIndex > 3)
				{
					uDashBoardIndex = 0;
				}
				g_pMainControl->setDashBoardIndex(uDashBoardIndex);
			}
			break;

			// 스킬아이콘 클릭
		case ANW::SET_SHAREDSKILLICON_CLICKED:
			if(pControl->getRTTI()->getName() == ANW::StatusUI_Shared_SkillIcon::RTTI.getName())
			{
				pSkill_Icon = (ANW::StatusUI_Shared_SkillIcon*)pControl;
				int nSkill_ID = pSkill_Icon->getRectID() - ID_SKILLICON_START;
			}
			break;

		case ANW::SET_BUTTON_CLICKED:
			if(g_pMainControl)
			{
				if(nControlID == ID_MAINGAME_MESSAGEBOX_01_UP)
				{
					g_pMainControl->scrollMessageBox(-1);
					//					g_pMainControl->setResultWin(true);
				}
				if(nControlID == ID_MAINGAME_MESSAGEBOX_01_DN)
				{
					g_pMainControl->scrollMessageBox(1);
					//					g_pMainControl->setResultWin(false);
				}
				if(nControlID == ID_MAINGAME_MESSAGEBOX_01_END)
				{
					g_pMainControl->scrollEnd();
				}
			}
			break;

		case ANW::SET_IMEEDITBOX_TARGET_STRING:
			if(g_pMainControl)
			{
				pIMEBoxT = (ANW::StatusUI_IMEEditBox_Target*)pControl;
				if(pIMEBoxT->getRTTI()->getName() == ANW::StatusUI_IMEEditBox_Target::RTTI.getName())
				{
					g_pMainControl->addMessage(pIMEBoxT->GetText(), D3DCOLOR_ARGB(255, 255, 255, 255), D3DCOLOR_ARGB(255, 255, 0, 0), 0);
					pIMEBoxT->ClearText();
					g_pMainControl->focusChat(false);
				}
			}
			break;

		default:
			break;
		}		
	}
}
// callback
//=================================================================================================================
//=================================================================================================================