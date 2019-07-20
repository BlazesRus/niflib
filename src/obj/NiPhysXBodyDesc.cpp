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
#include "../../include/obj/NiPhysXBodyDesc.h"
#include "../../include/gen/PhysXBodyStoredVels.h"
using namespace Niflib;

//Definition of TYPE constant
const Type NiPhysXBodyDesc::TYPE("NiPhysXBodyDesc", &NiObject::TYPE );

NiPhysXBodyDesc::NiPhysXBodyDesc() : mass(0.0f), numVels((unsigned int)0), wakeUpCounter(0.0f), linearDamping(0.0f), angularDamping(0.0f), maxAngularVelocity(0.0f), ccdMotionThreshold(0.0f), flags((unsigned int)0), sleepLinearVelocity(0.0f), sleepAngularVelocity(0.0f), solverIterationCount((unsigned int)0), sleepEnergyThreshold(0.0f), sleepDamping(0.0f), contactReportThreshold(0.0f) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

NiPhysXBodyDesc::~NiPhysXBodyDesc() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & NiPhysXBodyDesc::GetType() const {
	return TYPE;
}

NiObject * NiPhysXBodyDesc::Create() {
	return new NiPhysXBodyDesc;
}

void NiPhysXBodyDesc::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Read( in, link_stack, info );
	NifStream( localPose, in, info );
	NifStream( spaceInertia, in, info );
	NifStream( mass, in, info );
	NifStream( numVels, in, info );
	vels.resize(numVels);
	for (unsigned int i1 = 0; i1 < vels.size(); i1++) {
		NifStream( vels[i1].linearVelocity, in, info );
		NifStream( vels[i1].angularVelocity, in, info );
		if ( info.version >= 0x1E020003 ) {
			NifStream( vels[i1].sleep, in, info );
		};
	};
	NifStream( wakeUpCounter, in, info );
	NifStream( linearDamping, in, info );
	NifStream( angularDamping, in, info );
	NifStream( maxAngularVelocity, in, info );
	NifStream( ccdMotionThreshold, in, info );
	NifStream( flags, in, info );
	NifStream( sleepLinearVelocity, in, info );
	NifStream( sleepAngularVelocity, in, info );
	NifStream( solverIterationCount, in, info );
	if ( info.version >= 0x14030000 ) {
		NifStream( sleepEnergyThreshold, in, info );
		NifStream( sleepDamping, in, info );
	};
	if ( info.version >= 0x14040000 ) {
		NifStream( contactReportThreshold, in, info );
	};

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXBodyDesc::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::Write( out, link_map, missing_link_stack, info );
	numVels = (unsigned int)(vels.size());
	NifStream( localPose, out, info );
	NifStream( spaceInertia, out, info );
	NifStream( mass, out, info );
	NifStream( numVels, out, info );
	for (unsigned int i1 = 0; i1 < vels.size(); i1++) {
		NifStream( vels[i1].linearVelocity, out, info );
		NifStream( vels[i1].angularVelocity, out, info );
		if ( info.version >= 0x1E020003 ) {
			NifStream( vels[i1].sleep, out, info );
		};
	};
	NifStream( wakeUpCounter, out, info );
	NifStream( linearDamping, out, info );
	NifStream( angularDamping, out, info );
	NifStream( maxAngularVelocity, out, info );
	NifStream( ccdMotionThreshold, out, info );
	NifStream( flags, out, info );
	NifStream( sleepLinearVelocity, out, info );
	NifStream( sleepAngularVelocity, out, info );
	NifStream( solverIterationCount, out, info );
	if ( info.version >= 0x14030000 ) {
		NifStream( sleepEnergyThreshold, out, info );
		NifStream( sleepDamping, out, info );
	};
	if ( info.version >= 0x14040000 ) {
		NifStream( contactReportThreshold, out, info );
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string NiPhysXBodyDesc::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	unsigned int array_output_count = 0;
	out << NiObject::asString();
	numVels = (unsigned int)(vels.size());
	out << "  Local Pose:  " << localPose << endl;
	out << "  Space Inertia:  " << spaceInertia << endl;
	out << "  Mass:  " << mass << endl;
	out << "  Num Vels:  " << numVels << endl;
	array_output_count = 0;
	for (unsigned int i1 = 0; i1 < vels.size(); i1++) {
		if ( !verbose && ( array_output_count > MAXARRAYDUMP ) ) {
			out << "<Data Truncated. Use verbose mode to see complete listing.>" << endl;
			break;
		};
		out << "    Linear Velocity:  " << vels[i1].linearVelocity << endl;
		out << "    Angular Velocity:  " << vels[i1].angularVelocity << endl;
		out << "    Sleep:  " << vels[i1].sleep << endl;
	};
	out << "  Wake Up Counter:  " << wakeUpCounter << endl;
	out << "  Linear Damping:  " << linearDamping << endl;
	out << "  Angular Damping:  " << angularDamping << endl;
	out << "  Max Angular Velocity:  " << maxAngularVelocity << endl;
	out << "  CCD Motion Threshold:  " << ccdMotionThreshold << endl;
	out << "  Flags:  " << flags << endl;
	out << "  Sleep Linear Velocity:  " << sleepLinearVelocity << endl;
	out << "  Sleep Angular Velocity:  " << sleepAngularVelocity << endl;
	out << "  Solver Iteration Count:  " << solverIterationCount << endl;
	out << "  Sleep Energy Threshold:  " << sleepEnergyThreshold << endl;
	out << "  Sleep Damping:  " << sleepDamping << endl;
	out << "  Contact Report Threshold:  " << contactReportThreshold << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void NiPhysXBodyDesc::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiObject::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> NiPhysXBodyDesc::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiObject::GetRefs();
	return refs;
}

std::list<NiObject *> NiPhysXBodyDesc::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiObject::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
