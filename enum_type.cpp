//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:03:43 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "enum_type.h"
#include "core/string.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

    //--------------------------------------------------------------------
    
	enum_type::enum_type(const std::string& name) :
		base_type(name, base_type::t_enum)
	{}

	//--------------------------------------------------------------------
	
	enum_type::~enum_type()
	{}
	
	//--------------------------------------------------------------------

	void enum_type::add_member(const char* name, core::int32 value)
	{
		m_entries.push_back(entry(name, value));
	}
	
	//--------------------------------------------------------------------

	bool enum_type::find(const char* name, core::int32& value) const
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
	
	bool enum_type::find(core::int32 value, const char*& name) const
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
