/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIPHYSXJOINTLIMIT_H_
#define _NIPHYSXJOINTLIMIT_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NiPhysXJointLimit {
	/*! Default Constructor */
	NIFLIB_API NiPhysXJointLimit();
	/*! Default Destructor */
	NIFLIB_API ~NiPhysXJointLimit();
	/*! Copy Constructor */
	NIFLIB_API NiPhysXJointLimit( const NiPhysXJointLimit & src );
	/*! Copy Operator */
	NIFLIB_API NiPhysXJointLimit & operator=( const NiPhysXJointLimit & src );
	Vector3 limitPlaneNormal;
	float limitPlaneD;
	float limitPlaneR;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
