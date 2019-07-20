/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCMSDTRANSFORM_H_
#define _BHKCMSDTRANSFORM_H_

#include "../NIF_IO.h"

// Include structures
#include "hkQuaternion.h"
namespace Niflib {


/*! A set of transformation data: translation and rotation */
struct bhkCMSDTransform {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDTransform();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDTransform();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDTransform( const bhkCMSDTransform & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDTransform & operator=( const bhkCMSDTransform & src );
	/*! A vector that moves the chunk by the specified amount. W is not used. */
	Vector4 translation;
	/*! Rotation. Reference point for rotation is bhkRigidBody translation. */
	hkQuaternion rotation;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
