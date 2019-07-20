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
#include "../../include/obj/NiPersistentSrcTextureRendererData.h"
#include "../../include/gen/MipMap.h"
#include "../../include/obj/NiPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPersistentSrcTextureRendererData::TYPE("NiPersistentSrcTextureRendererData", &NiPixelFormat::TYPE );

NiPersistentSrcTextureRendererData::NiPersistentSrcTextureRendererData() : palette(NULL), numMipmaps((unsigned int)0), bytesPerPixel((unsigned int)0), numPixels((unsigned int)0), padNumPixels((unsigned int)0), numFaces((unsigned int)0), platform((PlatformID)0), renderer((RendererID)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPersistentSrcTextureRendererData::~NiPersistentSrcTextureRendererData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPersistentSrcTextureRendererData::GetType() const {
	return TYPE;
}

NiObject * NiPersistentSrcTextureRendererData::Create() {
	return new NiPersistentSrcTextureRendererData;
}

void NiPersistentSrcTextureRendererData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPixelFormat::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( numMipmaps, in, info );
	NifStream( bytesPerPixel, in, info );
	mipmaps.resize(numMipmaps);
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, in, info );
		NifStream( mipmaps[i1].height, in, info );
		NifStream( mipmaps[i1].offset, in, info );
	};
	NifStream( numPixels, in, info );
	if ( info.version >= 0x14020006 ) {
		NifStream( padNumPixels, in, info );
	};
	NifStream( numFaces, in, info );
	if ( info.version <= 0x1E010000 ) {
		NifStream( platform, in, info );
	};
	if ( info.version >= 0x1E010001 ) {
		NifStream( renderer, in, info );
	};
	pixelData.resize((numPixels * numFaces));
	for (unsigned int i1 = 0; i1 < pixelData.size(); i1++) {
		NifStream( pixelData[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPersistentSrcTextureRendererData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPixelFormat::Write( out, link_map, missing_link_stack, info );
	numMipmaps = (unsigned int)(mipmaps.size());
	WriteRef( StaticCast<NiObject>(palette), out, info, link_map, missing_link_stack );
	NifStream( numMipmaps, out, info );
	NifStream( bytesPerPixel, out, info );
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		NifStream( mipmaps[i1].width, out, info );
		NifStream( mipmaps[i1].height, out, info );
		NifStream( mipmaps[i1].offset, out, info );
	};
	NifStream( numPixels, out, info );
	if ( info.version >= 0x14020006 ) {
		NifStream( padNumPixels, out, info );
	};
	NifStream( numFaces, out, info );
	if ( info.version <= 0x1E010000 ) {
		NifStream( platform, out, info );
	};
	if ( info.version >= 0x1E010001 ) {
		NifStream( renderer, out, info );
	};
	for (unsigned int i1 = 0; i1 < pixelData.size(); i1++) {
		NifStream( pixelData[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPersistentSrcTextureRendererData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiPixelFormat::asString();
	numMipmaps = (unsigned int)(mipmaps.size());
	out << "  Palette:  " << palette << endl;
	out << "  Num Mipmaps:  " << numMipmaps << endl;
	out << "  Bytes Per Pixel:  " << bytesPerPixel << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < mipmaps.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Width:  " << mipmaps[i1].width << endl;
		out << "    Height:  " << mipmaps[i1].height << endl;
		out << "    Offset:  " << mipmaps[i1].offset << endl;
	};
	out << "  Num Pixels:  " << numPixels << endl;
	out << "  Pad Num Pixels:  " << padNumPixels << endl;
	out << "  Num Faces:  " << numFaces << endl;
	out << "  Platform:  " << platform << endl;
	out << "  Renderer:  " << renderer << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < pixelData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Pixel Data[" << i1 << "]:  " << pixelData[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPersistentSrcTextureRendererData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPixelFormat::FixLinks( objects, link_stack, missing_link_stack, info );
	palette = FixLink<NiPalette>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPersistentSrcTextureRendererData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPixelFormat::GetRefs();
	if ( palette != NULL )
		refs.push_back(StaticCast<NiObject>(palette));
	return refs;
}

std::list<NiObject *> NiPersistentSrcTextureRendererData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPixelFormat::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
