/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _INERTIAMATRIX_H_
#define _INERTIAMATRIX_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! An inertia matrix. */
struct InertiaMatrix {
	/*! Default Constructor */
	NIFLIB_API InertiaMatrix();
	/*! Default Destructor */
	NIFLIB_API ~InertiaMatrix();
	/*! Copy Constructor */
	NIFLIB_API InertiaMatrix( const InertiaMatrix & src );
	/*! Copy Operator */
	NIFLIB_API InertiaMatrix & operator=( const InertiaMatrix & src );
	float m11;
	float m12;
	float m13;
	/*! Zero */
	float m14;
	float m21;
	float m22;
	float m23;
	/*! Zero */
	float m24;
	float m31;
	float m32;
	float m33;
	/*! Zero */
	float m34;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
