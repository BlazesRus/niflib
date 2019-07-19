/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/CapsuleBV.h"
using namespace Niflib;

//Constructor
CapsuleBV::CapsuleBV() : extent(0.0f), radius(0.0f) {};

//Copy Constructor
CapsuleBV::CapsuleBV( const CapsuleBV & src ) {
	*this = src;
};

//Copy Operator
CapsuleBV & CapsuleBV::operator=( const CapsuleBV & src ) {
	this->center = src.center;
	this->origin = src.origin;
	this->extent = src.extent;
	this->radius = src.radius;
	return *this;
};

//Destructor
CapsuleBV::~CapsuleBV() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
