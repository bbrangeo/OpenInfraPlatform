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
#include "IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcLogical = LOGICAL;
		class IfcLogical : public IfcSimpleValue, public IfcBridgeType
		{
		public:
			IfcLogical();
			IfcLogical( bool value );
			~IfcLogical();
			virtual const char* classname() const { return "IfcLogical"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLogical> readStepData( std::string& arg );
			bool m_value;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

