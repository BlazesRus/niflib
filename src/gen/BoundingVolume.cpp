/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoundingVolume.h"
#include "../../include/gen/BoxBV.h"
#include "../../include/gen/CapsuleBV.h"
#include "../../include/gen/HalfSpaceBV.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiPlane.h"
using namespace Niflib;

//Constructor
BoundingVolume::BoundingVolume() : collisionType((BoundVolumeType)0) {};

//Copy Constructor
BoundingVolume::BoundingVolume( const BoundingVolume & src ) {
	*this = src;
};

//Copy Operator
BoundingVolume & BoundingVolume::operator=( const BoundingVolume & src ) {
	this->collisionType = src.collisionType;
	this->sphere = src.sphere;
	this->box = src.box;
	this->capsule = src.capsule;
	this->halfSpace = src.halfSpace;
	return *this;
};

//Destructor
BoundingVolume::~BoundingVolume() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
