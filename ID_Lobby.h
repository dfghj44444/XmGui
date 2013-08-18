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
	// ĳ���� ���� - ����
	//======================================================================================================================//		
	ID_LOBBY_SELECT_BACKGROUND				= 100,				// ����̹���


	ID_SELECT_CHARACTER_TYPE_CW,								// û�� 2D�Ϸ���Ʈ
	ID_SELECT_CHARACTER_TYPE_GR,								// ���� 2D�Ϸ���Ʈ
	ID_SELECT_CHARACTER_TYPE_PR,								// �и� 2D�Ϸ���Ʈ
	ID_SELECT_CHARACTER_TYPE_SW,								// �ҿ� 2D�Ϸ���Ʈ


	ID_SELECT_CHARACTER_BACK,									// ����
		
	ID_LOBBY_RUN_CHAR,											// ����
	ID_LOBBY_DEL_CHAR,											// ����
	ID_SELECT_CREATE,											// ����
	ID_SELECT_BACK,												// �ڷΰ���
	ID_LOBBY_GAME_EXIT,											// ������
	ID_SELECT_TURN_DM,												// ĳ��ȸ������
	ID_SELECT_TURN_ZL,												// ĳ��ȸ������
	ID_SELECT_TURN_ST,												// ĳ��ȸ������
	ID_SELECT_TURN_MT,												// ĳ��ȸ������
	ID_SELECT_TURN_NON,												// ĳ��ȸ������

	ID_SELECT_TURN_LEFT_DM,												// ĳ��ȸ������
	ID_SELECT_TURN_LEFT_ZL,												// ĳ��ȸ������
	ID_SELECT_TURN_LEFT_ST,												// ĳ��ȸ������
	ID_SELECT_TURN_LEFT_MT,												// ĳ��ȸ������
	ID_SELECT_TURN_LEFT_NON,

	ID_SELECT_TURN_RIGHT_DM,												// ĳ��ȸ������
	ID_SELECT_TURN_RIGHT_ZL,												// ĳ��ȸ������
	ID_SELECT_TURN_RIGHT_ST,												// ĳ��ȸ������
	ID_SELECT_TURN_RIGHT_MT,												// ĳ��ȸ������
	ID_SELECT_TURN_RIGHT_NON,												// ĳ��ȸ������

	ID_LOBBY_INFORMATION_FILD,								// ���� ��׶���
	ID_LOBBY_INFORMATION_BACKGROUND,						// ���� ��׶���
	ID_LOBBY_INFORMATION_TEXTURE,							// ĳ�������� �ؽ��� ��׶���

	ID_LOBBY_EXP_LEVEL,										// LV
	ID_LOBBY_EXP_NAME,										// �̸�
	
	ID_LOBBY_INFORMATION_WORK,								// ����
	ID_LOBBY_INFORMATION_GUILD,								// ���
	ID_LOBBY_INFORMATION_CLASS,								// ���	
	ID_LOBBY_INFORMATION_TOTAL_RESULT,						// ��ü����
	ID_LOBBY_INFORMATION_TODAY_RESULT,						// ��������		
	ID_LOBBY_INFORMATION_TOTAL_PERCENT,						// ���Ͻ·�
	ID_LOBBY_INFORMATION_TODAY_PERCENT,						// ��ü�·�

	ID_SELECT_CHARACTER_NON,								// ĳ���� ����

	
	//======================================================================================================================//
	// ĳ���� ���� - ��
	//======================================================================================================================//	


	//======================================================================================================================//
	// ĳ���� ����â - ����
	//======================================================================================================================//	
	//�Ϸ���Ʈ
	ID_LOBBY_CREATECHAR_CHARACTER_CW = 200,				// û���Ϸ���Ʈ
	ID_LOBBY_CREATECHAR_CHARACTER_GR,					// ����
	ID_LOBBY_CREATECHAR_CHARACTER_PR,
	ID_LOBBY_CREATECHAR_CHARACTER_SW,					// �ҿ�
		

	ID_LOBBY_CREATECHAR_IllUSTCANCLE,					// ��ҹ�ư


	// ����
	ID_LOBBY_CREATECHAR_BACKGROUND,						// ��׶��� ��ü
	ID_CREATECHAR_CHAR_BACK_CW,							// 3D�ڿ� �׷����� 2D�Ϸ���Ʈ
	ID_CREATECHAR_CHAR_BACK_GR,							// 3D�ڿ� �׷����� 2D�Ϸ���Ʈ
	ID_CREATECHAR_CHAR_BACK_PR,							// 3D�ڿ� �׷����� 2D�Ϸ���Ʈ
	ID_CREATECHAR_CHAR_BACK_SW,							// 3D�ڿ� �׷����� 2D�Ϸ���Ʈ

	ID_CREATECHAR_BACK,									// ����

	ID_LOBBY_CREATECHAR_ROTATIONLEFT,					// ȸ�� ����
	ID_LOBBY_CREATECHAR_ROTATIONRIGHT,					// ȸ�� ������
	

	ID_CREATECHAR_FILE,									// �̸� �� �Ӹ���� �Ӹ��� �ʵ�
	ID_CREATECHAR_NAME_BACKGROUND,						// �̸� ��׶���
	ID_CREATECHAR_NAME_FILD,							// �̸��Է��ʵ�
	ID_LOBBY_CREATECHAR_INPUTID,						// �̸��Է�

	
	ID_CREATECHAR_FACE_BACKGROUND,						// �� �ؽ��� 
	ID_CREATECHAR_HEAD_BACKGROUND,						// �Ӹ���� �ؽ��� 
	ID_CREATECHAR_COLOR_BACKGROUND,						// �Ӹ��� �ؽ��� 

	ID_CREATECHAR_FILE2,								// ��빫��, ĳ���� Ư¡ �ʵ�
	ID_CREATECHAR_ATTACK_BACKGROUND,						// ��빫�� �ؽ���
	ID_CREATECHAR_CHARDESC_BACKGROUND,						// ĳ���� Ư¡


	//////////////////////////////////////////////////////////////////////////
	// ��
	ID_CREATECHAR_FACE_CW_GROUP,
	ID_CREATECHAR_FACE_GR_GROUP,
	ID_CREATECHAR_FACE_PR_GROUP,
	ID_CREATECHAR_FACE_SW_GROUP,
	// û��
	ID_LOBBY_CREATECHAR_FACE_C0,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_C1,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_C2,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_C3,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_C4,						// ��Image

	//ä����
	ID_LOBBY_CREATECHAR_FACE_G0,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_G1,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_G2,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_G3,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_G4,						// ��Image

	// �и�
	ID_LOBBY_CREATECHAR_FACE_P0,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_P1,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_P2,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_P3,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_P4,						// ��Image

	//��ҿ�
	ID_LOBBY_CREATECHAR_FACE_S0,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_S1,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_S2,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_S3,						// ��Image
	ID_LOBBY_CREATECHAR_FACE_S4,						// ��Image


	//////////////////////////////////////////////////////////////////////////
	// �Ӹ�
	ID_CREATECHAR_HEAD_CW_GROUP,
	ID_CREATECHAR_HEAD_GR_GROUP,
	ID_CREATECHAR_HEAD_PR_GROUP,
	ID_CREATECHAR_HEAD_SW_GROUP,
	// û��
	ID_LOBBY_CREATECHAR_HEAD_C0,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_C1,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_C2,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_C3,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_C4,						// �Ӹ�Image

	// ä����
	ID_LOBBY_CREATECHAR_HEAD_G0,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_G1,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_G2,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_G3,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_G4,						// �Ӹ�Image

	// �и�
	ID_LOBBY_CREATECHAR_HEAD_P0,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_P1,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_P2,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_P3,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_P4,						// �Ӹ�Image
	//��ҿ�
	ID_LOBBY_CREATECHAR_HEAD_S0,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_S1,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_S2,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_S3,						// �Ӹ�Image
	ID_LOBBY_CREATECHAR_HEAD_S4,						// �Ӹ�Image

	
	ID_LOBBY_CREATECHAR_HEADCOLOR_GROUP,
	ID_LOBBY_CREATECHAR_HEADCOLOR_00,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_01,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_02,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_03,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_04,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_05,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_06,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_07,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_08,						// �Ӹ���
	ID_LOBBY_CREATECHAR_HEADCOLOR_09,						// �Ӹ���

	ID_LOBBY_CREATE_BACKGROUND1,							// ����̹���
	ID_LOBBY_CREATE_BACKGROUND2,							// ����̹���

	// ��빫��
	ID_LOBBY_CREATECHAR_CW,
	ID_LOBBY_CREATECHAR_GR,
	ID_LOBBY_CREATECHAR_PR,
	ID_LOBBY_CREATECHAR_SW,

	ID_LOBBY_CREATECHAR_CHARDESC,							// ���� ĳ��

	ID_LOBBY_CREATECHAR_CONFIRM,						// Ȯ��
	ID_LOBBY_CREATECHAR_CANCEL,							// ���

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
	/* �������� POPâ ���� �̳Ѱ� */
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
	// ĳ���� ����â - ��
	//======================================================================================================================//	



	//======================================================================================================================//
	// ���� ����â - ����
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
	// ���� ����â - ��
	//======================================================================================================================//	


	//======================================================================================================================//
	// �κ� ��׶��� - ����
	//======================================================================================================================//	
	// �̴ϸ�
	ID_BACK_MINIMAP						= 6000,		// �̴ϸ�
	ID_BACK_MINIMAP_NAME,							// �̸�
	ID_BACK_MINIMAP_PLUS,							// �÷�����ư
	ID_BACK_MINIMAP_CLOSE,							// �����ư
	ID_BACK_MINIMAPE_BACKGROUND_S,

	ID_BACK_MINIMAP_TIME_BACKGROUND1,				// �ð� ����
	ID_BACK_MINIMAP_TIME_BACKGROUND2,				// �ð� �𷡽ð�
	ID_BACK_MINIMAP_TIME,							// �ð�
	
	// ������
	ID_BACK_MYENERGY_BACKGROUND,					// MY ������ ��׶���
	ID_BACK_MYENERGY_FACE,							// ��
	ID_BACK_MYENERGY_LV,							// ����
	ID_BACK_MYENERGY_NAME,							// �̸�
	ID_BACK_MYENERGY_ENERGY,						// ��������
	ID_BACK_MYENERGY_STAMINA,						// ���׹̳�
	ID_REAL_ENERGY_MY_1,							// ���
	ID_REAL_ENERGY_MY_1_S,							// ���׹̳�
	ID_REAL_ENERGY_MY_1_ALPHA,						// ���
	ID_REAL_ENERGY_MY_1_ALPHA_S,					// ���׹̳�

	// Ÿ��
	ID_BACK_TAGET_BACKGROUND1,						// ��׶���	
	ID_BACK_TAGET_LV,								// ����
	ID_BACK_TAGET_NAEM,								// �̸�
	
	// ����
	ID_BACK_TAGET_BACKGROUND_BOSS,						// ������ ��
	ID_BACK_TAGET_ENERGY_BOSS,							// ������	
	ID_REAL_ENERGY_TAGET_BOSS,							// �ǽð�
	ID_REAL_ENERGY_TAGET_AlPHA_BOSS,					// ����

	// ����
	ID_BACK_TAGET_BACKGROUND_ELITE,						// ������ ��
	ID_BACK_TAGET_ENERGY_ELITE,							// ������	
	ID_REAL_ENERGY_TAGET_ELITE,							// �ǽð�
	ID_REAL_ENERGY_TAGET_AlPHA_ELITE,					// ����

	// �Ϲ�
	ID_BACK_TAGET_BACKGROUND_GENERAL,						// ������ ��
	ID_BACK_TAGET_ENERGY_GENERAL,							// ������	
	ID_REAL_ENERGY_TAGET_GENERAL,							// �ǽð�
	ID_REAL_ENERGY_TAGET_AlPHA_GENERAL,					// ����

	ID_BACK_TAGET_BACKGROUND_MENTAL,						// ������ ��
	ID_BACK_TAGET_ENERGY_MENTAL,							// ������	
	ID_REAL_ENERGY_TAGET_MENTAL,							// �ǽð�
	ID_REAL_ENERGY_TAGET_AlPHA_MENTAL,					// ����

	ID_BACK_TAGET_BACKGROUND_NPC,							// NPC Player

	// ��Ƽ
	ID_BACK_PARTY_BACKGROUND1,						// ��׶���
	ID_BACK_PARTY_FACE1,							// ��
	ID_BACK_PARTY_LV1,								// ����
	ID_BACK_PARTY_NAME1,							// �̸�
	ID_BACK_PARTY_ENERGY1,							// ������
	ID_BACK_PARTY_STAMINA1,							// ���׹̳�

	ID_BACK_PARTY_BACKGROUND2,						// ��׶���
	ID_BACK_PARTY_FACE2,							// ��
	ID_BACK_PARTY_LV2,								// ����
	ID_BACK_PARTY_NAME2,							// �̸�
	ID_BACK_PARTY_ENERGY2,							// ������
	ID_BACK_PARTY_STAMINA2,							// ���׹̳�

	ID_BACK_PARTY_BACKGROUND3,						// ��׶���	
	ID_BACK_PARTY_FACE3,							// ��	
	ID_BACK_PARTY_LV3,								// ����	
	ID_BACK_PARTY_NAME3,							// �̸�	
	ID_BACK_PARTY_ENERGY3,							// ������
	ID_BACK_PARTY_STAMINA3,							// ���׹̳�

	ID_BACK_PARTY_BACKGROUND4,						// ��׶���
	ID_BACK_PARTY_FACE4,							// ��
	ID_BACK_PARTY_LV4,								// ����
	ID_BACK_PARTY_NAME4,							// �̸�
	ID_BACK_PARTY_ENERGY4,							// ������
	ID_BACK_PARTY_STAMINA4,							// ���׹̳�

	// �ǽð� ������
	ID_REAL_ENERGY_PARTY_1,							// ��Ƽ
	ID_REAL_ENERGY_PARTY_2,
	ID_REAL_ENERGY_PARTY_3,	
	ID_REAL_ENERGY_PARTY_1_S,						// ��Ƽ ���׹̳�
	ID_REAL_ENERGY_PARTY_2_S,
	ID_REAL_ENERGY_PARTY_3_S,

	ID_REAL_ENERGY_PARTY_1_ALPHA,					// ��Ƽ
	ID_REAL_ENERGY_PARTY_2_ALPHA,
	ID_REAL_ENERGY_PARTY_3_ALPHA,	
	ID_REAL_ENERGY_PARTY_1_ALPHA_S,					// ��Ƽ ���׹̳�
	ID_REAL_ENERGY_PARTY_2_ALPHA_S,
	ID_REAL_ENERGY_PARTY_3_ALPHA_S,


	ID_BACK_CHATTING_MENU_BG,						// ��׶��� ( �Ϲ�,��ħ,��ü,���,�ӼӸ�,NPC,�ý��� )
	ID_BACK_CHATTING_MENU_COMMON,					// �Ϲ�
	ID_BACK_CHATTING_MENU_SCREAM,					// ��ħ
	ID_BACK_CHATTING_MENU_TOTALY,					// ��ü
	ID_BACK_CHATTING_MENU_GUILD,					// ���
	ID_BACK_CHATTING_MENU_WHISPER,					// �ӼӸ�	
	ID_BACK_CHATTING_MENU_SYSTEM,					// �ý���
	ID_BACK_CHATTING_MENU_NPC,						// npc

	ID_BACK_CHATTING_LIST_BG,						// ä�� ����Ʈ ��׶���
	ID_BACK_CHATTING_INPUT_BG,						// ä�� �Է� ��׶���
	ID_BACK_CHATTING_INPUT,							// ä�� �Է�
	ID_BACK_CHATTING_LIST,							// ä�� ����Ʈ

	ID_BACK_CHATTING_BUTTON_TYPE,					// ��ȭ Ÿ��

	ID_BACK_CHATTING_BUTTON_TYPECHICE0,				// �Ϲ�
	ID_BACK_CHATTING_BUTTON_TYPECHICE1,				// ��ħ
	ID_BACK_CHATTING_BUTTON_TYPECHICE2,				// ��ü
	ID_BACK_CHATTING_BUTTON_TYPECHICE3,				// ���
	ID_BACK_CHATTING_BUTTON_TYPECHICE4,				// �Ӹ�

	ID_BACK_CHATTING_BUTTON_EMOTION,
	ID_BACK_CHATTING_BUTTON_HIDE,

	ID_BACK_CHATTING_BUTTON_NORMAL_MODE,
	ID_BACK_CHATTING_BUTTON_SYSTEM_MODE,
	ID_BACK_CHATTING_MODE_GROUP,
		
	ID_BACK_BACKGROUND1,							// ��� ǥ��(����ġ)
	ID_BACK_EXP,									// ����ġ
	ID_BACK_BACKGROUND2,							// ����ġ ��׶���
	
	ID_BACK_CHANNEL,								// ä��ǥ��

	ID_BACK_ENERGY,									// ������
	ID_BACK_STAMINA,								// ���׹̳�	
	ID_REAL_ENERGY_MY_2,							// �ϴ�
	ID_REAL_ENERGY_MY_2_S,							// ���׹̳�
	ID_REAL_ENERGY_MY_2_ALPHA,						// �ϴ�
	ID_REAL_ENERGY_MY_2_ALPHA_S,					// ���׹̳�	

	ID_SKILLICON_BACKGROUND,


	ID_SKILLICON_MAINGAME_POS01,					//��ų
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


	ID_SKILLICON_MAINGAME_POSA,						// ������ų
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

	

	// �� ������
	ID_PAT_BACKGROUND,								// pat ��׶���
	ID_PAT_ENERGY,									// ������

	// ����
	ID_BUFF_CHAR00_00,								// �ڱ��ڽ�
	ID_BUFF_CHAR00_01,
	ID_BUFF_CHAR00_02,
	ID_BUFF_CHAR00_03,
	ID_BUFF_CHAR00_04,

	ID_BUFF_CHAR01_00,								// ��Ƽ�� 1
	ID_BUFF_CHAR01_01,
	ID_BUFF_CHAR01_02,
	ID_BUFF_CHAR01_03,
	ID_BUFF_CHAR01_04,

	ID_BUFF_CHAR02_00,								// ��Ƽ�� 2
	ID_BUFF_CHAR02_01,
	ID_BUFF_CHAR02_02,
	ID_BUFF_CHAR02_03,
	ID_BUFF_CHAR02_04,

	ID_BUFF_CHAR03_00,								// ��Ƽ�� 3
	ID_BUFF_CHAR03_01,
	ID_BUFF_CHAR03_02,
	ID_BUFF_CHAR03_03,
	ID_BUFF_CHAR03_04,

	ID_BUFF_CHAR04_00,								// Ÿ��
	ID_BUFF_CHAR04_01,
	ID_BUFF_CHAR04_02,
	ID_BUFF_CHAR04_03,
	ID_BUFF_CHAR04_04,

	// ��Ȱ�ð�
	ID_CHAR0_REGENTIME,
	ID_CHAR1_REGENTIME,
	ID_CHAR2_REGENTIME,
	ID_CHAR3_REGENTIME,	

	// ����Ʈ �˸�
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
	
	// ����ǥ��
	ID_PARTY_MASTER_00,
	ID_PARTY_MASTER_01,
	ID_PARTY_MASTER_02,
	ID_PARTY_MASTER_03,
	ID_PARTY_MASTER_04,
	// ����������
	ID_MODE_BATTLE,

	// �˸��޽���
	ID_MESSAGE_TEXT,

	// ���θ޴�
	ID_BACK_MAIN_MENU_INFORMATION,					// ĳ������
	ID_BACK_MAIN_MENU_SKILL_CONTROL,				// ����â
	ID_BACK_MAIN_MENU_MYBAG,						// ������
	ID_BACK_MAIN_MENU_QUEST,						// ����Ʈ
	ID_BACK_MAIN_MENU_PETSONSHOP,					// ���λ���
	ID_BACK_MAIN_MENU_FRIEND_CONTROL,				// ģ������
	ID_BACK_MAIN_MENU_GUILD,						// ���
	ID_BACK_MAIN_MENU_CHSHSHOP,						// ĳ������	
	ID_BACK_MAIN_MENU_SYSTEM,						// �ý���
	ID_BACK_MAIN_MENU_HIDE,

	// ��ȯ��
	ID_SUMMONS_BACKGROUND,
	ID_SUMMONS_LV,
	ID_SUMMONS_NAME,
	ID_SUMMONS_ENERGY,

	// ���̶���Ʈ
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


	// �����
	ID_WORLDMAP_BACKGROUND = 697,							// ��׶���	
	ID_WORLDMAP_NAEM = 698,									// �̸�
	ID_WORLDMAP_CLOSE = 699,								// �ݱ�
	//======================================================================================================================//
	// �κ� ��׶��� - ��
	//======================================================================================================================//	



	//======================================================================================================================//
	//������ - ����
	//======================================================================================================================//	
	ID_MYBAG_BACKGROUND					= 700,		// ��׶���

	ID_MYBAG_BACKGROUND_NAME,						// �̸�
	ID_MYBAG_BACKGROUND_CLOSE,						// �ݱ�

	// ������ ������ư
	ID_MYBAG_RADIOBUTTON_GROUP,
	ID_MYBAG_RADIOBUTTON_PERSON,					// ���
	ID_MYBAG_RADIOBUTTON_PERSONEX,				// �Ҹ�
	ID_MYBAG_RADIOBUTTON_QUEST,						// ����Ʈ
	ID_MYBAG_RADIOBUTTON_STUFF,						// ���
	ID_MYBAG_RADIOBUTTON_5,
	ID_MYBAG_RADIOBUTTON_6,

	ID_MYBAG_BG_GOLD,						// �ݾ� �ؽ�Ʈ
	ID_MYBAG_G_GOLD,						// �ݾ� �ؽ�Ʈ
	ID_MYBAG_Y_GOLD,						// �ݾ� �ؽ�Ʈ
	ID_MYBAG_T_GOLD,						// �ݾ� �ؽ�Ʈ

	// ������ ����
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

	// ����
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
	//������ - ��
	//======================================================================================================================//


	//======================================================================================================================//
	// ����â - ����
	//======================================================================================================================//
	ID_SKILL_BACKGROUND				= 8000,	// ��׶���
	ID_SKILL_BACKGROUND_WIN,					// MOVE
	ID_SKILL_BACKGROUND_FILD,					// �ʵ�


	ID_SKILL_BACKGROUND_NAME,					// �̸�
	ID_SKILL_BACKGROUND_CLOSE,					// �ݱ�
	ID_SKILL_BACKGROUND_CANCEL,


	// �����
	ID_SKILL_TAB_GROUP,
	ID_SKILL_TAB_SKILL,							// ��ų
	ID_SKILL_TAB_CREATEITEM,					// ����

	// ����
	ID_SKILL_CREATEITEM_GROUP,
	ID_SKILL_CREATEITEM_EFFECT,					// ȿ��
	ID_SKILL_CREATEITEM_STUFF,					// ���

	ID_SKILL_CREATEITEM_SHD,					// ��
	ID_SKILL_CREATEITEM_ACC,					// ��ű�

	ID_SKILL_CREATEITEM_ATT,					// ����
	ID_SKILL_CREATEITEM_PET,					// Ż��

	ID_SKILL_CREATEITEM_COMMON,					// ����

	// ����â ������ư
	// û��
	ID_SKILL_RADIOBUTTON_CW_GROUP,		
	ID_SKILL_RADIOBUTTON_CW_1,					// ����
	ID_SKILL_RADIOBUTTON_CW_2,					// ����
	ID_SKILL_RADIOBUTTON_CW_3,					// ��ȣ
	ID_SKILL_RADIOBUTTON_CW_4,
	ID_SKILL_RADIOBUTTON_CW_COMMON,				// ����
	ID_SKILL_RADIOBUTTON_CW_SPECIAL1,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL2,
	ID_SKILL_RADIOBUTTON_CW_COMMON_TREE,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL_TREE1,
	ID_SKILL_RADIOBUTTON_CW_SPECIAL_TREE2,
	ID_SKILL_RADIOBUTTON_CW_PET,				// ��

	// ä����
	ID_SKILL_RADIOBUTTON_GR_GROUP,		
	ID_SKILL_RADIOBUTTON_GR_1,					// �ӻ�
	ID_SKILL_RADIOBUTTON_GR_2,					// �ı�
	ID_SKILL_RADIOBUTTON_GR_3,					// Ÿ��
	ID_SKILL_RADIOBUTTON_GR_COMMON,				// ����
	ID_SKILL_RADIOBUTTON_GR_PET,				// ��

	// �и�
	ID_SKILL_RADIOBUTTON_PR_GROUP,		
	ID_SKILL_RADIOBUTTON_PR_1,					// ��ǳ
	ID_SKILL_RADIOBUTTON_PR_2,					// ���
	ID_SKILL_RADIOBUTTON_PR_3,					// ����
	ID_SKILL_RADIOBUTTON_PR_4,
	ID_SKILL_RADIOBUTTON_PR_COMMON,				// ����
	ID_SKILL_RADIOBUTTON_PR_SPECIAL1,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL2,
	ID_SKILL_RADIOBUTTON_PR_COMMON_TREE,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL_TREE1,
	ID_SKILL_RADIOBUTTON_PR_SPECIAL_TREE2,
	ID_SKILL_RADIOBUTTON_PR_PET,				// ��

	// ��ҿ�
	ID_SKILL_RADIOBUTTON_SW_GROUP,		
	ID_SKILL_RADIOBUTTON_SW_1,					// �ϻ�
	ID_SKILL_RADIOBUTTON_SW_2,					// ���
	ID_SKILL_RADIOBUTTON_SW_3,					// ��ô
	ID_SKILL_RADIOBUTTON_SW_COMMON,				// ����
	ID_SKILL_RADIOBUTTON_SW_PET,				// ��

	ID_SKILL_BUTTON_PAGE_LEFT,					// ������ ����
	ID_SKILL_BUTTON_PAGE_RIGHT,					// ������ ������
	ID_SKILL_BUTTON_PAGE_TEXT,					// ������ TETX

	// ����â ����
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

	//����
	ID_SKILL_CREATEITEM_BACKGROUND,			// ��׶���
	ID_SKILL_CREATEITEM_LIST,				// ����Ʈ
	ID_SKILL_CREATEITEM_ITEM,				// ������
	ID_SKILL_CREATEITEM_SKILL_BACKGROUND,	// ���õ� ��׶���
	ID_SKILL_CREATEITEM_SKILL,				// ���õ�
	ID_SKILL_CREATEITEM_OK,					// �����ϱ�

	ID_SKILL_BG_TOTAL,
	ID_SKILL_MANAGER_ID,					// �������̵�

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
	// ����â - ��
	//======================================================================================================================//


	//======================================================================================================================//
	// ���ΰŷ� - ����
	//======================================================================================================================//
	ID_PERSONBUY_BACKGROUND				= 900,	// ��׶���
	ID_PERSONBUY_BACKGROUND_CLOSE,				// �ݱ�

	ID_PERSONBUY_NAEM,							// �̸�

	ID_PERSONBUY_PLAYER_NAME_LEFT,				// �÷��̾� �̸�
	ID_PERSONBUY_PLAYER_NAME_RIGHT,				// �÷��̾� �̸�

	ID_PERSONBUY_GOLD_LEFR,						// �ݾ�ǥ��
	ID_PERSONBUY_GOLD_RIGHT,					// �ݾ�ǥ��
	ID_PERSONBUY_GOLD_RIGHT_G,					
	ID_PERSONBUY_GOLD_RIGHT_S,
	ID_PERSONBUY_GOLD_RIGHT_B,

	ID_PERSONBUY_BUTTON_OK,						// Ȯ�ι�ư
	ID_PERSONBUY_BUTTON_CANCLE,					// ��ҹ�ư

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

	// ��罺ũ��
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


	//�˸�
	ID_PERSONBUY_QUESTION_BACKGROUND,			// ��׶���
	ID_PERSONBUY_QUESTION_INPUT,				// �޽���
	ID_PERSONBUY_QUESTION_OK,					// Ȯ��
	ID_PERSONBUY_QUESTION_CANCLE,				// ���


	ID_PERSONBUY_BACKGROUND2,					// �����̱����� ��׶���
	ID_PERSONBUY_BG_TOTAL,
	ID_PERSONBUY_MANAGER_ID,					// �������̵�

	// �ŷ� ���� �˸�����
	ID_PERSONBUY_FIRST_QUESTION_BACKGROUND,		// ��׶���
	ID_PERSONBUY_FIRST_QUESTION_TEXT,			// �˸� ��
	ID_PERSONBUY_FIRST_OK,						// ����
	ID_PERSONBUY_FIRST_CANCLE,					// ����

	// �߰� ���
	ID_PERSONBUY_PLAYER_1_FACE_CW,					// ����	  ��_û��
	ID_PERSONBUY_PLAYER_1_FACE_GR,					// ����	  ��_ä����
	ID_PERSONBUY_PLAYER_1_FACE_PR,					// ����	  ��_�и�
	ID_PERSONBUY_PLAYER_1_FACE_SW,					// ����	  ��_��ҿ�

	ID_PERSONBUY_PLAYER_2_FACE_CW,					// ������  ��_û��
	ID_PERSONBUY_PLAYER_2_FACE_GR,					// ������  ��_ä����
	ID_PERSONBUY_PLAYER_2_FACE_PR,					// ������  ��_�и�
	ID_PERSONBUY_PLAYER_2_FACE_SW,					// ������  ��_��ҿ�
	//======================================================================================================================//
	// ���ΰŷ� - ��
	//======================================================================================================================//




	//======================================================================================================================//
	// �� ����Ʈ - ����
	//======================================================================================================================//
	ID_ROOMLIST_BACKGROUND				= 1000,				// ��׶���

	ID_ROOMLIST_NAEM,

	ID_ROOMLIST_GO_VILLAGE,				// ������ ����

	ID_ROOMLIST_BUTTON_FAST_VERSE,				// ���� ������
	ID_ROOMLIST_BUTTON_MAKEROOM,				// �游���

	ID_ROOMLIST_LIST_BACKGROUND,				// ����Ʈ ��׶���


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
	ID_ROOMLIST_SERVER_GENERAL,				// �Ϲݼ���
	ID_ROOMLIST_SERVER_GUILD,				// ��弭��

	ID_ROOMLIST_PAGE_LEFT,				// ������ ���ʹ�ư
	ID_ROOMLIST_PAGE_RIGHT,				// ������ �����ʹ�ư

	ID_ROOMLIST_PAGE_TEXT_BG,				// ������ ��׶���
	ID_ROOMLIST_PAGE_TEXT,				// ������ �ؽ�Ʈ "1/8"

	ID_ROOMLIST_RENEWAL,				// ����

	// PassWorld
	ID_ROOMLIST_PASSWORLD_BACKGROUND,				// ��׶���
	ID_ROOMLIST_PASSWORLD_ICON,				// ������
	ID_ROOMLIST_PASSWORLD_TEXT,				// �ؽ�Ʈ
	ID_ROOMLIST_PASSWORLD_OK,				// Ȯ�ι�ư
	ID_ROOMLIST_PASSWORLD_CANCLE,				// ��ҹ�ư


	ID_ROOMLIST_FAST_OK,								// Ȯ��
	ID_ROOMLIST_FAST_CANCLE,							// ���

	ID_NOTICE_NAME,
	ID_NOTICE_MESSAGE,

	ID_ROOMLIST_TOTAL,

	//======================================================================================================================//
	// �� ����Ʈ - ��
	//======================================================================================================================//




	//======================================================================================================================//
	// �游��� - ����
	//======================================================================================================================//	
	ID_ROOMMAKE_BACKGROUND				= 1100,				// ��׶���
	ID_ROOMMAKE_CLOSE,				// �ݱ�
	ID_ROOMMAKE_NAME,					// NAME
	ID_ROOMMAKE_ROOMNAME,				// ������
	ID_ROOMMAKE_PASSWORLD,				// �н�����

	ID_ROOMMAKE_MAP_CHOICE,				// �ʼ���
	ID_ROOMMAKE_ZONE_CHOICE,				// ��������

	ID_ROOMMAKE_LEVEL_GROUP,
	ID_ROOMMAKE_LEVEL_0,				// ��������
	ID_ROOMMAKE_LEVEL_1,				// ��������
	ID_ROOMMAKE_LEVEL_2,				// ��������

	ID_ROOMMAKE_OK,				// Ȯ��
	ID_ROOMMAKE_CANCLE,				// ���

	//======================================================================================================================//
	// �游��� - ��
	//======================================================================================================================//



	//======================================================================================================================//
	// ���� - ����
	//======================================================================================================================//
	ID_SHOP_BACKGROUND					= 1200,				// �鱸����
	ID_SHOP_BACKGROUND_WIN,									// �̵�
	ID_SHOP_NAME,											// �̸�
	ID_SHOP_CLOSE,											// �ݱ�
	
	ID_SHOP_SLOT00,											// ����
	ID_SHOP_SLOT01,											// ����
	ID_SHOP_SLOT02,											// ����
	ID_SHOP_SLOT03,											// ����
	ID_SHOP_SLOT04,											// ����
	ID_SHOP_SLOT05,											// ����
	ID_SHOP_SLOT06,											// ����
	ID_SHOP_SLOT07,											// ����
	ID_SHOP_SLOT08,											// ����
	ID_SHOP_SLOT09,											// ����
	ID_SHOP_SLOT10,											// ����
	ID_SHOP_SLOT11,											// ����
		

	ID_SHOP_PAGE_LEFT,										// ������ ����
	ID_SHOP_PAGE_RIGHT,										// ������ ������
	ID_SHOP_PAGE_TEXT,										// ������
	ID_SHOP_BG_TOTAL,
	ID_SHOP_GOLD_BG,
	ID_SHOP_GOLD_G,
	ID_SHOP_GOLD_Y,
	ID_SHOP_GOLD_T,
	ID_SHOP_PAGE_REPIRE1,
	ID_SHOP_PAGE_REPIRE2,
	ID_SHOP_PAGE_BUY,
	ID_SHOP_PAGE_CANCEL,
	ID_SHOP_MANAGER_ID,										// ������ȣ
	//======================================================================================================================//
	// ���� - ��
	//======================================================================================================================//


	//======================================================================================================================//
	// ��ų���� - ����
	//======================================================================================================================//
	ID_MYPET_BACKGROUND					= 1300,				// �鱸����
	ID_MYPET_WIN,											// �̵�
	ID_MYPET_CLOSE,											// �ݱ�

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
	// ��ų���� - ��
	//======================================================================================================================//


	//======================================================================================================================//
	// ���� �� - ����
	//======================================================================================================================//

	// ����
	ID_SHOPMENU_TAB_WEPON_GROUP = 1400,
	ID_SHOPMENU_TAB_WEPON_COMMAN,								// ���빫��
	ID_SHOPMENU_TAB_WEPON_SPECIAL,								// Ư������
	ID_SHOPMENU_TAB_WEPON_RE_BUY,								// �����

	ID_SHOPMENU_SPECIAL_WEAPON_GROUP,									
	ID_SHOPMENU_WEAPON_BO,										// ��/â
	ID_SHOPMENU_WEAPON_FAN,										// ��ä
	ID_SHOPMENU_WEAPON_AXE2,									// ��յ���
	ID_SHOPMENU_WEAPON_DAGGER2,									// �ּ��ܰ�

	ID_SHOPMENU_COMMAN_WEAPON_GROUP,
	ID_SHOPMENU_WEAPON_SWORD,									// ��
	ID_SHOPMENU_WEAPON_AXE,										// ����
	ID_SHOPMENU_WEAPON_DAGGER,									// �ܰ�

	// ��
	ID_SHOPMENU_TAB_ARMOR_GROUP,
	ID_SHOPMENU_TAB_ARMOR,										// ����
	ID_SHOPMENU_TAB_ARMOR_RE_BUY,								// �����

	// ĳ����
	ID_SHOPMENU_CHAR_GROUP,
	ID_SHOPMENU_CHAR_CHUNGWOON,									// ��������
	ID_SHOPMENU_CHAR_CHAEGARUNG,								// �����
	ID_SHOPMENU_CHAR_PAERUK,									// ��������
	ID_SHOPMENU_CHAR_BISOWOON,									// �ϼ��ڰ�



	// ��ű�
	ID_SHOPMENU_TAB_ACC_GROUP,
	ID_SHOPMENU_TAB_ACC,										// ��ű�
	ID_SHOPMENU_TAB_ACC_RE_BUY,									// �����

	ID_SHOPMENU_ACC_GROUP,
	ID_SHOPMENU_ACC_ACCESSORY,									// ����
	ID_SHOPMENU_ACC_RING,										// ����
	ID_SHOPMENU_ACC_ARMLET,										// ����
	ID_SHOPMENU_ACC_NECKLACE,									// �����


	// Ż��
	ID_SHOPMENU_TAB_PET_GROUP,
	ID_SHOPMENU_TAB_PET,										// Ż��
	ID_SHOPMENU_TAB_PET_RE_BUY,									// �����

	ID_SHOPMENU_PET_GROUP,
	ID_SHOPMENU_PET_HORSE,										// ��
	ID_SHOPMENU_PET_TIGER,										// ȣ����
	ID_SHOPMENU_PET_WOLF,										// ����	

	// ����
	ID_SHOPMENU_TAB_MANTLA_GROUP,
	ID_SHOPMENU_TAB_MANTLA,										// ����
	ID_SHOPMENU_TAB_BANTLA_RE_BUY,								// �����
	//======================================================================================================================//
	// ���� �� - ��
	//======================================================================================================================//

	//======================================================================================================================//
	// ���� ���� - ����
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
	// ���� ����  - ��
	//======================================================================================================================//

	//===============================================================================================================================================//
	// ĳ���� ���� -- ����
	//===============================================================================================================================================//
	ID_CHARACTER_BACKGROUND					= 1800,				// ����
	ID_CHARACTER_BACKGROUND2,
	ID_CHARACTER_WIN,											// ������	
	ID_CHARACTER_CLOSE,											// �رհ�ť
	ID_CHARACTER_EXBTN,

	ID_CHARACTER_LV,											// �ȼ�STA
	ID_CHARACTER_GUILD,											// ����STA
	ID_CHARACTER_CLASS,									//ְҵSTA

	ID_CHARACTER_SLOT_WEAPON,										// ���빫��
	ID_CHARACTER_SLOT_SP_WEAPON,										// ���빫��
	ID_CHARACTER_SLOT_NAKELACE,										// ����
	ID_CHARACTER_SLOT_PET,										// ��
	ID_CHARACTER_SLOT_ARROR,										// ����
	ID_CHARACTER_SLOT_HAIR,										// �Ӹ�	
	ID_CHARACTER_SLOT_FACE,										// ��
	ID_CHARACTER_SLOT_CUFF,										// ����
	ID_CHARACTER_SLOT_NECKLACE,										// �����
	ID_CHARACTER_SLOT_RING,										// ����
	ID_CHARACTER_SLOT_BACK,										// ����
	
	ID_CHARACTER_LEFT,											// ����ת��ť
	ID_CHARACTER_RIGHT,											// ����ת��ť


	
	ID_CHARACTER_TAB_GROUP,
	ID_CHARACTER_TAB_CHARACTER,									// �� ĳ����
	ID_CHARACTER_TAB_RECORD_POINT,								// �� ����Ʈ ����


	ID_CHARACTER_TAB_CHARACTER_BG,								// �� ĳ���� ��׶���
	ID_CHARACTER_TAB_RECORD_POINT_BG,							// �� ����Ʈ ���� ��׶���



	ID_CHARACTER_INFO_0,										// ü��
	ID_CHARACTER_INFO_1,										// ���
						
	ID_CHARACTER_INFO_2,										// ��������
	ID_CHARACTER_INFO_3,										// �ּ�����
	ID_CHARACTER_INFO_4,										// ���Ÿ�����

	ID_CHARACTER_INFO_5,										// �������
	ID_CHARACTER_INFO_6,										// �ּ����
	ID_CHARACTER_INFO_7,										// ���Ÿ����

	ID_CHARACTER_INFO_8,										// ��������
	ID_CHARACTER_INFO_9,										// �ֹ�����
	ID_CHARACTER_INFO_10,										// ���Ÿ�����

	ID_CHARACTER_INFO_11,										// ����ġ��
	ID_CHARACTER_INFO_12,										// �ּ�ġ��
	ID_CHARACTER_INFO_13,										// ���Ÿ�ġ��

	ID_CHARACTER_INFO_14,										// �������õ�
	ID_CHARACTER_INFO_15,										// ��������Ʈ
	ID_CHARACTER_INFO_16,										// ��������Ʈ

	ID_CHARACTER_INFO_17,										// ����ü����
	ID_CHARACTER_INFO_18,										// ��������
	ID_CHARACTER_INFO_19,										// ��ü�·�
	ID_CHARACTER_INFO_20,										// ���ý·�

	
	ID_CHARACTER_NAME,
	ID_CHARACTER_BG_TOTAL,
	ID_CHARACTER_MANAGER_ID,									// �������̵�

	ID_CHARACTER_ADD_BUTTON_1,
	ID_CHARACTER_ADD_BUTTON_2,
	ID_CHARACTER_ADD_BUTTON_3,
	ID_CHARACTER_ADD_BUTTON_4,

	ID_CHARACTER_BACKGROUND_1,
	ID_CHARACTER_BACKGROUND_2,
	ID_CHARACTER_BACKGROUND_3,
	//===============================================================================================================================================//
	// ĳ���� ���� -- ��
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// ����Ʈ -- ����
	//===============================================================================================================================================//
	ID_QUEST_BACKGROUND					=		1900,			// ��׶���
	ID_QUEST_BOOK,												// å��ư
	ID_QUEST_BACK,												// ������

	ID_QUEST_CHOICE_BREACKGROUND,								// ���ýöߴ� â	
	ID_QUEST_CHOICE_CLOSE,										// �ݱ�

	ID_QUEST_CHOICE_MAPNAME,									// ���̸�

	ID_QUEST_MISSION_TEXT_1,									// �̼�1
	ID_QUEST_MISSION_TEXT_2,									// �̼�2
	ID_QUEST_MISSION_TEXT_3,									// �̼�3

	ID_QUEST_CHOICE_GIVE_IMAGE,									// ����ǰ
	ID_QUEST_CHOICE_GIVE_NAME,									// ����ǰ�̸�

	ID_QUEST_CHOICE_GIVE_IMAGE2,									// ����ǰ
	ID_QUEST_CHOICE_GIVE_NAME2,									// ����ǰ�̸�

	ID_QUEST_CHOICE_GIVE_EXPLANATION,							// ����
	ID_QUEST_CHOICE_COMPLETION,									// �Ϸ����� ���	

	ID_QUEST_BUTTON_ACCEPT,										// ������ư	
	ID_QUEST_BUTTON_GIVEUP,										// �����ư

	// ����������
	ID_QUEST_MY_BACKGROUND,										// ��׶���
	ID_QUEST_MY_CLOSE,											// �ݱ�

	ID_QUEST_MY_LIST00,											// ����Ʈ
	ID_QUEST_MY_LIST01,
	ID_QUEST_MY_LIST02,
	ID_QUEST_MY_LIST03,
	ID_QUEST_MY_LIST04,
	ID_QUEST_MY_LIST05,
	ID_QUEST_MY_LIST06,
	ID_QUEST_MY_LIST07,
	ID_QUEST_MY_LIST08,
	ID_QUEST_MY_LIST09,


	// ������
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

	// ����
	ID_QUEST_INFORMATION_BACKGROUND,							// ��׶���
	ID_QUEST_INFORMATION_CLOSE,									// �ݱ�
	ID_QUEST_INFORMATION_NAME,									// ����Ʈ �̸�
	ID_QUEST_INFORMATION_EXPLANATION,							// ����
	ID_QUEST_INFORMATION_CONDITION,								// ����
	ID_QUEST_INFORMATION_GIVE_IMAGE,							// �����̹���
	ID_QUEST_INFORMATION_GIVE_NAME,								// �����̸�
	ID_QUEST_INFORMATION_GIVE_IMAGE2,							// �����̹���
	ID_QUEST_INFORMATION_GIVE_NAME2,								// �����̸�
	ID_QUEST_INFORMATION_GIVE_OK,								// ����ޱ�
	ID_QUEST_INFORMATION_GIVEUP,								// ����
	//===============================================================================================================================================//
	// ����Ʈ -- ��
	//===============================================================================================================================================//

	//===============================================================================================================================================//
	// �ý��� -- ����
	//===============================================================================================================================================//
	ID_SYSTEM_BACKGROUND			= 2100,						// ��׶���
	ID_SYSTEM_NAME,												// �̸�
	ID_SYSTEM_CLOSE,											// �ݱ�

	ID_SYSTEM_BUTTON_OPTION,									// �� ��
	ID_SYSTEM_BUTTON_CHANNEL,									// ä�κ���
	ID_SYSTEM_BUTTON_CHARACTER,									// ĳ���ͼ���
	ID_SYSTEM_BUTTON_GAMEOVER,									// ��������
	ID_SYSTEM_BUTTON_BACKTOWN,									// �����ε��ư���
	ID_SYSTEM_BG_TOTAL,
	//===============================================================================================================================================//
	// �ý��� -- ��
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// �ɼ� -- ����
	//===============================================================================================================================================//	
	ID_LOBBY_OPTION_BACKGROUND			=	2200,				// ��׶���
	ID_LOBBY_OPTION_WIN,										// �̵�
	ID_LOBBY_OPTION_NAME,										// �̸�
	ID_LOBBY_OPTION_CLOSE,										// �ݱ��ư

	ID_LOBBY_OPTION_TAB_GROUP,
	ID_LOBBY_OPTION_TAB_GAME,									// �� ���Ӽ���
	ID_LOBBY_OPTION_TAB_KEY,									// �� Ű����

	ID_LOBBY_OPTION_VOLUME_BACKGROUND,							// ����� ȿ���� ��׶���

	ID_LOBBY_OPTION_MUSIC_ONOFF,								// ����� on/off	
	ID_LOBBY_OPTION_MUSIC_BG,									// �����̵� ��׶���
	ID_LOBBY_OPTION_MUSIC_SLIDER,								// �����̵�

	
	ID_LOBBY_OPTION_EFFECT_ONOFF,								// ȿ���� on/off
	ID_LOBBY_OPTION_EFFECT_BG,									// �����̵� ��׶���
	ID_LOBBY_OPTION_EFFECT_SLIDER,								// �����̵�


	ID_LOBBY_OPTION_GAME_BACKGROUND,							// �ɼ� ��׶���
	ID_LOBBY_OPTION_NO_BUY,										// �ŷ�����
	ID_LOBBY_OPTION_NO_INVITATION_ROOM,							// �ʴ�ź�(��)
	ID_LOBBY_OPTION_NO_INVITATION_TOWN,							// �ʴ�ź�(����)	
	ID_LOBBY_OPTION_GUAGE_MYHP_VALUE,							// ü��/��� ��ġǥ��
	ID_LOBBY_OPTION_GUAGE_MYHP,									// �ڱ��̸�/ü��
	ID_LOBBY_OPTION_GUAGE_MYTEAMID,								// �Ʊ��̸�/ü��
	ID_LOBBY_OPTION_GUAGE_ENEMYTEAMID,							// �����̸�/ü��
	ID_LOBBY_OPTION_GAME_TIP,									// ������
	ID_LOBBY_OPTION_SKILL,										// ���� ��� ��ų ����â ���

	ID_LOBBY_OPTION_DEFAULT,									// �⺻��

	//////////////////////////////////////////////////////////////////////////

	ID_LOBBY_OPTION_KEY_GROUP,
	ID_LOBBY_OPTION_GAME_KEY,									// ����Ű����
	ID_LOBBY_OPTION_SKILL_KEY,									// A���Դ���Ű
	ID_LOBBY_OPTION_COMSKILL_KEY,								// B���Դ���Ű
	ID_LOBBY_OPTION_SKILL2_KEY,									// C��ų�»��
	ID_LOBBY_OPTION_GAMEMENU,									// ���Ӹ޴�

	ID_LOBBY_OPTION_DEFAULTA_KEYSETUP,							// �⺻��1
	ID_LOBBY_OPTION_DEFAULTB_KEYSETUP,							// �⺻��1
	ID_LOBBY_OPTION_CONFIRM_KEYSETUP,							// Ȯ��


	// ����Ű
	ID_LOBBY_OPTION_KEY_JUMP,
	ID_LOBBY_OPTION_KEY_ATTACK,
	ID_LOBBY_OPTION_KEY_CHANGEWEAPON,
	ID_LOBBY_OPTION_KEY_RIDEPET,
	ID_LOBBY_OPTION_KEY_MOVEUP,
	ID_LOBBY_OPTION_KEY_MOVEDOWN,
	ID_LOBBY_OPTION_KEY_MOVERIGHT,
	ID_LOBBY_OPTION_KEY_MOVELEFT,

	ID_LOBBY_OPTIONKEY_NULL_BG_1,			//����ִ°��� ä���ֱ�
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

	// ��ų
	ID_LOBBY_OPTIONKEY_NULL_BG_3,			//����ִ°��� ä���ֱ�
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

	// ���뽺ų
	ID_LOBBY_OPTIONKEY_NULL_BG_5,			//����ִ°��� ä���ֱ�
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

	// ����Ű
	ID_LOBBY_OPTION_HOT_CHARACTER,
	ID_LOBBY_OPTION_HOT_SKILL,
	ID_LOBBY_OPTION_HOT_BAG,
	ID_LOBBY_OPTION_HOT_QUEST,
	ID_LOBBY_OPTION_HOT_PERSONSHOP,

	ID_LOBBY_OPTIONKEY_NULL_BG_7,			//����ִ°��� ä���ֱ�
	
	ID_LOBBY_OPTION_HOT_FRIEND,
	ID_LOBBY_OPTION_HOT_GUILD,
	ID_LOBBY_OPTION_HOT_MAP,
	ID_LOBBY_OPTION_HOT_SYSTEM,
	ID_LOBBY_OPTION_HOT_CASHSHOP,
    
	ID_OPTION_BG_TOTAL,
	ID_OPTION_MANAGER_ID,
	//===============================================================================================================================================//
	// �ɼ� -- ��
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// ���ӹ� -- ����
	//===============================================================================================================================================//
	ID_LOBBY_GAMEROOMRIGHT_TEAMGROUP=	2400,
	ID_LOBBY_GAMEROOMRIGHT_REDTEAM,									// ������
	ID_LOBBY_GAMEROOMRIGHT_BLUETEAM,									// �����
	ID_LOBBY_GAMEROOMRIGHT_BACK,										// ��׶���
	ID_LOBBY_GAMEROOMRIGHT_ROOMINFO,									// ������
	ID_LOBBY_GAMEROOMRIGHT_INVITATION,								// �ʴ�
	ID_LOBBY_GAMEROOMRIGHT_EQUIPITEM,									// ����������
	ID_LOBBY_GAMEROOMRIGHT_EXIT,										// ������
	ID_LOBBY_GAMEROOMRIGHT_LEVEL,										// ���� TEXT
	ID_LOBBY_GAMEROOMRIGHT_JOIN,										// Join TEXT
	ID_LOBBY_GAMEROOMRIGHT_ROOMNAME,									// ���̸�

	ID_LOBBY_GAMEROOMRIGHT_START,										// ���۹�ư
	ID_LOBBY_GAMEROOMRIGHT_READY,								// �����ư

	ID_LOBBY_GAMEROOMRIGHT_MAPIMAGE,


	ID_LOBBY_GAMEROOMRIGHT_MAPLEFT,									// �� ����
	ID_LOBBY_GAMEROOMRIGHT_MAPRIGHT,									// �� ������
	ID_LOBBY_GAMEROOMRIGHT_MAPOPTION_L,								// �ɼ� ����
	ID_LOBBY_GAMEROOMRIGHT_MAPOPTION_R,								// �ɼ� ������
	ID_LOBBY_GAMEROOMRIGHT_MAPBACK,									// ȭ���� �̹���


	ID_LOBBY_GAMEROOMRIGHT_ZONE_LEFT,								// ���� ���� ��ư
	ID_LOBBY_GAMEROOMRIGHT_ZONE_TEXT,								// ���� �ؽ�Ʈ
	ID_LOBBY_GAMEROOMRIGHT_ZONE_RIGHT,								// ���� ������ ��ư


	ID_LOBBY_GAMEROOMRIGHT_ITEM_LEFT,								// ������ȹ�� ���� ��ư
	ID_LOBBY_GAMEROOMRIGHT_ITEM_TEXT,								// ������ȹ�� �ؽ�Ʈ
	ID_LOBBY_GAMEROOMRIGHT_ITEM_RIGHT,								// ������ȹ�� ������ ��ư

	//ä��
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
	// ���ӹ� -- ��
	//===============================================================================================================================================//



	//===============================================================================================================================================//
	// ��ȭ ���� ���� -- ����
	//===============================================================================================================================================//
	// �����۰�ȭ ���̾�α�
	ID_RRD_BACKGROUND					= 2700,			// ��׶���
	ID_RRD_WIN,											// �̵�
	ID_RRD_CLOSE,										// �ݱ�

	ID_RRD_TAB_GROUP,
	ID_RRD_TAB_REINFOREC,								// ��ȭ
	ID_RRD_TAB_DECOMPOSE,								// ����
	ID_RRD_TAB_RECHARGE,								// ����

	ID_RRD_IMAGE_DECOMPOSE,								// ���� �̹���

	ID_RRD_PROGRESS_NAME,								// �������̸�
	ID_RRD_PROGRESS_1,									// ���α׷��� ������(��ȭ)
	ID_RRD_PROGRESS_2,									// ���α׷��� ������(����)
	ID_RRD_PROGRESS_3,									// ���α׷��� ������(����)
	ID_RRD_MSG,											// �˸��޽���
	ID_RRD_OK,											// ����
	ID_RRD_RECHARGE,											// ����
	ID_RRD_CANCEL,											// ����
	ID_RRD_BG_TOTAL,
	ID_RRD_MANAGER_ID,

	ID_RRD_REINFOREC_IMAGE = 2740,								// ��ȭ �̹���
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

	ID_RRD_RECHARGE_IMAGE = 2770,								// ���� �̹���
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
	// ��ȭ ���� ���� -- ��
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// ���������� -- ����
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
	// ���������� -- ��
	//===============================================================================================================================================//



	//======================================================================================================================//
	// ���λ��� - ����
	//======================================================================================================================//	
	
	ID_PERSONSHOP_BG						= 3000,
	ID_PERSONSHOP_BG_CASH,					// ĳ��

	ID_PERSONSHOP_BG_WIN,
	ID_PERSONSHOP_CLOSE_BTN,
	ID_PERSONSHOP_CLOSE_BTN_2,
	ID_PERSONSHOP_NAME,
	ID_PERSONSHOP_CHAT,
	ID_PERSONSHOP_OTEM_SELL_BG,

	ID_PERSONSHOP_ITEM_IMAGE1,				// �̹���
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

	ID_PERSPNSHOP_START,					// �ǸŽ���
	ID_PERSPNSHOP_END,						// ����
	ID_PERSPNSHOP_SETNAME,
	ID_PERSPNSHOP_LBTN,
	ID_PERSPNSHOP_RBTN,
	ID_PERSONSHOP_TOTAL,					
	ID_PERSONSHOP_MANAGER_ID,

	//Ȯ��â
	ID_PERSONSHOP_CK_BACKGROUND,			// ��׶���
	ID_PERSONSHOP_CK_WIN,					// �̵�
	ID_PERSONSHOP_CK_TEXT,					// �ŷ��� �Ϸ� �Ͻðڽ��ϱ�?
	ID_PERSONSHOP_CK_OK,					// Ȯ��
	ID_PERSONSHOP_CK_CANCLE,				// ���
	ID_PERSONSHOP_CK_MANAGER_ID,

	ID_PERSONSHOP_PR_BACKGROUND,			// ��׶���
	ID_PERSONSHOP_PR_WIN,					// �̵�
	ID_PERSONSHOP_PR_TEXT1,
	ID_PERSONSHOP_PR_TEXT2,
	ID_PERSONSHOP_PR_TEXT3,
	ID_PERSONSHOP_PR_OK,					// Ȯ��
	ID_PERSONSHOP_PR_CANCLE,				// ���
	//*/
	
	//======================================================================================================================//
	// ���λ��� - ��
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
	// ģ����� - ����
	//======================================================================================================================//
	ID_MESSENGER_BG					=	4000,

	ID_MESSENGER_BG_NAME,
	ID_MESSENGER_OFF_BTN,

	ID_MESSENGER_TAB1_BTN,		// ģ�����
	ID_MESSENGER_TAB2_BTN,		// ���ܸ��
	ID_MESSENGER_TAB3_BTN,		// �˻�
	ID_MESSENGER_GROUP_TAB,

	ID_MESSENGER_NAME_BTN,		// �̸�
	ID_MESSENGER_LV_BTN,		// ����
	ID_MESSENGER_STATE_BTN,		// ����
	ID_MESSENGER_JOB_BTN,		// ����

	ID_MESSENGER_LEFT_BTN,		
	ID_MESSENGER_RIGHT_BTN,
	ID_MESSENGER_PAGE_NUM,

	ID_MESSENGER_ADD_BTN,		// ���
	ID_MESSENGER_DELETE_BTN,
	ID_MESSENGER_BLOCK_BTN,		// ����

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

	ID_MESSENGER_FINDFRIEND_TXT_BG,		// ģ��ã�� �̸��Է� ��׶���
	ID_MESSENGER_FINDFORBTN,			// �̸� ���� ������ ��ɷ� ã����? ��ư
	ID_MESSENGER_FINDFRIEND_TXT,		// �Է�
	ID_MESSENGER_FINDFRIEND_BTN,		// �˻���ư


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
	//��â�� - ����
	//======================================================================================================================//	
	ID_WAREHOUSE_BACKGROUND					= 4300,		// ��׶���
	ID_WAREHOUSE_BACKGROUND_CLOSE,						// �ݱ�
	ID_WAREHOUSE_NAME,

	// ��â�� ����
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
	//��â�� - ��
	//======================================================================================================================//




	//======================================================================================================================//
	//����Ʈ - ����
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
	
	
	/* npc quest ��ȭ */
	ID_QUEST_NPC_BG							= 4600,

	ID_QUEST_NPC_NAME_TXT,				// �̸�
	ID_QUEST_NPC_CANCLE_BTN,			// �ݱ�
	ID_QUEST_NPC_STORY_TXT,				// �ȳ���

	ID_QUEST_NPC_TALK1_BTN,				// ���� ��ư
	ID_QUEST_NPC_TALK2_BTN,
	ID_QUEST_NPC_TALK3_BTN,
	ID_QUEST_NPC_TALK4_BTN,
	ID_QUEST_NPC_TALK5_BTN,

	ID_QUEST_NPC_TALK1_IMAGE_COMP,			// ����Ʈ �Ϸ��̹���
	ID_QUEST_NPC_TALK2_IMAGE_COMP,
	ID_QUEST_NPC_TALK3_IMAGE_COMP,
	ID_QUEST_NPC_TALK4_IMAGE_COMP,
	ID_QUEST_NPC_TALK5_IMAGE_COMP,


	ID_QUEST_NPC_TALK1_IMAGE_NEW,			// ���ο� ����Ʈ �̹���
	ID_QUEST_NPC_TALK2_IMAGE_NEW,
	ID_QUEST_NPC_TALK3_IMAGE_NEW,
	ID_QUEST_NPC_TALK4_IMAGE_NEW,
	ID_QUEST_NPC_TALK5_IMAGE_NEW,

	ID_QUEST_NPC_TALK1_IMAGE_ING,			// �������� ����Ʈ �̹���
	ID_QUEST_NPC_TALK2_IMAGE_ING,
	ID_QUEST_NPC_TALK3_IMAGE_ING,
	ID_QUEST_NPC_TALK4_IMAGE_ING,
	ID_QUEST_NPC_TALK5_IMAGE_ING,

	ID_QUEST_NPC_TALK1_TXT,					// ���ڿ���
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


	//��Ȱ
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
	//����Ʈ - ��
	//======================================================================================================================//




	//======================================================================================================================//
	// ���â -- ����
	//======================================================================================================================//	
	ID_GAMERESULT_BACKGROUND1			=	5500,
	ID_GAMERESULT_BACKGROUND2,
	
	ID_GAMERESULT_FILED_KILL,				// ų
	ID_GAMERESULT_FILED_ATACK,				// ����
	ID_GAMERESULT_FILED_COUNTER,			// ī����
	ID_GAMERESULT_FILED_DAMAGE,				// ������
	ID_GAMERESULT_FILED_DIE,				// ����		
	ID_GAMERESULT_FILED_EXP,				// ����ġ
	ID_GAMERESULT_FILED_GOLD,				// ����

	// Ŭ����
	ID_GAMERESULT_STAGE_CLEAR,
	ID_GAMERESULT_STAGE_FAIL,
	ID_GAMERESULT_WIN,
	ID_GAMERESULT_LOSE,
	ID_GAMERESULT_DRAW,

	// ���
	ID_GAMERESULT_S,
	ID_GAMERESULT_A,
	ID_GAMERESULT_B,
	ID_GAMERESULT_C,
	ID_GAMERESULT_D,
	ID_GAMERESULT_E,
	ID_GAMERESULT_F,

	// �ﰢ��
	ID_GAMERESULT_TRIANGLE_BACKGROUND,		// �ﰢ�� ��׶���
	ID_GAMERESULT_ITEM_01,
	ID_GAMERESULT_ITEM_02,
	ID_GAMERESULT_ITEM_03,
	
	ID_GAMERESULT_NO_ITEM_01,
	ID_GAMERESULT_NO_ITEM_02,
	ID_GAMERESULT_NO_ITEM_03,

	ID_GAMERESULT_BUTTON_01,				// ��
	ID_GAMERESULT_BUTTON_02,				// ����
	ID_GAMERESULT_BUTTON_03,				// ������

	// �޴�
	ID_GAMERESULT_MENU_BACKGROUND,			// ��׶���
	ID_GAMERESULT_MENU_REGAME,				// ���Ӵٽ��ϱ�
	ID_GAMERESULT_MENU_TOWN,				// �����ε��ư���
	ID_GAMERESULT_MENU_MAP,					// �ʼ���

	ID_GAMERESULT_BG_KILL,				// ų
	ID_GAMERESULT_BG_ATACK,				// ����
	ID_GAMERESULT_BG_COUNTER,			// ī����
	ID_GAMERESULT_BG_DAMAGE,				// ������
	ID_GAMERESULT_BG_DIE,				// ����		
	ID_GAMERESULT_BG_EXP,				// ����ġ
	ID_GAMERESULT_BG_GOLD,				// ����
	//===================================================================================================================//
	// ���â -- ��
	//===================================================================================================================//



	//===================================================================================================================//
	// ����â -- ����
	//===================================================================================================================//
	ID_CREATEITEM_BACKGROUND	=	5600,		// ��׶���
	ID_CREATEITEM_MOVE,							// ������
	ID_CREATEITEM_NAEM,							// �̸�
	ID_CREATEITEM_CLOSE,						// �ݱ�
	ID_CREATEITEM_FILD,							// �ʵ�

	ID_CREATEITEM_IMAGE_BOOK,					// ���ۼ�
	ID_CREATEITEM_ITEM_NUMBER,					// ���ۼ� �Ʒ� ����� �ִ¼�
	ID_CREATEITEM_BOOK_NAME,					// ���ۼ��̸�
	ID_CREATEITEM_LEVEL,						// �ʿ䷹��
	ID_CREATEITEM_SKILL,						// �ʿ���õ�
	ID_CREATEITEM_GOLD,							// �ʿ�ݾ�
	ID_CREATEITEM_INVISIBLE,					// ���ۼ�����
	ID_CREATEITEM_SPACE,						// �ʿ����

	ID_CREATEITEM_ITEMIMAGE_00,					// �ʿ������
	ID_CREATEITEM_ITEMIMAGE_01,
	ID_CREATEITEM_ITEMIMAGE_02,
	ID_CREATEITEM_ITEMIMAGE_03,

	ID_CREATEITEM_ITEMNAME_00,					// ����̸�
	ID_CREATEITEM_ITEMNAME_01,
	ID_CREATEITEM_ITEMNAME_02,
	ID_CREATEITEM_ITEMNAME_03,

	ID_CREATEITEM_CURRENT_00,					// ��᰹��
	ID_CREATEITEM_CURRENT_01,
	ID_CREATEITEM_CURRENT_02,
	ID_CREATEITEM_CURRENT_03,

	ID_CREATEITEM_PROGRESS,						// ���α׷�����

	ID_CREATEITEM_LEFT,							// ���鰹�� ����
	ID_CREATEITEM_RIGHT,						// ���鰹�� ������
	ID_CREATEITEM_TEXT,							// ����

	ID_CREATEITEM_MAKE,							// �����
	ID_CREATEITEM_ALLMAKE,						// ��θ����

	ID_CREATEITEM_CANCLE,						// ���

	ID_CREATEiTEM_TOTAL,
	ID_CREATEITEM_MANAGER_ID,					// �������̵�
	//===================================================================================================================//
	// ����â -- ��
	//===================================================================================================================//


	//===================================================================================================================//
	// ����â ���â -- ����
	//===================================================================================================================//
	// ����â
	ID_CREATEITEM_CHOICE_BAKCGROUND = 5700,	// ��׶��
	ID_CREATEITEM_CHOICE_MOVE,				// �̵�
	ID_CREATEITEM_CHOICE_NAME,				// �̸�
	ID_CREATEITEM_CHOICE_CLOSE,				// �ݱ�

	ID_CREATEITEM_CHOICE_GROUP,
	ID_CREATEITEM_CHOICE_EFF_SUF,			// ȿ��/���
	ID_CREATEITEM_CHOICE_SHI_ACC,			// ��/�Ǽ�����
	ID_CREATEITEM_CHOICE_ATT_PAT,			// ����/��

	ID_CREATEITEM_CHOICE_OK,				// Ȯ��

	ID_CREATEITEM_CHOICE_TOTAL,
	ID_CREATEITEM_CHOICE_MANAGER_ID,

	// Ȯ��â
	ID_CREATEITEM_QUESTION_BACKGROUND,		// ��׶���
	ID_CREATEITEM_QUESTION_TEXT,			// �ؽ�Ʈ
	ID_CREATEITEM_QUESTION_OK,				// Ȯ��
	ID_CREATEITEM_QUESTION_CANCLE,			// ���
	//===================================================================================================================//
	// ����â ���â -- ��
	//===================================================================================================================//



	//===================================================================================================================//
	// �Ӹ��� ������ -- ����
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
	// �Ӹ��� ������ -- ��
	//===================================================================================================================//


	// ��ų ����	
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

