/*
file : ID_Lobby.h
*/

#ifndef _YB_LOBBY_ID_H_
#define _YB_LOBBY_ID_H_

#pragma warning(disable:4311)
#pragma warning(disable:4312)

//#include "../StateMng/ID_Notice_Mng.h"

#define MAX_SHOP_ITEM_LIST_COUNT 12
typedef enum YB_LOBBY_ID {

	//======================================================================================================================//
	// 캐릭터 선택 - 시작
	//======================================================================================================================//		
	ID_LOBBY_SELECT_BACKGROUND				= 100,				// 배경이미지


	ID_SELECT_CHARACTER_TYPE_CW,								// 청운 2D일러스트
	ID_SELECT_CHARACTER_TYPE_GR,								// 가령 2D일러스트
	ID_SELECT_CHARACTER_TYPE_PR,								// 패륵 2D일러스트
	ID_SELECT_CHARACTER_TYPE_SW,								// 소운 2D일러스트


	ID_SELECT_CHARACTER_BACK,									// 발판
		
	ID_LOBBY_RUN_CHAR,											// 실행
	ID_LOBBY_DEL_CHAR,											// 삭제
	ID_SELECT_CREATE,											// 생성
	ID_SELECT_BACK,												// 뒤로가기
	ID_LOBBY_GAME_EXIT,											// 나가기
	ID_SELECT_TURN_DM,												// 캐릭회전선택
	ID_SELECT_TURN_ZL,												// 캐릭회전선택
	ID_SELECT_TURN_ST,												// 캐릭회전선택
	ID_SELECT_TURN_MT,												// 캐릭회전선택
	ID_SELECT_TURN_NON,												// 캐릭회전선택

	ID_SELECT_TURN_LEFT_DM,												// 캐릭회전선택
	ID_SELECT_TURN_LEFT_ZL,												// 캐릭회전선택
	ID_SELECT_TURN_LEFT_ST,												// 캐릭회전선택
	ID_SELECT_TURN_LEFT_MT,												// 캐릭회전선택
	ID_SELECT_TURN_LEFT_NON,

	ID_SELECT_TURN_RIGHT_DM,												// 캐릭회전선택
	ID_SELECT_TURN_RIGHT_ZL,												// 캐릭회전선택
	ID_SELECT_TURN_RIGHT_ST,												// 캐릭회전선택
	ID_SELECT_TURN_RIGHT_MT,												// 캐릭회전선택
	ID_SELECT_TURN_RIGHT_NON,												// 캐릭회전선택

	ID_LOBBY_INFORMATION_FILD,								// 정보 백그라운드
	ID_LOBBY_INFORMATION_BACKGROUND,						// 정보 백그라운드
	ID_LOBBY_INFORMATION_TEXTURE,							// 캐릭터정보 텍스쳐 백그라운드

	ID_LOBBY_EXP_LEVEL,										// LV
	ID_LOBBY_EXP_NAME,										// 이름
	
	ID_LOBBY_INFORMATION_WORK,								// 직업
	ID_LOBBY_INFORMATION_GUILD,								// 길드
	ID_LOBBY_INFORMATION_CLASS,								// 등급	
	ID_LOBBY_INFORMATION_TOTAL_RESULT,						// 전체전적
	ID_LOBBY_INFORMATION_TODAY_RESULT,						// 금일전적		
	ID_LOBBY_INFORMATION_TOTAL_PERCENT,						// 금일승률
	ID_LOBBY_INFORMATION_TODAY_PERCENT,						// 전체승률

	ID_SELECT_CHARACTER_NON,								// 캐릭이 읍따

	
	//======================================================================================================================//
	// 캐릭터 선택 - 끝
	//======================================================================================================================//	


	//======================================================================================================================//
	// 캐릭터 생성창 - 시작
	//======================================================================================================================//	
	//일러스트
	ID_LOBBY_CREATECHAR_CHARACTER_CW = 200,				// 청운일러스트
	ID_LOBBY_CREATECHAR_CHARACTER_GR,					// 가령
	ID_LOBBY_CREATECHAR_CHARACTER_PR,
	ID_LOBBY_CREATECHAR_CHARACTER_SW,					// 소운
		

	ID_LOBBY_CREATECHAR_IllUSTCANCLE,					// 취소버튼


	// 생성
	ID_LOBBY_CREATECHAR_BACKGROUND,						// 백그라운드 전체
	ID_CREATECHAR_CHAR_BACK_CW,							// 3D뒤에 그려지는 2D일러스트
	ID_CREATECHAR_CHAR_BACK_GR,							// 3D뒤에 그려지는 2D일러스트
	ID_CREATECHAR_CHAR_BACK_PR,							// 3D뒤에 그려지는 2D일러스트
	ID_CREATECHAR_CHAR_BACK_SW,							// 3D뒤에 그려지는 2D일러스트

	ID_CREATECHAR_BACK,									// 발판

	ID_LOBBY_CREATECHAR_ROTATIONLEFT,					// 회전 왼쪽
	ID_LOBBY_CREATECHAR_ROTATIONRIGHT,					// 회전 오름쪽
	

	ID_CREATECHAR_FILE,									// 이름 얼굴 머리모야 머리색 필드
	ID_CREATECHAR_NAME_BACKGROUND,						// 이름 백그라운드
	ID_CREATECHAR_NAME_FILD,							// 이름입력필드
	ID_LOBBY_CREATECHAR_INPUTID,						// 이름입력

	
	ID_CREATECHAR_FACE_BACKGROUND,						// 얼굴 텍스쳐 
	ID_CREATECHAR_HEAD_BACKGROUND,						// 머리모양 텍스쳐 
	ID_CREATECHAR_COLOR_BACKGROUND,						// 머리색 텍스쳐 

	ID_CREATECHAR_FILE2,								// 사용무기, 캐릭터 특징 필드
	ID_CREATECHAR_ATTACK_BACKGROUND,						// 사용무기 텍스쳐
	ID_CREATECHAR_CHARDESC_BACKGROUND,						// 캐릭터 특징


	//////////////////////////////////////////////////////////////////////////
	// 얼굴
	ID_CREATECHAR_FACE_CW_GROUP,
	ID_CREATECHAR_FACE_GR_GROUP,
	ID_CREATECHAR_FACE_PR_GROUP,
	ID_CREATECHAR_FACE_SW_GROUP,
	// 청운
	ID_LOBBY_CREATECHAR_FACE_C0,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_C1,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_C2,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_C3,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_C4,						// 얼굴Image

	//채가령
	ID_LOBBY_CREATECHAR_FACE_G0,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_G1,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_G2,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_G3,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_G4,						// 얼굴Image

	// 패륵
	ID_LOBBY_CREATECHAR_FACE_P0,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_P1,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_P2,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_P3,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_P4,						// 얼굴Image

	//비소운
	ID_LOBBY_CREATECHAR_FACE_S0,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_S1,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_S2,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_S3,						// 얼굴Image
	ID_LOBBY_CREATECHAR_FACE_S4,						// 얼굴Image


	//////////////////////////////////////////////////////////////////////////
	// 머리
	ID_CREATECHAR_HEAD_CW_GROUP,
	ID_CREATECHAR_HEAD_GR_GROUP,
	ID_CREATECHAR_HEAD_PR_GROUP,
	ID_CREATECHAR_HEAD_SW_GROUP,
	// 청운
	ID_LOBBY_CREATECHAR_HEAD_C0,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_C1,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_C2,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_C3,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_C4,						// 머리Image

	// 채가령
	ID_LOBBY_CREATECHAR_HEAD_G0,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_G1,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_G2,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_G3,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_G4,						// 머리Image

	// 패륵
	ID_LOBBY_CREATECHAR_HEAD_P0,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_P1,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_P2,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_P3,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_P4,						// 머리Image
	//비소운
	ID_LOBBY_CREATECHAR_HEAD_S0,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_S1,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_S2,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_S3,						// 머리Image
	ID_LOBBY_CREATECHAR_HEAD_S4,						// 머리Image

	
	ID_LOBBY_CREATECHAR_HEADCOLOR_GROUP,
	ID_LOBBY_CREATECHAR_HEADCOLOR_00,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_01,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_02,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_03,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_04,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_05,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_06,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_07,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_08,						// 머리색
	ID_LOBBY_CREATECHAR_HEADCOLOR_09,						// 머리색

	ID_LOBBY_CREATE_BACKGROUND1,							// 배경이미지
	ID_LOBBY_CREATE_BACKGROUND2,							// 배경이미지

	// 사용무기
	ID_LOBBY_CREATECHAR_CW,
	ID_LOBBY_CREATECHAR_GR,
	ID_LOBBY_CREATECHAR_PR,
	ID_LOBBY_CREATECHAR_SW,

	ID_LOBBY_CREATECHAR_CHARDESC,							// 설명 캐릭

	ID_LOBBY_CREATECHAR_CONFIRM,						// 확인
	ID_LOBBY_CREATECHAR_CANCEL,							// 취소

	ID_LOBBY_CREATECHAR_NEXTCLASS,
	ID_LOBBY_CREATECHAR_PREVCLASS,

	ID_LOBBY_CREATECHAR_CHECKNAME,

	ID_CREATECHAR_CLASS_DM,
	ID_CREATECHAR_CLASS_ZL,
	ID_CREATECHAR_CLASS_ST,
	ID_CREATECHAR_CLASS_DL,
	
	ID_CREATECHAR_TYPE_NORMAL,
	ID_CREATECHAR_TYPE_ATTACK,
	ID_CREATECHAR_TYPE_DEFANCE,
	ID_CREATECHAR_TYPE_MAX,

	//////////////////////////////////////////////////////////////////////////
	/* 서버선택 POP창 생성 이넘값 */
	ID_LOBBY_SELECT_SERVER_POP_BG,
	ID_LOBBY_SELECT_SERVER_POP_BTN,
	ID_LOBBY_SELECT_SERVER_POP_BTN_CLOSED,
	ID_LOBBY_SELECT_SERVER_POP_PAGE_LEFT,
	ID_LOBBY_SELECT_SERVER_POP_PAGE_RIGHT,
	ID_LOBBY_SELECT_SERVER_POP_NEW_BTN,
	ID_LOBBY_SELECT_SERVER_POP_START_BTN,
	ID_LOBBY_SELECT_SERVER_POP_BTN_GROUP,
	ID_LOBBY_SELECT_SERVER_POP_BTN1,
	ID_LOBBY_SELECT_SERVER_POP_BTN2,
	ID_LOBBY_SELECT_SERVER_POP_BTN3,
	ID_LOBBY_SELECT_SERVER_POP_BTN4,
	ID_LOBBY_SELECT_SERVER_POP_BTN5,
	ID_LOBBY_SELECT_SERVER_POP_BTN6,
	ID_LOBBY_SELECT_SERVER_POP_BTN7,
	ID_LOBBY_SELECT_SERVER_POP_BTN8,
	ID_LOBBY_SELECT_SERVER_POP_BTN9,
	ID_LOBBY_SELECT_SERVER_POP_BTN10,
	ID_LOBBY_SELECT_SERVER_POP_NUM1,
	ID_LOBBY_SELECT_SERVER_POP_NUM2,
	ID_LOBBY_SELECT_SERVER_POP_NUM3,
	ID_LOBBY_SELECT_SERVER_POP_NUM4,
	ID_LOBBY_SELECT_SERVER_POP_NUM5,
	ID_LOBBY_SELECT_SERVER_POP_NUM6,
	ID_LOBBY_SELECT_SERVER_POP_NUM7,
	ID_LOBBY_SELECT_SERVER_POP_NUM8,
	ID_LOBBY_SELECT_SERVER_POP_NUM9,
	ID_LOBBY_SELECT_SERVER_POP_NUM10,
	ID_LOBBY_SELECT_SERVER_POP_BAR1_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR2_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR3_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR4_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR5_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR6_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR7_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR8_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR9_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR10_BG,
	ID_LOBBY_SELECT_SERVER_POP_BAR1,
	ID_LOBBY_SELECT_SERVER_POP_BAR2,
	ID_LOBBY_SELECT_SERVER_POP_BAR3,
	ID_LOBBY_SELECT_SERVER_POP_BAR4,
	ID_LOBBY_SELECT_SERVER_POP_BAR5,
	ID_LOBBY_SELECT_SERVER_POP_BAR6,
	ID_LOBBY_SELECT_SERVER_POP_BAR7,
	ID_LOBBY_SELECT_SERVER_POP_BAR8,
	ID_LOBBY_SELECT_SERVER_POP_BAR9,
	ID_LOBBY_SELECT_SERVER_POP_BAR10,
	ID_LOBBY_SELECT_SERVER_POP_INFO1,
	ID_LOBBY_SELECT_SERVER_POP_INFO2,
	ID_LOBBY_SELECT_SERVER_POP_INFO3,
	ID_LOBBY_SELECT_SERVER_POP_INFO4,
	ID_LOBBY_SELECT_SERVER_POP_INFO5,
	ID_LOBBY_SELECT_SERVER_POP_INFO6,
	ID_LOBBY_SELECT_SERVER_POP_INFO7,
	ID_LOBBY_SELECT_SERVER_POP_INFO8,
	ID_LOBBY_SELECT_SERVER_POP_INFO9,
	ID_LOBBY_SELECT_SERVER_POP_INFO10,
	//======================================================================================================================//
	// 캐릭터 생성창 - 끝
	//======================================================================================================================//	



	//======================================================================================================================//
	// 서버 선택창 - 시작
	//======================================================================================================================//	
	ID_SERVER_SELECT_BG						= 400,
	ID_SERVER_SELECT_TITLE,
	ID_SERVER_SELECT_BG2,
	ID_SERVER_SELECT_BTN_BG,
	ID_SERVER_SELECT_BTN_ALL,
	ID_SERVER_SELECT_BTN1,
	ID_SERVER_SELECT_BTN2,
	ID_SERVER_SELECT_BTN3,
	ID_SERVER_SELECT_BTN4,
	ID_SERVER_SELECT_BTN5,

	ID_SERVER_SELECT_CHANNEL_BTN1,
	ID_SERVER_SELECT_CHANNEL_BTN2,
	ID_SERVER_SELECT_CHANNEL_BTN3,
	ID_SERVER_SELECT_CHANNEL_BTN4,
	ID_SERVER_SELECT_CHANNEL_BTN5,
	ID_SERVER_SELECT_CHANNEL_BTN6,
	ID_SERVER_SELECT_CHANNEL_BTN7,
	ID_SERVER_SELECT_CHANNEL_BTN8,
	ID_SERVER_SELECT_CHANNEL_BTN9,
	ID_SERVER_SELECT_CHANNEL_BTN10,


	ID_SERVER_SELECT_CHANNEL_STATE1,
	ID_SERVER_SELECT_CHANNEL_STATE2,
	ID_SERVER_SELECT_CHANNEL_STATE3,
	ID_SERVER_SELECT_CHANNEL_STATE4,
	ID_SERVER_SELECT_CHANNEL_STATE5,
	ID_SERVER_SELECT_CHANNEL_STATE6,
	ID_SERVER_SELECT_CHANNEL_STATE7,
	ID_SERVER_SELECT_CHANNEL_STATE8,
	ID_SERVER_SELECT_CHANNEL_STATE9,
	ID_SERVER_SELECT_CHANNEL_STATE10,

	ID_SERVER_SELECT_CHANNEL2_STATE1,
	ID_SERVER_SELECT_CHANNEL2_STATE2,
	ID_SERVER_SELECT_CHANNEL2_STATE3,
	ID_SERVER_SELECT_CHANNEL2_STATE4,
	ID_SERVER_SELECT_CHANNEL2_STATE5,
	ID_SERVER_SELECT_CHANNEL2_STATE6,
	ID_SERVER_SELECT_CHANNEL2_STATE7,
	ID_SERVER_SELECT_CHANNEL2_STATE8,
	ID_SERVER_SELECT_CHANNEL2_STATE9,
	ID_SERVER_SELECT_CHANNEL2_STATE10,

	ID_SERVER_SELECT_CHANNEL3_STATE1,
	ID_SERVER_SELECT_CHANNEL3_STATE2,
	ID_SERVER_SELECT_CHANNEL3_STATE3,
	ID_SERVER_SELECT_CHANNEL3_STATE4,
	ID_SERVER_SELECT_CHANNEL3_STATE5,
	ID_SERVER_SELECT_CHANNEL3_STATE6,
	ID_SERVER_SELECT_CHANNEL3_STATE7,
	ID_SERVER_SELECT_CHANNEL3_STATE8,
	ID_SERVER_SELECT_CHANNEL3_STATE9,
	ID_SERVER_SELECT_CHANNEL3_STATE10,	
	ID_SERVER_SELECT_END_BTN,
	//======================================================================================================================//
	// 서버 선택창 - 끝
	//======================================================================================================================//	


	//======================================================================================================================//
	// 로비 백그라운드 - 시작
	//======================================================================================================================//	
	// 미니맵
	ID_BACK_MINIMAP						= 6000,		// 미니맵
	ID_BACK_MINIMAP_NAME,							// 이름
	ID_BACK_MINIMAP_PLUS,							// 플러스버튼
	ID_BACK_MINIMAP_CLOSE,							// 종료버튼
	ID_BACK_MINIMAPE_BACKGROUND_S,

	ID_BACK_MINIMAP_TIME_BACKGROUND1,				// 시계 빽판
	ID_BACK_MINIMAP_TIME_BACKGROUND2,				// 시계 모래시계
	ID_BACK_MINIMAP_TIME,							// 시계
	
	// 에너지
	ID_BACK_MYENERGY_BACKGROUND,					// MY 에너지 백그라운드
	ID_BACK_MYENERGY_FACE,							// 얼굴
	ID_BACK_MYENERGY_LV,							// 레벨
	ID_BACK_MYENERGY_NAME,							// 이름
	ID_BACK_MYENERGY_ENERGY,						// 에너지바
	ID_BACK_MYENERGY_STAMINA,						// 스테미나
	ID_REAL_ENERGY_MY_1,							// 상단
	ID_REAL_ENERGY_MY_1_S,							// 스테미너
	ID_REAL_ENERGY_MY_1_ALPHA,						// 상단
	ID_REAL_ENERGY_MY_1_ALPHA_S,					// 스테미너

	// 타겟
	ID_BACK_TAGET_BACKGROUND1,						// 백그라운드	
	ID_BACK_TAGET_LV,								// 레벨
	ID_BACK_TAGET_NAEM,								// 이름
	
	// 보스
	ID_BACK_TAGET_BACKGROUND_BOSS,						// 에너지 바
	ID_BACK_TAGET_ENERGY_BOSS,							// 에너지	
	ID_REAL_ENERGY_TAGET_BOSS,							// 실시간
	ID_REAL_ENERGY_TAGET_AlPHA_BOSS,					// 알파

	// 정예
	ID_BACK_TAGET_BACKGROUND_ELITE,						// 에너지 바
	ID_BACK_TAGET_ENERGY_ELITE,							// 에너지	
	ID_REAL_ENERGY_TAGET_ELITE,							// 실시간
	ID_REAL_ENERGY_TAGET_AlPHA_ELITE,					// 알파

	// 일반
	ID_BACK_TAGET_BACKGROUND_GENERAL,						// 에너지 바
	ID_BACK_TAGET_ENERGY_GENERAL,							// 에너지	
	ID_REAL_ENERGY_TAGET_GENERAL,							// 실시간
	ID_REAL_ENERGY_TAGET_AlPHA_GENERAL,					// 알파

	ID_BACK_TAGET_BACKGROUND_MENTAL,						// 에너지 바
	ID_BACK_TAGET_ENERGY_MENTAL,							// 에너지	
	ID_REAL_ENERGY_TAGET_MENTAL,							// 실시간
	ID_REAL_ENERGY_TAGET_AlPHA_MENTAL,					// 알파

	ID_BACK_TAGET_BACKGROUND_NPC,							// NPC Player

	// 파티
	ID_BACK_PARTY_BACKGROUND1,						// 백그라운드
	ID_BACK_PARTY_FACE1,							// 얼굴
	ID_BACK_PARTY_LV1,								// 레벨
	ID_BACK_PARTY_NAME1,							// 이름
	ID_BACK_PARTY_ENERGY1,							// 에너지
	ID_BACK_PARTY_STAMINA1,							// 스테미너

	ID_BACK_PARTY_BACKGROUND2,						// 백그라운드
	ID_BACK_PARTY_FACE2,							// 얼굴
	ID_BACK_PARTY_LV2,								// 레벨
	ID_BACK_PARTY_NAME2,							// 이름
	ID_BACK_PARTY_ENERGY2,							// 에너지
	ID_BACK_PARTY_STAMINA2,							// 스테미너

	ID_BACK_PARTY_BACKGROUND3,						// 백그라운드	
	ID_BACK_PARTY_FACE3,							// 얼굴	
	ID_BACK_PARTY_LV3,								// 레벨	
	ID_BACK_PARTY_NAME3,							// 이름	
	ID_BACK_PARTY_ENERGY3,							// 에너지
	ID_BACK_PARTY_STAMINA3,							// 스테미너

	ID_BACK_PARTY_BACKGROUND4,						// 백그라운드
	ID_BACK_PARTY_FACE4,							// 얼굴
	ID_BACK_PARTY_LV4,								// 레벨
	ID_BACK_PARTY_NAME4,							// 이름
	ID_BACK_PARTY_ENERGY4,							// 에너지
	ID_BACK_PARTY_STAMINA4,							// 스테미너

	// 실시간 에너지
	ID_REAL_ENERGY_PARTY_1,							// 파티
	ID_REAL_ENERGY_PARTY_2,
	ID_REAL_ENERGY_PARTY_3,	
	ID_REAL_ENERGY_PARTY_1_S,						// 파티 스테미너
	ID_REAL_ENERGY_PARTY_2_S,
	ID_REAL_ENERGY_PARTY_3_S,

	ID_REAL_ENERGY_PARTY_1_ALPHA,					// 파티
	ID_REAL_ENERGY_PARTY_2_ALPHA,
	ID_REAL_ENERGY_PARTY_3_ALPHA,	
	ID_REAL_ENERGY_PARTY_1_ALPHA_S,					// 파티 스테미너
	ID_REAL_ENERGY_PARTY_2_ALPHA_S,
	ID_REAL_ENERGY_PARTY_3_ALPHA_S,


	ID_BACK_CHATTING_MENU_BG,						// 백그라운드 ( 일반,외침,전체,길드,귓속말,NPC,시스템 )
	ID_BACK_CHATTING_MENU_COMMON,					// 일반
	ID_BACK_CHATTING_MENU_SCREAM,					// 외침
	ID_BACK_CHATTING_MENU_TOTALY,					// 전체
	ID_BACK_CHATTING_MENU_GUILD,					// 길드
	ID_BACK_CHATTING_MENU_WHISPER,					// 귓속말	
	ID_BACK_CHATTING_MENU_SYSTEM,					// 시스템
	ID_BACK_CHATTING_MENU_NPC,						// npc

	ID_BACK_CHATTING_LIST_BG,						// 채팅 리스트 백그라운드
	ID_BACK_CHATTING_INPUT_BG,						// 채팅 입력 백그라운드
	ID_BACK_CHATTING_INPUT,							// 채팅 입력
	ID_BACK_CHATTING_LIST,							// 채팅 리스트

	ID_BACK_CHATTING_BUTTON_TYPE,					// 대화 타입

	ID_BACK_CHATTING_BUTTON_TYPECHICE0,				// 일반
	ID_BACK_CHATTING_BUTTON_TYPECHICE1,				// 외침
	ID_BACK_CHATTING_BUTTON_TYPECHICE2,				// 전체
	ID_BACK_CHATTING_BUTTON_TYPECHICE3,				// 길드
	ID_BACK_CHATTING_BUTTON_TYPECHICE4,				// 귓말

	ID_BACK_CHATTING_BUTTON_EMOTION,
	ID_BACK_CHATTING_BUTTON_HIDE,

	ID_BACK_CHATTING_BUTTON_NORMAL_MODE,
	ID_BACK_CHATTING_BUTTON_SYSTEM_MODE,
	ID_BACK_CHATTING_MODE_GROUP,
		
	ID_BACK_BACKGROUND1,							// 가운데 표시(경험치)
	ID_BACK_EXP,									// 경험치
	ID_BACK_BACKGROUND2,							// 경험치 백그라운드
	
	ID_BACK_CHANNEL,								// 채널표시

	ID_BACK_ENERGY,									// 에너지
	ID_BACK_STAMINA,								// 스테미너	
	ID_REAL_ENERGY_MY_2,							// 하단
	ID_REAL_ENERGY_MY_2_S,							// 스테미너
	ID_REAL_ENERGY_MY_2_ALPHA,						// 하단
	ID_REAL_ENERGY_MY_2_ALPHA_S,					// 스테미너	

	ID_SKILLICON_BACKGROUND,


	ID_SKILLICON_MAINGAME_POS01,					//스킬
	ID_SKILLICON_MAINGAME_POS02,
	ID_SKILLICON_MAINGAME_POS03,
	ID_SKILLICON_MAINGAME_POS04,
	ID_SKILLICON_MAINGAME_POS05,
	ID_SKILLICON_MAINGAME_POS06,
	ID_SKILLICON_MAINGAME_POS07,
	ID_SKILLICON_MAINGAME_POS08,
	ID_SKILLICON_MAINGAME_POS09,
	ID_SKILLICON_MAINGAME_POS10,

	ID_SKILLICON_MAINGAME_POS11,
	ID_SKILLICON_MAINGAME_POS12,
	ID_SKILLICON_MAINGAME_POS13,
	ID_SKILLICON_MAINGAME_POS14,
	ID_SKILLICON_MAINGAME_POS15,
	ID_SKILLICON_MAINGAME_POS16,
	ID_SKILLICON_MAINGAME_POS17,
	ID_SKILLICON_MAINGAME_POS18,
	ID_SKILLICON_MAINGAME_POS19,
	ID_SKILLICON_MAINGAME_POS20,


	ID_SKILLICON_MAINGAME_POSA,						// 팀전스킬
	ID_SKILLICON_MAINGAME_POSB,
	ID_SKILLICON_MAINGAME_POSC,
	ID_SKILLICON_MAINGAME_POSD,
	ID_SKILLICON_MAINGAME_POSE,
	ID_SKILLICON_MAINGAME_POSF,
	ID_SKILLICON_MAINGAME_POSG,
	ID_SKILLICON_MAINGAME_POSH,
	ID_SKILLICON_MAINGAME_POSI,
	ID_SKILLICON_MAINGAME_POSJ,
	ID_SKILLICON_MAINGAME_PAGEUP,
	ID_SKILLICON_MAINGAME_PAGEDOWN,
	ID_SKILLICON_MAINGAME_PAGENUM,

	

	// 펫 에너지
	ID_PAT_BACKGROUND,								// pat 백그라운드
	ID_PAT_ENERGY,									// 에너지

	// 버프
	ID_BUFF_CHAR00_00,								// 자기자신
	ID_BUFF_CHAR00_01,
	ID_BUFF_CHAR00_02,
	ID_BUFF_CHAR00_03,
	ID_BUFF_CHAR00_04,

	ID_BUFF_CHAR01_00,								// 파티원 1
	ID_BUFF_CHAR01_01,
	ID_BUFF_CHAR01_02,
	ID_BUFF_CHAR01_03,
	ID_BUFF_CHAR01_04,

	ID_BUFF_CHAR02_00,								// 파티원 2
	ID_BUFF_CHAR02_01,
	ID_BUFF_CHAR02_02,
	ID_BUFF_CHAR02_03,
	ID_BUFF_CHAR02_04,

	ID_BUFF_CHAR03_00,								// 파티원 3
	ID_BUFF_CHAR03_01,
	ID_BUFF_CHAR03_02,
	ID_BUFF_CHAR03_03,
	ID_BUFF_CHAR03_04,

	ID_BUFF_CHAR04_00,								// 타겟
	ID_BUFF_CHAR04_01,
	ID_BUFF_CHAR04_02,
	ID_BUFF_CHAR04_03,
	ID_BUFF_CHAR04_04,

	// 부활시간
	ID_CHAR0_REGENTIME,
	ID_CHAR1_REGENTIME,
	ID_CHAR2_REGENTIME,
	ID_CHAR3_REGENTIME,	

	// 퀘스트 알림
	ID_QUEST_INFOR_00,
	ID_QUEST_INFOR_01,
	ID_QUEST_INFOR_02,
	ID_QUEST_INFOR_03,
	ID_QUEST_INFOR_04,
	ID_QUEST_INFOR_05,
	ID_QUEST_INFOR_06,
	ID_QUEST_INFOR_07,
	ID_QUEST_INFOR_08,
	ID_QUEST_INFOR_09,
	
	// 방장표시
	ID_PARTY_MASTER_00,
	ID_PARTY_MASTER_01,
	ID_PARTY_MASTER_02,
	ID_PARTY_MASTER_03,
	ID_PARTY_MASTER_04,
	// 전장모드진입
	ID_MODE_BATTLE,

	// 알림메시지
	ID_MESSAGE_TEXT,

	// 메인메뉴
	ID_BACK_MAIN_MENU_INFORMATION,					// 캐릭정보
	ID_BACK_MAIN_MENU_SKILL_CONTROL,				// 무공창
	ID_BACK_MAIN_MENU_MYBAG,						// 내가방
	ID_BACK_MAIN_MENU_QUEST,						// 퀘스트
	ID_BACK_MAIN_MENU_PETSONSHOP,					// 개인상점
	ID_BACK_MAIN_MENU_FRIEND_CONTROL,				// 친구관리
	ID_BACK_MAIN_MENU_GUILD,						// 길드
	ID_BACK_MAIN_MENU_CHSHSHOP,						// 캐쉬상점	
	ID_BACK_MAIN_MENU_SYSTEM,						// 시스템
	ID_BACK_MAIN_MENU_HIDE,

	// 소환마
	ID_SUMMONS_BACKGROUND,
	ID_SUMMONS_LV,
	ID_SUMMONS_NAME,
	ID_SUMMONS_ENERGY,

	// 하이라이트
	ID_HILIGHT_CHAR_0,
	ID_HILIGHT_CHAR_1,
	ID_HILIGHT_CHAR_2,
	ID_HILIGHT_CHAR_3,

	BASERKER_BUTTON,
	BASERKER_BG,
	ID_BASERKER_PROGRESS,

	ID_FPS_MESSAGE,
	ID_MINI_QUEST_BG,
	ID_MINI_QUEST_BUTTON,


	// 월드맵
	ID_WORLDMAP_BACKGROUND = 697,							// 백그라운드	
	ID_WORLDMAP_NAEM = 698,									// 이름
	ID_WORLDMAP_CLOSE = 699,								// 닫기
	//======================================================================================================================//
	// 로비 백그라운드 - 끝
	//======================================================================================================================//	



	//======================================================================================================================//
	//내가방 - 시작
	//======================================================================================================================//	
	ID_MYBAG_BACKGROUND					= 700,		// 백그라운드

	ID_MYBAG_BACKGROUND_NAME,						// 이름
	ID_MYBAG_BACKGROUND_CLOSE,						// 닫기

	// 내가방 라디오버튼
	ID_MYBAG_RADIOBUTTON_GROUP,
	ID_MYBAG_RADIOBUTTON_PERSON,					// 장비
	ID_MYBAG_RADIOBUTTON_PERSONEX,				// 소모
	ID_MYBAG_RADIOBUTTON_QUEST,						// 퀘스트
	ID_MYBAG_RADIOBUTTON_STUFF,						// 재료
	ID_MYBAG_RADIOBUTTON_5,
	ID_MYBAG_RADIOBUTTON_6,

	ID_MYBAG_BG_GOLD,						// 금액 텍스트
	ID_MYBAG_G_GOLD,						// 금액 텍스트
	ID_MYBAG_Y_GOLD,						// 금액 텍스트
	ID_MYBAG_T_GOLD,						// 금액 텍스트

	// 내가방 슬롯
	ID_MYBAG_SLOT_00,
	ID_MYBAG_SLOT_01,
	ID_MYBAG_SLOT_02,
	ID_MYBAG_SLOT_03,
	ID_MYBAG_SLOT_04,
	ID_MYBAG_SLOT_05,
	ID_MYBAG_SLOT_06,
	ID_MYBAG_SLOT_07,
	ID_MYBAG_SLOT_08,
	ID_MYBAG_SLOT_09,
	ID_MYBAG_SLOT_10,
	ID_MYBAG_SLOT_11,
	ID_MYBAG_SLOT_12,
	ID_MYBAG_SLOT_13,
	ID_MYBAG_SLOT_14,
	ID_MYBAG_SLOT_15,
	ID_MYBAG_SLOT_16,
	ID_MYBAG_SLOT_17,
	ID_MYBAG_SLOT_18,
	ID_MYBAG_SLOT_19,
	ID_MYBAG_SLOT_20,
	ID_MYBAG_SLOT_21,
	ID_MYBAG_SLOT_22,
	ID_MYBAG_SLOT_23,
	ID_MYBAG_SLOT_24,
	ID_MYBAG_SLOT_25,
	ID_MYBAG_SLOT_26,
	ID_MYBAG_SLOT_27,
	ID_MYBAG_SLOT_28,
	ID_MYBAG_SLOT_29,
	ID_MYBAG_SLOT_30,
	ID_MYBAG_SLOT_31,
	ID_MYBAG_SLOT_32,
	ID_MYBAG_SLOT_33,
	ID_MYBAG_SLOT_34,
	ID_MYBAG_SLOT_35,
	ID_MYBAG_BACKGROUND_WIN,
	ID_MYBAG_BG_TOTAL,
	ID_MYBAG_BG_PS,
	ID_MYBAG_BG_REVISE,
	ID_MYBAG_MANAGER_ID,

	// 분할
	ID_MYBAG_CUT_BACKGROUND,
	ID_MYBAG_CUT_LEFT,
	ID_MYBAG_CUT_RIGHT,
	ID_MYBAG_CUT_TEXT,
	ID_MYBAG_CUT_OK,
	ID_MYBAG_CUT_CANCLE,

	ID_MYBAG_NAME_PERSON,
	ID_MYBAG_NAME_PERSONEX,
	ID_MYBAG_NAME_QUEST,

	//======================================================================================================================//
	//내가방 - 끝
	//======================================================================================================================//


	//======================================================================================================================//
	// 무공창 - 시작
	//======================================================================================================================//
	ID_SKILL_BACKGROUND				= 8000,	// 백그라운드
	ID_SKILL_BACKGROUND_WIN,					// MOVE
	ID_SKILL_BACKGROUND_FILD,					// 필드


	ID_SKILL_BACKGROUND_NAME,					// 이름
	ID_SKILL_BACKGROUND_CLOSE,					// 닫기
	ID_SKILL_BACKGROUND_CANCEL,


	// 상단탭
	ID_SKILL_TAB_GROUP,
	ID_SKILL_TAB_SKILL,							// 스킬
	ID_SKILL_TAB_CREATEITEM,					// 제조

	// 제조
	ID_SKILL_CREATEITEM_GROUP,
	ID_SKILL_CREATEITEM_EFFECT,					// 효과
	ID_SKILL_CREATEITEM_STUFF,					// 재료

	ID_SKILL_CREATEITEM_SHD,					// 방어구
	ID_SKILL_CREATEITEM_ACC,					// 장신구

	ID_SKILL_CREATEITEM_ATT,					// 무기
	ID_SKILL_CREATEITEM_PET,					// 탈것

	ID_SKILL_CREATEITEM_COMMON,					// 공통

	// 무공창 라디오버튼
	// 청운
	ID_SKILL_RADIOBUTTON_CW_GROUP,		
	ID_SKILL_RADIOBUTTON_CW_1,					// 전투
	ID_SKILL_RADIOBUTTON_CW_2,					// 돌격
	ID_SKILL_RADIOBUTTON_CW_3,					// 보호
	ID_SKILL_RADIOBUTTON_CW_4,
	ID_SKILL_RADIOBUTTON_CW_COMMON,				// 공통
	ID_SKILL_RADIOBUTTON_CW_SPECIAL1,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL2,
	ID_SKILL_RADIOBUTTON_CW_COMMON_TREE,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL_TREE1,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL_TREE2,
	ID_SKILL_RADIOBUTTON_CW_PET,				// 펫

	// 채가령
	ID_SKILL_RADIOBUTTON_GR_GROUP,		
	ID_SKILL_RADIOBUTTON_GR_1,					// 속사
	ID_SKILL_RADIOBUTTON_GR_2,					// 파괴
	ID_SKILL_RADIOBUTTON_GR_3,					// 타격
	ID_SKILL_RADIOBUTTON_GR_COMMON,				// 공통
	ID_SKILL_RADIOBUTTON_GR_PET,				// 펫

	// 패륵
	ID_SKILL_RADIOBUTTON_PR_GROUP,		
	ID_SKILL_RADIOBUTTON_PR_1,					// 질풍
	ID_SKILL_RADIOBUTTON_PR_2,					// 방어
	ID_SKILL_RADIOBUTTON_PR_3,					// 광폭
	ID_SKILL_RADIOBUTTON_PR_4,
	ID_SKILL_RADIOBUTTON_PR_COMMON,				// 공통
	ID_SKILL_RADIOBUTTON_PR_SPECIAL1,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL2,
	ID_SKILL_RADIOBUTTON_PR_COMMON_TREE,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL_TREE1,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL_TREE2,
	ID_SKILL_RADIOBUTTON_PR_PET,				// 펫

	// 비소운
	ID_SKILL_RADIOBUTTON_SW_GROUP,		
	ID_SKILL_RADIOBUTTON_SW_1,					// 암살
	ID_SKILL_RADIOBUTTON_SW_2,					// 쾌속
	ID_SKILL_RADIOBUTTON_SW_3,					// 투척
	ID_SKILL_RADIOBUTTON_SW_COMMON,				// 공통
	ID_SKILL_RADIOBUTTON_SW_PET,				// 펫

	ID_SKILL_BUTTON_PAGE_LEFT,					// 페이지 왼쪽
	ID_SKILL_BUTTON_PAGE_RIGHT,					// 페이지 오른쪽
	ID_SKILL_BUTTON_PAGE_TEXT,					// 페이지 TETX

	// 무공창 슬롯
	ID_SKILL_SLOT_00,
	ID_SKILL_SLOT_01,
	ID_SKILL_SLOT_02,
	ID_SKILL_SLOT_03,
	ID_SKILL_SLOT_04,	
	ID_SKILL_SLOT_05,
	ID_SKILL_SLOT_06,
	ID_SKILL_SLOT_07,
	ID_SKILL_SLOT_08,
	ID_SKILL_SLOT_09,	
	ID_SKILL_SLOT_10,
	ID_SKILL_SLOT_11,
	ID_SKILL_SLOT_12,
	ID_SKILL_SLOT_13,
	ID_SKILL_SLOT_14,	
	ID_SKILL_SLOT_15,
	ID_SKILL_SLOT_16,
	ID_SKILL_SLOT_17,
	ID_SKILL_SLOT_18,
	ID_SKILL_SLOT_19,
	ID_SKILL_SLOT_20,
	ID_SKILL_SLOT_21,
	ID_SKILL_SLOT_22,
	ID_SKILL_SLOT_23,
	ID_SKILL_SLOT_24,
	ID_SKILL_SLOT_25,
	ID_SKILL_SLOT_26,
	ID_SKILL_SLOT_27,
	ID_SKILL_SLOT_28,

	//제조
	ID_SKILL_CREATEITEM_BACKGROUND,			// 백그라운드
	ID_SKILL_CREATEITEM_LIST,				// 리스트
	ID_SKILL_CREATEITEM_ITEM,				// 아이템
	ID_SKILL_CREATEITEM_SKILL_BACKGROUND,	// 숙련도 백그라운드
	ID_SKILL_CREATEITEM_SKILL,				// 숙련도
	ID_SKILL_CREATEITEM_OK,					// 제조하기

	ID_SKILL_BG_TOTAL,
	ID_SKILL_MANAGER_ID,					// 고유아이디

	ID_SKILLFIRST_BACKGROUND_CLOSE,

	ID_SKILLFIRST_BACKGROUND_DM,
	ID_SKILLFIRST_BACKGROUND_LBUTTON_DM,
	ID_SKILLFIRST_BACKGROUND_RBUTTON_DM,

	ID_SKILLFIRST_BACKGROUND_PR,
	ID_SKILLFIRST_BACKGROUND_LBUTTON_PR,
	ID_SKILLFIRST_BACKGROUND_RBUTTON_PR,

	ID_SKILL_POINT,
	ID_SKILL_SCROLL,

	ID_SKILL_BUTTON_DM_TREE1COMBO1,
	ID_SKILL_BUTTON_DM_TREE1COMBO2,
	ID_SKILL_BUTTON_DM_TREE1COMBO3,
	ID_SKILL_BUTTON_DM_TREE1COMBO4,

	ID_SKILL_BUTTON_DM_TREE2COMBO1,
	ID_SKILL_BUTTON_DM_TREE2COMBO2,
	ID_SKILL_BUTTON_DM_TREE2COMBO3,
	ID_SKILL_BUTTON_DM_TREE2COMBO4,

	ID_SKILL_BUTTON_DL_TREE1COMBO1,
	ID_SKILL_BUTTON_DL_TREE1COMBO2,
	ID_SKILL_BUTTON_DL_TREE1COMBO3,
	ID_SKILL_BUTTON_DL_TREE1COMBO4,
	ID_SKILL_BUTTON_DL_TREE1COMBO5,

	ID_SKILL_BUTTON_DL_TREE2COMBO1,
	ID_SKILL_BUTTON_DL_TREE2COMBO2,
	ID_SKILL_BUTTON_DL_TREE2COMBO3,
	ID_SKILL_BUTTON_DL_TREE2COMBO4,
	ID_SKILL_BUTTON_DL_TREE2COMBO5,

	ID_SKILL_TEXT_DM_TREE1COMBO1,
	ID_SKILL_TEXT_DM_TREE1COMBO2,
	ID_SKILL_TEXT_DM_TREE1COMBO3,
	ID_SKILL_TEXT_DM_TREE1COMBO4,

	ID_SKILL_TEXT_DM_TREE2COMBO1,
	ID_SKILL_TEXT_DM_TREE2COMBO2,
	ID_SKILL_TEXT_DM_TREE2COMBO3,
	ID_SKILL_TEXT_DM_TREE2COMBO4,

	ID_SKILL_TEXT_DL_TREE1COMBO1,
	ID_SKILL_TEXT_DL_TREE1COMBO2,
	ID_SKILL_TEXT_DL_TREE1COMBO3,
	ID_SKILL_TEXT_DL_TREE1COMBO4,
	ID_SKILL_TEXT_DL_TREE1COMBO5,

	ID_SKILL_TEXT_DL_TREE2COMBO1,
	ID_SKILL_TEXT_DL_TREE2COMBO2,
	ID_SKILL_TEXT_DL_TREE2COMBO3,
	ID_SKILL_TEXT_DL_TREE2COMBO4,
	ID_SKILL_TEXT_DL_TREE2COMBO5,

	ID_SKILL_LEARN_BACKGROUND,
    ID_SKILL_CONTAINER_TREE,

	//======================================================================================================================//
	// 무공창 - 끝
	//======================================================================================================================//


	//======================================================================================================================//
	// 개인거래 - 시작
	//======================================================================================================================//
	ID_PERSONBUY_BACKGROUND				= 900,	// 백그라운드
	ID_PERSONBUY_BACKGROUND_CLOSE,				// 닫기

	ID_PERSONBUY_NAEM,							// 이름

	ID_PERSONBUY_PLAYER_NAME_LEFT,				// 플레이어 이름
	ID_PERSONBUY_PLAYER_NAME_RIGHT,				// 플레이어 이름

	ID_PERSONBUY_GOLD_LEFR,						// 금액표시
	ID_PERSONBUY_GOLD_RIGHT,					// 금액표시
	ID_PERSONBUY_GOLD_RIGHT_G,					
	ID_PERSONBUY_GOLD_RIGHT_S,
	ID_PERSONBUY_GOLD_RIGHT_B,

	ID_PERSONBUY_BUTTON_OK,						// 확인버튼
	ID_PERSONBUY_BUTTON_CANCLE,					// 취소버튼

	ID_PERSONBUY_PLAYER_1_SLOT0,
	ID_PERSONBUY_PLAYER_1_SLOT1,
	ID_PERSONBUY_PLAYER_1_SLOT2,
	ID_PERSONBUY_PLAYER_1_SLOT3,
	ID_PERSONBUY_PLAYER_1_SLOT4,
	ID_PERSONBUY_PLAYER_1_SLOT5,

	ID_PERSONBUY_PLAYER_2_SLOT0,
	ID_PERSONBUY_PLAYER_2_SLOT1,
	ID_PERSONBUY_PLAYER_2_SLOT2,
	ID_PERSONBUY_PLAYER_2_SLOT3,
	ID_PERSONBUY_PLAYER_2_SLOT4,
	ID_PERSONBUY_PLAYER_2_SLOT5,

	// 블루스크린
	ID_PERSONBUY_BLUE_LEFT_0,
	ID_PERSONBUY_BLUE_LEFT_1,
	ID_PERSONBUY_BLUE_LEFT_2,
	ID_PERSONBUY_BLUE_LEFT_3,
	ID_PERSONBUY_BLUE_LEFT_4,
	ID_PERSONBUY_BLUE_LEFT_5,
	
	ID_PERSONBUY_BLUE_RIGHT_0,
	ID_PERSONBUY_BLUE_RIGHT_1,
	ID_PERSONBUY_BLUE_RIGHT_2,
	ID_PERSONBUY_BLUE_RIGHT_3,
	ID_PERSONBUY_BLUE_RIGHT_4,
	ID_PERSONBUY_BLUE_RIGHT_5,


	//알림
	ID_PERSONBUY_QUESTION_BACKGROUND,			// 백그라운드
	ID_PERSONBUY_QUESTION_INPUT,				// 메시지
	ID_PERSONBUY_QUESTION_OK,					// 확인
	ID_PERSONBUY_QUESTION_CANCLE,				// 취소


	ID_PERSONBUY_BACKGROUND2,					// 움직이기위한 백그라운드
	ID_PERSONBUY_BG_TOTAL,
	ID_PERSONBUY_MANAGER_ID,					// 고유아이디

	// 거래 최초 알림통지
	ID_PERSONBUY_FIRST_QUESTION_BACKGROUND,		// 백그라운드
	ID_PERSONBUY_FIRST_QUESTION_TEXT,			// 알림 글
	ID_PERSONBUY_FIRST_OK,						// 수락
	ID_PERSONBUY_FIRST_CANCLE,					// 거절

	// 추가 기능
	ID_PERSONBUY_PLAYER_1_FACE_CW,					// 왼쪽	  얼굴_청운
	ID_PERSONBUY_PLAYER_1_FACE_GR,					// 왼쪽	  얼굴_채가령
	ID_PERSONBUY_PLAYER_1_FACE_PR,					// 왼쪽	  얼굴_패륵
	ID_PERSONBUY_PLAYER_1_FACE_SW,					// 왼쪽	  얼굴_비소운

	ID_PERSONBUY_PLAYER_2_FACE_CW,					// 오른쪽  얼굴_청운
	ID_PERSONBUY_PLAYER_2_FACE_GR,					// 오른쪽  얼굴_채가령
	ID_PERSONBUY_PLAYER_2_FACE_PR,					// 오른쪽  얼굴_패륵
	ID_PERSONBUY_PLAYER_2_FACE_SW,					// 오른쪽  얼굴_비소운
	//======================================================================================================================//
	// 개인거래 - 끝
	//======================================================================================================================//




	//======================================================================================================================//
	// 룸 리스트 - 시작
	//======================================================================================================================//
	ID_ROOMLIST_BACKGROUND				= 1000,				// 백그라운드

	ID_ROOMLIST_NAEM,

	ID_ROOMLIST_GO_VILLAGE,				// 마을로 들어가기

	ID_ROOMLIST_BUTTON_FAST_VERSE,				// 빠른 전장모드
	ID_ROOMLIST_BUTTON_MAKEROOM,				// 방만들기

	ID_ROOMLIST_LIST_BACKGROUND,				// 리스트 백그라운드


	ID_ROOMLIST_ROOM_0,
	ID_ROOMLIST_ROOM_1,
	ID_ROOMLIST_ROOM_2,
	ID_ROOMLIST_ROOM_3,
	ID_ROOMLIST_ROOM_4,
	ID_ROOMLIST_ROOM_5,
	ID_ROOMLIST_ROOM_6,
	ID_ROOMLIST_ROOM_7,
	ID_ROOMLIST_ROOM_8,
	ID_ROOMLIST_ROOM_9,
	ID_ROOMLIST_ROOM_10,
	ID_ROOMLIST_ROOM_11,
	ID_ROOMLIST_ROOM_12,
	ID_ROOMLIST_ROOM_13,
	ID_ROOMLIST_ROOM_14,
	ID_ROOMLIST_ROOM_15,
	ID_ROOMLIST_ROOM_16,

	ID_ROOMLIST_SERVER_GROUP,
	ID_ROOMLIST_SERVER_GENERAL,				// 일반서버
	ID_ROOMLIST_SERVER_GUILD,				// 길드서버

	ID_ROOMLIST_PAGE_LEFT,				// 페이지 왼쪽버튼
	ID_ROOMLIST_PAGE_RIGHT,				// 페이지 오른쪽버튼

	ID_ROOMLIST_PAGE_TEXT_BG,				// 페이지 백그라운드
	ID_ROOMLIST_PAGE_TEXT,				// 페이지 텍스트 "1/8"

	ID_ROOMLIST_RENEWAL,				// 갱신

	// PassWorld
	ID_ROOMLIST_PASSWORLD_BACKGROUND,				// 백그라운드
	ID_ROOMLIST_PASSWORLD_ICON,				// 아이콘
	ID_ROOMLIST_PASSWORLD_TEXT,				// 텍스트
	ID_ROOMLIST_PASSWORLD_OK,				// 확인버튼
	ID_ROOMLIST_PASSWORLD_CANCLE,				// 취소버튼


	ID_ROOMLIST_FAST_OK,								// 확인
	ID_ROOMLIST_FAST_CANCLE,							// 취소

	ID_NOTICE_NAME,
	ID_NOTICE_MESSAGE,

	ID_ROOMLIST_TOTAL,

	//======================================================================================================================//
	// 룸 리스트 - 끝
	//======================================================================================================================//




	//======================================================================================================================//
	// 방만들기 - 시작
	//======================================================================================================================//	
	ID_ROOMMAKE_BACKGROUND				= 1100,				// 백그라운드
	ID_ROOMMAKE_CLOSE,				// 닫기
	ID_ROOMMAKE_NAME,					// NAME
	ID_ROOMMAKE_ROOMNAME,				// 방제목
	ID_ROOMMAKE_PASSWORLD,				// 패스워드

	ID_ROOMMAKE_MAP_CHOICE,				// 맵선택
	ID_ROOMMAKE_ZONE_CHOICE,				// 구역선택

	ID_ROOMMAKE_LEVEL_GROUP,
	ID_ROOMMAKE_LEVEL_0,				// 레벨제한
	ID_ROOMMAKE_LEVEL_1,				// 레벨제한
	ID_ROOMMAKE_LEVEL_2,				// 레벨제한

	ID_ROOMMAKE_OK,				// 확인
	ID_ROOMMAKE_CANCLE,				// 취소

	//======================================================================================================================//
	// 방만들기 - 끝
	//======================================================================================================================//



	//======================================================================================================================//
	// 상점 - 시작
	//======================================================================================================================//
	ID_SHOP_BACKGROUND					= 1200,				// 백구라운드
	ID_SHOP_BACKGROUND_WIN,									// 이동
	ID_SHOP_NAME,											// 이름
	ID_SHOP_CLOSE,											// 닫기
	
	ID_SHOP_SLOT00,											// 슬롯
	ID_SHOP_SLOT01,											// 슬롯
	ID_SHOP_SLOT02,											// 슬롯
	ID_SHOP_SLOT03,											// 슬롯
	ID_SHOP_SLOT04,											// 슬롯
	ID_SHOP_SLOT05,											// 슬롯
	ID_SHOP_SLOT06,											// 슬롯
	ID_SHOP_SLOT07,											// 슬롯
	ID_SHOP_SLOT08,											// 슬롯
	ID_SHOP_SLOT09,											// 슬롯
	ID_SHOP_SLOT10,											// 슬롯
	ID_SHOP_SLOT11,											// 슬롯
		

	ID_SHOP_PAGE_LEFT,										// 페이지 왼쪽
	ID_SHOP_PAGE_RIGHT,										// 페이지 오른쪽
	ID_SHOP_PAGE_TEXT,										// 페이지
	ID_SHOP_BG_TOTAL,
	ID_SHOP_GOLD_BG,
	ID_SHOP_GOLD_G,
	ID_SHOP_GOLD_Y,
	ID_SHOP_GOLD_T,
	ID_SHOP_PAGE_REPIRE1,
	ID_SHOP_PAGE_REPIRE2,
	ID_SHOP_PAGE_BUY,
	ID_SHOP_PAGE_CANCEL,
	ID_SHOP_MANAGER_ID,										// 고유번호
	//======================================================================================================================//
	// 상점 - 끝
	//======================================================================================================================//


	//======================================================================================================================//
	// 스킬상점 - 시작
	//======================================================================================================================//
	ID_MYPET_BACKGROUND					= 1300,				// 백구라운드
	ID_MYPET_WIN,											// 이동
	ID_MYPET_CLOSE,											// 닫기

	ID_MYPET_NAME,
	ID_PLAYER_NAME,
	ID_MYPET_LEVEL,
	ID_MYPET_STATE,
	ID_MYPET_GROW,
	ID_MYPET_DEVOTION,

	ID_MYPET_EXP,
	ID_MYPET_HUNGRY,

	ID_MYPET_BUTTON_CHANGENAME,
	ID_MYPET_BUTTON_OUT,
	ID_MYPET_BUTTON_BACK,
	ID_MYPET_BUTTON_FEED,
	ID_MYPET_BUTTON_DELETE,

	ID_MYPET_SKILL1,
	ID_MYPET_SKILL2,
	ID_MYPET_SKILL3,
	ID_MYPET_SKILL4,

	ID_MYPET_BUTTON_PREV,
	ID_MYPET_BUTTON_NEXT,

	ID_MYPET_SLOT01,
	ID_MYPET_SLOT02,
	ID_MYPET_SLOT03,
	ID_MYPET_SLOT04,
	ID_MYPET_SLOT05,
	ID_MYPET_SLOT06,
	ID_MYPET_SLOT07,
	ID_MYPET_SLOT08,
	ID_MYPET_SLOT09,
	ID_MYPET_SLOT10,

	ID_MYPET_MANAGER_ID,
	//======================================================================================================================//
	// 스킬상점 - 끝
	//======================================================================================================================//


	//======================================================================================================================//
	// 상점 탭 - 시작
	//======================================================================================================================//

	// 무기
	ID_SHOPMENU_TAB_WEPON_GROUP = 1400,
	ID_SHOPMENU_TAB_WEPON_COMMAN,								// 공통무기
	ID_SHOPMENU_TAB_WEPON_SPECIAL,								// 특수무기
	ID_SHOPMENU_TAB_WEPON_RE_BUY,								// 재매입

	ID_SHOPMENU_SPECIAL_WEAPON_GROUP,									
	ID_SHOPMENU_WEAPON_BO,										// 봉/창
	ID_SHOPMENU_WEAPON_FAN,										// 부채
	ID_SHOPMENU_WEAPON_AXE2,									// 양손도끼
	ID_SHOPMENU_WEAPON_DAGGER2,									// 쌍수단검

	ID_SHOPMENU_COMMAN_WEAPON_GROUP,
	ID_SHOPMENU_WEAPON_SWORD,									// 검
	ID_SHOPMENU_WEAPON_AXE,										// 도끼
	ID_SHOPMENU_WEAPON_DAGGER,									// 단검

	// 방어구
	ID_SHOPMENU_TAB_ARMOR_GROUP,
	ID_SHOPMENU_TAB_ARMOR,										// 갑옷
	ID_SHOPMENU_TAB_ARMOR_RE_BUY,								// 재매입

	// 캐릭터
	ID_SHOPMENU_CHAR_GROUP,
	ID_SHOPMENU_CHAR_CHUNGWOON,									// 내공무사
	ID_SHOPMENU_CHAR_CHAEGARUNG,								// 비술사
	ID_SHOPMENU_CHAR_PAERUK,									// 전투무사
	ID_SHOPMENU_CHAR_BISOWOON,									// 암술자객



	// 장신구
	ID_SHOPMENU_TAB_ACC_GROUP,
	ID_SHOPMENU_TAB_ACC,										// 장신구
	ID_SHOPMENU_TAB_ACC_RE_BUY,									// 재매입

	ID_SHOPMENU_ACC_GROUP,
	ID_SHOPMENU_ACC_ACCESSORY,									// 보주
	ID_SHOPMENU_ACC_RING,										// 반지
	ID_SHOPMENU_ACC_ARMLET,										// 팔찌
	ID_SHOPMENU_ACC_NECKLACE,									// 목걸이


	// 탈것
	ID_SHOPMENU_TAB_PET_GROUP,
	ID_SHOPMENU_TAB_PET,										// 탈것
	ID_SHOPMENU_TAB_PET_RE_BUY,									// 재매입

	ID_SHOPMENU_PET_GROUP,
	ID_SHOPMENU_PET_HORSE,										// 말
	ID_SHOPMENU_PET_TIGER,										// 호랑이
	ID_SHOPMENU_PET_WOLF,										// 늑대	

	// 망토
	ID_SHOPMENU_TAB_MANTLA_GROUP,
	ID_SHOPMENU_TAB_MANTLA,										// 망토
	ID_SHOPMENU_TAB_BANTLA_RE_BUY,								// 재매입
	//======================================================================================================================//
	// 상점 탭 - 끝
	//======================================================================================================================//

	//======================================================================================================================//
	// 전장 상점 - 시작
	//======================================================================================================================//
	ID_BPSHOP_BG							= 1500,
	
	ID_BOSS_BPSHOPRADIO,
	ID_RADIOBTN1,
	ID_RADIOBTN2,
	ID_RADIOBTN3,
	ID_RADIOBTN4,
	ID_RADIOBTN5,

	ID_ITEM_BTN_GROUP,
	ID_ITEM_BTN1,
	ID_ITEM_BTN2,
	ID_ITEM_BTN3,
	ID_ITEM_BTN4,
	ID_ITEM_BTN5,

	ID_BP_ITEM1,
	ID_BP_ITEM2,
	ID_BP_ITEM3,
	ID_BP_ITEM4,
	ID_BP_ITEM5,

	
	ID_BPSHOP_NAME,
	ID_BPSHOP_CLOSE_BTN,
	ID_BPSHOP_LEFT_BTN,
	ID_BPSHOP_RIGHT_BTN,
	ID_BPSHOP_BUY_BTN,
	ID_BPSHOP_MYPOINT,
	ID_BPSHOP_PAGE,

	ID_BP_WIN_BG,
	ID_BP_TOTAL,
	ID_BPSHOP_MANAGER_ID,
	//======================================================================================================================//
	// 전장 상점  - 끝
	//======================================================================================================================//

	//===============================================================================================================================================//
	// 캐릭터 정보 -- 시작
	//===============================================================================================================================================//
	ID_CHARACTER_BACKGROUND					= 1800,				// 교쒼
	ID_CHARACTER_BACKGROUND2,
	ID_CHARACTER_WIN,											// 깃痙으	
	ID_CHARACTER_CLOSE,											// 밑균객큐
	ID_CHARACTER_EXBTN,

	ID_CHARACTER_LV,											// 된섬STA
	ID_CHARACTER_GUILD,											// 묏삔STA
	ID_CHARACTER_CLASS,									//斂撚STA

	ID_CHARACTER_SLOT_WEAPON,										// 공통무기
	ID_CHARACTER_SLOT_SP_WEAPON,										// 전용무기
	ID_CHARACTER_SLOT_NAKELACE,										// 보주
	ID_CHARACTER_SLOT_PET,										// 펫
	ID_CHARACTER_SLOT_ARROR,										// 갑옷
	ID_CHARACTER_SLOT_HAIR,										// 머리	
	ID_CHARACTER_SLOT_FACE,										// 얼굴
	ID_CHARACTER_SLOT_CUFF,										// 망토
	ID_CHARACTER_SLOT_NECKLACE,										// 목걸이
	ID_CHARACTER_SLOT_RING,										// 반지
	ID_CHARACTER_SLOT_BACK,										// 팔찌
	
	ID_CHARACTER_LEFT,											// 璘旗瘻객큐
	ID_CHARACTER_RIGHT,											// 塘旗瘻객큐


	
	ID_CHARACTER_TAB_GROUP,
	ID_CHARACTER_TAB_CHARACTER,									// 탭 캐릭터
	ID_CHARACTER_TAB_RECORD_POINT,								// 탬 포인트 전적


	ID_CHARACTER_TAB_CHARACTER_BG,								// 탭 캐릭터 백그라운드
	ID_CHARACTER_TAB_RECORD_POINT_BG,							// 탬 포인트 전적 백그라운드



	ID_CHARACTER_INFO_0,										// 체력
	ID_CHARACTER_INFO_1,										// 기력
						
	ID_CHARACTER_INFO_2,										// 물리공격
	ID_CHARACTER_INFO_3,										// 주술공격
	ID_CHARACTER_INFO_4,										// 원거리공격

	ID_CHARACTER_INFO_5,										// 물리방어
	ID_CHARACTER_INFO_6,										// 주술방어
	ID_CHARACTER_INFO_7,										// 원거리방어

	ID_CHARACTER_INFO_8,										// 물리안정
	ID_CHARACTER_INFO_9,										// 주물안정
	ID_CHARACTER_INFO_10,										// 원거리안정

	ID_CHARACTER_INFO_11,										// 물리치명
	ID_CHARACTER_INFO_12,										// 주술치명
	ID_CHARACTER_INFO_13,										// 원거리치명

	ID_CHARACTER_INFO_14,										// 제조숙련도
	ID_CHARACTER_INFO_15,										// 무공포인트
	ID_CHARACTER_INFO_16,										// 전장포인트

	ID_CHARACTER_INFO_17,										// 저너체전적
	ID_CHARACTER_INFO_18,										// 오늘전적
	ID_CHARACTER_INFO_19,										// 전체승률
	ID_CHARACTER_INFO_20,										// 오늘승률

	
	ID_CHARACTER_NAME,
	ID_CHARACTER_BG_TOTAL,
	ID_CHARACTER_MANAGER_ID,									// 고유아이디

	ID_CHARACTER_ADD_BUTTON_1,
	ID_CHARACTER_ADD_BUTTON_2,
	ID_CHARACTER_ADD_BUTTON_3,
	ID_CHARACTER_ADD_BUTTON_4,

	ID_CHARACTER_BACKGROUND_1,
	ID_CHARACTER_BACKGROUND_2,
	ID_CHARACTER_BACKGROUND_3,
	//===============================================================================================================================================//
	// 캐릭터 정보 -- 끝
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// 퀘스트 -- 시작
	//===============================================================================================================================================//
	ID_QUEST_BACKGROUND					=		1900,			// 백그라운드
	ID_QUEST_BOOK,												// 책버튼
	ID_QUEST_BACK,												// 나가기

	ID_QUEST_CHOICE_BREACKGROUND,								// 선택시뜨는 창	
	ID_QUEST_CHOICE_CLOSE,										// 닫기

	ID_QUEST_CHOICE_MAPNAME,									// 맵이름

	ID_QUEST_MISSION_TEXT_1,									// 미션1
	ID_QUEST_MISSION_TEXT_2,									// 미션2
	ID_QUEST_MISSION_TEXT_3,									// 미션3

	ID_QUEST_CHOICE_GIVE_IMAGE,									// 보상품
	ID_QUEST_CHOICE_GIVE_NAME,									// 보상품이름

	ID_QUEST_CHOICE_GIVE_IMAGE2,									// 보상품
	ID_QUEST_CHOICE_GIVE_NAME2,									// 보상품이름

	ID_QUEST_CHOICE_GIVE_EXPLANATION,							// 설명
	ID_QUEST_CHOICE_COMPLETION,									// 완료조건 요약	

	ID_QUEST_BUTTON_ACCEPT,										// 수락버튼	
	ID_QUEST_BUTTON_GIVEUP,										// 포기버튼

	// 내모헙일지
	ID_QUEST_MY_BACKGROUND,										// 백그라운드
	ID_QUEST_MY_CLOSE,											// 닫기

	ID_QUEST_MY_LIST00,											// 리스트
	ID_QUEST_MY_LIST01,
	ID_QUEST_MY_LIST02,
	ID_QUEST_MY_LIST03,
	ID_QUEST_MY_LIST04,
	ID_QUEST_MY_LIST05,
	ID_QUEST_MY_LIST06,
	ID_QUEST_MY_LIST07,
	ID_QUEST_MY_LIST08,
	ID_QUEST_MY_LIST09,


	// 아이콘
	ID_QUEST_ICON00,
	ID_QUEST_ICON01,
	ID_QUEST_ICON02,
	ID_QUEST_ICON03,
	ID_QUEST_ICON04,
	ID_QUEST_ICON05,
	ID_QUEST_ICON06,
	ID_QUEST_ICON07,
	ID_QUEST_ICON08,
	ID_QUEST_ICON09,
	ID_QUEST_ICON10,
	ID_QUEST_ICON11,
	ID_QUEST_ICON12,
	ID_QUEST_ICON13,
	ID_QUEST_ICON14,
	ID_QUEST_ICON15,
	ID_QUEST_ICON16,
	ID_QUEST_ICON17,
	ID_QUEST_ICON18,
	ID_QUEST_ICON19,
	ID_QUEST_ICON20,
	ID_QUEST_ICON21,
	ID_QUEST_ICON22,
	ID_QUEST_ICON23,
	ID_QUEST_ICON24,
	ID_QUEST_ICON25,
	ID_QUEST_ICON26,
	ID_QUEST_ICON27,
	ID_QUEST_ICON28,
	ID_QUEST_ICON29,
	ID_QUEST_ICON30,
	ID_QUEST_ICON31,
	ID_QUEST_ICON32,
	ID_QUEST_ICON33,
	ID_QUEST_ICON34,
	ID_QUEST_ICON35,

	// 정보
	ID_QUEST_INFORMATION_BACKGROUND,							// 백그라운드
	ID_QUEST_INFORMATION_CLOSE,									// 닫기
	ID_QUEST_INFORMATION_NAME,									// 퀘스트 이름
	ID_QUEST_INFORMATION_EXPLANATION,							// 설명
	ID_QUEST_INFORMATION_CONDITION,								// 조건
	ID_QUEST_INFORMATION_GIVE_IMAGE,							// 보상이미지
	ID_QUEST_INFORMATION_GIVE_NAME,								// 보상이름
	ID_QUEST_INFORMATION_GIVE_IMAGE2,							// 보상이미지
	ID_QUEST_INFORMATION_GIVE_NAME2,								// 보상이름
	ID_QUEST_INFORMATION_GIVE_OK,								// 보상받기
	ID_QUEST_INFORMATION_GIVEUP,								// 포기
	//===============================================================================================================================================//
	// 퀘스트 -- 끝
	//===============================================================================================================================================//

	//===============================================================================================================================================//
	// 시스템 -- 시작
	//===============================================================================================================================================//
	ID_SYSTEM_BACKGROUND			= 2100,						// 백그라운드
	ID_SYSTEM_NAME,												// 이름
	ID_SYSTEM_CLOSE,											// 닫기

	ID_SYSTEM_BUTTON_OPTION,									// 옵 션
	ID_SYSTEM_BUTTON_CHANNEL,									// 채널변경
	ID_SYSTEM_BUTTON_CHARACTER,									// 캐릭터선택
	ID_SYSTEM_BUTTON_GAMEOVER,									// 게임종료
	ID_SYSTEM_BUTTON_BACKTOWN,									// 마을로돌아가기
	ID_SYSTEM_BG_TOTAL,
	//===============================================================================================================================================//
	// 시스템 -- 끝
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// 옵션 -- 시작
	//===============================================================================================================================================//	
	ID_LOBBY_OPTION_BACKGROUND			=	2200,				// 백그라운드
	ID_LOBBY_OPTION_WIN,										// 이동
	ID_LOBBY_OPTION_NAME,										// 이름
	ID_LOBBY_OPTION_CLOSE,										// 닫기버튼

	ID_LOBBY_OPTION_TAB_GROUP,
	ID_LOBBY_OPTION_TAB_GAME,									// 탭 게임설정
	ID_LOBBY_OPTION_TAB_KEY,									// 탭 키설정

	ID_LOBBY_OPTION_VOLUME_BACKGROUND,							// 배경음 효과음 백그라운드

	ID_LOBBY_OPTION_MUSIC_ONOFF,								// 배경음 on/off	
	ID_LOBBY_OPTION_MUSIC_BG,									// 슬라이드 백그라운드
	ID_LOBBY_OPTION_MUSIC_SLIDER,								// 슬라이드

	
	ID_LOBBY_OPTION_EFFECT_ONOFF,								// 효과음 on/off
	ID_LOBBY_OPTION_EFFECT_BG,									// 슬라이드 백그라운드
	ID_LOBBY_OPTION_EFFECT_SLIDER,								// 슬라이드


	ID_LOBBY_OPTION_GAME_BACKGROUND,							// 옵션 백그라운드
	ID_LOBBY_OPTION_NO_BUY,										// 거래거절
	ID_LOBBY_OPTION_NO_INVITATION_ROOM,							// 초대거부(룸)
	ID_LOBBY_OPTION_NO_INVITATION_TOWN,							// 초대거부(광장)	
	ID_LOBBY_OPTION_GUAGE_MYHP_VALUE,							// 체력/기력 수치표시
	ID_LOBBY_OPTION_GUAGE_MYHP,									// 자기이름/체력
	ID_LOBBY_OPTION_GUAGE_MYTEAMID,								// 아군이름/체력
	ID_LOBBY_OPTION_GUAGE_ENEMYTEAMID,							// 적군이름/체력
	ID_LOBBY_OPTION_GAME_TIP,									// 게임팁
	ID_LOBBY_OPTION_SKILL,										// 좌측 상단 스킬 단축창 사용

	ID_LOBBY_OPTION_DEFAULT,									// 기본값

	//////////////////////////////////////////////////////////////////////////

	ID_LOBBY_OPTION_KEY_GROUP,
	ID_LOBBY_OPTION_GAME_KEY,									// 게임키설정
	ID_LOBBY_OPTION_SKILL_KEY,									// A슬롯단축키
	ID_LOBBY_OPTION_COMSKILL_KEY,								// B슬롯단축키
	ID_LOBBY_OPTION_SKILL2_KEY,									// C스킬좌상단
	ID_LOBBY_OPTION_GAMEMENU,									// 게임메뉴

	ID_LOBBY_OPTION_DEFAULTA_KEYSETUP,							// 기본값1
	ID_LOBBY_OPTION_DEFAULTB_KEYSETUP,							// 기본값1
	ID_LOBBY_OPTION_CONFIRM_KEYSETUP,							// 확인


	// 게임키
	ID_LOBBY_OPTION_KEY_JUMP,
	ID_LOBBY_OPTION_KEY_ATTACK,
	ID_LOBBY_OPTION_KEY_CHANGEWEAPON,
	ID_LOBBY_OPTION_KEY_RIDEPET,
	ID_LOBBY_OPTION_KEY_MOVEUP,
	ID_LOBBY_OPTION_KEY_MOVEDOWN,
	ID_LOBBY_OPTION_KEY_MOVERIGHT,
	ID_LOBBY_OPTION_KEY_MOVELEFT,

	ID_LOBBY_OPTIONKEY_NULL_BG_1,			//비어있는공간 채워넣기
	ID_LOBBY_OPTION_KEY_TEAMSKILL1,
	ID_LOBBY_OPTION_KEY_TEAMSKILL2,
	ID_LOBBY_OPTION_KEY_TEAMSKILL3,
	ID_LOBBY_OPTION_KEY_TEAMSKILL4,
	ID_LOBBY_OPTION_KEY_TEAMSKILL5,
	ID_LOBBY_OPTION_KEY_TEAMSKILL6,
	ID_LOBBY_OPTION_KEY_TEAMSKILL7,
	ID_LOBBY_OPTION_KEY_TEAMSKILL8,
	ID_LOBBY_OPTION_KEY_TEAMSKILL9,
	ID_LOBBY_OPTION_KEY_TEAMSKILL10,
	ID_LOBBY_OPTION_KEY_SELOURTEAM,	
	ID_LOBBY_OPTION_KEY_SELNEAROPP,	
	ID_LOBBY_OPTION_KEY_SHOWINFO,
	ID_LOBBY_OPTION_KEY_SHOWHELP,

	// 스킬
	ID_LOBBY_OPTIONKEY_NULL_BG_3,			//비어있는공간 채워넣기
	ID_LOBBY_OPTION_SHOTCUT_SKILL01,
	ID_LOBBY_OPTION_SHOTCUT_SKILL02,
	ID_LOBBY_OPTION_SHOTCUT_SKILL03,
	ID_LOBBY_OPTION_SHOTCUT_SKILL04,
	ID_LOBBY_OPTION_SHOTCUT_SKILL05,
	ID_LOBBY_OPTION_SHOTCUT_SKILL06,
	ID_LOBBY_OPTION_SHOTCUT_SKILL07,
	ID_LOBBY_OPTION_SHOTCUT_SKILL08,
	ID_LOBBY_OPTION_SHOTCUT_SKILL09,
	ID_LOBBY_OPTION_SHOTCUT_SKILL10,

	// 공통스킬
	ID_LOBBY_OPTIONKEY_NULL_BG_5,			//비어있는공간 채워넣기
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL01,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL02,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL03,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL04,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL05,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL06,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL07,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL08,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL09,
	ID_LOBBY_OPTION_SHOTCUT_COMSKILL10,

	// 단축키
	ID_LOBBY_OPTION_HOT_CHARACTER,
	ID_LOBBY_OPTION_HOT_SKILL,
	ID_LOBBY_OPTION_HOT_BAG,
	ID_LOBBY_OPTION_HOT_QUEST,
	ID_LOBBY_OPTION_HOT_PERSONSHOP,

	ID_LOBBY_OPTIONKEY_NULL_BG_7,			//비어있는공간 채워넣기
	
	ID_LOBBY_OPTION_HOT_FRIEND,
	ID_LOBBY_OPTION_HOT_GUILD,
	ID_LOBBY_OPTION_HOT_MAP,
	ID_LOBBY_OPTION_HOT_SYSTEM,
	ID_LOBBY_OPTION_HOT_CASHSHOP,
    
	ID_OPTION_BG_TOTAL,
	ID_OPTION_MANAGER_ID,
	//===============================================================================================================================================//
	// 옵션 -- 끝
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// 게임방 -- 시작
	//===============================================================================================================================================//
	ID_LOBBY_GAMEROOMRIGHT_TEAMGROUP=	2400,
	ID_LOBBY_GAMEROOMRIGHT_REDTEAM,									// 레디팀
	ID_LOBBY_GAMEROOMRIGHT_BLUETEAM,									// 블루팀
	ID_LOBBY_GAMEROOMRIGHT_BACK,										// 백그라운드
	ID_LOBBY_GAMEROOMRIGHT_ROOMINFO,									// 룸정보
	ID_LOBBY_GAMEROOMRIGHT_INVITATION,								// 초대
	ID_LOBBY_GAMEROOMRIGHT_EQUIPITEM,									// 아이템장착
	ID_LOBBY_GAMEROOMRIGHT_EXIT,										// 나가기
	ID_LOBBY_GAMEROOMRIGHT_LEVEL,										// 레벨 TEXT
	ID_LOBBY_GAMEROOMRIGHT_JOIN,										// Join TEXT
	ID_LOBBY_GAMEROOMRIGHT_ROOMNAME,									// 방이름

	ID_LOBBY_GAMEROOMRIGHT_START,										// 시작버튼
	ID_LOBBY_GAMEROOMRIGHT_READY,								// 레디버튼

	ID_LOBBY_GAMEROOMRIGHT_MAPIMAGE,


	ID_LOBBY_GAMEROOMRIGHT_MAPLEFT,									// 맵 왼쪽
	ID_LOBBY_GAMEROOMRIGHT_MAPRIGHT,									// 맵 오른쪽
	ID_LOBBY_GAMEROOMRIGHT_MAPOPTION_L,								// 옵션 왼쪽
	ID_LOBBY_GAMEROOMRIGHT_MAPOPTION_R,								// 옵션 오른쪽
	ID_LOBBY_GAMEROOMRIGHT_MAPBACK,									// 화려한 이미지


	ID_LOBBY_GAMEROOMRIGHT_ZONE_LEFT,								// 구역 왼쪽 버튼
	ID_LOBBY_GAMEROOMRIGHT_ZONE_TEXT,								// 구역 텍스트
	ID_LOBBY_GAMEROOMRIGHT_ZONE_RIGHT,								// 구역 오른쪽 버튼


	ID_LOBBY_GAMEROOMRIGHT_ITEM_LEFT,								// 아이템획득 왼쪽 버튼
	ID_LOBBY_GAMEROOMRIGHT_ITEM_TEXT,								// 아이템획득 텍스트
	ID_LOBBY_GAMEROOMRIGHT_ITEM_RIGHT,								// 아이템획득 오른쪽 버튼

	//채팅
	ID_LOBBY_GAMEROOM_CHAT_FILD,
	ID_LBBBY_GAMEROOM_CHAT_LIST,
	ID_LBBBY_GAMEROOM_CHAT_INPU,


	ID_LOBBY_GAMEROOM_SLOT_0	 = 2500	,
	ID_LOBBY_GAMEROOM_SLOT_1		,
	ID_LOBBY_GAMEROOM_SLOT_2		,
	ID_LOBBY_GAMEROOM_SLOT_3		,
	ID_LOBBY_GAMEROOM_SLOT_4		,
	ID_LOBBY_GAMEROOM_SLOT_5		,
	ID_LOBBY_GAMEROOM_SLOT_6		,
	ID_LOBBY_GAMEROOM_SLOT_7		,

	ID_LOBBY_GAMEROOM_READY_0		,
	ID_LOBBY_GAMEROOM_READY_1		,
	ID_LOBBY_GAMEROOM_READY_2		,
	ID_LOBBY_GAMEROOM_READY_3		,
	ID_LOBBY_GAMEROOM_READY_4		,
	ID_LOBBY_GAMEROOM_READY_5		,
	ID_LOBBY_GAMEROOM_READY_6		,
	ID_LOBBY_GAMEROOM_READY_7		,	

	ID_LOBBY_GAMEROOM_CROWN_0		,	
	ID_LOBBY_GAMEROOM_CROWN_1		,	
	ID_LOBBY_GAMEROOM_CROWN_2		,	
	ID_LOBBY_GAMEROOM_CROWN_3		,	
	ID_LOBBY_GAMEROOM_CROWN_4		,	
	ID_LOBBY_GAMEROOM_CROWN_5		,	
	ID_LOBBY_GAMEROOM_CROWN_6		,	
	ID_LOBBY_GAMEROOM_CROWN_7		,	

	ID_LOBBY_CHARINFO_BG			,	
	ID_LOBBY_CHARINFO_LINE_0		,	
	ID_LOBBY_CHARINFO_LINE_1		,	
	ID_LOBBY_CHARINFO_LINE_2		,	
	ID_LOBBY_CHARINFO_LINE_3		,	
	ID_LOBBY_CHARINFO_INFOBUTTON	,	
	ID_LOBBY_CHARINFO_CLOSEBUTTON	,	
	ID_LOBBY_CHARINFO_TITLE_ID		,	
	ID_LOBBY_CHARINFO_TITLE_LEVEL	,	
	ID_LOBBY_CHARINFO_TITLE_GUILD	,	
	ID_LOBBY_CHARINFO_TITLE_CLASS	,	
	ID_LOBBY_CHARINFO_TITLE_SCORE	,	
	ID_LOBBY_CHARINFO_ID			,	
	ID_LOBBY_CHARINFO_LEVEL			,	
	ID_LOBBY_CHARINFO_GUILD			,	
	ID_LOBBY_CHARINFO_CLASS			,	
	ID_LOBBY_CHARINFO_SCORE			,	

	ID_LOBBY_CHARINFO_NAME_0		,	
	ID_LOBBY_CHARINFO_NAME_1		,	
	ID_LOBBY_CHARINFO_NAME_2		,	
	ID_LOBBY_CHARINFO_NAME_3		,	
	ID_LOBBY_CHARINFO_NAME_4		,	
	ID_LOBBY_CHARINFO_NAME_5		,	
	ID_LOBBY_CHARINFO_NAME_6		,	
	ID_LOBBY_CHARINFO_NAME_7		,	
	ID_LOBBY_CHARINFO_NAME_8		,

	//===============================================================================================================================================//
	// 게임방 -- 끝
	//===============================================================================================================================================//



	//===============================================================================================================================================//
	// 강화 분해 수리 -- 시작
	//===============================================================================================================================================//
	// 아이템강화 다이얼로그
	ID_RRD_BACKGROUND					= 2700,			// 백그라운드
	ID_RRD_WIN,											// 이동
	ID_RRD_CLOSE,										// 닫기

	ID_RRD_TAB_GROUP,
	ID_RRD_TAB_REINFOREC,								// 강화
	ID_RRD_TAB_DECOMPOSE,								// 분해
	ID_RRD_TAB_RECHARGE,								// 수리

	ID_RRD_IMAGE_DECOMPOSE,								// 분해 이미지

	ID_RRD_PROGRESS_NAME,								// 아이템이름
	ID_RRD_PROGRESS_1,									// 프로그래서 에너지(강화)
	ID_RRD_PROGRESS_2,									// 프로그래서 에너지(분해)
	ID_RRD_PROGRESS_3,									// 프로그래서 에너지(수리)
	ID_RRD_MSG,											// 알림메시지
	ID_RRD_OK,											// 실행
	ID_RRD_RECHARGE,											// 실행
	ID_RRD_CANCEL,											// 실행
	ID_RRD_BG_TOTAL,
	ID_RRD_MANAGER_ID,

	ID_RRD_REINFOREC_IMAGE = 2740,								// 강화 이미지
	ID_RRD_REINFOREC_TEXT,
	ID_RRD_REINFOREC_PERCENT,
	ID_RRD_REINFOREC_BG,
	ID_RRD_REINFOREC_BIGBALL,
	ID_RRD_REINFOREC_EQUIPMENT,
	ID_RRD_REINFOREC_BALL01,
	ID_RRD_REINFOREC_BALL02,
	ID_RRD_REINFOREC_ICON01,
	ID_RRD_REINFOREC_ICON02,
	ID_RRD_REINFOREC_ICON03,
	ID_RRD_REINFOREC_ICON04,
	ID_RRD_REINFOREC_ICON05,
	ID_RRD_REINFOREC_NUMBER01,
	ID_RRD_REINFOREC_NUMBER02,
	ID_RRD_REINFOREC_NUMBER03,
	ID_RRD_REINFOREC_NUMBER04,
	ID_RRD_REINFOREC_NUMBER05,
	ID_RRD_REINFOREC_TEXT01,
	ID_RRD_REINFOREC_TEXT02,
	ID_RRD_REINFOREC_TEXT_PERCENT,

	ID_RRD_RECHARGE_IMAGE = 2770,								// 수리 이미지
	ID_RRD_RECHARGE_TEXT,
	ID_RRD_RECHARGE_PERCENT,
	ID_RRD_RECHARGE_BG,
	ID_RRD_RECHARGE_BIGBALL,
	ID_RRD_RECHARGE_EQUIPMENT,
	ID_RRD_RECHARGE_BALL01,
	ID_RRD_RECHARGE_ICON01,
	ID_RRD_RECHARGE_ICON02,
	ID_RRD_RECHARGE_TEXT01,
	ID_RRD_RECHARGE_TEXT02,
	ID_RRD_RECHARGE_TEXT_PERCENT,

	ID_RRD_REINFOREC_PERCENT_UP,
	ID_RRD_RECHARGE_PERCENT_UP,
	ID_RRD_REINFOREC_BEHARD,
	ID_RRD_RECHARGE_BEHARD,


	//===============================================================================================================================================//
	// 강화 분해 수리 -- 끝
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// 아이템장착 -- 시작
	//===============================================================================================================================================//	
	ID_LOBBY_BASE1_EQUIPITEM_FIELD = 2800,
	ID_LOBBY_EQUIPITEM_ARMOR0	,
	ID_LOBBY_EQUIPITEM_ARMOR1	,
	ID_LOBBY_EQUIPITEM_ARMOR2	,
	ID_LOBBY_EQUIPITEM_ARMOR3	,
	ID_LOBBY_EQUIPITEM_ARMOR4	,
	ID_LOBBY_EQUIPITEM_ARMOR5	,
	ID_LOBBY_EQUIPITEM_ARMOR6	,
	ID_LOBBY_EQUIPITEM_ARMOR7	,
	ID_LOBBY_EQUIPITEM_WEAPON0	,
	ID_LOBBY_EQUIPITEM_WEAPON1	,
	ID_LOBBY_EQUIPITEM_WEAPON2	,
	ID_LOBBY_EQUIPITEM_SWEAPON0	,
	ID_LOBBY_EQUIPITEM_SWEAPON1	,
	ID_LOBBY_EQUIPITEM_SWEAPON2	,
	ID_LOBBY_EQUIPITEM_ACCESORY0,
	ID_LOBBY_EQUIPITEM_ACCESORY1,
	ID_LOBBY_EQUIPITEM_ACCESORY2,
	ID_LOBBY_EQUIPITEM_PET0		,
	ID_LOBBY_EQUIPITEM_PET1		,
	ID_LOBBY_EQUIPITEM_PET2		,
	ID_LOBBY_EQUIPITEM_ARMORLEFT,
	ID_LOBBY_EQUIPITEM_ARMORRIGHT	,
	ID_LOBBY_EQUIPITEM_WEAPONLEFT	,
	ID_LOBBY_EQUIPITEM_WEAPONRIGHT	,
	ID_LOBBY_EQUIPITEM_SWEAPONLEFT	,
	ID_LOBBY_EQUIPITEM_SWEAPONRIGHT	,
	ID_LOBBY_EQUIPITEM_ACCESORYLEFT	,
	ID_LOBBY_EQUIPITEM_ACCESORYRIGHT,
	ID_LOBBY_EQUIPITEM_PETLEFT		,
	ID_LOBBY_EQUIPITEM_PETRIGHT		,
	ID_LOBBY_EQUIPITEM_CONFIRM,		
	ID_LOBBY_EQUIPITEM_CANCEL,		

	ID_LOBBY_EQUIPITEM_ARMOR_GROUP	,
	ID_LOBBY_EQUIPITEM_ARMOR0_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR1_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR2_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR3_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR4_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR5_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR6_CHOICE,
	ID_LOBBY_EQUIPITEM_ARMOR7_CHOICE,

	ID_LOBBY_EQUIPITEM_WEAPON_GROUP,
	ID_LOBBY_EQUIPITEM_WEAPON0_CHOICE,
	ID_LOBBY_EQUIPITEM_WEAPON1_CHOICE,
	ID_LOBBY_EQUIPITEM_WEAPON2_CHOICE,

	ID_LOBBY_EQUIPITEM_SWEAPON_GROUP,
	ID_LOBBY_EQUIPITEM_SWEAPON0_CHOICE,
	ID_LOBBY_EQUIPITEM_SWEAPON1_CHOICE,
	ID_LOBBY_EQUIPITEM_SWEAPON2_CHOICE,

	ID_LOBBY_EQUIPITEM_ACCESORY_GROUP,	
	ID_LOBBY_EQUIPITEM_ACCESORY0_CHOICE	,
	ID_LOBBY_EQUIPITEM_ACCESORY1_CHOICE	,
	ID_LOBBY_EQUIPITEM_ACCESORY2_CHOICE	,

	ID_LOBBY_EQUIPITEM_PET_GROUP,		
	ID_LOBBY_EQUIPITEM_PET0_CHOICE,		
	ID_LOBBY_EQUIPITEM_PET1_CHOICE,		
	ID_LOBBY_EQUIPITEM_PET2_CHOICE,		
	ID_LOBBY_EQUIPITEM_ARMOR0_CHECK,		
	ID_LOBBY_EQUIPITEM_ARMOR1_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR2_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR3_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR4_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR5_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR6_CHECK	,	
	ID_LOBBY_EQUIPITEM_ARMOR7_CHECK	,	

	ID_LOBBY_EQUIPITEM_WEAPON0_CHECK,	
	ID_LOBBY_EQUIPITEM_WEAPON1_CHECK,	
	ID_LOBBY_EQUIPITEM_WEAPON2_CHECK,	

	ID_LOBBY_EQUIPITEM_SWEAPON0_CHECK,	
	ID_LOBBY_EQUIPITEM_SWEAPON1_CHECK,	
	ID_LOBBY_EQUIPITEM_SWEAPON2_CHECK,	

	ID_LOBBY_EQUIPITEM_ACCESORY0_CHECK,	
	ID_LOBBY_EQUIPITEM_ACCESORY1_CHECK,	
	ID_LOBBY_EQUIPITEM_ACCESORY2_CHECK,	

	ID_LOBBY_EQUIPITEM_PET0_CHECK	,	
	ID_LOBBY_EQUIPITEM_PET1_CHECK	,	
	ID_LOBBY_EQUIPITEM_PET2_CHECK	,	
	//===============================================================================================================================================//
	// 아이템장착 -- 끝
	//===============================================================================================================================================//



	//======================================================================================================================//
	// 개인상점 - 시작
	//======================================================================================================================//	
	
	ID_PERSONSHOP_BG						= 3000,
	ID_PERSONSHOP_BG_CASH,					// 캐쉬

	ID_PERSONSHOP_BG_WIN,
	ID_PERSONSHOP_CLOSE_BTN,
	ID_PERSONSHOP_CLOSE_BTN_2,
	ID_PERSONSHOP_NAME,
	ID_PERSONSHOP_CHAT,
	ID_PERSONSHOP_OTEM_SELL_BG,

	ID_PERSONSHOP_ITEM_IMAGE1,				// 이미지
	ID_PERSONSHOP_ITEM_IMAGE2,
	ID_PERSONSHOP_ITEM_IMAGE3,
	ID_PERSONSHOP_ITEM_IMAGE4,

	ID_PERSONSHOP_ITEM_PRICE1_BG,	
	ID_PERSONSHOP_ITEM_PRICE2_BG,
	ID_PERSONSHOP_ITEM_PRICE3_BG,
	ID_PERSONSHOP_ITEM_PRICE4_BG,

	ID_PERSONSHOP_ITEM_PRICE1_G,	
	ID_PERSONSHOP_ITEM_PRICE2_G,
	ID_PERSONSHOP_ITEM_PRICE3_G,
	ID_PERSONSHOP_ITEM_PRICE4_G,

	ID_PERSONSHOP_ITEM_PRICE1_Y,	
	ID_PERSONSHOP_ITEM_PRICE2_Y,
	ID_PERSONSHOP_ITEM_PRICE3_Y,
	ID_PERSONSHOP_ITEM_PRICE4_Y,

	ID_PERSONSHOP_ITEM_PRICE1_T,	
	ID_PERSONSHOP_ITEM_PRICE2_T,
	ID_PERSONSHOP_ITEM_PRICE3_T,
	ID_PERSONSHOP_ITEM_PRICE4_T,

	ID_PERSONSHOP_ITEM_BUY_BTN1,
	ID_PERSONSHOP_ITEM_BUY_BTN2,
	ID_PERSONSHOP_ITEM_BUY_BTN3,
	ID_PERSONSHOP_ITEM_BUY_BTN4,

	ID_PERSONSHOP_ITEM_SETPRI_BTN1,
	ID_PERSONSHOP_ITEM_SETPRI_BTN2,
	ID_PERSONSHOP_ITEM_SETPRI_BTN3,
	ID_PERSONSHOP_ITEM_SETPRI_BTN4,

	ID_PERSPNSHOP_START,					// 판매시작
	ID_PERSPNSHOP_END,						// 종료
	ID_PERSPNSHOP_SETNAME,
	ID_PERSPNSHOP_LBTN,
	ID_PERSPNSHOP_RBTN,
	ID_PERSONSHOP_TOTAL,					
	ID_PERSONSHOP_MANAGER_ID,

	//확인창
	ID_PERSONSHOP_CK_BACKGROUND,			// 백그라운드
	ID_PERSONSHOP_CK_WIN,					// 이동
	ID_PERSONSHOP_CK_TEXT,					// 거래를 완료 하시겠습니까?
	ID_PERSONSHOP_CK_OK,					// 확인
	ID_PERSONSHOP_CK_CANCLE,				// 취소
	ID_PERSONSHOP_CK_MANAGER_ID,

	ID_PERSONSHOP_PR_BACKGROUND,			// 백그라운드
	ID_PERSONSHOP_PR_WIN,					// 이동
	ID_PERSONSHOP_PR_TEXT1,
	ID_PERSONSHOP_PR_TEXT2,
	ID_PERSONSHOP_PR_TEXT3,
	ID_PERSONSHOP_PR_OK,					// 확인
	ID_PERSONSHOP_PR_CANCLE,				// 취소
	//*/
	
	//======================================================================================================================//
	// 개인상점 - 끝
	//======================================================================================================================//


	ID_MYPLAYER_POP					= 3900,
	ID_MYPLAYER_BTN,

	ID_CHAT_POP						= 3910,
	ID_CHAT_POP_NAME,
	ID_CHAT_INVITE_PARTY_BTN,
	ID_CHAT_WHISPER_BTN,
	ID_CHAT_ADDFRIEND_BTN,
	ID_CHAT_BLOCK_BTN,

	ID_FRIENDLIST_POP				= 3920,
	ID_FRIENDLIST_INVITE_PARTY_BTN,
	ID_FRIENDLIST_WHISPER_BTN,
	ID_FRIENDLIST_BLOCK_BTN,
	ID_FRIENDLIST_DELETEFRIEND_BTN,

	ID_SEARCHFRIEND_POP				= 3930,
	ID_SEARCHFRIEND_INVITE_PARTY_BTN,
	ID_SEARCHFRIEND_WHISPER_BTN,
	ID_SEARCHFRIEND_ADDFRIEND_BTN,

	ID_BLOCKFRIEND_POP				= 3940,
	ID_BLOCKFRIEND_BLOCK_DELETE_BTN,
	ID_BLOCKFRIEND_DELETEFRIEND_BTN,

	ID_SEARCH_STATE_POP				= 3950,
	ID_SEARCH_STATE_NAME_BTN,
	ID_SEARCH_STATE_LV_BTN,
	ID_SEARCH_STATE_JOB_BTN,

	ID_PARTYBOSS_POP				= 3960,
	ID_PARTYBOSS_NAME,
	ID_PARTYBOSS_CHANGE_BOSS_BTN,
	ID_PARTYBOSS_WHISPER_BTN,
	ID_PARTYBOSS_ADDFRIEND_BTN,
	ID_PARTYBOSS_TRADE_BTN,
	ID_PARTYBOSS_BLOCK_BTN,
	ID_PARTYBOSS_OUT_BTN,

	ID_NOMAL_POP					= 3970,	
	ID_NOMAL_NAME,	
	ID_NOMAL_INVITE_PARTY_BTN,
	ID_NOMAL_WHISPER_BTN,
	ID_NOMAL_ADDFRIEND_BTN,
	ID_NOMAL_TRADE_BTN,
	ID_NOMAL_BLOCK_BTN,

	ID_PARTYBOSSFULL_POP			= 3980,
	ID_PARTYBOSSFULL_NAME,
	ID_PARTYBOSSFULL_WHISPER_BTN,
	ID_PARTYBOSSFULL_ADDFRIEND_BTN,
	ID_PARTYBOSSFULL_TRADE_BTN,
	ID_PARTYBOSSFULL_BLOCK_BTN,


	//======================================================================================================================//
	// 친구목록 - 시작
	//======================================================================================================================//
	ID_MESSENGER_BG					=	4000,

	ID_MESSENGER_BG_NAME,
	ID_MESSENGER_OFF_BTN,

	ID_MESSENGER_TAB1_BTN,		// 친구목록
	ID_MESSENGER_TAB2_BTN,		// 차단목록
	ID_MESSENGER_TAB3_BTN,		// 검색
	ID_MESSENGER_GROUP_TAB,

	ID_MESSENGER_NAME_BTN,		// 이름
	ID_MESSENGER_LV_BTN,		// 레벨
	ID_MESSENGER_STATE_BTN,		// 접속
	ID_MESSENGER_JOB_BTN,		// 직업

	ID_MESSENGER_LEFT_BTN,		
	ID_MESSENGER_RIGHT_BTN,
	ID_MESSENGER_PAGE_NUM,

	ID_MESSENGER_ADD_BTN,		// 등록
	ID_MESSENGER_DELETE_BTN,
	ID_MESSENGER_BLOCK_BTN,		// 차단

	ID_MESSENGER_FRIEND_NAME1,
	ID_MESSENGER_FRIEND_NAME2,
	ID_MESSENGER_FRIEND_NAME3,
	ID_MESSENGER_FRIEND_NAME4,
	ID_MESSENGER_FRIEND_NAME5,
	ID_MESSENGER_FRIEND_NAME6,
	ID_MESSENGER_FRIEND_NAME7,
	ID_MESSENGER_FRIEND_NAME8,
	ID_MESSENGER_FRIEND_NAME9,
	ID_MESSENGER_FRIEND_NAME10,
	ID_MESSENGER_FRIEND_LV1,
	ID_MESSENGER_FRIEND_LV2,
	ID_MESSENGER_FRIEND_LV3,
	ID_MESSENGER_FRIEND_LV4,
	ID_MESSENGER_FRIEND_LV5,
	ID_MESSENGER_FRIEND_LV6,
	ID_MESSENGER_FRIEND_LV7,
	ID_MESSENGER_FRIEND_LV8,
	ID_MESSENGER_FRIEND_LV9,
	ID_MESSENGER_FRIEND_LV10,
	ID_MESSENGER_FRIEND_STATE1,
	ID_MESSENGER_FRIEND_STATE2,
	ID_MESSENGER_FRIEND_STATE3,
	ID_MESSENGER_FRIEND_STATE4,
	ID_MESSENGER_FRIEND_STATE5,
	ID_MESSENGER_FRIEND_STATE6,
	ID_MESSENGER_FRIEND_STATE7,
	ID_MESSENGER_FRIEND_STATE8,
	ID_MESSENGER_FRIEND_STATE9,
	ID_MESSENGER_FRIEND_STATE10,
	ID_MESSENGER_FRIEND_BTN1,
	ID_MESSENGER_FRIEND_BTN2,
	ID_MESSENGER_FRIEND_BTN3,
	ID_MESSENGER_FRIEND_BTN4,
	ID_MESSENGER_FRIEND_BTN5,
	ID_MESSENGER_FRIEND_BTN6,
	ID_MESSENGER_FRIEND_BTN7,
	ID_MESSENGER_FRIEND_BTN8,
	ID_MESSENGER_FRIEND_BTN9,
	ID_MESSENGER_FRIEND_BTN10,
	ID_MESSENGER_FRIEND_GROUP,

	ID_MESSENGER_FINDFRIEND_TXT_BG,		// 친구찾기 이름입력 백그라운드
	ID_MESSENGER_FINDFORBTN,			// 이름 레벨 직업등 어떤걸로 찾을지? 버튼
	ID_MESSENGER_FINDFRIEND_TXT,		// 입력
	ID_MESSENGER_FINDFRIEND_BTN,		// 검색버튼


	ID_MESSENGER_POP_BG,
	ID_MESSENGER_POP_TXT,
	ID_MESSENGER_POP_OK_BTN,
	ID_MESSENGER_POP_CANCLE_BTN,

	ID_MESSENGER_BG_WIN,
	ID_MESSENGER_BG_TOATL,
	ID_MESSAGEER_MANAGER_ID,

	ID_ALLMAP_BG							= 4200,
	ID_ALLMAP_BTN_CLOSED,
	ID_ALLMAP_ME_POINT,
	ID_ALLMAP_QUEST_POINT,
	ID_ALLMAP_EXPLORATION_POINT,
	ID_ALLMAP_BOSS1_POINT,
	ID_ALLMAP_BOSS2_POINT,
	ID_ALLMAP_BOSS3_POINT,
	ID_ALLMAP_BOSS4_POINT,
	ID_ALLMAP_BOSS5_POINT,
	ID_ALLMAP_QUEST_BOSS_POINT,


	//======================================================================================================================//
	//내창고 - 시작
	//======================================================================================================================//	
	ID_WAREHOUSE_BACKGROUND					= 4300,		// 백그라운드
	ID_WAREHOUSE_BACKGROUND_CLOSE,						// 닫기
	ID_WAREHOUSE_NAME,

	// 내창고 슬롯
	ID_WAREHOUSE_SLOT_00,
	ID_WAREHOUSE_SLOT_01,
	ID_WAREHOUSE_SLOT_02,
	ID_WAREHOUSE_SLOT_03,
	ID_WAREHOUSE_SLOT_04,
	ID_WAREHOUSE_SLOT_05,
	ID_WAREHOUSE_SLOT_06,
	ID_WAREHOUSE_SLOT_07,
	ID_WAREHOUSE_SLOT_08,
	ID_WAREHOUSE_SLOT_09,
	ID_WAREHOUSE_SLOT_10,
	ID_WAREHOUSE_SLOT_11,
	ID_WAREHOUSE_SLOT_12,
	ID_WAREHOUSE_SLOT_13,
	ID_WAREHOUSE_SLOT_14,
	ID_WAREHOUSE_SLOT_15,
	ID_WAREHOUSE_SLOT_16,
	ID_WAREHOUSE_SLOT_17,
	ID_WAREHOUSE_SLOT_18,
	ID_WAREHOUSE_SLOT_19,
	ID_WAREHOUSE_SLOT_20,
	ID_WAREHOUSE_SLOT_21,
	ID_WAREHOUSE_SLOT_22,
	ID_WAREHOUSE_SLOT_23,
	ID_WAREHOUSE_SLOT_24,

	ID_WAREHOUSE_BACKGROUND_WIN,
	ID_WAREHOUSE_BACKGROUND_TOTAL,
	ID_WAREHOUSE_MANAGER_ID,
	//======================================================================================================================//
	//내창고 - 끝
	//======================================================================================================================//




	//======================================================================================================================//
	//퀘스트 - 시작
	//======================================================================================================================//
	/*quest*/
	ID_QUEST_BG								= 4500,
	ID_QUSET_TXT_NAME,
	ID_QUEST_CANCLE_BTN,

	ID_QUSET_PARTY_BTN,
	ID_QUSET_DELETE_BTN,
	
	ID_QUEST_NAME_TXT,

	ID_QUEST_STORY_NAME_TXT,
	ID_QUEST_STORY_TXT,

	ID_QUEST_NAME_UP_BTN,
	ID_QUEST_NAME_DOWN_BTN,

	ID_QUEST_STORY_UP_BTN,
	ID_QUEST_STORY_DOWN_BTN,

	ID_QUEST_PRESENTEXP_TXT,
	ID_QUEST_PRESENTGOLD_TXT,

	ID_QUEST_PRESENT1_IMAGE,
	ID_QUEST_PRESENT1_TXT,

	ID_QUEST_PRESENT2_IMAGE,
	ID_QUEST_PRESENT2_TXT,

	ID_QUEST_PRESENT3_IMAGE,
	ID_QUEST_PRESENT3_TXT,

	ID_QUEST_PRESENT4_IMAGE,
	ID_QUEST_PRESENT4_TXT,

	ID_QUSET_TXT_PAGE_TXT,

	ID_QUEST_WIN,

	ID_QUEST_BG_TOATL,
	ID_QUEST_MANAGER_ID,
	
	
	/* npc quest 대화 */
	ID_QUEST_NPC_BG							= 4600,

	ID_QUEST_NPC_NAME_TXT,				// 이름
	ID_QUEST_NPC_CANCLE_BTN,			// 닫기
	ID_QUEST_NPC_STORY_TXT,				// 안내문

	ID_QUEST_NPC_TALK1_BTN,				// 선택 버튼
	ID_QUEST_NPC_TALK2_BTN,
	ID_QUEST_NPC_TALK3_BTN,
	ID_QUEST_NPC_TALK4_BTN,
	ID_QUEST_NPC_TALK5_BTN,

	ID_QUEST_NPC_TALK1_IMAGE_COMP,			// 퀘스트 완료이미지
	ID_QUEST_NPC_TALK2_IMAGE_COMP,
	ID_QUEST_NPC_TALK3_IMAGE_COMP,
	ID_QUEST_NPC_TALK4_IMAGE_COMP,
	ID_QUEST_NPC_TALK5_IMAGE_COMP,


	ID_QUEST_NPC_TALK1_IMAGE_NEW,			// 새로운 퀘스트 이미지
	ID_QUEST_NPC_TALK2_IMAGE_NEW,
	ID_QUEST_NPC_TALK3_IMAGE_NEW,
	ID_QUEST_NPC_TALK4_IMAGE_NEW,
	ID_QUEST_NPC_TALK5_IMAGE_NEW,

	ID_QUEST_NPC_TALK1_IMAGE_ING,			// 진행중인 퀘스트 이미지
	ID_QUEST_NPC_TALK2_IMAGE_ING,
	ID_QUEST_NPC_TALK3_IMAGE_ING,
	ID_QUEST_NPC_TALK4_IMAGE_ING,
	ID_QUEST_NPC_TALK5_IMAGE_ING,

	ID_QUEST_NPC_TALK1_TXT,					// 문자열들
	ID_QUEST_NPC_TALK2_TXT,
	ID_QUEST_NPC_TALK3_TXT,
	ID_QUEST_NPC_TALK4_TXT,
	ID_QUEST_NPC_TALK5_TXT,

	ID_QUEST_NPC_STORY_IMAGE,
	ID_QUEST_NPC_STORY_IMAGE2,
	ID_QUEST_NPC_BG_WIN,
	ID_QUEST_NPC_BG_TOATL,
	ID_QUEST_NPC_MANAGER_ID,
	ID_QUEST_NPC_CONTAINER,

	/* quest_receive */
	ID_QUEST_REC_BG							= 4700,
	ID_QUEST_REC_NAME_TXT,
	ID_QUEST_REC_CANCLE_BTN,
	ID_QUEST_REC_STORY_TXT,

	ID_QUEST_REC_TITLE_TXT,
	ID_QUEST_REC_TOWN_TXT,

	ID_QUEST_REC_PRESENTEXP_TXT,
	ID_QUEST_REC_PRESENTGOLD_TXT,

	ID_QUEST_REC_PRESENT1_IMAGE,
	ID_QUEST_REC_PRESENT1_TXT,
	ID_QUEST_REC_PRESENT2_IMAGE,
	ID_QUEST_REC_PRESENT2_TXT,
	ID_QUEST_REC_PRESENT3_IMAGE,
	ID_QUEST_REC_PRESENT3_TXT,
	ID_QUEST_REC_PRESENT4_IMAGE,
	ID_QUEST_REC_PRESENT4_TXT,

	ID_QUEST_REC_CANCLE,
	ID_QUEST_REC_OK,
	ID_QUEST_REC_ACCEPT_BTN,
	ID_QUEST_REC_REJECT_BTN,	
	ID_QUEST_REC_BG_WIN,	
	ID_QUEST_REC_BG_TOATL,
	ID_QUEST_REC_MANAGER_ID,

	/* player pop */
	/*
	ID_PLAYER_POP_BG1				= 4750,
	ID_PLAYER_POP_BG4,
	ID_PLAYER_POP_BG5,
	ID_PLAYER_POP_BG6,
	ID_PLAYER_POP_BG7,
	ID_PLAYER_NAME,

	ID_PLAYER_BTN_INVITEPARTY,
	ID_PLAYER_BTN_PLAYEREXIT,
	ID_PLAYER_BTN_CHANGEMASTER,
	ID_PLAYER_BTN_WISHPER,
	ID_PLAYER_BTN_ADDFRIEND,
	ID_PLAYER_BTN_ADDBLOCK,
	ID_PLAYER_BTN_PARTYOUT,
	ID_PLAYER_BTN_TRADE,

	ID_PLAYER_TXT_INVITEPARTY,
	ID_PLAYER_TXT_PLAYEREXIT,
	ID_PLAYER_TXT_CHANGEMASTER,
	ID_PLAYER_TXT_WISHPER,
	ID_PLAYER_TXT_ADDFRIEND,
	ID_PLAYER_TXT_ADDBLOCK,
	ID_PLAYER_TXT_PARTYOUT,
	ID_PLAYER_TXT_TRADE,
	*/

	/* map select */
	ID_MAPSELECT_BG1						= 4800,
    ID_MAPSELECT_BG2,	
	ID_MAPSELECT_CLOSE_BTN,

	ID_MAPSELECT_BTN1,
	ID_MAPSELECT_BTN2,
	ID_MAPSELECT_BTN3,
	ID_MAPSELECT_BTN4,
	ID_MAPSELECT_BTN5,
	ID_MAPSELECT_BTN6,
	ID_MAPSELECT_BTN7,
	ID_MAPSELECT_BTN8,

	ID_MAPSELECT_GROUP1_BTN,
	ID_MAPSELECT_GROUP2_BTN,

    /* map setail panel */
    ID_MAPDETAIL_BG                 =4900,
    ID_MAPDETAIL_MANAGER_ID,
    ID_MAPDETAIL_BG_WIN,
    ID_MAPDETAIL_CONFIRM,
    ID_MAPDETAIL_CANCEL,
    ID_MAPDETAIL_TURNLEFT,
    ID_MAPDETAIL_TURNRIGHT,
    ID_MAPDETAIL_TXT_TITLE,
    ID_MAPDETAIL_TXT_DIFFCULT,
    ID_MAPDETAIL_TXT_MAPLV,
    ID_MAPDETAIL_TXT_SUGGESTLV,

    ID_MAPDETAIL_HEAD1,
    ID_MAPDETAIL_HEAD2,
    ID_MAPDETAIL_HEAD3,
    ID_MAPDETAIL_HEAD4,
    ID_MAPDETAIL_HEAD5,
    ID_MAPDETAIL_HEAD6,
    ID_MAPDETAIL_HEAD7,
    ID_MAPDETAIL_HEAD8,


	//부활
	ID_GAMERESURRECTION_BG		=	5400,
	ID_GAMERESURRECTION_TITLE,
	ID_GAMERESURRECTION_MSG1,
	ID_GAMERESURRECTION_MSG2,
	ID_GAMERESURRECTION_MSG3,
	ID_GAMERESURRECTION_OK,
	ID_GAMERESURRECTION_CENCLE,
    ID_GAMERESURRECTION_USE,
    ID_GAMERESURRECTION_RETRY,
    ID_GAMERESURRECTION_RETURNTOWN,
	ID_GAMERESURRECTION_BG_ICON,
	//======================================================================================================================//
	//퀘스트 - 끝
	//======================================================================================================================//




	//======================================================================================================================//
	// 결과창 -- 시작
	//======================================================================================================================//	
	ID_GAMERESULT_BACKGROUND1			=	5500,
	ID_GAMERESULT_BACKGROUND2,
	
	ID_GAMERESULT_FILED_KILL,				// 킬
	ID_GAMERESULT_FILED_ATACK,				// 공격
	ID_GAMERESULT_FILED_COUNTER,			// 카운터
	ID_GAMERESULT_FILED_DAMAGE,				// 데미지
	ID_GAMERESULT_FILED_DIE,				// 죽음		
	ID_GAMERESULT_FILED_EXP,				// 경험치
	ID_GAMERESULT_FILED_GOLD,				// 금전

	// 클리어
	ID_GAMERESULT_STAGE_CLEAR,
	ID_GAMERESULT_STAGE_FAIL,
	ID_GAMERESULT_WIN,
	ID_GAMERESULT_LOSE,
	ID_GAMERESULT_DRAW,

	// 등급
	ID_GAMERESULT_S,
	ID_GAMERESULT_A,
	ID_GAMERESULT_B,
	ID_GAMERESULT_C,
	ID_GAMERESULT_D,
	ID_GAMERESULT_E,
	ID_GAMERESULT_F,

	// 삼각형
	ID_GAMERESULT_TRIANGLE_BACKGROUND,		// 삼각형 백그라운드
	ID_GAMERESULT_ITEM_01,
	ID_GAMERESULT_ITEM_02,
	ID_GAMERESULT_ITEM_03,
	
	ID_GAMERESULT_NO_ITEM_01,
	ID_GAMERESULT_NO_ITEM_02,
	ID_GAMERESULT_NO_ITEM_03,

	ID_GAMERESULT_BUTTON_01,				// 위
	ID_GAMERESULT_BUTTON_02,				// 왼쪽
	ID_GAMERESULT_BUTTON_03,				// 오른쪽

	// 메뉴
	ID_GAMERESULT_MENU_BACKGROUND,			// 백그라운드
	ID_GAMERESULT_MENU_REGAME,				// 게임다시하기
	ID_GAMERESULT_MENU_TOWN,				// 마을로돌아가기
	ID_GAMERESULT_MENU_MAP,					// 맵선택

	ID_GAMERESULT_BG_KILL,				// 킬
	ID_GAMERESULT_BG_ATACK,				// 공격
	ID_GAMERESULT_BG_COUNTER,			// 카운터
	ID_GAMERESULT_BG_DAMAGE,				// 데미지
	ID_GAMERESULT_BG_DIE,				// 죽음		
	ID_GAMERESULT_BG_EXP,				// 경험치
	ID_GAMERESULT_BG_GOLD,				// 금전
	//===================================================================================================================//
	// 결과창 -- 끝
	//===================================================================================================================//



	//===================================================================================================================//
	// 제조창 -- 시작
	//===================================================================================================================//
	ID_CREATEITEM_BACKGROUND	=	5600,		// 백그라운드
	ID_CREATEITEM_MOVE,							// 움직여
	ID_CREATEITEM_NAEM,							// 이름
	ID_CREATEITEM_CLOSE,						// 닫기
	ID_CREATEITEM_FILD,							// 필드

	ID_CREATEITEM_IMAGE_BOOK,					// 제작서
	ID_CREATEITEM_ITEM_NUMBER,					// 제작서 아래 만들수 있는수
	ID_CREATEITEM_BOOK_NAME,					// 제작서이름
	ID_CREATEITEM_LEVEL,						// 필요레벨
	ID_CREATEITEM_SKILL,						// 필요숙련도
	ID_CREATEITEM_GOLD,							// 필요금액
	ID_CREATEITEM_INVISIBLE,					// 제작수수료
	ID_CREATEITEM_SPACE,						// 필요장소

	ID_CREATEITEM_ITEMIMAGE_00,					// 필요한재료
	ID_CREATEITEM_ITEMIMAGE_01,
	ID_CREATEITEM_ITEMIMAGE_02,
	ID_CREATEITEM_ITEMIMAGE_03,

	ID_CREATEITEM_ITEMNAME_00,					// 재료이름
	ID_CREATEITEM_ITEMNAME_01,
	ID_CREATEITEM_ITEMNAME_02,
	ID_CREATEITEM_ITEMNAME_03,

	ID_CREATEITEM_CURRENT_00,					// 재료갯수
	ID_CREATEITEM_CURRENT_01,
	ID_CREATEITEM_CURRENT_02,
	ID_CREATEITEM_CURRENT_03,

	ID_CREATEITEM_PROGRESS,						// 프로그래스바

	ID_CREATEITEM_LEFT,							// 만들갯수 왼쪽
	ID_CREATEITEM_RIGHT,						// 만들갯수 오른쪽
	ID_CREATEITEM_TEXT,							// 갯수

	ID_CREATEITEM_MAKE,							// 만들기
	ID_CREATEITEM_ALLMAKE,						// 모두만들기

	ID_CREATEITEM_CANCLE,						// 취소

	ID_CREATEiTEM_TOTAL,
	ID_CREATEITEM_MANAGER_ID,					// 고유아이디
	//===================================================================================================================//
	// 제조창 -- 끝
	//===================================================================================================================//


	//===================================================================================================================//
	// 제조창 경고창 -- 시작
	//===================================================================================================================//
	// 주의창
	ID_CREATEITEM_CHOICE_BAKCGROUND = 5700,	// 백그라운
	ID_CREATEITEM_CHOICE_MOVE,				// 이동
	ID_CREATEITEM_CHOICE_NAME,				// 이름
	ID_CREATEITEM_CHOICE_CLOSE,				// 닫기

	ID_CREATEITEM_CHOICE_GROUP,
	ID_CREATEITEM_CHOICE_EFF_SUF,			// 효과/재료
	ID_CREATEITEM_CHOICE_SHI_ACC,			// 방어구/악세서리
	ID_CREATEITEM_CHOICE_ATT_PAT,			// 무기/펫

	ID_CREATEITEM_CHOICE_OK,				// 확인

	ID_CREATEITEM_CHOICE_TOTAL,
	ID_CREATEITEM_CHOICE_MANAGER_ID,

	// 확인창
	ID_CREATEITEM_QUESTION_BACKGROUND,		// 백그라운드
	ID_CREATEITEM_QUESTION_TEXT,			// 텍스트
	ID_CREATEITEM_QUESTION_OK,				// 확인
	ID_CREATEITEM_QUESTION_CANCLE,			// 취소
	//===================================================================================================================//
	// 제조창 경고창 -- 끝
	//===================================================================================================================//



	//===================================================================================================================//
	// 머리위 에너지 -- 시작
	//===================================================================================================================//
	ID_HEAD_ENERGY_CHAR_0			= 5800,
	ID_HEAD_ENERGY_CHAR_1,
	ID_HEAD_ENERGY_CHAR_2,
	ID_HEAD_ENERGY_CHAR_3,

	ID_HEAD_EP_CHAR_0,
	ID_HEAD_EP_CHAR_1,
	ID_HEAD_EP_CHAR_2,
	ID_HEAD_EP_CHAR_3,

	ID_HEAD_ENERGY_ENEMY_0,
	ID_HEAD_ENERGY_ENEMY_1,
	ID_HEAD_ENERGY_ENEMY_2,
	ID_HEAD_ENERGY_ENEMY_3,

	ID_HEAD_EP_ENEMY_0,
	ID_HEAD_EP_ENEMY_1,
	ID_HEAD_EP_ENEMY_2,
	ID_HEAD_EP_ENEMY_3,

	ID_HEAD_ENERGY_TAGET,
	ID_HEAD_EP_TAGET,
	//===================================================================================================================//
	// 머리위 에너지 -- 끝
	//===================================================================================================================//


	// 스킬 공용	
	ID_SKILLICON_START			=	100000,
	ID_SKILLICON_RECEIVE_SLOT	=	300000,
	ID_BUFFICON_START			=	500000,
	ID_SKILLICON_TEAM_START		=	600000,
	ID_BUFFICON_START_ME		=	700000,
	



	// ToolTip
	ID_TOOLTIP_SHOP1				=	90000,
	ID_TOOLTIP_SHOP2				=	90001,
	ID_TOOLTIP_BAG1					=	90002,
	ID_TOOLTIP_BAG2					=	90003,
	ID_TOOLTIP_CHAREQITEM			=	90004,
	ID_TOOLTIP_REINFORCE			=   90005,
	ID_TOOLTIP_RECHATGE				=   90006,
	ID_TOOLTIP_RRD					=   90007,
	ID_TOOLTIP_BPSHOP				=	90008,
	ID_TOOLTIP_WAREHOUSE			=	90009,
	ID_TOOLTIP_PERSONBUY			=	90010,
	ID_TOOLTIP_BUFF					=	90011,
	ID_GAMETOOLTIP					=	90012,
	ID_PERSONSHOP_TIP				=	90013,
	ID_TOOLTIP_WORLDMAP				=   90014,	
	ID_QUEST_TIP					=	90015,
	ID_REQUEST_TIP					=	90016,
	ID_TOOLTIP_CREATEITEM			=   90017,
	ID_TOOLTIP_COMPARE			=   90018,

	
	// Modal Dialog
	ID_LOBBY_MODAL_BKGND			=	30000,
	ID_LOBBY_MODAL_MSGFIELD			=	30001,
	ID_LOBBY_MODAL_CONFIRM			=	30002,
	ID_LOBBY_MODAL_CANCEL			=	30003,


	// buyItem
	ID_LOBBY_BUYITEM_MSG1			=	30005,
	ID_LOBBY_BUYITEM_MSG2			=	30006,
	ID_LOBBY_BUYITEM_MSG3			=	30007,
	ID_LOBBY_BUYITEM_BG				=	30008,
	ID_LOBBY_BUYITEM_BUYCONFIRM		=	30009,
	ID_LOBBY_BUYITEM_BUYCANCEL		=	30010,

	// Leaving
	ID_LOBBY_MODAL_LEAV_BKGND			=	30011,
	ID_LOBBY_MODAL_LEAV_MSGFIELD		=	30012,
	ID_LOBBY_MODAL_LEAV_CONFIRM			=	30013,
	ID_LOBBY_MODAL_LEAV_CANCEL			=	30014,
	ID_LOBBY_MODAL_LEAV_MSGFIELD_P		=	30015,


};

