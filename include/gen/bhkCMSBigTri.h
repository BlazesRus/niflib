/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCMSBIGTRI_H_
#define _BHKCMSBIGTRI_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Bethesda extension of hkpCompressedMeshShape::BigTriangle. Triangles that don't
 * fit the maximum size.
 */
struct bhkCMSBigTri {
	/*! Default Constructor */
	NIFLIB_API bhkCMSBigTri();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSBigTri();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSBigTri( const bhkCMSBigTri & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSBigTri & operator=( const bhkCMSBigTri & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
