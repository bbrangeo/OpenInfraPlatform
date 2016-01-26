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
#include "IfcAppliedValueSelect.h"
#include "IfcMetricValueSelect.h"

// TYPE IfcValue = SELECT	(IfcDerivedMeasureValue	,IfcMeasureValue	,IfcSimpleValue);
namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcValue : public IfcAppliedValueSelect, public IfcMetricValueSelect
		{
		public:
			IfcValue();
			~IfcValue();
			virtual const char* classname() const { return "IfcValue"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const = 0; // abstract class
			static shared_ptr<IfcValue> readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map );
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

