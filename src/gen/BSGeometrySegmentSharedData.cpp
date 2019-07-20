/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSGeometrySegmentSharedData.h"
#include "../../include/gen/BSGeometryPerSegmentSharedData.h"
using namespace Niflib;

//Constructor
BSGeometrySegmentSharedData::BSGeometrySegmentSharedData() : numSegments((unsigned int)0), totalSegments((unsigned int)0), ssfLength((unsigned short)0) {};

//Copy Constructor
BSGeometrySegmentSharedData::BSGeometrySegmentSharedData( const BSGeometrySegmentSharedData & src ) {
	*this = src;
};

//Copy Operator
BSGeometrySegmentSharedData & BSGeometrySegmentSharedData::operator=( const BSGeometrySegmentSharedData & src ) {
	this->numSegments = src.numSegments;
	this->totalSegments = src.totalSegments;
	this->segmentStarts = src.segmentStarts;
	this->perSegmentData = src.perSegmentData;
	this->ssfLength = src.ssfLength;
	this->ssfFile = src.ssfFile;
	return *this;
};

//Destructor
BSGeometrySegmentSharedData::~BSGeometrySegmentSharedData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
