/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKHINGECONSTRAINTCINFO_H_
#define _BHKHINGECONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Serialization data for bhkHingeConstraint. A basic hinge with no angular limits
 * or motor.
 */
struct bhkHingeConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkHingeConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkHingeConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkHingeConstraintCInfo( const bhkHingeConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkHingeConstraintCInfo & operator=( const bhkHingeConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
