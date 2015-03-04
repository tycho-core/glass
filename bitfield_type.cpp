//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Wednesday, 10 December 2008 11:50:07 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "bitfield_type.h"
#include "core/string.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

    //--------------------------------------------------------------------

	bitfield_type::bitfield_type(const std::string& name) :
		base_type(name, base_type::t_bitfield)
	{}

	//--------------------------------------------------------------------

	void bitfield_type::add_member(const char* name, core::int32 value)
	{
		m_entries.push_back(entry(name, value));
	}
	
	//--------------------------------------------------------------------

	bool bitfield_type::find(const char* name, core::int32& value) const
	{
		entry_list::const_iterator it(m_entries.begin());
		entry_list::const_iterator end(m_entries.end());
		for(; it != end; ++it)
		{
			const entry& e = *it;
			if(core::strcmp(e.name, name) == 0)
			{
				value = e.value;
				return true;
			}
		}				
		return false;
	}

	//--------------------------------------------------------------------
	
	bool bitfield_type::find(core::int32 value, const char*& name) const
	{
		entry_list::const_iterator it(m_entries.begin());
		entry_list::const_iterator end(m_entries.end());
		for(; it != end; ++it)
		{
			const entry& e = *it;
			if(e.value == value)
			{
				name = e.name;
				return true;
			}
		}				
		return false;
	}

	//--------------------------------------------------------------------

} // end namespace
} // end namespace
