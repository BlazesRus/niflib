/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIPLANE_H_
#define _NIPLANE_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A plane. */
struct NiPlane {
	/*! Default Constructor */
	NIFLIB_API NiPlane();
	/*! Default Destructor */
	NIFLIB_API ~NiPlane();
	/*! Copy Constructor */
	NIFLIB_API NiPlane( const NiPlane & src );
	/*! Copy Operator */
	NIFLIB_API NiPlane & operator=( const NiPlane & src );
	/*! The plane normal. */
	Vector3 normal;
	/*! The plane constant. */
	float constant;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
