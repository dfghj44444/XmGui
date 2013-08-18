/*

file : XM_MouseUtil.cpp

*/

#include "stdafx.h"

namespace XM
{
	mouseUtil::mouseUtil()
	{
		m_nMouseX			= 0;
		m_nMouseY			= 0;
		m_nScreenWidth		= 0;
		m_nScreenHeight		= 0;
	}
	mouseUtil::~mouseUtil()
	{
	}

	void mouseUtil::calcRayVectorLH(D3DXMATRIX matView, D3DXMATRIX matProj)
	{
		D3DXMATRIX matInvView;
		D3DVECTOR v;

		D3DXMatrixInverse( &matInvView, NULL, &matView );

		m_vRayPos.x	= matInvView._41;
		m_vRayPos.y	= matInvView._42;
		m_vRayPos.z	= matInvView._43;

		v.x =  (  ( ( ( 2.0f * ( m_nMouseX ) ) / m_nScreenWidth  ) - 1 ) - matProj._31 ) / matProj._11;
		v.y =  ( -( ( ( 2.0f * ( m_nMouseY ) ) / m_nScreenHeight ) - 1 ) - matProj._32 ) / matProj._22;
		v.z =  1.0f;

		m_vRayDir.x = v.x * matInvView._11 + v.y * matInvView._21 + v.z * matInvView._31;
		m_vRayDir.y = v.x * matInvView._12 + v.y * matInvView._22 + v.z * matInvView._32;
		m_vRayDir.z = v.x * matInvView._13 + v.y * matInvView._23 + v.z * matInvView._33;
	}
	void mouseUtil::calcRayVectorOrthoLH(D3DXMATRIX matView, D3DXMATRIX matProj)
	{
		D3DXMATRIX matInvView;
		D3DVECTOR v;

		D3DXMatrixInverse( &matInvView, NULL, &matView );

		v.x =  (  ( ( ( 2.0f * ( m_nMouseX ) ) / m_nScreenWidth  ) - 1 ) - matProj._31 ) / matProj._11;
		v.y =  ( -( ( ( 2.0f * ( m_nMouseY ) ) / m_nScreenHeight ) - 1 ) - matProj._32 ) / matProj._22;
		v.z =  1.0f;

		m_vRayPos.x	= v.x * matInvView._11 + v.y * matInvView._21 + v.z * matInvView._31;
		m_vRayPos.y	= v.x * matInvView._12 + v.y * matInvView._22 + v.z * matInvView._32;
		m_vRayPos.z	= matInvView._43;

		m_vRayDir.x = matInvView._41;
		m_vRayDir.y = matInvView._42;
		m_vRayDir.z = v.x * matInvView._13 + v.y * matInvView._23 + v.z * matInvView._33;
	}
	void mouseUtil::calcRayVectorRH(D3DXMATRIX matView, D3DXMATRIX matProj)
	{
		D3DXMATRIX matInvView;
		D3DVECTOR v;

		D3DXMatrixInverse( &matInvView, NULL, &matView );

		m_vRayPos.x	= matInvView._41;
		m_vRayPos.y	= matInvView._42;
		m_vRayPos.z	= matInvView._43;

		v.x =  (  ( ( ( 2.0f * ( m_nMouseX ) ) / m_nScreenWidth  ) - 1 ) - matProj._31 ) / matProj._11;
		v.y =  ( -( ( ( 2.0f * ( m_nMouseY ) ) / m_nScreenHeight ) - 1 ) - matProj._32 ) / matProj._22;
		v.z =  -1.0f;

		m_vRayDir.x = v.x * matInvView._11 + v.y * matInvView._21 + v.z * matInvView._31;
		m_vRayDir.y = v.x * matInvView._12 + v.y * matInvView._22 + v.z * matInvView._32;
		m_vRayDir.z = v.x * matInvView._13 + v.y * matInvView._23 + v.z * matInvView._33;
	}
	void mouseUtil::calcRayVectorOrthoRH(D3DXMATRIX matView, D3DXMATRIX matProj)
	{
		D3DXMATRIX matInvView;
		D3DVECTOR v;

		D3DXMatrixInverse( &matInvView, NULL, &matView );

		v.x =  (  ( ( ( 2.0f * ( m_nMouseX ) ) / m_nScreenWidth  ) - 1 ) - matProj._31 ) / matProj._11;
		v.y =  ( -( ( ( 2.0f * ( m_nMouseY ) ) / m_nScreenHeight ) - 1 ) - matProj._32 ) / matProj._22;
		v.z =  -1.0f;

		m_vRayPos.x	= v.x * matInvView._11 + v.y * matInvView._21 + v.z * matInvView._31;
		m_vRayPos.y	= v.x * matInvView._12 + v.y * matInvView._22 + v.z * matInvView._32;
		m_vRayPos.z	= matInvView._43;

		m_vRayDir.x = matInvView._41;
		m_vRayDir.y = matInvView._42;
		m_vRayDir.z = v.x * matInvView._13 + v.y * matInvView._23 + v.z * matInvView._33;
	}
	void mouseUtil::onMouseMove(int nMouseX, int nMouseY)
	{
		m_nMouseX = nMouseX;
		m_nMouseY = nMouseY;
	}
	void mouseUtil::onSize(int nWidth, int nHeight)
	{
		m_nScreenWidth	= nWidth;
		m_nScreenHeight	= nHeight;
	}

	int mouseUtil::getMousePosX()
	{
		return m_nMouseX;
	}
	int mouseUtil::getMousePosY()
	{
		return m_nMouseY;
	}
	void mouseUtil::getMousePos(int* pX, int* pY)
	{
		XM_ASSERT(pX);
		XM_ASSERT(pY);
		*pX = m_nMouseX;
		*pY = m_nMouseY;
	}
	int mouseUtil::getMousePosXByCenter()
	{
		return m_nMouseX - m_nScreenWidth/2;
	}
	int mouseUtil::getMousePosYByCenter()
	{
		return m_nScreenHeight/2 - m_nMouseY;
	}
	void mouseUtil::getMousePosByCenter(int* pX, int* pY)
	{
		XM_ASSERT(pX);
		XM_ASSERT(pY);
		*pX = m_nMouseX - m_nScreenWidth/2;
		*pY = m_nScreenHeight/2 - m_nMouseY;
	}

	int mouseUtil::getScreenWidth()
	{
		return m_nScreenWidth;
	}
	int mouseUtil::getScreenHeight()
	{
		return m_nScreenHeight;
	}
	void mouseUtil::getScreenSize(int* pX, int* pY)
	{
		XM_ASSERT(pX);
		XM_ASSERT(pY);
		*pX = m_nScreenWidth;
		*pY = m_nScreenHeight;
	}

	D3DXVECTOR3 mouseUtil::getRayPos()
	{
		return m_vRayPos;
	}
	D3DXVECTOR3 mouseUtil::getRayDir()
	{
		return m_vRayDir;
	}

} // namespace XM