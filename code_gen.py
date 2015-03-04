#
# Parses glass/detail/member_function_thunk.template and generates thunks for all variations of
# number of parameters, constness and return types of member functions supported.
#
import re
import sys

# Maximum number of parameters
Arity = 6

# Return type variants
ReturnTypes = [
	[ "",             "void", ""    ], # void return type
	[ "typename R, ", "R",    "R, " ]  # non void return type
	]

# CV specifier variations
CVSpecifier = [ "", "const" ]

# regex match objects
ReReturnTypeDef = re.compile("\!return_type_def\!")
ReArgsDef = re.compile("(\!args_def\!)")
ReReturnType = re.compile("(\!return_type\!)")
ReReturnThunk = re.compile("(\!return_type_thunk\!)")
ReArgs = re.compile("(\!args\!)")
ReCommaArgs = re.compile("(\!comma_args\!)")

ReCastArgs = re.compile("(\!cast_args\!)")
ReCount = re.compile("(\!count\!)")
ReAddParams = re.compile("(\!add_params\!)")
ReSetReturnType = re.compile("(\!set_return_type\!)")

FileHeader = r"""//////////////////////////////////////////////////////////////////////////////
// Tycho Game Library
// Copyright (C) 2008 Martin Slater
// 
// THIS HEADER IS GENERATED, DO NOT MODIFY!
//
//////////////////////////////////////////////////////////////////////////////
"""

def generate_template(source, DestFile, Arity, ReturnTypeDef, ReturnType, ReturnTypeThunk, CVSpecifier, class_counter):
	copy = source
	is_void = (ReturnTypeDef == "")
	
	ArgsDef = ""
	Args = ""
	CastArgs = ""
	AddParams = ""
	if Arity > 0:
		for i in range(Arity):
			ArgsDef = ArgsDef + ", typename A%s" % i
			AddParams = AddParams + "TYCHO_GLASS_INTERNAL_ADD_PARAMETER(nt, A%s);\n" % i
			if i == 0:
				Args = "A0"
				CastArgs = "TYCHO_GLASS_INTERNAL_CAST_ARG(A0, 0)"
			else:
				Args = Args + ", A%s" % i
				CastArgs = CastArgs + ", TYCHO_GLASS_INTERNAL_CAST_ARG(A%s, %s)" % (i, i)
				
	CommaArgs = ""
	if Arity > 0:
		CommaArgs = ", " + Args

	SetReturnType = ""
	if ReturnTypeDef != "":
		SetReturnType = "TYCHO_GLASS_INTERNAL_SET_RETURN_TYPE(nt, R)"
		
	copy = re.sub(ReReturnTypeDef,	ReturnTypeDef, copy)
	copy = re.sub(ReArgsDef,		ArgsDef, copy)
	copy = re.sub(ReReturnType,		ReturnType, copy)
	copy = re.sub(ReReturnThunk,	ReturnTypeThunk, copy)
	copy = re.sub(ReArgs,			Args, copy)
	copy = re.sub(ReCommaArgs,		CommaArgs, copy)
	copy = re.sub(ReCastArgs,		CastArgs, copy)
	copy = re.sub(ReAddParams,		AddParams, copy)
	copy = re.sub(ReSetReturnType,	SetReturnType, copy)
	
	copy = re.sub(ReCount,		    "%s" % class_counter, copy)
	
	if is_void:		
		DestFile.write("#define TY_VOID_TYPE\n");
	DestFile.write(copy)
	if is_void:		
		DestFile.write("#undef TY_VOID_TYPE\n");
	DestFile.write("\n")
	
def GenerateFunctionBindingDefinitions(source, dest):	
	# input source
	src = open(source)
	template = src.read()

	# output file
	output = open(dest, "w+t");
	output.write(FileHeader);
	
	# counter used to uniquley name classes
	class_counter = 0

	# generate over all variations
	for return_type in ReturnTypes:
		for arity in range(Arity+1):
			generate_template(template, output, arity, return_type[0], return_type[1], return_type[2],"", class_counter)
			class_counter = class_counter + 1
			
	return 0
	
