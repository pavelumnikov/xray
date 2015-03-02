#include <xrCore/ExtensionFramework/Public/IModuleInterface.h>

#ifndef __xrCore__IInterfaceFactory_h__
#define __xrCore__IInterfaceFactory_h__

class XRCORE_API xrIModuleManager
{
public:
	virtual ~xrIModuleManager() { }
	virtual void RegisterInterface( xrIModuleInterface* iface, uint32_t ifaceCode ) = 0;
	virtual xrIModuleInterface* QueryInterface( uint32_t ifaceCode ) = 0;
	virtual bool IsRegistered( uint32_t ifaceCode ) const = 0;

	template< typename ResultType >
	ResultType* QueryTypedInterface( uint32_t ifaceCode );
};

template< typename ResultType >
IC ResultType* xrIModuleManager::QueryTypedInterface( uint32_t ifaceCode ) {
	xrIModuleInterface* iface = QueryInterface( ifaceCode );
	return static_cast<ResultType*>(iface);
}

extern XRCORE_API xrIModuleManager* XRayInterfaceFactory;

template< typename Type, typename FourCC, typename... Args >
class xrStaticInterfaceRegister
{
public:
	xrStaticInterfaceRegister(Args&&... args) {
		static_assert(std::is_base_of< xrIModuleInterface, Type >::value,
					   "Registering instance must be derived from xrIModuleManager");

		static_assert(typeid(FourCC::value) == typeid(uint32_t), "Return value type must be uint32_t");

		Type* result = new Type(std::forward<Args>(args)...);
		XRayInterfaceFactory->RegisterInterface( result, FourCC::value );
	}
};

#endif /// __xrCore__IInterfaceFactory_h__