#include <xrCore/Jobs/Public/IJobDispatcher.h>

#ifndef __xrCore__Jobs__xrJobDispatcher_h__
#define __xrCore__Jobs__xrJobDispatcher_h__

class xrJobCPUDispatcher : public xrIJobDispatcher
{
public:
	xrJobCPUDispatcher() { }
	virtual ~xrJobCPUDispatcher() { }
	virtual void enqueue( xrJob* root );
	virtual void spawn( xrJob* root );
	virtual void wait( xrJob* root );
};

#endif /// __xrCore__Jobs__xrJobDispatcher_h__