/*
file : ID_Maingame.h
*/


#ifndef _YB_MAINGAME_ID_H_
#define _YB_MAINGAME_ID_H_





typedef enum YB_MAINGAME_ID{


	//======================================================================================================================//
	//������ - ����
	//======================================================================================================================//	
	ID_MYBAG_BACKGROUND2					= 300,		// ��׶���
	ID_MYBAG_BACKGROUND_ICON2,						// ICON
	ID_MYBAG_BACKGROUND_NAME2,						// �̸�
	ID_MYBAG_BACKGROUND_CLOSE2,						// �ݱ�

	// ������ ������ư
	ID_MYBAG_RADIOBUTTON_GROUP2,
	ID_MYBAG_RADIOBUTTON_EQUIPMENT2,					// ���
	ID_MYBAG_RADIOBUTTON_CONSUMPTION2,				// �Ҹ�
	ID_MYBAG_RADIOBUTTON_STUFF12,					// ���1
	ID_MYBAG_RADIOBUTTON_STUFF22,					// ���2
	ID_MYBAG_RADIOBUTTON_GOLD_BG2,					// �ݾ� ��׶���
	ID_MYBAG_RADIOBUTTON_GOLD2,						// �ݾ� �ؽ�Ʈ

	// ������ ����
	ID_MYBAG_SLOT_002,
	ID_MYBAG_SLOT_012,
	ID_MYBAG_SLOT_022,
	ID_MYBAG_SLOT_032,
	ID_MYBAG_SLOT_042,
	ID_MYBAG_SLOT_052,
	ID_MYBAG_SLOT_062,
	ID_MYBAG_SLOT_072,
	ID_MYBAG_SLOT_082,
	ID_MYBAG_SLOT_092,
	ID_MYBAG_SLOT_102,
	ID_MYBAG_SLOT_112,
	ID_MYBAG_SLOT_122,
	ID_MYBAG_SLOT_132,
	ID_MYBAG_SLOT_142,
	ID_MYBAG_SLOT_152,
	ID_MYBAG_SLOT_162,
	ID_MYBAG_SLOT_172,
	ID_MYBAG_SLOT_182,
	ID_MYBAG_SLOT_192,
	ID_MYBAG_SLOT_202,
	ID_MYBAG_SLOT_212,
	ID_MYBAG_SLOT_222,
	ID_MYBAG_SLOT_232,
	ID_MYBAG_SLOT_242,

	// �Ҹ� ������ �޴°�
	ID_MYBAG_RECEIVER_BACKGROUND2,			// ��׶���
	// ����
	ID_MYBAG_RECEIVER_SLOT002,
	ID_MYBAG_RECEIVER_SLOT012,
	ID_MYBAG_RECEIVER_SLOT022,
	ID_MYBAG_RECEIVER_SLOT032,
	ID_MYBAG_DELETE2,						// ����
	//======================================================================================================================//
	//������ - ��
	//======================================================================================================================//

	ID_MAINGAME_EXP_TITLE		=	101,
	ID_MAINGAME_EXP_VALUE		=	102,

	ID_MAINGAME_TIME_TITLE		=	111,
	ID_MAINGAME_TIME_VALUE		=	112,

	ID_MAINGAME_MONEY_TITLE		=	121,
	ID_MAINGAME_MONEY_VALUE		=	122,

	ID_MAINGAME_CHATLEFT_TITLE	=	131,
	ID_MAINGAME_CHAR0_REGENTIME	=	132,
	ID_MAINGAME_CHAR1_REGENTIME	=	133,
	ID_MAINGAME_CHAR2_REGENTIME	=	134,
	ID_MAINGAME_CHAR3_REGENTIME	=	135,
	ID_MAINGAME_CHAR_CENTER		=	136,
	ID_MAINGAME_CHAR_CENTER_TEXT=	137,
	ID_MAINGAME_CHAR_ENERGY_TEXT=   138,

	ID_MAINGAME_CHATRIGHT_TITLE	=	141,
	ID_MAINGAME_ENEMY0_REGENTIME=	142,
	ID_MAINGAME_ENEMY1_REGENTIME=	143,
	ID_MAINGAME_ENEMY2_REGENTIME=	144,
	ID_MAINGAME_ENEMY3_REGENTIME=	145,
	ID_MAINGAME_ENEMY4_REGENTIME=	146,

	//ĳ���� ����
	ID_MAINGAME_CHAR0_DIE		=	150,
	ID_MAINGAME_CHAR1_DIE		=	151,
	ID_MAINGAME_CHAR2_DIE		=	152,
	ID_MAINGAME_CHAR3_DIE		=	153,

	ID_MAINGAME_ENEMY0_DIE		=	154,
	ID_MAINGAME_ENEMY1_DIE		=	155,
	ID_MAINGAME_ENEMY2_DIE		=	156,
	ID_MAINGAME_ENEMY3_DIE		=	157,
	ID_MAINGAME_ENEMY4_DIE		=	158,

	ID_MAINGAME_MINIMAP_FRAME	=	201,
	ID_MAINGAME_MINIMAP_MAP		=	202,

	ID_MAINGAME_CHARLEFT_FRAME	=	350,
	ID_MAINGAME_CHARRIGHT_FRAME	=	351,
	ID_MAINGAME_CHARSTAMINA_FRAME=	352,
	ID_MAINGAME_CHARNAME_BG	=353,
	ID_MAINGAME_BOSS_FRAME	=	354,

	ID_MAINGAME_CHAR0_FRAME	=	401,
	ID_MAINGAME_CHAR1_FRAME	=	411,
	ID_MAINGAME_CHAR2_FRAME	=	421,
	ID_MAINGAME_CHAR3_FRAME	=	431,

	ID_MAINGAME_ENEMY0_FRAME=	501,
	ID_MAINGAME_ENEMY1_FRAME=	511,
	ID_MAINGAME_ENEMY2_FRAME=	521,
	ID_MAINGAME_ENEMY3_FRAME=	531,
	ID_MAINGAME_ENEMY4_FRAME=	541,

	ID_MAINGAME_CHAR0_BACKLIGHT	=	550,
	ID_MAINGAME_CHAR1_BACKLIGHT	=	551,
	ID_MAINGAME_CHAR2_BACKLIGHT	=	552,
	ID_MAINGAME_CHAR3_BACKLIGHT	=	553,

	ID_MAINGAME_ENEMY0_BACKLIGHT=	561,
	ID_MAINGAME_ENEMY1_BACKLIGHT=	562,
	ID_MAINGAME_ENEMY2_BACKLIGHT=	563,
	ID_MAINGAME_ENEMY3_BACKLIGHT=	564,
	ID_MAINGAME_ENEMY4_BACKLIGHT=	565,

	ID_MAINGAME_CHAR0_NAME		=	601,
	ID_MAINGAME_CHAR1_NAME		=	611,
	ID_MAINGAME_CHAR2_NAME		=	621,
	ID_MAINGAME_CHAR3_NAME		=	631,

	ID_MAINGAME_ENEMY0_NAME		=	701,
	ID_MAINGAME_ENEMY1_NAME		=	711,
	ID_MAINGAME_ENEMY2_NAME		=	721,
	ID_MAINGAME_ENEMY3_NAME		=	731,
	ID_MAINGAME_ENEMY4_NAME		=	741,

	ID_MAINGAME_CHAR0_ENERGY	=	801,
	ID_MAINGAME_CHAR1_ENERGY	=	811,
	ID_MAINGAME_CHAR2_ENERGY	=	821,
	ID_MAINGAME_CHAR3_ENERGY	=	831,

	ID_MAINGAME_SHARED_POS_CHAR0=	851,
	ID_MAINGAME_SHARED_POS_CHAR1=	861,
	ID_MAINGAME_SHARED_POS_CHAR2=	871,
	ID_MAINGAME_SHARED_POS_CHAR3=	881,

	ID_MAINGAME_ENEMY0_ENERGY	=	901,
	ID_MAINGAME_ENEMY1_ENERGY	=	911,
	ID_MAINGAME_ENEMY2_ENERGY	=	921,
	ID_MAINGAME_ENEMY3_ENERGY	=	931,
	ID_MAINGAME_ENEMY4_ENERGY	=	941,

	ID_MAINGAME_SHARED_POS_ENEMY0=	951,
	ID_MAINGAME_SHARED_POS_ENEMY1=	961,
	ID_MAINGAME_SHARED_POS_ENEMY2=	971,
	ID_MAINGAME_SHARED_POS_ENEMY3=	981,
	ID_MAINGAME_SHARED_POS_ENEMY4=	991,

	ID_MAINGAME_BOSS_ENERGY		=	992,

	ID_MAINGAME_CHAT_BAR		=	1001,	
	ID_MAINGAME_MESSAGEBOX_01	=	1011,
	ID_MAINGAME_MESSAGEBOX_02	=	1021,

	ID_MAINGAME_MESSAGEBOX_01_UP=	1031,
	ID_MAINGAME_MESSAGEBOX_01_DN=	1041,
	ID_MAINGAME_MESSAGEBOX_01_HOME=	1051,
	ID_MAINGAME_MESSAGEBOX_01_END=	1061,

	// ������ �޽��� (����)
	ID_MAINGAME_HELP_MESSAGE	=	1150,
	//EXP
	ID_MAINGAME_EXP				=	1160,
	ID_MAINGAME_EXPBG			=	1161,

	//�޸���
	ID_MAINGAME_RUN				=	1170,

	//  ĳ���� �Ӹ��� ������
	ID_MAINGAME_CHAR0BALLOON	=	1200,
	ID_MAINGAME_CHAR1BALLOON	=	1201,
	ID_MAINGAME_CHAR2BALLOON	=	1202,
	ID_MAINGAME_CHAR3BALLOON	=	1203,
	ID_MAINGAME_CHAR0BALLOON_FRAME=	1210,
	ID_MAINGAME_CHAR1BALLOON_FRAME=	1211,
	ID_MAINGAME_CHAR2BALLOON_FRAME=	1212,
	ID_MAINGAME_CHAR3BALLOON_FRAME=	1213,
	ID_MAINGAME_CHAR0BALLOON_NAME=	1300,
	ID_MAINGAME_CHAR1BALLOON_NAME=	1301,
	ID_MAINGAME_CHAR2BALLOON_NAME=	1302,
	ID_MAINGAME_CHAR3BALLOON_NAME=	1303,

	// �� ĳ���� �Ӹ��� ������
	ID_MAINGAME_ENEMY0BALLOON	=	1400,
	ID_MAINGAME_ENEMY1BALLOON	=	1401,
	ID_MAINGAME_ENEMY2BALLOON	=	1402,
	ID_MAINGAME_ENEMY3BALLOON	=	1403,
	ID_MAINGAME_ENEMY0BALLOON_FRAME	=1410,
	ID_MAINGAME_ENEMY1BALLOON_FRAME=	1411,
	ID_MAINGAME_ENEMY2BALLOON_FRAME=	1412,
	ID_MAINGAME_ENEMY3BALLOON_FRAME=	1413,
	ID_MAINGAME_ENEMY0BALLOON_NAME=	1500,
	ID_MAINGAME_ENEMY1BALLOON_NAME=	1501,
	ID_MAINGAME_ENEMY2BALLOON_NAME=	1502,
	ID_MAINGAME_ENEMY3BALLOON_NAME=	1503,

	// ���� Ÿ��
	ID_MAINGAME_ATTACKTAGET		=	1600,
	ID_MAINGAME_ATTACKTAGET_FRAME=	1700,
	ID_MAINGAME_ATTACKTAGET_NAME=	1800,

	// Effect
	ID_MAINGAME_EFFECT			=	1900,

	ID_CHARFACE_START			=	2000,

	ID_MONSTERFACE_START		=	50000,

	//===============================================================================================================================================//
	// ���â -- ����
	//===============================================================================================================================================//
	// ��׶���
	ID_GAMERESULT_BACKGROUND1	=	5000,
	ID_GAMERESULT_BACKGROUND2,
	ID_GAMERESULT_BACKGROUND3,

	// �ʵ�
	ID_GAMERESULT_FIELD,

	ID_GAMERESULT_FILED_00,					// ����ų
	ID_GAMERESULT_FILED_01,					// ���̵� , ĳ���� ų��,
	ID_GAMERESULT_FILED_02,					// ��ȰȽ��
	ID_GAMERESULT_FILED_03,					// �������
	ID_GAMERESULT_FILED_04,					// ��������
	ID_GAMERESULT_FILED_05,					// ��ɰ��, ������, ����Ʈ ���
	ID_GAMERESULT_FILED_06,					// �����ð�

	ID_GAMERESULT_FILED_07,					// ����ų			��
	ID_GAMERESULT_FILED_08,					// ���̵� , ĳ���� ų��,	��
	ID_GAMERESULT_FILED_09,					// ��ȰȽ��	��
	ID_GAMERESULT_FILED_10,					// �������	��
	ID_GAMERESULT_FILED_11,					// ��������	��
	ID_GAMERESULT_FILED_12,					// ��ɰ��, ������, ����Ʈ ���	��
	ID_GAMERESULT_FILED_13,					// �����ð�	��

	ID_GAMERESULT_PROGRESS,					// ���α׷�����

	ID_GAMERESULT_FILED_ITEM1,				// ������
	ID_GAMERESULT_FILED_PC1,					// PC ��
	ID_GAMERESULT_FILED_EVENT1,				// �̺�Ʈ

	ID_GAMERESULT_FILED_ITEM2,				// ������
	ID_GAMERESULT_FILED_PC2,					// PC ��
	ID_GAMERESULT_FILED_EVENT2,				// �̺�Ʈ

	ID_GAMERESULT_FILED_GOLD,				// ����
	ID_GAMERESULT_FILED_EXP,				// ����ġ

	// ������
	ID_GAMERESULT_VS_BACKGROUND,			// ��׶���

	// ��
	ID_GAMERESULT_VS_SHAREDFACE_00,
	ID_GAMERESULT_VS_SHAREDFACE_01,
	ID_GAMERESULT_VS_SHAREDFACE_02,
	ID_GAMERESULT_VS_SHAREDFACE_03,


	ID_GAMERESULT_VS_CHARNAME_00,					// ĳ���� �̸�
	ID_GAMERESULT_VS_CHARNAME_01,					// ĳ���� �̸�
	ID_GAMERESULT_VS_CHARNAME_02,					// ĳ���� �̸�
	ID_GAMERESULT_VS_CHARNAME_03,					// ĳ���� �̸�

	ID_GAMERESULT_VS_OBTAINEDITEM_00,				// ������
	ID_GAMERESULT_VS_OBTAINEDITEM_01,				// ������
	ID_GAMERESULT_VS_OBTAINEDITEM_02,				// ������
	ID_GAMERESULT_VS_OBTAINEDITEM_03,				// ������

	ID_GAMERESULT_VS_SKILLPOS_00,					//��ų ������
	ID_GAMERESULT_VS_SKILLPOS_01,					//��ų ������
	ID_GAMERESULT_VS_SKILLPOS_02,					//��ų ������
	ID_GAMERESULT_VS_SKILLPOS_03,					//��ų ������

	ID_GAMERESULT_VS_ITEMNAME_00,					// ������ �̸�
	ID_GAMERESULT_VS_ITEMNAME_01,					// ������ �̸�
	ID_GAMERESULT_VS_ITEMNAME_02,					// ������ �̸�
	ID_GAMERESULT_VS_ITEMNAME_03,					// ������ �̸�


	ID_GAMERESULT_VS_V,							// ��	
	ID_GAMERESULT_VS_S,							// ��
	ID_GAMERESULT_VS_P,							// ��

	ID_GAMERESULT_VS_POINT,						// ��������


	// ��ɸ��
	ID_GAMERESULT_KILL_BACKGROUND,			// ��׶���

	// ��
	ID_GAMERESULT_KILL_SHAREDFACE_00,
	ID_GAMERESULT_KILL_SHAREDFACE_01,
	ID_GAMERESULT_KILL_SHAREDFACE_02,
	ID_GAMERESULT_KILL_SHAREDFACE_03,



	ID_GAMERESULT_KILL_CHARNAME_00,					// ĳ���� �̸�
	ID_GAMERESULT_KILL_CHARNAME_01,					// ĳ���� �̸�
	ID_GAMERESULT_KILL_CHARNAME_02,					// ĳ���� �̸�
	ID_GAMERESULT_KILL_CHARNAME_03,					// ĳ���� �̸�

	ID_GAMERESULT_KILL_OBTAINEDITEM_00,				// ������
	ID_GAMERESULT_KILL_OBTAINEDITEM_01,				// ������
	ID_GAMERESULT_KILL_OBTAINEDITEM_02,				// ������
	ID_GAMERESULT_KILL_OBTAINEDITEM_03,				// ������

	ID_GAMERESULT_KILL_SKILLPOS_00,					//��ų ������
	ID_GAMERESULT_KILL_SKILLPOS_01,					//��ų ������
	ID_GAMERESULT_KILL_SKILLPOS_02,					//��ų ������
	ID_GAMERESULT_KILL_SKILLPOS_03,					//��ų ������

	ID_GAMERESULT_KILL_ITEMNAME_00,					// ������ �̸�
	ID_GAMERESULT_KILL_ITEMNAME_01,					// ������ �̸�
	ID_GAMERESULT_KILL_ITEMNAME_02,					// ������ �̸�
	ID_GAMERESULT_KILL_ITEMNAME_03,					// ������ �̸�

	// ����Ʈ 1
	ID_GAMERESULT_QUEST_BACKGROUND,					// ��׶���
	ID_GAMERESULT_QUEST_NAME,						// ����Ʈ �̸�

	ID_GAMERESULT_QUEST_MISSION1,					// ����Ʈ ���� 1
	ID_GAMERESULT_QUEST_MISSION2,					// ����Ʈ ���� 2
	ID_GAMERESULT_QUEST_MISSION3,					// ����Ʈ ���� 3

	ID_GAMERESULT_QUEST_RESULT,						// ������

	ID_GAMERESULT_QUEST_GIVE_IMAGE,					// ���� �̹���
	ID_GAMERESULT_QUEST_GIVE_NAME,					// ���� �̸�

	ID_GAMERESULT_QUEST_GIVE_EXP,					// ���� ����ġ
	ID_GAMERESULT_QUEST_GIVE_GOLD,					// ���� ����

	// ����Ʈ 2
	ID_GAMERESULT_QUEST_BACKGROUND_2,					// ��׶���
	ID_GAMERESULT_QUEST_NAME_2,						// ����Ʈ �̸�

	ID_GAMERESULT_QUEST_MISSION1_2,					// ����Ʈ ���� 1
	ID_GAMERESULT_QUEST_MISSION2_2,					// ����Ʈ ���� 2
	ID_GAMERESULT_QUEST_MISSION3_2,					// ����Ʈ ���� 3

	ID_GAMERESULT_QUEST_RESULT_2,						// ������

	ID_GAMERESULT_QUEST_GIVE_IMAGE_2,					// ���� �̹���
	ID_GAMERESULT_QUEST_GIVE_NAME_2,					// ���� �̸�

	ID_GAMERESULT_QUEST_GIVE_EXP_2,					// ���� ����ġ
	ID_GAMERESULT_QUEST_GIVE_GOLD_2,					// ���� ����
	//===============================================================================================================================================//
	// ���â -- ��
	//===============================================================================================================================================//

	//===============================================================================================================================================//
	// ����Ʈ -- ����
	//===============================================================================================================================================//
	ID_GAME_QUEST_MISSION1			= 20000,
	ID_GAME_QUEST_MISSION2,
	ID_GAME_QUEST_MISSION3,
	//===============================================================================================================================================//
	// ����Ʈ -- ��
	//===============================================================================================================================================//


	//===============================================================================================================================================//
	// �������� -- ����
	//===============================================================================================================================================//
	ID_LEAVING_BG	=	7500,
	ID_LEAVING_MSG1	=	7501,	
	ID_LEAVING_OK	=	7502,
	ID_LEAVING_CENCLE=	7503,
	//===============================================================================================================================================//
	// �������� -- ��
	//===============================================================================================================================================//

	//===============================================================================================================================================//
	// ������ -- ����
	//===============================================================================================================================================//
	ID_MYBAG_BUTTON		= 7600,
	//===============================================================================================================================================//
	// ������ -- ��
	//===============================================================================================================================================//

	//��ų ������
	ID_GAMERESULT_SKILLPOS		=	5300,

	//��Ȱ
	ID_GAMERESURRECTION_BG	=	7000,
	ID_GAMERESURRECTION_TITLE	=	7001,
	ID_GAMERESURRECTION_MSG1	=	7002,
	ID_GAMERESURRECTION_MSG2	=	7003,
	ID_GAMERESURRECTION_MSG3	=	7004,
	ID_GAMERESURRECTION_OK	=	7005,
	ID_GAMERESURRECTION_CENCLE=	7006,
	ID_GAMERESURRECTION_BG_ICON = 7007,


	// �ɼ�
	ID_MAINGAME_OPTION_GAMEKEY_BG		=	8000,
	ID_MAINGAME_OPTION_KEY_JUMP		=	8001,
	ID_MAINGAME_OPTION_KEY_ATTACK		=	8002,
	ID_MAINGAME_OPTION_KEY_CHANGEWEAPON=	8003,
	ID_MAINGAME_OPTION_KEY_RIDEPET		=	8004,
	ID_MAINGAME_OPTION_KEY_MOVEUP		=	8005,
	ID_MAINGAME_OPTION_KEY_MOVEDOWN	=	8006,
	ID_MAINGAME_OPTION_KEY_MOVERIGHT	=	8007,
	ID_MAINGAME_OPTION_KEY_MOVELEFT	=	8008,
	ID_MAINGAME_OPTION_KEY_TEAMSKILL1	=	8009,
	ID_MAINGAME_OPTION_KEY_TEAMSKILL2	=	8010,
	ID_MAINGAME_OPTION_KEY_TEAMSKILL3	=	8011,
	ID_MAINGAME_OPTION_KEY_TEAMSKILL4	=	8012,
	ID_MAINGAME_OPTION_KEY_SELOURTEAM	=	8013,
	ID_MAINGAME_OPTION_KEY_SELLEFTOPP	=	8014,
	ID_MAINGAME_OPTION_KEY_SELNEAROPP	=	8015,
	ID_MAINGAME_OPTION_KEY_SELRIGHTOPP	=	8016,
	ID_MAINGAME_OPTION_KEY_SHOWINFO	=	8017,
	ID_MAINGAME_OPTION_KEY_SHOWHELP	=	8018,
	ID_MAINGAME_OPTION_SHOTCUT_BG		=	8019,
	ID_MAINGAME_OPTION_SHOTCUT_TITLE	=	8020,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL01	=	8021,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL02	=	8022,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL03	=	8023,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL04	=	8024,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL05	=	8025,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL06	=	8026,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL07	=	8027,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL08	=	8028,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL09	=	8029,
	ID_MAINGAME_OPTION_SHOTCUT_SKILL10	=	8030,

	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL01=		8031,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL02=		8032,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL03=		8033,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL04=		8034,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL05=		8035,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL06=		8036,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL07=		8037,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL08=		8038,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL09=		8039,
	ID_MAINGAME_OPTION_SHOTCUT_COMSKILL10=		8040,
	ID_MAINGAME_OPTION_CONFIRM_KEYSETUP=	8041,
	ID_MAINGAME_OPTION_RADIO_GROUP	=8042,
	ID_MAINGAME_OPTION_GAME_KEY	=8043,
	ID_MAINGAME_OPTION_SKILL_KEY	=8044,
	ID_MAINGAME_OPTION_COMSKILL_KEY=	8045,
	ID_MAINGAME_BASE_OPTION_FIELDRIGHT = 8046,

	ID_SKILLICON_START			=	20000,
	ID_TEAMSKILLICON_START		=	50000,

	ID_SKILLICON_MAINGAME_POS01	=	25001,
	ID_SKILLICON_MAINGAME_POS02	=	25002,
	ID_SKILLICON_MAINGAME_POS03	=	25003,
	ID_SKILLICON_MAINGAME_POS04	=	25004,
	ID_SKILLICON_MAINGAME_POS05	=	25005,
	ID_SKILLICON_MAINGAME_POS06	=	25006,
	ID_SKILLICON_MAINGAME_POS07	=	25007,
	ID_SKILLICON_MAINGAME_POS08	=	25008,
	ID_SKILLICON_MAINGAME_POS09	=	25009,
	ID_SKILLICON_MAINGAME_POS10	=	25010,

	ID_SKILLICON_MAINGAME_POS11	=	25011,
	ID_SKILLICON_MAINGAME_POS12	=	25012,
	ID_SKILLICON_MAINGAME_POS13	=	25013,
	ID_SKILLICON_MAINGAME_POS14	=	25014,
	ID_SKILLICON_MAINGAME_POS15	=	25015,
	ID_SKILLICON_MAINGAME_POS16	=	25016,
	ID_SKILLICON_MAINGAME_POS17	=	25017,
	ID_SKILLICON_MAINGAME_POS18	=	25018,
	ID_SKILLICON_MAINGAME_POS19	=	25019,
	ID_SKILLICON_MAINGAME_POS20	=	25020,


	ID_SKILLICON_MAINGAME_POSA	=	25021,
	ID_SKILLICON_MAINGAME_POSB	=	25022,
	ID_SKILLICON_MAINGAME_POSC	=	25023,
	ID_SKILLICON_MAINGAME_POSD	=	25024,

	ID_SKILLICON_MAINGAME_POSAA	=	25025,
	ID_SKILLICON_MAINGAME_POSBB	=	25026,
	ID_SKILLICON_MAINGAME_POSCC	=	25027,
	ID_SKILLICON_MAINGAME_POSDD	=	25028,

	ID_MAINGAME_MENU_MINIMAP	=		26100,
	ID_MAINGAME_MENU_QUESTLIST	=		26101,
	ID_MAINGAME_MENU_OUT		=		26102,
	ID_MAINGAME_TOTALMAP		=		26103,

	ID_BUFF_CHAR01_01		=		30011,
	ID_BUFF_CHAR01_02		=		30012,
	ID_BUFF_CHAR01_03		=		30013,
	ID_BUFF_CHAR01_04		=		30014,
	ID_BUFF_CHAR01_05		=		30015,
	ID_BUFF_CHAR02_01		=		30021,
	ID_BUFF_CHAR02_02		=		30022,
	ID_BUFF_CHAR02_03		=		30023,
	ID_BUFF_CHAR02_04		=		30024,
	ID_BUFF_CHAR02_05		=		30025,
	ID_BUFF_CHAR03_01		=		30031,
	ID_BUFF_CHAR03_02		=		30032,
	ID_BUFF_CHAR03_03		=		30033,
	ID_BUFF_CHAR03_04		=		30034,
	ID_BUFF_CHAR03_05		=		30035,
	ID_BUFF_CHAR04_01		=		30041,
	ID_BUFF_CHAR04_02		=		30042,
	ID_BUFF_CHAR04_03		=		30043,
	ID_BUFF_CHAR04_04		=		30044,
	ID_BUFF_CHAR04_05		=		30045,

	ID_BUFF_ENEMY01_01		=		30111,
	ID_BUFF_ENEMY01_02		=		30112,
	ID_BUFF_ENEMY01_03		=		30113,
	ID_BUFF_ENEMY01_04		=		30114,
	ID_BUFF_ENEMY01_05		=		30115,
	ID_BUFF_ENEMY02_01		=		30121,
	ID_BUFF_ENEMY02_02		=		30122,
	ID_BUFF_ENEMY02_03		=		30123,
	ID_BUFF_ENEMY02_04		=		30124,
	ID_BUFF_ENEMY02_05		=		30125,
	ID_BUFF_ENEMY03_01		=		30131,
	ID_BUFF_ENEMY03_02		=		30132,
	ID_BUFF_ENEMY03_03		=		30133,
	ID_BUFF_ENEMY03_04		=		30134,
	ID_BUFF_ENEMY03_05		=		30135,
	ID_BUFF_ENEMY04_01		=		30141,
	ID_BUFF_ENEMY04_02		=		30142,
	ID_BUFF_ENEMY04_03		=		30143,
	ID_BUFF_ENEMY04_04		=		30144,
	ID_BUFF_ENEMY04_05		=		30145,
	ID_BUFF_ENEMY05_01		=		30151,
	ID_BUFF_ENEMY05_02		=		30152,
	ID_BUFF_ENEMY05_03		=		30153,
	ID_BUFF_ENEMY05_04		=		30154,
	ID_BUFF_ENEMY05_05		=		30155,
	

	// Modal Dialog
	ID_MODAL_BKGND			=		40000,
	ID_MODAL_TITAL			=		40001,
	ID_MODAL_MSG			=		40002,
	ID_MODAL_EXIT			=		40003,
	ID_MODAL_CANCLE			=		40004,

	ID_MODAL_QUESTION_BKGND =		41000,
	ID_MODAL_QUESTION_TITAL =		41001,
	ID_MODAL_QUESTION_MSG	=		41002,
	ID_MODAL_QUESTION_OK	=		41003,



	ID_GAMETOOLTIP			=		100000,
	ID_GAMEBUFTOOLTIP		=		100001,
};

