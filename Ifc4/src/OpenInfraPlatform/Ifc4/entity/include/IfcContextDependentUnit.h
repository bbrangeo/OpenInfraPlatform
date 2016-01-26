/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcResourceObjectSelect.h"
#include "IfcNamedUnit.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcLabel;
		class IfcExternalReferenceRelationship;
		//ENTITY
		class IfcContextDependentUnit : public IfcResourceObjectSelect, public IfcNamedUnit
		{
		public:
			IfcContextDependentUnit();
			IfcContextDependentUnit( int id );
			~IfcContextDependentUnit();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcContextDependentUnit"; }


			// IfcNamedUnit -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcDimensionalExponents>						m_Dimensions;
			//  shared_ptr<IfcUnitEnum>									m_UnitType;

			// IfcContextDependentUnit -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>										m_Name;
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_HasExternalReference_inverse;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

