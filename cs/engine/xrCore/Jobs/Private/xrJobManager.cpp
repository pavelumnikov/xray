#include <xrCore/stdafx.h>
#include <xrCore/Jobs/Private/xrJobManager.h>
#include <xrCore/ExtensionFramework/Public/IModuleManager.h>

#include <xrCore/Jobs/Private/xrJobCPUDispatcher.h>

xrJobManager::xrJobManager() {
}

xrJobManager::~xrJobManager() { 
}

void xrJobManager::initialize() {

}

void xrJobManager::shutdown() {

}

bool xrJobManager::isInitialized() const {
	return true;
}

xrIJobDispatcher* xrJobManager::getCPUDispatcher( bool forceCreate ) {
	xrIJobDispatcher* dispatcher = myCpuDispatcherTLS;
	if ( dispatcher != nullptr && forceCreate ) {
		dispatcher = _createCpuDispatcher();
		myCpuDispatcherTLS = dispatcher;
	}

	return dispatcher;
}

xrIJobDispatcher* xrJobManager::getGPUDispatcher( bool forceCreate ) {
	return nullptr;
}

xrIJobDispatcher* xrJobManager::getSPUDispatcher( bool forceCreate ) {
	return nullptr;
}

bool xrJobManager::hasGPUDispatcher() const {
	return myGpuDispatcherTLS != nullptr;
}

bool xrJobManager::hasSPUDispatcher() const {
	return mySpuDispatcherTLS != nullptr;
}

xrIJobDispatcher* xrJobManager::_createCpuDispatcher() {
	return nullptr;
}

static xrStaticInterfaceRegister<xrJobManager, xrInterfaceFourCC<'J', 'M', 'A', 'N'>> RegisterJobManagerInterface();