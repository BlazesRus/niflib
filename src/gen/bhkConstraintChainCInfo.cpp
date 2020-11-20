/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkConstraintChainCInfo.h"
#include "../../include/gen/bhkConstraintCInfo.h"
#include "../../include/obj/bhkEntity.h"
#include "../../include/obj/bhkRigidBody.h"
using namespace Niflib;

//Constructor
bhkConstraintChainCInfo::bhkConstraintChainCInfo() : numChainedEntities((unsigned int)0) {};

//Copy Constructor
bhkConstraintChainCInfo::bhkConstraintChainCInfo( const bhkConstraintChainCInfo & src ) {
	*this = src;
};

//Copy Operator
bhkConstraintChainCInfo & bhkConstraintChainCInfo::operator=( const bhkConstraintChainCInfo & src ) {
	this->numChainedEntities = src.numChainedEntities;
	this->chainedEntities = src.chainedEntities;
	this->constraintInfo = src.constraintInfo;
	return *this;
};

//Destructor
bhkConstraintChainCInfo::~bhkConstraintChainCInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
