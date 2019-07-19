/* Copyright (c) 2019, NIF File Format Library and Tools
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
#include "../../include/obj/NiPalette.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPalette::TYPE("NiPalette", &NiObject::TYPE );

NiPalette::NiPalette() : hasAlpha((byte)0), numEntries((unsigned int)256) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPalette::~NiPalette() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPalette::GetType() const {
	return TYPE;
}

NiObject * NiPalette::Create() {
	return new NiPalette;
}

void NiPalette::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( hasAlpha, in, info );
	NifStream( numEntries, in, info );
	if ( (numEntries == 16) ) {
		for (unsigned int i2 = 0; i2 < 16; i2++) {
			NifStream( palette[i2], in, info );
		};
	};
	if ( (numEntries != 16) ) {
		for (unsigned int i2 = 0; i2 < 256; i2++) {
			NifStream( (ByteColor4&)palette[i2], in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPalette::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	NifStream( hasAlpha, out, info );
	NifStream( numEntries, out, info );
	if ( (numEntries == 16) ) {
		for (unsigned int i2 = 0; i2 < 16; i2++) {
			NifStream( palette[i2], out, info );
		};
	};
	if ( (numEntries != 16) ) {
		for (unsigned int i2 = 0; i2 < 256; i2++) {
			NifStream( (ByteColor4&)palette[i2], out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPalette::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Has Alpha:  " << hasAlpha << endl;
	out << "  Num Entries:  " << numEntries << endl;
	if ( (numEntries == 16) ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 16; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Palette[" << i2 << "]:  " << palette[i2] << endl;
			array_output_count++;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPalette::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPalette::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPalette::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

vector<Color4> NiPalette::GetPalette() const {
	vector<Color4> color_pal(256);

	for ( unsigned int i = 0; i < 256; ++i ) {
		
		color_pal[i].r = float(palette[i].r) / 255.0f;
		color_pal[i].g = float(palette[i].g) / 255.0f;
		color_pal[i].b = float(palette[i].b) / 255.0f;
		color_pal[i].a = float(palette[i].a) / 255.0f;
	}

	return color_pal;
}

void NiPalette::SetPalette( const vector<Color4> & new_pal ) {
	if ( new_pal.size() != 256 ) {
		throw runtime_error( "Palette size must be 256" );
	}

	for ( unsigned int i = 0; i < 256; ++i ) {
		palette[i].r = int( new_pal[i].r * 255.0f );
		palette[i].g = int( new_pal[i].g * 255.0f );
		palette[i].b = int( new_pal[i].b * 255.0f );
		palette[i].a = int( new_pal[i].a * 255.0f );
	}
}

//--END CUSTOM CODE--//
