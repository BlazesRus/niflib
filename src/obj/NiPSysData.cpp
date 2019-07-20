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
#include "../../include/obj/NiPSysData.h"
#include "../../include/gen/ParticleDesc.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPSysData::TYPE("NiPSysData", &NiParticlesData::TYPE );

NiPSysData::NiPSysData() : hasRotationSpeeds(false), numAddedParticles((unsigned short)0), addedParticlesBase((unsigned short)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

NiPSysData::~NiPSysData() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & NiPSysData::GetType() const {
	return TYPE;
}

NiObject * NiPSysData::Create() {
	return new NiPSysData;
}

void NiPSysData::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticlesData::Read( in, link_stack, info );
	if ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) {
		particleDescriptions.resize(numVertices);
		for (unsigned int i2 = 0; i2 < particleDescriptions.size(); i2++) {
			NifStream( particleDescriptions[i2].translation, in, info );
			if ( info.version <= 0x0A040001 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( particleDescriptions[i2].unknownFloats1[i4], in, info );
				};
			};
			NifStream( particleDescriptions[i2].unknownFloat1, in, info );
			NifStream( particleDescriptions[i2].unknownFloat2, in, info );
			NifStream( particleDescriptions[i2].unknownFloat3, in, info );
			NifStream( particleDescriptions[i2].unknownInt1, in, info );
		};
	};
	if ( info.version >= 0x14000002 ) {
		NifStream( hasRotationSpeeds, in, info );
	};
	if ( ( info.version >= 0x14000002 ) && ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) ) {
		if ( hasRotationSpeeds ) {
			rotationSpeeds.resize(numVertices);
			for (unsigned int i3 = 0; i3 < rotationSpeeds.size(); i3++) {
				NifStream( rotationSpeeds[i3], in, info );
			};
		};
	};
	if ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) {
		NifStream( numAddedParticles, in, info );
		NifStream( addedParticlesBase, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticlesData::Write( out, link_map, missing_link_stack, info );
	if ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) {
		for (unsigned int i2 = 0; i2 < particleDescriptions.size(); i2++) {
			NifStream( particleDescriptions[i2].translation, out, info );
			if ( info.version <= 0x0A040001 ) {
				for (unsigned int i4 = 0; i4 < 3; i4++) {
					NifStream( particleDescriptions[i2].unknownFloats1[i4], out, info );
				};
			};
			NifStream( particleDescriptions[i2].unknownFloat1, out, info );
			NifStream( particleDescriptions[i2].unknownFloat2, out, info );
			NifStream( particleDescriptions[i2].unknownFloat3, out, info );
			NifStream( particleDescriptions[i2].unknownInt1, out, info );
		};
	};
	if ( info.version >= 0x14000002 ) {
		NifStream( hasRotationSpeeds, out, info );
	};
	if ( ( info.version >= 0x14000002 ) && ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) ) {
		if ( hasRotationSpeeds ) {
			for (unsigned int i3 = 0; i3 < rotationSpeeds.size(); i3++) {
				NifStream( rotationSpeeds[i3], out, info );
			};
		};
	};
	if ( (!((info.version == 0x14020007) && (info.userVersion2 > 0))) ) {
		NifStream( numAddedParticles, out, info );
		NifStream( addedParticlesBase, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string NiPSysData::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiParticlesData::asString();
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < particleDescriptions.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Translation:  " << particleDescriptions[i1].translation << endl;
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < 3; i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Unknown Floats 1[" << i2 << "]:  " << particleDescriptions[i1].unknownFloats1[i2] << endl;
			array_output_count++;
		};
		out << "    Unknown Float 1:  " << particleDescriptions[i1].unknownFloat1 << endl;
		out << "    Unknown Float 2:  " << particleDescriptions[i1].unknownFloat2 << endl;
		out << "    Unknown Float 3:  " << particleDescriptions[i1].unknownFloat3 << endl;
		out << "    Unknown Int 1:  " << particleDescriptions[i1].unknownInt1 << endl;
	};
	out << "  Has Rotation Speeds:  " << hasRotationSpeeds << endl;
	if ( hasRotationSpeeds ) {
		array_output_count = 0;
		for (unsigned int i2 = 0; i2 < rotationSpeeds.size(); i2++) {
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
				break;
			};
			if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
				break;
			};
			out << "      Rotation Speeds[" << i2 << "]:  " << rotationSpeeds[i2] << endl;
			array_output_count++;
		};
	};
	out << "  Num Added Particles:  " << numAddedParticles << endl;
	out << "  Added Particles Base:  " << addedParticlesBase << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void NiPSysData::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	NiParticlesData::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPSysData::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiParticlesData::GetRefs();
	return refs;
}

std::list<NiObject *> NiPSysData::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiParticlesData::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
