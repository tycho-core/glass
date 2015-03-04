//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 12 January 2009 1:02:25 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __RUNTIME_H_EBCF9992_6C4D_48C0_9477_8FCB692520FF_
#define __RUNTIME_H_EBCF9992_6C4D_48C0_9477_8FCB692520FF_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/argument.h"
#include <map>
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// Runtime management system.
    class TYCHO_GLASS_ABI runtime
    {
    public:    
		void register_named_object(const char* name, const base_type* type, void* ptr);			
		void unregister_named_object(const char* name);
		glass::argument* find_named_object(const char* name);
		glass::argument* find_named_object(const void* ptr);
    
    private:
		typedef std::map<std::string, glass::argument> named_object_map;
		
		/// objects that can be looked up by name
		named_object_map m_named_objects;		
    };

} // end namespace
} // end namespace

#endif // __RUNTIME_H_EBCF9992_6C4D_48C0_9477_8FCB692520FF_
