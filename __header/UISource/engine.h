/*

file : XM_Engine.h

*/

#ifndef H_XM_ENGINEBASE_H
#define H_XM_ENGINEBASE_H

namespace XM
{
typedef VOID (CALLBACK *PCB_GETPACKEDFILEHANDLE) (TCHAR* filename, HANDLE& hFileHandleOut);
typedef VOID* (CALLBACK *PCB_GETLOADEDFILEMEMORY) (TCHAR* filename, int* pReadSize);


class xmEngine : public baseNode
{
	//===================================================================================================
	// ctor/dtor
	public:
		xmEngine();
		virtual ~xmEngine();
	//===================================================================================================
	protected:
		static xmEngine*			ms_xmEngineInstance;
	public:
		static xmEngine*			getInstance();
	//===================================================================================================
	#if defined(_DEBUG)||defined(DEBUG)
	protected:
		xmPtrNameMap				m_ptrMap;//UI 结点map，用来检查内存泄露
	public:
		void						setLeakFilename(WCHAR* filename);//waiting for implement
		const CStringW&				getLeakFilename();//waiting for implement
		void						addPtr(void* pPtr, CStringW strFilename, long lineNum);
		void						addPtr(void* pPtr, CStringW strFilename, long lineNum, CStringW strSaveFilename );
		void						removePtr(void* pPtr);
		void						printPtrList();
	#endif

	//===================================================================================================
	protected:
		IDirect3DDevice9*			m_pDevice;
		listResNode					m_listDeviceData;

	public:
		inline IDirect3DDevice9*	getDevice() const {return m_pDevice;};
		void						addDeviceData(resNode* pNode);
		void						removeDeviceData(resNode* pNode);
		bool						onCreateDevice(IDirect3DDevice9* pDevice);
		bool						onResetDevice(IDirect3DDevice9* pDevice);
		void						onLostDevice();
		void						onDestroyDevice();
	//===================================================================================================
	protected:
		texMgr						m_TexManager;
        typedef stdext::hash_map<std::wstring, texNode*> TexMap;
		TexMap						m_listTexNode;

	public:
		inline texMgr*				getTexManager(){ return &m_TexManager; };
		void						addTexNode(WCHAR* strTex, texNode* pNode);
		void						removeTexNode(WCHAR* strTex);
		texNode*					getTexNode(WCHAR* strTex);
	//===================================================================================================
	protected:
		fontMgr						m_FontManager;
	public:
		inline fontMgr*				getFontManager() {	return &m_FontManager; };

	//===================================================================================================
	// timer
	protected:
		xmTimer						m_Timer;

	public:
		inline xmTimer*				getTimer()  {	return &m_Timer; };
	//===================================================================================================
	// IMM
	protected:
		HINSTANCE					m_hDllImm32;	// IME instance
		INPUTCONTEXT*				(WINAPI * _ImmLockIMC)(HIMC);
		BOOL						(WINAPI * _ImmUnlockIMC)(HIMC);
		LPVOID						(WINAPI * _ImmLockIMCC)(HIMCC);
		BOOL						(WINAPI * _ImmUnlockIMCC)(HIMCC);
		void						initIMM();

	public:
		INPUTCONTEXT*				LockIMC(HIMC hImc);
		BOOL						UnlockIMC(HIMC hImc);
		LPVOID						LockIMCC(HIMCC);
		BOOL						UnlockIMCC(HIMCC);

	//===================================================================================================
	// closeEngine
	protected:
		void						closeEngine();

	//===================================================================================================
	// message procedure
	protected:
		HWND						m_hWnd;
	public:
		bool						handleMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing);
		void						setHwnd(HWND hWnd);
		HWND						getHwnd();
	//===================================================================================================
	// ui manager
	protected:
		xmVec<UI_Manager*>	m_listStatusUIManager;
		UI_Manager*			m_pModal;
		mouseUtil			m_MouseUtil;
	public:
		void						addStatusUIManager(UI_Manager* pManager);
		void						removeStatusUIManager(UI_Manager* pManager);
		void						setModal(UI_Manager* pManager);
		UI_Manager*					getModal();
		void						setUserValue(int nValue);
		int							getUserValue();

	//===================================================================================================
	// saved file path
	protected:
		xmVec<CStringW>				m_listFilePath;
	public:
		void						clearPathList();
		xmVec<CStringW>*			getPathList();
		void						addFilePath(CStringW strPath);
		void						addFilePath(WCHAR* strPath);
		void						addFilePath(char* strPath);
		void						removeFilePath(CStringW strPath);
		void						removeFilePath(WCHAR* strPath);
		void						removeFilePath(char* strPath);
	//===================================================================================================
	// StringTable
	public:
		int							m_nStringCnt;
		TCHAR**						m_ppString;//从bin文件读取的内容
		bool						InitStringTable(void);
		void						RemoveStringTable(void);
		TCHAR*						GetString( int nIdx );
		inline mouseUtil*		    getMouseUtil() { return &m_MouseUtil; };
	}; // class xmEngine

    void makeStandard(wchar_t* name);

} // namespace XM

#define g_pStaticEngine				XM::xmEngine::getInstance()
#define g_pStaticTexMgr				g_pStaticEngine->getTexManager()
#define g_pStaticFontMgr			g_pStaticEngine->getFontManager()
#define g_pStaticMouseUtil			g_pStaticEngine->getMouseUtil()
#define g_pStaticTimer				g_pStaticEngine->getTimer()
#define g_pStaticDevice             g_pStaticEngine->getDevice()

#define _LANG_CHINA

#if defined( _LANG_CHINA )				
	#define _FONT_NAME_		_T("微软雅黑")
#endif

#if defined( _LANG_CHINA )	
	#define CODE_PAGE	936 
#endif

#endif // H_XM_ENGINEBASE_H