//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 11:23:52 PM
// Helper macros to expose C++ symbols to glass.
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MACRO_INTERFACE_H_5433767B_EE90_40F8_A869_B3959E92E522_
#define __MACRO_INTERFACE_H_5433767B_EE90_40F8_A869_B3959E92E522_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/type_info.h"
#include "glass/class_type.h"
#include "glass/enum_type.h"
#include "glass/bitfield_type.h"
#include "glass/pointer_type.h"
#include "glass/reference_type.h"
#include "glass/static_type_info.h"
#include "glass/detail/utilities.h"
#include "glass/detail/type_builder.h"
#include <stack>

//////////////////////////////////////////////////////////////////////////////
// DEFINES
//////////////////////////////////////////////////////////////////////////////

/// Must come before any definitions
#define TYCHO_GLASS_REGISTER_BEGIN() { \
	tycho::glass::detail::type_builder bld;
	
/// Must come before after any definitions
#define TYCHO_GLASS_REGISTER_END() }

//////////////////////////////////////////////////////////////////////////////
// NAMESPACE DEFINES
//////////////////////////////////////////////////////////////////////////////

#define TYCHO_GLASS_BEGIN_NAMESPACE(_name) { \
	using namespace _name; \
	bld.push_namespace(#_name);

#define TYCHO_GLASS_END_NAMESPACE() bld.pop(); }

//////////////////////////////////////////////////////////////////////////////
// C++ to Glass type helpers
//////////////////////////////////////////////////////////////////////////////

/// helper function
#define TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX0(_abi, _t, _glass_type) \
    namespace tycho { namespace glass { \
	template<> struct _abi  type_info<_t> { \
		static _glass_type* get_type_info() { \
			TYCHO_ASSERT(!init); \
			return type; \
		} \
		static void set_type_info(_glass_type* t) { \
			TYCHO_ASSERT(init); \
			type = t; \
			type->set_size(size); \
			init = false; \
		} \
		static const int size = sizeof(_t); \
		static _glass_type* type; \
		static bool init; \
	}; }}
	
/// helper function
#define TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX(_abi, _t, _glass_type) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX0(_abi, _t, _glass_type) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX0(_abi, _t*, tycho::glass::pointer_type) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX0(_abi, _t&, tycho::glass::reference_type)
	

/// helper function 
#define TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX0(_abi, _t, _glass_type) \
	_abi _glass_type* tycho::glass::type_info<_t>::type; \
	_abi bool tycho::glass::type_info<_t>::init = true;

#define TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX(_abi, _t, _glass_type) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX0(_abi, _t, _glass_type) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX0(_abi, _t*, tycho::glass::pointer_type) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX0(_abi, _t&, tycho::glass::reference_type)
				
				
//////////////////////////////////////////////////////////////////////////////
// Classes
//////////////////////////////////////////////////////////////////////////////
				
/// per class type_info instantiation, must be declared in a header file that is included by all types that use this type.
#define TYCHO_GLASS_INSTANTIATE_CLASS_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX(_abi, _name, tycho::glass::class_type) 

/// per class type_info implementation, must be declared in a single cpp file.
#define TYCHO_GLASS_IMPLEMENT_CLASS_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX(_abi, _name, tycho::glass::class_type) 	
	
///	begin a class definition
#define TYCHO_GLASS_DEF_CLASS(_name) { \
	typedef _name this_type; \
	tycho::glass::class_type* ct = new tycho::glass::class_type(#_name); \
	tycho::glass::type_info<this_type>::set_type_info(ct); \
	ct->set_access<_name>(); \
	bld.push_symbol(ct); \
	TYCHO_GLASS_DEF_POINTER(_name)
	
/// end a class definition
#define TYCHO_GLASS_DEF_CLASS_END() \
	bld.pop();	}

/// define a base class
#define  TYCHO_GLASS_DEF_CLASS_BASE_CLASS(_c)

/// define a binary operator
#define TYCHO_GLASS_DEF_CLASS_BINARY_OP()

/// define a unary operator
#define TYCHO_GLASS_DEF_CLASS_UNARY_OP()

/// define a class member variable
#define TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(_var) \
	bld.add_symbol(new tycho::glass::member_variable(#_var, &this_type::_var));

/// define a class static member variable
#define TYCHO_GLASS_DEF_CLASS_STATIC_MEMBER

/// define a class constructor
#define TYCHO_GLASS_DEF_CLASS_CONSTRUCTOR()

/// helper for class member function creation
#define TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION_AUX(_func, _flags) { \
	const tycho::glass::member_function_type* type = \
	tycho::glass::detail::make_member_function_type(&this_type::_func, _flags);	\
	bld.add_symbol(new tycho::glass::member_function(#_func, type)); \
	}

/// define a class member function
#define TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(_func) \
	TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION_AUX(_func, tycho::glass::member_function_type::f_none)
	
/// define a class virtual member function
#define TYCHO_GLASS_DEF_CLASS_VIRTUAL_FUNCTION(_func) \
	TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION_AUX(_func, tycho::glass::member_function_type::f_virtual)

/// define a class static member function
#define TYCHO_GLASS_DEF_CLASS_STATIC_MEMBER_FUNCTION

//////////////////////////////////////////////////////////////////////////////
// ENUM DEFINES
//////////////////////////////////////////////////////////////////////////////

/// begin an enum definition
#define TYCHO_GLASS_DEF_ENUM(_name) { \
	typedef _name this_type; \
	tycho::glass::enum_type* nt = new tycho::glass::enum_type(#_name); \
	bld.add_symbol(nt); \
	tycho::glass::type_info<this_type>::set_type_info(nt); \
	nt->set_access<_name>(); \
	TYCHO_GLASS_DEF_POINTER(_name)

/// end an enum definition
#define TYCHO_GLASS_DEF_ENUM_END() \
	} 

/// add a member to an enum definition
#define TYCHO_GLASS_DEF_ENUM_MEMBER(_name) nt->add_member(#_name, _name);

/// per enum type_info instantiation, must be declared in a header file that is included by all types that use this type.
#define TYCHO_GLASS_INSTANTIATE_ENUM_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX(_abi, _name, tycho::glass::enum_type) 

/// per enum type_info implementation, must be declared in a single cpp file.
#define TYCHO_GLASS_IMPLEMENT_ENUM_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX(_abi, _name, tycho::glass::enum_type) 	

//////////////////////////////////////////////////////////////////////////////
// BITFIELD DEFINES
//////////////////////////////////////////////////////////////////////////////

/// begin an bitfield definition
#define TYCHO_GLASS_DEF_BITFIELD(_name) { \
	typedef _name this_type; \
	tycho::glass::bitfield_type* nt = new tycho::glass::bitfield_type(#_name); \
	bld.add_symbol(nt); \
	tycho::glass::type_info<this_type>::set_type_info(nt); \
	nt->set_access<_name>(); \
	TYCHO_GLASS_DEF_POINTER(_name)

/// end an bitfield definition
#define TYCHO_GLASS_DEF_BITFIELD_END() \
	} 

/// add a member to an bitfield definition
#define TYCHO_GLASS_DEF_BITFIELD_MEMBER(_name) nt->add_member(#_name, _name);

/// per bitfield type_info instantiation, must be declared in a header file that is included by all types that use this type.
#define TYCHO_GLASS_INSTANTIATE_BITFIELD_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_INSTANTIATE_TYPE_INFO_AUX(_abi, _name, tycho::glass::bitfield_type) 

/// per bitfield type_info implementation, must be declared in a single cpp file.
#define TYCHO_GLASS_IMPLEMENT_BITFIELD_TYPE_INFO(_abi, _name) \
	TYCHO_GLASS_IMPLEMENT_TYPE_INFO_AUX(_abi, _name, tycho::glass::bitfield_type) 	

//////////////////////////////////////////////////////////////////////////////
// POINTER DEFINES
//////////////////////////////////////////////////////////////////////////////

/// pointer definition
#define TYCHO_GLASS_DEF_POINTER0(_name, _sym) { \
	tycho::glass::pointer_type* nt = new tycho::glass::pointer_type(#_name #_sym); \
	tycho::glass::type_info<_name*>::set_type_info(nt); \
	nt->set_access<_name*>(); \
	nt->set_pointee_type(tycho::glass::static_type_info<_name>()); \
	bld.add_symbol(nt); }

#define TYCHO_GLASS_DEF_REFERENCE(_name, _sym) { \
	tycho::glass::reference_type* nt = new tycho::glass::reference_type(#_name #_sym); \
	tycho::glass::type_info<_name&>::set_type_info(nt); \
	nt->set_pointee_type(tycho::glass::static_type_info<_name>()); \
	bld.add_symbol(nt); }

/// pointer definition
#define TYCHO_GLASS_DEF_POINTER(_name) \
	TYCHO_GLASS_DEF_POINTER0(_name, *) \
	TYCHO_GLASS_DEF_REFERENCE(_name, &)
	
//////////////////////////////////////////////////////////////////////////////
// FREE DEFINES
//////////////////////////////////////////////////////////////////////////////
#define TYCHO_GLASS_FREE_FUNCTION
#define TYCHO_GLASS_FREE_VARIABLE




#endif // __MACRO_INTERFACE_H_5433767B_EE90_40F8_A869_B3959E92E522_
