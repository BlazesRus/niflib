/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSPACKEDGEOMOBJECT_H_
#define _BSPACKEDGEOMOBJECT_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! This appears to be a 64-bit hash but nif.xml does not have a 64-bit type. */
struct BSPackedGeomObject {
	/*! Default Constructor */
	NIFLIB_API BSPackedGeomObject();
	/*! Default Destructor */
	NIFLIB_API ~BSPackedGeomObject();
	/*! Copy Constructor */
	NIFLIB_API BSPackedGeomObject( const BSPackedGeomObject & src );
	/*! Copy Operator */
	NIFLIB_API BSPackedGeomObject & operator=( const BSPackedGeomObject & src );
	unsigned int shapeId1;
	unsigned int shapeId2;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
