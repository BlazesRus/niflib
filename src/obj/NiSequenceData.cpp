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
#include "../../include/obj/NiSequenceData.h"
#include "../../include/gen/ControlledBlock.h"
#include "../../include/obj/NiBlendInterpolator.h"
#include "../../include/obj/NiEvaluator.h"
#include "../../include/obj/NiInterpolator.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/obj/NiTextKeyExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSequenceData::TYPE("NiSequenceData", &NiObject::TYPE );

NiSequenceData::NiSequenceData() : numControlledBlocks((unsigned int)0), arrayGrowBy((unsigned int)0), numEvaluators((unsigned int)0), textKeys(NULL), duration(0.0f), cycleType((CycleType)0), frequency(1.0f), accumFlags((AccumFlags)ACCUM_X_FRONT) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiSequenceData::~NiSequenceData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiSequenceData::GetType() const {
	return TYPE;
}

NiObject * NiSequenceData::Create() {
	return new NiSequenceData;
}

void NiSequenceData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	if ( info.version <= 0x14050001 ) {
		NifStream( numControlledBlocks, in, info );
		NifStream( arrayGrowBy, in, info );
		controlledBlocks.resize(numControlledBlocks);
		for (unsigned int i2 = 0; i2 < controlledBlocks.size(); i2++) {
			if ( info.version <= 0x0A010067 ) {
				NifStream( controlledBlocks[i2].targetName, in, info );
			};
			if ( info.version >= 0x0A01006A ) {
				NifStream( block_num, in, info );
				link_stack.push_back( block_num );
			};
			if ( info.version <= 0x14050000 ) {
				NifStream( block_num, in, info );
				link_stack.push_back( block_num );
			};
			if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A01006E ) ) {
				NifStream( block_num, in, info );
				link_stack.push_back( block_num );
				NifStream( controlledBlocks[i2].blendIndex, in, info );
			};
			if ( ( info.version >= 0x0A01006A ) && ( (info.userVersion2 > 0) ) ) {
				NifStream( controlledBlocks[i2].priority, in, info );
			};
			if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A010071 ) ) {
				NifStream( controlledBlocks[i2].nodeName, in, info );
				NifStream( controlledBlocks[i2].propertyType, in, info );
				NifStream( controlledBlocks[i2].controllerType, in, info );
				NifStream( controlledBlocks[i2].controllerId, in, info );
				NifStream( controlledBlocks[i2].interpolatorId, in, info );
			};
			if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
				NifStream( block_num, in, info );
				link_stack.push_back( block_num );
				NifStream( controlledBlocks[i2].nodeNameOffset, in, info );
				NifStream( controlledBlocks[i2].propertyTypeOffset, in, info );
				NifStream( controlledBlocks[i2].controllerTypeOffset, in, info );
				NifStream( controlledBlocks[i2].controllerIdOffset, in, info );
				NifStream( controlledBlocks[i2].interpolatorIdOffset, in, info );
			};
			if ( info.version >= 0x14010001 ) {
				NifStream( (IndexString&)controlledBlocks[i2].nodeName, in, info );
				NifStream( (IndexString&)controlledBlocks[i2].propertyType, in, info );
				NifStream( (IndexString&)controlledBlocks[i2].controllerType, in, info );
				NifStream( (IndexString&)controlledBlocks[i2].controllerId, in, info );
				NifStream( (IndexString&)controlledBlocks[i2].interpolatorId, in, info );
			};
		};
	};
	if ( info.version >= 0x14050002 ) {
		NifStream( numEvaluators, in, info );
		evaluators.resize(numEvaluators);
		for (unsigned int i2 = 0; i2 < evaluators.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( duration, in, info );
	NifStream( cycleType, in, info );
	NifStream( frequency, in, info );
	NifStream( accumRootName, in, info );
	NifStream( accumFlags, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiSequenceData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numEvaluators = (unsigned int)(evaluators.size());
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	NifStream( name, out, info );
	if ( info.version <= 0x14050001 ) {
		NifStream( numControlledBlocks, out, info );
		NifStream( arrayGrowBy, out, info );
		for (unsigned int i2 = 0; i2 < controlledBlocks.size(); i2++) {
			if ( info.version <= 0x0A010067 ) {
				NifStream( controlledBlocks[i2].targetName, out, info );
			};
			if ( info.version >= 0x0A01006A ) {
				WriteRef( StaticCast<NiObject>(controlledBlocks[i2].interpolator), out, info, link_map, missing_link_stack );
			};
			if ( info.version <= 0x14050000 ) {
				WriteRef( StaticCast<NiObject>(controlledBlocks[i2].controller), out, info, link_map, missing_link_stack );
			};
			if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A01006E ) ) {
				WriteRef( StaticCast<NiObject>(controlledBlocks[i2].blendInterpolator), out, info, link_map, missing_link_stack );
				NifStream( controlledBlocks[i2].blendIndex, out, info );
			};
			if ( ( info.version >= 0x0A01006A ) && ( (info.userVersion2 > 0) ) ) {
				NifStream( controlledBlocks[i2].priority, out, info );
			};
			if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A010071 ) ) {
				NifStream( controlledBlocks[i2].nodeName, out, info );
				NifStream( controlledBlocks[i2].propertyType, out, info );
				NifStream( controlledBlocks[i2].controllerType, out, info );
				NifStream( controlledBlocks[i2].controllerId, out, info );
				NifStream( controlledBlocks[i2].interpolatorId, out, info );
			};
			if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
				WriteRef( StaticCast<NiObject>(controlledBlocks[i2].stringPalette), out, info, link_map, missing_link_stack );
				NifStream( controlledBlocks[i2].nodeNameOffset, out, info );
				NifStream( controlledBlocks[i2].propertyTypeOffset, out, info );
				NifStream( controlledBlocks[i2].controllerTypeOffset, out, info );
				NifStream( controlledBlocks[i2].controllerIdOffset, out, info );
				NifStream( controlledBlocks[i2].interpolatorIdOffset, out, info );
			};
			if ( info.version >= 0x14010001 ) {
				NifStream( (IndexString&)controlledBlocks[i2].nodeName, out, info );
				NifStream( (IndexString&)controlledBlocks[i2].propertyType, out, info );
				NifStream( (IndexString&)controlledBlocks[i2].controllerType, out, info );
				NifStream( (IndexString&)controlledBlocks[i2].controllerId, out, info );
				NifStream( (IndexString&)controlledBlocks[i2].interpolatorId, out, info );
			};
		};
	};
	if ( info.version >= 0x14050002 ) {
		NifStream( numEvaluators, out, info );
		for (unsigned int i2 = 0; i2 < evaluators.size(); i2++) {
			WriteRef( StaticCast<NiObject>(evaluators[i2]), out, info, link_map, missing_link_stack );
		};
	};
	WriteRef( StaticCast<NiObject>(textKeys), out, info, link_map, missing_link_stack );
	NifStream( duration, out, info );
	NifStream( cycleType, out, info );
	NifStream( frequency, out, info );
	NifStream( accumRootName, out, info );
	NifStream( accumFlags, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiSequenceData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numEvaluators = (unsigned int)(evaluators.size());
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	out << "  Name:  " << name << endl;
	out << "  Num Controlled Blocks:  " << numControlledBlocks << endl;
	out << "  Array Grow By:  " << arrayGrowBy << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Target Name:  " << controlledBlocks[i1].targetName << endl;
		out << "    Interpolator:  " << controlledBlocks[i1].interpolator << endl;
		out << "    Controller:  " << controlledBlocks[i1].controller << endl;
		out << "    Blend Interpolator:  " << controlledBlocks[i1].blendInterpolator << endl;
		out << "    Blend Index:  " << controlledBlocks[i1].blendIndex << endl;
		out << "    Priority:  " << controlledBlocks[i1].priority << endl;
		out << "    Node Name:  " << controlledBlocks[i1].nodeName << endl;
		out << "    Property Type:  " << controlledBlocks[i1].propertyType << endl;
		out << "    Controller Type:  " << controlledBlocks[i1].controllerType << endl;
		out << "    Controller ID:  " << controlledBlocks[i1].controllerId << endl;
		out << "    Interpolator ID:  " << controlledBlocks[i1].interpolatorId << endl;
		out << "    String Palette:  " << controlledBlocks[i1].stringPalette << endl;
		out << "    Node Name Offset:  " << controlledBlocks[i1].nodeNameOffset << endl;
		out << "    Property Type Offset:  " << controlledBlocks[i1].propertyTypeOffset << endl;
		out << "    Controller Type Offset:  " << controlledBlocks[i1].controllerTypeOffset << endl;
		out << "    Controller ID Offset:  " << controlledBlocks[i1].controllerIdOffset << endl;
		out << "    Interpolator ID Offset:  " << controlledBlocks[i1].interpolatorIdOffset << endl;
	};
	out << "  Num Evaluators:  " << numEvaluators << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < evaluators.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Evaluators[" << i1 << "]:  " << evaluators[i1] << endl;
		array_output_count++;
	};
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Duration:  " << duration << endl;
	out << "  Cycle Type:  " << cycleType << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Accum Root Name:  " << accumRootName << endl;
	out << "  Accum Flags:  " << accumFlags << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiSequenceData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version <= 0x14050001 ) {
		for (unsigned int i2 = 0; i2 < controlledBlocks.size(); i2++) {
			if ( info.version >= 0x0A01006A ) {
				controlledBlocks[i2].interpolator = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
			};
			if ( info.version <= 0x14050000 ) {
				controlledBlocks[i2].controller = FixLink<NiTimeController>( objects, link_stack, missing_link_stack, info );
			};
			if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A01006E ) ) {
				controlledBlocks[i2].blendInterpolator = FixLink<NiBlendInterpolator>( objects, link_stack, missing_link_stack, info );
			};
			if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
				controlledBlocks[i2].stringPalette = FixLink<NiStringPalette>( objects, link_stack, missing_link_stack, info );
			};
		};
	};
	if ( info.version >= 0x14050002 ) {
		for (unsigned int i2 = 0; i2 < evaluators.size(); i2++) {
			evaluators[i2] = FixLink<NiEvaluator>( objects, link_stack, missing_link_stack, info );
		};
	};
	textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSequenceData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( controlledBlocks[i1].interpolator != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].interpolator));
		if ( controlledBlocks[i1].controller != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].controller));
		if ( controlledBlocks[i1].blendInterpolator != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].blendInterpolator));
		if ( controlledBlocks[i1].stringPalette != NULL )
			refs.push_back(StaticCast<NiObject>(controlledBlocks[i1].stringPalette));
	};
	for (unsigned int i1 = 0; i1 < evaluators.size(); i1++) {
		if ( evaluators[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(evaluators[i1]));
	};
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	return refs;
}

std::list<NiObject *> NiSequenceData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
	};
	for (unsigned int i1 = 0; i1 < evaluators.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
