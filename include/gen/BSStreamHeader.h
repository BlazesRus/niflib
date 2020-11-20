/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BSSTREAMHEADER_H_
#define _BSSTREAMHEADER_H_

#include "../NIF_IO.h"

namespace Niflib {


/*! Information about how the file was exported */
struct BSStreamHeader {
	/*! Default Constructor */
	NIFLIB_API BSStreamHeader();
	/*! Default Destructor */
	NIFLIB_API ~BSStreamHeader();
	/*! Copy Constructor */
	NIFLIB_API BSStreamHeader( const BSStreamHeader & src );
	/*! Copy Operator */
	NIFLIB_API BSStreamHeader & operator=( const BSStreamHeader & src );
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
