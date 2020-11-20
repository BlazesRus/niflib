/* Copyright (c) 2005-2020, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _BHKRIGIDBODYCINFO550_660_H_
#define _BHKRIGIDBODYCINFO550_660_H_

#include "../NIF_IO.h"

// Include structures
#include "HavokFilter.h"
#include "hkQuaternion.h"
namespace Niflib {


struct bhkRigidBodyCInfo550_660 {
	/*! Default Constructor */
	NIFLIB_API bhkRigidBodyCInfo550_660();
	/*! Default Destructor */
	NIFLIB_API ~bhkRigidBodyCInfo550_660();
	/*! Copy Constructor */
	NIFLIB_API bhkRigidBodyCInfo550_660( const bhkRigidBodyCInfo550_660 & src );
	/*! Copy Operator */
	NIFLIB_API bhkRigidBodyCInfo550_660 & operator=( const bhkRigidBodyCInfo550_660 & src );
	Niflib::NifArray<4,byte > unused01;
	HavokFilter havokFilter;
	Niflib::NifArray<4,byte > unused02;
	hkResponseType collisionResponse;
	byte unused03;
	unsigned short processContactCallbackDelay;
	Niflib::NifArray<4,byte > unused04;
	/*!
	 * A vector that moves the body by the specified amount. Only enabled in
	 * bhkRigidBodyT objects.
	 */
	Vector4 translation;
	/*!
	 * The rotation Yaw/Pitch/Roll to apply to the body. Only enabled in bhkRigidBodyT
	 * objects.
	 */
	hkQuaternion rotation;
	/*! Linear velocity. */
	Vector4 linearVelocity;
	/*! Angular velocity. */
	Vector4 angularVelocity;
	/*!
	 * Defines how the mass is distributed among the body, i.e. how difficult it is to
	 * rotate around any given axis.
	 */
	InertiaMatrix inertiaTensor;
	/*! The body's center of mass. */
	Vector4 center;
	/*! The body's mass in kg. A mass of zero represents an immovable object. */
	float mass;
	/*!
	 * Reduces the movement of the body over time. A value of 0.1 will remove 10% of
	 * the linear velocity every second.
	 */
	float linearDamping;
	/*!
	 * Reduces the movement of the body over time. A value of 0.05 will remove 5% of
	 * the angular velocity every second.
	 */
	float angularDamping;
	/*! How smooth its surfaces is and how easily it will slide along other bodies. */
	float friction;
	/*!
	 * How "bouncy" the body is, i.e. how much energy it has after colliding. Less than
	 * 1.0 loses energy, greater than 1.0 gains energy.
	 *             If the restitution is not 0.0 the object will need extra CPU for all
	 * new collisions.
	 */
	float restitution;
	/*! Maximal linear velocity. */
	float maxLinearVelocity;
	/*! Maximal angular velocity. */
	float maxAngularVelocity;
	/*!
	 * The maximum allowed penetration for this object.
	 *             This is a hint to the engine to see how much CPU the engine should
	 * invest to keep this object from penetrating.
	 *             A good choice is 5% - 20% of the smallest diameter of the object.
	 */
	float penetrationDepth;
	/*! Motion system? Overrides Quality when on Keyframed? */
	hkMotionType motionSystem;
	/*! The initial deactivator type of the body. */
	hkDeactivatorType deactivatorType;
	/*!
	 * How aggressively the engine will try to zero the velocity for slow objects. This
	 * does not save CPU.
	 */
	hkSolverDeactivation solverDeactivation;
	/*! The type of interaction with other objects. */
	hkQualityType qualityType;
	Niflib::NifArray<12,byte > unused05;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
