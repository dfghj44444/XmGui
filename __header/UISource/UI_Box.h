
#ifndef UI_CONTAINER_H
#define UI_CONTAINER_H

namespace XM
{
    class UI_Box : public UI_Object
    {
        XM_RTTI_DECLARE_STATIC

    public:
        UI_Box();
        virtual ~UI_Box();

        // serialize
        virtual bool		saveFile(IStream& rStream);
        virtual bool		loadFile(IStream& rStream);
        
		virtual void		updatePosition();

        virtual void		frameMove(DWORD dwElapsedTime);
        virtual void		render( IDirect3DDevice9* pd3dDevice);

        virtual UI_Object*	hitTest(int nMouseX, int nMouseY, float& zDist);
        virtual UI_Object*	findControl(int nControlID) const;
		virtual UI_Object*	getMouseObject();

        bool				hasControl(UI_Object* pControl) const;
        bool				addControl(UI_Object* pControl);

        void				setControlVisible(int nID, bool bFlag);
        bool				getControlVisible(int nID);
        bool				getControlVisible(int nID, bool& value);
        void				setControlEnabled(int nID, bool bFlag);
        int					getControlEnabled(int nID, bool& value);

		//pos
		void					setOffset(float x, float y);
		float					getOffsetX() const { return m_fOffsetX; }
		float					getOffsetY() const { return m_fOffsetY; }

		inline float			getPosX() const	   { return m_vPos.x; };
		inline float			getPosY() const	   { return m_vPos.y; };
		inline float			getPosZ() const    { return m_vPos.z; };

		// UIManager ID
		virtual void			setSuperID(int nID);

    protected:
        xmVec<UI_Object*>		m_listControls;
        float					m_fOffsetX;
        float					m_fOffsetY;

		D3DXVECTOR3             m_vPos;

		int						m_nSuperID;

		float					m_Width;
		float					m_Height;
    };
}

#endif