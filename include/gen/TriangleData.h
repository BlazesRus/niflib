/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _TRIANGLEDATA_H_
#define _TRIANGLEDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Bethesda Havok. A triangle with extra data used for physics. */
struct TriangleData {
	/*! Default Constructor */
	NIFLIB_API TriangleData();
	/*! Default Destructor */
	NIFLIB_API ~TriangleData();
	/*! Copy Constructor */
	NIFLIB_API TriangleData( const TriangleData & src );
	/*! Copy Operator */
	NIFLIB_API TriangleData & operator=( const TriangleData & src );
	/*! The triangle. */
	Triangle triangle;
	/*! Additional havok information on how triangles are welded. */
	unsigned short weldingInfo;
	/*! This is the triangle's normal. */
	Vector3 normal;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
