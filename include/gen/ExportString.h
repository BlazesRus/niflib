/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _EXPORTSTRING_H_
#define _EXPORTSTRING_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Specific to Bethesda-specific header export strings. */
struct ExportString {
	/*! Default Constructor */
	NIFLIB_API ExportString();
	/*! Default Destructor */
	NIFLIB_API ~ExportString();
	/*! Copy Constructor */
	NIFLIB_API ExportString( const ExportString & src );
	/*! Copy Operator */
	NIFLIB_API ExportString & operator=( const ExportString & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
