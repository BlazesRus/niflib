/* Copyright (c) 2019, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for license. */

//-----------------------------------NOTICE----------------------------------//
// Some of this file is automatically filled in by a Python script.  Only    //
// add custom code in the designated areas or it will be overwritten during  //
// the next update.                                                          //
//-----------------------------------NOTICE----------------------------------//

#ifndef _BSPROCEDURALLIGHTNINGCONTROLLER_H_
#define _BSPROCEDURALLIGHTNINGCONTROLLER_H_

//--BEGIN FILE HEAD CUSTOM CODE--//

//--END CUSTOM CODE--//

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;
class BSShaderProperty;
class BSProceduralLightningController;
typedef Ref<BSProceduralLightningController> BSProceduralLightningControllerRef;

/*!
 * Skyrim, Paired with dummy TriShapes, this controller generates lightning shapes
 * for special effects.
 *     First interpolator controls Generation.
 */
class BSProceduralLightningController : public NiTimeController {
public:
	/*! Constructor */
	NIFLIB_API BSProceduralLightningController();
	
	/*! Destructor */
	NIFLIB_API virtual ~BSProceduralLightningController();
	
	/*!
	 * A constant value which uniquly identifies objects of this type.
	 */
	NIFLIB_API static const Type TYPE;
	
	/*!
	 * A factory function used during file reading to create an instance of this type of object.
	 * \return A pointer to a newly allocated instance of this type of object.
	 */
	NIFLIB_API static NiObject * Create();
	
	/*!
	 * Summarizes the information contained in this object in English.
	 * \param[in] verbose Determines whether or not detailed information about large areas of data will be printed out.
	 * \return A string containing a summary of the information within the object in English.  This is the function that Niflyze calls to generate its analysis, so the output is the same.
	 */
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	
	/*!
	 * Used to determine the type of a particular instance of this object.
	 * \return The type constant for the actual type of the object.
	 */
	NIFLIB_API virtual const Type & GetType() const;

	//--BEGIN MISC CUSTOM CODE--//

	//--END CUSTOM CODE--//
protected:
	/*! References generation interpolator. */
	Ref<NiInterpolator > interpolator1_Generation;
	/*! References interpolator for Mutation of strips */
	Ref<NiInterpolator > interpolator2_Mutation;
	/*! References subdivision interpolator. */
	Ref<NiInterpolator > interpolator3_Subdivision;
	/*! References branches interpolator. */
	Ref<NiInterpolator > interpolator4_NumBranches;
	/*! References branches variation interpolator. */
	Ref<NiInterpolator > interpolator5_NumBranchesVar;
	/*! References length interpolator. */
	Ref<NiInterpolator > interpolator6_Length;
	/*! References length variation interpolator. */
	Ref<NiInterpolator > interpolator7_LengthVar;
	/*! References width interpolator. */
	Ref<NiInterpolator > interpolator8_Width;
	/*! References interpolator for amplitude control. 0=straight, 50=wide */
	Ref<NiInterpolator > interpolator9_ArcOffset;
	unsigned short subdivisions;
	unsigned short numBranches;
	unsigned short numBranchesVariation;
	/*! How far lightning will stretch to. */
	float length;
	/*! How far lightning variation will stretch to. */
	float lengthVariation;
	/*! How wide the bolt will be. */
	float width;
	/*! Influences forking behavior with a multiplier. */
	float childWidthMult;
	float arcOffset;
	bool fadeMainBolt;
	bool fadeChildBolts;
	bool animateArcOffset;
	/*! Reference to a shader property. */
	Ref<BSShaderProperty > shaderProperty;
public:
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info );
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;
	/*! NIFLIB_HIDDEN function.  For internal use only. */
	NIFLIB_HIDDEN virtual list<NiObject *> GetPtrs() const;
};

//--BEGIN FILE FOOT CUSTOM CODE--//

//--END CUSTOM CODE--//

}
#endif
