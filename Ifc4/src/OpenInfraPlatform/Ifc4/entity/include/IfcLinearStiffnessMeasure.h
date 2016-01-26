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
#include "IfcDerivedMeasureValue.h"
#include "IfcTranslationalStiffnessSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLinearStiffnessMeasure = REAL;
		class IfcLinearStiffnessMeasure : public IfcDerivedMeasureValue, public IfcTranslationalStiffnessSelect, public Ifc4Type
		{
		public:
			IfcLinearStiffnessMeasure();
			IfcLinearStiffnessMeasure( double value );
			~IfcLinearStiffnessMeasure();
			virtual const char* classname() const { return "IfcLinearStiffnessMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLinearStiffnessMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

