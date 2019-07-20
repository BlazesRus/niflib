/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _POLYGON_H_
#define _POLYGON_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Two dimensional screen elements. */
struct Polygon {
	/*! Default Constructor */
	NIFLIB_API Polygon();
	/*! Default Destructor */
	NIFLIB_API ~Polygon();
	/*! Copy Constructor */
	NIFLIB_API Polygon( const Polygon & src );
	/*! Copy Operator */
	NIFLIB_API Polygon & operator=( const Polygon & src );
	unsigned short numVertices;
	/*! Offset in vertex array. */
	unsigned short vertexOffset;
	unsigned short numTriangles;
	/*! Offset in indices array. */
	unsigned short triangleOffset;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
