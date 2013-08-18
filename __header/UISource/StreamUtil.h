/*

file : XM_StreamUtil.h

*/

#ifndef H_XM_STREAMUTIL_H
#define H_XM_STREAMUTIL_H

#define ISTREAM_READ(x,y,z)			if( false == (x.read(z, y) > 0 ? true:false) ) return false
#define ISTREAM_READBool(x,y)		if( false == (x.read(1, y) > 0 ? true:false) ) return false
#define ISTREAM_READBOOL(x,y)		if( false == (x.read(4, y) > 0 ? true:false) ) return false
#define ISTREAM_READINT(x,y)		if( false == (x.read(4, y) > 0 ? true:false) ) return false
#define ISTREAM_READUINT(x,y)		if( false == (x.read(4, y) > 0 ? true:false) ) return false
#define ISTREAM_READUSHORT(x,y)		if( false == (x.read(2, y) > 0 ? true:false) ) return false
#define ISTREAM_READULONG(x,y)		if( false == (x.read(4, y) > 0 ? true:false) ) return false
#define ISTREAM_READFLOAT(x,y)		if( false == (x.read(4, y) > 0 ? true:false) ) return false
#define ISTREAM_READSTRING(x,y)		if( false == IStream_ReadString(x,y) ) return false
#define ISTREAM_READVEC2(x,y)		if( false == (x.read(8, y) > 0 ? true:false) ) return false
#define ISTREAM_READVEC3(x,y)		if( false == (x.read(12, y) > 0 ? true:false) ) return false
#define ISTREAM_READVEC4(x,y)		if( false == (x.read(16, y) > 0 ? true:false) ) return false
#define ISTREAM_READMATRIX(x,y)		if( false == (x.read(64, y) > 0 ? true:false) ) return false

#define ISTREAM_WRITE(x,y,z)		if( false == (x.write(z, y) > 0 ? true:false) ) return false
#define ISTREAM_WRITEBool(x,y)		if( false == (x.write(1, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEBOOL(x,y)		if( false == (x.write(4, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEINT(x,y)		if( false == (x.write(4, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEUINT(x,y)		if( false == (x.write(4, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEUSHORT(x,y)	if( false == (x.write(2, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEULONG(x,y)		if( false == (x.write(4, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEFLOAT(x,y)		if( false == (x.write(4, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITESTRING(x,y)	if( false == IStream_WriteString(x,y) ) return false
#define ISTREAM_WRITEVEC2(x,y)		if( false == (x.write(8, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEVEC3(x,y)		if( false == (x.write(12, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEVEC4(x,y)		if( false == (x.write(16, (void*)&(y)) > 0 ? true:false) ) return false
#define ISTREAM_WRITEMATRIX(x,y)	if( false == (x.write(64, (void*)&(y)) > 0 ? true:false) ) return false


namespace XM
{
	bool	IStream_Read(IStream& rStream, void* pRead, int size);
	bool	IStream_ReadBool(IStream& rStream, bool* pOut);
	bool	IStream_ReadBOOL(IStream& rStream, BOOL* pOut);
	bool	IStream_ReadInt(IStream& rStream, int* pOut);
	bool	IStream_ReadUint(IStream& rStream, unsigned int* pOut);
	bool 	IStream_ReadUShort(IStream& rStream, unsigned short* pOut);
	bool	IStream_ReadULong(IStream& rStream, unsigned long* uValue);
	bool	IStream_ReadFloat(IStream& rStream, float* pOut);
	bool	IStream_ReadString(IStream& rStream, CStringW* pOut);
	bool	IStream_ReadVec2(IStream& rStream, D3DXVECTOR2* pOut);
	bool	IStream_ReadVec3(IStream& rStream, D3DXVECTOR3* pOut);
	bool	IStream_ReadVec4(IStream& rStream, D3DXVECTOR4* pOut);
	bool	IStream_ReadMatrix(IStream& rStream, D3DXMATRIX* pOut);

	bool	IStream_Write(IStream& rStream, void* pWrite, int size);
	bool	IStream_WriteBool(IStream& rStream, bool bValue);
	bool	IStream_WriteBOOL(IStream& rStream, BOOL bValue);
	bool	IStream_WriteInt(IStream& rStream, int nValue);
	bool	IStream_WriteUint(IStream& rStream, unsigned int uValue);
	bool	IStream_WriteUShort(IStream& rStream, unsigned short uValue);
	bool	IStream_WriteULong(IStream& rStream, unsigned long uValue);
	bool	IStream_WriteFloat(IStream& rStream, float fValue);
	bool	IStream_WriteString(IStream& rStream, CStringW strWValue);
	bool	IStream_WriteVec2(IStream& rStream, D3DXVECTOR2 vValue);
	bool	IStream_WriteVec3(IStream& rStream, D3DXVECTOR3 vValue);
	bool	IStream_WriteVec4(IStream& rStream, D3DXVECTOR4 vValue);
	bool	IStream_WriteMatrix(IStream& rStream, D3DXMATRIX matValue);
} // namespace XM

#endif // H_XM_STREAMUTIL_H