/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NITRANSFORM_H_
#define _NITRANSFORM_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NiTransform {
	/*! Default Constructor */
	NIFLIB_API NiTransform();
	/*! Default Destructor */
	NIFLIB_API ~NiTransform();
	/*! Copy Constructor */
	NIFLIB_API NiTransform( const NiTransform & src );
	/*! Copy Operator */
	NIFLIB_API NiTransform & operator=( const NiTransform & src );
	/*! The rotation part of the transformation matrix. */
	Matrix33 rotation;
	/*! The translation vector. */
	Vector3 translation;
	/*! Scaling part (only uniform scaling is supported). */
	float scale;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
