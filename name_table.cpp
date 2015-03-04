//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Thursday, 1 October 2009 9:45:09 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "name_table.h"
#include "core/hash.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

    //--------------------------------------------------------------------

	bool name_table::add_name(const char* str, void* obj)
	{
		return m_names.insert(std::make_pair(str, obj)).second;
	}

    //--------------------------------------------------------------------

	void* name_table::find_name(const char* str) const
	{
		name_map::const_iterator it = m_names.find(str);
		if(it == m_names.end())
			return 0;
		return it->second;
	}

    //--------------------------------------------------------------------

	bool name_table::remove_name(const char* str)
	{
		name_map::iterator it = m_names.find(str);
		if(it == m_names.end())
			return false;
		m_names.erase(it);
		return true;
	}

    //--------------------------------------------------------------------


} // end namespace
} // end namespace
