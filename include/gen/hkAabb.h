/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HKAABB_H_
#define _HKAABB_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Havok AABB using min/max coordinates instead of center/half extents. */
struct hkAabb {
	/*! Default Constructor */
	NIFLIB_API hkAabb();
	/*! Default Destructor */
	NIFLIB_API ~hkAabb();
	/*! Copy Constructor */
	NIFLIB_API hkAabb( const hkAabb & src );
	/*! Copy Operator */
	NIFLIB_API hkAabb & operator=( const hkAabb & src );
	/*! Coordinates of the corner with the lowest numerical values. */
	Vector4 min;
	/*! Coordinates of the corner with the highest numerical values. */
	Vector4 max;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
