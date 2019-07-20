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
#include "../../include/obj/BSShaderNoLightingProperty.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSShaderNoLightingProperty::TYPE("BSShaderNoLightingProperty", &BSShaderLightingProperty::TYPE );

BSShaderNoLightingProperty::BSShaderNoLightingProperty() : falloffStartAngle(1.0f), falloffStopAngle(0.0f), falloffStartOpacity(1.0f), falloffStopOpacity(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSShaderNoLightingProperty::~BSShaderNoLightingProperty() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSShaderNoLightingProperty::GetType() const {
	return TYPE;
}

NiObject * BSShaderNoLightingProperty::Create() {
	return new BSShaderNoLightingProperty;
}

void BSShaderNoLightingProperty::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::Read( in, link_stack, info );
	NifStream( fileName, in, info );
	if ( (info.userVersion2 > 26) ) {
		NifStream( falloffStartAngle, in, info );
		NifStream( falloffStopAngle, in, info );
		NifStream( falloffStartOpacity, in, info );
		NifStream( falloffStopOpacity, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderNoLightingProperty::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::Write( out, link_map, missing_link_stack, info );
	NifStream( fileName, out, info );
	if ( (info.userVersion2 > 26) ) {
		NifStream( falloffStartAngle, out, info );
		NifStream( falloffStopAngle, out, info );
		NifStream( falloffStartOpacity, out, info );
		NifStream( falloffStopOpacity, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSShaderNoLightingProperty::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << BSShaderLightingProperty::asString();
	out << "  File Name:  " << fileName << endl;
	out << "  Falloff Start Angle:  " << falloffStartAngle << endl;
	out << "  Falloff Stop Angle:  " << falloffStopAngle << endl;
	out << "  Falloff Start Opacity:  " << falloffStartOpacity << endl;
	out << "  Falloff Stop Opacity:  " << falloffStopOpacity << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSShaderNoLightingProperty::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	BSShaderLightingProperty::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSShaderNoLightingProperty::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = BSShaderLightingProperty::GetRefs();
	return refs;
}

std::list<NiObject *> BSShaderNoLightingProperty::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = BSShaderLightingProperty::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

string BSShaderNoLightingProperty::GetFileName() const {
	return fileName;
}

void BSShaderNoLightingProperty::SetFileName( const string & value ) {
	fileName = value;
}

//--END CUSTOM CODE--//
