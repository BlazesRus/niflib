/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXClothState.h"
#include "../../include/gen/Matrix34.h"
using namespace Niflib;

//Constructor
PhysXClothState::PhysXClothState() : numVertexPositions((unsigned short)0), numTearIndices((unsigned short)0) {};

//Copy Constructor
PhysXClothState::PhysXClothState( const PhysXClothState & src ) {
	*this = src;
};

//Copy Operator
PhysXClothState & PhysXClothState::operator=( const PhysXClothState & src ) {
	this->pose = src.pose;
	this->numVertexPositions = src.numVertexPositions;
	this->vertexPositions = src.vertexPositions;
	this->numTearIndices = src.numTearIndices;
	this->tearIndices = src.tearIndices;
	this->tearSplitPlanes = src.tearSplitPlanes;
	return *this;
};

//Destructor
PhysXClothState::~PhysXClothState() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
