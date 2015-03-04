//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 1:46:41 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __STATIC_TYPE_INFO_H_D8FCCF65_A261_46E0_88F1_8A4301800BC7_
#define __STATIC_TYPE_INFO_H_D8FCCF65_A261_46E0_88F1_8A4301800BC7_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/type_info.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{
	
	/// \returns the type_info structure for the template type
	template<class T> const base_type* static_type_info()
	{
		return type_info<T>::get_type_info();
	}
	
	/// \returns the type_info structure for the argument type
	template<class T> const base_type* static_type_info(T)
	{
		return type_info<T>::get_type_info();
	}
	

} // end namespace
} // end namespace

#endif // __STATIC_TYPE_INFO_H_D8FCCF65_A261_46E0_88F1_8A4301800BC7_
