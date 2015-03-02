#ifndef __xrCore__Templates__Allocator__TDefaultAllocator_h__
#define __xrCore__Templates__Allocator__TDefaultAllocator_h__

template< typename Type >
class xrTDefaultAllocator
{
public:
	typedef Type value_type;
	typedef value_type* pointer;
	typedef const value_type* const_pointer;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef std::size_t size_type;
	typedef std::ptrdiff_t difference_type;

	//    convert an allocator<T> to allocator<U>
	template<typename U>
	struct rebind
	{
		typedef xrTDefaultAllocator<U> other;
	};

	inline explicit xrTDefaultAllocator() { }
	inline ~xrTDefaultAllocator() { }
	inline explicit xrTDefaultAllocator( const xrTDefaultAllocator& ) { }

	template<typename U>
	inline explicit xrTDefaultAllocator( const xrTDefaultAllocator<U>& ) { }

	//    address
	inline pointer address( reference r ) { return &r; }
	inline const_pointer address( const_reference r ) { return &r; }

	//    memory allocation
	inline pointer allocate( size_type cnt,
							 typename std::allocator<void>::const_pointer = 0 ) {
		return static_cast<pointer>(Memory.mem_alloc( cnt * sizeof( value_type ), "C++" ));
	}

	inline void deallocate( pointer p, size_type ) {
		Memory.mem_free( p );
	}

	//    size
	inline size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof( value_type );
	}

	//    construction/destruction
	inline void construct( pointer p, const value_type& t ) { new(p)value_type( t ); }
	inline void destroy( pointer p ) { p->~value_type(); }

	inline bool operator==(xrTDefaultAllocator const&) { return true; }
	inline bool operator!=(xrTDefaultAllocator const& a) { return !operator==(a); }
};

#endif /// __xrCore__Templates__Allocator__TDefaultAllocator_h__