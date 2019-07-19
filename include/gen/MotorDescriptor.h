/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _MOTORDESCRIPTOR_H_
#define _MOTORDESCRIPTOR_H_

#include "../NIF_IO.h"

// Include structures
#include "bhkPositionConstraintMotor.h"
#include "bhkVelocityConstraintMotor.h"
#include "bhkSpringDamperConstraintMotor.h"
namespace Niflib {


struct MotorDescriptor {
	/*! Default Constructor */
	NIFLIB_API MotorDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~MotorDescriptor();
	/*! Copy Constructor */
	NIFLIB_API MotorDescriptor( const MotorDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API MotorDescriptor & operator=( const MotorDescriptor & src );
	MotorType type;
	bhkPositionConstraintMotor positionMotor;
	bhkVelocityConstraintMotor velocityMotor;
	bhkSpringDamperConstraintMotor springDamperMotor;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
