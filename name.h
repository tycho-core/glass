//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 11:06:34 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __NAME_H_A0AAE3D7_55D2_4ED0_80C6_FAB56AEA65E5_
#define __NAME_H_A0AAE3D7_55D2_4ED0_80C6_FAB56AEA65E5_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include <string>
#include <vector>

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{


	/// All type instances in glass have an associated name that must be unique within a
	/// given process.
    class TYCHO_GLASS_ABI name
    {
    public:
		/// constructor 
		name(const char *);

		/// \returns the number of parts in the name
		int get_num_parts() const;

		/// \returns the i'th part of the name
		bool get_part(int i, char* buf, int len) const;

		/// \returns name as '::' seperated string
		const char* get_name() const;

		/// get the name as '\' seperated string
		bool get_name_as_path(char* buf, int buf_len) const;

		/// \returns true if name matches the passed name
		bool operator==(const name& rhs) const;		   

	private:
		void cache_parts() const;

    private:
		/// name in foo::bar format
		const char* m_name;

		/// cached part information, generated when requested first
		mutable std::vector<std::pair<const char*, int> > m_parts;
    };

} // end namespace
} // end namespace

#endif // __NAME_H_A0AAE3D7_55D2_4ED0_80C6_FAB56AEA65E5_
