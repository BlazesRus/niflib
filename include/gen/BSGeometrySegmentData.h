/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSGEOMETRYSEGMENTDATA_H_
#define _BSGEOMETRYSEGMENTDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "BSGeometrySubSegment.h"
namespace Niflib {


/*!
 * Bethesda-specific. Describes groups of triangles either segmented in a grid (for
 * LOD) or by body part for skinned FO4 meshes.
 */
struct BSGeometrySegmentData {
	/*! Default Constructor */
	NIFLIB_API BSGeometrySegmentData();
	/*! Default Destructor */
	NIFLIB_API ~BSGeometrySegmentData();
	/*! Copy Constructor */
	NIFLIB_API BSGeometrySegmentData( const BSGeometrySegmentData & src );
	/*! Copy Operator */
	NIFLIB_API BSGeometrySegmentData & operator=( const BSGeometrySegmentData & src );
	byte flags;
	/*! Index = previous Index + previous Num Tris in Segment * 3 */
	unsigned int index;
	/*! The number of triangles belonging to this segment */
	unsigned int numTrisInSegment;
	unsigned int startIndex;
	unsigned int numPrimitives;
	unsigned int parentArrayIndex;
	mutable unsigned int numSubSegments;
	vector<BSGeometrySubSegment > subSegment;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
