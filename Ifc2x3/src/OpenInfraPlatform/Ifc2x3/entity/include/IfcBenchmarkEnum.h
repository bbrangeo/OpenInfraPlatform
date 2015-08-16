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

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBenchmarkEnum = ENUMERATION OF	(GREATERTHAN	,GREATERTHANOREQUALTO	,LESSTHAN	,LESSTHANOREQUALTO	,EQUALTO	,NOTEQUALTO);
		class IfcBenchmarkEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcBenchmarkEnumEnum
			{
				ENUM_GREATERTHAN,
				ENUM_GREATERTHANOREQUALTO,
				ENUM_LESSTHAN,
				ENUM_LESSTHANOREQUALTO,
				ENUM_EQUALTO,
				ENUM_NOTEQUALTO
			};

			IfcBenchmarkEnum();
			IfcBenchmarkEnum( IfcBenchmarkEnumEnum e ) { m_enum = e; }
			~IfcBenchmarkEnum();
			virtual const char* classname() const { return "IfcBenchmarkEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBenchmarkEnum> readStepData( std::string& arg );
			IfcBenchmarkEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

