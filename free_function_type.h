//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:06:07 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __FREE_FUNCTION_TYPE_H_EEF4E7B5_D326_42A5_B4C0_E1A3561812FA_
#define __FREE_FUNCTION_TYPE_H_EEF4E7B5_D326_42A5_B4C0_E1A3561812FA_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/function_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

    class TYCHO_GLASS_ABI free_function_type : public function_type
    {
    public:
		/// constructor
		free_function_type(const std::string& name) : function_type(name, base_type::t_free_function) {}    
    
    private:
    
    };

} // end namespace
} // end namespace

#endif // __FREE_FUNCTION_TYPE_H_EEF4E7B5_D326_42A5_B4C0_E1A3561812FA_
