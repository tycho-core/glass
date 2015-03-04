//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 October 2009 9:45:09 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __NAME_TABLE_H_FF6FFA1F_2109_470E_A106_4CF472CD757C_
#define __NAME_TABLE_H_FF6FFA1F_2109_470E_A106_4CF472CD757C_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "core/noncopyable.h"
#include "core/containers/hash_table.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// Runtime store of names to object mappings, offers fast object to name lookup.
	class TYCHO_GLASS_ABI name_table : core::noncopyable
    {
    public:
		/// add a new name to the name table. must be in '::' delimited form. 
		/// i.e. foo::bar::var
		bool add_name(const char* str, void* obj);

		/// find an object by name
		void* find_name(const char* str) const;

		/// remove object from name table
		bool remove_name(const char* str);

	private:
		typedef core::hash_table<const char*, void*, 512, core::compare_cstr> name_map;
		name_map m_names;
    };

} // end namespace
} // end namespace

#endif // __NAME_TABLE_H_FF6FFA1F_2109_470E_A106_4CF472CD757C_
