//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Monday, 8 December 2008 3:27:21 AM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass.h"
#include "glass/any_value.h"
#include "glass/argument_list.h"
#include "glass/name_space.h"
#include "glass/name_table.h"
#include "glass/name.h"
#include "glass/utils.h"
#include "glass/exports/core_types.h"
#include "core/string.h"
#include <map>
#include <string>

//////////////////////////////////////////////////////////////////////////////
// CONFIG DEFINES
//////////////////////////////////////////////////////////////////////////////
#define TYCHO_GLASS_ENABLE_HEADER_CHECK 1

//////////////////////////////////////////////////////////////////////////////
// DEFINES
//////////////////////////////////////////////////////////////////////////////
#if TYCHO_GLASS_ENABLE_HEADER_CHECK
#define TYCHO_GLASS_HEADER_CHECK_MAGIC (('t' << 24) | ('y' << 16) | ('o' << 8) | ('b'))
#define TYCHO_GLASS_CHECK_HEADER_MAGIC(_val) TYCHO_ASSERT(_val == TYCHO_GLASS_HEADER_CHECK_MAGIC)
#else
#define TYCHO_GLASS_CHECK_HEADER_MAGIC(_val)
#endif

//////////////////////////////////////////////////////////////////////////////
// CLASS
//////////////////////////////////////////////////////////////////////////////
namespace tycho
{
namespace glass
{

	namespace detail
	{
		/// structure that precedes object memory. all objcets allocated through glass
		/// have this header setup for O(1) retrieval of name and type information.
		///
		/// Memory layout for a named glass object is :-
		///		char[] name		: null terminated string
		///		object_header	: object_header
		///			obj_name	: points to name above
		///			obj_type	: type of the object
		///		object			: object itself
		struct object_header
		{
			const char*			obj_name;
			const base_type*	obj_type;
#if TYCHO_GLASS_ENABLE_HEADER_CHECK
			core::uint32		debug_magic;
#endif
		};

		/// runtime environment for managing types and object instances
		class environment
		{
		public:
			environment() :
				global_namespace("$global")
			{}
		
			~environment() 
				{ clear(); }
				
			void clear() 
				{	}
			
			name_space global_namespace;
			name_table object_name_table;
		};	
	} // end namespace

	///////////////////////////////////////////////////////////////////////////////////////				
	// Static variables
	///////////////////////////////////////////////////////////////////////////////////////

	static detail::environment g_environment;


	///////////////////////////////////////////////////////////////////////////////////////				
	// System management
	///////////////////////////////////////////////////////////////////////////////////////
	
	TYCHO_GLASS_ABI bool initialise()
	{
		detail::register_core_types();
		return true;	
	}

	//------------------------------------------------------------------------------------
		
	TYCHO_GLASS_ABI bool shutdown()
	{	
		g_environment.clear();
		return true;
	}


	///////////////////////////////////////////////////////////////////////////////////////				
	// Names
	///////////////////////////////////////////////////////////////////////////////////////

	TYCHO_GLASS_ABI std::string make_default_name(const char* prefix)
	{
		static int counter = 0;
		static char buf[512];
		core::snprintf(buf, 512, "%s%d", prefix, counter++);
		return std::string(buf);
	}


	///////////////////////////////////////////////////////////////////////////////////////				
	// Querying
	///////////////////////////////////////////////////////////////////////////////////////

	//------------------------------------------------------------------------------------
	
	TYCHO_GLASS_ABI name_space* get_global_namespace()
	{
		return &g_environment.global_namespace;
	}	
	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI const base_type* find_type(const char* name)
	{
		const symbol* s = find_symbol(name);
		if(!s || !s->is_type(symbol::t_type))
			return 0;
			
		return core::debug_checked_cast<const base_type*>(s);
	}
		
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI const symbol* find_symbol(const char* name)
	{
		// split name into sections
		symbol* s = get_global_namespace();
		const char* start = name;
		const int buf_len = 256;
		char buf[buf_len] = { 0 };
		while(*start != 0)
		{
			int length = utils::split_name(start);

			// check the name was valid
			if(length == -1)
				return 0;
				
			TYCHO_ASSERT(length < buf_len);
			core::strncpy(buf, start, length);
			buf[length+1] = 0;			
			symbol* next = s->lookup_child_symbol(buf);
			if(!next)
			{
				// name doesn't exist
				return 0;
			}
			s = next;
			start = start + length;
			if(*start != 0)
				start += 2;
		}
		
		// reached the end, check we did not end with a '::'		
		if(*start != 0)
			return 0;

		return s;	
	}
	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void* find_object(const char* name)
	{
		TYCHO_ASSERT(name);
		return g_environment.object_name_table.find_name(name);
	}

	//------------------------------------------------------------------------------------

	///////////////////////////////////////////////////////////////////////////////////////				
	// Creation
	///////////////////////////////////////////////////////////////////////////////////////

