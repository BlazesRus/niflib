/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCMSDCHUNK_H_
#define _BHKCMSDCHUNK_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Defines subshape chunks in bhkCompressedMeshShapeData */
struct bhkCMSDChunk {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDChunk();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDChunk();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDChunk( const bhkCMSDChunk & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDChunk & operator=( const bhkCMSDChunk & src );
	Vector4 translation;
	/*! Index of material in bhkCompressedMeshShapeData::Chunk Materials */
	unsigned int materialIndex;
	/*! Always 65535? */
	unsigned short reference;
	/*! Index of transformation in bhkCompressedMeshShapeData::Chunk Transforms */
	unsigned short transformIndex;
	mutable unsigned int numVertices;
	vector<unsigned short > vertices;
	mutable unsigned int numIndices;
	vector<unsigned short > indices;
	mutable unsigned int numStrips;
	vector<unsigned short > strips;
	mutable unsigned int numWeldingInfo;
	vector<unsigned short > weldingInfo;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
