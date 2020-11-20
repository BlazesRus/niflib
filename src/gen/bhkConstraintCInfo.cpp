/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#include "../../include/gen/bhkConstraintCInfo.h"
#include "../../include/obj/bhkEntity.h"
using namespace Niflib;

//Constructor
bhkConstraintCInfo::bhkConstraintCInfo() : numEntities((unsigned int)2), entityA(NULL), entityB(NULL), priority((ConstraintPriority)PRIORITY_PSI) {};

//Copy Constructor
bhkConstraintCInfo::bhkConstraintCInfo( const bhkConstraintCInfo & src ) {
	*this = src;
};

//Copy Operator
bhkConstraintCInfo & bhkConstraintCInfo::operator=( const bhkConstraintCInfo & src ) {
	this->numEntities = src.numEntities;
	this->entityA = src.entityA;
	this->entityB = src.entityB;
	this->priority = src.priority;
	return *this;
};

//Destructor
bhkConstraintCInfo::~bhkConstraintCInfo() {};

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
