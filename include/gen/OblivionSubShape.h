/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _OBLIVIONSUBSHAPE_H_
#define _OBLIVIONSUBSHAPE_H_

#include "../NIF_IO.h"

// Include structures
#include "HavokFilter.h"
#include "HavokMaterial.h"
namespace Niflib {


/*! Bethesda Havok. Havok Information for packed TriStrip shapes. */
struct OblivionSubShape {
	/*! Default Constructor */
	NIFLIB_API OblivionSubShape();
	/*! Default Destructor */
	NIFLIB_API ~OblivionSubShape();
	/*! Copy Constructor */
	NIFLIB_API OblivionSubShape( const OblivionSubShape & src );
	/*! Copy Operator */
	NIFLIB_API OblivionSubShape & operator=( const OblivionSubShape & src );
	HavokFilter havokFilter;
	/*! The number of vertices that form this sub shape. */
	unsigned int numVertices;
	/*! The material of the subshape. */
	HavokMaterial material;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
