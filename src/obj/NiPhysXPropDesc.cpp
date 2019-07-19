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
#include "../../include/obj/NiPhysXPropDesc.h"
#include "../../include/gen/PhysXMaterialRef.h"
#include "../../include/gen/PhysXStateName.h"
#include "../../include/obj/NiObject.h"
#include "../../include/obj/NiPhysXActorDesc.h"
#include "../../include/obj/NiPhysXJointDesc.h"
#include "../../include/obj/NiPhysXMaterialDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXPropDesc::TYPE("NiPhysXPropDesc", &NiObject::TYPE );

NiPhysXPropDesc::NiPhysXPropDesc() : numActors((int)0), numJoints((unsigned int)0), numClothes((unsigned int)0), numMaterials((unsigned int)0), numStates((unsigned int)0), numStateNames((unsigned int)0), flags((byte)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXPropDesc::~NiPhysXPropDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXPropDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXPropDesc::Create() {
	return new NiPhysXPropDesc;
}

void NiPhysXPropDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( numActors, in, info );
	actors.resize(numActors);
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numJoints, in, info );
	joints.resize(numJoints);
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( info.version >= 0x14030005 ) {
		NifStream( numClothes, in, info );
		clothes.resize(numClothes);
		for (unsigned int i2 = 0; i2 < clothes.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	NifStream( numMaterials, in, info );
	materials.resize(numMaterials);
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
		NifStream( materials[i1].key, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numStates, in, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( numStateNames, in, info );
		stateNames.resize(numStateNames);
		for (unsigned int i2 = 0; i2 < stateNames.size(); i2++) {
			NifStream( stateNames[i2].name, in, info );
			NifStream( stateNames[i2].index, in, info );
		};
		NifStream( flags, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXPropDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numStateNames = (unsigned int)(stateNames.size());
	numMaterials = (unsigned int)(materials.size());
	numClothes = (unsigned int)(clothes.size());
	numJoints = (unsigned int)(joints.size());
	numActors = (int)(actors.size());
	NifStream( numActors, out, info );
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
		WriteRef( StaticCast<NiObject>(actors[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numJoints, out, info );
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
		WriteRef( StaticCast<NiObject>(joints[i1]), out, info, link_map, missing_link_stack );
	};
	if ( info.version >= 0x14030005 ) {
		NifStream( numClothes, out, info );
		for (unsigned int i2 = 0; i2 < clothes.size(); i2++) {
			WriteRef( StaticCast<NiObject>(clothes[i2]), out, info, link_map, missing_link_stack );
		};
	};
	NifStream( numMaterials, out, info );
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
		NifStream( materials[i1].key, out, info );
		WriteRef( StaticCast<NiObject>(materials[i1].materialDesc), out, info, link_map, missing_link_stack );
	};
	NifStream( numStates, out, info );
	if ( info.version >= 0x14040000 ) {
		NifStream( numStateNames, out, info );
		for (unsigned int i2 = 0; i2 < stateNames.size(); i2++) {
			NifStream( stateNames[i2].name, out, info );
			NifStream( stateNames[i2].index, out, info );
		};
		NifStream( flags, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXPropDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numStateNames = (unsigned int)(stateNames.size());
	numMaterials = (unsigned int)(materials.size());
	numClothes = (unsigned int)(clothes.size());
	numJoints = (unsigned int)(joints.size());
	numActors = (int)(actors.size());
	out << "  Num Actors:  " << numActors << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Actors[" << i1 << "]:  " << actors[i1] << endl;
		array_output_count++;
	};
	out << "  Num Joints:  " << numJoints << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Joints[" << i1 << "]:  " << joints[i1] << endl;
		array_output_count++;
	};
	out << "  Num Clothes:  " << numClothes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < clothes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Clothes[" << i1 << "]:  " << clothes[i1] << endl;
		array_output_count++;
	};
	out << "  Num Materials:  " << numMaterials << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Key:  " << materials[i1].key << endl;
		out << "    Material Desc:  " << materials[i1].materialDesc << endl;
	};
	out << "  Num States:  " << numStates << endl;
	out << "  Num State Names:  " << numStateNames << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stateNames.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Name:  " << stateNames[i1].name << endl;
		out << "    Index:  " << stateNames[i1].index << endl;
	};
	out << "  Flags:  " << flags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXPropDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
		actors[i1] = FixLink<NiPhysXActorDesc>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
		joints[i1] = FixLink<NiPhysXJointDesc>( objects, link_stack, missing_link_stack, info );
	};
	if ( info.version >= 0x14030005 ) {
		for (unsigned int i2 = 0; i2 < clothes.size(); i2++) {
			clothes[i2] = FixLink<NiObject>( objects, link_stack, missing_link_stack, info );
		};
	};
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
		materials[i1].materialDesc = FixLink<NiPhysXMaterialDesc>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXPropDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
		if ( actors[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(actors[i1]));
	};
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
		if ( joints[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(joints[i1]));
	};
	for (unsigned int i1 = 0; i1 < clothes.size(); i1++) {
		if ( clothes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(clothes[i1]));
	};
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
		if ( materials[i1].materialDesc != NULL )
			refs.push_back(StaticCast<NiObject>(materials[i1].materialDesc));
	};
	return refs;
}

std::list<NiObject *> NiPhysXPropDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < actors.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < joints.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < clothes.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < materials.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
