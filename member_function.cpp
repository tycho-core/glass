//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 11:13:54 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "member_function.h"
#include "member_function_type.h"
#include "detail/member_function_thunk.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	//--------------------------------------------------------------------

	member_function::~member_function()
	{
		m_obj_type = 0;
		core::safe_delete(m_type);
	}

	//--------------------------------------------------------------------

	bool member_function::call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		if(!obj_ptr || !m_type)
			return false;
		m_type->get_call_thunk()->call(obj_ptr, args, result);
		return true;	
	}

	//--------------------------------------------------------------------

} // end namespace
} // end namespace
