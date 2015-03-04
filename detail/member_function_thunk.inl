//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// 
// THIS HEADER IS GENERATED, DO NOT MODIFY!
//
//////////////////////////////////////////////////////////////////////////////
#define TY_VOID_TYPE
 template<class U>
struct member_function_thunk_0 : member_function_thunk_base
{
	typedef void (U::*mem_fun)();
		
	member_function_thunk_0(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)();
		}
		else
			(obj.*m_mem_fun)();
#else			
		(obj.*m_mem_fun)();
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U>
inline member_function_type* make_member_function_type(void (U::*func)(), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	
	nt->set_call_thunk(new detail::member_function_thunk_0<U>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0>
struct member_function_thunk_1 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0);
		
	member_function_thunk_1(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0>
inline member_function_type* make_member_function_type(void (U::*func)(A0), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);

	nt->set_call_thunk(new detail::member_function_thunk_1<U, A0>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0, typename A1>
struct member_function_thunk_2 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0, A1);
		
	member_function_thunk_2(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0, typename A1>
inline member_function_type* make_member_function_type(void (U::*func)(A0, A1), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);

	nt->set_call_thunk(new detail::member_function_thunk_2<U, A0, A1>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0, typename A1, typename A2>
struct member_function_thunk_3 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0, A1, A2);
		
	member_function_thunk_3(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0, typename A1, typename A2>
inline member_function_type* make_member_function_type(void (U::*func)(A0, A1, A2), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);

	nt->set_call_thunk(new detail::member_function_thunk_3<U, A0, A1, A2>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0, typename A1, typename A2, typename A3>
struct member_function_thunk_4 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0, A1, A2, A3);
		
	member_function_thunk_4(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0, typename A1, typename A2, typename A3>
inline member_function_type* make_member_function_type(void (U::*func)(A0, A1, A2, A3), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);

	nt->set_call_thunk(new detail::member_function_thunk_4<U, A0, A1, A2, A3>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0, typename A1, typename A2, typename A3, typename A4>
struct member_function_thunk_5 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0, A1, A2, A3, A4);
		
	member_function_thunk_5(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0, typename A1, typename A2, typename A3, typename A4>
inline member_function_type* make_member_function_type(void (U::*func)(A0, A1, A2, A3, A4), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A4);

	nt->set_call_thunk(new detail::member_function_thunk_5<U, A0, A1, A2, A3, A4>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

#define TY_VOID_TYPE
 template<class U, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct member_function_thunk_6 : member_function_thunk_base
{
	typedef void (U::*mem_fun)(A0, A1, A2, A3, A4, A5);
		
	member_function_thunk_6(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<class U, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline member_function_type* make_member_function_type(void (U::*func)(A0, A1, A2, A3, A4, A5), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A4);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A5);

	nt->set_call_thunk(new detail::member_function_thunk_6<U, A0, A1, A2, A3, A4, A5>(func));
	
	return nt;
}

#undef TY_VOID_TYPE

 template<typename R, class U>
struct member_function_thunk_7 : member_function_thunk_base
{
	typedef R (U::*mem_fun)();
		
	member_function_thunk_7(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)();
		}
		else
			(obj.*m_mem_fun)();
#else			
		(obj.*m_mem_fun)();
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U>
inline member_function_type* make_member_function_type(R (U::*func)(), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	
	nt->set_call_thunk(new detail::member_function_thunk_7<R, U>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0>
struct member_function_thunk_8 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0);
		
	member_function_thunk_8(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0>
inline member_function_type* make_member_function_type(R (U::*func)(A0), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);

	nt->set_call_thunk(new detail::member_function_thunk_8<R, U, A0>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0, typename A1>
struct member_function_thunk_9 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0, A1);
		
	member_function_thunk_9(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0, typename A1>
inline member_function_type* make_member_function_type(R (U::*func)(A0, A1), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);

	nt->set_call_thunk(new detail::member_function_thunk_9<R, U, A0, A1>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0, typename A1, typename A2>
struct member_function_thunk_10 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0, A1, A2);
		
	member_function_thunk_10(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0, typename A1, typename A2>
inline member_function_type* make_member_function_type(R (U::*func)(A0, A1, A2), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);

	nt->set_call_thunk(new detail::member_function_thunk_10<R, U, A0, A1, A2>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0, typename A1, typename A2, typename A3>
struct member_function_thunk_11 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0, A1, A2, A3);
		
	member_function_thunk_11(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0, typename A1, typename A2, typename A3>
inline member_function_type* make_member_function_type(R (U::*func)(A0, A1, A2, A3), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);

	nt->set_call_thunk(new detail::member_function_thunk_11<R, U, A0, A1, A2, A3>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0, typename A1, typename A2, typename A3, typename A4>
struct member_function_thunk_12 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0, A1, A2, A3, A4);
		
	member_function_thunk_12(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0, typename A1, typename A2, typename A3, typename A4>
inline member_function_type* make_member_function_type(R (U::*func)(A0, A1, A2, A3, A4), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A4);

	nt->set_call_thunk(new detail::member_function_thunk_12<R, U, A0, A1, A2, A3, A4>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


 template<typename R, class U, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
struct member_function_thunk_13 : member_function_thunk_base
{
	typedef R (U::*mem_fun)(A0, A1, A2, A3, A4, A5);
		
	member_function_thunk_13(mem_fun func) : m_mem_fun(func) {}				
	
	virtual void call(void* obj_ptr, const argument_list& args, const argument& result) const
	{
		U& obj = *((U*)obj_ptr);
#ifndef TY_VOID_TYPE 
		if(result.get_ptr())
		{
			R& res = *((R*)result.get_ptr());
			res = (obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
		}
		else
			(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
#else			
		(obj.*m_mem_fun)(TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0), TYCHO_GLASS_INTERNAL_CAST_ARG(A1, 1), TYCHO_GLASS_INTERNAL_CAST_ARG(A2, 2), TYCHO_GLASS_INTERNAL_CAST_ARG(A3, 3), TYCHO_GLASS_INTERNAL_CAST_ARG(A4, 4), TYCHO_GLASS_INTERNAL_CAST_ARG(A5, 5));
#endif		
		
	}	
	
private:
	mem_fun m_mem_fun;		
};


template<typename R, class U, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5>
inline member_function_type* make_member_function_type(R (U::*func)(A0, A1, A2, A3, A4, A5), int flags)
{
	member_function_type* nt = new member_function_type(glass::make_default_name("$mft"), flags);
	nt->set_class_type(core::debug_checked_cast<const class_type*>(static_type_info<U>()));		
	TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A0);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A1);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A2);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A3);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A4);
TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A5);

	nt->set_call_thunk(new detail::member_function_thunk_13<R, U, A0, A1, A2, A3, A4, A5>(func));
	TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)
	return nt;
}


