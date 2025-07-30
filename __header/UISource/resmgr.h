/*
file : XM_ResourceMgr.h
*/

#ifndef H_XM_RESOURCEMANAGER_H
#define H_XM_RESOURCEMANAGER_H

namespace XM
{
	class resMgr : public baseNode
	{
	protected:

		 xmVec<resNode*>		m_listResources;

	public:

		resMgr();
		virtual ~resMgr();

		// clear
		void					clear();

	}; // class resMgr

} // namespace XM

#endif // H_XM_RESOURCEMANAGER_H