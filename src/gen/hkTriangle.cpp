/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/hkTriangle.h"
using namespace Niflib;

//Constructor
hkTriangle::hkTriangle() : weldingInfo((unsigned short)0) {};

//Copy Constructor
hkTriangle::hkTriangle( const hkTriangle & src ) {
	*this = src;
};

//Copy Operator
hkTriangle & hkTriangle::operator=( const hkTriangle & src ) {
	this->triangle = src.triangle;
	this->weldingInfo = src.weldingInfo;
	this->normal = src.normal;
	return *this;
};

//Destructor
hkTriangle::~hkTriangle() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
