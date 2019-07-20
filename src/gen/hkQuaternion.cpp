/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
hkQuaternion::hkQuaternion() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {};

//Copy Constructor
hkQuaternion::hkQuaternion( const hkQuaternion & src ) {
	*this = src;
};

//Copy Operator
hkQuaternion & hkQuaternion::operator=( const hkQuaternion & src ) {
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
	this->w = src.w;
	return *this;
};

//Destructor
hkQuaternion::~hkQuaternion() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
