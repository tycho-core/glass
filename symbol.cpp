//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 22 December 2008 11:37:20 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "symbol.h"
#include "core/string.h"
#include <algorithm>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

    //--------------------------------------------------------------------

	symbol::symbol(type t, const std::string& name) :
		m_name(name),
		m_type(t)
	{
	}

    //--------------------------------------------------------------------

	symbol::~symbol()
	{
		for(size_t i = 0; i < m_children.size(); ++i)
		{
			delete m_children[i];
		}
		m_children.clear();
		m_annotations.clear();
	}

    //--------------------------------------------------------------------

	bool symbol::add_child_symbol(symbol* s)
	{
		if(lookup_child_symbol(s->get_name().c_str()))
			return false;
		m_children.push_back(s);
		return true;	
	}

    //--------------------------------------------------------------------

	const symbol* symbol::lookup_child_symbol(const char* name) const
	{ 
		std::vector<symbol*>::const_iterator it(m_children.begin());
		std::vector<symbol*>::const_iterator end(m_children.end());
		for(; it != end; ++it)
		{
			const symbol*s = *it;
			if(core::strcmp(s->get_name().c_str(), name) == 0)
			{
				return s;
			}
		}				
		return 0;
	}

    //--------------------------------------------------------------------

	symbol* symbol::lookup_child_symbol(const char* name)
	{ 
		return const_cast<symbol*>(const_cast<const symbol*>(this)->lookup_child_symbol(name));
	}

    //--------------------------------------------------------------------

	int symbol::get_num_child_symbols() const
	{
		return (int)m_children.size();
	}

    //--------------------------------------------------------------------

	const symbol* symbol::get_child_symbol(int i) const
	{
		TYCHO_ASSERT(i < get_num_child_symbols());
		return m_children[i];
	}

    //--------------------------------------------------------------------

} // end namespace
} // end namespace
