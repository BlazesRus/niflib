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
#include "../../include/obj/NiCollisionData.h"
#include "../../include/gen/BoundingVolume.h"
#include "../../include/gen/BoxBV.h"
#include "../../include/gen/CapsuleBV.h"
#include "../../include/gen/HalfSpaceBV.h"
#include "../../include/gen/NiBound.h"
#include "../../include/gen/NiPlane.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiCollisionData::TYPE("NiCollisionData", &NiCollisionObject::TYPE );

NiCollisionData::NiCollisionData() : propagationMode((PropagationMode)0), collisionMode((CollisionMode)0), useAbv((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiCollisionData::~NiCollisionData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiCollisionData::GetType() const {
	return TYPE;
}

NiObject * NiCollisionData::Create() {
	return new NiCollisionData;
}

void NiCollisionData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::Read( in, link_stack, info );
	NifStream( propagationMode, in, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( collisionMode, in, info );
	};
	NifStream( useAbv, in, info );
	if ( (useAbv == 1) ) {
		NifStream( boundingVolume.collisionType, in, info );
		if ( (boundingVolume.collisionType == 0) ) {
			NifStream( boundingVolume.sphere.center, in, info );
			NifStream( boundingVolume.sphere.radius, in, info );
		};
		if ( (boundingVolume.collisionType == 1) ) {
			NifStream( boundingVolume.box.center, in, info );
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				NifStream( boundingVolume.box.axis[i3], in, info );
			};
			NifStream( boundingVolume.box.extent, in, info );
		};
		if ( (boundingVolume.collisionType == 2) ) {
			NifStream( boundingVolume.capsule.center, in, info );
			NifStream( boundingVolume.capsule.origin, in, info );
			NifStream( boundingVolume.capsule.extent, in, info );
			NifStream( boundingVolume.capsule.radius, in, info );
		};
		if ( (boundingVolume.collisionType == 5) ) {
			NifStream( boundingVolume.halfSpace.plane.normal, in, info );
			NifStream( boundingVolume.halfSpace.plane.constant, in, info );
			NifStream( boundingVolume.halfSpace.center, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::Write( out, link_map, missing_link_stack, info );
	NifStream( propagationMode, out, info );
	if ( info.version >= 0x0A010000 ) {
		NifStream( collisionMode, out, info );
	};
	NifStream( useAbv, out, info );
	if ( (useAbv == 1) ) {
		NifStream( boundingVolume.collisionType, out, info );
		if ( (boundingVolume.collisionType == 0) ) {
			NifStream( boundingVolume.sphere.center, out, info );
			NifStream( boundingVolume.sphere.radius, out, info );
		};
		if ( (boundingVolume.collisionType == 1) ) {
			NifStream( boundingVolume.box.center, out, info );
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				NifStream( boundingVolume.box.axis[i3], out, info );
			};
			NifStream( boundingVolume.box.extent, out, info );
		};
		if ( (boundingVolume.collisionType == 2) ) {
			NifStream( boundingVolume.capsule.center, out, info );
			NifStream( boundingVolume.capsule.origin, out, info );
			NifStream( boundingVolume.capsule.extent, out, info );
			NifStream( boundingVolume.capsule.radius, out, info );
		};
		if ( (boundingVolume.collisionType == 5) ) {
			NifStream( boundingVolume.halfSpace.plane.normal, out, info );
			NifStream( boundingVolume.halfSpace.plane.constant, out, info );
			NifStream( boundingVolume.halfSpace.center, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiCollisionData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiCollisionObject::asString();
	out << "  Propagation Mode:  " << propagationMode << endl;
	out << "  Collision Mode:  " << collisionMode << endl;
	out << "  Use ABV:  " << useAbv << endl;
	if ( (useAbv == 1) ) {
		out << "    Collision Type:  " << boundingVolume.collisionType << endl;
		if ( (boundingVolume.collisionType == 0) ) {
			out << "      Center:  " << boundingVolume.sphere.center << endl;
			out << "      Radius:  " << boundingVolume.sphere.radius << endl;
		};
		if ( (boundingVolume.collisionType == 1) ) {
			out << "      Center:  " << boundingVolume.box.center << endl;
			array_output_count = 0;
			for (unsigned int i3 = 0; i3 < 3; i3++) {
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
					break;
				};
				if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
					break;
				};
				out << "        Axis[" << i3 << "]:  " << boundingVolume.box.axis[i3] << endl;
				array_output_count++;
			};
			out << "      Extent:  " << boundingVolume.box.extent << endl;
		};
		if ( (boundingVolume.collisionType == 2) ) {
			out << "      Center:  " << boundingVolume.capsule.center << endl;
			out << "      Origin:  " << boundingVolume.capsule.origin << endl;
			out << "      Extent:  " << boundingVolume.capsule.extent << endl;
			out << "      Radius:  " << boundingVolume.capsule.radius << endl;
		};
		if ( (boundingVolume.collisionType == 5) ) {
			out << "      Normal:  " << boundingVolume.halfSpace.plane.normal << endl;
			out << "      Constant:  " << boundingVolume.halfSpace.plane.constant << endl;
			out << "      Center:  " << boundingVolume.halfSpace.center << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiCollisionData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiCollisionObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiCollisionData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiCollisionObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiCollisionData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiCollisionObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
