#include <type_traits>

#ifndef __xrCore__Templates__TTypeTraits_h__
#define __xrCore__Templates__TTypeTraits_h__

template< typename TypeA, typename TypeB >
struct xrTraitCanBeStaticCasted
{
	enum { value = std::is_base_of< TypeA, TypeB >::value || std::is_base_of< TypeB, TypeA >::value };
};

#endif /// __xrCore__Templates__TTypeTraits_h__