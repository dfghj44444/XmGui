/*
file : XM_RTTI.h
*/

#ifndef H_XM_RTTI_H
#define H_XM_RTTI_H
#include <atlstr.h>

namespace XM
{
	class RTTIClass
	{
	protected:

		RTTIClass*				m_pSuper;
		CStringW				m_strName;

	protected:

		// name
		void					setName(const WCHAR* strName);
		void					setName(const CStringW strName);

	public:

		// ctor/dtor
		RTTIClass();
		RTTIClass(const WCHAR* strName, RTTIClass* pSuper);
		~RTTIClass();

		// name
		const WCHAR*			getName();

		// parent
		RTTIClass*				getSuper();

		// check RTTIClass
		 bool					isA(RTTIClass* pRTTI);			
		 bool					isAKindOf(RTTIClass* pRTTI);	
	}; // class RTTIClass

    class UI_Widget;
    UI_Widget* createControl(const CStringW& name);

} // namespace XM

#define XM_RTTI_DECLARE_STATIC											public:	static XM::RTTIClass RTTI;
#define XM_RTTI_CREATE_STATIC(RTTIUserClass, className, SuperUser)		XM::RTTIClass RTTIUserClass::RTTI(className, &(SuperUser::RTTI));
#define XM_RTTI_INIT_POINTER											m_pRTTI = &RTTI

#define XM_RTTI_ASSERT_ISA(x, y)										XM_ASSERT(x->getRTTI()->isA(&y::RTTI) == true)
#define XM_RTTI_ASSERT_ISAKINDOF(x, y)									XM_ASSERT(x->getRTTI()->isAKindOf(&y::RTTI) == true)

#endif // H_XM_RTTI_H