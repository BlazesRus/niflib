/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HKQUATERNION_H_
#define _HKQUATERNION_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A quaternion as it appears in the havok objects. */
struct hkQuaternion {
	/*! Default Constructor */
	NIFLIB_API hkQuaternion();
	/*! Default Destructor */
	NIFLIB_API ~hkQuaternion();
	/*! Copy Constructor */
	NIFLIB_API hkQuaternion( const hkQuaternion & src );
	/*! Copy Operator */
	NIFLIB_API hkQuaternion & operator=( const hkQuaternion & src );
	/*! The x-coordinate. */
	float x;
	/*! The y-coordinate. */
	float y;
	/*! The z-coordinate. */
	float z;
	/*! The w-coordinate. */
	float w;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
