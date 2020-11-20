/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKMESHMATERIAL_H_
#define _BHKMESHMATERIAL_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * hkpBSMaterial, a subclass of hkpMeshMaterial. hkpMeshMaterial is a base class
 * for material info for hkMeshShapes.
 */
struct bhkMeshMaterial {
	/*! Default Constructor */
	NIFLIB_API bhkMeshMaterial();
	/*! Default Destructor */
	NIFLIB_API ~bhkMeshMaterial();
	/*! Copy Constructor */
	NIFLIB_API bhkMeshMaterial( const bhkMeshMaterial & src );
	/*! Copy Operator */
	NIFLIB_API bhkMeshMaterial & operator=( const bhkMeshMaterial & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
