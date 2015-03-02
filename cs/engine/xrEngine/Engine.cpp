// Engine.cpp: implementation of the CEngine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Engine.h"
#include "dedicated_server_only.h"

#include <xrCore/ExtensionFramework/Public/IModuleManager.h>

CEngine				Engine;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEngine::CEngine()
{
	
}

CEngine::~CEngine()
{
	
}

extern	void msCreate		(LPCSTR name);

PROTECT_API void CEngine::Initialize	(void)
{
	// Other stuff
	//Engine.Sheduler.Initialize			( );
	// 
	CSheduler* shedulerIface = new CSheduler();
	XRayInterfaceFactory->RegisterInterface( shedulerIface, xrInterfaceFourCC<'G', 'S', 'H', 'D'>::value );
#ifdef DEBUG
	msCreate							("game");
#endif
}

void CEngine::Destroy	()
{
	//Engine.Sheduler.Destroy				( );
#ifdef DEBUG_MEMORY_MANAGER
	extern void	dbg_dump_leaks_prepare	( );
	if (Memory.debug_mode)				dbg_dump_leaks_prepare	();
#endif // DEBUG_MEMORY_MANAGER
	Engine.External.Destroy				( );
}
