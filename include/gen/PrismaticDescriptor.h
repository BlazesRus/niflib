/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PRISMATICDESCRIPTOR_H_
#define _PRISMATICDESCRIPTOR_H_

#include "../NIF_IO.h"

// Include structures
#include "MotorDescriptor.h"
namespace Niflib {


struct PrismaticDescriptor {
	/*! Default Constructor */
	NIFLIB_API PrismaticDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~PrismaticDescriptor();
	/*! Copy Constructor */
	NIFLIB_API PrismaticDescriptor( const PrismaticDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API PrismaticDescriptor & operator=( const PrismaticDescriptor & src );
	/*! Pivot. */
	Vector4 pivotA;
	/*! Rotation axis. */
	Vector4 rotationA;
	/*! Plane normal. Describes the plane the object is able to move on. */
	Vector4 planeA;
	/*! Describes the axis the object is able to travel along. Unit vector. */
	Vector4 slidingA;
	/*! Pivot in B coordinates. */
	Vector4 pivotB;
	/*! Rotation axis. */
	Vector4 rotationB;
	/*!
	 * Plane normal. Describes the plane the object is able to move on in B
	 * coordinates.
	 */
	Vector4 planeB;
	/*!
	 * Describes the axis the object is able to travel along in B coordinates. Unit
	 * vector.
	 */
	Vector4 slidingB;
	/*! Describe the min distance the object is able to travel. */
	float minDistance;
	/*! Describe the max distance the object is able to travel. */
	float maxDistance;
	/*! Friction. */
	float friction;
	MotorDescriptor motor;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
