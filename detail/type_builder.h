//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 14 December 2008 3:09:11 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __TYPE_BUILDER_H_7E77DB6A_3785_4E76_98E8_F61EA0CB8D19_
#define __TYPE_BUILDER_H_7E77DB6A_3785_4E76_98E8_F61EA0CB8D19_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include <stack>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
namespace detail
{

	/// used internally when constructing type_info's for exported types.
    class TYCHO_GLASS_ABI type_builder
    {
    public:
		/// constructor 
		type_builder();
		
		/// destructor
		~type_builder();
		
		/// push a new namespace on the stack, if a namespace already exists then it is opened.
		bool push_namespace(const char* name);
		
		/// adds the symbol to the current topmost scope and pushes the new on to the stack		
		/// \returns false if a symbol already exists of that name
		bool push_symbol(symbol*);
		
		/// add a symbol to the top most scope
		bool add_symbol(symbol*);
		
		/// close the top most scope
		bool pop();
						
    private:
		std::stack<symbol*> m_scope_stack;
    };

} // end namespace
} // end namespace
} // end namespace

#endif // __TYPE_BUILDER_H_7E77DB6A_3785_4E76_98E8_F61EA0CB8D19_
