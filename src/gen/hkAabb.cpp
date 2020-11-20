/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/hkAabb.h"
using namespace Niflib;

//Constructor
hkAabb::hkAabb() {};

//Copy Constructor
hkAabb::hkAabb( const hkAabb & src ) {
	*this = src;
};

//Copy Operator
hkAabb & hkAabb::operator=( const hkAabb & src ) {
	this->min = src.min;
	this->max = src.max;
	return *this;
};

//Destructor
hkAabb::~hkAabb() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
