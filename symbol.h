//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 22 December 2008 11:37:19 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __SYMBOL_H_8A9416BB_8F0C_4CC6_BD08_263A7B1482A5_
#define __SYMBOL_H_8A9416BB_8F0C_4CC6_BD08_263A7B1482A5_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/annotation.h"
#include "core/noncopyable.h"
#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// union of all possible operations, each thing that can be returned from scoped
	/// lookup implements a derived version of this that implements the functions it
	/// supports and allows the base version to return unsupported if it doesn't. This 
	/// allows all operations to operate generically and report errors in a consistent
	/// manner.
// 		virtual bool call_function()			{ return false; }
// 		virtual bool set_value()				{ return false; }
// 		virtual bool get_value()				{ return false; }
// 		virtual bool construct()				{ return false; }
// 		virtual bool destruct()					{ return false; }
// 		virtual bool dereference()				{ return false; }	
// 		virtual bool address_of()				{ return false; }
// 		virtual bool lookup_name(const char*)	{ return false; }



    class TYCHO_GLASS_ABI symbol : public core::noncopyable
    {
    public:
		enum type
		{
			t_invalid = 0,
			t_type,
			t_namespace,
			t_enum,
			t_constant,
			t_free_function,
			t_member_function,
			t_static_member_function,
			t_variable,
			t_member_variable
		};
		
		/// constructor
		symbol(type t, const std::string& name);

		/// destructor
		virtual ~symbol();
				
		/// \returns the type of this symbol
		type get_type() const 
			{ return m_type; }
			
		/// \returns true if the type is the same as the passed type
		bool is_type(type t) const
			{ return m_type == t; }
			
		/// \return the name of this symbol
		const std::string& get_name() const 
			{ return m_name; }
						
		/// add a child symbol. this object takes ownership over the passed pointer.
		/// \returns false if a symbol of the same name already exists
		bool add_child_symbol(symbol*);
		
		/// lookup a child symbol of this symbol
		const symbol* lookup_child_symbol(const char* name) const;

		/// lookup a child symbol of this symbol
		symbol* lookup_child_symbol(const char* name);

		/// \returns the number of child symbols this contains
		int get_num_child_symbols() const;

		/// \returns the i'th child symbol
		const symbol* get_child_symbol(int i) const;

	protected:
		/// name of the symbol
		std::string m_name;
		
		/// each symbol can have an arbitrary number of annotations attached to it. Some are defined
		/// by glass but others can be implemented by the user to attach arbitrary data to the symbol.
		std::vector<annotation*> m_annotations;
		
		/// each symbol can have an arbitrary number of child symbols as appropriate to the concrete symbol
		std::vector<symbol*> m_children;
		
    private: 
		/// type of the symbol   
		type m_type;
    };

} // end namespace
} // end namespace

#endif // __SYMBOL_H_8A9416BB_8F0C_4CC6_BD08_263A7B1482A5_
