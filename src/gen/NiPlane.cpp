/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiPlane.h"
using namespace Niflib;

//Constructor
NiPlane::NiPlane() : constant(0.0f) {};

//Copy Constructor
NiPlane::NiPlane( const NiPlane & src ) {
	*this = src;
};

//Copy Operator
NiPlane & NiPlane::operator=( const NiPlane & src ) {
	this->normal = src.normal;
	this->constant = src.constant;
	return *this;
};

//Destructor
NiPlane::~NiPlane() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
