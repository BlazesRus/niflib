/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HAVOKMATERIAL_H_
#define _HAVOKMATERIAL_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Bethesda Havok. Material wrapper for varying material enums by game. */
struct HavokMaterial {
	/*! Default Constructor */
	NIFLIB_API HavokMaterial();
	/*! Default Destructor */
	NIFLIB_API ~HavokMaterial();
	/*! Copy Constructor */
	NIFLIB_API HavokMaterial( const HavokMaterial & src );
	/*! Copy Operator */
	NIFLIB_API HavokMaterial & operator=( const HavokMaterial & src );
	/*! The material of the shape. */
	OblivionHavokMaterial material_ob;
	/*! The material of the shape. */
	Fallout3HavokMaterial material_fo;
	/*! The material of the shape. */
	SkyrimHavokMaterial material_sk;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
