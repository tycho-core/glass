//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 11:06:34 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "name.h"
#include "glass/utils.h"
#include "core/string.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{


    //--------------------------------------------------------------------

	name::name(const char* name) :
		m_name(name)
	{
	}

	//--------------------------------------------------------------------

	int name::get_num_parts() const
	{
		cache_parts();
		return (int)m_parts.size();
	}

	//--------------------------------------------------------------------

	bool name::get_part(int i, char* buf, int len) const
	{
		TYCHO_ASSERT(i < get_num_parts());
		cache_parts();
		const char* pname = m_parts[i].first;
		const int   plen  = m_parts[i].second;
		if(len-1 < plen)
			return false;
		core::strncpy(buf, pname, plen);
		buf[plen] = '\0';
		return true;
	}

    //--------------------------------------------------------------------

	const char* name::get_name() const
	{
		return m_name;
	}

    //--------------------------------------------------------------------

	bool name::get_name_as_path(char* buf, int buf_len) const
	{
		int num_parts = get_num_parts();
		for(int i = 0; i < num_parts; ++i)
		{
			const char* pname = m_parts[i].first;
			const int   plen  = m_parts[i].second;
			if(buf_len-1 < plen+1)
				return false;
			*buf++ = '/';
			core::strncpy(buf, pname, plen);
			buf += plen;
			buf_len -= plen + 1;
		}
		*buf = '\0';
		return true;
	}

    //--------------------------------------------------------------------

	bool name::operator==(const name& rhs) const
	{
		return core::strcmp(m_name, rhs.m_name) == 0;
	}
	
    //--------------------------------------------------------------------

	void name::cache_parts() const
	{
		if(m_parts.size() > 0)
			return;

		const char* start = m_name;
		while(*start != 0)
		{
			int length = utils::split_name(start);
			m_parts.push_back(std::make_pair(start, length));
			start = start + length;
			if(*start != 0)
				start += 2;
		}
	}

    //--------------------------------------------------------------------

} // end namespace
} // end namespace
