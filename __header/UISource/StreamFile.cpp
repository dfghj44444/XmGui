/*

file : XM_StreamFile.cpp

*/

#include "stdafx.h"

namespace XM
{
	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	IStreamFile::IStreamFile()
	{
		m_hFile			= nullptr;
		m_bReadMode		= false;
		m_bWriteMode	= false;
	}
	IStreamFile::~IStreamFile()
	{
		closeFile();
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// read/write
	int IStreamFile::read(int bytes, void* pBuffer)
	{
		XM_ASSERT(pBuffer);
		if(pBuffer == nullptr)
			return 0;

		if(m_bReadMode == false)
			return 0;

		if(m_hFile == nullptr) 
			return 0;

		DWORD nCount;
		if(ReadFile(m_hFile, pBuffer, bytes, &nCount, nullptr) == FALSE)
			return 0;

		return nCount;
	}
	int IStreamFile::write(int bytes, const void* pBuffer)
	{
		XM_ASSERT(pBuffer);
		if(pBuffer == nullptr)
			return 0;

		if(m_bWriteMode == false)
			return 0;

		if(m_hFile == nullptr) return 0;

		DWORD nCount;
		if(WriteFile(m_hFile, pBuffer, bytes, &nCount, nullptr) == FALSE)
			return 0;

		return nCount;
	}
	// read/write
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// seek
	bool IStreamFile::setCurPos(int pos)
	{
		//if (!m_bReadMode && !m_bWriteMode)
		//	return false;

		//return (fseek(m_pFile, pos, SEEK_SET) == 0);
		return true;
	}
	int IStreamFile::getCurPos()
	{
		//if (!m_bReadMode && !m_bWriteMode)
		//	return 0;

		//return ftell(m_pFile);
		return 0;
	}
	// seek
	///////////////////////////////////////////////////////////////////////////
	bool IStreamFile::openReadFile(CStringW filename)
	{
        closeFile();

		TCHAR* pszFileName = filename.GetBuffer();
		m_hFile = CreateFile( pszFileName, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
        if(m_hFile != INVALID_HANDLE_VALUE)
        {
            m_bReadMode = true;
            m_bWriteMode = false;
            return true;
        }

		xmVec<CStringW>* pathList = g_pStaticEngine->getPathList();
		if(pathList)
		{
			int nSize = pathList->size();
			for(int i = 0; i<nSize; ++i)
			{
				CStringW strComplete = (*pathList)[i] + _T('\\') + pszFileName;
				m_hFile = CreateFile( strComplete, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
				if(m_hFile != INVALID_HANDLE_VALUE)
				{
					m_bReadMode = true;
					m_bWriteMode = false;
					return true;
				}
			}
		}

        m_hFile = INVALID_HANDLE_VALUE;
        return false;
	}

	bool IStreamFile::openWriteFile(char* filename)
	{
		if(m_hFile)		{closeFile();}

		m_hFile = CreateFileA(filename, GENERIC_WRITE|GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = true;
		m_bWriteMode = true;
		return true;
	}
	bool IStreamFile::openWriteFile(std::string filename)
	{
		if(m_hFile)		{closeFile();}

		m_hFile = CreateFileA(filename.c_str(), GENERIC_WRITE|GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = true;
		m_bWriteMode = true;
		return true;
	}
	bool IStreamFile::openWriteFile(CStringW filename)
	{
		if(m_hFile)		{closeFile();}

		m_hFile = CreateFileW(filename, GENERIC_WRITE|GENERIC_READ, 0, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = true;
		m_bWriteMode = true;
		return true;
	}

	bool IStreamFile::openOverwriteFile(char* filename)
	{
		if(m_hFile)		{closeFile();}
		XM_ASSERT(filename);
		if(filename == nullptr)
		{
			return false;
		}

		m_hFile = CreateFileA(filename, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = false;
		m_bWriteMode = true;
		return true;
	}
	bool IStreamFile::openOverwriteFile(std::string filename)
	{
		if(m_hFile)		{closeFile();}

		m_hFile = CreateFileA(filename.c_str(), GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = false;
		m_bWriteMode = true;
		return true;
	}
	bool IStreamFile::openOverwriteFile(CStringW filename)
	{
		if(m_hFile)		{closeFile();}

		m_hFile = CreateFileW(filename, GENERIC_WRITE, 0, nullptr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr);
		if(m_hFile == INVALID_HANDLE_VALUE) {return false;}

		m_bReadMode = false;
		m_bWriteMode = true;
		return true;
	}

	void IStreamFile::closeFile()
	{
		if (m_hFile && m_hFile != INVALID_HANDLE_VALUE)
		{
			CloseHandle(m_hFile);
			m_hFile = INVALID_HANDLE_VALUE;
		}

		m_bReadMode = false;
		m_bWriteMode = false;
	}
	// open/close file
	///////////////////////////////////////////////////////////////////////////

} // namespace XM