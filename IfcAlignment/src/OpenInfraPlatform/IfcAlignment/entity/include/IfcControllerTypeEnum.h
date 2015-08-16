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
		// TYPE IfcControllerTypeEnum = ENUMERATION OF	(FLOATING	,PROGRAMMABLE	,PROPORTIONAL	,MULTIPOSITION	,TWOPOSITION	,USERDEFINED	,NOTDEFINED);
		class IfcControllerTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcControllerTypeEnumEnum
			{
				ENUM_FLOATING,
				ENUM_PROGRAMMABLE,
				ENUM_PROPORTIONAL,
				ENUM_MULTIPOSITION,
				ENUM_TWOPOSITION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcControllerTypeEnum();
			IfcControllerTypeEnum( IfcControllerTypeEnumEnum e ) { m_enum = e; }
			~IfcControllerTypeEnum();
			virtual const char* classname() const { return "IfcControllerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcControllerTypeEnum> readStepData( std::string& arg );
			IfcControllerTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

