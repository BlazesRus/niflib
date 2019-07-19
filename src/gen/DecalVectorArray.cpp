/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/DecalVectorArray.h"
using namespace Niflib;

//Constructor
DecalVectorArray::DecalVectorArray() : numVectors((short)0) {};

//Copy Constructor
DecalVectorArray::DecalVectorArray( const DecalVectorArray & src ) {
	*this = src;
};

//Copy Operator
DecalVectorArray & DecalVectorArray::operator=( const DecalVectorArray & src ) {
	this->numVectors = src.numVectors;
	this->points = src.points;
	this->normals = src.normals;
	return *this;
};

//Destructor
DecalVectorArray::~DecalVectorArray() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
