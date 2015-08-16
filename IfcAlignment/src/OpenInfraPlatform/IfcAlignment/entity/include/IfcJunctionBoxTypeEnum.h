/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcJunctionBoxTypeEnum = ENUMERATION OF	(DATA	,POWER	,USERDEFINED	,NOTDEFINED);
		class IfcJunctionBoxTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcJunctionBoxTypeEnumEnum
			{
				ENUM_DATA,
				ENUM_POWER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcJunctionBoxTypeEnum();
			IfcJunctionBoxTypeEnum( IfcJunctionBoxTypeEnumEnum e ) { m_enum = e; }
			~IfcJunctionBoxTypeEnum();
			virtual const char* classname() const { return "IfcJunctionBoxTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcJunctionBoxTypeEnum> readStepData( std::string& arg );
			IfcJunctionBoxTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

