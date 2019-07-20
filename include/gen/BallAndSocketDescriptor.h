/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BALLANDSOCKETDESCRIPTOR_H_
#define _BALLANDSOCKETDESCRIPTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


struct BallAndSocketDescriptor {
	/*! Default Constructor */
	NIFLIB_API BallAndSocketDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~BallAndSocketDescriptor();
	/*! Copy Constructor */
	NIFLIB_API BallAndSocketDescriptor( const BallAndSocketDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API BallAndSocketDescriptor & operator=( const BallAndSocketDescriptor & src );
	/*! Pivot point in the local space of entity A. */
	Vector4 pivotA;
	/*! Pivot point in the local space of entity B. */
	Vector4 pivotB;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
