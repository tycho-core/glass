//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:11:02 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "base_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	//------------------------------------------------------------------------
	
	base_type::base_type(const std::string& name, const type_t t) :
		symbol(t_type, name),
		m_access(0),
        m_size(0),
		m_type(t)
	{
	}
	
	//------------------------------------------------------------------------

	base_type::~base_type()
	{
		m_size = 0;
		core::safe_delete(m_access);
	}

	//------------------------------------------------------------------------

	void base_type::set_size(int size) 
	{ 
		m_size = size; 
	}	   	  												

	//------------------------------------------------------------------------

	int base_type::get_size() const 
	{ 
		return m_size; 
	}												

	//------------------------------------------------------------------------

	bool base_type::construct(void* ptr) const
	{
		if(!m_access || !ptr)
			return false;	
		m_access->construct(ptr);
		return true;
	}
	
	//------------------------------------------------------------------------

	bool base_type::destruct(void* ptr) const
	{
		if(!m_access || !ptr)
			return false;	
		m_access->destruct(ptr);
		return true;	
	}

} // end namespace
} // end namespace
