/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
using namespace Niflib;

//Constructor
bhkSpringDamperConstraintMotor::bhkSpringDamperConstraintMotor() : minForce(-1000000.0f), maxForce(1000000.0f), springConstant(0.0f), springDamping(0.0f), motorEnabled(0) {};

//Copy Constructor
bhkSpringDamperConstraintMotor::bhkSpringDamperConstraintMotor( const bhkSpringDamperConstraintMotor & src ) {
	*this = src;
};

//Copy Operator
bhkSpringDamperConstraintMotor & bhkSpringDamperConstraintMotor::operator=( const bhkSpringDamperConstraintMotor & src ) {
	this->minForce = src.minForce;
	this->maxForce = src.maxForce;
	this->springConstant = src.springConstant;
	this->springDamping = src.springDamping;
	this->motorEnabled = src.motorEnabled;
	return *this;
};

//Destructor
bhkSpringDamperConstraintMotor::~bhkSpringDamperConstraintMotor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
