/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once

#include <iostream>
#include <sstream>
#include <map>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"

// TYPE IfcMetricValueSelect = SELECT	(IfcCostValue	,IfcMeasureWithUnit	,IfcTable	,IfcTimeSeries	,IfcValue);
namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcMetricValueSelect : public IfcBridgeAbstractSelect
		{
		public:
			IfcMetricValueSelect();
			~IfcMetricValueSelect();
			virtual const char* classname() const { return "IfcMetricValueSelect"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcMetricValueSelect> readStepData( std::string& arg, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

