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
#include "../../include/obj/BSSegmentedTriShape.h"
#include "../../include/gen/BSGeometrySegmentData.h"
#include "../../include/gen/BSGeometrySubSegment.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSSegmentedTriShape::TYPE("BSSegmentedTriShape", &NiTriShape::TYPE );

BSSegmentedTriShape::BSSegmentedTriShape() : numSegments((int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSSegmentedTriShape::~BSSegmentedTriShape() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSSegmentedTriShape::GetType() const {
	return TYPE;
}

NiObject * BSSegmentedTriShape::Create() {
	return new BSSegmentedTriShape;
}

void BSSegmentedTriShape::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::Read( in, link_stack, info );
	NifStream( numSegments, in, info );
	segment.resize(numSegments);
	for (unsigned int i1 = 0; i1 < segment.size(); i1++) {
		if ( (info.userVersion2 < 130) ) {
			NifStream( segment[i1].flags, in, info );
			NifStream( segment[i1].index, in, info );
			NifStream( segment[i1].numTrisInSegment, in, info );
		};
		if ( info.userVersion2 == 130 ) {
			NifStream( segment[i1].startIndex, in, info );
			NifStream( segment[i1].numPrimitives, in, info );
			NifStream( segment[i1].parentArrayIndex, in, info );
			NifStream( segment[i1].numSubSegments, in, info );
			segment[i1].subSegment.resize(segment[i1].numSubSegments);
			for (unsigned int i3 = 0; i3 < segment[i1].subSegment.size(); i3++) {
				NifStream( segment[i1].subSegment[i3].startIndex, in, info );
				NifStream( segment[i1].subSegment[i3].numPrimitives, in, info );
				NifStream( segment[i1].subSegment[i3].parentArrayIndex, in, info );
				NifStream( segment[i1].subSegment[i3].unused, in, info );
			};
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSegmentedTriShape::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::Write( out, link_map, missing_link_stack, info );
	numSegments = (int)(segment.size());
	NifStream( numSegments, out, info );
	for (unsigned int i1 = 0; i1 < segment.size(); i1++) {
		segment[i1].numSubSegments = (unsigned int)(segment[i1].subSegment.size());
		if ( (info.userVersion2 < 130) ) {
			NifStream( segment[i1].flags, out, info );
			NifStream( segment[i1].index, out, info );
			NifStream( segment[i1].numTrisInSegment, out, info );
		};
		if ( info.userVersion2 == 130 ) {
			NifStream( segment[i1].startIndex, out, info );
			NifStream( segment[i1].numPrimitives, out, info );
			NifStream( segment[i1].parentArrayIndex, out, info );
			NifStream( segment[i1].numSubSegments, out, info );
			for (unsigned int i3 = 0; i3 < segment[i1].subSegment.size(); i3++) {
				NifStream( segment[i1].subSegment[i3].startIndex, out, info );
				NifStream( segment[i1].subSegment[i3].numPrimitives, out, info );
				NifStream( segment[i1].subSegment[i3].parentArrayIndex, out, info );
				NifStream( segment[i1].subSegment[i3].unused, out, info );
			};
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSSegmentedTriShape::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiTriShape::asString();
	numSegments = (int)(segment.size());
	out << "  Num Segments:  " << numSegments << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < segment.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		segment[i1].numSubSegments = (unsigned int)(segment[i1].subSegment.size());
		out << "    Flags:  " << segment[i1].flags << endl;
		out << "    Index:  " << segment[i1].index << endl;
		out << "    Num Tris in Segment:  " << segment[i1].numTrisInSegment << endl;
		out << "    Start Index:  " << segment[i1].startIndex << endl;
		out << "    Num Primitives:  " << segment[i1].numPrimitives << endl;
		out << "    Parent Array Index:  " << segment[i1].parentArrayIndex << endl;
		out << "    Num Sub Segments:  " << segment[i1].numSubSegments << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < segment[i1].subSegment.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Start Index:  " << segment[i1].subSegment[i2].startIndex << endl;
			out << "      Num Primitives:  " << segment[i1].subSegment[i2].numPrimitives << endl;
			out << "      Parent Array Index:  " << segment[i1].subSegment[i2].parentArrayIndex << endl;
			out << "      Unused:  " << segment[i1].subSegment[i2].unused << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSSegmentedTriShape::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTriShape::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSSegmentedTriShape::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTriShape::GetRefs();
	return refs;
}

std::list<NiObject *> BSSegmentedTriShape::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTriShape::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
