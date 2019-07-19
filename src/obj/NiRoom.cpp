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
#include "../../include/obj/NiRoom.h"
#include "../../include/gen/NiPlane.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/NiPortal.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiRoom::TYPE("NiRoom", &NiNode::TYPE );

NiRoom::NiRoom() : numWalls((int)0), numInPortals((unsigned int)0), numOutPortals((unsigned int)0), numFixtures((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiRoom::~NiRoom() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiRoom::GetType() const {
	return TYPE;
}

NiObject * NiRoom::Create() {
	return new NiRoom;
}

void NiRoom::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiNode::Read( in, link_stack, info );
	NifStream( numWalls, in, info );
	wallPlanes.resize(numWalls);
	for (unsigned int i1 = 0; i1 < wallPlanes.size(); i1++) {
		NifStream( wallPlanes[i1].normal, in, info );
		NifStream( wallPlanes[i1].constant, in, info );
	};
	NifStream( numInPortals, in, info );
	inPortals.resize(numInPortals);
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numOutPortals, in, info );
	outPortals.resize(numOutPortals);
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numFixtures, in, info );
	fixtures.resize(numFixtures);
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiRoom::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::Write( out, link_map, missing_link_stack, info );
	numFixtures = (unsigned int)(fixtures.size());
	numOutPortals = (unsigned int)(outPortals.size());
	numInPortals = (unsigned int)(inPortals.size());
	numWalls = (int)(wallPlanes.size());
	NifStream( numWalls, out, info );
	for (unsigned int i1 = 0; i1 < wallPlanes.size(); i1++) {
		NifStream( wallPlanes[i1].normal, out, info );
		NifStream( wallPlanes[i1].constant, out, info );
	};
	NifStream( numInPortals, out, info );
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
		WriteRef( StaticCast<NiObject>(inPortals[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numOutPortals, out, info );
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
		WriteRef( StaticCast<NiObject>(outPortals[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numFixtures, out, info );
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
		WriteRef( StaticCast<NiObject>(fixtures[i1]), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiRoom::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiNode::asString();
	numFixtures = (unsigned int)(fixtures.size());
	numOutPortals = (unsigned int)(outPortals.size());
	numInPortals = (unsigned int)(inPortals.size());
	numWalls = (int)(wallPlanes.size());
	out << "  Num Walls:  " << numWalls << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < wallPlanes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Normal:  " << wallPlanes[i1].normal << endl;
		out << "    Constant:  " << wallPlanes[i1].constant << endl;
	};
	out << "  Num In Portals:  " << numInPortals << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    In Portals[" << i1 << "]:  " << inPortals[i1] << endl;
		array_output_count++;
	};
	out << "  Num Out Portals:  " << numOutPortals << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Out Portals[" << i1 << "]:  " << outPortals[i1] << endl;
		array_output_count++;
	};
	out << "  Num Fixtures:  " << numFixtures << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Fixtures[" << i1 << "]:  " << fixtures[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiRoom::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiNode::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
		inPortals[i1] = FixLink<NiPortal>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
		outPortals[i1] = FixLink<NiPortal>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
		fixtures[i1] = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiRoom::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiNode::GetRefs();
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
	};
	return refs;
}

std::list<NiObject *> NiRoom::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiNode::GetPtrs();
	for (unsigned int i1 = 0; i1 < inPortals.size(); i1++) {
		if ( inPortals[i1] != NULL )
			ptrs.push_back((NiObject *)(inPortals[i1]));
	};
	for (unsigned int i1 = 0; i1 < outPortals.size(); i1++) {
		if ( outPortals[i1] != NULL )
			ptrs.push_back((NiObject *)(outPortals[i1]));
	};
	for (unsigned int i1 = 0; i1 < fixtures.size(); i1++) {
		if ( fixtures[i1] != NULL )
			ptrs.push_back((NiObject *)(fixtures[i1]));
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
