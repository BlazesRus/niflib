/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCMSCHUNK_H_
#define _BHKCMSCHUNK_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * Bethesda extension of hkpCompressedMeshShape::Chunk. A compressed chunk of
 * hkpCompressedMeshShape geometry.
 */
struct bhkCMSChunk {
	/*! Default Constructor */
	NIFLIB_API bhkCMSChunk();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSChunk();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSChunk( const bhkCMSChunk & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSChunk & operator=( const bhkCMSChunk & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
