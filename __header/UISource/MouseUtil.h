/*

file : XM_MouseUtil.h

*/

#ifndef H_XM_MOUSEUTIL_H
#define H_XM_MOUSEUTIL_H

namespace XM
{
	class mouseUtil : public baseNode
	{
	protected:

		int						m_nMouseX;
		int						m_nMouseY;

		int						m_nScreenWidth;
		int						m_nScreenHeight;

		D3DXVECTOR3				m_vRayPos;
		D3DXVECTOR3				m_vRayDir;

	public:

		mouseUtil();
		virtual ~mouseUtil();

		void					calcRayVectorLH(D3DXMATRIX matView, D3DXMATRIX matProj);
		void					calcRayVectorOrthoLH(D3DXMATRIX matView, D3DXMATRIX matProj);
		void					calcRayVectorRH(D3DXMATRIX matView, D3DXMATRIX matProj);
		void					calcRayVectorOrthoRH(D3DXMATRIX matView, D3DXMATRIX matProj);

		void					onMouseMove(int nMouseX, int nMouseY);
		void					onSize(int nWidth, int nHeight);

		int						getMousePosX();
		int						getMousePosY();
		void					getMousePos(int* pX, int* pY);
		int						getMousePosXByCenter();
		int						getMousePosYByCenter();
		void					getMousePosByCenter(int* pX, int* pY);
		int						getScreenWidth();
		int						getScreenHeight();
		void					getScreenSize(int* pX, int* pY);
		D3DXVECTOR3				getRayPos();
		D3DXVECTOR3				getRayDir();

	}; // class mouseUtil

} // namespace XM

#endif // H_XM_MOUSEUTIL_H