//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 3:27:21 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __GLASS_H_558FE7FB_A54B_4A37_8EDA_959A90A103C8_
#define __GLASS_H_558FE7FB_A54B_4A37_8EDA_959A90A103C8_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/bound_member_variable.h"
#include "glass/class_type.h"
#include "glass/name.h"
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
	///////////////////////////////////////////////////////////////////////////////////////				
	// Constants
	///////////////////////////////////////////////////////////////////////////////////////
	
	/// Maximum number of parameters function can take. To modify change here and in code_gen.py.
	const int MaxArity = 6; 

	/// Maximum length of an object name
	const int MaxNameLength = 256;

	///////////////////////////////////////////////////////////////////////////////////////				
	// System management
	///////////////////////////////////////////////////////////////////////////////////////
	
	/// Initialise the glass system
	TYCHO_GLASS_ABI bool initialise();
		
	/// Shutdown the glass system
	TYCHO_GLASS_ABI bool shutdown();
	
	///////////////////////////////////////////////////////////////////////////////////////				
	// Names
	///////////////////////////////////////////////////////////////////////////////////////

	/// make a new default name using the passed prefix
	TYCHO_GLASS_ABI std::string make_default_name(const char* prefix);

	///////////////////////////////////////////////////////////////////////////////////////				
	// Querying
	///////////////////////////////////////////////////////////////////////////////////////

	/// \returns the global namespace
	TYCHO_GLASS_ABI name_space* get_global_namespace();
	
	/// Find a type by fully qualified name
	TYCHO_GLASS_ABI const base_type* find_type(const char* name);
	
	/// Find a symbol by its fully qualified name
	TYCHO_GLASS_ABI const symbol* find_symbol(const char* name);

	/// Find an object by fully qualified name
	TYCHO_GLASS_ABI void* find_object(const char* name);

	///////////////////////////////////////////////////////////////////////////////////////				
	// Creation
	///////////////////////////////////////////////////////////////////////////////////////
	
	/// construct a new default named object
	TYCHO_GLASS_ABI void* create_new_object(const base_type*);

	/// construct a new named object
	TYCHO_GLASS_ABI void* create_new_object(const base_type*, const char* name);

	/// construct a new default named object by class name
	TYCHO_GLASS_ABI void* create_new_object(const char* class_name);

	/// construct a new named object by class name
	TYCHO_GLASS_ABI void* create_new_object(const char* class_name, const char* name);

	/// destruct an object, doesn't deallocate its memory so is ready for a construct_in_place.
	TYCHO_GLASS_ABI void destruct_object(const base_type*, void* mem);
	
	/// delete an object, this destructs the object and frees its memory
	TYCHO_GLASS_ABI void delete_object(const base_type*, void* mem);

	/// free an objects memory.
	/// \warning  this does not destruct the object so destruct_object must be called before calling this.
	TYCHO_GLASS_ABI void free_object(const base_type*, void* mem);
	
	/// construct a default named object in a previously allocated piece of memory
	TYCHO_GLASS_ABI void construct_in_place(const base_type*, void* mem);


	///////////////////////////////////////////////////////////////////////////////////////				
	// Value mutation
	///////////////////////////////////////////////////////////////////////////////////////
			
	/// get a object member value
	TYCHO_GLASS_ABI any_value read_value(const class_type*, void* obj_ptr, const char* name);

	/// set a object member value
	TYCHO_GLASS_ABI bool write_value(const class_type*, void* obj_ptr, const char* name, const any_value&);

	/// get a value from the global table
	TYCHO_GLASS_ABI any_value get_free_value(const char* name);

	/// set a value in the global table
	TYCHO_GLASS_ABI bool set_free_value(const char* name, const any_value&);

	
	///////////////////////////////////////////////////////////////////////////////////////				
	// Function calling
	///////////////////////////////////////////////////////////////////////////////////////
		
	/// call a free function with no arguments.
	TYCHO_GLASS_ABI bool call_function(const char* name);
	
	/// call a free function with arguments
	TYCHO_GLASS_ABI bool call_function(const char* name, const argument_list& arguments);
	
	/// call a member function with no arguments.
	TYCHO_GLASS_ABI bool call_function(const class_type*, void* object, const char* name);
	
	/// call a free function with arguments
	TYCHO_GLASS_ABI bool call_function(const class_type*, void* object, const char* name, const argument_list& arguments);

	/// call a free function with no arguments.
	TYCHO_GLASS_ABI bool call_function(const char* name, const argument& result);
	
	/// call a free function with arguments
	TYCHO_GLASS_ABI bool call_function(const char* name, const argument_list& arguments, const argument& result);
	
	/// call a member function with no arguments.
	TYCHO_GLASS_ABI bool call_function(const class_type*, void* object, const char* name, const argument& result);
	
	/// call a free function with arguments
	TYCHO_GLASS_ABI bool call_function(const class_type*, void* object, const char* name, const argument_list& arguments, const argument& result);
	
	///////////////////////////////////////////////////////////////////////////////////////				
	// Object information
	///////////////////////////////////////////////////////////////////////////////////////

	/// \returns the name of the object.
	/// \warning the passed obj pointer *must* point to an object allocated with one of the
	/// glass::create_new_object functions.
	TYCHO_GLASS_ABI name get_object_name(const void* obj);

	/// \returns the type_info for the passed object.
	/// \warning the passed obj pointer *must* point to an object allocated with one of the
	/// glass::create_new_object functions.
	TYCHO_GLASS_ABI const base_type* get_object_type(const void* obj);

} // end namespace
} // end namespace

#endif // __GLASS_H_558FE7FB_A54B_4A37_8EDA_959A90A103C8_
