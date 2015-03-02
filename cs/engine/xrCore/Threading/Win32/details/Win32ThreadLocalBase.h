#ifndef __xrCore__Threading__Win32__Details__Win32ThreadLocalBase_h__
#define __xrCore__Threading__Win32__Details__Win32ThreadLocalBase_h__

namespace details
{
	template< typename Type >
	class Win32ThreadLocalBase
	{
	public:
		~Win32ThreadLocalBase() { 
			TlsFree( tlsData );
		}

		void setData( Type value ) {
			TlsSetValue( tlsData, reinterpret_cast<void*>(value) );
		}

		Type getData() const {
			return reinterpret_cast<Type>(TlsGetValue( tlsData ));
		}

	protected:
		Win32ThreadLocalBase() { 
			DWORD temp = TlsAlloc();
			assert( temp != TLS_OUT_OF_INDEXES );
			tlsData = temp;
		}

	private:
		DWORD tlsData; //!< Thread-local data
	};
}

#endif /// __xrCore__Threading__Win32__Details__Win32ThreadLocalBase_h__