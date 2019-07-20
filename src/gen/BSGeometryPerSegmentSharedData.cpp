/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSGeometryPerSegmentSharedData.h"
using namespace Niflib;

//Constructor
BSGeometryPerSegmentSharedData::BSGeometryPerSegmentSharedData() : userIndex((unsigned int)0), boneId((unsigned int)0), numCutOffsets((unsigned int)0) {};

//Copy Constructor
BSGeometryPerSegmentSharedData::BSGeometryPerSegmentSharedData( const BSGeometryPerSegmentSharedData & src ) {
	*this = src;
};

//Copy Operator
BSGeometryPerSegmentSharedData & BSGeometryPerSegmentSharedData::operator=( const BSGeometryPerSegmentSharedData & src ) {
	this->userIndex = src.userIndex;
	this->boneId = src.boneId;
	this->numCutOffsets = src.numCutOffsets;
	this->cutOffsets = src.cutOffsets;
	return *this;
};

//Destructor
BSGeometryPerSegmentSharedData::~BSGeometryPerSegmentSharedData() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
