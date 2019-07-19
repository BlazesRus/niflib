/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//---THIS FILE WAS AUTOMATICALLY GENERATED.  DO NOT EDIT---//

// To change this file, alter the gen_niflib.py script.

#ifndef _CONTROLLEDBLOCK_H_
#define _CONTROLLEDBLOCK_H_

#include "../NIF_IO.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;
class NiTimeController;
class NiBlendInterpolator;
class NiStringPalette;

/*!
 * In a .kf file, this links to a controllable object, via its name (or for version
 * 10.2.0.0 and up, a link and offset to a NiStringPalette that contains the name),
 * and a sequence of interpolators that apply to this controllable object, via
 * links.
 *         For Controller ID, NiInterpController::GetCtlrID() virtual function
 * returns a string formatted specifically for the derived type.
 *         For Interpolator ID, NiInterpController::GetInterpolatorID() virtual
 * function returns a string formatted specifically for the derived type.
 *         The string formats are documented on the relevant niobject blocks.
 */
struct ControlledBlock {
	/*! Default Constructor */
	NIFLIB_API ControlledBlock();
	/*! Default Destructor */
	NIFLIB_API ~ControlledBlock();
	/*! Copy Constructor */
	NIFLIB_API ControlledBlock( const ControlledBlock & src );
	/*! Copy Operator */
	NIFLIB_API ControlledBlock & operator=( const ControlledBlock & src );
	/*! Name of a controllable object in another NIF file. */
	IndexString targetName;
	Ref<NiInterpolator > interpolator;
	Ref<NiTimeController > controller;
	Ref<NiBlendInterpolator > blendInterpolator;
	unsigned short blendIndex;
	/*!
	 * Idle animations tend to have low values for this, and high values tend to
	 * correspond with the important parts of the animations.
	 */
	byte priority;
	/*! The name of the animated NiAVObject. */
	IndexString nodeName;
	/*! The RTTI type of the NiProperty the controller is attached to, if applicable. */
	IndexString propertyType;
	/*! The RTTI type of the NiTimeController. */
	IndexString controllerType;
	/*!
	 * An ID that can uniquely identify the controller among others of the same type on
	 * the same NiObjectNET.
	 */
	IndexString controllerId;
	/*!
	 * An ID that can uniquely identify the interpolator among others of the same type
	 * on the same NiObjectNET.
	 */
	IndexString interpolatorId;
	/*!
	 * Refers to the NiStringPalette which contains the name of the controlled NIF
	 * object.
	 */
	Ref<NiStringPalette > stringPalette;
	/*! Offset in NiStringPalette to the name of the animated NiAVObject. */
	unsigned int nodeNameOffset;
	/*!
	 * Offset in NiStringPalette to the RTTI type of the NiProperty the controller is
	 * attached to, if applicable.
	 */
	unsigned int propertyTypeOffset;
	/*! Offset in NiStringPalette to the RTTI type of the NiTimeController. */
	unsigned int controllerTypeOffset;
	/*!
	 * Offset in NiStringPalette to an ID that can uniquely identify the controller
	 * among others of the same type on the same NiObjectNET.
	 */
	unsigned int controllerIdOffset;
	/*!
	 * Offset in NiStringPalette to an ID that can uniquely identify the interpolator
	 * among others of the same type on the same NiObjectNET.
	 */
	unsigned int interpolatorIdOffset;
	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
};

}
#endif
