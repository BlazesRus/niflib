/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _SHADERTEXDESC_H_
#define _SHADERTEXDESC_H_

#include "../NIF_IO.h"

// Include structures
#include "TexDesc.h"
namespace Niflib {


/*! NiTexturingProperty::ShaderMap. Shader texture description. */
struct ShaderTexDesc {
	/*! Default Constructor */
	NIFLIB_API ShaderTexDesc();
	/*! Default Destructor */
	NIFLIB_API ~ShaderTexDesc();
	/*! Copy Constructor */
	NIFLIB_API ShaderTexDesc( const ShaderTexDesc & src );
	/*! Copy Operator */
	NIFLIB_API ShaderTexDesc & operator=( const ShaderTexDesc & src );
	bool hasMap;
	TexDesc map;
	/*! Unique identifier for the Gamebryo shader system. */
	unsigned int mapId;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
