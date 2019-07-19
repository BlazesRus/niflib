/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Constructor
MotorDescriptor::MotorDescriptor() : type((MotorType)MOTOR_NONE) {};

//Copy Constructor
MotorDescriptor::MotorDescriptor( const MotorDescriptor & src ) {
	*this = src;
};

//Copy Operator
MotorDescriptor & MotorDescriptor::operator=( const MotorDescriptor & src ) {
	this->type = src.type;
	this->positionMotor = src.positionMotor;
	this->velocityMotor = src.velocityMotor;
	this->springDamperMotor = src.springDamperMotor;
	return *this;
};

//Destructor
MotorDescriptor::~MotorDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
