//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 8:58:44 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __BOUND_MEMBER_VARIABLE_H_F48C0CD5_1119_4FE8_9FA9_12044D0748FB_
#define __BOUND_MEMBER_VARIABLE_H_F48C0CD5_1119_4FE8_9FA9_12044D0748FB_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/static_type_info.h"
#include "glass/member_variable.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// Member_variable need to be bound to an object before they can be modified
	/// or retrieved.
    class TYCHO_GLASS_ABI bound_member_variable
    {
    public:
		/// constructor 
		bound_member_variable(const member_variable* mem_var, void* obj_ptr) :
			m_mem_var(mem_var),
			m_obj_ptr(obj_ptr)
		{}
		
		/// default constructor
		bound_member_variable() :
			m_mem_var(0),
			m_obj_ptr(0)
		{}
		
		/// destructor
		~bound_member_variable()
		{
			m_mem_var = 0;
			m_obj_ptr = 0;
		}
			
		/// \returns the value of the variable
		template<class T> bool read(T& dst)
		{
			TYCHO_ASSERT_MSG(static_type_info<T>() == m_mem_var->get_type(), "The type you are reading to does not match the type being read from.");
			return m_mem_var->read(m_obj_ptr, (void*)&dst);
		}

		/// \returns the value of the variable
		template<class T> bool write(const T& src)
		{
			TYCHO_ASSERT_MSG(static_type_info<T>() == m_mem_var->get_type(), "The type you are writing to does not match the type being read from.");
			return m_mem_var->write(m_obj_ptr, (void*)&src);
		}
		
		    
    private:
		const member_variable* m_mem_var;
		void*				   m_obj_ptr;
    };

} // end namespace
} // end namespace

#endif // __BOUND_MEMBER_VARIABLE_H_F48C0CD5_1119_4FE8_9FA9_12044D0748FB_
