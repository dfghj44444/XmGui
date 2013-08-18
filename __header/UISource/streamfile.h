/*

file : XM_StreamFile.h

*/

#ifndef H_XM_STREAMFILE_H
#define H_XM_STREAMFILE_H

namespace XM
{
	class CMemoryFile
	{
	protected:

		CHAR*					m_pMemory;							// Memory
		DWORD					m_dwReadPos;						// Memory 
		DWORD					m_dwMemorySize;						// Memory 

	public:
		CMemoryFile();

		virtual ~CMemoryFile();
		
		VOID				ClearMemory();
		VOID				UIReadFromMemory( LPVOID pData, DWORD dwReadSize );
		VOID				MemoryFile( HANDLE &hFile, DWORD dwSize );
	};

	class IStream : public baseNode
	{
	public:
		IStream();
		virtual ~IStream();

		virtual int				read(int bytes, void * pBuffer) = 0;
		virtual int				write(int bytes, const void * pBuffer) = 0;

		virtual bool			setCurPos(int pos) = 0;
		virtual int				getCurPos() = 0;

	}; // class IStream
	
	class IStreamFile : public IStream
	{
	protected:
		HANDLE					m_hFile;

		bool					m_bReadMode;
		bool					m_bWriteMode;
		CMemoryFile*			m_xMemory;

	public:

		IStreamFile();
		virtual ~IStreamFile();

		// read/write
		virtual int				read(int bytes, void * pBuffer);
		virtual int				write(int bytes, const void * pBuffer);

		// seek
		virtual bool			setCurPos(int pos);
		virtual int				getCurPos();

		// open/close file
		bool					openReadFile(CStringW filename);
		bool					openWriteFile(char* filename);
		bool					openWriteFile(std::string filename);
		bool					openWriteFile(CStringW filename);
		bool					openOverwriteFile(char* filename);
		bool					openOverwriteFile(std::string filename);
		bool					openOverwriteFile(CStringW filename);
		void					closeFile();
	}; // class IStreamFile

	/* For MemoryFile */
} // namespace XM

#endif // H_XM_STREAMFILE_H