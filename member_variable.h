//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 3:06:24 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __MEMBER_VARIABLE_H_28FFD056_37AD_46A5_B836_74C4168C80E6_
#define __MEMBER_VARIABLE_H_28FFD056_37AD_46A5_B836_74C4168C80E6_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/any_value.h"
#include "glass/symbol.h"
#include "glass/static_type_info.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// class or struct member variable description
    class TYCHO_GLASS_ABI member_variable : 
		public symbol
    {
    public:
		struct member_access_base
		{
			virtual ~member_access_base() {}
			virtual member_access_base* clone() const = 0;
			virtual void read(void* obj_ptr, void* dst_ptr) const = 0;
			virtual void write(void* obj_ptr, void* src_ptr) const = 0;
			virtual const void* get_raw_ptr(const void* obj_ptr) const = 0;
		};
		
		template<class T, class U>
		struct member_access : member_access_base
		{
			typedef U      member_type;
			typedef T      class_type;
			typedef U T::* mem_ptr;
			
			/// constructor
			member_access(mem_ptr mem_var) :
				m_mem_var(mem_var)
			{}

			/// copy constructor
			member_access(const member_access& other) :
				m_mem_var(other.m_mem_var)
			{}
						
			/// create a copy of this object
			virtual member_access* clone() const
			{
				return new member_access(m_mem_var);				
			}
			
			virtual void write(void* obj_ptr, void* src_ptr) const
			{
				T& dst = *((T*)obj_ptr);
				member_type& src = *((member_type*)src_ptr);
				dst.*m_mem_var = src;
			}
			
			virtual void read(void* obj_ptr, void* dst_ptr) const
			{
				T& src = *((T*)obj_ptr);
				member_type& dst = *((member_type*)dst_ptr);
				dst = src.*m_mem_var;
			}

			virtual const void* get_raw_ptr(const void* obj_ptr) const
			{
				T& dst = *((T*)obj_ptr);
				return &(dst.*m_mem_var);
			}
			
			mem_ptr m_mem_var;
		};
		
		/// constructor
		member_variable(const char* name, const base_type *type);
		
		/// copy constructor
		member_variable(const member_variable &rhs) :
			symbol(t_member_variable, rhs.get_name()),
			m_type(rhs.m_type),
			m_access(rhs.m_access->clone())
		{			
		}
		
		/// destructor
		~member_variable();
		
		/// assignment operator
		member_variable& operator=(const member_variable& rhs)
		{
			m_type = rhs.m_type;
			m_access = m_access->clone();
			return *this;
		}
		
		/// constructor
		template<class T, class U>
		member_variable(const char* name, U T::* mem_var) :
			symbol(t_member_variable, name)
		{
			m_name = name;
			m_type = static_type_info<U>();
			m_access = new member_access<T, U>(mem_var);
		}		
		
		/// \returns the type of the member variable
		const base_type* get_type() const { return m_type; }
		
		/// read the member from the passed object. 
		/// \warning the type are assumed to match exactly, if not there may be memory stomping.
		/// \returns true if the read succeeded, false otherwise
		bool read(void* obj_ptr, void* dst_ptr) const;
		
		/// write the member from the passed object. 
		/// \warning the type are assumed to match exactly, if not there may be memory stomping.
		/// \returns true if the write succeeded, false otherwise
		bool write(void* obj_ptr, void* dst_ptr) const;

		/// \returns a raw pointer to the member variable
		const void* get_raw_ptr(const void* obj_ptr) const;
		
    private:
		const base_type* m_type;
		member_access_base* m_access;
    };

} // end namespace
} // end namespace

#endif // __MEMBER_VARIABLE_H_28FFD056_37AD_46A5_B836_74C4168C80E6_
