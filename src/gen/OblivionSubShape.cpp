/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/OblivionSubShape.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/HavokMaterial.h"
using namespace Niflib;

//Constructor
OblivionSubShape::OblivionSubShape() : numVertices((unsigned int)0) {};

//Copy Constructor
OblivionSubShape::OblivionSubShape( const OblivionSubShape & src ) {
	*this = src;
};

//Copy Operator
OblivionSubShape & OblivionSubShape::operator=( const OblivionSubShape & src ) {
	this->havokFilter = src.havokFilter;
	this->numVertices = src.numVertices;
	this->material = src.material;
	return *this;
};

//Destructor
OblivionSubShape::~OblivionSubShape() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
