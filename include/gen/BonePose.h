/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BONEPOSE_H_
#define _BONEPOSE_H_

#include "../NIF_IO.h"

// Include structures
#include "BoneTransform.h"
namespace Niflib {


/*! A list of transforms for each bone in bhkPoseArray. */
struct BonePose {
	/*! Default Constructor */
	NIFLIB_API BonePose();
	/*! Default Destructor */
	NIFLIB_API ~BonePose();
	/*! Copy Constructor */
	NIFLIB_API BonePose( const BonePose & src );
	/*! Copy Operator */
	NIFLIB_API BonePose & operator=( const BonePose & src );
	mutable unsigned int numTransforms;
	vector<BoneTransform > transforms;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
