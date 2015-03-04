//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 9 June 2009 7:54:07 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __UTILS_H_CEF31E77_782B_413E_B0BF_E86A19FE4E34_
#define __UTILS_H_CEF31E77_782B_413E_B0BF_E86A19FE4E34_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/argument.h"
#include "glass/class_type.h"
#include "glass/bound_member_variable.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
namespace utils
{

	/// Creates a list of all unique objects referenced by the passed object.
	TYCHO_GLASS_ABI bool gather_unique_objects(const base_type*, const void* ptr, std::vector<glass::argument>& unique_objects);

	/// get a object member value
	template<class T> bool read_value(const class_type* type, void* obj_ptr, const char* name, T& dst)
	{
		const member_variable* mem_var = type->find_member_variable(name);
		if(!mem_var)
			return false;
		bound_member_variable var(mem_var, obj_ptr);
		return var.read<T>(dst);
	}

	/// write a object member value
	template<class T> bool write_value(const class_type* type, void* obj_ptr, const char* name, const T& dst)
	{
		const member_variable* mem_var = type->find_member_variable(name);
		if(!mem_var)
			return false;
		bound_member_variable var(mem_var, obj_ptr);
		return var.write(dst);
	}

	/// calculates the length of the name up to the next '::'
	TYCHO_GLASS_ABI int split_name(const char* start);

} // end namespace
} // end namespace
} // end namespace

#endif // __UTILS_H_CEF31E77_782B_413E_B0BF_E86A19FE4E34_
