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
#include "../../include/obj/NiPathController.h"
#include "../../include/obj/NiFloatData.h"
#include "../../include/obj/NiPosData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPathController::TYPE("NiPathController", &NiTimeController::TYPE );

NiPathController::NiPathController() : pathFlags((PathFlags)0), bankDir((int)1), maxBankAngle(0.0f), smoothing(0.0f), followAxis((short)0), pathData(NULL), percentData(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPathController::~NiPathController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPathController::GetType() const {
	return TYPE;
}

NiObject * NiPathController::Create() {
	return new NiPathController;
}

void NiPathController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( pathFlags, in, info );
	};
	NifStream( bankDir, in, info );
	NifStream( maxBankAngle, in, info );
	NifStream( smoothing, in, info );
	NifStream( followAxis, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPathController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTimeController::Write( out, link_map, missing_link_stack, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( pathFlags, out, info );
	};
	NifStream( bankDir, out, info );
	NifStream( maxBankAngle, out, info );
	NifStream( smoothing, out, info );
	NifStream( followAxis, out, info );
	WriteRef( StaticCast<NiObject>(pathData), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(percentData), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPathController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << NiTimeController::asString();
	out << "  Path Flags:  " << pathFlags << endl;
	out << "  Bank Dir:  " << bankDir << endl;
	out << "  Max Bank Angle:  " << maxBankAngle << endl;
	out << "  Smoothing:  " << smoothing << endl;
	out << "  Follow Axis:  " << followAxis << endl;
	out << "  Path Data:  " << pathData << endl;
	out << "  Percent Data:  " << percentData << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPathController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiTimeController::FixLinks( objects, link_stack, missing_link_stack, info );
	pathData = FixLink<NiPosData>( objects, link_stack, missing_link_stack, info );
	percentData = FixLink<NiFloatData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPathController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( pathData != NULL )
		refs.push_back(StaticCast<NiObject>(pathData));
	if ( percentData != NULL )
		refs.push_back(StaticCast<NiObject>(percentData));
	return refs;
}

std::list<NiObject *> NiPathController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTimeController::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<NiFloatData> NiPathController::GetFloatData() const {
	return floatData;
}

void NiPathController::SetFloatData( NiFloatData * n ) {
	floatData = n;
}

Ref<NiPosData> NiPathController::GetPosData() const {
	return posData;
}

void NiPathController::SetPosData( NiPosData * n ) {
	posData = n;
}

//--END CUSTOM CODE--//
