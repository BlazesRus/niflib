/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCONSTRAINTMOTORCINFO_H_
#define _BHKCONSTRAINTMOTORCINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * hkConstraintCinfo::SaveMotor(). Not a Bethesda extension of hkpConstraintMotor,
 * but a wrapper for its serialization function.
 */
struct bhkConstraintMotorCInfo {
	/*! Default Constructor */
	NIFLIB_API bhkConstraintMotorCInfo();
	/*! Default Destructor */
	NIFLIB_API ~bhkConstraintMotorCInfo();
	/*! Copy Constructor */
	NIFLIB_API bhkConstraintMotorCInfo( const bhkConstraintMotorCInfo & src );
	/*! Copy Operator */
	NIFLIB_API bhkConstraintMotorCInfo & operator=( const bhkConstraintMotorCInfo & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
