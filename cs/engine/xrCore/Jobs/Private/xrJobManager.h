#include <xrCore/Jobs/Public/IJobManager.h>
#include <xrCore/Jobs/Private/xrJobCPUDispatcher.h>
#include <xrCore/Threading/ThreadLocal.h>

#ifndef __xrCore__Jobs__xrJobManager_h__
#define __xrCore__Jobs__xrJobManager_h__

class xrJobManager : public xrIJobManager
{
public:
	xrJobManager();
	virtual ~xrJobManager();

	virtual void initialize();
	virtual void shutdown();
	virtual bool isInitialized() const;

	virtual xrIJobDispatcher* getCPUDispatcher( bool forceCreate );
	virtual xrIJobDispatcher* getGPUDispatcher( bool forceCreate );
	virtual xrIJobDispatcher* getSPUDispatcher( bool forceCreate );

	virtual bool hasGPUDispatcher() const;
	virtual bool hasSPUDispatcher() const;

private:
	xrIJobDispatcher* _createCpuDispatcher();
	xrIJobDispatcher* _createGpuDispatcher();
	xrIJobDispatcher* _createSpuDispatcher();

	xrThreadLocal< xrIJobDispatcher* > myCpuDispatcherTLS;
	xrThreadLocal< xrIJobDispatcher* > myGpuDispatcherTLS;
	xrThreadLocal< xrIJobDispatcher* > mySpuDispatcherTLS;
};

#endif /// __xrCore__Jobs__xrJobManager_h__