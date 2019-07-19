/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _MALLEABLEDESCRIPTOR_H_
#define _MALLEABLEDESCRIPTOR_H_

#include "../NIF_IO.h"

// Include structures
#include "BallAndSocketDescriptor.h"
#include "HingeDescriptor.h"
#include "LimitedHingeDescriptor.h"
#include "PrismaticDescriptor.h"
#include "RagdollDescriptor.h"
#include "StiffSpringDescriptor.h"
namespace Niflib {

// Forward define of referenced NIF objects
class bhkEntity;

struct MalleableDescriptor {
	/*! Default Constructor */
	NIFLIB_API MalleableDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~MalleableDescriptor();
	/*! Copy Constructor */
	NIFLIB_API MalleableDescriptor( const MalleableDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API MalleableDescriptor & operator=( const MalleableDescriptor & src );
	/*! Type of constraint. */
	hkConstraintType type;
	/*! Always 2 (Hardcoded). Number of bodies affected by this constraint. */
	unsigned int numEntities;
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
	float tau;
	float damping;
	float strength;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
