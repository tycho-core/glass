//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 11:27:19 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __ANNOTATION_H_C7F3D2A3_93DF_4E0B_8E22_2B61BC8C85DC_
#define __ANNOTATION_H_C7F3D2A3_93DF_4E0B_8E22_2B61BC8C85DC_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// An annotation allows arbitrary data to be associated with an symbol
	/// that can be queried at a later time.
    class TYCHO_GLASS_ABI annotation
    {
    public:
		/// destructor
		virtual ~annotation() {}    
    };

} // end namespace
} // end namespace

#endif // __ANNOTATION_H_C7F3D2A3_93DF_4E0B_8E22_2B61BC8C85DC_
