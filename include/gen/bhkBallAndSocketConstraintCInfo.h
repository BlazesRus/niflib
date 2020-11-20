/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKBALLANDSOCKETCONSTRAINTCINFO_H_
#define _BHKBALLANDSOCKETCONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Serialization data for bhkBallAndSocketConstraint.
 *         Point-to-point constraint that attempts to keep the pivot point of two
 * bodies in the same space.
 */
struct bhkBallAndSocketConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkBallAndSocketConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkBallAndSocketConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkBallAndSocketConstraintCInfo( const bhkBallAndSocketConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkBallAndSocketConstraintCInfo & operator=( const bhkBallAndSocketConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
