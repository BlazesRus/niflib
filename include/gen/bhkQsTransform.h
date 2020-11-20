/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKQSTRANSFORM_H_
#define _BHKQSTRANSFORM_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Bethesda extension of hkQsTransform. The scale vector is not serialized. */
struct bhkQsTransform {
	/*! Default Constructor */
	NIFLIB_API bhkQsTransform();
	/*! Default Destructor */
	NIFLIB_API ~bhkQsTransform();
	/*! Copy Constructor */
	NIFLIB_API bhkQsTransform( const bhkQsTransform & src );
	/*! Copy Operator */
	NIFLIB_API bhkQsTransform & operator=( const bhkQsTransform & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
