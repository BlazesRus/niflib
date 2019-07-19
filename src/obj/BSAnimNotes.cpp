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
#include "../../include/obj/BSAnimNotes.h"
#include "../../include/obj/BSAnimNote.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSAnimNotes::TYPE("BSAnimNotes", &NiObject::TYPE );

BSAnimNotes::BSAnimNotes() : numAnimNotes((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSAnimNotes::~BSAnimNotes() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSAnimNotes::GetType() const {
	return TYPE;
}

NiObject * BSAnimNotes::Create() {
	return new BSAnimNotes;
}

void BSAnimNotes::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( numAnimNotes, in, info );
	animNotes.resize(numAnimNotes);
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSAnimNotes::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numAnimNotes = (unsigned short)(animNotes.size());
	NifStream( numAnimNotes, out, info );
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
		WriteRef( StaticCast<NiObject>(animNotes[i1]), out, info, link_map, missing_link_stack );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSAnimNotes::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numAnimNotes = (unsigned short)(animNotes.size());
	out << "  Num Anim Notes:  " << numAnimNotes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Anim Notes[" << i1 << "]:  " << animNotes[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSAnimNotes::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
		animNotes[i1] = FixLink<BSAnimNote>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSAnimNotes::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
		if ( animNotes[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(animNotes[i1]));
	};
	return refs;
}

std::list<NiObject *> BSAnimNotes::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < animNotes.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
