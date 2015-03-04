//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// Created : Saturday, 17 May 2008 1:24:01 PM
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////
// INCLUDES
//////////////////////////////////////////////////////////////////////////////
#include "glass/macro_interface.h"
#include "glass/static_type_info.h"
#include "glass/glass.h"
#include "glass/name_space.h"
#include "glass/bound_member_variable.h"
#include "glass/argument_list.h"
#include "glass/exports/core_types.h"
#include "glass/utils.h"
#include "glass/bitfield_type.h"
#include "mirror/filesystem_database.h"
#include "core/debug/assert.h"
#include "core/core.h"
#include "core/console.h"
#include "core/string.h"
#include "io/filesystem_device.h"
#include "io/interface.h"
#include "core/globals.h"
#include <typeinfo>
#include <float.h>
#include <stack>

using namespace std;
using namespace tycho;

/// for type registration
#if TYCHO_PC
#define ABI __declspec(dllexport)
#else
#define ABI
#endif


namespace test
{

struct bah
{
	int x, y;
};

#define TYCHO_FORCE_32BIT_ENUM(_e)  _e##TychoMaxEnumValue = 0x7fffffff

enum test_enum
{
	m1 = 0,
	m2 = 1,
	m3 = 2,
	TYCHO_FORCE_32BIT_ENUM(test_enum)
};

enum test_bitfield
{
	b1 = 1,
	b2 = 2,
	b3 = 4,
	b4 = 8,
	TYCHO_FORCE_32BIT_ENUM(test_bitfield)
};

/// test class
struct foo
{
	foo() : a(-9999), b(-9999), enum_(m2), other_foo(0), other_foo2(0), bitfield_((test_bitfield)(b1 | b2 | b4)) {}
	~foo() { a = 0; b = 0; }

	void zero() { a = 0; b = 0; }
	int	 get_a() { return a; }
	void set_a(const int a_) { a = a_;}
	void sum_params(int a1, int a2, int a3, int a4, foo) { a = a1 + a2 + a3 + a4; }

	bah get_bah() { return bah_; }
	void set_bah(bah b) { bah_ = b; }
	
	int a;
	float b;
	bah   bah_;
	test_enum enum_;
	foo* other_foo;
	foo* other_foo2;
	test_bitfield bitfield_;
	void (foo::*mem_fun)();
};

} // end namespace

TYCHO_GLASS_INSTANTIATE_CLASS_TYPE_INFO(ABI,test::foo)
TYCHO_GLASS_INSTANTIATE_CLASS_TYPE_INFO(ABI,test::bah)
TYCHO_GLASS_INSTANTIATE_ENUM_TYPE_INFO(ABI,test::test_enum)
TYCHO_GLASS_INSTANTIATE_BITFIELD_TYPE_INFO(ABI,test::test_bitfield)
 
TYCHO_GLASS_IMPLEMENT_CLASS_TYPE_INFO(ABI,test::foo)
TYCHO_GLASS_IMPLEMENT_CLASS_TYPE_INFO(ABI,test::bah)
TYCHO_GLASS_IMPLEMENT_ENUM_TYPE_INFO(ABI,test::test_enum)
TYCHO_GLASS_IMPLEMENT_BITFIELD_TYPE_INFO(ABI,test::test_bitfield)

void register_stuff()
{
	TYCHO_GLASS_REGISTER_BEGIN()
		TYCHO_GLASS_BEGIN_NAMESPACE(test)		
			TYCHO_GLASS_DEF_CLASS(bah)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(x)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(y)
			TYCHO_GLASS_DEF_CLASS_END()
		TYCHO_GLASS_END_NAMESPACE()
		
		TYCHO_GLASS_BEGIN_NAMESPACE(test)		
			TYCHO_GLASS_DEF_ENUM(test_enum)
				TYCHO_GLASS_DEF_ENUM_MEMBER(m1)
				TYCHO_GLASS_DEF_ENUM_MEMBER(m2)
				TYCHO_GLASS_DEF_ENUM_MEMBER(m3)
			TYCHO_GLASS_DEF_ENUM_END()

			TYCHO_GLASS_DEF_BITFIELD(test_bitfield)
				TYCHO_GLASS_DEF_BITFIELD_MEMBER(b1)
				TYCHO_GLASS_DEF_BITFIELD_MEMBER(b2)
				TYCHO_GLASS_DEF_BITFIELD_MEMBER(b3)
				TYCHO_GLASS_DEF_BITFIELD_MEMBER(b4)
			TYCHO_GLASS_DEF_ENUM_END()

			TYCHO_GLASS_DEF_CLASS(foo)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(a)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(b)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(bah_)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(enum_)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(bitfield_)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(other_foo)
				TYCHO_GLASS_DEF_CLASS_MEMBER_VARIABLE(other_foo2)
				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(zero)
  				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(get_a)
  				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(set_a)
  				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(sum_params)
  				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(get_bah)
  				TYCHO_GLASS_DEF_CLASS_MEMBER_FUNCTION(set_bah)
			TYCHO_GLASS_DEF_CLASS_END()
		TYCHO_GLASS_END_NAMESPACE()
	TYCHO_GLASS_REGISTER_END()
}

void test_builtin_types()
{
	using namespace tycho::glass;

#define CHECK_BUILTIN(_name) TYCHO_ASSERT(core::strcmp(static_type_info<tycho::core::_name>()->get_name().c_str(), #_name) == 0)

	CHECK_BUILTIN(int64);
	CHECK_BUILTIN(int32);
	CHECK_BUILTIN(int16);
	CHECK_BUILTIN(int8);
	CHECK_BUILTIN(uint64);
	CHECK_BUILTIN(uint32);
	CHECK_BUILTIN(uint16);
	CHECK_BUILTIN(uint8);
	CHECK_BUILTIN(float32);
	CHECK_BUILTIN(float64);
	
#undef CHECK_BUILTIN
}


