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
#include "../../include/obj/NiPSysGravityModifier.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysGravityModifier::TYPE("NiPSysGravityModifier", &NiPSysModifier::TYPE );

NiPSysGravityModifier::NiPSysGravityModifier() : gravityObject(NULL), gravityAxis(1.0, 0.0, 0.0), decay(0.0f), strength(1.0f), forceType((ForceType)0), turbulence(0.0f), turbulenceScale(1.0f), worldAligned(false) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysGravityModifier::~NiPSysGravityModifier() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysGravityModifier::GetType() const {
	return TYPE;
}

NiObject * NiPSysGravityModifier::Create() {
	return new NiPSysGravityModifier;
}

void NiPSysGravityModifier::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSysModifier::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( gravityAxis, in, info );
	NifStream( decay, in, info );
	NifStream( strength, in, info );
	NifStream( forceType, in, info );
	NifStream( turbulence, in, info );
	NifStream( turbulenceScale, in, info );
	if ( (info.userVersion2 > 16) ) {
		NifStream( worldAligned, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysGravityModifier::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(gravityObject), out, info, link_map, missing_link_stack );
	NifStream( gravityAxis, out, info );
	NifStream( decay, out, info );
	NifStream( strength, out, info );
	NifStream( forceType, out, info );
	NifStream( turbulence, out, info );
	NifStream( turbulenceScale, out, info );
	if ( (info.userVersion2 > 16) ) {
		NifStream( worldAligned, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysGravityModifier::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSysModifier::asString();
	out << "  Gravity Object:  " << gravityObject << endl;
	out << "  Gravity Axis:  " << gravityAxis << endl;
	out << "  Decay:  " << decay << endl;
	out << "  Strength:  " << strength << endl;
	out << "  Force Type:  " << forceType << endl;
	out << "  Turbulence:  " << turbulence << endl;
	out << "  Turbulence Scale:  " << turbulenceScale << endl;
	out << "  World Aligned:  " << worldAligned << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysGravityModifier::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiPSysModifier::FixLinks( objects, link_stack, missing_link_stack, info );
	gravityObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysGravityModifier::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSysModifier::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysGravityModifier::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSysModifier::GetPtrs();
	if ( gravityObject != NULL )
		ptrs.push_back((NiObject *)(gravityObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
