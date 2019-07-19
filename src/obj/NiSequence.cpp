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
#include "../../include/obj/NiSequence.h"
#include "../../include/gen/ControlledBlock.h"
#include "../../include/obj/NiBlendInterpolator.h"
#include "../../include/obj/NiInterpolator.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/obj/NiTextKeyExtraData.h"
#include "../../include/obj/NiTimeController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiSequence::TYPE("NiSequence", &NiObject::TYPE );

NiSequence::NiSequence() : textKeys(NULL), unknownInt4((int)0), unknownInt5((int)0), numControlledBlocks((unsigned int)0), arrayGrowBy((unsigned int)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiSequence::~NiSequence() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiSequence::GetType() const {
	return TYPE;
}

NiObject * NiSequence::Create() {
	return new NiSequence;
}

void NiSequence::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiObject::Read( in, link_stack, info );
	NifStream( name, in, info );
	if ( info.version <= 0x0A010067 ) {
		NifStream( accumRootName, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( info.userVersion == 131072 ) ) {
		NifStream( unknownInt4, in, info );
		NifStream( unknownInt5, in, info );
	};
	NifStream( numControlledBlocks, in, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( arrayGrowBy, in, info );
	};
	controlledBlocks.resize(numControlledBlocks);
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version <= 0x0A010067 ) {
			NifStream( controlledBlocks[i1].targetName, in, info );
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
			NifStream( controlledBlocks[i1].blendIndex, in, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( (info.userVersion2 > 0) ) ) {
			NifStream( controlledBlocks[i1].priority, in, info );
		};
		if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A010071 ) ) {
			NifStream( controlledBlocks[i1].nodeName, in, info );
			NifStream( controlledBlocks[i1].propertyType, in, info );
			NifStream( controlledBlocks[i1].controllerType, in, info );
			NifStream( controlledBlocks[i1].controllerId, in, info );
			NifStream( controlledBlocks[i1].interpolatorId, in, info );
		};
		if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
			NifStream( controlledBlocks[i1].nodeNameOffset, in, info );
			NifStream( controlledBlocks[i1].propertyTypeOffset, in, info );
			NifStream( controlledBlocks[i1].controllerTypeOffset, in, info );
			NifStream( controlledBlocks[i1].controllerIdOffset, in, info );
			NifStream( controlledBlocks[i1].interpolatorIdOffset, in, info );
		};
		if ( info.version >= 0x14010001 ) {
			NifStream( (IndexString&)controlledBlocks[i1].nodeName, in, info );
			NifStream( (IndexString&)controlledBlocks[i1].propertyType, in, info );
			NifStream( (IndexString&)controlledBlocks[i1].controllerType, in, info );
			NifStream( (IndexString&)controlledBlocks[i1].controllerId, in, info );
			NifStream( (IndexString&)controlledBlocks[i1].interpolatorId, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSequence::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	NifStream( name, out, info );
	if ( info.version <= 0x0A010067 ) {
		NifStream( accumRootName, out, info );
		WriteRef( StaticCast<NiObject>(textKeys), out, info, link_map, missing_link_stack );
	};
	if ( ( info.version >= 0x14030009 ) && ( info.version <= 0x14030009 ) && ( info.userVersion == 131072 ) ) {
		NifStream( unknownInt4, out, info );
		NifStream( unknownInt5, out, info );
	};
	NifStream( numControlledBlocks, out, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( arrayGrowBy, out, info );
	};
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version <= 0x0A010067 ) {
			NifStream( controlledBlocks[i1].targetName, out, info );
		};
		if ( info.version >= 0x0A01006A ) {
			WriteRef( StaticCast<NiObject>(controlledBlocks[i1].interpolator), out, info, link_map, missing_link_stack );
		};
		if ( info.version <= 0x14050000 ) {
			WriteRef( StaticCast<NiObject>(controlledBlocks[i1].controller), out, info, link_map, missing_link_stack );
		};
		if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A01006E ) ) {
			WriteRef( StaticCast<NiObject>(controlledBlocks[i1].blendInterpolator), out, info, link_map, missing_link_stack );
			NifStream( controlledBlocks[i1].blendIndex, out, info );
		};
		if ( ( info.version >= 0x0A01006A ) && ( (info.userVersion2 > 0) ) ) {
			NifStream( controlledBlocks[i1].priority, out, info );
		};
		if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A010071 ) ) {
			NifStream( controlledBlocks[i1].nodeName, out, info );
			NifStream( controlledBlocks[i1].propertyType, out, info );
			NifStream( controlledBlocks[i1].controllerType, out, info );
			NifStream( controlledBlocks[i1].controllerId, out, info );
			NifStream( controlledBlocks[i1].interpolatorId, out, info );
		};
		if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
			WriteRef( StaticCast<NiObject>(controlledBlocks[i1].stringPalette), out, info, link_map, missing_link_stack );
			NifStream( controlledBlocks[i1].nodeNameOffset, out, info );
			NifStream( controlledBlocks[i1].propertyTypeOffset, out, info );
			NifStream( controlledBlocks[i1].controllerTypeOffset, out, info );
			NifStream( controlledBlocks[i1].controllerIdOffset, out, info );
			NifStream( controlledBlocks[i1].interpolatorIdOffset, out, info );
		};
		if ( info.version >= 0x14010001 ) {
			NifStream( (IndexString&)controlledBlocks[i1].nodeName, out, info );
			NifStream( (IndexString&)controlledBlocks[i1].propertyType, out, info );
			NifStream( (IndexString&)controlledBlocks[i1].controllerType, out, info );
			NifStream( (IndexString&)controlledBlocks[i1].controllerId, out, info );
			NifStream( (IndexString&)controlledBlocks[i1].interpolatorId, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiSequence::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numControlledBlocks = (unsigned int)(controlledBlocks.size());
	out << "  Name:  " << name << endl;
	out << "  Accum Root Name:  " << accumRootName << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Unknown Int 4:  " << unknownInt4 << endl;
	out << "  Unknown Int 5:  " << unknownInt5 << endl;
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
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiSequence::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version <= 0x0A010067 ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, missing_link_stack, info );
	};
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
		if ( info.version >= 0x0A01006A ) {
			controlledBlocks[i1].interpolator = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
		};
		if ( info.version <= 0x14050000 ) {
			controlledBlocks[i1].controller = FixLink<NiTimeController>( objects, link_stack, missing_link_stack, info );
		};
		if ( ( info.version >= 0x0A010068 ) && ( info.version <= 0x0A01006E ) ) {
			controlledBlocks[i1].blendInterpolator = FixLink<NiBlendInterpolator>( objects, link_stack, missing_link_stack, info );
		};
		if ( ( info.version >= 0x0A020000 ) && ( info.version <= 0x14010000 ) ) {
			controlledBlocks[i1].stringPalette = FixLink<NiStringPalette>( objects, link_stack, missing_link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiSequence::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
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
	return refs;
}

std::list<NiObject *> NiSequence::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	for (unsigned int i1 = 0; i1 < controlledBlocks.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
string NiSequence::GetName() const {
   return name;
}

void NiSequence::SetName( const string & value ) {
   name = value;
}

string NiSequence::GetTextKeysName() const {
   return textKeysName;
}

void NiSequence::SetTextKeysName( const string & value ) {
   textKeysName = value;
}

Ref<NiTextKeyExtraData > NiSequence::GetTextKeys() const {
   return textKeys;
}

void NiSequence::SetTextKeys( Ref<NiTextKeyExtraData > value ) {
   textKeys = value;
}

vector<ControllerLink > NiSequence::GetControlledBlocks() const {
   return controlledBlocks;
}

void NiSequence::SetControlledBlocks( const vector<ControllerLink >& value ) {
   controlledBlocks = value;
}

//--END CUSTOM CODE--//
