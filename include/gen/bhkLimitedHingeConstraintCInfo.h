/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKLIMITEDHINGECONSTRAINTCINFO_H_
#define _BHKLIMITEDHINGECONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Serialization data for bhkLimitedHingeConstraint.
 *         This constraint allows rotation about a specified axis, limited by
 * specified boundaries.
 */
struct bhkLimitedHingeConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkLimitedHingeConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkLimitedHingeConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkLimitedHingeConstraintCInfo( const bhkLimitedHingeConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkLimitedHingeConstraintCInfo & operator=( const bhkLimitedHingeConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
