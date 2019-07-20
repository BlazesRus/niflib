/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSGeometrySegmentData.h"
#include "../../include/gen/BSGeometrySubSegment.h"
using namespace Niflib;

//Constructor
BSGeometrySegmentData::BSGeometrySegmentData() : flags((byte)0), index((unsigned int)0), numTrisInSegment((unsigned int)0), startIndex((unsigned int)0), numPrimitives((unsigned int)0), parentArrayIndex((unsigned int)0), numSubSegments((unsigned int)0) {};

//Copy Constructor
BSGeometrySegmentData::BSGeometrySegmentData( const BSGeometrySegmentData & src ) {
	*this = src;
};

//Copy Operator
BSGeometrySegmentData & BSGeometrySegmentData::operator=( const BSGeometrySegmentData & src ) {
	this->flags = src.flags;
	this->index = src.index;
	this->numTrisInSegment = src.numTrisInSegment;
	this->startIndex = src.startIndex;
	this->numPrimitives = src.numPrimitives;
	this->parentArrayIndex = src.parentArrayIndex;
	this->numSubSegments = src.numSubSegments;
	this->subSegment = src.subSegment;
	return *this;
};

//Destructor
BSGeometrySegmentData::~BSGeometrySegmentData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
