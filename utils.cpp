//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Tuesday, 9 June 2009 7:54:09 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "utils.h"
#include "core/string.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{
namespace utils
{

    //--------------------------------------------------------------------

	TYCHO_GLASS_ABI bool gather_unique_objects(const base_type* type, const void* ptr, std::vector<glass::argument>& unique_objects)
	{
		// iterate over the type info digging out pointers to other objects
		return false;
	}
	
    //--------------------------------------------------------------------

	TYCHO_GLASS_ABI int split_name(const char* start)
	{
		if(*start == 0)
			return 0;
		const char* end = core::strchr(start, ':');		
		if(end == 0)
			return core::strlen(start);
		if(*end == 0 || *(end+1) != ':')
			return 0; // invalid name
		return end - start;
	}

    //--------------------------------------------------------------------

} // end namespace
} // end namespace
} // end namespace
