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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcRadioActivityMeasure = REAL;
		class IfcRadioActivityMeasure : public IfcDerivedMeasureValue, public Ifc4Type
		{
		public:
			IfcRadioActivityMeasure();
			IfcRadioActivityMeasure( double value );
			~IfcRadioActivityMeasure();
			virtual const char* classname() const { return "IfcRadioActivityMeasure"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRadioActivityMeasure> readStepData( std::string& arg );
			double m_value;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

