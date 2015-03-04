//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:05:27 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FUNCTION_TYPE_H_2783ED13_D14E_4935_99D9_6D3B3615C82D_
#define __FUNCTION_TYPE_H_2783ED13_D14E_4935_99D9_6D3B3615C82D_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/base_type.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// Base of all function types.
    class TYCHO_GLASS_ABI function_type : public base_type
    {
    public:
		/// constructor
		function_type(const std::string& name, const base_type::type_t t) : base_type(name, t), m_return_type(0) {}    
		
		/// sets the return type for the function
		void set_return_type(const base_type* t)
			{ m_return_type = t; }
			
		/// \returns the return type of the function
		const base_type* get_return_type() const
			{ return m_return_type; }
		
		/// add a parameter to the function. These must be added in order from left to right
		void add_parameter(const base_type* t);
		
		/// \returns the number of arguments the parameters takes
		int get_num_parameter() const
			{ return m_parameters.size(); }

	private:		
		const base_type*  m_return_type;
		std::vector<const base_type*> m_parameters;
	};

} // end namespace
} // end namespace

#endif // __FUNCTION_TYPE_H_2783ED13_D14E_4935_99D9_6D3B3615C82D_
