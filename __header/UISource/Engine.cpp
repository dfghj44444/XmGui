/*
file : XM_Engine.cpp
*/

#include "stdafx.h"

namespace XM
{
	// ctor/dtor
	xmEngine::xmEngine()
	{
		// IMM
		initIMM();

		m_nStringCnt = 0;
		m_ppString = nullptr;

		// String Table
		InitStringTable();
		m_pDevice = nullptr;
		// HWND
		m_hWnd = nullptr;
		m_listStatusUIManager.clear();
		
		// Modal Dialog
		m_pModal = nullptr;
	}
	xmEngine::~xmEngine()
	{
		RemoveStringTable();
		closeEngine();
	}

	///////////////////////////////////////////////////////////////////////////
	xmEngine* xmEngine::ms_xmEngineInstance = nullptr;
	xmEngine* xmEngine::getInstance()
	{
        if(ms_xmEngineInstance == nullptr)
            ms_xmEngineInstance = new xmEngine;

		if(ms_xmEngineInstance == (void*)0xFFFFFFFF)
			return nullptr;

		return ms_xmEngineInstance;
	}

	///////////////////////////////////////////////////////////////////////////
	#if defined(_DEBUG)||defined(DEBUG)
	void xmEngine::addPtr(void* pPtr, const CStringW& strFilename, long lineNum)
	{
		char buf[32];
		_itoa(lineNum, buf, 10);
		CStringW strInsert = "File : ";
		strInsert += strFilename;
		strInsert += ", Line : ";
		strInsert += buf;	
		m_ptrMap[pPtr] = strInsert;
	}

	void xmEngine::addPtr(void* pPtr, const CStringW& strFilename, long lineNum, const CStringW& strSaveFilename )
	{
		char buf[32];
		_itoa(lineNum, buf, 10);
		CStringW strInsert = "File : ";
		strInsert += ",~~~~~~~~[ ";
		strInsert += strFilename;
		strInsert += " ]~~~~~~~~";
		strInsert += strSaveFilename;
		strInsert += ", Line : ";
		strInsert += buf;	
		m_ptrMap[pPtr] = strInsert;
	}

	void xmEngine::removePtr(void* pPtr)
	{
		m_ptrMap.erase(pPtr);
	}
	void xmEngine::printPtrList()
	{
		int nPtrCount = static_cast<int>(m_ptrMap.size());
		if(nPtrCount > 0)
		{
			FILE* fp = _wfopen(L"leak.txt", L"a");
			fwprintf(fp, L"%d Leak(s) Founded.\n", nPtrCount);

			for(auto itMap = m_ptrMap.begin(); itMap != m_ptrMap.end(); ++itMap)
			{
				fwprintf(fp, L"Found Leak!!! %s\n", itMap->second.GetBuffer());
			}
			fwprintf(fp, L"\n");
			fclose(fp);
		}
	}
	#endif

