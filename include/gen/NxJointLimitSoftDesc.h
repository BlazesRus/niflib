/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXJOINTLIMITSOFTDESC_H_
#define _NXJOINTLIMITSOFTDESC_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NxJointLimitSoftDesc {
	/*! Default Constructor */
	NIFLIB_API NxJointLimitSoftDesc();
	/*! Default Destructor */
	NIFLIB_API ~NxJointLimitSoftDesc();
	/*! Copy Constructor */
	NIFLIB_API NxJointLimitSoftDesc( const NxJointLimitSoftDesc & src );
	/*! Copy Operator */
	NIFLIB_API NxJointLimitSoftDesc & operator=( const NxJointLimitSoftDesc & src );
	float value;
	float restitution;
	float spring;
	float damping;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
