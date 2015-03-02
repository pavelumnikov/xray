#include <xrCore/Threading/Win32/details/Win32ThreadLocalBase.h>
#include <xrCore/Templates/TDefaultTemplateTypes.h>
#include <xrCore/Templates/TTypeTraits.h>

#ifndef __xrCore__Threading__Win32__Win32ThreadLocal_h__
#define __xrCore__Threading__Win32__Win32ThreadLocal_h__

template< typename Type >
class xrThreadLocal : protected details::Win32ThreadLocalBase<Type>
{
public:
	typedef xrThreadLocal this_type;
	typedef Type value_type;

	xrThreadLocal() { }

	xrThreadLocal( value_type value ) {
		setData( value );
	}

	~xrThreadLocal() { }

	this_type& operator = (value_type val) { 
		setData( val );
		return *this;
	}

	operator value_type () { 
		Type value = getData();
		return value;
	}
};

template< typename Type >
class xrThreadLocal < Type* > : protected details::Win32ThreadLocalBase<Type*>
{
public:
	typedef xrThreadLocal this_type;
	typedef Type value_type;
	typedef Type* pointer;
	typedef Type& reference;

	xrThreadLocal() { }

	xrThreadLocal( pointer initialValue ) {
		setData( initialValue );
	}

	~xrThreadLocal() { }

	this_type& operator = (pointer ptr) {
		setData( ptr );
		return *this;
	}

	this_type& operator = (this_type& rhs) {
		pointer ptr = rhs.getData();
		setData( ptr );
		return *this;
	}

	template< typename U >
	this_type& operator = (xrThreadLocal<U*>& rhs) { 
		pointer ptr = static_cast<typename xrThreadLocal<U*>::pointer>(rhs.getData());
		setData( ptr );
		return *this;
	}

	operator pointer () { 
		pointer ptr = getData();
		return ptr;
	} 

	pointer operator -> () { 
		pointer ptr = getData();
		return ptr;
	}

	reference operator * () { 
		pointer ptr = getData();
		return *ptr;
	}

	bool operator != (pointer ptr) const { 
		return !operator==(ptr);
	}

	bool operator == (pointer ptr) const { 
		pointer p = getData();
		return p == ptr;
	}

	bool operator != (this_type& rhs) const { 
		return !operator==(rhs);
	}

	bool operator == (this_type& rhs) const {
		pointer ptr = rhs.getData();
		pointer p = getData();
		return p == ptr;
	}

	template< typename U >
	bool operator != (typename xrThreadLocal<U*>::pointer ptr) const { 
		return !operator==(ptr);
	}

	template< typename U >
	bool operator == (typename xrThreadLocal<U*>::pointer ptr) const { 
		pointer p = getData();
		return p == static_cast<pointer>(ptr);
	}

	template< typename U >
	bool operator != (xrThreadLocal<U*>& rhs) const { 
		return !operator==(rhs);
	}

	template< typename U >
	bool operator == (xrThreadLocal<U*>& rhs) const { 
		typename xrThreadLocal<U*>::pointer ptr = rhs.getData();
		pointer p = getData();
		return p == static_cast<pointer>(ptr);
	}
};

#endif /// __xrCore__Threading__Win32__Win32ThreadLocal_h__