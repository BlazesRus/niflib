/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NICURVE3_H_
#define _NICURVE3_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A 3D curve made up of control points and knots. */
struct NiCurve3 {
	/*! Default Constructor */
	NIFLIB_API NiCurve3();
	/*! Default Destructor */
	NIFLIB_API ~NiCurve3();
	/*! Copy Constructor */
	NIFLIB_API NiCurve3( const NiCurve3 & src );
	/*! Copy Operator */
	NIFLIB_API NiCurve3 & operator=( const NiCurve3 & src );
	unsigned int degree;
	mutable unsigned int numControlPoints;
	vector<Vector3 > controlPoints;
	mutable unsigned int numKnots;
	vector<float > knots;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
