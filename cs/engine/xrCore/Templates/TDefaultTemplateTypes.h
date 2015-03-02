#ifndef __xrCore__TDefaultTemplateTypes_h__
#define __xrCore__TDefaultTemplateTypes_h__

template< typename Type, typename Ptr, typename Ref >
class xrTDefaultTemplateTypes
{
public:
	typedef Type value_type;
	typedef Ptr pointer;
	typedef Ref reference;
	typedef const Ptr const_pointer;
	typedef const Ref const_reference;
};

#endif /// __xrCore__TDefaultTemplateTypes_h__