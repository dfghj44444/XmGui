/*

file : XM_UI_RectItem.h

*/

#ifndef H_XM_UI_RectITEM_H
#define H_XM_UI_RectITEM_H
struct VTXTYPE_2D_COLOR_TEX1
{
	float x, y, z, h;
	D3DCOLOR color;
	float tu, tv;
	static DWORD FVF;
}; // struct VTXTYPE_2D_COLOR_TEX1

namespace XM
{
	class UI_RectItem : public UI_Base
	{
		XM_RTTI_DECLARE_STATIC

	protected:

		texNode*				m_pTexNode;						// 텍스쳐 노드

//		bool					m_bTEST;

		// position
		D3DXVECTOR3				m_vParentPos;
		D3DXVECTOR3				m_vPos;
		D3DXVECTOR3				m_vSize;

		// hit test
		bool					m_bUseHitTest;

		float					m_fTexCoords[8];
		float					m_fTexCoords_Size[2];

		VTXTYPE_2D_COLOR_TEX1	m_Vertices[4];

	protected:

		// update rect
		void					updateItemRect();
		void					updateVertexTexCoord();

	public:

		// ctor/dtor
		UI_RectItem();
		virtual ~UI_RectItem();

		// serialize
		virtual bool			saveFile(IStream& rStream);
		virtual bool			loadFile(IStream& rStream);

		virtual void			frameMove(DWORD dwElapsedTime);
		void					render(IDirect3DDevice9* pDevice);

		virtual bool hitTest(int mouseX, int mouseY, float& zOut);

		void					setTexture(const WCHAR* strTexture);
		void					setTexture(texNode* pTexNode);
		const texNode*			getTexNode();
		const IDirect3DTexture9* getTexture();

		void					setAlpha( const int& nAl = 255 );

//		void					SetTEST( bool bFlag );

		// hit test
		void					enableHitTest(bool bFlag);
		bool					getUseHitTest();

		// size, position
		void					setSize(const D3DXVECTOR3& vSize);
		void					getSize(D3DXVECTOR3& vOut) const;
		const D3DXVECTOR3&		getSize() const;
		void					setPos(const D3DXVECTOR3& vPos);
		void					getPos(D3DXVECTOR3& vOut) const;
		const D3DXVECTOR3&		getPos() const;
		void					setParentPos(const D3DXVECTOR3& vPos);
		void					getParentPos(D3DXVECTOR3& vOut) const;
		const D3DXVECTOR3&		getParentPos() const;

		// texcoords
		void					setTexCoords_Size(const D3DXVECTOR3& vSize);
		void					setTexCoords_Size(float x, float y);
		void					setTexCoords(float x, float y);
        void					setTexCoords(float x0, float y0, float x1, float y1);

		void					setTexCoords(const float* pTexCoords);
		void					getTexCoords(float* pTexCoordsIn);
		const float*			getTexCoords();

	}; // class UI_RectItem

} // namespace XM

#endif // H_XM_UI_RectITEM_H