typedef enum GAME_MODE
{
	PW_GAME_BATTLE = 0,
	PW_GAME_STORY,	
	PW_GAME_QUEST,
};

void CALLBACK OnGUIEvent_MainUIControl(UINT nEvent, int nControlID, ANW::StatusUI_Control* pControl, void* pUserContext);

class yb_MainUIControl
{
protected:

	ANW::StatusUI_Manager*	m_pStatusUI_Main;
	ANW::StatusUI_Manager*	m_pStatusUI_Char;
	ANW::StatusUI_Manager*	m_pStatusUI_Dash;	
	ANW::StatusUI_Manager*	m_pStatusUI_Story;
	ANW::StatusUI_Manager*	m_pStatusUI_Key;

	ANW::StatusUI_Manager*	m_pStatusUI_Result_BackGround_1;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_BackGround_2;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_Fild;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_VS;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_KILL;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_QUEST_1;
	ANW::StatusUI_Manager*	m_pStatusUI_Result_QUEST_2;

	unsigned int		m_uDashBoardIndex;

	// Game Mode
	int					m_nGameMode;

	// Modal Dialog
	ANW::StatusUI_Manager*		m_pModal_ExitQuestion;
	ANW::StatusUI_Manager*		m_pModal_Resurrection;
	ANW::StatusUI_Manager*		m_pModal_Question;
	ANW::StatusUI_Manager*		m_pModal_Leaving;

