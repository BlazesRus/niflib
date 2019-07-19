/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSVERTEXDESC_H_
#define _BSVERTEXDESC_H_

#include "../NIF_IO.h"

namespace Niflib {


struct BSVertexDesc {
	/*! Default Constructor */
	NIFLIB_API BSVertexDesc();
	/*! Default Destructor */
	NIFLIB_API ~BSVertexDesc();
	/*! Copy Constructor */
	NIFLIB_API BSVertexDesc( const BSVertexDesc & src );
	/*! Copy Operator */
	NIFLIB_API BSVertexDesc & operator=( const BSVertexDesc & src );
	byte vf1;
	byte vf2;
	byte vf3;
	byte vf4;
	byte vf5;
	VertexFlags vertexAttributes;
	byte vf8;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
