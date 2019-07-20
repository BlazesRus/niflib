/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _TEXDESC_H_
#define _TEXDESC_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiImage;
class NiSourceTexture;

/*! NiTexturingProperty::Map. Texture description. */
struct TexDesc {
	/*! Default Constructor */
	NIFLIB_API TexDesc();
	/*! Default Destructor */
	NIFLIB_API ~TexDesc();
	/*! Copy Constructor */
	NIFLIB_API TexDesc( const TexDesc & src );
	/*! Copy Operator */
	NIFLIB_API TexDesc & operator=( const TexDesc & src );
	/*! Link to the texture image. */
	Ref<NiImage > image;
	/*! NiSourceTexture object index. */
	Ref<NiSourceTexture > source;
	/*! 0=clamp S clamp T, 1=clamp S wrap T, 2=wrap S clamp T, 3=wrap S wrap T */
	TexClampMode clampMode;
	/*! 0=nearest, 1=bilinear, 2=trilinear, 3=..., 4=..., 5=... */
	TexFilterMode filterMode;
	/*!
	 * Texture mode flags; clamp and filter mode stored in upper byte with 0xYZ00 =
	 * clamp mode Y, filter mode Z.
	 */
	unsigned short flags;
	unsigned short maxAnisotropy;
	/*! The texture coordinate set in NiGeometryData that this texture slot will use. */
	unsigned int uvSet;
	/*! L can range from 0 to 3 and are used to specify how fast a texture gets blurry. */
	short ps2L;
	/*!
	 * K is used as an offset into the mipmap levels and can range from -2047 to 2047.
	 * Positive values push the mipmap towards being blurry and negative values make
	 * the mipmap sharper.
	 */
	short ps2K;
	/*! Unknown, 0 or 0x0101? */
	unsigned short unknown1;
	/*! Whether or not the texture coordinates are transformed. */
	bool hasTextureTransform;
	/*! The UV translation. */
	TexCoord translation;
	/*! The UV scale. */
	TexCoord scale;
	/*! The W axis rotation in texture space. */
	float rotation;
	/*! Depending on the source, scaling can occur before or after rotation. */
	TransformMethod transformMethod;
	/*! The origin around which the texture rotates. */
	TexCoord center;
	//--BEGIN MISC CUSTOM CODE--//
	//--END CUSTOM CODE--//
};

}
#endif
