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
#include "../../include/obj/NiPSPlanarCollider.h"
#include "../../include/obj/NiAVObject.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSPlanarCollider::TYPE("NiPSPlanarCollider", &NiPSCollider::TYPE );

NiPSPlanarCollider::NiPSPlanarCollider() : width(0.0f), height(0.0f), colliderObject(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPSPlanarCollider::~NiPSPlanarCollider() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPSPlanarCollider::GetType() const {
	return TYPE;
}

NiObject * NiPSPlanarCollider::Create() {
	return new NiPSPlanarCollider;
}

void NiPSPlanarCollider::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiPSCollider::Read( in, link_stack, info );
	NifStream( width, in, info );
	NifStream( height, in, info );
	NifStream( xAxis, in, info );
	NifStream( yAxis, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSPlanarCollider::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSCollider::Write( out, link_map, missing_link_stack, info );
	NifStream( width, out, info );
	NifStream( height, out, info );
	NifStream( xAxis, out, info );
	NifStream( yAxis, out, info );
	WriteRef( StaticCast<NiObject>(colliderObject), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPSPlanarCollider::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPSCollider::asString();
	out << "  Width:  " << width << endl;
	out << "  Height:  " << height << endl;
	out << "  X Axis:  " << xAxis << endl;
	out << "  Y Axis:  " << yAxis << endl;
	out << "  Collider Object:  " << colliderObject << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPSPlanarCollider::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPSCollider::FixLinks( objects, link_stack, missing_link_stack, info );
	colliderObject = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSPlanarCollider::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPSCollider::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSPlanarCollider::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPSCollider::GetPtrs();
	if ( colliderObject != NULL )
		ptrs.push_back((NiObject *)(colliderObject));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
