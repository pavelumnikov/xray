#include <xrCore/ExtensionFramework/Public/IModuleInterface.h>

#ifndef __xrCore__IJobManager_h__
#define __xrCore__IJobManager_h__

class xrIJobDispatcher;

class xrIJobManager : public xrIModuleInterface
{
public:
	virtual ~xrIJobManager() { }

	virtual void initialize() = 0;
	virtual void shutdown() = 0;
	virtual bool isInitialized() const = 0;

	virtual xrIJobDispatcher* getCPUDispatcher( bool forceCreate = true ) = 0;
	virtual xrIJobDispatcher* getGPUDispatcher( bool forceCreate = true ) = 0;
	virtual xrIJobDispatcher* getSPUDispatcher( bool forceCreate = true ) = 0;

	virtual bool hasGPUDispatcher() const = 0;
	virtual bool hasSPUDispatcher() const = 0;
};

#endif /// __xrCore__IJobManager_h__