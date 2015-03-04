//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Friday, 12 December 2008 9:48:34 AM
//////////////////////////////////////////////////////////////////////////////
#if _MSC_VER > 1000
#pragma once
#endif  // _MSC_VER

#ifndef __POINTER_TYPE_H_C9FB3A8E_86FD_4B2E_BBE3_A7267B960369_
#define __POINTER_TYPE_H_C9FB3A8E_86FD_4B2E_BBE3_A7267B960369_

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/glass_abi.h"
#include "glass/forward_decls.h"
#include "glass/base_type.h"

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////

namespace tycho
{
namespace glass
{

    class TYCHO_GLASS_ABI pointer_type : public base_type
    {
    public:
		/// constructor 
		pointer_type(const std::string& name);
		
		/// destructor
		~pointer_type();
		
		/// set the pointee type
		void set_pointee_type(const base_type*);
		
		/// get the type of the object pointed to
		const base_type* get_pointee_type() const;
		
    private:
		const base_type* m_pointee_type;
    };

} // end namespace
} // end namespace

#endif // __POINTER_TYPE_H_C9FB3A8E_86FD_4B2E_BBE3_A7267B960369_