enum // �޽����ڽ��� ��������, ���¸� �˱����� ����
{
	MSGBOX_CHARACTER_DELETE = 0,		// ĳ���� ����
	MSGBOX_ITEM_BUY,
	MSGBOX_GAMEOVER,
	MSGBOX_UNVISIBLE,
	MSGBOX_P2P_INIT,
	MSGBOX_REINFORCE,
	MSGBOX_CHARGE,
	MSGBOX_LOGINFAILED,
	MSGBOX_SERVER_CONNECTION_LOST,
	MSGBOX_ROOMLIST,
	MSGBOX_TOWNJOIN, // ���� ����
	MSGBOX_QUEST_ACCEPT,	// ����Ʈ����
	MSGBOX_QUEST_GIVEUP,	// ����Ʈ����
	MSGBOX_QUEST_ACCEPT_YN, // ����Ʈ ���� ����
	MSGBOX_QUEST_GIVEUP_YN, // ����Ʈ ���� ����
	MSGBOX_QUEST_MENU_GIVEUP_YN,	 // �۷ι� ����Ʈ��ư ���� ����â
	MSGBOX_QUEST_ITEM_SELL_YN,		// ������ �ȱ�
	MSGBOX_TOWN_MOVE,				// �������̵�
	MSGBOX_ITEM_DELETE,				// ������ ����
	MSGBOX_CHARACTER_DELETE_ACCEPT,	// ĳ���� ������ ��������
	MSGBOX_QUESTVIEW,				// ���ӷ뿡�� ���� ���
	MSGBOX_ERROR_DECOM,				// �����ϱ� ����
};

