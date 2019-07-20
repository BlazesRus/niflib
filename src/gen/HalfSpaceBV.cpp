/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HalfSpaceBV.h"
#include "../../include/gen/NiPlane.h"
using namespace Niflib;

//Constructor
HalfSpaceBV::HalfSpaceBV() {};

//Copy Constructor
HalfSpaceBV::HalfSpaceBV( const HalfSpaceBV & src ) {
	*this = src;
};

//Copy Operator
HalfSpaceBV & HalfSpaceBV::operator=( const HalfSpaceBV & src ) {
	this->plane = src.plane;
	this->center = src.center;
	return *this;
};

//Destructor
HalfSpaceBV::~HalfSpaceBV() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
