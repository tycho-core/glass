//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 3:09:21 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __UTILITIES_H_977ACB6C_9332_4AAC_9B25_52D0A6154DF0_
#define __UTILITIES_H_977ACB6C_9332_4AAC_9B25_52D0A6154DF0_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/type_info.h"
#include "glass/forward_decls.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
namespace detail
{

	/// \returns The type info of the member type pointed to through a pointer to member.
	template<class T, class U> const base_type* extract_pointed_to_member_type(U T::*)
	{
		return type_info<U>::get_type_info();
	}
	

} // end namespace
} // end namespace
} // end namespace

#endif // __UTILITIES_H_977ACB6C_9332_4AAC_9B25_52D0A6154DF0_
