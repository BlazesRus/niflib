/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXMATERIALREF_H_
#define _PHYSXMATERIALREF_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPhysXMaterialDesc;

struct PhysXMaterialRef {
	/*! Default Constructor */
	NIFLIB_API PhysXMaterialRef();
	/*! Default Destructor */
	NIFLIB_API ~PhysXMaterialRef();
	/*! Copy Constructor */
	NIFLIB_API PhysXMaterialRef( const PhysXMaterialRef & src );
	/*! Copy Operator */
	NIFLIB_API PhysXMaterialRef & operator=( const PhysXMaterialRef & src );
	unsigned short key;
	Ref<NiPhysXMaterialDesc > materialDesc;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
