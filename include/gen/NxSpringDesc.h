/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXSPRINGDESC_H_
#define _NXSPRINGDESC_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NxSpringDesc {
	/*! Default Constructor */
	NIFLIB_API NxSpringDesc();
	/*! Default Destructor */
	NIFLIB_API ~NxSpringDesc();
	/*! Copy Constructor */
	NIFLIB_API NxSpringDesc( const NxSpringDesc & src );
	/*! Copy Operator */
	NIFLIB_API NxSpringDesc & operator=( const NxSpringDesc & src );
	float spring;
	float damper;
	float targetValue;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
