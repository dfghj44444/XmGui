
/*

file : XM_StreamUtil.cpp

*/


#include "stdafx.h"

namespace XM
{
	bool IStream_Read(IStream& rStream, void* pRead, int size)
	{
		XM_ASSERT(pRead);
		if(pRead == nullptr)
		{
			return false;
		}

		if(rStream.read(size, (void*)pRead) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadBool(IStream& rStream, bool* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(bool), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadBOOL(IStream& rStream, BOOL* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(BOOL), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadInt(IStream& rStream, int* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(int), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadUint(IStream& rStream, unsigned int* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned int), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadUShort(IStream& rStream, unsigned short* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned short), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadULong(IStream& rStream, unsigned long* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned long), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadFloat(IStream& rStream, float* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(float), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadString(IStream& rStream, CStringW* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		// read size
		int nSize;
		if(IStream_ReadInt(rStream, &nSize) == false)
		{
			return false;
		}

		// create read buffer
		WCHAR* pBuf = new WCHAR[nSize+1];
		XM_ASSERT(pBuf);
		if(pBuf == nullptr)
		{
			return false;
		}

		// read
		if(rStream.read(sizeof(WCHAR)*nSize, (void*)pBuf) <= 0)
		{
			delete[] pBuf;
			return false;
		}

		// null-terminate
		pBuf[nSize] = 0;

		// copy
		*pOut = pBuf;

		delete[] pBuf;

		return true;
	}
	bool IStream_ReadVec2(IStream& rStream, D3DXVECTOR2* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(D3DXVECTOR2), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadVec3(IStream& rStream, D3DXVECTOR3* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(D3DXVECTOR3), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadVec4(IStream& rStream, D3DXVECTOR4* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(D3DXVECTOR4), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadMatrix(IStream& rStream, D3DXMATRIX* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == nullptr)
		{
			return false;
		}

		if(rStream.read(sizeof(D3DXMATRIX), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}

	bool IStream_Write(IStream& rStream, void* pWrite, int size)
	{
		XM_ASSERT(pWrite);
		if(pWrite == nullptr)
		{
			return false;
		}

		if(rStream.write(size, pWrite) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_WriteBool(IStream& rStream, bool bValue)
	{
		if(rStream.write(sizeof(bool), (void*)&bValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteBOOL(IStream& rStream, BOOL bValue)
	{
		if(rStream.write(sizeof(BOOL), (void*)&bValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteInt(IStream& rStream, int nValue)
	{
		if(rStream.write(sizeof(int), (void*)&nValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteUint(IStream& rStream, unsigned int uValue)
	{
		if(rStream.write(sizeof(unsigned int), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteUShort(IStream& rStream, unsigned short uValue)
	{
		if(rStream.write(sizeof(unsigned short), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteULong(IStream& rStream, unsigned long uValue)
	{
		if(rStream.write(sizeof(unsigned long), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteFloat(IStream& rStream, float fValue)
	{
		if(rStream.write(sizeof(float), (void*)&fValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteString(IStream& rStream, CStringW strWValue)
	{
		// write string length
		int nSize = strWValue.GetLength();
		if(IStream_WriteInt(rStream, nSize) == false)
		{
			return false;
		}

		// write string
		if(rStream.write(sizeof(WCHAR)*nSize, (void*)strWValue.GetBuffer()) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteVec2(IStream& rStream, D3DXVECTOR2 vValue)
	{
		if(rStream.write(sizeof(D3DXVECTOR2), (void*)&vValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteVec3(IStream& rStream, D3DXVECTOR3 vValue)
	{
		if(rStream.write(sizeof(D3DXVECTOR3), (void*)&vValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteVec4(IStream& rStream, D3DXVECTOR4 vValue)
	{
		if(rStream.write(sizeof(D3DXVECTOR4), (void*)&vValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteMatrix(IStream& rStream, D3DXMATRIX matValue)
	{
		if(rStream.write(sizeof(D3DXMATRIX), (void*)&matValue) <= 0)
		{
			return false;
		}
		return true;
	}

} // namespace XM

/*


#include "stdafx.h"

namespace XM
{
	bool IStream_Read(IStream& rStream, void* pRead, int size)
	{
		XM_ASSERT(pRead);
		if(pRead == 0)
		{
			return false;
		}

		if(rStream.read(size, (void*)pRead) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadBool(IStream& rStream, bool* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(bool), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadBOOL(IStream& rStream, BOOL* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(BOOL), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadInt(IStream& rStream, int* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(int), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadUint(IStream& rStream, unsigned int* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned int), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadUShort(IStream& rStream, unsigned short* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned short), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadULong(IStream& rStream, unsigned long* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(unsigned long), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadFloat(IStream& rStream, float* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(float), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_ReadString(IStream& rStream, CStringW* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		// read size
		int nSize;
		if(IStream_ReadInt(rStream, &nSize) == false)
		{
			return false;
		}

		// create read buffer
		WCHAR* pBuf = new WCHAR[nSize+1];
		XM_ASSERT(pBuf);
		if(pBuf == 0)
		{
			return false;
		}

		// read
		if(rStream.read(sizeof(WCHAR)*nSize, (void*)pBuf) <= 0)
		{
			delete[] pBuf;
			return false;
		}

		// null-terminate
		pBuf[nSize] = 0;

		// copy
		*pOut = pBuf;

		delete[] pBuf;

		return true;
	}
	bool IStream_ReadVec2(IStream& rStream, D3DXVECTOR2* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(float), (void*)&(pOut->x)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->y)) <= 0) return false;
		//if(rStream.read(sizeof(D3DXVECTOR2), (void*)pOut) <= 0)
		//{
		//	return false;
		//}

		return true;
	}
	bool IStream_ReadVec3(IStream& rStream, D3DXVECTOR3* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(float), (void*)&(pOut->x)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->y)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->z)) <= 0) return false;
		//if(rStream.read(sizeof(D3DXVECTOR3), (void*)pOut) <= 0)
		//{
		//	return false;
		//}

		return true;
	}
	bool IStream_ReadVec4(IStream& rStream, D3DXVECTOR4* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(float), (void*)&(pOut->x)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->y)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->z)) <= 0) return false;
		if(rStream.read(sizeof(float), (void*)&(pOut->w)) <= 0) return false;
		//if(rStream.read(sizeof(D3DXVECTOR4), (void*)pOut) <= 0)
		//{
		//	return false;
		//}

		return true;
	}
	bool IStream_ReadMatrix(IStream& rStream, D3DXMATRIX* pOut)
	{
		XM_ASSERT(pOut);
		if(pOut == 0)
		{
			return false;
		}

		if(rStream.read(sizeof(D3DXMATRIX), (void*)pOut) <= 0)
		{
			return false;
		}

		return true;
	}

	bool IStream_Write(IStream& rStream, void* pWrite, int size)
	{
		XM_ASSERT(pWrite);
		if(pWrite == 0)
		{
			return false;
		}

		if(rStream.write(size, pWrite) <= 0)
		{
			return false;
		}

		return true;
	}
	bool IStream_WriteBool(IStream& rStream, bool bValue)
	{
		if(rStream.write(sizeof(bool), (void*)&bValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteBOOL(IStream& rStream, BOOL bValue)
	{
		if(rStream.write(sizeof(BOOL), (void*)&bValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteInt(IStream& rStream, int nValue)
	{
		if(rStream.write(sizeof(int), (void*)&nValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteUint(IStream& rStream, unsigned int uValue)
	{
		if(rStream.write(sizeof(unsigned int), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteUShort(IStream& rStream, unsigned short uValue)
	{
		if(rStream.write(sizeof(unsigned short), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteULong(IStream& rStream, unsigned long uValue)
	{
		if(rStream.write(sizeof(unsigned long), (void*)&uValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteFloat(IStream& rStream, float fValue)
	{
		if(rStream.write(sizeof(float), (void*)&fValue) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteString(IStream& rStream, CStringW strWValue)
	{
		// write string length
		int nSize = strWValue.GetLength();
		if(IStream_WriteInt(rStream, nSize) == false)
		{
			return false;
		}

		// write string
		if(rStream.write(sizeof(WCHAR)*nSize, (void*)strWValue.GetBuffer()) <= 0)
		{
			return false;
		}
		return true;
	}
	bool IStream_WriteVec2(IStream& rStream, D3DXVECTOR2 vValue)
	{
		if(rStream.write(sizeof(float), (void*)&(vValue.x)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.y)) <= 0 ) return false;
		//if(rStream.write(sizeof(D3DXVECTOR2), (void*)&vValue) <= 0)
		//{
		//	return false;
		//}
		return true;
	}
	bool IStream_WriteVec3(IStream& rStream, D3DXVECTOR3 vValue)
	{
		if(rStream.write(sizeof(float), (void*)&(vValue.x)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.y)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.x)) <= 0 ) return false;
		//if(rStream.write(sizeof(D3DXVECTOR3), (void*)&vValue) <= 0)
		//{
		//	return false;
		//}
		return true;
	}
	bool IStream_WriteVec4(IStream& rStream, D3DXVECTOR4 vValue)
	{
		if(rStream.write(sizeof(float), (void*)&(vValue.x)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.y)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.x)) <= 0 ) return false;
		if(rStream.write(sizeof(float), (void*)&(vValue.w)) <= 0 ) return false;
		//if(rStream.write(sizeof(D3DXVECTOR4), (void*)&vValue) <= 0)
		//{
		//	return false;
		//}
		return true;
	}
	bool IStream_WriteMatrix(IStream& rStream, D3DXMATRIX matValue)
	{
		if(rStream.write(sizeof(D3DXMATRIX), (void*)&matValue) <= 0)
		{
			return false;
		}
		return true;
	}

} // namespace XM

*/