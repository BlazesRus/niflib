/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _LODINFO_H_
#define _LODINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


struct LODInfo {
	/*! Default Constructor */
	NIFLIB_API LODInfo();
	/*! Default Destructor */
	NIFLIB_API ~LODInfo();
	/*! Copy Constructor */
	NIFLIB_API LODInfo( const LODInfo & src );
	/*! Copy Operator */
	NIFLIB_API LODInfo & operator=( const LODInfo & src );
	unsigned int numBones;
	mutable unsigned int numActiveSkins;
	vector<unsigned int > skinIndices;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
