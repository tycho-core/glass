//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:06:14 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "member_function_type.h"
#include "glass/detail/member_function_thunk.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	//--------------------------------------------------------------------

	member_function_type::~member_function_type()
	{
		m_class_type = 0;
		core::safe_delete(m_thunk);	
	}

	//--------------------------------------------------------------------

} // end namespace
} // end namespace
