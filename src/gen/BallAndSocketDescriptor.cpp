/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/BallAndSocketDescriptor.h"
using namespace Niflib;

//Constructor
BallAndSocketDescriptor::BallAndSocketDescriptor() {};

//Copy Constructor
BallAndSocketDescriptor::BallAndSocketDescriptor( const BallAndSocketDescriptor & src ) {
	*this = src;
};

//Copy Operator
BallAndSocketDescriptor & BallAndSocketDescriptor::operator=( const BallAndSocketDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->pivotB = src.pivotB;
	return *this;
};

//Destructor
BallAndSocketDescriptor::~BallAndSocketDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
