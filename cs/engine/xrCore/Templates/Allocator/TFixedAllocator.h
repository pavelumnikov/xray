#ifndef __xrCore__Templates__Allocator__TFixedAllocator_h__
#define __xrCore__Templates__Allocator__TFixedAllocator_h__

template< typename T, std::size_t Count >
class xrTFixedAllocator
{
public:
	typedef T value_type;
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
		typedef xrTFixedAllocator<U, Count> other;
	};

	inline explicit xrTFixedAllocator()
		: myPointer( reinterpret_cast<void*>(myPreallocatedPtr) )
		, myOffsetFromBegin( 0 ) {
		std::memset( myPreallocatedPtr, 0, thePreallocatedSpace );
	}
	inline ~xrTFixedAllocator() { }
	inline explicit xrTFixedAllocator( const xrTFixedAllocator& ) { }
	template<typename U>
	inline explicit xrTFixedAllocator( const xrTFixedAllocator<U, Count>& ) { }

	//    address
	inline pointer address( reference r ) { return &r; }
	inline const_pointer address( const_reference r ) { return &r; }

	//    memory allocation
	inline pointer allocate( size_type cnt,
							 typename std::allocator<void>::const_pointer = 0 ) {
		assert( myOffsetFromBegin + cnt * sizeof( value_type ) < thePreallocatedSpace );

		pointer currentPtr = reinterpret_cast<pointer>(reinterpret_cast<uintptr_t>(myPointer)+myOffsetFromBegin);
		myOffsetFromBegin += cnt * sizeof( value_type );

		return currentPtr;
	}

	inline void deallocate( pointer p, size_type ) {
	}

	//    size
	inline size_type max_size() const {
		return std::numeric_limits<size_type>::max() / sizeof( T );
	}

	//    construction/destruction
	inline void construct( pointer p, const T& t ) { new(p)T( t ); }
	inline void destroy( pointer p ) { p->~T(); }

	inline bool operator==(xrInterfaceSpecialAllocator const&) { return true; }
	inline bool operator!=(xrInterfaceSpecialAllocator const& a) { return !operator==(a); }

private:
	enum { thePreallocatedSpace = Count * sizeof( value_type ) };

	uint8_t myPreallocatedPtr[thePreallocatedSpace];

	typename std::allocator<void>::const_pointer myPointer;
	difference_type myOffsetFromBegin;
};

#endif /// __xrCore__Templates__Allocator__TFixedAllocator_h__