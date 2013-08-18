/*
file : XM_ResourceNode.h
*/

#ifndef H_XM_RESOURCENODE_H
#define H_XM_RESOURCENODE_H

namespace XM
{
	class resNode : public baseNode
	{
	protected:

		// Direct3DDevice9
		IDirect3DDevice9*		m_pDevice;
		CStringW				m_strResname;
		// group
		int						m_nGroupID;

	public:

		resNode();
		virtual ~resNode();

		bool					setDevice(IDirect3DDevice9* pDevice);

		//bool					setResname(WCHAR* strFilename);
		bool					setResname(CStringW strFilename);
		CStringW				getResname();

		// group
		void					setGroupID(int nGroupID);
		int						getGroupID();

		// on create/reset/lost/destroy
		virtual bool			onCreateDevice(IDirect3DDevice9* pDevice);
		virtual bool			onResetDevice(IDirect3DDevice9* pDevice);
		virtual void			onLostDevice();
		virtual void			onDestroyDevice();

	}; // class resNode

	typedef xmVec<resNode*>	listResNode;

} // namespace XM

#endif // H_XM_RESOURCENODE_H