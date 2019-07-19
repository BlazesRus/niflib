/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/PrismaticDescriptor.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Constructor
PrismaticDescriptor::PrismaticDescriptor() : minDistance(0.0f), maxDistance(0.0f), friction(0.0f) {};

//Copy Constructor
PrismaticDescriptor::PrismaticDescriptor( const PrismaticDescriptor & src ) {
	*this = src;
};

//Copy Operator
PrismaticDescriptor & PrismaticDescriptor::operator=( const PrismaticDescriptor & src ) {
	this->pivotA = src.pivotA;
	this->rotationA = src.rotationA;
	this->planeA = src.planeA;
	this->slidingA = src.slidingA;
	this->pivotB = src.pivotB;
	this->rotationB = src.rotationB;
	this->planeB = src.planeB;
	this->slidingB = src.slidingB;
	this->minDistance = src.minDistance;
	this->maxDistance = src.maxDistance;
	this->friction = src.friction;
	this->motor = src.motor;
	return *this;
};

//Destructor
PrismaticDescriptor::~PrismaticDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
