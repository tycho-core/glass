//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 5:50:46 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __CORE_TYPES_H_6BAE7CBF_227C_4ACE_A5E6_E80D2EE79241_
#define __CORE_TYPES_H_6BAE7CBF_227C_4ACE_A5E6_E80D2EE79241_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/numeric_type.h"
#include "glass/macro_interface.h"
#include "core/types.h"

//////////////////////////////////////////////////////////////////////////////
// EXPORTS
//////////////////////////////////////////////////////////////////////////////

#define TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(_t) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX(TYCHO_GLASS_ABI, tycho::core:: _t, tycho::glass:: _t##_type)

TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(int64);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(int32);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(int16);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(int8);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(uint64);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(uint32);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(uint16);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(uint8);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(float32);
TYCHO_GLASS_INSTANTIATE_BUILTIN_TYPE(float64);

//////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{	

namespace detail
{

	/// register all builtin types
	void register_core_types();
	
} // end namespace
} // end namespace
} // end namespace

#endif // __CORE_TYPES_H_6BAE7CBF_227C_4ACE_A5E6_E80D2EE79241_
