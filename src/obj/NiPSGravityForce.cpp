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
#include "../../include/obj/NiPSGravityForce.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSGravityForce::TYPE("NiPSGravityForce", &NiPSForce::TYPE );

NiPSGravityForce::NiPSGravityForce() : decay(0.0f), strength(0.0f), forceType((ForceType)0), turbulence(0.0f), turbulenceScale(0.0f), gravityObject(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSGravityForce::~NiPSGravityForce() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSGravityForce::GetType() const {
	return TYPE;
}

NiObject * NiPSGravityForce::Create() {
	return new NiPSGravityForce;
}

void NiPSGravityForce::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSForce::Read( in, link_stack, info );
	NifStream( gravityAxis, in, info );
	NifStream( decay, in, info );
	NifStream( strength, in, info );
	NifStream( forceType, in, info );
	NifStream( turbulence, in, info );
	NifStream( turbulenceScale, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSGravityForce::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::Write( out, link_map, missing_link_stack, info );
	NifStream( gravityAxis, out, info );
	NifStream( decay, out, info );
	NifStream( strength, out, info );
	NifStream( forceType, out, info );
	NifStream( turbulence, out, info );
	NifStream( turbulenceScale, out, info );
	WriteRef( StaticCast<NiObject>(gravityObject), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSGravityForce::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSForce::asString();
	out << "  Gravity Axis:  " << gravityAxis << endl;
	out << "  Decay:  " << decay << endl;
	out << "  Strength:  " << strength << endl;
	out << "  Force Type:  " << forceType << endl;
	out << "  Turbulence:  " << turbulence << endl;
	out << "  Turbulence Scale:  " << turbulenceScale << endl;
	out << "  Gravity Object:  " << gravityObject << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSGravityForce::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::FixLinks( objects, link_stack, missing_link_stack, info );
	gravityObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSGravityForce::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSForce::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSGravityForce::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSForce::GetPtrs();
	if ( gravityObject != NULL )
		ptrs.push_back((NiObject *)(gravityObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
