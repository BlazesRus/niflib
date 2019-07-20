/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _SKININFOSET_H_
#define _SKININFOSET_H_

#include "../NIF_IO.h"

// Include structures
#include "SkinInfo.h"
namespace Niflib {


/*! A set of NiBoneLODController::SkinInfo. */
struct SkinInfoSet {
	/*! Default Constructor */
	NIFLIB_API SkinInfoSet();
	/*! Default Destructor */
	NIFLIB_API ~SkinInfoSet();
	/*! Copy Constructor */
	NIFLIB_API SkinInfoSet( const SkinInfoSet & src );
	/*! Copy Operator */
	NIFLIB_API SkinInfoSet & operator=( const SkinInfoSet & src );
	mutable unsigned int numSkinInfo;
	vector<SkinInfo > skinInfo;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
