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
#include "../../include/obj/bhkPrismaticConstraint.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/PrismaticDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkPrismaticConstraint::TYPE("bhkPrismaticConstraint", &bhkConstraint::TYPE );

bhkPrismaticConstraint::bhkPrismaticConstraint() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkPrismaticConstraint::~bhkPrismaticConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkPrismaticConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkPrismaticConstraint::Create() {
	return new bhkPrismaticConstraint;
}

void bhkPrismaticConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	if ( info.version <= 0x14000005 ) {
		NifStream( prismatic.pivotA, in, info );
		NifStream( prismatic.rotationA, in, info );
		NifStream( prismatic.planeA, in, info );
		NifStream( prismatic.slidingA, in, info );
		NifStream( prismatic.pivotB, in, info );
		NifStream( prismatic.rotationB, in, info );
		NifStream( prismatic.planeB, in, info );
		NifStream( prismatic.slidingB, in, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( (Vector4&)prismatic.slidingA, in, info );
		NifStream( (Vector4&)prismatic.rotationA, in, info );
		NifStream( (Vector4&)prismatic.planeA, in, info );
		NifStream( (Vector4&)prismatic.pivotA, in, info );
		NifStream( (Vector4&)prismatic.slidingB, in, info );
		NifStream( (Vector4&)prismatic.rotationB, in, info );
		NifStream( (Vector4&)prismatic.planeB, in, info );
		NifStream( (Vector4&)prismatic.pivotB, in, info );
	};
	NifStream( prismatic.minDistance, in, info );
	NifStream( prismatic.maxDistance, in, info );
	NifStream( prismatic.friction, in, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( prismatic.motor.type, in, info );
		if ( (prismatic.motor.type == 1) ) {
			NifStream( prismatic.motor.positionMotor.minForce, in, info );
			NifStream( prismatic.motor.positionMotor.maxForce, in, info );
			NifStream( prismatic.motor.positionMotor.tau, in, info );
			NifStream( prismatic.motor.positionMotor.damping, in, info );
			NifStream( prismatic.motor.positionMotor.proportionalRecoveryVelocity, in, info );
			NifStream( prismatic.motor.positionMotor.constantRecoveryVelocity, in, info );
			NifStream( prismatic.motor.positionMotor.motorEnabled, in, info );
		};
		if ( (prismatic.motor.type == 2) ) {
			NifStream( prismatic.motor.velocityMotor.minForce, in, info );
			NifStream( prismatic.motor.velocityMotor.maxForce, in, info );
			NifStream( prismatic.motor.velocityMotor.tau, in, info );
			NifStream( prismatic.motor.velocityMotor.targetVelocity, in, info );
			NifStream( prismatic.motor.velocityMotor.useVelocityTarget, in, info );
			NifStream( prismatic.motor.velocityMotor.motorEnabled, in, info );
		};
		if ( (prismatic.motor.type == 3) ) {
			NifStream( prismatic.motor.springDamperMotor.minForce, in, info );
			NifStream( prismatic.motor.springDamperMotor.maxForce, in, info );
			NifStream( prismatic.motor.springDamperMotor.springConstant, in, info );
			NifStream( prismatic.motor.springDamperMotor.springDamping, in, info );
			NifStream( prismatic.motor.springDamperMotor.motorEnabled, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPrismaticConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	if ( info.version <= 0x14000005 ) {
		NifStream( prismatic.pivotA, out, info );
		NifStream( prismatic.rotationA, out, info );
		NifStream( prismatic.planeA, out, info );
		NifStream( prismatic.slidingA, out, info );
		NifStream( prismatic.pivotB, out, info );
		NifStream( prismatic.rotationB, out, info );
		NifStream( prismatic.planeB, out, info );
		NifStream( prismatic.slidingB, out, info );
	};
	if ( info.version >= 0x14020007 ) {
		NifStream( (Vector4&)prismatic.slidingA, out, info );
		NifStream( (Vector4&)prismatic.rotationA, out, info );
		NifStream( (Vector4&)prismatic.planeA, out, info );
		NifStream( (Vector4&)prismatic.pivotA, out, info );
		NifStream( (Vector4&)prismatic.slidingB, out, info );
		NifStream( (Vector4&)prismatic.rotationB, out, info );
		NifStream( (Vector4&)prismatic.planeB, out, info );
		NifStream( (Vector4&)prismatic.pivotB, out, info );
	};
	NifStream( prismatic.minDistance, out, info );
	NifStream( prismatic.maxDistance, out, info );
	NifStream( prismatic.friction, out, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( prismatic.motor.type, out, info );
		if ( (prismatic.motor.type == 1) ) {
			NifStream( prismatic.motor.positionMotor.minForce, out, info );
			NifStream( prismatic.motor.positionMotor.maxForce, out, info );
			NifStream( prismatic.motor.positionMotor.tau, out, info );
			NifStream( prismatic.motor.positionMotor.damping, out, info );
			NifStream( prismatic.motor.positionMotor.proportionalRecoveryVelocity, out, info );
			NifStream( prismatic.motor.positionMotor.constantRecoveryVelocity, out, info );
			NifStream( prismatic.motor.positionMotor.motorEnabled, out, info );
		};
		if ( (prismatic.motor.type == 2) ) {
			NifStream( prismatic.motor.velocityMotor.minForce, out, info );
			NifStream( prismatic.motor.velocityMotor.maxForce, out, info );
			NifStream( prismatic.motor.velocityMotor.tau, out, info );
			NifStream( prismatic.motor.velocityMotor.targetVelocity, out, info );
			NifStream( prismatic.motor.velocityMotor.useVelocityTarget, out, info );
			NifStream( prismatic.motor.velocityMotor.motorEnabled, out, info );
		};
		if ( (prismatic.motor.type == 3) ) {
			NifStream( prismatic.motor.springDamperMotor.minForce, out, info );
			NifStream( prismatic.motor.springDamperMotor.maxForce, out, info );
			NifStream( prismatic.motor.springDamperMotor.springConstant, out, info );
			NifStream( prismatic.motor.springDamperMotor.springDamping, out, info );
			NifStream( prismatic.motor.springDamperMotor.motorEnabled, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkPrismaticConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << prismatic.pivotA << endl;
	out << "  Rotation A:  " << prismatic.rotationA << endl;
	out << "  Plane A:  " << prismatic.planeA << endl;
	out << "  Sliding A:  " << prismatic.slidingA << endl;
	out << "  Pivot B:  " << prismatic.pivotB << endl;
	out << "  Rotation B:  " << prismatic.rotationB << endl;
	out << "  Plane B:  " << prismatic.planeB << endl;
	out << "  Sliding B:  " << prismatic.slidingB << endl;
	out << "  Min Distance:  " << prismatic.minDistance << endl;
	out << "  Max Distance:  " << prismatic.maxDistance << endl;
	out << "  Friction:  " << prismatic.friction << endl;
	out << "  Type:  " << prismatic.motor.type << endl;
	if ( (prismatic.motor.type == 1) ) {
		out << "    Min Force:  " << prismatic.motor.positionMotor.minForce << endl;
		out << "    Max Force:  " << prismatic.motor.positionMotor.maxForce << endl;
		out << "    Tau:  " << prismatic.motor.positionMotor.tau << endl;
		out << "    Damping:  " << prismatic.motor.positionMotor.damping << endl;
		out << "    Proportional Recovery Velocity:  " << prismatic.motor.positionMotor.proportionalRecoveryVelocity << endl;
		out << "    Constant Recovery Velocity:  " << prismatic.motor.positionMotor.constantRecoveryVelocity << endl;
		out << "    Motor Enabled:  " << prismatic.motor.positionMotor.motorEnabled << endl;
	};
	if ( (prismatic.motor.type == 2) ) {
		out << "    Min Force:  " << prismatic.motor.velocityMotor.minForce << endl;
		out << "    Max Force:  " << prismatic.motor.velocityMotor.maxForce << endl;
		out << "    Tau:  " << prismatic.motor.velocityMotor.tau << endl;
		out << "    Target Velocity:  " << prismatic.motor.velocityMotor.targetVelocity << endl;
		out << "    Use Velocity Target:  " << prismatic.motor.velocityMotor.useVelocityTarget << endl;
		out << "    Motor Enabled:  " << prismatic.motor.velocityMotor.motorEnabled << endl;
	};
	if ( (prismatic.motor.type == 3) ) {
		out << "    Min Force:  " << prismatic.motor.springDamperMotor.minForce << endl;
		out << "    Max Force:  " << prismatic.motor.springDamperMotor.maxForce << endl;
		out << "    Spring Constant:  " << prismatic.motor.springDamperMotor.springConstant << endl;
		out << "    Spring Damping:  " << prismatic.motor.springDamperMotor.springDamping << endl;
		out << "    Motor Enabled:  " << prismatic.motor.springDamperMotor.motorEnabled << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkPrismaticConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkPrismaticConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkPrismaticConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
