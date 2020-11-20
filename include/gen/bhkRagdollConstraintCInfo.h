/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKRAGDOLLCONSTRAINTCINFO_H_
#define _BHKRAGDOLLCONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Serialization data for bhkRagdollConstraint.
 *         The area of movement can be represented as a main cone + 2 orthogonal
 * cones which may subtract from the main cone volume depending on limits.
 */
struct bhkRagdollConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkRagdollConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkRagdollConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkRagdollConstraintCInfo( const bhkRagdollConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkRagdollConstraintCInfo & operator=( const bhkRagdollConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
