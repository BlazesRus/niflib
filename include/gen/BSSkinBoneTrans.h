/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSSKINBONETRANS_H_
#define _BSSKINBONETRANS_H_

#include "../NIF_IO.h"

// Include structures
#include "NiBound.h"
namespace Niflib {


/*! Fallout 4 Bone Transform */
struct BSSkinBoneTrans {
	/*! Default Constructor */
	NIFLIB_API BSSkinBoneTrans();
	/*! Default Destructor */
	NIFLIB_API ~BSSkinBoneTrans();
	/*! Copy Constructor */
	NIFLIB_API BSSkinBoneTrans( const BSSkinBoneTrans & src );
	/*! Copy Operator */
	NIFLIB_API BSSkinBoneTrans & operator=( const BSSkinBoneTrans & src );
	NiBound boundingSphere;
	Matrix33 rotation;
	Vector3 translation;
	float scale;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
