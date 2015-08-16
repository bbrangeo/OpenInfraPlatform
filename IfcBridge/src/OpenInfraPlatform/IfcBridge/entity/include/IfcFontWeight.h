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

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcFontWeight = STRING;
		class IfcFontWeight : public IfcBridgeType
		{
		public:
			IfcFontWeight();
			IfcFontWeight( std::string value );
			~IfcFontWeight();
			virtual const char* classname() const { return "IfcFontWeight"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFontWeight> readStepData( std::string& arg );
			std::string m_value;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

