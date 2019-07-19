/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/NxJointDriveDesc.h"
using namespace Niflib;

//Constructor
NxJointDriveDesc::NxJointDriveDesc() : driveType((NxD6JointDriveType)0), restitution(0.0f), spring(0.0f), damping(0.0f) {};

//Copy Constructor
NxJointDriveDesc::NxJointDriveDesc( const NxJointDriveDesc & src ) {
	*this = src;
};

//Copy Operator
NxJointDriveDesc & NxJointDriveDesc::operator=( const NxJointDriveDesc & src ) {
	this->driveType = src.driveType;
	this->restitution = src.restitution;
	this->spring = src.spring;
	this->damping = src.damping;
	return *this;
};

//Destructor
NxJointDriveDesc::~NxJointDriveDesc() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
