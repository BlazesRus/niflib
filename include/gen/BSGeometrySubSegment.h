/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSGEOMETRYSUBSEGMENT_H_
#define _BSGEOMETRYSUBSEGMENT_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! This is only defined because of recursion issues. */
struct BSGeometrySubSegment {
	/*! Default Constructor */
	NIFLIB_API BSGeometrySubSegment();
	/*! Default Destructor */
	NIFLIB_API ~BSGeometrySubSegment();
	/*! Copy Constructor */
	NIFLIB_API BSGeometrySubSegment( const BSGeometrySubSegment & src );
	/*! Copy Operator */
	NIFLIB_API BSGeometrySubSegment & operator=( const BSGeometrySubSegment & src );
	unsigned int startIndex;
	unsigned int numPrimitives;
	unsigned int parentArrayIndex;
	unsigned int unused;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
