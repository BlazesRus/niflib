/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXPLANE_H_
#define _NXPLANE_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NxPlane {
	/*! Default Constructor */
	NIFLIB_API NxPlane();
	/*! Default Destructor */
	NIFLIB_API ~NxPlane();
	/*! Copy Constructor */
	NIFLIB_API NxPlane( const NxPlane & src );
	/*! Copy Operator */
	NIFLIB_API NxPlane & operator=( const NxPlane & src );
	float val1;
	Vector3 point1;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