	// ���� �ȿ��� ������ ���� ���ؼ�
	ANW::StatusUI_Manager*		m_pGameMyBag;

protected:

	// load
	bool				loadUI(ANW::StatusUI_Manager** pManager, CStringW strFilename);

public:

	yb_MainUIControl();
	~yb_MainUIControl();


	// gameExiut Question Modal
	void				DoModal_GameExitQuestion(CStringW strIn, int posX = 377, int posY=277);

	// Game_Question Modal
	void				DoModal_GameQuestion( const CStringW& strIn );


	// ���ӳ��� ������ ���Ұ��� �����...�κ�ε��ƿ����� ��ų��ġ Ŭ���� ĳ���Ͱ� �����Ѵ�.
	void				GameAllEnable( const bool& bFlag );





	// Game Mode
	void				SetGameMode( int nmode )	{ m_nGameMode = nmode;			}
	int					GetGameMode()				{ return m_nGameMode;			}
	// set callback
	void				setCallback(ANW::PCALLBACKSTATUSGUIEVENT pCallback);

	// load
	bool				loadUI_Main( void );
	bool				loadUI_Char( void );
	bool				loadUI_Dash( void );
	bool				loadUI_Result_BackGround_1( void );
	bool				loadUI_Result_BackGround_2( void );
	bool				loadUI_Result_Fild( void );
	bool				loadUI_Result_VS( void );
	bool				loadUI_Result_KILL( void );
	bool				loadUI_Result_QUEST_1( void );
	bool				loadUI_Result_QUEST_2( void );
	bool				loadUI_Modal_ExitQuestion( void );	
	bool				loadUI_StoryMain( void );
	bool				loadUI_Modal_Resurrection( void );
	bool				loadUI_Key( void );
	bool				loadUI_Modal_Question( void );
	bool				loadUI_Modal_Leaving( void );
	bool				loadUI_Bag( void );

