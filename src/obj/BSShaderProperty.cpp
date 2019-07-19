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
#include "../../include/obj/BSShaderProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSShaderProperty::TYPE("BSShaderProperty", &NiShadeProperty::TYPE );

BSShaderProperty::BSShaderProperty() : shaderType((BSShaderType)SHADER_DEFAULT), shaderFlags((BSShaderFlags)0x82000000), shaderFlags2((BSShaderFlags2)1), environmentMapScale(1.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSShaderProperty::~BSShaderProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSShaderProperty::GetType() const {
	return TYPE;
}

NiObject * BSShaderProperty::Create() {
	return new BSShaderProperty;
}

void BSShaderProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::Read( in, link_stack, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( shaderType, in, info );
		NifStream( shaderFlags, in, info );
		NifStream( shaderFlags2, in, info );
		NifStream( environmentMapScale, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion2 <= 34) ) {
		NifStream( shaderType, out, info );
		NifStream( shaderFlags, out, info );
		NifStream( shaderFlags2, out, info );
		NifStream( environmentMapScale, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSShaderProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiShadeProperty::asString();
	out << "  Shader Type:  " << shaderType << endl;
	out << "  Shader Flags:  " << shaderFlags << endl;
	out << "  Shader Flags 2:  " << shaderFlags2 << endl;
	out << "  Environment Map Scale:  " << environmentMapScale << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiShadeProperty::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSShaderProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiShadeProperty::GetRefs();
	return refs;
}

std::list<NiObject *> BSShaderProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiShadeProperty::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

unsigned short BSShaderProperty::GetFlags() const {
   return flags;
}

void BSShaderProperty::SetFlags( unsigned short value ) {
   flags = value;
}

BSShaderType BSShaderProperty::GetShaderType() const {
   return shaderType;
}

void BSShaderProperty::SetShaderType( const BSShaderType & value ) {
   shaderType = value;
}

BSShaderFlags BSShaderProperty::GetShaderFlags() const {
   return shaderFlags;
}

void BSShaderProperty::SetShaderFlags( const BSShaderFlags & value ) {
   shaderFlags = value;
}

float BSShaderProperty::GetEnvmapScale() const {
   return envmapScale;
}

void BSShaderProperty::SetEnvmapScale( float value ) {
   envmapScale = value;
}

//--END CUSTOM CODE--//
