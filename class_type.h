//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:03:40 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __CLASS_TYPE_H_A15C8893_BD21_4ACA_B34F_A9E60842A9AA_
#define __CLASS_TYPE_H_A15C8893_BD21_4ACA_B34F_A9E60842A9AA_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/base_type.h"
#include "glass/symbol.h"
#include "glass/member_variable.h"
#include "glass/member_function.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// C++ class type, all structures are handled as classes as well.
    class TYCHO_GLASS_ABI class_type : 
		public base_type
    {	
	public:			
		/// constructor 
		class_type(const char* name);	

		/// destructor
		~class_type();
		
		/// find a member variable by name
		const member_variable* find_member_variable(const char* name) const;
		
		/// find a member function
		const member_function* find_member_function(const char*name) const;
		
	private:
		//TODO : need to store per base class functors that cast to that base as 
		//       their base pointer may be different.
		std::vector<const class_type*>	m_base_classes;
    };

} // end namespace
} // end namespace

#endif // __CLASS_TYPE_H_A15C8893_BD21_4ACA_B34F_A9E60842A9AA_
