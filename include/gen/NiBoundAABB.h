/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIBOUNDAABB_H_
#define _NIBOUNDAABB_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Divinity 2 specific NiBound extension. */
struct NiBoundAABB {
	/*! Default Constructor */
	NIFLIB_API NiBoundAABB();
	/*! Default Destructor */
	NIFLIB_API ~NiBoundAABB();
	/*! Copy Constructor */
	NIFLIB_API NiBoundAABB( const NiBoundAABB & src );
	/*! Copy Operator */
	NIFLIB_API NiBoundAABB & operator=( const NiBoundAABB & src );
	unsigned short numCorners;
	/*! Corners are only non-zero if Num Corners is 2. Hardcoded to 2. */
	Niflib::NifArray<2,Vector3 > corners;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
