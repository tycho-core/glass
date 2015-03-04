//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 9 December 2008 4:17:33 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MAKE_MEMBER_FUNCTION_TYPE_H_3E8FB75F_88A6_4675_95BA_C86E55E5BCF9_
#define __MAKE_MEMBER_FUNCTION_TYPE_H_3E8FB75F_88A6_4675_95BA_C86E55E5BCF9_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/argument.h"
#include "glass/argument_list.h"
#include "glass/detail/member_function_thunk.h"
#include "core/cast.h"

//////////////////////////////////////////////////////////////////////////////
// FUNCTIONS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
    // avoid circular dependency
    extern TYCHO_GLASS_ABI std::string make_default_name(const char* prefix);

namespace detail
{

#define TYCHO_GLASS_INTERNAL_ADD_PARAMETER(_t, _pt) (nt->add_parameter(static_type_info<_pt>()));
#define TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(_t, _rt) (nt->set_return_type(static_type_info<_rt>()));
#define TYCHO_GLASS_INTERNAL_CAST_ARG(_t, _a) (*((_t*)args.get_argument(_a).get_ptr()))

#if TYCHO_PC
#pragma warning(push)
#pragma warning(disable : 4100)
#endif

#include "member_function_thunk.inl"

#if TYCHO_PC
#pragma warning(pop)
#endif

#undef TYCHO_GLASS_INTERNAL_ADD_PARAMETER
#undef TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE
#undef TYCHO_GLASS_INTERNAL_CAST_ARG

} // end namespace
} // end namespace
} // end namespace

#endif // __MAKE_MEMBER_FUNCTION_TYPE_H_3E8FB75F_88A6_4675_95BA_C86E55E5BCF9_
