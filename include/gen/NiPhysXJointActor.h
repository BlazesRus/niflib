/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIPHYSXJOINTACTOR_H_
#define _NIPHYSXJOINTACTOR_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPhysXActorDesc;

struct NiPhysXJointActor {
	/*! Default Constructor */
	NIFLIB_API NiPhysXJointActor();
	/*! Default Destructor */
	NIFLIB_API ~NiPhysXJointActor();
	/*! Copy Constructor */
	NIFLIB_API NiPhysXJointActor( const NiPhysXJointActor & src );
	/*! Copy Operator */
	NIFLIB_API NiPhysXJointActor & operator=( const NiPhysXJointActor & src );
	Ref<NiPhysXActorDesc > actor;
	Vector3 localNormal;
	Vector3 localAxis;
	Vector3 localAnchor;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
