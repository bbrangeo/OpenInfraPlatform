/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcDerivedMeasureValue.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcIntegerCountRateMeasure = INTEGER;
		class IfcIntegerCountRateMeasure : public IfcDerivedMeasureValue, public IfcAlignmentP6Type
		{
		public:
			IfcIntegerCountRateMeasure();
			IfcIntegerCountRateMeasure( int value );
			~IfcIntegerCountRateMeasure();
			virtual const char* classname() const { return "IfcIntegerCountRateMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcIntegerCountRateMeasure> readStepData( std::string& arg );
			int m_value;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

