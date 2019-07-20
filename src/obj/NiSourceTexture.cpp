/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiSourceTexture.h"
#include "../../include/gen/FormatPrefs.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiPixelFormat.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSourceTexture::TYPE("NiSourceTexture", &NiTexture::TYPE );

NiSourceTexture::NiSourceTexture() : useExternal((byte)1), unknownLink(NULL), unknownByte((byte)1), pixelData(NULL), isStatic((byte)1), directRender(1), persistRenderData(0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSourceTexture::~NiSourceTexture() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiSourceTexture::GetType() const {
	return TYPE;
}

NiObject * NiSourceTexture::Create() {
	return new NiSourceTexture;
}

void NiSourceTexture::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiTexture::Read( in, link_stack, info );
	NifStream( useExternal, in, info );
	if ( (useExternal == 1) ) {
		NifStream( fileName, in, info );
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	if ( info.version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, in, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( (IndexString&)fileName, in, info );
		};
	};
	if ( (useExternal == 0) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( formatPrefs.pixelLayout, in, info );
	NifStream( formatPrefs.useMipmaps, in, info );
	NifStream( formatPrefs.alphaFormat, in, info );
	NifStream( isStatic, in, info );
	if ( info.version >= 0x0A010067 ) {
		NifStream( directRender, in, info );
	};
	if ( info.version >= 0x14020004 ) {
		NifStream( persistRenderData, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSourceTexture::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTexture::Write( out, link_map, missing_link_stack, info );
	NifStream( useExternal, out, info );
	if ( (useExternal == 1) ) {
		NifStream( fileName, out, info );
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			WriteRef( StaticCast<NiObject>(unknownLink), out, info, link_map, missing_link_stack );
		};
	};
	if ( info.version <= 0x0A000100 ) {
		if ( (useExternal == 0) ) {
			NifStream( unknownByte, out, info );
		};
	};
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 0) ) {
			NifStream( (IndexString&)fileName, out, info );
		};
	};
	if ( (useExternal == 0) ) {
		WriteRef( StaticCast<NiObject>(pixelData), out, info, link_map, missing_link_stack );
	};
	NifStream( formatPrefs.pixelLayout, out, info );
	NifStream( formatPrefs.useMipmaps, out, info );
	NifStream( formatPrefs.alphaFormat, out, info );
	NifStream( isStatic, out, info );
	if ( info.version >= 0x0A010067 ) {
		NifStream( directRender, out, info );
	};
	if ( info.version >= 0x14020004 ) {
		NifStream( persistRenderData, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSourceTexture::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTexture::asString();
	out << "  Use External:  " << useExternal << endl;
	if ( (useExternal == 1) ) {
		out << "    File Name:  " << fileName << endl;
		out << "    Unknown Link:  " << unknownLink << endl;
	};
	if ( (useExternal == 0) ) {
		out << "    Unknown Byte:  " << unknownByte << endl;
		out << "    Pixel Data:  " << pixelData << endl;
	};
	out << "  Pixel Layout:  " << formatPrefs.pixelLayout << endl;
	out << "  Use Mipmaps:  " << formatPrefs.useMipmaps << endl;
	out << "  Alpha Format:  " << formatPrefs.alphaFormat << endl;
	out << "  Is Static:  " << isStatic << endl;
	out << "  Direct Render:  " << directRender << endl;
	out << "  Persist Render Data:  " << persistRenderData << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSourceTexture::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTexture::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		if ( (useExternal == 1) ) {
			unknownLink = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
		};
	};
	if ( (useExternal == 0) ) {
		pixelData = FixLink<NiPixelFormat>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSourceTexture::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTexture::GetRefs();
	if ( unknownLink != NULL )
		refs.push_back(StaticCast<NiObject>(unknownLink));
	if ( pixelData != NULL )
		refs.push_back(StaticCast<NiObject>(pixelData));
	return refs;
}

std::list<NiObject *> NiSourceTexture::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTexture::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

bool NiSourceTexture::IsTextureExternal() const {
	return ( useExternal != 0 );
}

void NiSourceTexture::SetExternalTexture( string file_name ) {
	useExternal = 1;
	pixelData = NULL;
	fileName = file_name;
	unknownLink = NULL;
}

void NiSourceTexture::SetInternalTexture( string original_file_name, NiPixelData * pixel_data ) {
	useExternal = 0;
	fileName.clear();
	
	//TODO: Fix name problem with Unknown Byte in XML
	unknownByte = 0;
	fileName = original_file_name;
	pixelData = pixel_data;
}

string NiSourceTexture::GetTextureFileName() const {
   return fileName;
}

Ref<NiPixelData> NiSourceTexture::GetPixelData() const {
	return DynamicCast<NiPixelData>(pixelData);
}

PixelLayout NiSourceTexture::GetPixelLayout() const {
	return pixelLayout;
}

void NiSourceTexture::SetPixelLayout( PixelLayout n ) {
	pixelLayout = n;
}

MipMapFormat NiSourceTexture::GetMipMapFormat() const {
	return useMipmaps;
}

void NiSourceTexture::SetMipMapFormat( MipMapFormat n ) {
	useMipmaps = n;
}

AlphaFormat NiSourceTexture::GetAlphaFormat() const {
	return alphaFormat;
}

void NiSourceTexture::SetAlphaFormat( AlphaFormat n ) {
	alphaFormat = n;
}

//--END CUSTOM CODE--//
