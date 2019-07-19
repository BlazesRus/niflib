/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _CONSTRAINTDATA_H_
#define _CONSTRAINTDATA_H_

#include "../NIF_IO.h"

// Include structures
#include "BallAndSocketDescriptor.h"
#include "HingeDescriptor.h"
#include "LimitedHingeDescriptor.h"
#include "PrismaticDescriptor.h"
#include "RagdollDescriptor.h"
#include "StiffSpringDescriptor.h"
#include "MalleableDescriptor.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkEntity;

struct ConstraintData {
	/*! Default Constructor */
	NIFLIB_API ConstraintData();
	/*! Default Destructor */
	NIFLIB_API ~ConstraintData();
	/*! Copy Constructor */
	NIFLIB_API ConstraintData( const ConstraintData & src );
	/*! Copy Operator */
	NIFLIB_API ConstraintData & operator=( const ConstraintData & src );
	/*! Type of constraint. */
	hkConstraintType type;
	/*! Always 2 (Hardcoded). Number of bodies affected by this constraint. */
	unsigned int numEntities2;
	/*! Usually NONE. The entity affected by this constraint. */
	bhkEntity * entityA;
	/*! Usually NONE. The entity affected by this constraint. */
	bhkEntity * entityB;
	/*! Usually 1. Higher values indicate higher priority of this constraint? */
	unsigned int priority;
	BallAndSocketDescriptor ballAndSocket;
	HingeDescriptor hinge;
	LimitedHingeDescriptor limitedHinge;
	PrismaticDescriptor prismatic;
	RagdollDescriptor ragdoll;
	StiffSpringDescriptor stiffSpring;
	MalleableDescriptor malleable;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
