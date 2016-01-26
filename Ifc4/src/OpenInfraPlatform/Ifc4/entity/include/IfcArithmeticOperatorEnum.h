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
		// TYPE IfcArithmeticOperatorEnum = ENUMERATION OF	(ADD	,DIVIDE	,MULTIPLY	,SUBTRACT);
		class IfcArithmeticOperatorEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcArithmeticOperatorEnumEnum
			{
				ENUM_ADD,
				ENUM_DIVIDE,
				ENUM_MULTIPLY,
				ENUM_SUBTRACT
			};

			IfcArithmeticOperatorEnum();
			IfcArithmeticOperatorEnum( IfcArithmeticOperatorEnumEnum e ) { m_enum = e; }
			~IfcArithmeticOperatorEnum();
			virtual const char* classname() const { return "IfcArithmeticOperatorEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcArithmeticOperatorEnum> readStepData( std::string& arg );
			IfcArithmeticOperatorEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

