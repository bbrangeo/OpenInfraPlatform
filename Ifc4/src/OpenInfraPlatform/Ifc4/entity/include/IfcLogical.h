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
#include "IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcLogical = LOGICAL;
		class IfcLogical : public IfcSimpleValue, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

