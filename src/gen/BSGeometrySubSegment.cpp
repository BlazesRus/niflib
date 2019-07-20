/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSGeometrySubSegment.h"
using namespace Niflib;

//Constructor
BSGeometrySubSegment::BSGeometrySubSegment() : startIndex((unsigned int)0), numPrimitives((unsigned int)0), parentArrayIndex((unsigned int)0), unused((unsigned int)0) {};

//Copy Constructor
BSGeometrySubSegment::BSGeometrySubSegment( const BSGeometrySubSegment & src ) {
	*this = src;
};

//Copy Operator
BSGeometrySubSegment & BSGeometrySubSegment::operator=( const BSGeometrySubSegment & src ) {
	this->startIndex = src.startIndex;
	this->numPrimitives = src.numPrimitives;
	this->parentArrayIndex = src.parentArrayIndex;
	this->unused = src.unused;
	return *this;
};

//Destructor
BSGeometrySubSegment::~BSGeometrySubSegment() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
