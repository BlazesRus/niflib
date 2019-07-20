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
#include "../../include/obj/NiPSDragForce.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSDragForce::TYPE("NiPSDragForce", &NiPSForce::TYPE );

NiPSDragForce::NiPSDragForce() : percentage(0.0f), range(0.0f), rangeFalloff(0.0f), dragObject(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSDragForce::~NiPSDragForce() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSDragForce::GetType() const {
	return TYPE;
}

NiObject * NiPSDragForce::Create() {
	return new NiPSDragForce;
}

void NiPSDragForce::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSForce::Read( in, link_stack, info );
	NifStream( dragAxis, in, info );
	NifStream( percentage, in, info );
	NifStream( range, in, info );
	NifStream( rangeFalloff, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSDragForce::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::Write( out, link_map, missing_link_stack, info );
	NifStream( dragAxis, out, info );
	NifStream( percentage, out, info );
	NifStream( range, out, info );
	NifStream( rangeFalloff, out, info );
	WriteRef( StaticCast<NiObject>(dragObject), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSDragForce::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSForce::asString();
	out << "  Drag Axis:  " << dragAxis << endl;
	out << "  Percentage:  " << percentage << endl;
	out << "  Range:  " << range << endl;
	out << "  Range Falloff:  " << rangeFalloff << endl;
	out << "  Drag Object:  " << dragObject << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSDragForce::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSForce::FixLinks( objects, link_stack, missing_link_stack, info );
	dragObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSDragForce::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSForce::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSDragForce::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSForce::GetPtrs();
	if ( dragObject != NULL )
		ptrs.push_back((NiObject *)(dragObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
