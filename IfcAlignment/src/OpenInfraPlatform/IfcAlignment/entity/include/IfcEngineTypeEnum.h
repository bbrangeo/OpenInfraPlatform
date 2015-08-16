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
		// TYPE IfcEngineTypeEnum = ENUMERATION OF	(EXTERNALCOMBUSTION	,INTERNALCOMBUSTION	,USERDEFINED	,NOTDEFINED);
		class IfcEngineTypeEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcEngineTypeEnumEnum
			{
				ENUM_EXTERNALCOMBUSTION,
				ENUM_INTERNALCOMBUSTION,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcEngineTypeEnum();
			IfcEngineTypeEnum( IfcEngineTypeEnumEnum e ) { m_enum = e; }
			~IfcEngineTypeEnum();
			virtual const char* classname() const { return "IfcEngineTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcEngineTypeEnum> readStepData( std::string& arg );
			IfcEngineTypeEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

