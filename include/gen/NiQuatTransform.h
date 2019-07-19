/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NIQUATTRANSFORM_H_
#define _NIQUATTRANSFORM_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NiQuatTransform {
	/*! Default Constructor */
	NIFLIB_API NiQuatTransform();
	/*! Default Destructor */
	NIFLIB_API ~NiQuatTransform();
	/*! Copy Constructor */
	NIFLIB_API NiQuatTransform( const NiQuatTransform & src );
	/*! Copy Operator */
	NIFLIB_API NiQuatTransform & operator=( const NiQuatTransform & src );
	Vector3 translation;
	Quaternion rotation;
	float scale;
	/*! Whether each transform component is valid. */
	Niflib::NifArray<3,bool > trsValid;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
