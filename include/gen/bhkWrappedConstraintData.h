/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKWRAPPEDCONSTRAINTDATA_H_
#define _BHKWRAPPEDCONSTRAINTDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! A constraint wrapper for polymorphic hkpConstraintData serialization. */
struct bhkWrappedConstraintData {
	/*! Default Constructor */
	NIFLIB_API bhkWrappedConstraintData();
	/*! Default Destructor */
	NIFLIB_API ~bhkWrappedConstraintData();
	/*! Copy Constructor */
	NIFLIB_API bhkWrappedConstraintData( const bhkWrappedConstraintData & src );
	/*! Copy Operator */
	NIFLIB_API bhkWrappedConstraintData & operator=( const bhkWrappedConstraintData & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
