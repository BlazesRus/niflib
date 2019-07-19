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
#include "../../include/obj/NiScreenElementsData.h"
#include "../../include/gen/Polygon.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiScreenElementsData::TYPE("NiScreenElementsData", &NiTriShapeData::TYPE );

NiScreenElementsData::NiScreenElementsData() : maxPolygons((unsigned short)0), polygonGrowBy((unsigned short)1), numPolygons((unsigned short)0), maxVertices((unsigned short)0), verticesGrowBy((unsigned short)1), maxIndices((unsigned short)0), indicesGrowBy((unsigned short)1) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiScreenElementsData::~NiScreenElementsData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiScreenElementsData::GetType() const {
	return TYPE;
}

NiObject * NiScreenElementsData::Create() {
	return new NiScreenElementsData;
}

void NiScreenElementsData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShapeData::Read( in, link_stack, info );
	NifStream( maxPolygons, in, info );
	polygons.resize(maxPolygons);
	for (unsigned int i1 = 0; i1 < polygons.size(); i1++) {
		NifStream( polygons[i1].numVertices, in, info );
		NifStream( polygons[i1].vertexOffset, in, info );
		NifStream( polygons[i1].numTriangles, in, info );
		NifStream( polygons[i1].triangleOffset, in, info );
	};
	polygonIndices.resize(maxPolygons);
	for (unsigned int i1 = 0; i1 < polygonIndices.size(); i1++) {
		NifStream( polygonIndices[i1], in, info );
	};
	NifStream( polygonGrowBy, in, info );
	NifStream( numPolygons, in, info );
	NifStream( maxVertices, in, info );
	NifStream( verticesGrowBy, in, info );
	NifStream( maxIndices, in, info );
	NifStream( indicesGrowBy, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiScreenElementsData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShapeData::Write( out, link_map, missing_link_stack, info );
	maxPolygons = (unsigned short)(polygons.size());
	NifStream( maxPolygons, out, info );
	for (unsigned int i1 = 0; i1 < polygons.size(); i1++) {
		NifStream( polygons[i1].numVertices, out, info );
		NifStream( polygons[i1].vertexOffset, out, info );
		NifStream( polygons[i1].numTriangles, out, info );
		NifStream( polygons[i1].triangleOffset, out, info );
	};
	for (unsigned int i1 = 0; i1 < polygonIndices.size(); i1++) {
		NifStream( polygonIndices[i1], out, info );
	};
	NifStream( polygonGrowBy, out, info );
	NifStream( numPolygons, out, info );
	NifStream( maxVertices, out, info );
	NifStream( verticesGrowBy, out, info );
	NifStream( maxIndices, out, info );
	NifStream( indicesGrowBy, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiScreenElementsData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriShapeData::asString();
	maxPolygons = (unsigned short)(polygons.size());
	out << "  Max Polygons:  " << maxPolygons << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < polygons.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Num Vertices:  " << polygons[i1].numVertices << endl;
		out << "    Vertex Offset:  " << polygons[i1].vertexOffset << endl;
		out << "    Num Triangles:  " << polygons[i1].numTriangles << endl;
		out << "    Triangle Offset:  " << polygons[i1].triangleOffset << endl;
	};
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < polygonIndices.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Polygon Indices[" << i1 << "]:  " << polygonIndices[i1] << endl;
		array_output_count++;
	};
	out << "  Polygon Grow By:  " << polygonGrowBy << endl;
	out << "  Num Polygons:  " << numPolygons << endl;
	out << "  Max Vertices:  " << maxVertices << endl;
	out << "  Vertices Grow By:  " << verticesGrowBy << endl;
	out << "  Max Indices:  " << maxIndices << endl;
	out << "  Indices Grow By:  " << indicesGrowBy << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiScreenElementsData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShapeData::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiScreenElementsData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriShapeData::GetRefs();
	return refs;
}

std::list<NiObject *> NiScreenElementsData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTriShapeData::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
