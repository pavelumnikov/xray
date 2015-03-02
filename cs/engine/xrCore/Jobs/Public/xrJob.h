#include <xrCore/Templates/TLinkedList.h>

#ifndef __xrCore__xrJob_h__
#define __xrCore__xrJob_h__

class xrJob : public xrTLinkedList<xrJob>
{
public:
	virtual ~xrJob() { }
	virtual xrJob* execute() { /* Override in subclass*/ }

private:
	xrJob* m_next;
};

#endif /// __xrCore__xrJob_h__