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
#include "IfcRotationalStiffnessSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcRotationalStiffnessMeasure = REAL;
		class IfcRotationalStiffnessMeasure : public IfcDerivedMeasureValue, public IfcRotationalStiffnessSelect, public IfcAlignmentP6Type
		{
		public:
			IfcRotationalStiffnessMeasure();
			IfcRotationalStiffnessMeasure( double value );
			~IfcRotationalStiffnessMeasure();
			virtual const char* classname() const { return "IfcRotationalStiffnessMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRotationalStiffnessMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

