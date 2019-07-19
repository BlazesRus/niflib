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
#include "../../include/obj/bhkBallSocketConstraintChain.h"
#include "../../include/gen/ConstraintInfo.h"
#include "../../include/obj/bhkRigidBody.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkBallSocketConstraintChain::TYPE("bhkBallSocketConstraintChain", &bhkSerializable::TYPE );

bhkBallSocketConstraintChain::bhkBallSocketConstraintChain() : numPivots((unsigned int)0), tau(1.0f), damping(0.6f), constraintForceMixing(1.1920929e-08f), maxErrorDistance(0.1f), numEntitiesA((unsigned int)0), numEntities((unsigned int)2), entityA(NULL), entityB(NULL), priority((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkBallSocketConstraintChain::~bhkBallSocketConstraintChain() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkBallSocketConstraintChain::GetType() const {
	return TYPE;
}

NiObject * bhkBallSocketConstraintChain::Create() {
	return new bhkBallSocketConstraintChain;
}

void bhkBallSocketConstraintChain::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkSerializable::Read( in, link_stack, info );
	NifStream( numPivots, in, info );
	pivots.resize((numPivots / 2));
	for (unsigned int i1 = 0; i1 < pivots.size(); i1++) {
		NifStream( pivots[i1].pivotInA, in, info );
		NifStream( pivots[i1].pivotInB, in, info );
	};
	NifStream( tau, in, info );
	NifStream( damping, in, info );
	NifStream( constraintForceMixing, in, info );
	NifStream( maxErrorDistance, in, info );
	NifStream( numEntitiesA, in, info );
	entitiesA.resize(numEntitiesA);
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numEntities, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( priority, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkBallSocketConstraintChain::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkSerializable::Write( out, link_map, missing_link_stack, info );
	numEntitiesA = (unsigned int)(entitiesA.size());
	numPivots = (unsigned int)(pivots.size());
	NifStream( numPivots, out, info );
	for (unsigned int i1 = 0; i1 < pivots.size(); i1++) {
		NifStream( pivots[i1].pivotInA, out, info );
		NifStream( pivots[i1].pivotInB, out, info );
	};
	NifStream( tau, out, info );
	NifStream( damping, out, info );
	NifStream( constraintForceMixing, out, info );
	NifStream( maxErrorDistance, out, info );
	NifStream( numEntitiesA, out, info );
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
		WriteRef( StaticCast<NiObject>(entitiesA[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numEntities, out, info );
	WriteRef( StaticCast<NiObject>(entityA), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(entityB), out, info, link_map, missing_link_stack );
	NifStream( priority, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkBallSocketConstraintChain::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	numEntitiesA = (unsigned int)(entitiesA.size());
	numPivots = (unsigned int)(pivots.size());
	out << "  Num Pivots:  " << numPivots << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < pivots.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Pivot In A:  " << pivots[i1].pivotInA << endl;
		out << "    Pivot In B:  " << pivots[i1].pivotInB << endl;
	};
	out << "  Tau:  " << tau << endl;
	out << "  Damping:  " << damping << endl;
	out << "  Constraint Force Mixing:  " << constraintForceMixing << endl;
	out << "  Max Error Distance:  " << maxErrorDistance << endl;
	out << "  Num Entities A:  " << numEntitiesA << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Entities A[" << i1 << "]:  " << entitiesA[i1] << endl;
		array_output_count++;
	};
	out << "  Num Entities:  " << numEntities << endl;
	out << "  Entity A:  " << entityA << endl;
	out << "  Entity B:  " << entityB << endl;
	out << "  Priority:  " << priority << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkBallSocketConstraintChain::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkSerializable::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
		entitiesA[i1] = FixLink<bhkRigidBody>( objects, link_stack, missing_link_stack, info );
	};
	entityA = FixLink<bhkRigidBody>( objects, link_stack, missing_link_stack, info );
	entityB = FixLink<bhkRigidBody>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkBallSocketConstraintChain::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
	};
	return refs;
}

std::list<NiObject *> bhkBallSocketConstraintChain::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkSerializable::GetPtrs();
	for (unsigned int i1 = 0; i1 < entitiesA.size(); i1++) {
		if ( entitiesA[i1] != NULL )
			ptrs.push_back((NiObject *)(entitiesA[i1]));
	};
	if ( entityA != NULL )
		ptrs.push_back((NiObject *)(entityA));
	if ( entityB != NULL )
		ptrs.push_back((NiObject *)(entityB));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
