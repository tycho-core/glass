//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 5:50:46 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "core_types.h"
#include "glass/glass.h"

//////////////////////////////////////////////////////////////////////////////
// EXPORTS
//////////////////////////////////////////////////////////////////////////////

#define TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(_t) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX(TYCHO_GLASS_ABI, tycho::core::_t, tycho::glass::_t##_type)

TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(int64);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(int32);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(int16);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(int8);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(uint64);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(uint32);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(uint16);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(uint8);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(float32);
TYCHO_GLASS_IMPLEMENT_BUILTIN_TYPE(float64);


//////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{	
namespace detail
{

	//--------------------------------------------------------------------

	void register_core_types()
	{
#define REGISTER(_t) { \
	tycho::glass::_t##_type* nt = new tycho::glass::_t##_type(#_t); \
	type_info<tycho::core::_t>::set_type_info(nt); \
 	nt->set_access<tycho::core::_t>(); \
 	bld.add_symbol(nt); \
 	TYCHO_GLASS_DEF_POINTER(_t) }

	TYCHO_GLASS_REGISTER_BEGIN()	
		TYCHO_GLASS_BEGIN_NAMESPACE(tycho)		
			TYCHO_GLASS_BEGIN_NAMESPACE(core)		
				REGISTER(int64);
				REGISTER(int32);
				REGISTER(int16);
				REGISTER(int8);
				REGISTER(uint64);
				REGISTER(uint32);
				REGISTER(uint16);
				REGISTER(uint8);
				REGISTER(float32);
				REGISTER(float64);
			TYCHO_GLASS_END_NAMESPACE()
		TYCHO_GLASS_END_NAMESPACE()
	TYCHO_GLASS_REGISTER_END()
	
#undef REGISTER
	}

} // end namespace
} // end namespace
} // end namespace

