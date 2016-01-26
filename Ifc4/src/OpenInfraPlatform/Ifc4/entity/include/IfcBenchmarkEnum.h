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

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBenchmarkEnum = ENUMERATION OF	(GREATERTHAN	,GREATERTHANOREQUALTO	,LESSTHAN	,LESSTHANOREQUALTO	,EQUALTO	,NOTEQUALTO	,INCLUDES	,NOTINCLUDES	,INCLUDEDIN	,NOTINCLUDEDIN);
		class IfcBenchmarkEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

