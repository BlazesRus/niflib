/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXStateName.h"
using namespace Niflib;

//Constructor
PhysXStateName::PhysXStateName() : index((unsigned int)0) {};

//Copy Constructor
PhysXStateName::PhysXStateName( const PhysXStateName & src ) {
	*this = src;
};

//Copy Operator
PhysXStateName & PhysXStateName::operator=( const PhysXStateName & src ) {
	this->name = src.name;
	this->index = src.index;
	return *this;
};

//Destructor
PhysXStateName::~PhysXStateName() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
