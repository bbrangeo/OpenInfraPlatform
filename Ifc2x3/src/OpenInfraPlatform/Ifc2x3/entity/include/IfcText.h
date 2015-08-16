/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"
#include "IfcMetricValueSelect.h"
#include "IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcText = STRING;
		class IfcText : public IfcMetricValueSelect, public IfcSimpleValue, public Ifc2x3Type
		{
		public:
			IfcText();
			IfcText( std::string value );
			~IfcText();
			virtual const char* classname() const { return "IfcText"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcText> readStepData( std::string& arg );
			std::string m_value;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

