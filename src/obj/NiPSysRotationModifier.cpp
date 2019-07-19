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
#include "../../include/obj/NiPSysRotationModifier.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysRotationModifier::TYPE("NiPSysRotationModifier", &NiPSysModifier::TYPE );

NiPSysRotationModifier::NiPSysRotationModifier() : rotationSpeed(0.0f), rotationSpeedVariation(0.0f), rotationAngle(0.0f), rotationAngleVariation(0.0f), randomRotSpeedSign(false), randomAxis(1), axis(1.0, 0.0, 0.0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysRotationModifier::~NiPSysRotationModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysRotationModifier::GetType() const {
	return TYPE;
}

NiObject * NiPSysRotationModifier::Create() {
	return new NiPSysRotationModifier;
}

void NiPSysRotationModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::Read( in, link_stack, info );
	NifStream( rotationSpeed, in, info );
	if ( info.version >= 0x14000002 ) {
		NifStream( rotationSpeedVariation, in, info );
		NifStream( rotationAngle, in, info );
		NifStream( rotationAngleVariation, in, info );
		NifStream( randomRotSpeedSign, in, info );
	};
	NifStream( randomAxis, in, info );
	NifStream( axis, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysRotationModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::Write( out, link_map, missing_link_stack, info );
	NifStream( rotationSpeed, out, info );
	if ( info.version >= 0x14000002 ) {
		NifStream( rotationSpeedVariation, out, info );
		NifStream( rotationAngle, out, info );
		NifStream( rotationAngleVariation, out, info );
		NifStream( randomRotSpeedSign, out, info );
	};
	NifStream( randomAxis, out, info );
	NifStream( axis, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysRotationModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSysModifier::asString();
	out << "  Rotation Speed:  " << rotationSpeed << endl;
	out << "  Rotation Speed Variation:  " << rotationSpeedVariation << endl;
	out << "  Rotation Angle:  " << rotationAngle << endl;
	out << "  Rotation Angle Variation:  " << rotationAngleVariation << endl;
	out << "  Random Rot Speed Sign:  " << randomRotSpeedSign << endl;
	out << "  Random Axis:  " << randomAxis << endl;
	out << "  Axis:  " << axis << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysRotationModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysRotationModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysRotationModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysModifier::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
