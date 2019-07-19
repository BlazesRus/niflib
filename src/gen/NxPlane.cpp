/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxPlane.h"
using namespace Niflib;

//Constructor
NxPlane::NxPlane() : val1(0.0f) {};

//Copy Constructor
NxPlane::NxPlane( const NxPlane & src ) {
	*this = src;
};

//Copy Operator
NxPlane & NxPlane::operator=( const NxPlane & src ) {
	this->val1 = src.val1;
	this->point1 = src.point1;
	return *this;
};

//Destructor
NxPlane::~NxPlane() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
