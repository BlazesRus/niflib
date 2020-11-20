/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _NITFIXEDSTRINGMAP_H_
#define _NITFIXEDSTRINGMAP_H_

#include "../NIF_IO.h"

// Include structures
#include "NiTFixedStringMapItem.h"
namespace Niflib {


/*!
 * A mapping or hash table between NiFixedString keys and a generic value.
 *         Currently, #T# must be a basic type due to nif.xml restrictions.
 */
struct NiTFixedStringMap {
	/*! Default Constructor */
	NIFLIB_API NiTFixedStringMap();
	/*! Default Destructor */
	NIFLIB_API ~NiTFixedStringMap();
	/*! Copy Constructor */
	NIFLIB_API NiTFixedStringMap( const NiTFixedStringMap & src );
	/*! Copy Operator */
	NIFLIB_API NiTFixedStringMap & operator=( const NiTFixedStringMap & src );
	mutable unsigned int numStrings;
	vector<NiTFixedStringMapItem<#T# > > strings;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
