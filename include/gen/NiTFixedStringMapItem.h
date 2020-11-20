/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NITFIXEDSTRINGMAPITEM_H_
#define _NITFIXEDSTRINGMAPITEM_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Currently, #T# must be a basic type due to nif.xml restrictions. */
struct NiTFixedStringMapItem {
	/*! Default Constructor */
	NIFLIB_API NiTFixedStringMapItem();
	/*! Default Destructor */
	NIFLIB_API ~NiTFixedStringMapItem();
	/*! Copy Constructor */
	NIFLIB_API NiTFixedStringMapItem( const NiTFixedStringMapItem & src );
	/*! Copy Operator */
	NIFLIB_API NiTFixedStringMapItem & operator=( const NiTFixedStringMapItem & src );
	NiFixedString string;
	#T# value;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
