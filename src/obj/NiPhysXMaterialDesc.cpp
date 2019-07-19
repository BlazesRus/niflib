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
#include "../../include/obj/NiPhysXMaterialDesc.h"
#include "../../include/gen/NxMaterialDesc.h"
#include "../../include/gen/NxSpringDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXMaterialDesc::TYPE("NiPhysXMaterialDesc", &NiObject::TYPE );

NiPhysXMaterialDesc::NiPhysXMaterialDesc() : index((unsigned short)0), numStates((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXMaterialDesc::~NiPhysXMaterialDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXMaterialDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXMaterialDesc::Create() {
	return new NiPhysXMaterialDesc;
}

void NiPhysXMaterialDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( index, in, info );
	NifStream( numStates, in, info );
	materialDescs.resize(numStates);
	for (unsigned int i1 = 0; i1 < materialDescs.size(); i1++) {
		NifStream( materialDescs[i1].dynamicFriction, in, info );
		NifStream( materialDescs[i1].staticFriction, in, info );
		NifStream( materialDescs[i1].restitution, in, info );
		NifStream( materialDescs[i1].dynamicFrictionV, in, info );
		NifStream( materialDescs[i1].staticFrictionV, in, info );
		NifStream( materialDescs[i1].directionOfAnisotropy, in, info );
		NifStream( materialDescs[i1].flags, in, info );
		NifStream( materialDescs[i1].frictionCombineMode, in, info );
		NifStream( materialDescs[i1].restitutionCombineMode, in, info );
		if ( info.version <= 0x14020300 ) {
			NifStream( materialDescs[i1].hasSpring, in, info );
			if ( materialDescs[i1].hasSpring ) {
				NifStream( materialDescs[i1].spring.spring, in, info );
				NifStream( materialDescs[i1].spring.damper, in, info );
				NifStream( materialDescs[i1].spring.targetValue, in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXMaterialDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numStates = (unsigned int)(materialDescs.size());
	NifStream( index, out, info );
	NifStream( numStates, out, info );
	for (unsigned int i1 = 0; i1 < materialDescs.size(); i1++) {
		NifStream( materialDescs[i1].dynamicFriction, out, info );
		NifStream( materialDescs[i1].staticFriction, out, info );
		NifStream( materialDescs[i1].restitution, out, info );
		NifStream( materialDescs[i1].dynamicFrictionV, out, info );
		NifStream( materialDescs[i1].staticFrictionV, out, info );
		NifStream( materialDescs[i1].directionOfAnisotropy, out, info );
		NifStream( materialDescs[i1].flags, out, info );
		NifStream( materialDescs[i1].frictionCombineMode, out, info );
		NifStream( materialDescs[i1].restitutionCombineMode, out, info );
		if ( info.version <= 0x14020300 ) {
			NifStream( materialDescs[i1].hasSpring, out, info );
			if ( materialDescs[i1].hasSpring ) {
				NifStream( materialDescs[i1].spring.spring, out, info );
				NifStream( materialDescs[i1].spring.damper, out, info );
				NifStream( materialDescs[i1].spring.targetValue, out, info );
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXMaterialDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numStates = (unsigned int)(materialDescs.size());
	out << "  Index:  " << index << endl;
	out << "  Num States:  " << numStates << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < materialDescs.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Dynamic Friction:  " << materialDescs[i1].dynamicFriction << endl;
		out << "    Static Friction:  " << materialDescs[i1].staticFriction << endl;
		out << "    Restitution:  " << materialDescs[i1].restitution << endl;
		out << "    Dynamic Friction V:  " << materialDescs[i1].dynamicFrictionV << endl;
		out << "    Static Friction V:  " << materialDescs[i1].staticFrictionV << endl;
		out << "    Direction of Anisotropy:  " << materialDescs[i1].directionOfAnisotropy << endl;
		out << "    Flags:  " << materialDescs[i1].flags << endl;
		out << "    Friction Combine Mode:  " << materialDescs[i1].frictionCombineMode << endl;
		out << "    Restitution Combine Mode:  " << materialDescs[i1].restitutionCombineMode << endl;
		out << "    Has Spring:  " << materialDescs[i1].hasSpring << endl;
		if ( materialDescs[i1].hasSpring ) {
			out << "      Spring:  " << materialDescs[i1].spring.spring << endl;
			out << "      Damper:  " << materialDescs[i1].spring.damper << endl;
			out << "      Target Value:  " << materialDescs[i1].spring.targetValue << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXMaterialDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXMaterialDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPhysXMaterialDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
