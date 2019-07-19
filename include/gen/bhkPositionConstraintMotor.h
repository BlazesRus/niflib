/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKPOSITIONCONSTRAINTMOTOR_H_
#define _BHKPOSITIONCONSTRAINTMOTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


struct bhkPositionConstraintMotor {
	/*! Default Constructor */
	NIFLIB_API bhkPositionConstraintMotor();
	/*! Default Destructor */
	NIFLIB_API ~bhkPositionConstraintMotor();
	/*! Copy Constructor */
	NIFLIB_API bhkPositionConstraintMotor( const bhkPositionConstraintMotor & src );
	/*! Copy Operator */
	NIFLIB_API bhkPositionConstraintMotor & operator=( const bhkPositionConstraintMotor & src );
	/*! Minimum motor force */
	float minForce;
	/*! Maximum motor force */
	float maxForce;
	/*! Relative stiffness */
	float tau;
	/*! Motor damping value */
	float damping;
	/*! A factor of the current error to calculate the recovery velocity */
	float proportionalRecoveryVelocity;
	/*! A constant velocity which is used to recover from errors */
	float constantRecoveryVelocity;
	/*! Is Motor enabled */
	bool motorEnabled;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
