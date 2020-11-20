/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXCLOTHATTACHMENTPOSITION_H_
#define _PHYSXCLOTHATTACHMENTPOSITION_H_

#include "../NIF_IO.h"

namespace Niflib {


struct PhysXClothAttachmentPosition {
	/*! Default Constructor */
	NIFLIB_API PhysXClothAttachmentPosition();
	/*! Default Destructor */
	NIFLIB_API ~PhysXClothAttachmentPosition();
	/*! Copy Constructor */
	NIFLIB_API PhysXClothAttachmentPosition( const PhysXClothAttachmentPosition & src );
	/*! Copy Operator */
	NIFLIB_API PhysXClothAttachmentPosition & operator=( const PhysXClothAttachmentPosition & src );
	unsigned int vertexId;
	Vector3 position;
	unsigned int flags;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
