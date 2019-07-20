/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BonePose.h"
#include "../../include/gen/BoneTransform.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
BonePose::BonePose() : numTransforms((unsigned int)0) {};

//Copy Constructor
BonePose::BonePose( const BonePose & src ) {
	*this = src;
};

//Copy Operator
BonePose & BonePose::operator=( const BonePose & src ) {
	this->numTransforms = src.numTransforms;
	this->transforms = src.transforms;
	return *this;
};

//Destructor
BonePose::~BonePose() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
