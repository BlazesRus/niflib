/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoneTransform.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
BoneTransform::BoneTransform() {};

//Copy Constructor
BoneTransform::BoneTransform( const BoneTransform & src ) {
	*this = src;
};

//Copy Operator
BoneTransform & BoneTransform::operator=( const BoneTransform & src ) {
	this->translation = src.translation;
	this->rotation = src.rotation;
	this->scale = src.scale;
	return *this;
};

//Destructor
BoneTransform::~BoneTransform() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
