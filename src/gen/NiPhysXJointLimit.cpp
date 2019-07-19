/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NiPhysXJointLimit.h"
using namespace Niflib;

//Constructor
NiPhysXJointLimit::NiPhysXJointLimit() : limitPlaneD(0.0f), limitPlaneR(0.0f) {};

//Copy Constructor
NiPhysXJointLimit::NiPhysXJointLimit( const NiPhysXJointLimit & src ) {
	*this = src;
};

//Copy Operator
NiPhysXJointLimit & NiPhysXJointLimit::operator=( const NiPhysXJointLimit & src ) {
	this->limitPlaneNormal = src.limitPlaneNormal;
	this->limitPlaneD = src.limitPlaneD;
	this->limitPlaneR = src.limitPlaneR;
	return *this;
};

//Destructor
NiPhysXJointLimit::~NiPhysXJointLimit() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
