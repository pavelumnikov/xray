#include "xrJob.h"

#ifndef __xrCore__IJobDispatcher_h__
#define __xrCore__IJobDispatcher_h__

class xrIJobDispatcher
{
public:
	virtual ~xrIJobDispatcher() { }
	virtual void enqueue( xrJob* root ) = 0;
	virtual void spawn( xrJob* root ) = 0;
	virtual void wait( xrJob* root ) = 0;
};

#endif /// __xrCore__IJobDispatcher_h__