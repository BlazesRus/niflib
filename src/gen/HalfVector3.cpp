/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HalfVector3.h"
using namespace Niflib;

//Constructor
HalfVector3::HalfVector3() : x((hfloat)0), y((hfloat)0), z((hfloat)0) {};

//Copy Constructor
HalfVector3::HalfVector3( const HalfVector3 & src ) {
	*this = src;
};

//Copy Operator
HalfVector3 & HalfVector3::operator=( const HalfVector3 & src ) {
	this->x = src.x;
	this->y = src.y;
	this->z = src.z;
	return *this;
};

//Destructor
HalfVector3::~HalfVector3() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
