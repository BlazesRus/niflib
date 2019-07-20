/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PhysXBodyStoredVels.h"
using namespace Niflib;

//Constructor
PhysXBodyStoredVels::PhysXBodyStoredVels() : sleep(false) {};

//Copy Constructor
PhysXBodyStoredVels::PhysXBodyStoredVels( const PhysXBodyStoredVels & src ) {
	*this = src;
};

//Copy Operator
PhysXBodyStoredVels & PhysXBodyStoredVels::operator=( const PhysXBodyStoredVels & src ) {
	this->linearVelocity = src.linearVelocity;
	this->angularVelocity = src.angularVelocity;
	this->sleep = src.sleep;
	return *this;
};

//Destructor
PhysXBodyStoredVels::~PhysXBodyStoredVels() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
