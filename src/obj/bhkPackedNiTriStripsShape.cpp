/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/Inertia.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/bhkPackedNiTriStripsShape.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/HavokMaterial.h"
#include "../../include/gen/OblivionSubShape.h"
#include "../../include/obj/hkPackedNiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPackedNiTriStripsShape::TYPE("bhkPackedNiTriStripsShape", &bhkShapeCollection::TYPE );

bhkPackedNiTriStripsShape::bhkPackedNiTriStripsShape() : numSubShapes((unsigned short)0), userData((unsigned int)0), unused1((unsigned int)0), radius(0.1f), unused2((unsigned int)0), scale(1.0, 1.0, 1.0, 0.0), radiusCopy(0.1f), scaleCopy(1.0, 1.0, 1.0, 0.0), data(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkPackedNiTriStripsShape::~bhkPackedNiTriStripsShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkPackedNiTriStripsShape::GetType() const {
	return TYPE;
}

NiObject * bhkPackedNiTriStripsShape::Create() {
	return new bhkPackedNiTriStripsShape;
}

void bhkPackedNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkShapeCollection::Read( in, link_stack, info );
	if ( info.version <= 0x14000005 ) {
		NifStream( numSubShapes, in, info );
		subShapes.resize(numSubShapes);
		for (unsigned int i2 = 0; i2 < subShapes.size(); i2++) {
			if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
				NifStream( subShapes[i2].havokFilter.layer_ob, in, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
				NifStream( subShapes[i2].havokFilter.layer_fo, in, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
				NifStream( subShapes[i2].havokFilter.layer_sk, in, info );
			};
			NifStream( subShapes[i2].havokFilter.flagsAndPartNumber, in, info );
			NifStream( subShapes[i2].havokFilter.group, in, info );
			NifStream( subShapes[i2].numVertices, in, info );
			if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
				NifStream( subShapes[i2].material.material_ob, in, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
				NifStream( subShapes[i2].material.material_fo, in, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
				NifStream( subShapes[i2].material.material_sk, in, info );
			};
		};
	};
	NifStream( userData, in, info );
	NifStream( unused1, in, info );
	NifStream( radius, in, info );
	NifStream( unused2, in, info );
	NifStream( scale, in, info );
	NifStream( radiusCopy, in, info );
	NifStream( scaleCopy, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPackedNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, missing_link_stack, info );
	numSubShapes = (unsigned short)(subShapes.size());
	if ( info.version <= 0x14000005 ) {
		NifStream( numSubShapes, out, info );
		for (unsigned int i2 = 0; i2 < subShapes.size(); i2++) {
			if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
				NifStream( subShapes[i2].havokFilter.layer_ob, out, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
				NifStream( subShapes[i2].havokFilter.layer_fo, out, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
				NifStream( subShapes[i2].havokFilter.layer_sk, out, info );
			};
			NifStream( subShapes[i2].havokFilter.flagsAndPartNumber, out, info );
			NifStream( subShapes[i2].havokFilter.group, out, info );
			NifStream( subShapes[i2].numVertices, out, info );
			if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
				NifStream( subShapes[i2].material.material_ob, out, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
				NifStream( subShapes[i2].material.material_fo, out, info );
			};
			if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
				NifStream( subShapes[i2].material.material_sk, out, info );
			};
		};
	};
	NifStream( userData, out, info );
	NifStream( unused1, out, info );
	NifStream( radius, out, info );
	NifStream( unused2, out, info );
	NifStream( scale, out, info );
	NifStream( radiusCopy, out, info );
	NifStream( scaleCopy, out, info );
	WriteRef( StaticCast<NiObject>(data), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkPackedNiTriStripsShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numSubShapes = (unsigned short)(subShapes.size());
	out << "  Num Sub Shapes:  " << numSubShapes << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < subShapes.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << subShapes[i1].havokFilter.layer_ob << endl;
		out << "    Layer:  " << subShapes[i1].havokFilter.layer_fo << endl;
		out << "    Layer:  " << subShapes[i1].havokFilter.layer_sk << endl;
		out << "    Flags and Part Number:  " << subShapes[i1].havokFilter.flagsAndPartNumber << endl;
		out << "    Group:  " << subShapes[i1].havokFilter.group << endl;
		out << "    Num Vertices:  " << subShapes[i1].numVertices << endl;
		out << "    Material:  " << subShapes[i1].material.material_ob << endl;
		out << "    Material:  " << subShapes[i1].material.material_fo << endl;
		out << "    Material:  " << subShapes[i1].material.material_sk << endl;
	};
	out << "  User Data:  " << userData << endl;
	out << "  Unused 1:  " << unused1 << endl;
	out << "  Radius:  " << radius << endl;
	out << "  Unused 2:  " << unused2 << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Radius Copy:  " << radiusCopy << endl;
	out << "  Scale Copy:  " << scaleCopy << endl;
	out << "  Data:  " << data << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPackedNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, missing_link_stack, info );
	data = FixLink<hkPackedNiTriStripsData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkPackedNiTriStripsShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	if ( data != NULL )
		refs.push_back(StaticCast<NiObject>(data));
	return refs;
}

std::list<NiObject *> bhkPackedNiTriStripsShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkShapeCollection::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
Ref<hkPackedNiTriStripsData> bhkPackedNiTriStripsShape::GetData() const {
	return data;
}

void bhkPackedNiTriStripsShape::SetData( hkPackedNiTriStripsData * n ) {
	data = n;
}

vector<OblivionSubShape> bhkPackedNiTriStripsShape::GetSubShapes() const {
	return subShapes;
}

void bhkPackedNiTriStripsShape::SetSubShapes( vector<OblivionSubShape>& value ) {
	numSubShapes = value.size();
	subShapes = value;
}

Vector4 bhkPackedNiTriStripsShape::GetScale() const {
	return scale;
}

void bhkPackedNiTriStripsShape::SetScale( const Vector4 & n ) {
	scale = n;	
}

void bhkPackedNiTriStripsShape::CalcMassProperties(float density, bool solid, float &mass, float &volume, Vector3 &center, InertiaMatrix& inertia)
{
	center = Vector3(0,0,0);
	mass = 0.0f, volume = 0.0f;
	inertia = InertiaMatrix::IDENTITY;

	if (data != NULL)
	{
		vector<Vector3> verts = data->GetVertices();
		vector<Triangle> tris = data->GetTriangles();
		Inertia::CalcMassPropertiesPolyhedron(verts, tris, density, solid, mass, volume, center, inertia);
	}
}

float bhkPackedNiTriStripsShape::GetRadius() const
{
	return radius;
}

void bhkPackedNiTriStripsShape::SetRadius(float value)
{
	radius = value;
}

//--END CUSTOM CODE--//
