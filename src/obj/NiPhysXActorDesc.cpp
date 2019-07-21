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
#include "../../include/obj/NiPhysXActorDesc.h"
#include "../../include/gen/Matrix34.h"
#include "../../include/obj/NiPhysXBodyDesc.h"
#include "../../include/obj/NiPhysXRigidBodyDest.h"
#include "../../include/obj/NiPhysXRigidBodySrc.h"
#include "../../include/obj/NiPhysXShapeDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXActorDesc::TYPE("NiPhysXActorDesc", &NiObject::TYPE );

NiPhysXActorDesc::NiPhysXActorDesc() : numPoses((unsigned int)0), bodyDesc(NULL), density(0.0f), actorFlags((unsigned int)0), actorGroup((unsigned short)0), dominanceGroup((unsigned short)0), contactReportFlags((unsigned int)0), forceFieldMaterial((unsigned short)0), dummy((unsigned int)0), numShapeDescs((unsigned int)0), actorParent(NULL), source(NULL), dest(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXActorDesc::~NiPhysXActorDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXActorDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXActorDesc::Create() {
	return new NiPhysXActorDesc;
}

void NiPhysXActorDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( actorName, in, info );
	NifStream( numPoses, in, info );
	poses.resize(numPoses);
	for (unsigned int i1 = 0; i1 < poses.size(); i1++) {
		NifStream( poses[i1].m11, in, info );
		NifStream( poses[i1].m21, in, info );
		NifStream( poses[i1].m31, in, info );
		NifStream( poses[i1].m12, in, info );
		NifStream( poses[i1].m22, in, info );
		NifStream( poses[i1].m32, in, info );
		NifStream( poses[i1].m13, in, info );
		NifStream( poses[i1].m23, in, info );
		NifStream( poses[i1].m33, in, info );
		NifStream( poses[i1].m14, in, info );
		NifStream( poses[i1].m24, in, info );
		NifStream( poses[i1].m34, in, info );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( density, in, info );
	NifStream( actorFlags, in, info );
	NifStream( actorGroup, in, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( dominanceGroup, in, info );
		NifStream( contactReportFlags, in, info );
		NifStream( forceFieldMaterial, in, info );
	};
	if ( ( info.version >= 0x14030001 ) && ( info.version <= 0x14030005 ) ) {
		NifStream( dummy, in, info );
	};
	NifStream( numShapeDescs, in, info );
	shapeDescriptions.resize(numShapeDescs);
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXActorDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numShapeDescs = (unsigned int)(shapeDescriptions.size());
	numPoses = (unsigned int)(poses.size());
	NifStream( actorName, out, info );
	NifStream( numPoses, out, info );
	for (unsigned int i1 = 0; i1 < poses.size(); i1++) {
		NifStream( poses[i1].m11, out, info );
		NifStream( poses[i1].m21, out, info );
		NifStream( poses[i1].m31, out, info );
		NifStream( poses[i1].m12, out, info );
		NifStream( poses[i1].m22, out, info );
		NifStream( poses[i1].m32, out, info );
		NifStream( poses[i1].m13, out, info );
		NifStream( poses[i1].m23, out, info );
		NifStream( poses[i1].m33, out, info );
		NifStream( poses[i1].m14, out, info );
		NifStream( poses[i1].m24, out, info );
		NifStream( poses[i1].m34, out, info );
	};
	WriteRef( StaticCast<NiObject>(bodyDesc), out, info, link_map, missing_link_stack );
	NifStream( density, out, info );
	NifStream( actorFlags, out, info );
	NifStream( actorGroup, out, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( dominanceGroup, out, info );
		NifStream( contactReportFlags, out, info );
		NifStream( forceFieldMaterial, out, info );
	};
	if ( ( info.version >= 0x14030001 ) && ( info.version <= 0x14030005 ) ) {
		NifStream( dummy, out, info );
	};
	NifStream( numShapeDescs, out, info );
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
		WriteRef( StaticCast<NiObject>(shapeDescriptions[i1]), out, info, link_map, missing_link_stack );
	};
	WriteRef( StaticCast<NiObject>(actorParent), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(source), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(dest), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXActorDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numShapeDescs = (unsigned int)(shapeDescriptions.size());
	numPoses = (unsigned int)(poses.size());
	out << "  Actor Name:  " << actorName << endl;
	out << "  Num Poses:  " << numPoses << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < poses.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    m11:  " << poses[i1].m11 << endl;
		out << "    m21:  " << poses[i1].m21 << endl;
		out << "    m31:  " << poses[i1].m31 << endl;
		out << "    m12:  " << poses[i1].m12 << endl;
		out << "    m22:  " << poses[i1].m22 << endl;
		out << "    m32:  " << poses[i1].m32 << endl;
		out << "    m13:  " << poses[i1].m13 << endl;
		out << "    m23:  " << poses[i1].m23 << endl;
		out << "    m33:  " << poses[i1].m33 << endl;
		out << "    m14:  " << poses[i1].m14 << endl;
		out << "    m24:  " << poses[i1].m24 << endl;
		out << "    m34:  " << poses[i1].m34 << endl;
	};
	out << "  Body Desc:  " << bodyDesc << endl;
	out << "  Density:  " << density << endl;
	out << "  Actor Flags:  " << actorFlags << endl;
	out << "  Actor Group:  " << actorGroup << endl;
	out << "  Dominance Group:  " << dominanceGroup << endl;
	out << "  Contact Report Flags:  " << contactReportFlags << endl;
	out << "  Force Field Material:  " << forceFieldMaterial << endl;
	out << "  Dummy:  " << dummy << endl;
	out << "  Num Shape Descs:  " << numShapeDescs << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Shape Descriptions[" << i1 << "]:  " << shapeDescriptions[i1] << endl;
		array_output_count++;
	};
	out << "  Actor Parent:  " << actorParent << endl;
	out << "  Source:  " << source << endl;
	out << "  Dest:  " << dest << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXActorDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	bodyDesc = FixLink<NiPhysXBodyDesc>( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
		shapeDescriptions[i1] = FixLink<NiPhysXShapeDesc>( objects, link_stack, missing_link_stack, info );
	};
	actorParent = FixLink<NiPhysXActorDesc>( objects, link_stack, missing_link_stack, info );
	source = FixLink<NiPhysXRigidBodySrc>( objects, link_stack, missing_link_stack, info );
	dest = FixLink<NiPhysXRigidBodyDest>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXActorDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( bodyDesc != NULL )
		refs.push_back(StaticCast<NiObject>(bodyDesc));
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
		if ( shapeDescriptions[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(shapeDescriptions[i1]));
	};
	if ( actorParent != NULL )
		refs.push_back(StaticCast<NiObject>(actorParent));
	if ( source != NULL )
		refs.push_back(StaticCast<NiObject>(source));
	if ( dest != NULL )
		refs.push_back(StaticCast<NiObject>(dest));
	return refs;
}

std::list<NiObject *> NiPhysXActorDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < shapeDescriptions.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
