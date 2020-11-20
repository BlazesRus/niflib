/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkRigidBodyCInfo2014.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
bhkRigidBodyCInfo2014::bhkRigidBodyCInfo2014() : mass(1.0f), linearDamping(0.1f), angularDamping(0.05f), gravityFactor(1.0f), friction(0.5f), rollingFrictionMultiplier(0.0f), restitution(0.4f), maxLinearVelocity(104.4f), maxAngularVelocity(31.57f), motionSystem((hkMotionType)MO_SYS_DYNAMIC), enableDeactivation(1), solverDeactivation((hkSolverDeactivation)SOLVER_DEACTIVATION_OFF), unused03((byte)0), penetrationDepth(0.15f), timeFactor(0.0f), collisionResponse((hkResponseType)0), unused05((byte)0), processContactCallbackDelay3((unsigned short)0xffff), qualityType((hkQualityType)MO_QUAL_FIXED), autoRemoveLevel((byte)0), responseModifierFlags((byte)0), numShapeKeysInContactPoint((byte)3), forceCollidedOntoPpu(false) {};

//Copy Constructor
bhkRigidBodyCInfo2014::bhkRigidBodyCInfo2014( const bhkRigidBodyCInfo2014 & src ) {
	*this = src;
};

//Copy Operator
bhkRigidBodyCInfo2014 & bhkRigidBodyCInfo2014::operator=( const bhkRigidBodyCInfo2014 & src ) {
	this->unused01 = src.unused01;
	this->havokFilter = src.havokFilter;
	this->unused02 = src.unused02;
	this->translation = src.translation;
	this->rotation = src.rotation;
	this->linearVelocity = src.linearVelocity;
	this->angularVelocity = src.angularVelocity;
	this->inertiaTensor = src.inertiaTensor;
	this->center = src.center;
	this->mass = src.mass;
	this->linearDamping = src.linearDamping;
	this->angularDamping = src.angularDamping;
	this->gravityFactor = src.gravityFactor;
	this->friction = src.friction;
	this->rollingFrictionMultiplier = src.rollingFrictionMultiplier;
	this->restitution = src.restitution;
	this->maxLinearVelocity = src.maxLinearVelocity;
	this->maxAngularVelocity = src.maxAngularVelocity;
	this->motionSystem = src.motionSystem;
	this->enableDeactivation = src.enableDeactivation;
	this->solverDeactivation = src.solverDeactivation;
	this->unused03 = src.unused03;
	this->penetrationDepth = src.penetrationDepth;
	this->timeFactor = src.timeFactor;
	this->unused04 = src.unused04;
	this->collisionResponse = src.collisionResponse;
	this->unused05 = src.unused05;
	this->processContactCallbackDelay3 = src.processContactCallbackDelay3;
	this->qualityType = src.qualityType;
	this->autoRemoveLevel = src.autoRemoveLevel;
	this->responseModifierFlags = src.responseModifierFlags;
	this->numShapeKeysInContactPoint = src.numShapeKeysInContactPoint;
	this->forceCollidedOntoPpu = src.forceCollidedOntoPpu;
	this->unused06 = src.unused06;
	return *this;
};

//Destructor
bhkRigidBodyCInfo2014::~bhkRigidBodyCInfo2014() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
