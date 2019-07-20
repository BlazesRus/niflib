/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKCMSDMATERIAL_H_
#define _BHKCMSDMATERIAL_H_

#include "../NIF_IO.h"

// Include structures
#include "HavokFilter.h"
namespace Niflib {


/*! Per-chunk material, used in bhkCompressedMeshShapeData */
struct bhkCMSDMaterial {
	/*! Default Constructor */
	NIFLIB_API bhkCMSDMaterial();
	/*! Default Destructor */
	NIFLIB_API ~bhkCMSDMaterial();
	/*! Copy Constructor */
	NIFLIB_API bhkCMSDMaterial( const bhkCMSDMaterial & src );
	/*! Copy Operator */
	NIFLIB_API bhkCMSDMaterial & operator=( const bhkCMSDMaterial & src );
	SkyrimHavokMaterial material;
	HavokFilter filter;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
