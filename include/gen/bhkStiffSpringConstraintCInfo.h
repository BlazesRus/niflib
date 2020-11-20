/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKSTIFFSPRINGCONSTRAINTCINFO_H_
#define _BHKSTIFFSPRINGCONSTRAINTCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * bhkStiffSpringConstraint serialization data. Holds two bodies at a specified
 * distance from one another.
 */
struct bhkStiffSpringConstraintCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkStiffSpringConstraintCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkStiffSpringConstraintCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkStiffSpringConstraintCInfo( const bhkStiffSpringConstraintCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkStiffSpringConstraintCInfo & operator=( const bhkStiffSpringConstraintCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
