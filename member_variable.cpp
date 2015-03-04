//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 3:06:25 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "member_variable.h"
#include "core/memory.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	//------------------------------------------------------------------------
	
	member_variable::member_variable(const char* name, const base_type *type) :
		symbol(t_member_variable, name),
		m_type(type)
	{}

	//------------------------------------------------------------------------

	member_variable::~member_variable()
	{
        m_type = nullptr;
		core::safe_delete(m_access);
	}

	//------------------------------------------------------------------------

	bool member_variable::read(void* obj_ptr, void* dst_ptr) const
	{
		if(!m_access || !obj_ptr || !dst_ptr)
			return false;		
		m_access->read(obj_ptr, dst_ptr);
		return true;
	}

	//------------------------------------------------------------------------

	bool member_variable::write(void* obj_ptr, void* src_ptr) const
	{
		if(!m_access || !obj_ptr || !src_ptr)
			return false;
		m_access->write(obj_ptr, src_ptr);
		return true;	
	}

	//------------------------------------------------------------------------

	const void* member_variable::get_raw_ptr(const void* obj_ptr) const
	{
		if(!m_access || !obj_ptr)
            return nullptr;
		return m_access->get_raw_ptr(obj_ptr);
	}

	//------------------------------------------------------------------------

} // end namespace
} // end namespace
