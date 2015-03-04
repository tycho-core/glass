//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:50:37 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FORWARD_DECLS_H_F9EE49F2_783F_4862_837E_23300E76C600_
#define __FORWARD_DECLS_H_F9EE49F2_783F_4862_837E_23300E76C600_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	// types
	class base_type;
	class class_type;
	class union_type;
	class function_type;
	class free_function_type;
	class member_function_type;
	class builtin_type;
	class numeric_type;	
	class enum_type;
	class typedef_type;
		
	class symbol;
	class name_space;
	
	// misc
	class argument_list;
	class argument;
	class any_value;
	class name;
	class member_variable;
	class bound_member_variable;
	class member_function;
	class bound_member_function;
	
namespace detail
{
	struct member_function_thunk_base;
	
} // end namespace	

} // end namespace
} // end namespace

#endif // __FORWARD_DECLS_H_F9EE49F2_783F_4862_837E_23300E76C600_
