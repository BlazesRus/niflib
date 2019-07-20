/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HALFSPACEBV_H_
#define _HALFSPACEBV_H_

#include "../NIF_IO.h"

// Include structures
#include "NiPlane.h"
namespace Niflib {


struct HalfSpaceBV {
	/*! Default Constructor */
	NIFLIB_API HalfSpaceBV();
	/*! Default Destructor */
	NIFLIB_API ~HalfSpaceBV();
	/*! Copy Constructor */
	NIFLIB_API HalfSpaceBV( const HalfSpaceBV & src );
	/*! Copy Operator */
	NIFLIB_API HalfSpaceBV & operator=( const HalfSpaceBV & src );
	NiPlane plane;
	Vector3 center;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
