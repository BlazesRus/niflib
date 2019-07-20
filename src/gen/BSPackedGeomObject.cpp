/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BSPackedGeomObject.h"
using namespace Niflib;

//Constructor
BSPackedGeomObject::BSPackedGeomObject() : shapeId1((unsigned int)0), shapeId2((unsigned int)0) {};

//Copy Constructor
BSPackedGeomObject::BSPackedGeomObject( const BSPackedGeomObject & src ) {
	*this = src;
};

//Copy Operator
BSPackedGeomObject & BSPackedGeomObject::operator=( const BSPackedGeomObject & src ) {
	this->shapeId1 = src.shapeId1;
	this->shapeId2 = src.shapeId2;
	return *this;
};

//Destructor
BSPackedGeomObject::~BSPackedGeomObject() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
