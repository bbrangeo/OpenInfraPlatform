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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcPresentationStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcNullStyle = ENUMERATION OF	(NULL);
		class IfcNullStyle : public IfcPresentationStyleSelect, public IfcRoadType
		{
		public:
			enum IfcNullStyleEnum
			{
				ENUM_ENUM_NULL
			};

			IfcNullStyle();
			IfcNullStyle( IfcNullStyleEnum e ) { m_enum = e; }
			~IfcNullStyle();
			virtual const char* classname() const { return "IfcNullStyle"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcNullStyle> readStepData( std::string& arg );
			IfcNullStyleEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

