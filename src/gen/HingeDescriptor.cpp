/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/HingeDescriptor.h"
using namespace Niflib;

//Constructor
HingeDescriptor::HingeDescriptor() {};

//Copy Constructor
HingeDescriptor::HingeDescriptor( const HingeDescriptor & src ) {
	*this = src;
};

//Copy Operator
HingeDescriptor & HingeDescriptor::operator=( const HingeDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->perp2AxleInA1 = src.perp2AxleInA1;
	this->perp2AxleInA2 = src.perp2AxleInA2;
	this->pivotB = src.pivotB;
	this->axleB = src.axleB;
	this->axleA = src.axleA;
	this->perp2AxleInB1 = src.perp2AxleInB1;
	this->perp2AxleInB2 = src.perp2AxleInB2;
	return *this;
};

//Destructor
HingeDescriptor::~HingeDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
