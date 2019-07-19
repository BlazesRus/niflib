/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _PIXELFORMATCOMPONENT_H_
#define _PIXELFORMATCOMPONENT_H_

#include "../NIF_IO.h"

namespace Niflib {


struct PixelFormatComponent {
	/*! Default Constructor */
	NIFLIB_API PixelFormatComponent();
	/*! Default Destructor */
	NIFLIB_API ~PixelFormatComponent();
	/*! Copy Constructor */
	NIFLIB_API PixelFormatComponent( const PixelFormatComponent & src );
	/*! Copy Operator */
	NIFLIB_API PixelFormatComponent & operator=( const PixelFormatComponent & src );
	/*! Component Type */
	PixelComponent type;
	/*! Data Storage Convention */
	PixelRepresentation convention;
	/*! Bits per component */
	byte bitsPerChannel;
	bool isSigned;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
