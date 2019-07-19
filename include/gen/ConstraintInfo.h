/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _CONSTRAINTINFO_H_
#define _CONSTRAINTINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Two Vector4 for pivot in A and B. */
struct ConstraintInfo {
	/*! Default Constructor */
	NIFLIB_API ConstraintInfo();
	/*! Default Destructor */
	NIFLIB_API ~ConstraintInfo();
	/*! Copy Constructor */
	NIFLIB_API ConstraintInfo( const ConstraintInfo & src );
	/*! Copy Operator */
	NIFLIB_API ConstraintInfo & operator=( const ConstraintInfo & src );
	Vector4 pivotInA;
	Vector4 pivotInB;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
