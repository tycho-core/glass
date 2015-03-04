//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 9 December 2008 5:50:07 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MEMBER_FUNCTION_THUNK_H_880EF33C_C5C5_46D2_8CC4_DB78C6B14C09_
#define __MEMBER_FUNCTION_THUNK_H_880EF33C_C5C5_46D2_8CC4_DB78C6B14C09_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
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

	/// Base class for all member function thunks. Derived versions are generated to cope with
	/// up to tycho::glass::MaxArity number of parameters and varying return type.
	struct member_function_thunk_base
	{
		virtual ~member_function_thunk_base() {}
		virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const = 0;
	};

} // end namespace
} // end namespace
} // end namespace

#endif // __MEMBER_FUNCTION_THUNK_H_880EF33C_C5C5_46D2_8CC4_DB78C6B14C09_
