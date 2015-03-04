//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:03:43 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __ENUM_TYPE_H_D4FEBDB3_830D_4804_90BD_B46CA84002E6_
#define __ENUM_TYPE_H_D4FEBDB3_830D_4804_90BD_B46CA84002E6_

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

	/// C++ enumeration type, just a name to integer map.
    class TYCHO_GLASS_ABI enum_type : 
		public base_type
    {
    public:
		/// single entry in the enumeration.
		struct entry
		{
			entry(const char* name_, core::uint32 value_) :
				name(name_), value(value_) {}			
			const char*  name;
			core::int32 value;			
		};
		
	public:
		/// constructor
		enum_type(const std::string& name);
		
		/// destructor
		~enum_type();
		
		/// add a new entry to the enum
		void add_member(const char* name, core::int32 value);
		
		/// lookup a value from a name
		bool find(const char* name, core::int32& value) const;

		/// lookup a name from a value
		bool find(core::int32 value, const char*& name) const;
		    
    private:
		typedef std::vector<entry> entry_list;
		entry_list m_entries;
    };

} // end namespace
} // end namespace

#endif // __ENUM_TYPE_H_D4FEBDB3_830D_4804_90BD_B46CA84002E6_
