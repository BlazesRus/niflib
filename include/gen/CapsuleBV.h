/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _CAPSULEBV_H_
#define _CAPSULEBV_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Capsule Bounding Volume */
struct CapsuleBV {
	/*! Default Constructor */
	NIFLIB_API CapsuleBV();
	/*! Default Destructor */
	NIFLIB_API ~CapsuleBV();
	/*! Copy Constructor */
	NIFLIB_API CapsuleBV( const CapsuleBV & src );
	/*! Copy Operator */
	NIFLIB_API CapsuleBV & operator=( const CapsuleBV & src );
	Vector3 center;
	Vector3 origin;
	float extent;
	float radius;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
