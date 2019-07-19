/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _FORMATPREFS_H_
#define _FORMATPREFS_H_

#include "../NIF_IO.h"

namespace Niflib {


/*!
 * NiTexture::FormatPrefs. These preferences are a request to the renderer to use a
 * format the most closely matches the settings and may be ignored.
 */
struct FormatPrefs {
	/*! Default Constructor */
	NIFLIB_API FormatPrefs();
	/*! Default Destructor */
	NIFLIB_API ~FormatPrefs();
	/*! Copy Constructor */
	NIFLIB_API FormatPrefs( const FormatPrefs & src );
	/*! Copy Operator */
	NIFLIB_API FormatPrefs & operator=( const FormatPrefs & src );
	/*! Requests the way the image will be stored. */
	PixelLayout pixelLayout;
	/*! Requests if mipmaps are used or not. */
	MipMapFormat useMipmaps;
	/*! Requests no alpha, 1-bit alpha, or */
	AlphaFormat alphaFormat;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
