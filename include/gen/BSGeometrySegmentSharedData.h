/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSGEOMETRYSEGMENTSHAREDDATA_H_
#define _BSGEOMETRYSEGMENTSHAREDDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "BSGeometryPerSegmentSharedData.h"
namespace Niflib {


struct BSGeometrySegmentSharedData {
	/*! Default Constructor */
	NIFLIB_API BSGeometrySegmentSharedData();
	/*! Default Destructor */
	NIFLIB_API ~BSGeometrySegmentSharedData();
	/*! Copy Constructor */
	NIFLIB_API BSGeometrySegmentSharedData( const BSGeometrySegmentSharedData & src );
	/*! Copy Operator */
	NIFLIB_API BSGeometrySegmentSharedData & operator=( const BSGeometrySegmentSharedData & src );
	mutable unsigned int numSegments;
	mutable unsigned int totalSegments;
	vector<unsigned int > segmentStarts;
	vector<BSGeometryPerSegmentSharedData > perSegmentData;
	mutable unsigned short ssfLength;
	vector<byte > ssfFile;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
