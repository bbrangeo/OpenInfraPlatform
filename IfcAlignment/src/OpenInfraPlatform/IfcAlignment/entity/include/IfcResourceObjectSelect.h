/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

// TYPE IfcResourceObjectSelect = SELECT	(IfcActorRole	,IfcAppliedValue	,IfcApproval	,IfcConstraint	,IfcContextDependentUnit	,IfcConversionBasedUnit	,IfcExternalInformation	,IfcExternalReference	,IfcMaterialDefinition	,IfcOrganization	,IfcPerson	,IfcPersonAndOrganization	,IfcPhysicalQuantity	,IfcProfileDef	,IfcPropertyAbstraction	,IfcTimeSeries);
namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcResourceObjectSelect : public IfcAlignmentP6AbstractSelect
		{
		public:
			IfcResourceObjectSelect();
			~IfcResourceObjectSelect();
			virtual const char* classname() const { return "IfcResourceObjectSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcResourceObjectSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