	bool				loadUI_All( void );	

	void				loadUI_AllInitVisual( void );



	// render
	void				render(IDirect3DDevice9* pDevice);
	void				renderResult(IDirect3DDevice9* pDevice);
	void				StoryRender( IDirect3DDevice9* pDevice );

	// set exp, time, money
	void				setExp(unsigned int uExp);
	void				setMoney(unsigned int uMoney);
	void				setTime(unsigned int uMinute, unsigned int uSecond);
	void				setExpProgressbar( float nMax, float fCurr );
	void				setRunProgressbar( float nMax, float fCurr );

	// character setting
	void				hideAllChar();
	void				hideAllEnemy();
	void				showChar(unsigned int nOrdinal, bool bFlag);
	void				showEnemy(unsigned int nOrdinal, bool bFlag);
	void				setCharName(unsigned int nOrdinal, int nLv, CStringW strName);
	void				setEnemyName(unsigned int nOrdinal, int nLv, CStringW strName);
	void				setCharName(unsigned int nOrdinal, int nLv, char* strName);
	void				setEnemyName(unsigned int nOrdinal, int nLv,  char* strName);
	void				setCharEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent);
	void				setEnemyEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent);	
	void				setCharFace(unsigned int nOrdinal, int nFaceOrdinal, bool bMonster);
	void				setEnemyFace(unsigned int nOrdinal, int nFaceOrdinal, bool bMonster);
	void				showRegenTime(bool bChar, int nOrdinal, bool bFlag);
	void				setRegenTime(bool bChar, int nOrdinal, unsigned int uCurTime);
	void				setBufIcon(bool bChar, int nOrdinal, int nBufOrdinal, int nIconID);
	void				setBufOnOff(bool bChar, int nOrdinal, int nBufOrdinal, bool bFlag);
	void				setBufCoolTime(bool bChar, int nOrdinal, int nBufOrdinal, unsigned int uCoolTime);
	void				setBufUseCoolTime(bool bChar, int nOrdinal, int nBufOrdinal, bool bFlag);
	void				setCharDie( int nOrdinal, bool bFlag );
	void				setCharBackLight( int nOrdinal, bool bFlag );
	void				setEnemyBackLight( int nOrdinal, bool bFlag );

	void				showCharBalloon( int nOrdinal, bool bFlag );
	void				setCharBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent);
	void				setCharBalloonPos( unsigned int nOrdinal, float fX, float fY );

	void				showEnemyBalloon( int nOrdinal, bool bFlag );
	void				setEnemyBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent);
	void				setEnemyBalloonPos( unsigned int nOrdinal, float fX, float fY );

	void				showAttackTagetBalloon( int nOrdinal, bool bFlag );
	void				setAttackTagetBalloonEnergy(unsigned int nOrdinal, unsigned int uMax, unsigned int uCurrent, CStringW strName );
	void				setAttackTagetBalloonPos( unsigned int nOrdinal, float fX, float fY );

	void				showCharDie( int nOrdinal, bool bFlag );
	void				showEnemyDie( int nOrdinal, bool bFlag );

	void				showBossEnergy( bool bFlag );
	void				setBossEnergy( unsigned int uMax, unsigned int uCurrent );



	// ��� ��Ȱ�ð�
	void				showCenterRegenTime( bool bFlag );
	void				setCenterRegenTime(unsigned int uCurTime);
	// ��Ȱ �ð� �ؽ�Ʈ
	void				setConterRegen( bool bFlag, unsigned int cCurTime );

	/* ��Ȱ �����ۻ���Ͽ��� ������ �˾�â � */
	void				ShowResurrection( bool bShow, int nItemCount = 0 );
	void				SetResurrectionTime( unsigned int nTime );


	// ����Ʈ
	void				setEffect( int nOrdinal, float fX, float fY, unsigned int uDamage, bool bFlag );

	// minimap setting
	void				addMonsterPos(float fU, float fV);
	void				addBluePos(float fU, float fV);
	void				addRedPos(float fU, float fV);
	void				addPlayerPos( float fU, float fV );//���丮���
	void				clearAllPos();
	void				setMistStatus(BOOL m0, BOOL m1, BOOL m2, BOOL m3, BOOL m4, BOOL m5, BOOL m6);
	void				setProgressStatus(int m0, int m1, int m2, int m3, int m4, int m5, int m6);
	void				setMinimap(CStringW filename);
	void				setTotalMap(CStringW strfilename);
	void				setTotalMapShow( bool bFlag );
	bool				GetButtonCheckMini();						//���丮��忡�� ��ư�� ���ȳ� üũ(��ü����)
	bool				GetButtonCheckQuest();						//���丮��忡�� ��ư�� ���ȳ� üũ(��ü����)
	void				AddPlayerMovePos( const float& fU, const float& fV );	// �÷��̾� �̵� ����

	void				SetCurrentPos(int nIndex );		// ��ü�������� ������ġ
	void				SetAfterPos( int nSlot, int nIndex );		// ��ü�������� ������ ��ġ
	void				ClearTotalMap();

	// dashboard setting
	void				clearDashboard();
	void				setIcon(unsigned int uOrdinal, bool bShow, int nSkill_ID, bool bShowHotkey, unsigned int uHotkey, bool bShowCooltime, unsigned int uCooltime, bool bShowStockCount, unsigned int uStockCount);
	void				setIconVisibility(unsigned int uOrdinal, bool bShow);
	bool				getIconVisibility( unsigned int uOrdinal );
	void				setIconID(unsigned int uOrdinal, int nID);
	void				setHotkeyVisibility(unsigned int uOrdinal, bool bShow);
	void				setHotkeyValue(unsigned int uOrdinal, char szHotkey);
	void				setHotkey(unsigned int uOrdinal, bool bShow, char szHotkey);
	void				setCooltimeVisibility(unsigned int uOrdinal, bool bShow);
	void				setCooltimeValue(unsigned int uOrdinal, unsigned int uCooltime);
	void				setCooltime(unsigned int uOrdinal, bool bShow, unsigned int uCooltime);
	void				setStockCountVisibility(unsigned int uOrdinal, bool bShow);
	void				setStockCountValue(unsigned int uOrdinal, unsigned int uStockCount);
	void				setStockCount(unsigned int uOrdinal, bool bShow, unsigned int uStockCount);
	void				setDashBoardIndex(unsigned int uDashBoardIndex);
	unsigned int		getDashBoardIndex();
	void				enableSkillIcon(unsigned uOrdinal, bool bFlag);	
	int					GetCurrentSlotRectID( int nOrdinal );

	// dashboard selection hotkey
	void				setDashBoardSelectHotKey(unsigned int uHotKey);
	unsigned int		getDashBoardSelectHotKey();

	// chat message
	void				addMessage(CStringW strText, DWORD colorNormal, DWORD colorSelected, void* pData);
	void				addMessage(WCHAR* strText, DWORD colorNormal, DWORD colorSelected, void* pData);
	void				addMessage(char* strText, DWORD colorNormal, DWORD colorSelected, void* pData);
	void				scrollMessageBox(int nAmount);
	void				scrollHome();
	void				scrollEnd();
	void				focusChat(bool bFlag = true);
	void				ChatClear();


	// ���Ӽ��� ������ �ؽ�Ʈ ǥ��
	void				setGameHelpMessage( bool bFlag, CStringW strIn );

	// tooltip	
	int						getItemIndexNumber();
	bool					getMouseIn_Out( );
	bool					getMouseIn_Out( const int& nID );

	void					setShowToolTip( bool nFlag );
	void					setShowToolTip( const int& nID, bool nFlag );		// �������


	void					removeToolTipList();
	void					setToolTipNoMessage();
	ANW::StatusUI_Control*	getContorl();

	// tooltip information( Skill )
	void					ToolTip_ItemName(CStringW strIn, COLORREF color );										// ������ �̸�
	void					ToolTip_ItemName(const char* strIn, COLORREF color );
	void					ToolTip_ItemName(const WCHAR* strIn, COLORREF color );
	void					ToolTip_Step(int nValue, COLORREF color);												// ���繫���ܰ�

	void					ToolTip_Character(CStringW strIn, COLORREF color );										// ���ĳ���� �̸�
	void					ToolTip_Character(const char* strIn, COLORREF color );										// ���ĳ���� �̸�
	void					ToolTip_Character(const WCHAR* strIn, COLORREF color );										// ���ĳ���� �̸�

	void					ToolTip_Level( int nValue,  COLORREF color );											// ��뷹��

	void					ToolTip_Oder(CStringW strIn, COLORREF color);											// �����迭
	void					ToolTip_Oder(const char* strIn, COLORREF color);
	void					ToolTip_Oder(const WCHAR* strIn, COLORREF color);
	void					ToolTip_Embarkation(CStringW strIn, COLORREF color);									// ��»�뿩��
	void					ToolTip_Embarkation(const char* strIn, COLORREF color);
	void					ToolTip_Embarkation(const WCHAR* strIn, COLORREF color);
	void					ToolTip_Arms(CStringW strIn, COLORREF color);											// ��빫��
	void					ToolTip_Arms(const char* strIn, COLORREF color);
	void					ToolTip_Arms(const WCHAR* strIn, COLORREF color);
	void					ToolTip_ConsumptionLife(int nValue, COLORREF color);									// �ߵ��Ҹ����
	void					ToolTip_ConsumptionPoint(int nValue, COLORREF color);									// �ߵ��Ҹ�����Ʈ
	void					ToolTip_AgainTime(int nValue, COLORREF color);											// ����ð�
	void					ToolTip_BeefUpStep(int nValue, COLORREF color);											// ������ȭ�ܰ�

	void					ToolTip_ItemExplanation(CStringW strIn, COLORREF color);								// ������ ����
	void					ToolTip_ItemExplanation(const char* strIn, COLORREF color);
	void					ToolTip_ItemExplanation(const WCHAR* strIn, COLORREF color);

	// ��������
	bool					getBufMouseIn_Out();
	void					removeBufToolTipList();
	int						getBufItemIndexNumber();
	void					setBufShowToolTip( bool nFlag );
	void					BufToolTip_Explanation( const CStringW& strIn, const int& nLine, const COLORREF& color );
	void					BufToolTip_Explanation(const char* strIn, const int& nLine, const COLORREF& color );
	void					BufToolTip_Explanation(const WCHAR* strIn, const int& nLine, const COLORREF& color );

	// TeamSkill
	void					SetTeamSkill_Clean(void);
	void					SetTeamSkill_Show( int nSlot, bool bFlag );
	void					SetTeamSkill_Icon( int nSlot, int nSkillIndex );
	void					SetTeamSkill_IconClean( const int& nSlot );						// ��ų4���߿� �ش罺ų�� �ε����� -1�� �θ����


	// option �ɼ�
	void					ShowGameKeyState(bool bFlag);						// f12 ������ ����� ȣ��
	int						Get_Option_SelectKey();
	void					Show_Option_GameKey( bool bFlag );					// �ɼ� ����Ű
	void					Show_Option_Skill( bool bFlag );					// ��ų
	void					Show_Option_ComSkill( bool bFlag );					// ���뽺ų


	void				option_KB_setJump(WPARAM wParam);					// ����/�������ȯ
	void				option_KB_setAttack(WPARAM wParam);					// ����/�ݱ�
	void				option_KB_setChangeWeapon(WPARAM wParam);			// ���⺯��
	void				option_KB_setRidePet(WPARAM wParam);				// �� ž��/������
	void				option_KB_setMoveUp(WPARAM wParam);					// �����̵�
	void				option_KB_setMoveDown(WPARAM wParam);				// �Ʒ��̵�
	void				option_KB_setMoveRight(WPARAM wParam);				// �������̵�
	void				option_KB_setMoveLeft(WPARAM wParam);				// �����̵�
	void				option_KB_setTeamSkill1(WPARAM wParam);				// ������ų1
	void				option_KB_setTeamSkill2(WPARAM wParam);				// ������ų2
	void				option_KB_setTeamSkill3(WPARAM wParam);				// ������ų3
	void				option_KB_setTeamSkill4(WPARAM wParam);				// ������ų4
	void				option_KB_setSelectOurTeam(WPARAM wParam);			// �Ʊ�����
	void				option_KB_setSelectNearEnemy(WPARAM wParam);		// �������������
	void				option_KB_setSelectLeftEnemy(WPARAM wParam);		// �������������
	void				option_KB_setSelectRightEnemy(WPARAM wParam);		// ���������������
	void				option_KB_setShowInfo(WPARAM wParam);				// ����ǥ��
	void				option_KB_setShowHelp(WPARAM wParam);				// ����ǥ��

	// ���ེų	
	void				option_SC_setSkill01(WPARAM wParam);
	void				option_SC_setSkill02(WPARAM wParam);
	void				option_SC_setSkill03(WPARAM wParam);
	void				option_SC_setSkill04(WPARAM wParam);
	void				option_SC_setSkill05(WPARAM wParam);
	void				option_SC_setSkill06(WPARAM wParam);
	void				option_SC_setSkill07(WPARAM wParam);
	void				option_SC_setSkill08(WPARAM wParam);
	void				option_SC_setSkill09(WPARAM wParam);
	void				option_SC_setSkill10(WPARAM wParam);

	// ���뽺ų
	void				option_SC_setComSkill01(WPARAM wParam);
	void				option_SC_setComSkill02(WPARAM wParam);
	void				option_SC_setComSkill03(WPARAM wParam);
	void				option_SC_setComSkill04(WPARAM wParam);
	void				option_SC_setComSkill05(WPARAM wParam);
	void				option_SC_setComSkill06(WPARAM wParam);
	void				option_SC_setComSkill07(WPARAM wParam);
	void				option_SC_setComSkill08(WPARAM wParam);
	void				option_SC_setComSkill09(WPARAM wParam);
	void				option_SC_setComSkill10(WPARAM wParam);

	//=================================================================================================================
	// START - ���â
	//=================================================================================================================
	// �ʵ�
	void				Show_Result_FildWindow( const bool& bFlag );				// Ȱ�� ��Ȱ��

	void				Set_Result_Fild_Text_00( const CStringW&	strIn );		// ����ų
	void				Set_Result_Fild_Text_01( const CStringW&	strIn );		// ������ ĳ���� ��
	void				Set_Result_Fild_Text_02( const CStringW&	strIn );		// ��Ȱ Ƚ��
	void				Set_Result_Fild_Text_03( const CStringW&	strIn );		// �������	

	void				Set_Result_Fild_Text_04( const CStringW&	strIn );		// ��������
	void				Set_Result_Fild_Text_05( const CStringW&	strIn );		// ��ɰ��, ������, ����Ʈ ���
	void				Set_Result_Fild_Text_06( const CStringW&	strIn );		// �����ð�

	// ��
	void				Set_Result_Fild_Value_00( const CStringW&	strIn );		// ����ų
	void				Set_Result_Fild_Value_01( const CStringW&	strIn );		// ������ ĳ���� ��
	void				Set_Result_Fild_Value_02( const CStringW&	strIn );		// ��Ȱ Ƚ��
	void				Set_Result_Fild_Value_03( const CStringW&	strIn );		// �������
	void				Set_Result_Fild_Value_03_Visible( const bool& bFlag );		// ������� Ȱ�� ��Ȱ��
	void				Set_Result_Fild_Value_03_Progress( const int nMax, const int& nCurrent);		//������� ���α׷�����
	void				Set_Result_Fild_Value_03_Progress_Visible( const bool& bFlag );		//������� ���α׷����� Ȱ����Ȱ��

	void				Set_Result_Fild_Value_04( const CStringW&	strIn );		// ��������
	void				Set_Result_Fild_Value_05( const CStringW&	strIn );		// ��ɰ��, ������, ����Ʈ ���
	void				Set_Result_Fild_Value_06( const CStringW&	strIn );		// �����ð�


	// �߰� ����ġ
	void				Set_Result_Fild_ExpStatus( const bool& bFlag1, const bool& bFlag2, const bool& bFlag3 );			// ������, PC��, �̺�Ʈ
	// �߰� ����
	void				Set_Result_Fild_GoldStatus( const bool& bFlag1, const bool& bFlag2, const bool& bFlag3 );			// ������, PC��, �̺�Ʈ

	void				Set_Result_Fild_GOLD( const int& nGold );			// ȹ�����
	void				Set_Result_Fild_EXP( const int& nExp );				// ȹ�����ġ

	// ������
	void				Show_Result_VSWindow( const bool& bFlag );											// Ȱ��&��Ȱ��

	void				Set_Result_VS_FaceVisible( const int& nOrdinal, const bool& bFlag );				// ĳ���� �� -1 = �ʱ�ȭ Ȱ����Ȱ��
	void				Set_Result_VS_Face( const int& nPosOrdinal, const int& nOrdinal );					// ĳ���� ��

	void				Set_Result_VS_NameVisible( const int& nOrdinal, const bool& bFlag );				// ĳ���� �̸� Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_VS_Name( const int& nOrdinal, const CStringW& strName );					// ĳ���� �̸�

	void				Set_Result_VS_ItemVisible( const int& nOrdinal, const bool& bFlag );				// ������ Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_VS_ItemStatus( const int& nOrdinal, ANW::QUEST_SLOT_STATUS eStatus );	// ������ ������Ʈ QSS_YES = ����, QSS_NONE = ����
	void				Set_Result_VS_Item( const int& nOrdinal, const CStringW& strFileName );				// ������

	void				Set_Result_VS_SkillItemVisible( const int& nOrdinal, const bool& bFlag );			// ��ų������ Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_VS_SkillItem( const int& nOrdinal, const int& nSkillIndex );				// ��ų������

	void				Set_Result_VS_ItemNameVisible( const int& nOrdinal, const bool& bFlag );			// ������ �̸� Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_VS_ItemName( const int& nOrdinal, const CStringW& strName );				// ������ �̸�

	void				Set_Result_VS_Record( const int& nV, const int& nS, const int&nP);					// ������
	void				Set_Result_VS_Point( const int& nValue );											// ��������

	// ��ɸ��
	void				Show_Result_KillWindow( const bool& bFlag );										// Ȱ�� ��Ȱ��

	void				Set_Result_KILL_FaceVisible( const int& nOrdinal, const bool& bFlag );				// ĳ���� �� -1 �ʱ�ȭ
	void				Set_Result_KILL_Face( const int& nPosOrdinal, const int& nOrdinal );				// ĳ���� ��

	void				Set_Result_KILL_NameVisible( const int& nOrdinal, const bool& bFlag );				// ĳ���� �̸� Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_KILL_Name( const int& nOrdinal, const CStringW& strName );				// ĳ���� �̸�

	void				Set_Result_KILL_ItemVisible( const int& nOrdinal, const bool& bFlag );				// ������ Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_KILL_ItemStatus( const int& nOrdinal, ANW::QUEST_SLOT_STATUS eStatus );	// ������ ������Ʈ QSS_YES = ����, QSS_NONE = ����
	void				Set_Result_KILL_Item( const int& nOrdinal, const CStringW& strFileName );			// ������

	void				Set_Result_KILL_SkillItemVisible( const int& nOrdinal, const bool& bFlag );			// ��ų������ Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_KILL_SkillItem( const int& nOrdinal, const int& nSkillIndex );			// ��ų������

	void				Set_Result_KILL_ItemNameVisible( const int& nOrdinal, const bool& bFlag );			// ������ �̸� Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				Set_Result_KILL_ItemName( const int& nOrdinal, const CStringW& strName );			// ������ �̸�	

	// ����Ʈ_1
	void				Show_Result_Quest_1_Windos( const bool& bFlag1, const bool& bFlag2 );				// bFlag1 = Ȱ����Ȱ�� bFlag2 = ����Ʈ���� true = 1��, false = 2��

	void				Set_Result_Quest_1_Name( const CStringW& strName );									// ����Ʈ �̸� - 1 �ʱ�ȭ

	void				Set_Result_Quest_1_MIssionVisible( const int& nOrdinal, const bool& bFlag );		// -1 �ʱ�ȭ
	void				Set_Result_Quest_1_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag );	// nOrdinal ; 0,1,2 strIn = ����, bflag = �Ϸ��ߴ°�?

	void				Set_Result_Quest_1_Restult( const CStringW& strIn );								// ������ -1�ʱ�ȭ

	void				Set_Result_Quest_1_ItemVisible( const bool& bFlag );								// ������ Ȱ�� ��Ȱ��
	void				Set_Result_Quest_1_ItemStatus( ANW::QUEST_SLOT_STATUS eStatus );					// ������ ������Ʈ QSS_YES = ����, QSS_NONE = ����
	void				Set_Result_Quest_1_Item( const CStringW& strFileName );								// ������
	void				Set_Result_Quest_1_ItemNameVisible( const bool& bFlag );							// ������ �̸� Ȱ����Ȱ��
	void				Set_Result_Quest_1_ItemName( const CStringW& strItemName );							// ������ �̸�

	void				Set_Result_Quest_1_Exp( const CStringW& strExp );									// ���� ����ġ
	void				Set_Result_Quest_1_Gold( const CStringW& strExp );									// ���� ����
	// ����Ʈ_2
	void				Show_Result_Quest_2_Windos( const bool& bFlag );										//  Ȳ����Ȱ��

	void				Set_Result_Quest_2_Name( const CStringW& strName );									// ����Ʈ �̸�

	void				Set_Result_Quest_2_MIssionVisible( const int& nOrdinal, const bool& bFlag );		// -1 �ʱ�ȭ
	void				Set_Result_Quest_2_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag );	// nOrdinal ; 0,1,2 strIn = ����, bflag = �Ϸ��ߴ°�?

	void				Set_Result_Quest_2_Restult( const CStringW& strIn );								// ������

	void				Set_Result_Quest_2_ItemVisible( const bool& bFlag );								// ������ Ȱ�� ��Ȱ��
	void				Set_Result_Quest_2_ItemStatus( ANW::QUEST_SLOT_STATUS eStatus );					// ������ ������Ʈ QSS_YES = ����, QSS_NONE = ����
	void				Set_Result_Quest_2_Item( const CStringW& strFileName );								// ������
	void				Set_Result_Quest_2_ItemNameVisible( const bool& bFlag );							// ������ �̸� Ȱ����Ȱ��
	void				Set_Result_Quest_2_ItemName( const CStringW& strItemName );							// ������ �̸�

	void				Set_Result_Quest_2_Exp( const CStringW& strExp );									// ���� ����ġ
	void				Set_Result_Quest_2_Gold( const CStringW& strExp );									// ���� ����
	//=================================================================================================================
	// END - ���â
	//=================================================================================================================

	//=================================================================================================================
	// START - ����Ʈ
	//=================================================================================================================
	void				Set_Quest_MIssionVisible( const int& nOrdinal, const bool& bFlag );		// -1 �ʱ�ȭ
	void				Set_Quest_MIssion( const int& nOrdinal, const CStringW& strIn, const bool& bFlag );	// nOrdinal ; 0,1,2 strIn = ����, bflag = �Ϸ��ߴ°�?
	//=================================================================================================================
	// END - ����Ʈ
	//=================================================================================================================

	//=================================================================================================================
	// START - ���� ����
	//=================================================================================================================
	VOID				DoModal_GameLeaving(CStringW strIn, int posX=0, int posY=0);
	//=================================================================================================================
	// END - ���� ����
	//=================================================================================================================

	void				ShowMyBag();
	//=================================================================================================================================//
	// -START- : ������
	//=================================================================================================================================//
	// ������ 1	
	void				myBag_Init();													// �ʱ�ȭ
	void				myBag_setItemTexture(int nOrdinal, CStringW strTexture);		// nOrdinal:0~5, strTexture : �ؽ����̸�
	void				myBag_setIsIconUsable(int nOrdinal, bool bFlag);				// nOrdinal:0~5, bFlag : �̿밡��(false), �Ұ���(true)
	void				myBag_showButtonAll(int nOrdinal, bool bFlag);					// nOrdinal:0~5, bFlag : PCBANG(true), �Ϲ�(false)
	void				myBag_setIsUsing(int nOrdinal, bool bFlag);					// nOrdinal:0~5, bFlag : �����ǥ����(true), �����ǥ�þ���(false)
	void				myBag_setGoldText(const CStringW& strIn );						// ��� ǥ��
	bool				myBag_GetMouseMove();											// ���콺�� �ڽ�â���� �ִ°�?
	BOOL				myBag_GetIconMove(const int& nOrdingl );						// �������� �����̰��ִ°�?

	void				myBag_Show_ReceiverSlot( const bool& bFlag );					// �Ҹ𼺾����� Ȱ�� ��Ȱ�� -1 �ʱ�ȭ
	void				myBag_Set_ReeciverFileName( const int& nOrdinal, const CStringW& strFileName );	// ���Կ� ������ ä���

	void				myBag_setSelectedGroup(unsigned int uSel);
	int					myBag_GetSelectedGroup();

	void				myBag_SlotSetting( const int& nOrdinal );						// ��,�Ӹ�,����,����,���...����
	VOID				myBag_SetItemClick( int nOrdinal, bool bFlag );					// ������ Ŭ��

	VOID				myBag_ShowItemCount( const INT& nOrdinal, const BOOL& bFlag );	// ������ ���� Ȱ�� ��Ȱ��
	VOID				myBag_SetItemCount( const INT& nOrdinal, const INT& nCount );	// ������ ���� ī��Ʈ

	//=================================================================================================================================//
	// -END- : ������
	//=================================================================================================================================//

	void				myBagToolTip_ItemExplanation( int nID, CStringW strIn, COLORREF color);
	int					getItemIndexNumber(int nID );
	void				myBagToolTip_ItemName(int nID, CStringW strIn, COLORREF color );
	void				myBagToolTip_Character(int nID, CStringW strIn, COLORREF color);
	void				myBagToolTip_Hard( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_Level(int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_PhyAttack( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_InAttack( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_LongAttack( int nID,int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_ItemNumber( int nID, int nValue, COLORREF color);
	void				myBagToolTip_Life( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_PhyDefense( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_InDefense( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_LongDefense( int nID, int nValue1, int nValue2, COLORREF color);
	void				myBagToolTip_NonBeefUp( int nID, int nValue, COLORREF color);
	void				myBagToolTip_DesBeefUp( int nID, int nValue, COLORREF color);
	void				myBagToolTip_ComBeefUp( int nID, int nValue, COLORREF color);
	void				myBagToolTip_DefBeefUp( int nID, int nValue, COLORREF color);
	void				myBagToolTip_ProBeefUp( int nID, int nValue, COLORREF color);
	void				myBagToolTip_AttSpeed( int nID, int nValue, COLORREF color);
	void				myBagToolTip_MovSpeed( int nID, int nValue, COLORREF color);
	void				myBagToolTip_Pat( int nID, int nValue, COLORREF color);
	void				myBagToolTip_AddAttack( int nID, int nValue, COLORREF color);
	void				myBagToolTip_ResTime(int nID, int fValue, COLORREF color);
	void				myBagToolTip_AddExp(const int& nID, const int& fValue, const COLORREF& color);	
	void				myBagToolTip_AddGold(const int& nID, const int& fValue, const COLORREF& color);
	void				myBagToolTip_Power( int nID,CStringW strIn , COLORREF color);										// ��뼼��
	void				myBagToolTip_AddPoint(int nID,int nValue, COLORREF color);											// �����߰�����Ʈ
	void				myBagToolTip_HardRestor(int nID,int nValue, COLORREF color);										// ������ȸ������
	void				myBagToolTip_ItemBeefUpOption1(int nID,CStringW strIn, COLORREF color);									// �����۰�ȭ�ɼ�1
	void				myBagToolTip_ItemBeefUpOption2(int nID,CStringW strIn, COLORREF color);									// �����۰�ȭ�ɼ�2

}; // class yb_MainUIControl

#endif // _YB_MAINGAME_ID_H_