/*

file : XM_UI_RectItem.cpp

*/


#include "stdafx.h"

namespace XM
{
	XM_RTTI_CREATE_STATIC(UI_RectItem, L"UI_RectItem", UI_Base);
	///////////////////////////////////////////////////////////////////////////
	// ctor/dtor
	UI_RectItem::UI_RectItem()
	{
		XM_RTTI_INIT_POINTER;

		m_pTexNode				= 0;

		// hit test
		m_bUseHitTest			= true;

		m_fTexCoords_Size[0]	= 0.0f;
		m_fTexCoords_Size[1]	= 0.0f;

		m_fTexCoords[0]			= 0.0f;		m_fTexCoords[1]			= 0.0f;
		m_fTexCoords[2]			= 1.0f;		m_fTexCoords[3]			= 0.0f;
		m_fTexCoords[4]			= 1.0f;		m_fTexCoords[5]			= 1.0f;
		m_fTexCoords[6]			= 0.0f;		m_fTexCoords[7]			= 1.0f;
		updateVertexTexCoord();

		// h = 1
		m_Vertices[0].h			= 1.0f;		m_Vertices[1].h			= 1.0f;
		m_Vertices[2].h			= 1.0f;		m_Vertices[3].h			= 1.0f;
		m_Vertices[0].color		= D3DCOLOR_ARGB(255, 255, 255, 255);
		m_Vertices[1].color		= D3DCOLOR_ARGB(255, 255, 255, 255);
		m_Vertices[2].color		= D3DCOLOR_ARGB(255, 255, 255, 255);
		m_Vertices[3].color		= D3DCOLOR_ARGB(255, 255, 255, 255);

		m_vParentPos			= D3DXVECTOR3(0, 0, 0);
		m_vPos					= D3DXVECTOR3(0, 0, 0);
		m_vSize					= D3DXVECTOR3(10, 10, 1);
		updateItemRect();
	}
	UI_RectItem::~UI_RectItem()
	{
		_SAFE_DEREF(m_pTexNode);
	}
	// ctor/dtor
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// serialize
	bool UI_RectItem::saveFile(IStream& rStream)
	{
		bool bTex = m_pTexNode? true:false;
		ISTREAM_WRITEBool(rStream, bTex);

		if(bTex)
			ISTREAM_WRITESTRING(rStream, m_pTexNode->getResname()) ;

		// hit test
		ISTREAM_WRITEBool(rStream, m_bUseHitTest) ;
		ISTREAM_WRITEVEC3(rStream, m_vParentPos)  ;
		ISTREAM_WRITEVEC3(rStream, m_vPos)  ;
		ISTREAM_WRITEVEC3(rStream, m_vSize);

		for(int i = 0; i<8; ++i)
		{
			ISTREAM_WRITEFLOAT(rStream, m_fTexCoords[i]) ;
		}

		return true;
	}
	bool UI_RectItem::loadFile(IStream& rStream)
	{
		_SAFE_DEREF(m_pTexNode);

		bool bTex;
		ISTREAM_READBool(rStream, &bTex) ;
		if(bTex == true)
		{
			CStringW strTexture;
			ISTREAM_READSTRING(rStream, &strTexture) ;
			m_pTexNode = g_pStaticTexMgr->getTextureNode(strTexture);
			if(m_pTexNode != 0)
			{
				m_pTexNode->AddRef();
			}
		}


		// hit test
		ISTREAM_READBool(rStream, &m_bUseHitTest) ;
		ISTREAM_READVEC3(rStream, &m_vParentPos) ;
		ISTREAM_READVEC3(rStream, &m_vPos) ;
		ISTREAM_READVEC3(rStream, &m_vSize) ;

		for(int i = 0; i<8; ++i)
		{
			ISTREAM_READFLOAT(rStream, &(m_fTexCoords[i])) ;
		}

		updateItemRect();
		updateVertexTexCoord();

		return true;
	}
	// serialize
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// update rect
	void UI_RectItem::updateItemRect()
	{
		m_Vertices[0].x = m_vPos.x + m_vParentPos.x;
		m_Vertices[1].x = static_cast<float>((long)(m_vPos.x + m_vParentPos.x + m_vSize.x)) - 0.5f;
		m_Vertices[2].x = m_Vertices[1].x;
		m_Vertices[3].x = m_Vertices[0].x;

		m_Vertices[0].y = m_vPos.y + m_vParentPos.y;
		m_Vertices[1].y = m_Vertices[0].y;
		m_Vertices[2].y = static_cast<float>((long)(m_vPos.y + m_vParentPos.y + m_vSize.y)) - 0.5f;
		m_Vertices[3].y = m_Vertices[2].y;

		m_Vertices[0].z = m_vPos.z + m_vParentPos.z;
		m_Vertices[1].z = m_Vertices[0].z;
		m_Vertices[2].z = m_Vertices[0].z;
		m_Vertices[3].z = m_Vertices[0].z;

	}
	void UI_RectItem::updateVertexTexCoord()
	{
		m_Vertices[0].tu = m_fTexCoords[0]; m_Vertices[0].tv = m_fTexCoords[1];
		m_Vertices[1].tu = m_fTexCoords[2]; m_Vertices[1].tv = m_fTexCoords[3];
		m_Vertices[2].tu = m_fTexCoords[4]; m_Vertices[2].tv = m_fTexCoords[5];
		m_Vertices[3].tu = m_fTexCoords[6]; m_Vertices[3].tv = m_fTexCoords[7];
	}
	// update rect
	///////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////
	// frameMove
	void UI_RectItem::frameMove(DWORD dwElapsedTime)
	{

	}
	// frameMove
	//////////////////////////////////////////////////////////////////////////
	
