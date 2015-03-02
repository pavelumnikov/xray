#ifndef __xrCore__IModuleInterface_h__
#define __xrCore__IModuleInterface_h__

template <uint8_t a, uint8_t b, uint8_t c, uint8_t d>
struct xrInterfaceFourCC
{
	static const uint32_t value = ((uint32_t)(((d) << 24) | (uint32_t( c ) << 16) | (uint32_t( b ) << 8) | uint32_t( a )));
};

class XRCORE_API xrIModuleInterface
{
public:
	virtual ~xrIModuleInterface() { }
};

#endif /// __xrCore__IModuleInterface_h__