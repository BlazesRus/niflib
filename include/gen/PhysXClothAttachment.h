/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PHYSXCLOTHATTACHMENT_H_
#define _PHYSXCLOTHATTACHMENT_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
#include "PhysXClothAttachmentPosition.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiPhysXShapeDesc;

struct PhysXClothAttachment {
	/*! Default Constructor */
	NIFLIB_API PhysXClothAttachment();
	/*! Default Destructor */
	NIFLIB_API ~PhysXClothAttachment();
	/*! Copy Constructor */
	NIFLIB_API PhysXClothAttachment( const PhysXClothAttachment & src );
	/*! Copy Operator */
	NIFLIB_API PhysXClothAttachment & operator=( const PhysXClothAttachment & src );
	Ref<NiPhysXShapeDesc > shape;
	mutable unsigned int numVertices;
	unsigned int flags;
	vector<PhysXClothAttachmentPosition > positions;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
