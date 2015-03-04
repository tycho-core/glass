//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:03:40 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "class_type.h"
#include "core/string.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	//------------------------------------------------------------------------

	class_type::class_type(const char* name) : 
		base_type(name, base_type::t_class)
	{
	}
	
	//------------------------------------------------------------------------

	class_type::~class_type()
	{
	}

	//------------------------------------------------------------------------

	const member_variable* class_type::find_member_variable(const char* name) const
	{
		const symbol* s = lookup_child_symbol(name);
		if(s && s->is_type(symbol::t_member_variable))
			return core::debug_checked_cast<const member_variable*>(s);
		return 0;
	}

	//------------------------------------------------------------------------
		
	const member_function* class_type::find_member_function(const char* name) const
	{
		const symbol* s = lookup_child_symbol(name);
		if(s && s->is_type(symbol::t_member_function))
			return core::debug_checked_cast<const member_function*>(s);
		return 0;
	}

	//------------------------------------------------------------------------
		
} // end namespace
} // end namespace