typedef enum LOBBY_STATE
{
	LS_EVENT,				// �̺�Ʈ ȭ��
	LS_SELECT_CHAR,			// ĳ���� ����
	LS_CREATE_CHAR,			// ĳ���� ����
	LS_ROOM_LIST,			// �渮��Ʈ
	LS_MAKE_ROOM,			// �游���
	LS_VERSUS,				// ������
	LS_MONSTERKILL,			// ����ų
	LS_QUEST,				// ����Ʈ

	LS_MYBAG,				// ������(����)
	LS_SKILL,				// ������(��ų������)
	LS_SHOPLIST,			// ��������Ʈ1
	LS_SKILLSHOPLIST,			// ��������Ʈ2(��ų)
	LS_OPTION,				// �ɼ�
	LS_STORYQUEST,			// ���丮����Ʈ
	LS_TOWN,				// ����
	LS_SHOPSTATE,           // �������( ��ü scene )
	LS_REINFORCE,			// ��ȭâ
	LS_ILLUST,				// ����â �Ϸ���Ʈ
}; // LOBBY_STATE


typedef enum STATE_REINFORCE	
{
	STATE_1_REINFORCE = 0,		// ��ȭ
	STATE_2_RECHARGE,			// ����				
	STATE_3_DECOMPOSE,			// ����

	STATE_RRD_NONE		= 255,		// �ʱ�ȭ


	REINFORCE_NONE = 100,
	REINFORCE_TRUE,
	REINFORCE_FALSE,
};


typedef enum STATE_SKILL		// ����â
{
	SKILL_WHOLE = 1,				// ��ü
	SKILL_COMMON = 255,				// ����
	SKILL_GENERAL = 253,			// �Ϲ�
	SKILL_EXCLUSIVE = 100,			// ����
	SKILL_PET = 9,					// ��
	SKILL_NONE = -1,				// ����
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