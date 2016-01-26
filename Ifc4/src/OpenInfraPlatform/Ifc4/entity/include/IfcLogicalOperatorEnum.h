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
		// TYPE IfcLogicalOperatorEnum = ENUMERATION OF	(LOGICALAND	,LOGICALOR	,LOGICALXOR	,LOGICALNOTAND	,LOGICALNOTOR);
		class IfcLogicalOperatorEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcLogicalOperatorEnumEnum
			{
				ENUM_LOGICALAND,
				ENUM_LOGICALOR,
				ENUM_LOGICALXOR,
				ENUM_LOGICALNOTAND,
				ENUM_LOGICALNOTOR
			};

			IfcLogicalOperatorEnum();
			IfcLogicalOperatorEnum( IfcLogicalOperatorEnumEnum e ) { m_enum = e; }
			~IfcLogicalOperatorEnum();
			virtual const char* classname() const { return "IfcLogicalOperatorEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLogicalOperatorEnum> readStepData( std::string& arg );
			IfcLogicalOperatorEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

