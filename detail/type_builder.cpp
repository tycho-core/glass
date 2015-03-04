//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 14 December 2008 3:09:11 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "type_builder.h"
#include "glass/glass.h"
#include "glass/name_space.h"
#include "glass/symbol.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{
namespace detail
{

    //--------------------------------------------------------------------

	type_builder::type_builder()
	{
		// push the global namespace on the scope stack as the root.
		m_scope_stack.push(glass::get_global_namespace());
	}

    //--------------------------------------------------------------------
	
	type_builder::~type_builder()
	{
		// only global scope should be left on the stack
		TYCHO_ASSERT(m_scope_stack.size() == 1);
	}

    //--------------------------------------------------------------------

	bool type_builder::push_namespace(const char* name)
	{
		// check to see if namespace is already registered
		symbol* s = m_scope_stack.top()->lookup_child_symbol(name);
		if(!s)
		{
			// nope so create one, add to current symbol and push onto the stack
			name_space* ns = new name_space(name);
			m_scope_stack.top()->add_child_symbol(ns);
			m_scope_stack.push(ns);									
		}
		else
		{
			// reopen the existing namespace
			if(!s->is_type(symbol::t_namespace))
				return false;
			m_scope_stack.push(s);
		}
		return true;
	}

    //--------------------------------------------------------------------

	bool type_builder::push_symbol(symbol* s)
	{
		if(m_scope_stack.top()->add_child_symbol(s))
		{
			m_scope_stack.push(s);
			return true;
		}
		return false;
	}
		
    //--------------------------------------------------------------------

	bool type_builder::add_symbol(symbol* s)
	{
		return m_scope_stack.top()->add_child_symbol(s);	
	}
		
    //--------------------------------------------------------------------

	bool type_builder::pop()
	{
		if(m_scope_stack.size() == 0)
			return false;
		m_scope_stack.pop();
		return true;
	}

    //--------------------------------------------------------------------

} // end namespace
} // end namespace
} // end namespace
