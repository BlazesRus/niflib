/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _STIFFSPRINGDESCRIPTOR_H_
#define _STIFFSPRINGDESCRIPTOR_H_

#include "../NIF_IO.h"

namespace Niflib {


struct StiffSpringDescriptor {
	/*! Default Constructor */
	NIFLIB_API StiffSpringDescriptor();
	/*! Default Destructor */
	NIFLIB_API ~StiffSpringDescriptor();
	/*! Copy Constructor */
	NIFLIB_API StiffSpringDescriptor( const StiffSpringDescriptor & src );
	/*! Copy Operator */
	NIFLIB_API StiffSpringDescriptor & operator=( const StiffSpringDescriptor & src );
	Vector4 pivotA;
	Vector4 pivotB;
	float length;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
