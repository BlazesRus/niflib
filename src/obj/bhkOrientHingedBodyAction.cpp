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
#include "../../include/obj/bhkOrientHingedBodyAction.h"
#include "../../include/obj/bhkRigidBody.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkOrientHingedBodyAction::TYPE("bhkOrientHingedBodyAction", &bhkSerializable::TYPE );

bhkOrientHingedBodyAction::bhkOrientHingedBodyAction() : body(NULL), unknownInt1((unsigned int)0), unknownInt2((unsigned int)0), strength(0.0f), damping(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkOrientHingedBodyAction::~bhkOrientHingedBodyAction() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkOrientHingedBodyAction::GetType() const {
	return TYPE;
}

NiObject * bhkOrientHingedBodyAction::Create() {
	return new bhkOrientHingedBodyAction;
}

void bhkOrientHingedBodyAction::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkSerializable::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( unknownInt1, in, info );
	NifStream( unknownInt2, in, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused1[i1], in, info );
	};
	NifStream( hingeAxisLs, in, info );
	NifStream( forwardLs, in, info );
	NifStream( strength, in, info );
	NifStream( damping, in, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused2[i1], in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkOrientHingedBodyAction::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkSerializable::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(body), out, info, link_map, missing_link_stack );
	NifStream( unknownInt1, out, info );
	NifStream( unknownInt2, out, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused1[i1], out, info );
	};
	NifStream( hingeAxisLs, out, info );
	NifStream( forwardLs, out, info );
	NifStream( strength, out, info );
	NifStream( damping, out, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused2[i1], out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkOrientHingedBodyAction::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	out << "  Body:  " << body << endl;
	out << "  Unknown Int 1:  " << unknownInt1 << endl;
	out << "  Unknown Int 2:  " << unknownInt2 << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unused 1[" << i1 << "]:  " << unused1[i1] << endl;
		array_output_count++;
	};
	out << "  Hinge Axis LS:  " << hingeAxisLs << endl;
	out << "  Forward LS:  " << forwardLs << endl;
	out << "  Strength:  " << strength << endl;
	out << "  Damping:  " << damping << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unused 2[" << i1 << "]:  " << unused2[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkOrientHingedBodyAction::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkSerializable::FixLinks( objects, link_stack, missing_link_stack, info );
	body = FixLink<bhkRigidBody>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkOrientHingedBodyAction::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	return refs;
}

std::list<NiObject *> bhkOrientHingedBodyAction::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkSerializable::GetPtrs();
	if ( body != NULL )
		ptrs.push_back((NiObject *)(body));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
