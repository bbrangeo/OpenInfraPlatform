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
		// TYPE IfcProfileTypeEnum = ENUMERATION OF	(CURVE	,AREA);
		class IfcProfileTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcProfileTypeEnumEnum
			{
				ENUM_CURVE,
				ENUM_AREA
			};

			IfcProfileTypeEnum();
			IfcProfileTypeEnum( IfcProfileTypeEnumEnum e ) { m_enum = e; }
			~IfcProfileTypeEnum();
			virtual const char* classname() const { return "IfcProfileTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProfileTypeEnum> readStepData( std::string& arg );
			IfcProfileTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

