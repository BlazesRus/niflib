/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Constructor
bhkVelocityConstraintMotor::bhkVelocityConstraintMotor() : minForce(-1000000.0f), maxForce(1000000.0f), tau(0.0f), targetVelocity(0.0f), useVelocityTarget(0), motorEnabled(0) {};

//Copy Constructor
bhkVelocityConstraintMotor::bhkVelocityConstraintMotor( const bhkVelocityConstraintMotor & src ) {
	*this = src;
};

//Copy Operator
bhkVelocityConstraintMotor & bhkVelocityConstraintMotor::operator=( const bhkVelocityConstraintMotor & src ) {
	this->minForce = src.minForce;
	this->maxForce = src.maxForce;
	this->tau = src.tau;
	this->targetVelocity = src.targetVelocity;
	this->useVelocityTarget = src.useVelocityTarget;
	this->motorEnabled = src.motorEnabled;
	return *this;
};

//Destructor
bhkVelocityConstraintMotor::~bhkVelocityConstraintMotor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
