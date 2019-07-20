/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NXCAPSULE_H_
#define _NXCAPSULE_H_

#include "../NIF_IO.h"

namespace Niflib {


struct NxCapsule {
	/*! Default Constructor */
	NIFLIB_API NxCapsule();
	/*! Default Destructor */
	NIFLIB_API ~NxCapsule();
	/*! Copy Constructor */
	NIFLIB_API NxCapsule( const NxCapsule & src );
	/*! Copy Operator */
	NIFLIB_API NxCapsule & operator=( const NxCapsule & src );
	float val1;
	float val2;
	unsigned int capsuleFlags;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
