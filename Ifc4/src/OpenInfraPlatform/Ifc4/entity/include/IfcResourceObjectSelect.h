/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

// TYPE IfcResourceObjectSelect = SELECT	(IfcActorRole	,IfcAppliedValue	,IfcApproval	,IfcConstraint	,IfcContextDependentUnit	,IfcConversionBasedUnit	,IfcExternalInformation	,IfcExternalReference	,IfcMaterialDefinition	,IfcOrganization	,IfcPerson	,IfcPersonAndOrganization	,IfcPhysicalQuantity	,IfcProfileDef	,IfcPropertyAbstraction	,IfcTimeSeries);
namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcResourceObjectSelect : public Ifc4AbstractSelect
		{
		public:
			IfcResourceObjectSelect();
			~IfcResourceObjectSelect();
			virtual const char* classname() const { return "IfcResourceObjectSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcResourceObjectSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map );
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

