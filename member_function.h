//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 11:13:54 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MEMBER_FUNCTION_H_595E6DB6_5A98_48AD_A9E3_B0577A078A87_
#define __MEMBER_FUNCTION_H_595E6DB6_5A98_48AD_A9E3_B0577A078A87_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/member_function_type.h"
#include "glass/symbol.h"
#include "glass/class_type.h"
#include "glass/base_type.h"
#include "glass/detail/make_member_function_type.h"
#include "core/cast.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
		
	/// class member function that is bound to an object
    class TYCHO_GLASS_ABI member_function : public symbol
    {
    public:
		/// constructor
		member_function(const char* name, const member_function_type* type) :
			symbol(t_member_function, name),
			m_type(type)
		{}
		
		/// constructor
		template<class F> 
		member_function(const char* name, F func) :
			symbol(t_member_function, name)
		{
			m_type = detail::make_member_function_type(func);
			m_obj_type = m_type->get_class_type();
		}
		
		/// destructor
		~member_function();
		
		/// \returns the type of the member function
		const member_function_type* get_type() const { return m_type; }
		
		/// call the function
		bool call(void* obj_ptr, const argument_list& args, const argument& result) const;
		
    private:
		const class_type*			m_obj_type;
		const member_function_type*	m_type;
    };

} // end namespace
} // end namespace

#endif // __MEMBER_FUNCTION_H_595E6DB6_5A98_48AD_A9E3_B0577A078A87_
