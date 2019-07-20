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
#include "../../include/obj/BSProceduralLightningController.h"
#include "../../include/obj/BSShaderProperty.h"
#include "../../include/obj/NiInterpolator.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSProceduralLightningController::TYPE("BSProceduralLightningController", &NiTimeController::TYPE );

BSProceduralLightningController::BSProceduralLightningController() : interpolator1_Generation(NULL), interpolator2_Mutation(NULL), interpolator3_Subdivision(NULL), interpolator4_NumBranches(NULL), interpolator5_NumBranchesVar(NULL), interpolator6_Length(NULL), interpolator7_LengthVar(NULL), interpolator8_Width(NULL), interpolator9_ArcOffset(NULL), subdivisions((unsigned short)0), numBranches((unsigned short)0), numBranchesVariation((unsigned short)0), length(0.0f), lengthVariation(0.0f), width(0.0f), childWidthMult(0.0f), arcOffset(0.0f), fadeMainBolt(false), fadeChildBolts(false), animateArcOffset(false), shaderProperty(NULL) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSProceduralLightningController::~BSProceduralLightningController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSProceduralLightningController::GetType() const {
	return TYPE;
}

NiObject * BSProceduralLightningController::Create() {
	return new BSProceduralLightningController;
}

void BSProceduralLightningController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	unsigned int block_num;
	NiTimeController::Read( in, link_stack, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );
	NifStream( subdivisions, in, info );
	NifStream( numBranches, in, info );
	NifStream( numBranchesVariation, in, info );
	NifStream( length, in, info );
	NifStream( lengthVariation, in, info );
	NifStream( width, in, info );
	NifStream( childWidthMult, in, info );
	NifStream( arcOffset, in, info );
	NifStream( fadeMainBolt, in, info );
	NifStream( fadeChildBolts, in, info );
	NifStream( animateArcOffset, in, info );
	NifStream( block_num, in, info );
	link_stack.push_back( block_num );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSProceduralLightningController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::Write( out, link_map, missing_link_stack, info );
	WriteRef( StaticCast<NiObject>(interpolator1_Generation), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator2_Mutation), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator3_Subdivision), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator4_NumBranches), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator5_NumBranchesVar), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator6_Length), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator7_LengthVar), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator8_Width), out, info, link_map, missing_link_stack );
	WriteRef( StaticCast<NiObject>(interpolator9_ArcOffset), out, info, link_map, missing_link_stack );
	NifStream( subdivisions, out, info );
	NifStream( numBranches, out, info );
	NifStream( numBranchesVariation, out, info );
	NifStream( length, out, info );
	NifStream( lengthVariation, out, info );
	NifStream( width, out, info );
	NifStream( childWidthMult, out, info );
	NifStream( arcOffset, out, info );
	NifStream( fadeMainBolt, out, info );
	NifStream( fadeChildBolts, out, info );
	NifStream( animateArcOffset, out, info );
	WriteRef( StaticCast<NiObject>(shaderProperty), out, info, link_map, missing_link_stack );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSProceduralLightningController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiTimeController::asString();
	out << "  Interpolator 1: Generation:  " << interpolator1_Generation << endl;
	out << "  Interpolator 2: Mutation:  " << interpolator2_Mutation << endl;
	out << "  Interpolator 3: Subdivision:  " << interpolator3_Subdivision << endl;
	out << "  Interpolator 4: Num Branches:  " << interpolator4_NumBranches << endl;
	out << "  Interpolator 5: Num Branches Var:  " << interpolator5_NumBranchesVar << endl;
	out << "  Interpolator 6: Length:  " << interpolator6_Length << endl;
	out << "  Interpolator 7: Length Var:  " << interpolator7_LengthVar << endl;
	out << "  Interpolator 8: Width:  " << interpolator8_Width << endl;
	out << "  Interpolator 9: Arc Offset:  " << interpolator9_ArcOffset << endl;
	out << "  Subdivisions:  " << subdivisions << endl;
	out << "  Num Branches:  " << numBranches << endl;
	out << "  Num Branches Variation:  " << numBranchesVariation << endl;
	out << "  Length:  " << length << endl;
	out << "  Length Variation:  " << lengthVariation << endl;
	out << "  Width:  " << width << endl;
	out << "  Child Width Mult:  " << childWidthMult << endl;
	out << "  Arc Offset:  " << arcOffset << endl;
	out << "  Fade Main Bolt:  " << fadeMainBolt << endl;
	out << "  Fade Child Bolts:  " << fadeChildBolts << endl;
	out << "  Animate Arc Offset:  " << animateArcOffset << endl;
	out << "  Shader Property:  " << shaderProperty << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSProceduralLightningController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiTimeController::FixLinks( objects, link_stack, missing_link_stack, info );
	interpolator1_Generation = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator2_Mutation = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator3_Subdivision = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator4_NumBranches = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator5_NumBranchesVar = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator6_Length = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator7_LengthVar = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator8_Width = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	interpolator9_ArcOffset = FixLink<NiInterpolator>( objects, link_stack, missing_link_stack, info );
	shaderProperty = FixLink<BSShaderProperty>( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSProceduralLightningController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiTimeController::GetRefs();
	if ( interpolator1_Generation != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator1_Generation));
	if ( interpolator2_Mutation != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator2_Mutation));
	if ( interpolator3_Subdivision != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator3_Subdivision));
	if ( interpolator4_NumBranches != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator4_NumBranches));
	if ( interpolator5_NumBranchesVar != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator5_NumBranchesVar));
	if ( interpolator6_Length != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator6_Length));
	if ( interpolator7_LengthVar != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator7_LengthVar));
	if ( interpolator8_Width != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator8_Width));
	if ( interpolator9_ArcOffset != NULL )
		refs.push_back(StaticCast<NiObject>(interpolator9_ArcOffset));
	if ( shaderProperty != NULL )
		refs.push_back(StaticCast<NiObject>(shaderProperty));
	return refs;
}

std::list<NiObject *> BSProceduralLightningController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiTimeController::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//

//--END CUSTOM CODE--//
