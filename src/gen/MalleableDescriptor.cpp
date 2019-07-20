/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/MalleableDescriptor.h"
#include "../../include/gen/BallAndSocketDescriptor.h"
#include "../../include/gen/HingeDescriptor.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/PrismaticDescriptor.h"
#include "../../include/gen/RagdollDescriptor.h"
#include "../../include/gen/StiffSpringDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
#include "../../include/obj/bhkEntity.h"
using namespace Niflib;

//Constructor
MalleableDescriptor::MalleableDescriptor() : type((hkConstraintType)0), numEntities((unsigned int)2), entityA(NULL), entityB(NULL), priority((unsigned int)1), tau(0.0f), damping(0.0f), strength(0.0f) {};

//Copy Constructor
MalleableDescriptor::MalleableDescriptor( const MalleableDescriptor & src ) {
	*this = src;
};

//Copy Operator
MalleableDescriptor & MalleableDescriptor::operator=( const MalleableDescriptor & src ) {
	this->type = src.type;
	this->numEntities = src.numEntities;
	this->entityA = src.entityA;
	this->entityB = src.entityB;
	this->priority = src.priority;
	this->ballAndSocket = src.ballAndSocket;
	this->hinge = src.hinge;
	this->limitedHinge = src.limitedHinge;
	this->prismatic = src.prismatic;
	this->ragdoll = src.ragdoll;
	this->stiffSpring = src.stiffSpring;
	this->tau = src.tau;
	this->damping = src.damping;
	this->strength = src.strength;
	return *this;
};

//Destructor
MalleableDescriptor::~MalleableDescriptor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
