//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 9 December 2008 4:25:10 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __ARGUMENT_H_3D2356D3_CB55_4B93_B483_83C942C9A61C_
#define __ARGUMENT_H_3D2356D3_CB55_4B93_B483_83C942C9A61C_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/static_type_info.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// single argument to be passed to a function
	class TYCHO_GLASS_ABI argument
	{
	public:
		/// constructor.
		argument(const base_type* type, void* ptr) :
			m_type(type),
			m_ptr(ptr)
		{}
		
		/// constructor
		template<class T>
		argument(T& v)
		{
			m_type = static_type_info<T>();
			m_ptr = (void*)&v;
		}

		
		/// default constructor
		argument() :
			m_type(0),
			m_ptr(0)
		{}
		
		/// copy constructor
		argument(const argument& arg) :
			m_type(arg.m_type),
			m_ptr(arg.m_ptr)
		{}
		
		/// destructor
		~argument()
		{
			m_type = 0;
			m_ptr = 0;
		}
		
		/// get the type of the argument
		const base_type* get_type() const
			{ return m_type; }
		
		/// get the pointer to its memory location
		void* get_ptr() const
			{ return m_ptr; }		
		
	private:
		const base_type*	m_type;
		void*				m_ptr;
	};
	
} // end namespace
} // end namespace

#endif // __ARGUMENT_H_3D2356D3_CB55_4B93_B483_83C942C9A61C_
