/*

file : XM_RenderUtil.cpp

*/
#include "stdafx.h"

namespace XM
{
	DWORD VTXTYPE_3D_COLOR_TEX1::FVF	= D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	DWORD VTXTYPE_2D_COLOR_TEX1::FVF	= D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1;
	DWORD VTXTYPE_2D_COLOR::FVF			= D3DFVF_XYZRHW | D3DFVF_DIFFUSE;

	void renderRect_VTXTYPE_2D_COLOR(const RECT& rRC, D3DCOLOR cColor, float z, IDirect3DDevice9* pd3dDevice)
	{
		if(pd3dDevice == nullptr)
		{
			return;
		}

		VTXTYPE_2D_COLOR colorRect[4];
		colorRect[0].x = static_cast<float>(rRC.left);
		colorRect[0].y = static_cast<float>(rRC.top);
		colorRect[0].z = z;
		colorRect[0].h = 1;
		colorRect[1].x = static_cast<float>(rRC.right);
		colorRect[1].y = static_cast<float>(rRC.top);
		colorRect[1].z = z;
		colorRect[1].h = 1;
		colorRect[2].x = static_cast<float>(rRC.right);
		colorRect[2].y = static_cast<float>(rRC.bottom);
		colorRect[2].z = z;
		colorRect[2].h = 1;
		colorRect[3].x = static_cast<float>(rRC.left);
		colorRect[3].y = static_cast<float>(rRC.bottom);
		colorRect[3].z = z;
		colorRect[3].h = 1;
		colorRect[0].color = cColor;
		colorRect[1].color = cColor;
		colorRect[2].color = cColor;
		colorRect[3].color = cColor;
		pd3dDevice->SetTexture(0, nullptr);
		pd3dDevice->SetFVF(VTXTYPE_2D_COLOR::FVF);
		pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, colorRect, sizeof(VTXTYPE_2D_COLOR));
	}
	void renderRect_VTXTYPE_2D_COLOR_RoomMake(const RECT& rRC, D3DCOLOR cColor, float z, IDirect3DDevice9* pd3dDevice)
	{
		if(pd3dDevice == nullptr)
		{
			return;
		}

		VTXTYPE_2D_COLOR colorRect[4];
		colorRect[0].x = static_cast<float>(rRC.left);
		colorRect[0].y = static_cast<float>(rRC.top)+5;
		colorRect[0].z = z;
		colorRect[0].h = 1;
		colorRect[1].x = static_cast<float>(rRC.right)-17;
		colorRect[1].y = static_cast<float>(rRC.top)+5;
		colorRect[1].z = z;
		colorRect[1].h = 1;
		colorRect[2].x = static_cast<float>(rRC.right)-17;
		colorRect[2].y = static_cast<float>(rRC.bottom);
		colorRect[2].z = z;
		colorRect[2].h = 1;
		colorRect[3].x = static_cast<float>(rRC.left);
		colorRect[3].y = static_cast<float>(rRC.bottom);
		colorRect[3].z = z;
		colorRect[3].h = 1;
		colorRect[0].color = cColor;
		colorRect[1].color = cColor;
		colorRect[2].color = cColor;
		colorRect[3].color = cColor;
		pd3dDevice->SetTexture(0, nullptr);
		pd3dDevice->SetFVF(VTXTYPE_2D_COLOR::FVF);
		pd3dDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, colorRect, sizeof(VTXTYPE_2D_COLOR));
	}

	void renderString_Outline(CFont* pFont, CStringW& strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor)
	{
		if(pFont == nullptr)	{return;}

		RECT rcRender = rcRect;
		int nShift[] = {-1, 0, 1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};

		for(int i = 0; i<8; ++i)
		{
			OffsetRect(&rcRender, nShift[i*2], nShift[i*2 + 1]);
			pFont->DrawTextW(nullptr, strOut, nCount, &rcRender, dwFmt, cColor);
			OffsetRect(&rcRender, -nShift[i*2], -nShift[i*2 + 1]);
		}
	}
	void renderString_Shadow(CFont* pFont, CStringW& strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor, int nOffsetX, int nOffsetY)
	{
		if(pFont == nullptr)	{return;}
		RECT rcRender = rcRect;
		rcRender.left	+= nOffsetX;
		rcRender.right	+= nOffsetX;
		rcRender.top	+= nOffsetY;
		rcRender.bottom	+= nOffsetY;
		pFont->DrawTextW(nullptr, strOut, nCount, &rcRender, dwFmt, cColor);
	}
	void renderString_OutlineA(CFont* pFont, char* strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor)
	{
		if(pFont == nullptr || strOut == nullptr)	{return;}

		RECT rcRender = rcRect;
		int nShift[] = {-1, 0, 1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};

		for(int i = 0; i<8; ++i)
		{
			OffsetRect(&rcRender, nShift[i*2], nShift[i*2 + 1]);
			pFont->DrawTextA(nullptr, strOut, nCount, &rcRender, dwFmt, cColor);
			OffsetRect(&rcRender, -nShift[i*2], -nShift[i*2 + 1]);
		}
	}
	void renderString_ShadowA(CFont* pFont, char* strOut, int nCount, RECT& rcRect, DWORD dwFmt, D3DCOLOR cColor, int nOffsetX, int nOffsetY)
	{
		if(pFont == nullptr || strOut == nullptr)	{return;}

		RECT rcRender = rcRect;
		rcRender.left	+= nOffsetX;
		rcRender.right	+= nOffsetX;
		rcRender.top	+= nOffsetY;
		rcRender.bottom	+= nOffsetY;
		pFont->DrawTextA(nullptr, strOut, nCount, &rcRender, dwFmt, cColor);
	}
}