/* Copyright (c) 2005-2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

//--BEGIN FILE HEAD CUSTOM CODE--//
#include "../../include/obj/NiSingleInterpController.h"
#include "../../include/obj/NiObjectNET.h"
#include "../../include/obj/NiProperty.h"
#include "../../include/obj/NiInterpolator.h"
//--END CUSTOM CODE--//

#include "../../include/FixLink.h"
#include "../../include/ObjectRegistry.h"
#include "../../include/NIF_IO.h"
#include "../../include/obj/NiControllerSequence.h"
#include "../../include/obj/BSAnimNotes.h"
#include "../../include/obj/NiControllerManager.h"
#include "../../include/obj/NiStringPalette.h"
#include "../../include/obj/NiTextKeyExtraData.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiControllerSequence::TYPE("NiControllerSequence", &NiSequence::TYPE );

NiControllerSequence::NiControllerSequence() : weight(1.0f), textKeys(NULL), cycleType((CycleType)0), frequency(1.0f), phase(0.0f), startTime(3.402823466e+38f), stopTime(-3.402823466e+38f), playBackwards(false), manager(NULL), accumFlags((AccumFlags)ACCUM_X_FRONT), stringPalette(NULL), animNotes(NULL), numAnimNoteArrays((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiControllerSequence::~NiControllerSequence() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiControllerSequence::GetType() const {
	return TYPE;
}

NiObject * NiControllerSequence::Create() {
	return new NiControllerSequence;
}

void NiControllerSequence::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiSequence::Read( in, link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, in, info );
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( cycleType, in, info );
		NifStream( frequency, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A040001 ) ) {
		NifStream( phase, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( startTime, in, info );
		NifStream( stopTime, in, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( playBackwards, in, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
		NifStream( accumRootName, in, info );
	};
	if ( info.version >= 0x14030008 ) {
		NifStream( accumFlags, in, info );
	};
	if ( ( info.version >= 0x0A010071 ) && ( info.version <= 0x14010000 ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x14020007 ) && ( ((info.userVersion2 >= 24) && (info.userVersion2 <= 28)) ) ) {
		NifStream( block_num, in, info );
		link_stack.push_back( block_num );
	};
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 28) ) ) {
		NifStream( numAnimNoteArrays, in, info );
		animNoteArrays.resize(numAnimNoteArrays);
		for (unsigned int i2 = 0; i2 < animNoteArrays.size(); i2++) {
			NifStream( block_num, in, info );
			link_stack.push_back( block_num );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiControllerSequence::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiSequence::Write( out, link_map, missing_link_stack, info );
	numAnimNoteArrays = (unsigned short)(animNoteArrays.size());
	if ( info.version >= 0x0A01006A ) {
		NifStream( weight, out, info );
		WriteRef( StaticCast<NiObject>(textKeys), out, info, link_map, missing_link_stack );
		NifStream( cycleType, out, info );
		NifStream( frequency, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A040001 ) ) {
		NifStream( phase, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		NifStream( startTime, out, info );
		NifStream( stopTime, out, info );
	};
	if ( ( info.version >= 0x0A01006A ) && ( info.version <= 0x0A01006A ) ) {
		NifStream( playBackwards, out, info );
	};
	if ( info.version >= 0x0A01006A ) {
		WriteRef( StaticCast<NiObject>(manager), out, info, link_map, missing_link_stack );
		NifStream( accumRootName, out, info );
	};
	if ( info.version >= 0x14030008 ) {
		NifStream( accumFlags, out, info );
	};
	if ( ( info.version >= 0x0A010071 ) && ( info.version <= 0x14010000 ) ) {
		WriteRef( StaticCast<NiObject>(stringPalette), out, info, link_map, missing_link_stack );
	};
	if ( ( info.version >= 0x14020007 ) && ( ((info.userVersion2 >= 24) && (info.userVersion2 <= 28)) ) ) {
		WriteRef( StaticCast<NiObject>(animNotes), out, info, link_map, missing_link_stack );
	};
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 28) ) ) {
		NifStream( numAnimNoteArrays, out, info );
		for (unsigned int i2 = 0; i2 < animNoteArrays.size(); i2++) {
			WriteRef( StaticCast<NiObject>(animNoteArrays[i2]), out, info, link_map, missing_link_stack );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiControllerSequence::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiSequence::asString();
	numAnimNoteArrays = (unsigned short)(animNoteArrays.size());
	out << "  Weight:  " << weight << endl;
	out << "  Text Keys:  " << textKeys << endl;
	out << "  Cycle Type:  " << cycleType << endl;
	out << "  Frequency:  " << frequency << endl;
	out << "  Phase:  " << phase << endl;
	out << "  Start Time:  " << startTime << endl;
	out << "  Stop Time:  " << stopTime << endl;
	out << "  Play Backwards:  " << playBackwards << endl;
	out << "  Manager:  " << manager << endl;
	out << "  Accum Root Name:  " << accumRootName << endl;
	out << "  Accum Flags:  " << accumFlags << endl;
	out << "  String Palette:  " << stringPalette << endl;
	out << "  Anim Notes:  " << animNotes << endl;
	out << "  Num Anim Note Arrays:  " << numAnimNoteArrays << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < animNoteArrays.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			break;
		};
		out << "    Anim Note Arrays[" << i1 << "]:  " << animNoteArrays[i1] << endl;
		array_output_count++;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiControllerSequence::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiSequence::FixLinks( objects, link_stack, missing_link_stack, info );
	if ( info.version >= 0x0A01006A ) {
		textKeys = FixLink<NiTextKeyExtraData>( objects, link_stack, missing_link_stack, info );
		manager = FixLink<NiControllerManager>( objects, link_stack, missing_link_stack, info );
	};
	if ( ( info.version >= 0x0A010071 ) && ( info.version <= 0x14010000 ) ) {
		stringPalette = FixLink<NiStringPalette>( objects, link_stack, missing_link_stack, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( ((info.userVersion2 >= 24) && (info.userVersion2 <= 28)) ) ) {
		animNotes = FixLink<BSAnimNotes>( objects, link_stack, missing_link_stack, info );
	};
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 28) ) ) {
		for (unsigned int i2 = 0; i2 < animNoteArrays.size(); i2++) {
			animNoteArrays[i2] = FixLink<BSAnimNotes>( objects, link_stack, missing_link_stack, info );
		};
	};

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiControllerSequence::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiSequence::GetRefs();
	if ( textKeys != NULL )
		refs.push_back(StaticCast<NiObject>(textKeys));
	if ( stringPalette != NULL )
		refs.push_back(StaticCast<NiObject>(stringPalette));
	if ( animNotes != NULL )
		refs.push_back(StaticCast<NiObject>(animNotes));
	for (unsigned int i1 = 0; i1 < animNoteArrays.size(); i1++) {
		if ( animNoteArrays[i1] != NULL )
			refs.push_back(StaticCast<NiObject>(animNoteArrays[i1]));
	};
	return refs;
}

std::list<NiObject *> NiControllerSequence::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiSequence::GetPtrs();
	if ( manager != NULL )
		ptrs.push_back((NiObject *)(manager));
	for (unsigned int i1 = 0; i1 < animNoteArrays.size(); i1++) {
	};
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

NiControllerManager * NiControllerSequence::GetParent() const { 
   return manager; 
}

void NiControllerSequence::SetParent(NiControllerManager * parent) { 
   manager = parent; 
}

void NiControllerSequence::SetTextKey( NiTextKeyExtraData * txt_key ) {
	//Set new name
	textKeysName = txt_key->GetName();
	textKeys = txt_key;
}

void NiControllerSequence::AddController( NiTimeController * obj ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence.");
	}

	NiObjectNETRef target = obj->GetTarget();
	if ( target == NULL ) {
		throw runtime_error("Controller must have a target to be added to a NiControllerSequence.");
	}
	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;
	cl.controller = obj;
	cl.targetName = target->GetName();
	cl.nodeName = target->GetName();

	NiPropertyRef prop = DynamicCast<NiProperty>(target);
	if ( prop != NULL ) {
		cl.propertyType = prop->GetType().GetTypeName();
	}

	cl.controllerType = obj->GetType().GetTypeName();

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}

void NiControllerSequence::AddController( string const & targetName, NiTimeController * obj ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence.");
	}

	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;
	cl.controller = obj;
	cl.targetName = targetName;
	cl.nodeName = targetName;

	cl.controllerType = obj->GetType().GetTypeName();

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}

void NiControllerSequence::AddInterpolator( NiSingleInterpController * obj, byte priority ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence block.");
	}

	NiInterpolatorRef interp = obj->GetInterpolator();
	if ( interp == NULL ) {
		throw runtime_error("Controller must have an interpolator attached to be added to a NiControllerSequence with the AddInterpolator function.");
	}

	NiObjectNETRef target = obj->GetTarget();
	if ( target == NULL ) {
		throw runtime_error("Controller must have a target to be added to a NiControllerSequence.");
	}

	//If there are existing ControllerLinks, use the same StringPalette they're using
   if ( stringPalette == NULL ) {
      stringPalette = new NiStringPalette;
	}

	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;

	cl.interpolator = interp;
	cl.priority = priority;
	cl.stringPalette = stringPalette;
	cl.nodeName = target->GetName();
	cl.nodeNameOffset = stringPalette->AddSubStr( target->GetName() );

	NiPropertyRef prop = DynamicCast<NiProperty>(target);
	if ( prop != NULL ) {
		cl.propertyTypeOffset = stringPalette->AddSubStr( prop->GetType().GetTypeName() );
	}

	cl.controllerTypeOffset = stringPalette->AddSubStr( obj->GetType().GetTypeName() );

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}


void NiControllerSequence::AddInterpolator( NiSingleInterpController * obj, byte priority , bool include_string_pallete ) {
	//Make sure the link isn't null
	if ( obj == NULL ) {
		throw runtime_error("Attempted to add a null controller to NiControllerSequence block.");
	}

	NiInterpolatorRef interp = obj->GetInterpolator();
	if ( interp == NULL ) {
		throw runtime_error("Controller must have an interpolator attached to be added to a NiControllerSequence with the AddInterpolator function.");
	}

	NiObjectNETRef target = obj->GetTarget();
	if ( target == NULL ) {
		throw runtime_error("Controller must have a target to be added to a NiControllerSequence.");
	}



	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;

	NiPropertyRef prop = DynamicCast<NiProperty>(target);

	cl.interpolator = interp;
	cl.priority = priority;
	if(include_string_pallete == true) {
		//If there are existing ControllerLinks, use the same StringPalette they're using
		if ( stringPalette == NULL ) {
			stringPalette = new NiStringPalette;
		}

		cl.stringPalette = stringPalette;
		cl.nodeNameOffset = stringPalette->AddSubStr( target->GetName() );
		
		if ( prop != NULL ) {
			cl.propertyTypeOffset = stringPalette->AddSubStr( prop->GetType().GetTypeName() );
		}

		cl.controllerTypeOffset = stringPalette->AddSubStr( obj->GetType().GetTypeName() );

	} else {
		cl.stringPalette = NULL;
		cl.nodeName = target->GetName();
		if(prop != NULL) {
			cl.propertyType = prop->GetType().GetTypeName();
		}
		cl.controllerType = obj->GetType().GetTypeName();
	}


	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}


void NiControllerSequence::AddGenericInterpolator( NiInterpolator * interpolator, NiObjectNET* target, string controller_type_name, byte priority /*= 0*/, bool include_string_pallete /*= true*/ ) {
	//Make sure the parameters aren't null

	if(interpolator == NULL) {
		throw runtime_error("Attempted to add a null interpolator to the controller sequence");
	}

	if(target == NULL) {
		throw runtime_error("Attempted to add a null target to the controller sequence");
	}

	//Make a new ControllerLink and fill out necessary data
	ControllerLink cl;

	NiPropertyRef prop = DynamicCast<NiProperty>(target);

	cl.interpolator = interpolator;
	cl.priority = priority;
	if(include_string_pallete == true) {
		//If there are existing ControllerLinks, use the same StringPalette they're using
		if ( stringPalette == NULL ) {
			stringPalette = new NiStringPalette;
		}

		cl.stringPalette = stringPalette;
		cl.nodeNameOffset = stringPalette->AddSubStr( target->GetName() );

		if ( prop != NULL ) {
			cl.propertyTypeOffset = stringPalette->AddSubStr( prop->GetType().GetTypeName() );
		}

		cl.controllerTypeOffset = stringPalette->AddSubStr( controller_type_name );

	} else {
		cl.stringPalette = NULL;
		cl.nodeName = target->GetName();
		if(prop != NULL) {
			cl.propertyType = prop->GetType().GetTypeName();
		}
		cl.controllerType = controller_type_name;
	}

	//Add finished ControllerLink to list
	controlledBlocks.push_back( cl );
}



