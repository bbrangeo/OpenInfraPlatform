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
#include "IfcAppliedValueSelect.h"
#include "IfcMetricValueSelect.h"

// TYPE IfcValue = SELECT	(IfcDerivedMeasureValue	,IfcMeasureValue	,IfcSimpleValue);
namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcValue : public IfcAppliedValueSelect, public IfcMetricValueSelect
		{
		public:
			IfcValue();
			~IfcValue();
			virtual const char* classname() const { return "IfcValue"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcValue> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

