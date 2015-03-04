//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Sunday, 7 December 2008 10:04:03 PM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __NUMERIC_TYPE_H_4820ED8E_EDEF_4842_93E5_31FBDFE6942B_
#define __NUMERIC_TYPE_H_4820ED8E_EDEF_4842_93E5_31FBDFE6942B_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/builtin_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

    class TYCHO_GLASS_ABI numeric_type : public builtin_type
    {
    public:
		/// constructor
		numeric_type(const std::string& name, const base_type::type_t t);
    };
    
#define TYCHO_GLASS_CREATE_NUMERIC_TYPE(_t) \
	class _t##_type : public numeric_type { \
	public: \
	_t##_type(const char* name) : numeric_type(name, base_type::t_##_t) {} \
	};


	TYCHO_GLASS_CREATE_NUMERIC_TYPE(int64)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(int32)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(int16)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(int8)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(uint64)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(uint32)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(uint16)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(uint8)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(float32)
	TYCHO_GLASS_CREATE_NUMERIC_TYPE(float64)
	
} // end namespace
} // end namespace

#endif // __NUMERIC_TYPE_H_4820ED8E_EDEF_4842_93E5_31FBDFE6942B_