void NiControllerSequence::ClearControllerData() {
	
	throw runtime_error("The AddInterpolator function cannot be implemented until problems in the XML are solved.");

	//Clear list
	controlledBlocks.clear();
}

vector<ControllerLink> NiControllerSequence::GetControllerData() const {
	return controlledBlocks;
}

void NiControllerSequence::SetControllerData(const vector<ControllerLink>& value) {
	if ( value.size() != controlledBlocks.size() ) 
		throw runtime_error("The SetControllerData requires the ControllerLink array size to match the existing array.");
	controlledBlocks = value;
}


Ref<NiTextKeyExtraData> NiControllerSequence::GetTextKeyExtraData() const {
   if (textKeys != NULL)
	   return textKeys;
   return NiSequence::GetTextKeys();
}


float NiControllerSequence::GetFrequency() const {
	return frequency;
}

void NiControllerSequence::SetFrequency( float value ) {
	frequency = value;
}

float NiControllerSequence::GetStartTime() const {
	return startTime;
}

void NiControllerSequence::SetStartTime( float value ) {
	startTime = value;
}

float NiControllerSequence::GetStopTime() const {
	return stopTime;
}

void NiControllerSequence::SetStopTime( float value ) {
	stopTime = value;
}

CycleType NiControllerSequence::GetCycleType() const {
	return CycleType(cycleType);
}

