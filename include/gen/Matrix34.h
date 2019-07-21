/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _MATRIX34_H_
#define _MATRIX34_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A 3x4 transformation matrix. */
struct Matrix34 {
	/*! Default Constructor */
	NIFLIB_API Matrix34();
	/*! Default Destructor */
	NIFLIB_API ~Matrix34();
	/*! Copy Constructor */
	NIFLIB_API Matrix34( const Matrix34 & src );
	/*! Copy Operator */
	NIFLIB_API Matrix34 & operator=( const Matrix34 & src );
	/*! The (1,1) element. */
	float m11;
	/*! The (2,1) element. */
	float m21;
	/*! The (3,1) element. */
	float m31;
	/*! The (1,2) element. */
	float m12;
	/*! The (2,2) element. */
	float m22;
	/*! The (3,2) element. */
	float m32;
	/*! The (1,3) element. */
	float m13;
	/*! The (2,3) element. */
	float m23;
	/*! The (3,3) element. */
	float m33;
	/*! The (1,4) element. */
	float m14;
	/*! The (2,4) element. */
	float m24;
	/*! The (3,4) element. */
	float m34;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
