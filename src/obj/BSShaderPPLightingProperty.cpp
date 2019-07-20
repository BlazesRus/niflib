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
#include "../../include/obj/BSShaderPPLightingProperty.h"
#include "../../include/obj/BSShaderTextureSet.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSShaderPPLightingProperty::TYPE("BSShaderPPLightingProperty", &BSShaderLightingProperty::TYPE );

BSShaderPPLightingProperty::BSShaderPPLightingProperty() : textureSet(NULL), refractionStrength(0.0f), refractionFirePeriod((int)0), parallaxMaxPasses(4.0f), parallaxScale(1.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSShaderPPLightingProperty::~BSShaderPPLightingProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSShaderPPLightingProperty::GetType() const {
	return TYPE;
}

NiObject * BSShaderPPLightingProperty::Create() {
	return new BSShaderPPLightingProperty;
}

void BSShaderPPLightingProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	BSShaderLightingProperty::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( (info.userVersion2 > 14) ) {
		NifStream( refractionStrength, in, info );
		NifStream( refractionFirePeriod, in, info );
	};
	if ( (info.userVersion2 > 24) ) {
		NifStream( parallaxMaxPasses, in, info );
		NifStream( parallaxScale, in, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( emissiveColor, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderPPLightingProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(textureSet), out, info, link_map, missing_link_stack );
	if ( (info.userVersion2 > 14) ) {
		NifStream( refractionStrength, out, info );
		NifStream( refractionFirePeriod, out, info );
	};
	if ( (info.userVersion2 > 24) ) {
		NifStream( parallaxMaxPasses, out, info );
		NifStream( parallaxScale, out, info );
	};
	if ( (info.userVersion2 > 34) ) {
		NifStream( emissiveColor, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSShaderPPLightingProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << BSShaderLightingProperty::asString();
	out << "  Texture Set:  " << textureSet << endl;
	out << "  Refraction Strength:  " << refractionStrength << endl;
	out << "  Refraction Fire Period:  " << refractionFirePeriod << endl;
	out << "  Parallax Max Passes:  " << parallaxMaxPasses << endl;
	out << "  Parallax Scale:  " << parallaxScale << endl;
	out << "  Emissive Color:  " << emissiveColor << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderPPLightingProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::FixLinks( objects, link_stack, missing_link_stack, info );
	textureSet = FixLink<BSShaderTextureSet>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSShaderPPLightingProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShaderLightingProperty::GetRefs();
	if ( textureSet != NULL )
		refs.push_back(StaticCast<NiObject>(textureSet));
	return refs;
}

std::list<NiObject *> BSShaderPPLightingProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSShaderLightingProperty::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<BSShaderTextureSet > BSShaderPPLightingProperty::GetTextureSet() const {
	return textureSet;
}

void BSShaderPPLightingProperty::SetTextureSet( Ref<BSShaderTextureSet > value ) {
	textureSet = value;
}

//--END CUSTOM CODE--//