int main(int , char* [])
{
	using namespace tycho::glass;
	
	core::initialise();
	core::console::initialise("Glass Tests");
	glass::initialise();
	test_builtin_types();
	register_stuff();
	
	const int32_type* t = dynamic_cast<const int32_type*>(static_type_info<int>());
	const class_type* foo_type = dynamic_cast<const class_type*>(static_type_info<test::foo>());
	
	TYCHO_ASSERT(t);
	TYCHO_ASSERT(foo_type);
	TYCHO_ASSERT(glass::find_type("tycho::core::int32") == t);
	TYCHO_ASSERT(glass::find_type("test::foo") == foo_type);
	TYCHO_ASSERT(core::strcmp("foo", foo_type->get_name().c_str()) == 0);
		
	void* obj = glass::create_new_object(foo_type, "game_objects::foo1");
	TYCHO_ASSERT(obj);

	TYCHO_ASSERT(glass::find_object("game_objects::foo1") == obj);
	TYCHO_ASSERT(glass::get_object_name(obj) == glass::name("game_objects::foo1"));
	TYCHO_ASSERT(glass::get_object_type(obj) == foo_type);
	
	test::foo*  foo_obj = (test::foo*)obj;
	foo_obj->other_foo = (test::foo*)glass::create_new_object(foo_type, "game_objects::foo2");
	TYCHO_ASSERT(foo_obj->other_foo);

	int a = 9999;
	TYCHO_ASSERT(glass::utils::read_value<int>(foo_type, obj, "a", a));
	TYCHO_ASSERT(a == foo_obj->a);
	a += 1;
	TYCHO_ASSERT(glass::utils::write_value<int>(foo_type, obj, "a", a));
	TYCHO_ASSERT(a == foo_obj->a);
	a = -9999;
	TYCHO_ASSERT(glass::utils::read_value<int>(foo_type, obj, "a", a));
	TYCHO_ASSERT(a == foo_obj->a);

	float b = 0;
	TYCHO_ASSERT(glass::utils::read_value<float>(foo_type, obj, "b", b));
	TYCHO_ASSERT(b == foo_obj->b);
	b = 9999;
	TYCHO_ASSERT(glass::utils::write_value<float>(foo_type, obj, "b", b));
	TYCHO_ASSERT(b == foo_obj->b);
	b = -9999;
	TYCHO_ASSERT(glass::utils::read_value<float>(foo_type, obj, "b", b));	
	TYCHO_ASSERT(b == foo_obj->b);

	// 0 arg function
	glass::call_function(foo_type, obj, "zero");
	TYCHO_ASSERT(foo_obj->a == 0);
	TYCHO_ASSERT(foo_obj->b == 0.0f);
	
	
	// 1 arg function
	{
		glass::argument_list args;
		args.push(a);
		glass::call_function(foo_type, obj, "set_a", args);
	}
	
  	// 4 arg function
	{
		int a1 = 1, a2 = 2, a3 = 3, a4 = 4;
		test::foo f;
		glass::argument_list args;
		args.push(a1);
		args.push(a2);
		args.push(a3);
		args.push(a4);
		args.push(f);
		glass::call_function(foo_type, obj, "sum_params", args);
	}
	
	// return type test
	{
		int res;
		TYCHO_ASSERT(glass::call_function(foo_type, obj, "get_a", glass::argument(res)));
		TYCHO_ASSERT(res == foo_obj->a);
	}
	
	// 
	{
		test::bah b;
		b.x = 1;
		b.y = 2;
		glass::argument_list args;
		args.push(b);
		TYCHO_ASSERT(glass::call_function(foo_type, obj, "set_bah", args));
		TYCHO_ASSERT(foo_obj->bah_.x == b.x);
		TYCHO_ASSERT(foo_obj->bah_.y == b.y);
		b.x = b.y = 0;
		TYCHO_ASSERT(glass::call_function(foo_type, obj, "get_bah", glass::argument(b)));
		TYCHO_ASSERT(foo_obj->bah_.x == b.x);
		TYCHO_ASSERT(foo_obj->bah_.y == b.y);
	}
	
#if 0
	// mount asset db
	core::io::filesystem_device_ptr fs_device(new core::io::filesystem_device());
	core::globals::get_io().add_device(fs_device);
#if TYCHO_PC
	std::string asset_db_path = core::pc::app_data_dir("glass_tests") + "asset_db";
#elif TYCHO_LINUX
	std::string asset_db_path = core::linux::app_data_dir("glass_tests") + "asset_db";
#endif

	core::globals::get_io().mount("/asset_db/", fs_device->make_mount_point(asset_db_path.c_str()));	

	// serialise object tree to filesystem
	mirror::database* db = new mirror::filesystem_database("/asset_db");
	int trx_id = db->start_transaction();
	db->store_object(trx_id, foo_obj, foo_type, glass::get_object_name(foo_obj));
	db->store_object(trx_id, foo_obj->other_foo, foo_type, glass::get_object_name(foo_obj->other_foo));
	db->commit_transaction(trx_id);
	
	// reload object tree from filesystem
	trx_id = db->start_transaction();
	test::foo* f2 = (test::foo*)db->load_object(trx_id, "test::foo_obj");
	db->commit_transaction(trx_id);
	
	delete db;

#endif // 0


	// check they are equal
	
	glass::delete_object(foo_type, foo_obj->other_foo);	
	glass::delete_object(foo_type, obj);
	glass::shutdown();
	
	core::console::shutdown();
	core::shutdown();
	
	return 0;
}
