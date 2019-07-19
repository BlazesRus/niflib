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
#include "../../include/obj/bhkCompressedMeshShape.h"
#include "../../include/obj/NiAVObject.h"
#include "../../include/obj/bhkCompressedMeshShapeData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkCompressedMeshShape::TYPE("bhkCompressedMeshShape", &bhkShape::TYPE );

bhkCompressedMeshShape::bhkCompressedMeshShape() : target(NULL), userData((unsigned int)0), radius(0.005f), unknownFloat1(0.0f), scale(1.0, 1.0, 1.0, 0.0), radiusCopy(0.005f), scaleCopy(1.0, 1.0, 1.0, 0.0), data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

bhkCompressedMeshShape::~bhkCompressedMeshShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & bhkCompressedMeshShape::GetType() const {
	return TYPE;
}

NiObject * bhkCompressedMeshShape::Create() {
	return new bhkCompressedMeshShape;
}

void bhkCompressedMeshShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkShape::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( userData, in, info );
	NifStream( radius, in, info );
	NifStream( unknownFloat1, in, info );
	NifStream( scale, in, info );
	NifStream( radiusCopy, in, info );
	NifStream( scaleCopy, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkShape::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(target), out, info, link_map, missing_link_stack );
	NifStream( userData, out, info );
	NifStream( radius, out, info );
	NifStream( unknownFloat1, out, info );
	NifStream( scale, out, info );
	NifStream( radiusCopy, out, info );
	NifStream( scaleCopy, out, info );
	WriteRef( StaticCast<NiObject>(data), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string bhkCompressedMeshShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkShape::asString();
	out << "  Target:  " << target << endl;
	out << "  User Data:  " << userData << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Unknown Float 1:  " << unknownFloat1 << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Radius Copy:  " << radiusCopy << endl;
	out << "  Scale Copy:  " << scaleCopy << endl;
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void bhkCompressedMeshShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	bhkShape::FixLinks( objects, link_stack, missing_link_stack, info );
	target = FixLink<NiAVObject>( objects, link_stack, missing_link_stack, info );
	data = FixLink<bhkCompressedMeshShapeData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkCompressedMeshShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShape::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

std::list<NiObject *> bhkCompressedMeshShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkShape::GetPtrs();
	if ( target != NULL )
		ptrs.push_back((NiObject *)(target));
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
NiAVObject* bhkCompressedMeshShape::GetTarget() const {
	return target;
}

void bhkCompressedMeshShape::SetTarget(NiAVObject* value) {
	target = value;
}

Ref<bhkCompressedMeshShapeData> bhkCompressedMeshShape::GetData() const {
	return data;
}

void bhkCompressedMeshShape::SetData(Ref<bhkCompressedMeshShapeData > value) {
	data = value;
}

//--END CUSTOM CODE--//
