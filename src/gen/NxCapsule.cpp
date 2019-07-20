/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxCapsule.h"
using namespace Niflib;

//Constructor
NxCapsule::NxCapsule() : val1(0.0f), val2(0.0f), capsuleFlags((unsigned int)0) {};

//Copy Constructor
NxCapsule::NxCapsule( const NxCapsule & src ) {
	*this = src;
};

//Copy Operator
NxCapsule & NxCapsule::operator=( const NxCapsule & src ) {
	this->val1 = src.val1;
	this->val2 = src.val2;
	this->capsuleFlags = src.capsuleFlags;
	return *this;
};

//Destructor
NxCapsule::~NxCapsule() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
