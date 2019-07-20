/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiPhysXJointActor.h"
#include "../../include/obj/NiPhysXActorDesc.h"
using namespace Niflib;

//Constructor
NiPhysXJointActor::NiPhysXJointActor() : actor(NULL) {};

//Copy Constructor
NiPhysXJointActor::NiPhysXJointActor( const NiPhysXJointActor & src ) {
	*this = src;
};

//Copy Operator
NiPhysXJointActor & NiPhysXJointActor::operator=( const NiPhysXJointActor & src ) {
	this->actor = src.actor;
	this->localNormal = src.localNormal;
	this->localAxis = src.localAxis;
	this->localAnchor = src.localAnchor;
	return *this;
};

//Destructor
NiPhysXJointActor::~NiPhysXJointActor() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
