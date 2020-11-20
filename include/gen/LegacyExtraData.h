/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _LEGACYEXTRADATA_H_
#define _LEGACYEXTRADATA_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Extra Data for pre-3.0 versions */
struct LegacyExtraData {
	/*! Default Constructor */
	NIFLIB_API LegacyExtraData();
	/*! Default Destructor */
	NIFLIB_API ~LegacyExtraData();
	/*! Copy Constructor */
	NIFLIB_API LegacyExtraData( const LegacyExtraData & src );
	/*! Copy Operator */
	NIFLIB_API LegacyExtraData & operator=( const LegacyExtraData & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
