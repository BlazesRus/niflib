/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSTREADTRANSFORM_H_
#define _BSTREADTRANSFORM_H_

#include "../NIF_IO.h"

// Include structures
#include "NiQuatTransform.h"
namespace Niflib {


/*! Bethesda-specific compound. */
struct BSTreadTransform {
	/*! Default Constructor */
	NIFLIB_API BSTreadTransform();
	/*! Default Destructor */
	NIFLIB_API ~BSTreadTransform();
	/*! Copy Constructor */
	NIFLIB_API BSTreadTransform( const BSTreadTransform & src );
	/*! Copy Operator */
	NIFLIB_API BSTreadTransform & operator=( const BSTreadTransform & src );
	IndexString name;
	NiQuatTransform transform1;
	NiQuatTransform transform2;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
