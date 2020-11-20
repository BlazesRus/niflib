/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXCLOTHSTATE_H_
#define _PHYSXCLOTHSTATE_H_

#include "../NIF_IO.h"

// Include structures
#include "Matrix34.h"
namespace Niflib {


struct PhysXClothState {
	/*! Default Constructor */
	NIFLIB_API PhysXClothState();
	/*! Default Destructor */
	NIFLIB_API ~PhysXClothState();
	/*! Copy Constructor */
	NIFLIB_API PhysXClothState( const PhysXClothState & src );
	/*! Copy Operator */
	NIFLIB_API PhysXClothState & operator=( const PhysXClothState & src );
	Matrix34 pose;
	mutable unsigned short numVertexPositions;
	vector<Vector3 > vertexPositions;
	mutable unsigned short numTearIndices;
	vector<unsigned short > tearIndices;
	vector<Vector3 > tearSplitPlanes;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
