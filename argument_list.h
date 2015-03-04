//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:50:24 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __ARGUMENT_LIST_H_3F31A973_4157_45A5_BF39_E614BD4A298C_
#define __ARGUMENT_LIST_H_3F31A973_4157_45A5_BF39_E614BD4A298C_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/argument.h"
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// list of arguments for function calling
    class TYCHO_GLASS_ABI argument_list
    {
    public:
		/// push a new argument on to the list
		template<class T>
		void push(T& v)
		{
			const base_type* type = static_type_info<T>();
			argument arg(type, (void*)&v);
			m_arguments.push_back(arg);
		}
    
		/// \returns The number of arguments in the list
		int size() const 
			{ return m_arguments.size(); }
			
		/// \returns The i'th argument in the list
		const argument& get_argument(int i) const {
			TYCHO_ASSERT(i >= 0);
			TYCHO_ASSERT(i < size());
			return 	m_arguments[i];
		}
		
		static argument_list null_args;
		
    private:
		std::vector<argument> m_arguments;
    };

} // end namespace
} // end namespace

#endif // __ARGUMENT_LIST_H_3F31A973_4157_45A5_BF39_E614BD4A298C_
