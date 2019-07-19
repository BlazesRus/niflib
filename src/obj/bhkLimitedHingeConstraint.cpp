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
#include "../../include/obj/bhkLimitedHingeConstraint.h"
#include "../../include/gen/LimitedHingeDescriptor.h"
#include "../../include/gen/MotorDescriptor.h"
#include "../../include/gen/bhkPositionConstraintMotor.h"
#include "../../include/gen/bhkSpringDamperConstraintMotor.h"
#include "../../include/gen/bhkVelocityConstraintMotor.h"
using namespace Niflib;

//Definition of TYPE constant
const Type bhkLimitedHingeConstraint::TYPE("bhkLimitedHingeConstraint", &bhkConstraint::TYPE );

bhkLimitedHingeConstraint::bhkLimitedHingeConstraint() {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

bhkLimitedHingeConstraint::~bhkLimitedHingeConstraint() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

const Type & bhkLimitedHingeConstraint::GetType() const {
	return TYPE;
}

NiObject * bhkLimitedHingeConstraint::Create() {
	return new bhkLimitedHingeConstraint;
}

void bhkLimitedHingeConstraint::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Read( in, link_stack, info );
	if ( (info.userVersion2 <= 16) ) {
		NifStream( limitedHinge.pivotA, in, info );
		NifStream( limitedHinge.axleA, in, info );
		NifStream( limitedHinge.perp2AxleInA1, in, info );
		NifStream( limitedHinge.perp2AxleInA2, in, info );
		NifStream( limitedHinge.pivotB, in, info );
		NifStream( limitedHinge.axleB, in, info );
		NifStream( limitedHinge.perp2AxleInB2, in, info );
	};
	if ( (info.userVersion2 > 16) ) {
		NifStream( (Vector4&)limitedHinge.axleA, in, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInA1, in, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInA2, in, info );
		NifStream( (Vector4&)limitedHinge.pivotA, in, info );
		NifStream( (Vector4&)limitedHinge.axleB, in, info );
		NifStream( limitedHinge.perp2AxleInB1, in, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInB2, in, info );
		NifStream( (Vector4&)limitedHinge.pivotB, in, info );
	};
	NifStream( limitedHinge.minAngle, in, info );
	NifStream( limitedHinge.maxAngle, in, info );
	NifStream( limitedHinge.maxFriction, in, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( limitedHinge.motor.type, in, info );
		if ( (limitedHinge.motor.type == 1) ) {
			NifStream( limitedHinge.motor.positionMotor.minForce, in, info );
			NifStream( limitedHinge.motor.positionMotor.maxForce, in, info );
			NifStream( limitedHinge.motor.positionMotor.tau, in, info );
			NifStream( limitedHinge.motor.positionMotor.damping, in, info );
			NifStream( limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, in, info );
			NifStream( limitedHinge.motor.positionMotor.constantRecoveryVelocity, in, info );
			NifStream( limitedHinge.motor.positionMotor.motorEnabled, in, info );
		};
		if ( (limitedHinge.motor.type == 2) ) {
			NifStream( limitedHinge.motor.velocityMotor.minForce, in, info );
			NifStream( limitedHinge.motor.velocityMotor.maxForce, in, info );
			NifStream( limitedHinge.motor.velocityMotor.tau, in, info );
			NifStream( limitedHinge.motor.velocityMotor.targetVelocity, in, info );
			NifStream( limitedHinge.motor.velocityMotor.useVelocityTarget, in, info );
			NifStream( limitedHinge.motor.velocityMotor.motorEnabled, in, info );
		};
		if ( (limitedHinge.motor.type == 3) ) {
			NifStream( limitedHinge.motor.springDamperMotor.minForce, in, info );
			NifStream( limitedHinge.motor.springDamperMotor.maxForce, in, info );
			NifStream( limitedHinge.motor.springDamperMotor.springConstant, in, info );
			NifStream( limitedHinge.motor.springDamperMotor.springDamping, in, info );
			NifStream( limitedHinge.motor.springDamperMotor.motorEnabled, in, info );
		};
	};

	//--BEGIN POST-READ CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkLimitedHingeConstraint::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::Write( out, link_map, missing_link_stack, info );
	if ( (info.userVersion2 <= 16) ) {
		NifStream( limitedHinge.pivotA, out, info );
		NifStream( limitedHinge.axleA, out, info );
		NifStream( limitedHinge.perp2AxleInA1, out, info );
		NifStream( limitedHinge.perp2AxleInA2, out, info );
		NifStream( limitedHinge.pivotB, out, info );
		NifStream( limitedHinge.axleB, out, info );
		NifStream( limitedHinge.perp2AxleInB2, out, info );
	};
	if ( (info.userVersion2 > 16) ) {
		NifStream( (Vector4&)limitedHinge.axleA, out, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInA1, out, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInA2, out, info );
		NifStream( (Vector4&)limitedHinge.pivotA, out, info );
		NifStream( (Vector4&)limitedHinge.axleB, out, info );
		NifStream( limitedHinge.perp2AxleInB1, out, info );
		NifStream( (Vector4&)limitedHinge.perp2AxleInB2, out, info );
		NifStream( (Vector4&)limitedHinge.pivotB, out, info );
	};
	NifStream( limitedHinge.minAngle, out, info );
	NifStream( limitedHinge.maxAngle, out, info );
	NifStream( limitedHinge.maxFriction, out, info );
	if ( ( info.version >= 0x14020007 ) && ( (info.userVersion2 > 16) ) ) {
		NifStream( limitedHinge.motor.type, out, info );
		if ( (limitedHinge.motor.type == 1) ) {
			NifStream( limitedHinge.motor.positionMotor.minForce, out, info );
			NifStream( limitedHinge.motor.positionMotor.maxForce, out, info );
			NifStream( limitedHinge.motor.positionMotor.tau, out, info );
			NifStream( limitedHinge.motor.positionMotor.damping, out, info );
			NifStream( limitedHinge.motor.positionMotor.proportionalRecoveryVelocity, out, info );
			NifStream( limitedHinge.motor.positionMotor.constantRecoveryVelocity, out, info );
			NifStream( limitedHinge.motor.positionMotor.motorEnabled, out, info );
		};
		if ( (limitedHinge.motor.type == 2) ) {
			NifStream( limitedHinge.motor.velocityMotor.minForce, out, info );
			NifStream( limitedHinge.motor.velocityMotor.maxForce, out, info );
			NifStream( limitedHinge.motor.velocityMotor.tau, out, info );
			NifStream( limitedHinge.motor.velocityMotor.targetVelocity, out, info );
			NifStream( limitedHinge.motor.velocityMotor.useVelocityTarget, out, info );
			NifStream( limitedHinge.motor.velocityMotor.motorEnabled, out, info );
		};
		if ( (limitedHinge.motor.type == 3) ) {
			NifStream( limitedHinge.motor.springDamperMotor.minForce, out, info );
			NifStream( limitedHinge.motor.springDamperMotor.maxForce, out, info );
			NifStream( limitedHinge.motor.springDamperMotor.springConstant, out, info );
			NifStream( limitedHinge.motor.springDamperMotor.springDamping, out, info );
			NifStream( limitedHinge.motor.springDamperMotor.motorEnabled, out, info );
		};
	};

	//--BEGIN POST-WRITE CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::string bhkLimitedHingeConstraint::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//

	stringstream out;
	out << bhkConstraint::asString();
	out << "  Pivot A:  " << limitedHinge.pivotA << endl;
	out << "  Axle A:  " << limitedHinge.axleA << endl;
	out << "  Perp2 Axle In A1:  " << limitedHinge.perp2AxleInA1 << endl;
	out << "  Perp2 Axle In A2:  " << limitedHinge.perp2AxleInA2 << endl;
	out << "  Pivot B:  " << limitedHinge.pivotB << endl;
	out << "  Axle B:  " << limitedHinge.axleB << endl;
	out << "  Perp2 Axle In B2:  " << limitedHinge.perp2AxleInB2 << endl;
	out << "  Perp2 Axle In B1:  " << limitedHinge.perp2AxleInB1 << endl;
	out << "  Min Angle:  " << limitedHinge.minAngle << endl;
	out << "  Max Angle:  " << limitedHinge.maxAngle << endl;
	out << "  Max Friction:  " << limitedHinge.maxFriction << endl;
	out << "  Type:  " << limitedHinge.motor.type << endl;
	if ( (limitedHinge.motor.type == 1) ) {
		out << "    Min Force:  " << limitedHinge.motor.positionMotor.minForce << endl;
		out << "    Max Force:  " << limitedHinge.motor.positionMotor.maxForce << endl;
		out << "    Tau:  " << limitedHinge.motor.positionMotor.tau << endl;
		out << "    Damping:  " << limitedHinge.motor.positionMotor.damping << endl;
		out << "    Proportional Recovery Velocity:  " << limitedHinge.motor.positionMotor.proportionalRecoveryVelocity << endl;
		out << "    Constant Recovery Velocity:  " << limitedHinge.motor.positionMotor.constantRecoveryVelocity << endl;
		out << "    Motor Enabled:  " << limitedHinge.motor.positionMotor.motorEnabled << endl;
	};
	if ( (limitedHinge.motor.type == 2) ) {
		out << "    Min Force:  " << limitedHinge.motor.velocityMotor.minForce << endl;
		out << "    Max Force:  " << limitedHinge.motor.velocityMotor.maxForce << endl;
		out << "    Tau:  " << limitedHinge.motor.velocityMotor.tau << endl;
		out << "    Target Velocity:  " << limitedHinge.motor.velocityMotor.targetVelocity << endl;
		out << "    Use Velocity Target:  " << limitedHinge.motor.velocityMotor.useVelocityTarget << endl;
		out << "    Motor Enabled:  " << limitedHinge.motor.velocityMotor.motorEnabled << endl;
	};
	if ( (limitedHinge.motor.type == 3) ) {
		out << "    Min Force:  " << limitedHinge.motor.springDamperMotor.minForce << endl;
		out << "    Max Force:  " << limitedHinge.motor.springDamperMotor.maxForce << endl;
		out << "    Spring Constant:  " << limitedHinge.motor.springDamperMotor.springConstant << endl;
		out << "    Spring Damping:  " << limitedHinge.motor.springDamperMotor.springDamping << endl;
		out << "    Motor Enabled:  " << limitedHinge.motor.springDamperMotor.motorEnabled << endl;
	};
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

void bhkLimitedHingeConstraint::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//

	bhkConstraint::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//
	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> bhkLimitedHingeConstraint::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = bhkConstraint::GetRefs();
	return refs;
}

std::list<NiObject *> bhkLimitedHingeConstraint::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = bhkConstraint::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
//--END CUSTOM CODE--//
