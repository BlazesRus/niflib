/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HKWORLDOBJCINFOPROPERTY_H_
#define _HKWORLDOBJCINFOPROPERTY_H_

#include "../NIF_IO.h"

namespace Niflib {


struct hkWorldObjCinfoProperty {
	/*! Default Constructor */
	NIFLIB_API hkWorldObjCinfoProperty();
	/*! Default Destructor */
	NIFLIB_API ~hkWorldObjCinfoProperty();
	/*! Copy Constructor */
	NIFLIB_API hkWorldObjCinfoProperty( const hkWorldObjCinfoProperty & src );
	/*! Copy Operator */
	NIFLIB_API hkWorldObjCinfoProperty & operator=( const hkWorldObjCinfoProperty & src );
	unsigned int data;
	unsigned int size;
	unsigned int capacityAndFlags;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
