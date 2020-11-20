/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKMALLEABLECONSTRAINTCINFO_H_
#define _BHKMALLEABLECONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * bhkMalleableConstraint serialization data. A constraint wrapper used to soften
 * or harden constraints.
 */
struct bhkMalleableConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkMalleableConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkMalleableConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkMalleableConstraintCInfo( const bhkMalleableConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkMalleableConstraintCInfo & operator=( const bhkMalleableConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
