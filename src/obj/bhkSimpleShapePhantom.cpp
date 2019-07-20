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
#include "../../include/obj/bhkSimpleShapePhantom.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkSimpleShapePhantom::TYPE("bhkSimpleShapePhantom", &bhkShapePhantom::TYPE );

bhkSimpleShapePhantom::bhkSimpleShapePhantom() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkSimpleShapePhantom::~bhkSimpleShapePhantom() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkSimpleShapePhantom::GetType() const {
	return TYPE;
}

NiObject * bhkSimpleShapePhantom::Create() {
	return new bhkSimpleShapePhantom;
}

void bhkSimpleShapePhantom::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapePhantom::Read( in, link_stack, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused2[i1], in, info );
	};
	NifStream( transform, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkSimpleShapePhantom::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapePhantom::Write( out, link_map, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < 8; i1++) {
		NifStream( unused2[i1], out, info );
	};
	NifStream( transform, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkSimpleShapePhantom::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapePhantom::asString();
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
	out << "  Transform:  " << transform << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkSimpleShapePhantom::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapePhantom::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkSimpleShapePhantom::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapePhantom::GetRefs();
	return refs;
}

std::list<NiObject *> bhkSimpleShapePhantom::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkShapePhantom::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
