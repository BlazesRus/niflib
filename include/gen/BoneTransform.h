/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BONETRANSFORM_H_
#define _BONETRANSFORM_H_

#include "../NIF_IO.h"

// Include structures
#include "hkQuaternion.h"
namespace Niflib {


/*! Transformation data for the bone at this index in bhkPoseArray. */
struct BoneTransform {
	/*! Default Constructor */
	NIFLIB_API BoneTransform();
	/*! Default Destructor */
	NIFLIB_API ~BoneTransform();
	/*! Copy Constructor */
	NIFLIB_API BoneTransform( const BoneTransform & src );
	/*! Copy Operator */
	NIFLIB_API BoneTransform & operator=( const BoneTransform & src );
	Vector3 translation;
	hkQuaternion rotation;
	Vector3 scale;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
