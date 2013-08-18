/*
file : XM_BaseNode.h
*/

#ifndef H_XM_BASENODE_H
#define H_XM_BASENODE_H

namespace XM{

	class baseNode
	{
		XM_RTTI_DECLARE_STATIC

	protected:
		// RTTI
		RTTIClass*		m_pRTTI;
		// reference counting
		int				m_nRefCount;
		// node name
		CStringW		m_strName;
		// true
		bool			m_bNameTable;

	public:
		// ctor/dtor
		baseNode();
		virtual ~baseNode();

		// reference counting
		void			AddRef();
		void			DelRef();
		int				getRef();

		// RTTI
		RTTIClass*		getRTTI();
	}; // class baseNode
} // namespace XM

#endif // H_XM_BASENODE_H