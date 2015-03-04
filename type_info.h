	//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 2:37:13 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __TYPE_INFO_H_E2E11267_DCBE_4B80_AD2B_16E382E6C91D_
#define __TYPE_INFO_H_E2E11267_DCBE_4B80_AD2B_16E382E6C91D_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// Type info. This needs to be defined for all types that are to be
	/// visible to the glass.
	template<class T> struct type_info
    {
		/// \returns the glass type for this type
		static const base_type* get_type_info() { return 0; }	
				
		/// the size of the object in bytes on the machine it is being run on.
		static const int size = sizeof(T);
    };
           

} // end namespace
} // end namespace

#endif // __TYPE_INFO_H_E2E11267_DCBE_4B80_AD2B_16E382E6C91D_
