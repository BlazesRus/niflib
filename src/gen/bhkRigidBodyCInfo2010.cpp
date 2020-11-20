/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkRigidBodyCInfo2010.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/hkQuaternion.h"
using namespace Niflib;

//Constructor
bhkRigidBodyCInfo2010::bhkRigidBodyCInfo2010() : unknownInt1((unsigned int)0), collisionResponse((hkResponseType)RESPONSE_SIMPLE_CONTACT), unused03((byte)0), processContactCallbackDelay((unsigned short)0xffff), mass(1.0f), linearDamping(0.1f), angularDamping(0.05f), timeFactor(1.0f), gravityFactor(1.0f), friction(0.5f), rollingFrictionMultiplier(0.0f), restitution(0.4f), maxLinearVelocity(104.4f), maxAngularVelocity(31.57f), penetrationDepth(0.15f), motionSystem((hkMotionType)MO_SYS_DYNAMIC), enableDeactivation(1), solverDeactivation((hkSolverDeactivation)SOLVER_DEACTIVATION_OFF), qualityType((hkQualityType)MO_QUAL_FIXED), autoRemoveLevel((byte)0), responseModifierFlags((byte)0), numShapeKeysInContactPoint((byte)3), forceCollidedOntoPpu(false) {};

//Copy Constructor
bhkRigidBodyCInfo2010::bhkRigidBodyCInfo2010( const bhkRigidBodyCInfo2010 & src ) {
	*this = src;
};

//Copy Operator
bhkRigidBodyCInfo2010 & bhkRigidBodyCInfo2010::operator=( const bhkRigidBodyCInfo2010 & src ) {
	this->unused01 = src.unused01;
	this->havokFilter = src.havokFilter;
	this->unused02 = src.unused02;
	this->unknownInt1 = src.unknownInt1;
	this->collisionResponse = src.collisionResponse;
	this->unused03 = src.unused03;
	this->processContactCallbackDelay = src.processContactCallbackDelay;
	this->translation = src.translation;
	this->rotation = src.rotation;
	this->linearVelocity = src.linearVelocity;
	this->angularVelocity = src.angularVelocity;
	this->inertiaTensor = src.inertiaTensor;
	this->center = src.center;
	this->mass = src.mass;
	this->linearDamping = src.linearDamping;
	this->angularDamping = src.angularDamping;
	this->timeFactor = src.timeFactor;
	this->gravityFactor = src.gravityFactor;
	this->friction = src.friction;
	this->rollingFrictionMultiplier = src.rollingFrictionMultiplier;
	this->restitution = src.restitution;
	this->maxLinearVelocity = src.maxLinearVelocity;
	this->maxAngularVelocity = src.maxAngularVelocity;
	this->penetrationDepth = src.penetrationDepth;
	this->motionSystem = src.motionSystem;
	this->enableDeactivation = src.enableDeactivation;
	this->solverDeactivation = src.solverDeactivation;
	this->qualityType = src.qualityType;
	this->autoRemoveLevel = src.autoRemoveLevel;
	this->responseModifierFlags = src.responseModifierFlags;
	this->numShapeKeysInContactPoint = src.numShapeKeysInContactPoint;
	this->forceCollidedOntoPpu = src.forceCollidedOntoPpu;
	this->unused04 = src.unused04;
	return *this;
};

//Destructor
bhkRigidBodyCInfo2010::~bhkRigidBodyCInfo2010() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
