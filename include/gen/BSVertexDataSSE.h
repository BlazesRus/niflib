/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSVERTEXDATASSE_H_
#define _BSVERTEXDATASSE_H_

#include "../NIF_IO.h"

// Include structures
#include "HalfTexCoord.h"
#include "ByteVector3.h"
namespace Niflib {


struct BSVertexDataSSE {
	/*! Default Constructor */
	NIFLIB_API BSVertexDataSSE();
	/*! Default Destructor */
	NIFLIB_API ~BSVertexDataSSE();
	/*! Copy Constructor */
	NIFLIB_API BSVertexDataSSE( const BSVertexDataSSE & src );
	/*! Copy Operator */
	NIFLIB_API BSVertexDataSSE & operator=( const BSVertexDataSSE & src );
	Vector3 vertex;
	float bitangentX;
	/*! Unknown. */
	int unknownInt;
	HalfTexCoord uv;
	ByteVector3 normal;
	byte bitangentY;
	ByteVector3 tangent;
	byte bitangentZ;
	ByteColor4 vertexColors;
	Niflib::NifArray<4,hfloat > boneWeights;
	Niflib::NifArray<4,byte > boneIndices;
	float eyeData;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
