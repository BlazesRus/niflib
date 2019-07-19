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
#include "../../include/obj/NiTransformEvaluator.h"
#include "../../include/gen/NiQuatTransform.h"
#include "../../include/obj/NiTransformData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiTransformEvaluator::TYPE("NiTransformEvaluator", &NiKeyBasedEvaluator::TYPE );

NiTransformEvaluator::NiTransformEvaluator() : data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiTransformEvaluator::~NiTransformEvaluator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiTransformEvaluator::GetType() const {
	return TYPE;
}

NiObject * NiTransformEvaluator::Create() {
	return new NiTransformEvaluator;
}

void NiTransformEvaluator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiKeyBasedEvaluator::Read( in, link_stack, info );
	NifStream( value.translation, in, info );
	NifStream( value.rotation, in, info );
	NifStream( value.scale, in, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp;
				NifStream( tmp, in, info );
				value.trsValid[i2] = tmp;
			};
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiTransformEvaluator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiKeyBasedEvaluator::Write( out, link_map, missing_link_stack, info );
	NifStream( value.translation, out, info );
	NifStream( value.rotation, out, info );
	NifStream( value.scale, out, info );
	if ( info.version <= 0x0A01006D ) {
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			{
				bool tmp = value.trsValid[i2];
				NifStream( tmp, out, info );
			};
		};
	};
	WriteRef( StaticCast<NiObject>(data), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiTransformEvaluator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiKeyBasedEvaluator::asString();
	out << "  Translation:  " << value.translation << endl;
	out << "  Rotation:  " << value.rotation << endl;
	out << "  Scale:  " << value.scale << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    TRS Valid[" << i1 << "]:  " << value.trsValid[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiTransformEvaluator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiKeyBasedEvaluator::FixLinks( objects, link_stack, missing_link_stack, info );
	data = FixLink<NiTransformData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiTransformEvaluator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiKeyBasedEvaluator::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

std::list<NiObject *> NiTransformEvaluator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiKeyBasedEvaluator::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
