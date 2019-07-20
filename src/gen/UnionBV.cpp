/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/UnionBV.h"
#include "../../include/gen/BoundingVolume.h"
#include "../../include/gen/BoxBV.h"
#include "../../include/gen/CapsuleBV.h"
#include "../../include/gen/HalfSpaceBV.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiPlane.h"
using namespace Niflib;

//Constructor
UnionBV::UnionBV() : numBv((unsigned int)0) {};

//Copy Constructor
UnionBV::UnionBV( const UnionBV & src ) {
	*this = src;
};

//Copy Operator
UnionBV & UnionBV::operator=( const UnionBV & src ) {
	this->numBv = src.numBv;
	this->boundingVolumes = src.boundingVolumes;
	return *this;
};

//Destructor
UnionBV::~UnionBV() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
