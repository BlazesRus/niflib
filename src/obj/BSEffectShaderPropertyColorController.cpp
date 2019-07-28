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
#include "../../include/obj/BSEffectShaderPropertyColorController.h"
using namespace Niflib;

//Definition of TYPE constant
const Type BSEffectShaderPropertyColorController::TYPE("BSEffectShaderPropertyColorController", &NiPoint3InterpController::TYPE );

BSEffectShaderPropertyColorController::BSEffectShaderPropertyColorController() : typeOfControlledColor((EffectShaderControlledColor)0) {
	//--BEGIN CONSTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

BSEffectShaderPropertyColorController::~BSEffectShaderPropertyColorController() {
	//--BEGIN DESTRUCTOR CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

const Type & BSEffectShaderPropertyColorController::GetType() const {
	return TYPE;
}

NiObject * BSEffectShaderPropertyColorController::Create() {
	return new BSEffectShaderPropertyColorController;
}

void BSEffectShaderPropertyColorController::Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info ) {
	//--BEGIN PRE-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPoint3InterpController::Read( in, link_stack, info );
	NifStream( typeOfControlledColor, in, info );

	//--BEGIN POST-READ CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSEffectShaderPropertyColorController::Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, list<NiObject *> & missing_link_stack, const NifInfo & info ) const {
	//--BEGIN PRE-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPoint3InterpController::Write( out, link_map, missing_link_stack, info );
	NifStream( typeOfControlledColor, out, info );

	//--BEGIN POST-WRITE CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::string BSEffectShaderPropertyColorController::asString( bool verbose ) const {
	//--BEGIN PRE-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//

	stringstream out;
	out << NiPoint3InterpController::asString();
	out << "  Type of Controlled Color:  " << typeOfControlledColor << endl;
	return out.str();

	//--BEGIN POST-STRING CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

void BSEffectShaderPropertyColorController::FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, list<NiObjectRef> & missing_link_stack, const NifInfo & info ) {
	//--BEGIN PRE-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//

	NiPoint3InterpController::FixLinks( objects, link_stack, missing_link_stack, info );

	//--BEGIN POST-FIXLINKS CUSTOM CODE--//

	//--END CUSTOM CODE--//
}

std::list<NiObjectRef> BSEffectShaderPropertyColorController::GetRefs() const {
	list<Ref<NiObject> > refs;
	refs = NiPoint3InterpController::GetRefs();
	return refs;
}

std::list<NiObject *> BSEffectShaderPropertyColorController::GetPtrs() const {
	list<NiObject *> ptrs;
	ptrs = NiPoint3InterpController::GetPtrs();
	return ptrs;
}

//--BEGIN MISC CUSTOM CODE--//
EffectShaderControlledColor BSEffectShaderPropertyColorController::GetTargetColor() const {
	return typeOfControlledColor;
}

void BSEffectShaderPropertyColorController::SetTargetColor(EffectShaderControlledColor value) {
	typeOfControlledColor = value;
}

//--END CUSTOM CODE--//
