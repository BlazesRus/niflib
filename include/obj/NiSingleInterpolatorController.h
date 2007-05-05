/* Copyright (c) 2006, NIF File Format Library and Tools
All rights reserved.  Please see niflib.h for licence. */

#ifndef _NISINGLEINTERPOLATORCONTROLLER_H_
#define _NISINGLEINTERPOLATORCONTROLLER_H_

#include "NiTimeController.h"

// Include structures
#include "../Ref.h"
namespace Niflib {

// Forward define of referenced NIF objects
class NiInterpolator;

//#include "../gen/obj_defines.h"

class NiSingleInterpolatorController;
typedef Ref<NiSingleInterpolatorController> NiSingleInterpolatorControllerRef;

/*!
 * NiSingleInterpolatorController - A controller referring to an
 * interpolator.
 */

class NiSingleInterpolatorController : public NI_SINGLE_INTERPOLATOR_CONTROLLER_PARENT {
public:
	NIFLIB_API NiSingleInterpolatorController();
	NIFLIB_API ~NiSingleInterpolatorController();
	//Run-Time Type Information
	NIFLIB_API static const Type & TypeConst();
private:
	static const Type TYPE;
public:
	NIFLIB_API virtual const Type & GetType() const;
	NIFLIB_HIDDEN virtual void Read( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual void Write( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	NIFLIB_API virtual string asString( bool verbose = false ) const;
	NIFLIB_HIDDEN virtual void FixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	NIFLIB_HIDDEN virtual list<NiObjectRef> GetRefs() const;

	/*!
	 * Retrives the interpolator used by this controller.
	 * \return The interpolator.
	 */
	NIFLIB_API Ref<NiInterpolator > GetInterpolator() const;

	/*!
	 * Sets the interpolator used by this controller.
	 * \param[in] value The new interpolator.
	 */
	NIFLIB_API void SetInterpolator( NiInterpolator * value );

protected:
	NI_SINGLE_INTERPOLATOR_CONTROLLER_MEMBERS
private:
	void InternalRead( istream& in, list<unsigned int> & link_stack, const NifInfo & info );
	void InternalWrite( ostream& out, const map<NiObjectRef,unsigned int> & link_map, const NifInfo & info ) const;
	string InternalAsString( bool verbose ) const;
	void InternalFixLinks( const map<unsigned int,NiObjectRef> & objects, list<unsigned int> & link_stack, const NifInfo & info );
	list<NiObjectRef> InternalGetRefs() const;
};

}
#endif
