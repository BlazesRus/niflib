/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSPACKEDGEOMDATACOMBINED_H_
#define _BSPACKEDGEOMDATACOMBINED_H_

#include "../NIF_IO.h"

// Include structures
#include "NiTransform.h"
#include "NiBound.h"
namespace Niflib {


struct BSPackedGeomDataCombined {
	/*! Default Constructor */
	NIFLIB_API BSPackedGeomDataCombined();
	/*! Default Destructor */
	NIFLIB_API ~BSPackedGeomDataCombined();
	/*! Copy Constructor */
	NIFLIB_API BSPackedGeomDataCombined( const BSPackedGeomDataCombined & src );
	/*! Copy Operator */
	NIFLIB_API BSPackedGeomDataCombined & operator=( const BSPackedGeomDataCombined & src );
	float grayscaleToPaletteScale;
	NiTransform transform;
	NiBound boundingSphere;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
