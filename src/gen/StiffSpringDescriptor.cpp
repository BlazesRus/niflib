/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/StiffSpringDescriptor.h"
using namespace Niflib;

//Constructor
StiffSpringDescriptor::StiffSpringDescriptor() : length(0.0f) {};

//Copy Constructor
StiffSpringDescriptor::StiffSpringDescriptor( const StiffSpringDescriptor & src ) {
	*this = src;
};

//Copy Operator
StiffSpringDescriptor & StiffSpringDescriptor::operator=( const StiffSpringDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->pivotB = src.pivotB;
	this->length = src.length;
	return *this;
};

//Destructor
StiffSpringDescriptor::~StiffSpringDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