#define  YB_MODAL_OK					0x00000001
#define  YB_MODAL_CANCEL				0x00000010

void CALLBACK OnGUIEvent_LobbyUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);
typedef VOID (CALLBACK *PCALLBACKEXTRENDER) (IDirect3DDevice9* pDevice, RECT* rc );

enum // 메시지박스가 떠있을때, 상태를 알기위한 변수
{
	MSGBOX_CHARACTER_DELETE = 0,		// 캐릭터 삭제
	MSGBOX_ITEM_BUY,
	MSGBOX_GAMEOVER,
	MSGBOX_UNVISIBLE,
	MSGBOX_P2P_INIT,
	MSGBOX_REINFORCE,
	MSGBOX_CHARGE,
	MSGBOX_LOGINFAILED,
	MSGBOX_SERVER_CONNECTION_LOST,
	MSGBOX_ROOMLIST,
	MSGBOX_TOWNJOIN, // 마을 조인
	MSGBOX_QUEST_ACCEPT,	// 퀘스트수락
	MSGBOX_QUEST_GIVEUP,	// 퀘스트포기
	MSGBOX_QUEST_ACCEPT_YN, // 퀘스트 수락 질문
	MSGBOX_QUEST_GIVEUP_YN, // 퀘스트 포기 질문
	MSGBOX_QUEST_MENU_GIVEUP_YN,	 // 글로벌 퀘스트버튼 포기 질문창
	MSGBOX_QUEST_ITEM_SELL_YN,		// 아이템 팔기
	MSGBOX_TOWN_MOVE,				// 마을로이동
	MSGBOX_ITEM_DELETE,				// 아이템 삭제
	MSGBOX_CHARACTER_DELETE_ACCEPT,	// 캐릭터 삭제후 서버응답
	MSGBOX_QUESTVIEW,				// 게임룸에서 사운드 출력
	MSGBOX_ERROR_DECOM,				// 분해하기 오류
};

