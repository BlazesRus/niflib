/* Copyright (c) 2019, NIF File Format Library and Tools
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
#include "../../include/obj/bhkNiTriStripsShape.h"
#include "../../include/gen/HavokFilter.h"
#include "../../include/gen/HavokMaterial.h"
#include "../../include/obj/NiTriStripsData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkNiTriStripsShape::TYPE("bhkNiTriStripsShape", &bhkShapeCollection::TYPE );

bhkNiTriStripsShape::bhkNiTriStripsShape() : radius(0.1f), growBy((unsigned int)1), scale(1.0, 1.0, 1.0, 0.0), numStripsData((unsigned int)0), numDataLayers((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkNiTriStripsShape::~bhkNiTriStripsShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkNiTriStripsShape::GetType() const {
	return TYPE;
}

NiObject * bhkNiTriStripsShape::Create() {
	return new bhkNiTriStripsShape;
}

void bhkNiTriStripsShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	bhkShapeCollection::Read( in, link_stack, info );
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( material.material_ob, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( material.material_fo, in, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( material.material_sk, in, info );
	};
	NifStream( radius, in, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unused[i1], in, info );
	};
	NifStream( growBy, in, info );
	NifStream( scale, in, info );
	NifStream( numStripsData, in, info );
	stripsData.resize(numStripsData);
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	NifStream( numDataLayers, in, info );
	dataLayers.resize(numDataLayers);
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
			NifStream( dataLayers[i1].layer_ob, in, info );
		};
		if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
			NifStream( dataLayers[i1].layer_fo, in, info );
		};
		if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
			NifStream( dataLayers[i1].layer_sk, in, info );
		};
		NifStream( dataLayers[i1].flagsAndPartNumber, in, info );
		NifStream( dataLayers[i1].group, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkNiTriStripsShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::Write( out, link_map, missing_link_stack, info );
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
		NifStream( material.material_ob, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
		NifStream( material.material_fo, out, info );
	};
	if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
		NifStream( material.material_sk, out, info );
	};
	NifStream( radius, out, info );
	for (unsigned int i1 = 0; i1 < 5; i1++) {
		NifStream( unused[i1], out, info );
	};
	NifStream( growBy, out, info );
	NifStream( scale, out, info );
	NifStream( numStripsData, out, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		WriteRef( StaticCast<NiObject>(stripsData[i1]), out, info, link_map, missing_link_stack );
	};
	NifStream( numDataLayers, out, info );
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		if ( ( info.version >= 0x14000004 ) && ( info.version <= 0x14000005 ) ) {
			NifStream( dataLayers[i1].layer_ob, out, info );
		};
		if ( ((info.version == 0x14020007) && (info.userVersion2 <= 34)) ) {
			NifStream( dataLayers[i1].layer_fo, out, info );
		};
		if ( ((info.version == 0x14020007) && (info.userVersion2 > 34)) ) {
			NifStream( dataLayers[i1].layer_sk, out, info );
		};
		NifStream( dataLayers[i1].flagsAndPartNumber, out, info );
		NifStream( dataLayers[i1].group, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkNiTriStripsShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << bhkShapeCollection::asString();
	numDataLayers = (unsigned int)(dataLayers.size());
	numStripsData = (unsigned int)(stripsData.size());
	out << "  Material:  " << material.material_ob << endl;
	out << "  Material:  " << material.material_fo << endl;
	out << "  Material:  " << material.material_sk << endl;
	out << "  Radius:  " << radius << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < 5; i1++) {
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
	out << "  Grow By:  " << growBy << endl;
	out << "  Scale:  " << scale << endl;
	out << "  Num Strips Data:  " << numStripsData << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Strips Data[" << i1 << "]:  " << stripsData[i1] << endl;
		array_output_count++;
	};
	out << "  Num Data Layers:  " << numDataLayers << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < dataLayers.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Layer:  " << dataLayers[i1].layer_ob << endl;
		out << "    Layer:  " << dataLayers[i1].layer_fo << endl;
		out << "    Layer:  " << dataLayers[i1].layer_sk << endl;
		out << "    Flags and Part Number:  " << dataLayers[i1].flagsAndPartNumber << endl;
		out << "    Group:  " << dataLayers[i1].group << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkNiTriStripsShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkShapeCollection::FixLinks( objects, link_stack, missing_link_stack, info );
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		stripsData[i1] = FixLink<NiTriStripsData>( objects, link_stack, missing_link_stack, info );
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkNiTriStripsShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkShapeCollection::GetRefs();
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
		if ( stripsData[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(stripsData[i1]));
	};
	return refs;
}

std::list<NiObject *> bhkNiTriStripsShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkShapeCollection::GetPtrs();
	for (unsigned int i1 = 0; i1 < stripsData.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

int bhkNiTriStripsShape::GetNumStripsData( )
{
	return numStripsData;
}

void bhkNiTriStripsShape::SetNumStripsData(int n)
{
	numStripsData = n;
	stripsData.resize(n);
}

Ref<NiTriStripsData> bhkNiTriStripsShape::GetStripsData( int index )
{
	return Ref<NiTriStripsData>(stripsData[index]);
}

void bhkNiTriStripsShape::SetStripsData( int index, NiTriStripsData * strips )
{
	stripsData[index] = strips;
}



Vector3 bhkNiTriStripsShape::GetScale() const {
	return scale;
}

void bhkNiTriStripsShape::SetScale( const Vector3 & n ) {
	scale = n;	
}

HavokMaterial bhkNiTriStripsShape::GetMaterial() const {
	return material;
}

void bhkNiTriStripsShape::SetMaterial( HavokMaterial value ) {
	material = value;
}

unsigned int bhkNiTriStripsShape::GetNumDataLayers() const {
	return numDataLayers;
}

void bhkNiTriStripsShape::SetNumDataLayers( unsigned int i ) {
	numDataLayers = i;
	dataLayers.resize(i);
}

OblivionLayer bhkNiTriStripsShape::GetOblivionLayer( unsigned int index ) const {
	return dataLayers[index].layer;
}

void bhkNiTriStripsShape::SetOblivionLayer( unsigned int index, OblivionLayer layer ){
	dataLayers[index].layer = layer;
}

unsigned char bhkNiTriStripsShape::GetOblivionFilter( unsigned int index ) const {
	return dataLayers[index].colFilter;
}

void bhkNiTriStripsShape::SetOblivionFilter( unsigned int index, unsigned char filter ) {
	dataLayers[index].colFilter = filter;
}

void bhkNiTriStripsShape::CalcMassProperties(float density, bool solid, float &mass, float &volume, Vector3 &center, InertiaMatrix& inertia)
{
	center = Vector3(0,0,0);
	mass = 0.0f, volume = 0.0f;
	inertia = InertiaMatrix::IDENTITY;

	vector<Vector3> verts;
	vector<Triangle> tris;
	for ( vector<NiTriStripsDataRef>::iterator itr = stripsData.begin(); itr != stripsData.end(); ++itr )
	{
		size_t nv = verts.size(), nt = tris.size();
		vector<Vector3> v = (*itr)->GetVertices();
		vector<Triangle> t = (*itr)->GetTriangles();
		for (size_t i=0; i<nv; ++i)
			verts.push_back( v[i] );
		for (size_t i=0; i<nt; ++i)
			tris.push_back( Triangle(t[i][0] + nt, t[i][1] + nt, t[i][2] + nt) );
	}
	Inertia::CalcMassPropertiesPolyhedron(verts, tris, density, solid, mass, volume, center, inertia);
}
//--END CUSTOM CODE--//
