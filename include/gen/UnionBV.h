/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _UNIONBV_H_
#define _UNIONBV_H_

#include "../NIF_IO.h"

// Include structures
#include "BoundingVolume.h"
namespace Niflib {


struct UnionBV {
	/*! Default Constructor */
	NIFLIB_API UnionBV();
	/*! Default Destructor */
	NIFLIB_API ~UnionBV();
	/*! Copy Constructor */
	NIFLIB_API UnionBV( const UnionBV & src );
	/*! Copy Operator */
	NIFLIB_API UnionBV & operator=( const UnionBV & src );
	mutable unsigned int numBv;
	vector<BoundingVolume > boundingVolumes;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