typedef enum LOBBY_STATE
{
	LS_EVENT,				// 이벤트 화면
	LS_SELECT_CHAR,			// 캐릭터 선택
	LS_CREATE_CHAR,			// 캐릭터 생성
	LS_ROOM_LIST,			// 방리스트
	LS_MAKE_ROOM,			// 방만들기
	LS_VERSUS,				// 대전방
	LS_MONSTERKILL,			// 몬스터킬
	LS_QUEST,				// 퀘스트

	LS_MYBAG,				// 내가방(보통)
	LS_SKILL,				// 내가방(스킬아이콘)
	LS_SHOPLIST,			// 상점리스트1
	LS_SKILLSHOPLIST,			// 상점리스트2(스킬)
	LS_OPTION,				// 옵션
	LS_STORYQUEST,			// 스토리퀘스트
	LS_TOWN,				// 마을
	LS_SHOPSTATE,           // 전장상점( 전체 scene )
	LS_REINFORCE,			// 강화창
	LS_ILLUST,				// 생성창 일러스트
}; // LOBBY_STATE


typedef enum STATE_REINFORCE	
{
	STATE_1_REINFORCE = 0,		// 강화
	STATE_2_RECHARGE,			// 수리				
	STATE_3_DECOMPOSE,			// 분해

	STATE_RRD_NONE		= 255,		// 초기화


	REINFORCE_NONE = 100,
	REINFORCE_TRUE,
	REINFORCE_FALSE,
};


typedef enum STATE_SKILL		// 무공창
{
	SKILL_WHOLE = 1,				// 전체
	SKILL_COMMON = 255,				// 공통
	SKILL_GENERAL = 253,			// 일반
	SKILL_EXCLUSIVE = 100,			// 전용
	SKILL_PET = 9,					// 펫
	SKILL_NONE = -1,				// 없다
};


class yb_LobbyUIControl
{
protected:
	ANW::StatusUI_Manager		*m_pUiTest_1;
	ANW::StatusUI_Manager		*m_pUiTest_2;

protected:

	// LOAD
	bool				loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename);	

public:		
	bool				loadUI_All();
	VOID				Clear_All();
	void				setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback);	

	void				FrameMove(DWORD dwElapsedTime);	
	void				render(IDirect3DDevice9* pDevice);

	
public:
	yb_LobbyUIControl();
	~yb_LobbyUIControl();


}; // class yb_LobbyUIControl


#endif // _YB_LOBBY_ID_H_