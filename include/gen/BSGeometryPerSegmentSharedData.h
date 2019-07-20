/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSGEOMETRYPERSEGMENTSHAREDDATA_H_
#define _BSGEOMETRYPERSEGMENTSHAREDDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


struct BSGeometryPerSegmentSharedData {
	/*! Default Constructor */
	NIFLIB_API BSGeometryPerSegmentSharedData();
	/*! Default Destructor */
	NIFLIB_API ~BSGeometryPerSegmentSharedData();
	/*! Copy Constructor */
	NIFLIB_API BSGeometryPerSegmentSharedData( const BSGeometryPerSegmentSharedData & src );
	/*! Copy Operator */
	NIFLIB_API BSGeometryPerSegmentSharedData & operator=( const BSGeometryPerSegmentSharedData & src );
	/*!
	 * If Bone ID is 0xffffffff, this value refers to the Segment at the listed index.
	 * Otherwise this is the "Biped Object", which is like the body part types in
	 * Skyrim and earlier.
	 */
	unsigned int userIndex;
	/*! A hash of the bone name string. */
	unsigned int boneId;
	/*! Maximum of 8. */
	mutable unsigned int numCutOffsets;
	vector<float > cutOffsets;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
