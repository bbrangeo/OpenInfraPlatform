/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/IfcBridgeObject.h"
#include "IfcAppliedValueSelect.h"
#include "IfcMeasureValue.h"
#include "IfcSizeSelect.h"
#include "IfcTimeOrRatioSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcRatioMeasure = REAL;
		class IfcRatioMeasure : public IfcAppliedValueSelect, public IfcMeasureValue, public IfcSizeSelect, public IfcTimeOrRatioSelect, public IfcBridgeType
		{
		public:
			IfcRatioMeasure();
			IfcRatioMeasure( double value );
			~IfcRatioMeasure();
			virtual const char* classname() const { return "IfcRatioMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRatioMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

