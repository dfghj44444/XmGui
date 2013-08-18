/*
file : XM_TextureNode.h
*/

#ifndef H_XM_TEXTURENODE_H
#define H_XM_TEXTURENODE_H

namespace XM
{
	class texCreateParam : public baseNode
	{
	public:
		UINT			Width;
		UINT			Height;
		UINT			MipLevels;
		DWORD			Usage;
		D3DFORMAT		Format;
		D3DPOOL			Pool;
		DWORD			Filter;
		DWORD			MipFilter;
		D3DCOLOR		ColorKey;

	public:
		texCreateParam(){
			Width		= D3DX_DEFAULT;
			Height		= D3DX_DEFAULT;
			//		Width		= D3DX_DEFAULT_NONPOW2;
			//		Height		= D3DX_DEFAULT_NONPOW2;
			//		MipLevels	= D3DX_DEFAULT;
			MipLevels	= 1;
			Usage		= 0;
			Format		= D3DFMT_UNKNOWN;
			Pool		= D3DPOOL_MANAGED;
			Filter		= D3DX_DEFAULT;
			MipFilter	= D3DX_DEFAULT;		
			//		Filter		= D3DX_FILTER_NONE;
			//		MipFilter	= D3DX_FILTER_NONE;
			ColorKey	= 0;
		};
		virtual ~texCreateParam(){
		};
	}; // class texCreateParam

	class texNode : public resNode
	{
	protected:
		IDirect3DTexture9*		m_pTexture;
		texCreateParam*			m_pTexCreationParam;
		D3DXIMAGE_INFO			m_texInfo;

	public:
		// ctor/dtor
		texNode();
		texNode(texCreateParam* pParam);
		virtual ~texNode();

		bool					setTextureCreationParam(texCreateParam* pParam = 0);
		texCreateParam*			getTextureCreationParam();

		// create/release/get IDirect3DTexture9
		bool					createTexture();
		IDirect3DTexture9*		getTexture();
		void					releaseTexture();

        const D3DXIMAGE_INFO* getTextureInfo() const { return &m_texInfo; }

		// on create/reset/lost/destroy
		bool					onCreateDevice(IDirect3DDevice9* pDevice);
		bool					onResetDevice(IDirect3DDevice9* pDevice);
		void					onLostDevice();
		void					onDestroyDevice();

	}; // class texNode

} // namespace XM

#endif // H_XM_TEXTURENODE_H