void NiControllerSequence::SetCycleType( CycleType n ) {
	cycleType = n;
}

int NiControllerSequence::GetNumControllers() const {
   return int(controlledBlocks.size());
}

int NiControllerSequence::GetControllerPriority( int controller ) const {
   if (controller < 0 && controller < int(controlledBlocks.size())) {
      throw runtime_error("Invalid controller index.");
   }   
   return int(controlledBlocks[controller].priority);
}

void NiControllerSequence::SetControllerPriority( int controller, int priority ) {
   if (controller < 0 && controller < int(controlledBlocks.size())) {
      throw runtime_error("Invalid controller index.");
   }   
   if (priority < 0 || priority > int(0xFF)) {
      throw runtime_error("Invalid priority must be between 0 and 255.");
   }
   controlledBlocks[controller].priority = priority;
}

string NiControllerSequence::GetName() const {
	return name;
}

void NiControllerSequence::SetName( const string & value ) {
	name = value;
}

string NiControllerSequence::GetTargetName() const {
	return targetName;
}

void NiControllerSequence::SetTargetName( const string & value ) {
	targetName = value;
}

float NiControllerSequence::GetWeight() const {
	return weight;
}

void NiControllerSequence::SetWeight( const float value ) {
	weight = value;
}


Ref<NiStringPalette > Niflib::NiControllerSequence::GetStringPalette() const {
	return stringPalette;
}

void Niflib::NiControllerSequence::SetStringPalette( const Ref<NiStringPalette >& value ) {
	stringPalette = value;
}
//--END CUSTOM CODE--//
