/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiBound.h"
using namespace Niflib;

//Constructor
NiBound::NiBound() : radius(0.0f) {};

//Copy Constructor
NiBound::NiBound( const NiBound & src ) {
	*this = src;
};

//Copy Operator
NiBound & NiBound::operator=( const NiBound & src ) {
	this->center = src.center;
	this->radius = src.radius;
	return *this;
};

//Destructor
NiBound::~NiBound() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
