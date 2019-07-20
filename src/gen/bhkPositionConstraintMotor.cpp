/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkPositionConstraintMotor.h"
using namespace Niflib;

//Constructor
bhkPositionConstraintMotor::bhkPositionConstraintMotor() : minForce(-1000000.0f), maxForce(1000000.0f), tau(0.8f), damping(1.0f), proportionalRecoveryVelocity(2.0f), constantRecoveryVelocity(1.0f), motorEnabled(0) {};

//Copy Constructor
bhkPositionConstraintMotor::bhkPositionConstraintMotor( const bhkPositionConstraintMotor & src ) {
	*this = src;
};

//Copy Operator
bhkPositionConstraintMotor & bhkPositionConstraintMotor::operator=( const bhkPositionConstraintMotor & src ) {
	this->minForce = src.minForce;
	this->maxForce = src.maxForce;
	this->tau = src.tau;
	this->damping = src.damping;
	this->proportionalRecoveryVelocity = src.proportionalRecoveryVelocity;
	this->constantRecoveryVelocity = src.constantRecoveryVelocity;
	this->motorEnabled = src.motorEnabled;
	return *this;
};

//Destructor
bhkPositionConstraintMotor::~bhkPositionConstraintMotor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
