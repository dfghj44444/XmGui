/*

file : XM_RenderUtil.h

*/

#ifndef H_XM_RENDERUTIL_H
#define H_XM_RENDERUTIL_H

namespace XM
{
	struct VTXTYPE_3D_COLOR_TEX1
	{
		D3DXVECTOR3 vPos;
		D3DCOLOR color;
		float tu, tv;
		static DWORD FVF;
	}; // struct VTXTYPE_3D_COLOR_TEX1

	struct VTXTYPE_2D_COLOR_TEX1
	{
		float x, y, z, h;
		D3DCOLOR color;
		float tu, tv;
		static DWORD FVF;
	}; // struct VTXTYPE_2D_COLOR_TEX1

	struct VTXTYPE_2D_COLOR
	{
		float x, y, z, h;
		D3DCOLOR color;
		static DWORD FVF;
	}; // struct VTXTYPE_2D_COLOR

	void renderRect_VTXTYPE_2D_COLOR_RoomMake(const RECT& rRC, D3DCOLOR cColor, float z, IDirect3DDevice9* pd3dDevice);
	void renderRect_VTXTYPE_2D_COLOR(const RECT& rRC, D3DCOLOR cColor, float z, IDirect3DDevice9* pd3dDevice);
	void renderString_Outline(CFont* pFont, CStringW& strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor);
	void renderString_Shadow(CFont* pFont, CStringW& strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor, int nOffsetX, int nOffsetY);
	void renderString_OutlineA(CFont* pFont, char* strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor);
	void renderString_ShadowA(CFont* pFont, char* strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor, int nOffsetX, int nOffsetY);

} // namespace XM

#endif // H_XM_RENDERUTIL_H