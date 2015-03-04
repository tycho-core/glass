//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 11:29:33 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __BOUND_MEMBER_FUNCTION_H_2A5E6A27_20A6_4312_81C0_160E75BB4A1E_
#define __BOUND_MEMBER_FUNCTION_H_2A5E6A27_20A6_4312_81C0_160E75BB4A1E_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/member_function.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

    class TYCHO_GLASS_ABI bound_member_function
    {
    public:
		/// constructor 
		bound_member_function(const member_function* mem_fun, void* obj_ptr) :
			m_mem_fun(mem_fun),
			m_obj_ptr(obj_ptr)
		{}
		
		/// default constructor
		bound_member_function() :
			m_mem_fun(0),
			m_obj_ptr(0)
		{}
		
		/// destructor
		~bound_member_function()
		{
			m_mem_fun = 0;
			m_obj_ptr = 0;
		}
			
		/// \returns call a function that takes no arguments or returns a value.
		bool call();		
		    
    private:
		const member_function* m_mem_fun;
		void*				   m_obj_ptr;
    };

} // end namespace
} // end namespace

#endif // __BOUND_MEMBER_FUNCTION_H_2A5E6A27_20A6_4312_81C0_160E75BB4A1E_
