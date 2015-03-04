//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 12 December 2008 1:16:05 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __REFERENCE_TYPE_H_9438CB53_04DC_42D1_850C_85B6896655EC_
#define __REFERENCE_TYPE_H_9438CB53_04DC_42D1_850C_85B6896655EC_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/pointer_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

	/// implemented as a wrapper over a pointer. 
    class TYCHO_GLASS_ABI reference_type : public pointer_type
    {
    public:
		reference_type(const std::string& name);        
    };

} // end namespace
} // end namespace

#endif // __REFERENCE_TYPE_H_9438CB53_04DC_42D1_850C_85B6896655EC_