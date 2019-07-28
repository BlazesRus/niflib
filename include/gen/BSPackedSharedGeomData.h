/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSPACKEDSHAREDGEOMDATA_H_
#define _BSPACKEDSHAREDGEOMDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "BSPackedGeomDataCombined.h"
#include "BSVertexDesc.h"
namespace Niflib {


struct BSPackedSharedGeomData {
	/*! Default Constructor */
	NIFLIB_API BSPackedSharedGeomData();
	/*! Default Destructor */
	NIFLIB_API ~BSPackedSharedGeomData();
	/*! Copy Constructor */
	NIFLIB_API BSPackedSharedGeomData( const BSPackedSharedGeomData & src );
	/*! Copy Operator */
	NIFLIB_API BSPackedSharedGeomData & operator=( const BSPackedSharedGeomData & src );
	unsigned int numVerts;
	unsigned int lodLevels;
	unsigned int triCountLod0;
	unsigned int triOffsetLod0;
	unsigned int triCountLod1;
	unsigned int triOffsetLod1;
	unsigned int triCountLod2;
	unsigned int triOffsetLod2;
	mutable unsigned int numCombined;
	vector<BSPackedGeomDataCombined > combined;
	BSVertexDesc vertexDesc;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
