/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BoxBV.h"
using namespace Niflib;

//Constructor
BoxBV::BoxBV() {};

//Copy Constructor
BoxBV::BoxBV( const BoxBV & src ) {
	*this = src;
};

//Copy Operator
BoxBV & BoxBV::operator=( const BoxBV & src ) {
	this->center = src.center;
	this->axis = src.axis;
	this->extent = src.extent;
	return *this;
};

//Destructor
BoxBV::~BoxBV() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
