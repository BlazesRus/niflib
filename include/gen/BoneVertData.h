/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BONEVERTDATA_H_
#define _BONEVERTDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! NiSkinData::BoneVertData. A vertex and its weight. */
struct BoneVertData {
	/*! Default Constructor */
	NIFLIB_API BoneVertData();
	/*! Default Destructor */
	NIFLIB_API ~BoneVertData();
	/*! Copy Constructor */
	NIFLIB_API BoneVertData( const BoneVertData & src );
	/*! Copy Operator */
	NIFLIB_API BoneVertData & operator=( const BoneVertData & src );
	/*! The vertex index, in the mesh. */
	unsigned short index;
	/*! The vertex weight - between 0.0 and 1.0 */
	float weight;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
