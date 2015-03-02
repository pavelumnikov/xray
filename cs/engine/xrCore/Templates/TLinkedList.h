#include <xrCore/Templates/TDefaultTemplateTypes.h>

#ifndef __xrCore__TLinkedList_h__
#define __xrCore__TLinkedList_h__

template< typename Type >
class xrTLinkedList : public xrTDefaultTemplateTypes< Type, Type*, Type& >
{
public:
	xrTLinkedList() { }

private:
	pointer m_next;
};

#endif /// __xrCore__TLinkedList_h__