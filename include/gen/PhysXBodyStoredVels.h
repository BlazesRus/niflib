/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXBODYSTOREDVELS_H_
#define _PHYSXBODYSTOREDVELS_H_

#include "../NIF_IO.h"

namespace Niflib {


struct PhysXBodyStoredVels {
	/*! Default Constructor */
	NIFLIB_API PhysXBodyStoredVels();
	/*! Default Destructor */
	NIFLIB_API ~PhysXBodyStoredVels();
	/*! Copy Constructor */
	NIFLIB_API PhysXBodyStoredVels( const PhysXBodyStoredVels & src );
	/*! Copy Operator */
	NIFLIB_API PhysXBodyStoredVels & operator=( const PhysXBodyStoredVels & src );
	Vector3 linearVelocity;
	Vector3 angularVelocity;
	bool sleep;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
