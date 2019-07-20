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
#include "../../include/obj/NiBlendInterpolator.h"
#include "../../include/gen/InterpBlendItem.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiBlendInterpolator::TYPE("NiBlendInterpolator", &NiInterpolator::TYPE );

NiBlendInterpolator::NiBlendInterpolator() : flags((InterpBlendFlags)0), arraySize((byte)0), weightThreshold(0.0f), interpCount((byte)0), singleIndex((byte)255), highPriority((byte)-128), nextHighPriority((byte)-128), singleTime(-3.402823466e+38f), highWeightsSum(-3.402823466e+38f), nextHighWeightsSum(-3.402823466e+38f), highEaseSpinner(-3.402823466e+38f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiBlendInterpolator::~NiBlendInterpolator() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiBlendInterpolator::GetType() const {
	return TYPE;
}

NiObject * NiBlendInterpolator::Create() {
	return new NiBlendInterpolator;
}

void NiBlendInterpolator::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiInterpolator::Read( in, link_stack, info );
	NifStream( flags, in, info );
	NifStream( arraySize, in, info );
	NifStream( weightThreshold, in, info );
	if ( ((flags & 1) == 0) ) {
		NifStream( interpCount, in, info );
		NifStream( singleIndex, in, info );
		NifStream( highPriority, in, info );
		NifStream( nextHighPriority, in, info );
		NifStream( singleTime, in, info );
		NifStream( highWeightsSum, in, info );
		NifStream( nextHighWeightsSum, in, info );
		NifStream( highEaseSpinner, in, info );
		interpArrayItems.resize(arraySize);
		for (unsigned int i2 = 0; i2 < interpArrayItems.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( interpArrayItems[i2].weight, in, info );
			NifStream( interpArrayItems[i2].normalizedWeight, in, info );
			NifStream( interpArrayItems[i2].priority, in, info );
			NifStream( interpArrayItems[i2].easeSpinner, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBlendInterpolator::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::Write( out, link_map, missing_link_stack, info );
	arraySize = (byte)(interpArrayItems.size());
	NifStream( flags, out, info );
	NifStream( arraySize, out, info );
	NifStream( weightThreshold, out, info );
	if ( ((flags & 1) == 0) ) {
		NifStream( interpCount, out, info );
		NifStream( singleIndex, out, info );
		NifStream( highPriority, out, info );
		NifStream( nextHighPriority, out, info );
		NifStream( singleTime, out, info );
		NifStream( highWeightsSum, out, info );
		NifStream( nextHighWeightsSum, out, info );
		NifStream( highEaseSpinner, out, info );
		for (unsigned int i2 = 0; i2 < interpArrayItems.size(); i2++) {
			WriteRef( StaticCast<NiObject>(interpArrayItems[i2].interpolator), out, info, link_map, missing_link_stack );
			NifStream( interpArrayItems[i2].weight, out, info );
			NifStream( interpArrayItems[i2].normalizedWeight, out, info );
			NifStream( interpArrayItems[i2].priority, out, info );
			NifStream( interpArrayItems[i2].easeSpinner, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiBlendInterpolator::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiInterpolator::asString();
	arraySize = (byte)(interpArrayItems.size());
	out << "  Flags:  " << flags << endl;
	out << "  Array Size:  " << arraySize << endl;
	out << "  Weight Threshold:  " << weightThreshold << endl;
	if ( ((flags & 1) == 0) ) {
		out << "    Interp Count:  " << interpCount << endl;
		out << "    Single Index:  " << singleIndex << endl;
		out << "    High Priority:  " << highPriority << endl;
		out << "    Next High Priority:  " << nextHighPriority << endl;
		out << "    Single Time:  " << singleTime << endl;
		out << "    High Weights Sum:  " << highWeightsSum << endl;
		out << "    Next High Weights Sum:  " << nextHighWeightsSum << endl;
		out << "    High Ease Spinner:  " << highEaseSpinner << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < interpArrayItems.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			out << "      Interpolator:  " << interpArrayItems[i2].interpolator << endl;
			out << "      Weight:  " << interpArrayItems[i2].weight << endl;
			out << "      Normalized Weight:  " << interpArrayItems[i2].normalizedWeight << endl;
			out << "      Priority:  " << interpArrayItems[i2].priority << endl;
			out << "      Ease Spinner:  " << interpArrayItems[i2].easeSpinner << endl;
		};
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiBlendInterpolator::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiInterpolator::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( ((flags & 1) == 0) ) {
		for (unsigned int i2 = 0; i2 < interpArrayItems.size(); i2++) {
			interpArrayItems[i2].interpolator = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiBlendInterpolator::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiInterpolator::GetRefs();
	for (unsigned int i1 = 0; i1 < interpArrayItems.size(); i1++) {
		if ( interpArrayItems[i1].interpolator != NULL )
			refs.push_back(StaticCast<NiObject>(interpArrayItems[i1].interpolator));
	};
	return refs;
}

std::list<NiObject *> NiBlendInterpolator::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiInterpolator::GetPtrs();
	for (unsigned int i1 = 0; i1 < interpArrayItems.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
