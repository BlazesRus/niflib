/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkRigidBodyCInfo550_660.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
bhkRigidBodyCInfo550_660::bhkRigidBodyCInfo550_660() : collisionResponse((hkResponseType)RESPONSE_SIMPLE_CONTACT), unused03((byte)0), processContactCallbackDelay((unsigned short)0xffff), mass(1.0f), linearDamping(0.1f), angularDamping(0.05f), friction(0.5f), restitution(0.4f), maxLinearVelocity(104.4f), maxAngularVelocity(31.57f), penetrationDepth(0.15f), motionSystem((hkMotionType)MO_SYS_DYNAMIC), deactivatorType((hkDeactivatorType)DEACTIVATOR_NEVER), solverDeactivation((hkSolverDeactivation)SOLVER_DEACTIVATION_OFF), qualityType((hkQualityType)MO_QUAL_FIXED) {};

//Copy Constructor
bhkRigidBodyCInfo550_660::bhkRigidBodyCInfo550_660( const bhkRigidBodyCInfo550_660 & src ) {
	*this = src;
};

//Copy Operator
bhkRigidBodyCInfo550_660 & bhkRigidBodyCInfo550_660::operator=( const bhkRigidBodyCInfo550_660 & src ) {
	this->unused01 = src.unused01;
	this->havokFilter = src.havokFilter;
	this->unused02 = src.unused02;
	this->collisionResponse = src.collisionResponse;
	this->unused03 = src.unused03;
	this->processContactCallbackDelay = src.processContactCallbackDelay;
	this->unused04 = src.unused04;
	this->translation = src.translation;
	this->rotation = src.rotation;
	this->linearVelocity = src.linearVelocity;
	this->angularVelocity = src.angularVelocity;
	this->inertiaTensor = src.inertiaTensor;
	this->center = src.center;
	this->mass = src.mass;
	this->linearDamping = src.linearDamping;
	this->angularDamping = src.angularDamping;
	this->friction = src.friction;
	this->restitution = src.restitution;
	this->maxLinearVelocity = src.maxLinearVelocity;
	this->maxAngularVelocity = src.maxAngularVelocity;
	this->penetrationDepth = src.penetrationDepth;
	this->motionSystem = src.motionSystem;
	this->deactivatorType = src.deactivatorType;
	this->solverDeactivation = src.solverDeactivation;
	this->qualityType = src.qualityType;
	this->unused05 = src.unused05;
	return *this;
};

//Destructor
bhkRigidBodyCInfo550_660::~bhkRigidBodyCInfo550_660() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
