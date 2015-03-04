//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:06:14 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MEMBER_FUNCTION_TYPE_H_1604A16B_7C15_473F_8F89_5B536A833256_
#define __MEMBER_FUNCTION_TYPE_H_1604A16B_7C15_473F_8F89_5B536A833256_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/function_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

    class TYCHO_GLASS_ABI member_function_type : public function_type
    {
    public:
		enum flags
		{
			f_invalid = 0,
			f_none = 1,
			f_virtual = 2
		};
		
    public:
		/// constructor
		member_function_type(const std::string& name, int flags) : 
			function_type(name, base_type::t_member_function),
            m_flags(flags),
            m_thunk(0)
        {}
			
		/// destructor
		~member_function_type();
			
		void set_class_type(const class_type* t) 
			{ m_class_type = t; }

		/// \returns The type of the class this member function is in.
		const class_type* get_class_type() const
			{ return  m_class_type; }

		/// Set the call thunk, objec takes ownership of the pointer
		void set_call_thunk(detail::member_function_thunk_base* thunk)
			{ m_thunk = thunk; }
			
		/// \returns The call thunk object used to execute a call
		const detail::member_function_thunk_base* get_call_thunk() const
			{ return m_thunk; }
				
		/// \returns True if this is a virtual function
		bool is_virtual() const 
			{ return (m_flags & f_virtual) > 0; }
			
	private:		
		int									m_flags;
		const class_type*					m_class_type;
		detail::member_function_thunk_base* m_thunk;
    };

} // end namespace
} // end namespace

#endif // __MEMBER_FUNCTION_TYPE_H_1604A16B_7C15_473F_8F89_5B536A833256_

