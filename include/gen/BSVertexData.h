/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSVERTEXDATA_H_
#define _BSVERTEXDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "HalfVector3.h"
#include "HalfTexCoord.h"
#include "ByteVector3.h"
namespace Niflib {


struct BSVertexData {
	/*! Default Constructor */
	NIFLIB_API BSVertexData();
	/*! Default Destructor */
	NIFLIB_API ~BSVertexData();
	/*! Copy Constructor */
	NIFLIB_API BSVertexData( const BSVertexData & src );
	/*! Copy Operator */
	NIFLIB_API BSVertexData & operator=( const BSVertexData & src );
	HalfVector3 vertex;
	hfloat bitangentX;
	/*! Unknown. */
	unsigned short unknownShort;
	/*! Unknown. */
	unsigned int unknownInt;
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
