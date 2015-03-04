//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Wednesday, 10 December 2008 11:50:07 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __BITFIELD_TYPE_H_957DF70A_35AB_42CD_BEAF_00452E78E28E_
#define __BITFIELD_TYPE_H_957DF70A_35AB_42CD_BEAF_00452E78E28E_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/enum_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// We distinguish c++ enum types where each value is a power of 2 so we can 
	/// do more intelligent handling.
    class TYCHO_GLASS_ABI bitfield_type : public base_type
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
		bitfield_type(const std::string& name);

		/// add a new entry to the bitfield
		virtual void add_member(const char* name, core::int32 value);
		
		/// lookup a value from a bitfield
		virtual bool find(const char* name, core::int32& value) const;

		/// lookup a name from a bitfield
		virtual bool find(core::int32 value, const char*& name) const;
			    
    private:
		typedef std::vector<entry> entry_list;
		entry_list m_entries;
	};

} // end namespace
} // end namespace

#endif // __BITFIELD_TYPE_H_957DF70A_35AB_42CD_BEAF_00452E78E28E_
