//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:11:02 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __BASE_TYPE_H_E81F591E_25F5_4903_A57E_0508573BE110_
#define __BASE_TYPE_H_E81F591E_25F5_4903_A57E_0508573BE110_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/symbol.h"
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// base of all glass types, all types are named symbols
    class TYCHO_GLASS_ABI base_type : public symbol
    {
    public:
		enum type_t
		{
			t_int8,
			t_uint8,
			t_int16,
			t_uint16,
			t_int32,
			t_uint32,
			t_int64,
			t_uint64,
			t_float32,
			t_float64,
			t_string,
			t_class,
			t_union,
			t_enum,
			t_bitfield,
			t_function,
			t_member_function,
			t_free_function,
			t_pointer
		};

	public:
		/// constructor
		base_type(const std::string& name, const type_t t);
		
		/// destructor
		virtual ~base_type();

		/// \returns the type of this type, poor man rtti.
		type_t get_type_t() const
			{ return m_type; }	
		
		/// set the size of the type in bytes
		void set_size(int size);
		
		/// \returns the size of the type in bytes
		int get_size() const;
												
		/// default construct an object
		bool construct(void*) const;
		
		/// destruct an object
		bool destruct(void*) const;	
						
		/// setup object access 
		template<class T> void set_access()
		{
			if(m_access)
				delete m_access;
			m_access = new access<T>();
		}

		/// \returns true if the type is bitwise copyable
		bool is_bitwise_copyable() const
			{ return false; }
			
		/// \returns true if the type is copy constructible
		bool is_copy_constructible() const
			{ return false; }
			
		/// \returns true if the type is default constructible
		bool is_default_constructible() const
			{ return false; }
			
	private:
		struct access_base
		{
			virtual ~access_base() {}
			virtual void construct(void*) = 0;
			virtual void destruct(void*) = 0;
		};
		
		template<class T>
		struct access : access_base
		{
			virtual void construct(void* ptr)
			{
				new(ptr) T;
			}

			virtual void destruct(void* ptr)
			{
				// VC++2005 is very good and optimises out this destructor call if the type doesn't need it, but
				// then generates a warning that the ptr param isn't used, which is annoying so we reference it here
				// to avoid that.
#if TYCHO_PC
				ptr;
#endif
				((T*)ptr)->~T();
			}						
		};		
						
    private:
		access_base *m_access;	
		int m_size;
		type_t m_type;
    };

} // end namespace
} // end namespace

#endif // __BASE_TYPE_H_E81F591E_25F5_4903_A57E_0508573BE110_
