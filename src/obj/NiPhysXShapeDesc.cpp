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
#include "../../include/obj/NiPhysXShapeDesc.h"
#include "../../include/gen/NxCapsule.h"
#include "../../include/gen/NxPlane.h"
#include "../../include/obj/NiPhysXMeshDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXShapeDesc::TYPE("NiPhysXShapeDesc", &NiObject::TYPE );

NiPhysXShapeDesc::NiPhysXShapeDesc() : shapeType((NxShapeType)0), shapeFlags((unsigned int)0), collisionGroup((unsigned short)0), materialIndex((unsigned short)0), density(0.0f), mass(0.0f), skinWidth(0.0f), non_interactingCompartmentTypes((unsigned int)0), sphereRadius(0.0f), mesh(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXShapeDesc::~NiPhysXShapeDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXShapeDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXShapeDesc::Create() {
	return new NiPhysXShapeDesc;
}

void NiPhysXShapeDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( shapeType, in, info );
	NifStream( localPose, in, info );
	NifStream( shapeFlags, in, info );
	NifStream( collisionGroup, in, info );
	NifStream( materialIndex, in, info );
	NifStream( density, in, info );
	NifStream( mass, in, info );
	NifStream( skinWidth, in, info );
	NifStream( shapeName, in, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( non_interactingCompartmentTypes, in, info );
	};
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( collisionBits[i1], in, info );
	};
	if ( (shapeType == 0) ) {
		NifStream( plane.val1, in, info );
		NifStream( plane.point1, in, info );
	};
	if ( (shapeType == 1) ) {
		NifStream( sphereRadius, in, info );
	};
	if ( (shapeType == 2) ) {
		NifStream( boxHalfExtents, in, info );
	};
	if ( (shapeType == 3) ) {
		NifStream( capsule.val1, in, info );
		NifStream( capsule.val2, in, info );
		NifStream( capsule.capsuleFlags, in, info );
	};
	if ( ((shapeType == 5) || (shapeType == 6)) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXShapeDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	NifStream( shapeType, out, info );
	NifStream( localPose, out, info );
	NifStream( shapeFlags, out, info );
	NifStream( collisionGroup, out, info );
	NifStream( materialIndex, out, info );
	NifStream( density, out, info );
	NifStream( mass, out, info );
	NifStream( skinWidth, out, info );
	NifStream( shapeName, out, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( non_interactingCompartmentTypes, out, info );
	};
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( collisionBits[i1], out, info );
	};
	if ( (shapeType == 0) ) {
		NifStream( plane.val1, out, info );
		NifStream( plane.point1, out, info );
	};
	if ( (shapeType == 1) ) {
		NifStream( sphereRadius, out, info );
	};
	if ( (shapeType == 2) ) {
		NifStream( boxHalfExtents, out, info );
	};
	if ( (shapeType == 3) ) {
		NifStream( capsule.val1, out, info );
		NifStream( capsule.val2, out, info );
		NifStream( capsule.capsuleFlags, out, info );
	};
	if ( ((shapeType == 5) || (shapeType == 6)) ) {
		WriteRef( StaticCast<NiObject>(mesh), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXShapeDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	out << "  Shape Type:  " << shapeType << endl;
	out << "  Local Pose:  " << localPose << endl;
	out << "  Shape Flags:  " << shapeFlags << endl;
	out << "  Collision Group:  " << collisionGroup << endl;
	out << "  Material Index:  " << materialIndex << endl;
	out << "  Density:  " << density << endl;
	out << "  Mass:  " << mass << endl;
	out << "  Skin Width:  " << skinWidth << endl;
	out << "  Shape Name:  " << shapeName << endl;
	out << "  Non-Interacting Compartment Types:  " << non_interactingCompartmentTypes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Collision Bits[" << i1 << "]:  " << collisionBits[i1] << endl;
		array_output_count++;
	};
	if ( (shapeType == 0) ) {
		out << "    Val 1:  " << plane.val1 << endl;
		out << "    Point 1:  " << plane.point1 << endl;
	};
	if ( (shapeType == 1) ) {
		out << "    Sphere Radius:  " << sphereRadius << endl;
	};
	if ( (shapeType == 2) ) {
		out << "    Box Half Extents:  " << boxHalfExtents << endl;
	};
	if ( (shapeType == 3) ) {
		out << "    Val 1:  " << capsule.val1 << endl;
		out << "    Val 2:  " << capsule.val2 << endl;
		out << "    Capsule Flags:  " << capsule.capsuleFlags << endl;
	};
	if ( ((shapeType == 5) || (shapeType == 6)) ) {
		out << "    Mesh:  " << mesh << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXShapeDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( ((shapeType == 5) || (shapeType == 6)) ) {
		mesh = FixLink<NiPhysXMeshDesc>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXShapeDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( mesh != NULL )
		refs.push_back(StaticCast<NiObject>(mesh));
	return refs;
}

std::list<NiObject *> NiPhysXShapeDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
