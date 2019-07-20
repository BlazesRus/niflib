/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXJOINTDRIVEDESC_H_
#define _NXJOINTDRIVEDESC_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NxJointDriveDesc {
	/*! Default Constructor */
	NIFLIB_API NxJointDriveDesc();
	/*! Default Destructor */
	NIFLIB_API ~NxJointDriveDesc();
	/*! Copy Constructor */
	NIFLIB_API NxJointDriveDesc( const NxJointDriveDesc & src );
	/*! Copy Operator */
	NIFLIB_API NxJointDriveDesc & operator=( const NxJointDriveDesc & src );
	NxD6JointDriveType driveType;
	float restitution;
	float spring;
	float damping;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
