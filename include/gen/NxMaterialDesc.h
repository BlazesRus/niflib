/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXMATERIALDESC_H_
#define _NXMATERIALDESC_H_

#include "../NIF_IO.h"

// Include structures
#include "NxSpringDesc.h"
namespace Niflib {


struct NxMaterialDesc {
	/*! Default Constructor */
	NIFLIB_API NxMaterialDesc();
	/*! Default Destructor */
	NIFLIB_API ~NxMaterialDesc();
	/*! Copy Constructor */
	NIFLIB_API NxMaterialDesc( const NxMaterialDesc & src );
	/*! Copy Operator */
	NIFLIB_API NxMaterialDesc & operator=( const NxMaterialDesc & src );
	float dynamicFriction;
	float staticFriction;
	float restitution;
	float dynamicFrictionV;
	float staticFrictionV;
	Vector3 directionOfAnisotropy;
	NxMaterialFlag flags;
	NxCombineMode frictionCombineMode;
	NxCombineMode restitutionCombineMode;
	bool hasSpring;
	NxSpringDesc spring;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
