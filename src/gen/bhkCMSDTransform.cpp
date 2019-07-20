/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkCMSDTransform.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
bhkCMSDTransform::bhkCMSDTransform() {};

//Copy Constructor
bhkCMSDTransform::bhkCMSDTransform( const bhkCMSDTransform & src ) {
	*this = src;
};

//Copy Operator
bhkCMSDTransform & bhkCMSDTransform::operator=( const bhkCMSDTransform & src ) {
	this->translation = src.translation;
	this->rotation = src.rotation;
	return *this;
};

//Destructor
bhkCMSDTransform::~bhkCMSDTransform() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
