/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _HKSUBPARTDATA_H_
#define _HKSUBPARTDATA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Bethesda Havok. Havok Information for packed TriStrip shapes. */
struct hkSubPartData {
	/*! Default Constructor */
	NIFLIB_API hkSubPartData();
	/*! Default Destructor */
	NIFLIB_API ~hkSubPartData();
	/*! Copy Constructor */
	NIFLIB_API hkSubPartData( const hkSubPartData & src );
	/*! Copy Operator */
	NIFLIB_API hkSubPartData & operator=( const hkSubPartData & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
