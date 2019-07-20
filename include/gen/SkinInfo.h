/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _SKININFO_H_
#define _SKININFO_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiTriBasedGeom;
class NiSkinInstance;

/*! NiBoneLODController::SkinInfo. Reference to shape and skin instance. */
struct SkinInfo {
	/*! Default Constructor */
	NIFLIB_API SkinInfo();
	/*! Default Destructor */
	NIFLIB_API ~SkinInfo();
	/*! Copy Constructor */
	NIFLIB_API SkinInfo( const SkinInfo & src );
	/*! Copy Operator */
	NIFLIB_API SkinInfo & operator=( const SkinInfo & src );
	NiTriBasedGeom * shape;
	Ref<NiSkinInstance > skinInstance;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
