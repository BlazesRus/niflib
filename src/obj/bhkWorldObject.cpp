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
#include "../../include/obj/bhkWorldObject.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/hkWorldObjCinfoProperty.h"
#include "../../include/obj/bhkShape.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkWorldObject::TYPE("bhkWorldObject", &bhkSerializable::TYPE );

bhkWorldObject::bhkWorldObject() : shape(NULL), broadPhaseType((BroadPhaseType)1) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkWorldObject::~bhkWorldObject() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkWorldObject::GetType() const {
	return TYPE;
}

NiObject * bhkWorldObject::Create() {
	return new bhkWorldObject;
}

void bhkWorldObject::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkSerializable::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( havokFilter.layer_ob, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( havokFilter.layer_fo, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( havokFilter.layer_sk, in, info );
	};
	NifStream( havokFilter.flagsAndPartNumber, in, info );
	NifStream( havokFilter.group, in, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unused[i1], in, info );
	};
	NifStream( broadPhaseType, in, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unusedBytes[i1], in, info );
	};
	NifStream( cinfoProperty.data, in, info );
	NifStream( cinfoProperty.size, in, info );
	NifStream( cinfoProperty.capacityAndFlags, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkWorldObject::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkSerializable::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(shape), out, info, link_map, missing_link_stack );
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( havokFilter.layer_ob, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( havokFilter.layer_fo, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( havokFilter.layer_sk, out, info );
	};
	NifStream( havokFilter.flagsAndPartNumber, out, info );
	NifStream( havokFilter.group, out, info );
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		NifStream( unused[i1], out, info );
	};
	NifStream( broadPhaseType, out, info );
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		NifStream( unusedBytes[i1], out, info );
	};
	NifStream( cinfoProperty.data, out, info );
	NifStream( cinfoProperty.size, out, info );
	NifStream( cinfoProperty.capacityAndFlags, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkWorldObject::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkSerializable::asString();
	out << "  Shape:  " << shape << endl;
	out << "  Layer:  " << havokFilter.layer_ob << endl;
	out << "  Layer:  " << havokFilter.layer_fo << endl;
	out << "  Layer:  " << havokFilter.layer_sk << endl;
	out << "  Flags and Part Number:  " << havokFilter.flagsAndPartNumber << endl;
	out << "  Group:  " << havokFilter.group << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 4; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unused[" << i1 << "]:  " << unused[i1] << endl;
		array_output_count++;
	};
	out << "  Broad Phase Type:  " << broadPhaseType << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 3; i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Unused Bytes[" << i1 << "]:  " << unusedBytes[i1] << endl;
		array_output_count++;
	};
	out << "  Data:  " << cinfoProperty.data << endl;
	out << "  Size:  " << cinfoProperty.size << endl;
	out << "  Capacity and Flags:  " << cinfoProperty.capacityAndFlags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkWorldObject::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkSerializable::FixLinks( objects, link_stack, missing_link_stack, info );
	shape = FixLink<bhkShape>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkWorldObject::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkSerializable::GetRefs();
	if ( shape != NULL )
		refs.push_back(StaticCast<NiObject>(shape));
	return refs;
}

std::list<NiObject *> bhkWorldObject::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkSerializable::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

Ref<bhkShape > bhkWorldObject::GetShape() const {
	return shape;
}

void bhkWorldObject::SetShape( bhkShape * value ) {
	shape = value;
}

HavokFilter Niflib::bhkWorldObject::GetHavokFilter() const
{
	return havokFilter;
}

void Niflib::bhkWorldObject::SetHavokFilter(HavokFilter value)
{
	havokFilter = value;
}

BroadPhaseType Niflib::bhkWorldObject::GetBroadPhaseType() const
{
	return broadPhaseType;
}

void Niflib::bhkWorldObject::SetBroadPhaseType(BroadPhaseType value)
{
	broadPhaseType = value;
}

hkWorldObjCinfoProperty Niflib::bhkWorldObject::GetWorldInfoProperty() const
{
	return cinfoProperty;
}

void Niflib::bhkWorldObject::SetWorldInfoProperty(hkWorldObjCinfoProperty value)
{
	cinfoProperty = value;
}

//--END CUSTOM CODE--//
