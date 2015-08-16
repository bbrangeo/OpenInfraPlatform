/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcFontStyle = STRING;
		class IfcFontStyle : public IfcTunnelType
		{
		public:
			IfcFontStyle();
			IfcFontStyle( std::string value );
			~IfcFontStyle();
			virtual const char* classname() const { return "IfcFontStyle"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFontStyle> readStepData( std::string& arg );
			std::string m_value;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

