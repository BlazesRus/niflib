/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _EXPORTINFO_H_
#define _EXPORTINFO_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Information about how the file was exported */
struct ExportInfo {
	/*! Default Constructor */
	NIFLIB_API ExportInfo();
	/*! Default Destructor */
	NIFLIB_API ~ExportInfo();
	/*! Copy Constructor */
	NIFLIB_API ExportInfo( const ExportInfo & src );
	/*! Copy Operator */
	NIFLIB_API ExportInfo & operator=( const ExportInfo & src );
	ShortString author;
	ShortString processScript;
	ShortString exportScript;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
