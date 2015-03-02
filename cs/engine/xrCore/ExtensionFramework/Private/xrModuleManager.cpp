#include <xrCore/stdafx.h>
#include <xrCore/ExtensionFramework/Public/IModuleManager.h>

#include <unordered_map>
//#include <xrCore/Templates/Allocator/TFixedAllocator.h>
#include <xrCore/Templates/Allocator/TDefaultAllocator.h>

class xrModuleManager : public xrIModuleManager
{
public:
	xrModuleManager();
	virtual ~xrModuleManager() { }
	virtual void RegisterInterface( xrIModuleInterface* iface, uint32_t ifaceCode );
	virtual xrIModuleInterface* QueryInterface( uint32_t ifaceCode );
	virtual bool IsRegistered( uint32_t ifaceCode ) const;

private:
	static const size_t thePreallocatedCount = 150; //!< 50 kbytes must be enough

	/*typedef std::unordered_map<uint32_t, 
		xrIModuleInterface*,
		std::hash<uint32_t>,
		std::equal_to<uint32_t>,
		xrTFixedAllocator< std::pair< const uint32_t, xrIModuleInterface*>, thePreallocatedCount > > InterfaceHashMap;*/

	typedef std::unordered_map<uint32_t,
		xrIModuleInterface*,
		std::hash<uint32_t>,
		std::equal_to<uint32_t>,
		xrTDefaultAllocator< std::pair< const uint32_t, xrIModuleInterface*> > > InterfaceHashMap;

	InterfaceHashMap myAllocatedInterfaces;

	InterfaceHashMap::const_iterator _isRegisteredInterface( uint32_t ifaceCode ) const;
};

static xrModuleManager theInterfaceFactory;
xrIModuleManager* XRayInterfaceFactory = &theInterfaceFactory;

xrModuleManager::xrModuleManager() {
}

void xrModuleManager::RegisterInterface( xrIModuleInterface* iface, uint32_t ifaceCode ) {
	InterfaceHashMap::const_iterator iter = _isRegisteredInterface( ifaceCode );
	if ( iter != myAllocatedInterfaces.end() )
		return;

	myAllocatedInterfaces[ifaceCode] = iface;
}

xrIModuleInterface* xrModuleManager::QueryInterface( uint32_t fourCC ) {
	if ( !fourCC )
		return nullptr;

	InterfaceHashMap::const_iterator iter = _isRegisteredInterface( fourCC );
	if ( iter == myAllocatedInterfaces.end() )
		return nullptr;

	xrIModuleInterface* interface = iter->second;
	return interface;
}

bool xrModuleManager::IsRegistered( uint32_t ifaceCode ) const {
	const InterfaceHashMap::const_iterator iter = _isRegisteredInterface( ifaceCode );
	if ( iter != myAllocatedInterfaces.end() )
		return false;

	return true;
}

xrModuleManager::InterfaceHashMap::const_iterator xrModuleManager::_isRegisteredInterface( uint32_t ifaceCode ) const {
	return myAllocatedInterfaces.find( ifaceCode );
}