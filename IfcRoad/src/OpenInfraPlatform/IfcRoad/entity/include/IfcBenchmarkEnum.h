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

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcBenchmarkEnum = ENUMERATION OF	(GREATERTHAN	,GREATERTHANOREQUALTO	,LESSTHAN	,LESSTHANOREQUALTO	,EQUALTO	,NOTEQUALTO	,INCLUDES	,NOTINCLUDES	,INCLUDEDIN	,NOTINCLUDEDIN);
		class IfcBenchmarkEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcBenchmarkEnumEnum
			{
				ENUM_GREATERTHAN,
				ENUM_GREATERTHANOREQUALTO,
				ENUM_LESSTHAN,
				ENUM_LESSTHANOREQUALTO,
				ENUM_EQUALTO,
				ENUM_NOTEQUALTO,
				ENUM_INCLUDES,
				ENUM_NOTINCLUDES,
				ENUM_INCLUDEDIN,
				ENUM_NOTINCLUDEDIN
			};

			IfcBenchmarkEnum();
			IfcBenchmarkEnum( IfcBenchmarkEnumEnum e ) { m_enum = e; }
			~IfcBenchmarkEnum();
			virtual const char* classname() const { return "IfcBenchmarkEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBenchmarkEnum> readStepData( std::string& arg );
			IfcBenchmarkEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

