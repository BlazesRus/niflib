/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKSPRINGDAMPERCONSTRAINTMOTOR_H_
#define _BHKSPRINGDAMPERCONSTRAINTMOTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


struct bhkSpringDamperConstraintMotor {
	/*! Default Constructor */
	NIFLIB_API bhkSpringDamperConstraintMotor();
	/*! Default Destructor */
	NIFLIB_API ~bhkSpringDamperConstraintMotor();
	/*! Copy Constructor */
	NIFLIB_API bhkSpringDamperConstraintMotor( const bhkSpringDamperConstraintMotor & src );
	/*! Copy Operator */
	NIFLIB_API bhkSpringDamperConstraintMotor & operator=( const bhkSpringDamperConstraintMotor & src );
	/*! Minimum motor force */
	float minForce;
	/*! Maximum motor force */
	float maxForce;
	/*! The spring constant in N/m */
	float springConstant;
	/*! The spring damping in Nsec/m */
	float springDamping;
	/*! Is Motor enabled */
	bool motorEnabled;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