	void xmEngine::addDeviceData(resNode* pNode)
	{
		XM_ASSERT(pNode);
		if(pNode == nullptr)
			return;
		m_listDeviceData.push_back(pNode);
	}
	void xmEngine::removeDeviceData(resNode* pNode)
	{
		XM_ASSERT(pNode);
		if(pNode == nullptr)
			return;
		m_listDeviceData.remove(pNode);
	}
	bool xmEngine::onCreateDevice(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		if(pDevice == nullptr)
			return false;

		bool bRet = true;

		m_pDevice = pDevice;

		int nSize = m_listDeviceData.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listDeviceData[i]->onCreateDevice(pDevice) == false)
			{
				bRet = false;
			}
		}

        m_FontManager.init();

		return bRet;
	}
	bool xmEngine::onResetDevice(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);
		if(pDevice == nullptr)
			return false;

		bool bRet = true;

		int nSize = m_listDeviceData.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listDeviceData[i]->onResetDevice(pDevice) == false)
				bRet = false;
		}

		return bRet;
	}
	void xmEngine::onLostDevice()
	{
		int nSize = m_listDeviceData.size();
		for(int i = 0; i<nSize; ++i)
			m_listDeviceData[i]->onLostDevice();
	}
	void xmEngine::onDestroyDevice()
	{
		int nSize = m_listDeviceData.size();
		for(int i = 0; i<nSize; ++i)
			m_listDeviceData[i]->onDestroyDevice();

        m_FontManager.destroy();
		m_pDevice = nullptr;

        delete ms_xmEngineInstance;
        ms_xmEngineInstance = (xmEngine*)0xFFFFFFFF;
	}

	void xmEngine::addTexNode(WCHAR* strTex, texNode* pNode)
	{
		if((strTex == nullptr)||(pNode == nullptr))
		{
			XM_ASSERT(0);
			return;
		}

        wchar_t name[1024];
        wcsncpy(name, strTex, 1023);
        name[1023] = L'\0';
        makeStandard(name);

        XM_ASSERT(m_listTexNode.find(name) == m_listTexNode.end());

		m_listTexNode[name] = pNode;
	}
	
    void xmEngine::removeTexNode(WCHAR* strTex)
	{
		if(strTex == nullptr) 
            return;

        wchar_t name[1024];
        wcsncpy(name, strTex, 1023);
        name[1023] = L'\0';
        makeStandard(name);

		m_listTexNode.erase(name);
	}

	texNode* xmEngine::getTexNode(WCHAR* strTex)
	{
		if(strTex == nullptr)
		{
			XM_ASSERT(0);
			return nullptr;
		}

        wchar_t name[1024];
        wcsncpy(name, strTex, 1023);
        name[1023] = L'\0';
        makeStandard(name);

        TexMap::iterator itr = m_listTexNode.find(name);
        if( itr != m_listTexNode.end() )
            return itr->second;

        return nullptr;
	}
	///////////////////////////////////////////////////////////////////////////
	// IMM
	void xmEngine::initIMM()
	{
		CHAR szPath[MAX_PATH+1];

		if( GetSystemDirectoryA( szPath, MAX_PATH+1 ) ) 
		{
			strcat( szPath, "\\imm32.dll" );
			m_hDllImm32 = LoadLibraryA( szPath );
			if( m_hDllImm32 )
			{
				_ImmLockIMC		= (INPUTCONTEXT*(WINAPI *)( HIMC ))
					GetProcAddress( m_hDllImm32, "ImmLockIMC" );
				_ImmUnlockIMC	= (BOOL(WINAPI *)( HIMC ))
					GetProcAddress( m_hDllImm32, "ImmUnlockIMC" );
				_ImmLockIMCC	= (LPVOID(WINAPI *)( HIMCC ))
					GetProcAddress( m_hDllImm32, "ImmLockIMCC" );
				_ImmUnlockIMCC	= (BOOL(WINAPI *)( HIMCC ))
					GetProcAddress( m_hDllImm32, "ImmUnlockIMCC" );
			}
			else
			{
				XM_ASSERT(0);
			}
		}
	}

	INPUTCONTEXT* xmEngine::LockIMC(HIMC hImc)
	{
		if(_ImmLockIMC != nullptr) 
			return _ImmLockIMC(hImc);

		return nullptr;
	}

	BOOL xmEngine::UnlockIMC(HIMC hImc)
	{
		if(_ImmUnlockIMC != nullptr) 
			return _ImmUnlockIMC(hImc);
			
		return FALSE;
	}
	LPVOID xmEngine::LockIMCC(HIMCC himcc)
	{
		if(_ImmLockIMCC != nullptr) 
			return _ImmLockIMCC(himcc);

		return nullptr;
	}
	BOOL xmEngine::UnlockIMCC(HIMCC himcc)
	{
		if(_ImmUnlockIMCC != nullptr) 
			return _ImmUnlockIMCC(himcc);

		return NULL;
	}

	///////////////////////////////////////////////////////////////////////////
	// closeEngine
	void xmEngine::closeEngine()
	{
		m_FontManager.clear();
		m_texManager.clear();

		if(m_hDllImm32) 
		{
			FreeLibrary(m_hDllImm32);
		}

		// Modal Dialog 
		_SAFE_DEREF(m_pModal);

		#if defined(_DEBUG)||defined(DEBUG)
		printPtrList();
		#endif
	}

	///////////////////////////////////////////////////////////////////////////
	// message procedure
	void xmEngine::setHwnd(HWND hWnd)
	{
		m_hWnd = hWnd;
	}
	HWND xmEngine::getHwnd()
	{
		return m_hWnd;
	}
	bool xmEngine::handleMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, bool* pbNoFurtherProcessing)
	{
		if(uMsg == WM_SIZE)
		{
			RECT rcCurrentClient;
			GetClientRect(hWnd, &rcCurrentClient);
			//m_MouseUtil.onSize(rcCurrentClient.right - rcCurrentClient.left, rcCurrentClient.bottom - rcCurrentClient.top);
		}
		if(uMsg == WM_MOUSEMOVE)
		{
			//m_MouseUtil.onMouseMove(LOWORD(lParam), HIWORD(lParam));
		}
		
		if(m_pModal)
		{
			if(m_pModal->msgProc(uMsg, wParam, lParam) == true)
			{
				return true;
			}
		}
		else
		{
			int nSize2 = m_listStatusUIManager.size();

			for(int j = 0; j<nSize2; ++j)
			{
				if( (m_listStatusUIManager[j]->getEnabled() == true) || (m_listStatusUIManager[j]->getVisible() == true) )
				{
					if( m_listStatusUIManager[j]->msgProc(uMsg, wParam, lParam) == true )
					{						
						return true;
					}
				}
			}
		}

		return false;
	}

	///////////////////////////////////////////////////////////////////////////
	// ui manager
	void xmEngine::addStatusUIManager(UI_Manager* pManager)
	{
		if(pManager)
		{
			m_listStatusUIManager.push_back(pManager);
		}
	}
	void xmEngine::removeStatusUIManager(UI_Manager* pManager)
	{
		if(pManager)
		{
			m_listStatusUIManager.remove(pManager);
		}
	}
	void xmEngine::setModal(UI_Manager* pManager)
	{
		int nSize = m_listStatusUIManager.size();

		if(m_pModal)
		{
			m_pModal->setVisible(false);
		}
		_SAFE_DEREF(m_pModal);
		m_pModal = pManager;
		_SAFE_REF(m_pModal);
		if(m_pModal)
		{
			m_pModal->setVisible(true);
		}
	}
	UI_Manager* xmEngine::getModal()
	{
		return m_pModal;
	}

	///////////////////////////////////////////////////////////////////////////
	// saved file path
	void xmEngine::clearPathList()
	{
		m_listFilePath.clear();
	}
	xmVec<CStringW>* xmEngine::getPathList()
	{
		return &m_listFilePath;
	}
	void xmEngine::addFilePath(const CStringW& strPath)
	{
		CStringW strInsert = strPath;
		int nSize = m_listFilePath.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listFilePath[i] == strInsert)
			{
				return;
			}
		}
		m_listFilePath.push_back(strInsert);
	}
	void xmEngine::addFilePath(WCHAR* strPath)
	{
		CStringW strInsert = strPath;
		addFilePath(strInsert);
	}
	void xmEngine::addFilePath(char* strPath)
	{
		CStringW strInsert = strPath;
		addFilePath(strInsert);
	}
	void xmEngine::removeFilePath(const CStringW& strPath)
	{
		CStringW strDelete = strPath;
		int nSize = m_listFilePath.size();
		for(int i = 0; i<nSize; ++i)
		{
			if(m_listFilePath[i] == strDelete)
			{
				m_listFilePath.erase(i);
				return;
			}
		}
	}
	void xmEngine::removeFilePath(WCHAR* strPath)
	{
		CStringW strDelete = strPath;
		removeFilePath(strDelete);
	}
	void xmEngine::removeFilePath(char* strPath)
	{
		CStringW strDelete = strPath;
		removeFilePath(strDelete);
	}

	//////////////////////////////////////////////////////////////////////////
	// StringTable
	bool xmEngine::InitStringTable( VOID )
	{
		DWORD  dwSize;
		HANDLE hFile;
		SHORT  nStringLenght;

		hFile = CreateFile(_T("TextLib.bin"), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		
		if ( hFile == INVALID_HANDLE_VALUE ) {	return FALSE;	}

		ReadFile( hFile, &m_nStringCnt, sizeof(INT), &dwSize, nullptr);

		if ( m_nStringCnt )
		{
			m_ppString = (TCHAR**) new TCHAR*[ m_nStringCnt ];

			for ( INT i = 0; i < m_nStringCnt; ++i )
			{
				ReadFile( hFile, &nStringLenght, sizeof(SHORT), &dwSize, nullptr);

				m_ppString[i] = nullptr;

				if ( nStringLenght )
				{
					m_ppString[i] = (TCHAR*) new TCHAR[ nStringLenght + 1 ];

					ReadFile( hFile, m_ppString[i], sizeof(TCHAR) * nStringLenght, &dwSize, nullptr);

					m_ppString[i][ nStringLenght ] = '\0';
				}
			}
		}

		CloseHandle(hFile);

		return TRUE;
	}

	void xmEngine::RemoveStringTable(void)
	{
		for( int j = 0; j < m_nStringCnt; ++j )
		{
			_SAFE_DELETE_ARRAY( m_ppString[j] );
		}
		_SAFE_DELETE_ARRAY( m_ppString );
	}

	TCHAR* xmEngine::GetString( int nIdx )
	{
		nIdx -= 2;
		XM_ASSERT( nIdx >= 0 && nIdx < m_nStringCnt );
		return m_ppString[ nIdx ];
	}
} // namespace XM