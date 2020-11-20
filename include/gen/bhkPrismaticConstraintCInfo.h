/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKPRISMATICCONSTRAINTCINFO_H_
#define _BHKPRISMATICCONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Serialization data for bhkPrismaticConstraint.
 *         Creates a rail between two bodies that allows translation along a single
 * axis with linear limits and a motor.
 *         All three rotation axes and the remaining two translation axes are
 * fixed.
 */
struct bhkPrismaticConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkPrismaticConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkPrismaticConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkPrismaticConstraintCInfo( const bhkPrismaticConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkPrismaticConstraintCInfo & operator=( const bhkPrismaticConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