	TYCHO_GLASS_ABI void* create_new_object(const base_type* type)
	{
		// create default name for the object
		static const char name[] = "temp";
		return create_new_object(type, name);
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void* create_new_object(const base_type* type, const char* name)
	{
		TYCHO_ASSERT(type);
		TYCHO_ASSERT(core::strlen(name) < glass::MaxNameLength);
		using namespace detail;

		// get some memory for the object
		int size = type->get_size();
		TYCHO_ASSERT(size);

		// add some space for the object header
		size += sizeof(object_header);

		// and some more for its name
		int name_len = core::strlen(name);
		size += name_len + 1;

		// allocate some ram
		void* mem = core::malloc(size);
		TYCHO_ASSERT(mem);

		// setup name and header information
		char* name_ptr = (char*)mem;
		core::strcpy(name_ptr, name);
		object_header* hdr = (object_header*)((unsigned char*)mem + name_len + 1);
		hdr->obj_type = type;
		hdr->obj_name = name_ptr;
		hdr->debug_magic = TYCHO_GLASS_HEADER_CHECK_MAGIC;
		TYCHO_VERIFY(g_environment.object_name_table.add_name(name, hdr + 1));
					
		// construct object
		void* obj_ptr = (unsigned char*)hdr + sizeof(object_header);
		construct_in_place(type, obj_ptr);
		
		// all done		
		return obj_ptr;
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void* create_new_object(const char* class_name)
	{
		const base_type* type = find_type(class_name);
		if(!type)
			return 0;
			
		return create_new_object(type);
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void* create_new_object(const char* class_name, const char* name)
	{
		const base_type* type = find_type(class_name);
		if(!type)
			return 0;
			
		return create_new_object(type, name);	
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void destruct_object(const base_type* type, void* ptr)
	{
		type->destruct(ptr);
	}
	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void delete_object(const base_type* type, void* ptr)
	{
		// destroy the object
		destruct_object(type, ptr);

		// free its memory
		free_object(type, ptr);
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void free_object(const base_type*, void* ptr)
	{
		using namespace detail;

		// object memory starts at preceeding header
		object_header* hdr = (object_header*)((unsigned char*)ptr - sizeof(object_header));
		TYCHO_GLASS_CHECK_HEADER_MAGIC(hdr->debug_magic);

		// release name
		g_environment.object_name_table.remove_name(hdr->obj_name);

		// if hdr->obj_name is not 0 then it points to the beginning of the memory block 
		// otherwise the hdr is at the front.
		void* mem = hdr;
		if(hdr->obj_name)
			mem = (void*)hdr->obj_name;
		core::free(mem);	
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI void construct_in_place(const base_type* type, void* ptr)
	{
		type->construct(ptr);
	}

	//------------------------------------------------------------------------------------


	///////////////////////////////////////////////////////////////////////////////////////				
	// Value mutation
	///////////////////////////////////////////////////////////////////////////////////////
			
	TYCHO_GLASS_ABI any_value read_value(const class_type* type, void* ptr, const char* name)
	{
		TYCHO_ASSERT(type);
		TYCHO_ASSERT(ptr);
		TYCHO_ASSERT(name);
		
		const member_variable* mem_var = type->find_member_variable(name);
		if(!mem_var)
			return any_value();
			
			
		return any_value();
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool write_value(const class_type*, void* , const char* , const any_value&)
	{
		return false;
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI any_value get_free_value(const char*)
	{
		return any_value();
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool set_free_value(const char*, const any_value&)
	{
		return false;
	}

	///////////////////////////////////////////////////////////////////////////////////////				
	// Function calling
	///////////////////////////////////////////////////////////////////////////////////////
	
	TYCHO_GLASS_ABI bool call_function(const char* name)
	{
		return call_function(name, argument());
	}
	
	//------------------------------------------------------------------------------------
	
	TYCHO_GLASS_ABI bool call_function(const char* name, const argument_list& args)
	{
		return call_function(name, args, argument());	
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool call_function(const class_type* type, void* obj_ptr, const char* name)
	{
		return call_function(type, obj_ptr, name, argument_list::null_args, argument());
	}
	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool call_function(const class_type* type, void* obj_ptr, const char* name, const argument_list& args)
	{
		return call_function(type, obj_ptr, name, args, argument());
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool call_function(const char*, const argument&)
	{
		return false;
	}
	
	//------------------------------------------------------------------------------------
	
	TYCHO_GLASS_ABI bool call_function(const char*, const argument_list&, const argument&)
	{
		return false;
	}

	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool call_function(const class_type* type, void* obj_ptr, const char* name, const argument& result)
	{
		return call_function(type, obj_ptr, name, argument_list::null_args, result);
	}
	
	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI bool call_function(const class_type* type, void* obj_ptr, const char* name, const argument_list& args, const argument& result)
	{
		TYCHO_ASSERT(type);
		TYCHO_ASSERT(obj_ptr);
		TYCHO_ASSERT(name);
		
		const member_function* mem_fun = type->find_member_function(name);
		if(!mem_fun)
			return false;
		return mem_fun->call(obj_ptr, args, result);			
	}

	///////////////////////////////////////////////////////////////////////////////////////				
	// Object information
	///////////////////////////////////////////////////////////////////////////////////////

	TYCHO_GLASS_ABI name get_object_name(const void* obj)
	{
		TYCHO_ASSERT(obj);
		const detail::object_header* hdr = (const detail::object_header*)((const unsigned char*)obj - sizeof(detail::object_header));
		TYCHO_GLASS_CHECK_HEADER_MAGIC(hdr->debug_magic);
		return name(hdr->obj_name);
	}

	//------------------------------------------------------------------------------------

	TYCHO_GLASS_ABI const base_type* get_object_type(const void* obj)
	{
		TYCHO_ASSERT(obj);
		const detail::object_header* hdr = (const detail::object_header*)((const unsigned char*)obj - sizeof(detail::object_header));
		TYCHO_GLASS_CHECK_HEADER_MAGIC(hdr->debug_magic);
		return hdr->obj_type;
	}

	//------------------------------------------------------------------------------------

} // end namespace
} // end namespace
