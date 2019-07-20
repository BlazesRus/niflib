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
#include "../../include/obj/NiPSysEmitterCtlrData.h"
#include "../../include/gen/KeyGroup.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysEmitterCtlrData::TYPE("NiPSysEmitterCtlrData", &NiObject::TYPE );

NiPSysEmitterCtlrData::NiPSysEmitterCtlrData() : numActiveKeys((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysEmitterCtlrData::~NiPSysEmitterCtlrData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysEmitterCtlrData::GetType() const {
	return TYPE;
}

NiObject * NiPSysEmitterCtlrData::Create() {
	return new NiPSysEmitterCtlrData;
}

void NiPSysEmitterCtlrData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( birthRateKeys.numKeys, in, info );
	if ( (birthRateKeys.numKeys != 0) ) {
		NifStream( birthRateKeys.interpolation, in, info );
	};
	birthRateKeys.keys.resize(birthRateKeys.numKeys);
	for (unsigned int i1 = 0; i1 < birthRateKeys.keys.size(); i1++) {
		NifStream( birthRateKeys.keys[i1], in, info, birthRateKeys.interpolation );
	};
	NifStream( numActiveKeys, in, info );
	activeKeys.resize(numActiveKeys);
	for (unsigned int i1 = 0; i1 < activeKeys.size(); i1++) {
		NifStream( activeKeys[i1], in, info, 1 );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysEmitterCtlrData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numActiveKeys = (unsigned int)(activeKeys.size());
	birthRateKeys.numKeys = (unsigned int)(birthRateKeys.keys.size());
	NifStream( birthRateKeys.numKeys, out, info );
	if ( (birthRateKeys.numKeys != 0) ) {
		NifStream( birthRateKeys.interpolation, out, info );
	};
	for (unsigned int i1 = 0; i1 < birthRateKeys.keys.size(); i1++) {
		NifStream( birthRateKeys.keys[i1], out, info, birthRateKeys.interpolation );
	};
	NifStream( numActiveKeys, out, info );
	for (unsigned int i1 = 0; i1 < activeKeys.size(); i1++) {
		NifStream( activeKeys[i1], out, info, 1 );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysEmitterCtlrData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numActiveKeys = (unsigned int)(activeKeys.size());
	birthRateKeys.numKeys = (unsigned int)(birthRateKeys.keys.size());
	out << "  Num Keys:  " << birthRateKeys.numKeys << endl;
	if ( (birthRateKeys.numKeys != 0) ) {
		out << "    Interpolation:  " << birthRateKeys.interpolation << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < birthRateKeys.keys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Keys[" << i1 << "]:  " << birthRateKeys.keys[i1] << endl;
		array_output_count++;
	};
	out << "  Num Active Keys:  " << numActiveKeys << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < activeKeys.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Active Keys[" << i1 << "]:  " << activeKeys[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysEmitterCtlrData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysEmitterCtlrData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysEmitterCtlrData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
