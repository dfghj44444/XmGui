/*

file : XM_TextureMgr.h

*/

#ifndef H_XM_TEXTUREMGRD3D9_H
#define H_XM_TEXTUREMGRD3D9_H

namespace XM
{
	class texMgr : public resMgr
	{

	protected:

	public:

		texMgr();
		virtual ~texMgr();

		texNode*				getTextureNode(CStringW filename);
		texNode*				getTextureNode(CStringW filename, texCreateParam* pParam);

	}; // class texMgr
}

#endif // H_XM_TEXTUREMGRD3D9_H