	///////////////////////////////////////////////////////////////////////////
	// render
	void UI_RectItem::render(IDirect3DDevice9* pDevice)
	{
		XM_ASSERT(pDevice);

		if((pDevice == 0)||(m_pTexNode == 0))
			return;

		IDirect3DTexture9* pTexture = m_pTexNode->getTexture();
		if(pTexture == 0)	
			return;

		pDevice->SetTexture(0, pTexture);
		pDevice->SetFVF(VTXTYPE_2D_COLOR_TEX1::FVF);
		pDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_Vertices,	sizeof(VTXTYPE_2D_COLOR_TEX1));
	}

	// render
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// hit test
	bool UI_RectItem::hitTest(int mouseX, int mouseY, float& zOut)
	{
		if(!m_bUseHitTest)
			return false;

		float fMouseX = static_cast<float>(mouseX);
		float fMouseY = static_cast<float>(mouseY);

		if( fMouseX >= m_Vertices[0].x
         && fMouseX <= m_Vertices[1].x
         && fMouseY >= m_Vertices[0].y
         && fMouseY <= m_Vertices[2].y)
		{
			zOut = m_Vertices[0].z;
			return true;
		}

		return false;
	}
	// hit test
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	void UI_RectItem::setTexture(const WCHAR* strTexture)
	{
        texNode* pTexNode = g_pStaticTexMgr->getTextureNode(strTexture);
        if(pTexNode)
			pTexNode->AddRef();

		_SAFE_DEREF(m_pTexNode);
        m_pTexNode = pTexNode;
	}

	void UI_RectItem::setTexture(texNode* pTexNode)
	{
		_SAFE_DEREF(m_pTexNode);
		m_pTexNode = pTexNode;
		_SAFE_REF(m_pTexNode);
	}
	const texNode* UI_RectItem::getTexNode()
	{
		return m_pTexNode;
	}
	const IDirect3DTexture9* UI_RectItem::getTexture()
	{
		if(m_pTexNode)
		{
			return m_pTexNode->getTexture();
		}
		return 0;
	}

	void UI_RectItem::setAlpha( const int& nAl )
	{
		int nAlph = nAl;
		if( nAlph > 255) { nAlph = 255; }
		else if( nAlph < 0 ) { nAlph = 0; }
		m_Vertices[0].color		= D3DCOLOR_ARGB(nAlph, 255, 255, 255);
		m_Vertices[1].color		= D3DCOLOR_ARGB(nAlph, 255, 255, 255);
		m_Vertices[2].color		= D3DCOLOR_ARGB(nAlph, 255, 255, 255);
		m_Vertices[3].color		= D3DCOLOR_ARGB(nAlph, 255, 255, 255);
	}
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// hit test
	void UI_RectItem::enableHitTest(bool bFlag)
	{
		m_bUseHitTest = bFlag;
	}

	bool UI_RectItem::getUseHitTest()
	{
		return m_bUseHitTest;
	}
	// hit test
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// size, position
	void UI_RectItem::setSize(const D3DXVECTOR3& vSize)
	{
		m_vSize = vSize;
		updateItemRect();
	}
	void UI_RectItem::getSize(D3DXVECTOR3& vOut) const
	{		
		vOut = m_vSize;
	}
	const D3DXVECTOR3& UI_RectItem::getSize() const
	{
		return m_vSize;
	}
	void UI_RectItem::setPos(const D3DXVECTOR3& vPos)
	{
		m_vPos = vPos;
		updateItemRect();
	}
	void UI_RectItem::getPos(D3DXVECTOR3& vOut) const
	{
		vOut = m_vPos;
	}
	const D3DXVECTOR3& UI_RectItem::getPos() const
	{
		return m_vPos;
	}
	void UI_RectItem::setParentPos(const D3DXVECTOR3& vPos)
	{
		if(m_vParentPos == vPos) return;
		m_vParentPos = vPos;
		updateItemRect();
	}
	void UI_RectItem::getParentPos(D3DXVECTOR3& vOut) const
	{
		vOut = m_vParentPos;
	}
	const D3DXVECTOR3& UI_RectItem::getParentPos() const
	{
		return m_vParentPos;
	}
	// size, position, update rect
	///////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////
	// texcoords
	void UI_RectItem::setTexCoords_Size( const D3DXVECTOR3& vSize )
	{
		m_fTexCoords_Size[0] = vSize.x;
		m_fTexCoords_Size[1] = vSize.y;
	}

	void UI_RectItem::setTexCoords_Size(float x, float y)
	{
		m_fTexCoords_Size[0] = x;
		m_fTexCoords_Size[1] = y;
	}

	void UI_RectItem::setTexCoords(float x, float y)
	{	
		if( m_fTexCoords_Size[0] && m_fTexCoords_Size[1] )
		{
			m_fTexCoords[0] = ((x+0.5f)/m_fTexCoords_Size[0]);
            m_fTexCoords[1] = ((y+0.5f)/m_fTexCoords_Size[1]);
			
            m_fTexCoords[2] = ((x+m_vSize.x)/m_fTexCoords_Size[0]);	
            m_fTexCoords[3] = ((y+0.5f)/m_fTexCoords_Size[1]);
			
            m_fTexCoords[4] = ((x+m_vSize.x)/m_fTexCoords_Size[0]);	
            m_fTexCoords[5] = ((y+m_vSize.y)/m_fTexCoords_Size[1]);
			
            m_fTexCoords[6] = ((x+0.5f)/m_fTexCoords_Size[0]);		
            m_fTexCoords[7] = ((y+m_vSize.y)/m_fTexCoords_Size[1]);

			updateVertexTexCoord();
		}
	}

    void UI_RectItem::setTexCoords(float x0, float y0, float x1, float y1)
    {
        if( m_fTexCoords_Size[0] && m_fTexCoords_Size[1] )
        {
            m_fTexCoords[0] = x0/m_fTexCoords_Size[0];
            m_fTexCoords[1] = y0/m_fTexCoords_Size[1];

            m_fTexCoords[2] = x1/m_fTexCoords_Size[0];	
            m_fTexCoords[3] = y0/m_fTexCoords_Size[1];

            m_fTexCoords[4] = x1/m_fTexCoords_Size[0];	
            m_fTexCoords[5] = y1/m_fTexCoords_Size[1];

            m_fTexCoords[6] = x0/m_fTexCoords_Size[0];		
            m_fTexCoords[7] = y1/m_fTexCoords_Size[1];

            updateVertexTexCoord();
        }
    }

	void UI_RectItem::setTexCoords(const float* pTexCoords)
	{
		XM_ASSERT(pTexCoords);
		if(pTexCoords == 0)
		{
			return;
		}
		memcpy(m_fTexCoords, pTexCoords, sizeof(float)*8);
		updateVertexTexCoord();
	}
	void UI_RectItem::getTexCoords(float* pTexCoordsIn)
	{
		XM_ASSERT(pTexCoordsIn);
		if(pTexCoordsIn == 0)
		{
			return;
		}
		memcpy(pTexCoordsIn, m_fTexCoords, sizeof(float)*8);
	}
	const float* UI_RectItem::getTexCoords()
	{
		return m_fTexCoords;
	}
	// texcoords
	///////////////////////////////////////////////////////////////////////////

} // namespace XM