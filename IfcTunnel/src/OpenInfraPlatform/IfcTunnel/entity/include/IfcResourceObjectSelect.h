/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/IfcTunnelObject.h"

// TYPE IfcResourceObjectSelect = SELECT	(IfcActorRole	,IfcAppliedValue	,IfcApproval	,IfcConstraint	,IfcContextDependentUnit	,IfcConversionBasedUnit	,IfcExternalInformation	,IfcExternalReference	,IfcMaterialDefinition	,IfcOrganization	,IfcPerson	,IfcPersonAndOrganization	,IfcPhysicalQuantity	,IfcProfileDef	,IfcPropertyAbstraction	,IfcTimeSeries);
namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcResourceObjectSelect : public IfcTunnelAbstractSelect
		{
		public:
			IfcResourceObjectSelect();
			~IfcResourceObjectSelect();
			virtual const char* classname() const { return "IfcResourceObjectSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcResourceObjectSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

