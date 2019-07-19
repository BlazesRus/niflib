/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKVELOCITYCONSTRAINTMOTOR_H_
#define _BHKVELOCITYCONSTRAINTMOTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


struct bhkVelocityConstraintMotor {
	/*! Default Constructor */
	NIFLIB_API bhkVelocityConstraintMotor();
	/*! Default Destructor */
	NIFLIB_API ~bhkVelocityConstraintMotor();
	/*! Copy Constructor */
	NIFLIB_API bhkVelocityConstraintMotor( const bhkVelocityConstraintMotor & src );
	/*! Copy Operator */
	NIFLIB_API bhkVelocityConstraintMotor & operator=( const bhkVelocityConstraintMotor & src );
	/*! Minimum motor force */
	float minForce;
	/*! Maximum motor force */
	float maxForce;
	/*! Relative stiffness */
	float tau;
	float targetVelocity;
	bool useVelocityTarget;
	/*! Is Motor enabled */
	bool motorEnabled;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
