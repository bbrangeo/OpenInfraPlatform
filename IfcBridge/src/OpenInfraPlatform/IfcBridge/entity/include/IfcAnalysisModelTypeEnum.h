/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcAnalysisModelTypeEnum = ENUMERATION OF	(IN_PLANE_LOADING_2D	,OUT_PLANE_LOADING_2D	,LOADING_3D	,USERDEFINED	,NOTDEFINED);
		class IfcAnalysisModelTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcAnalysisModelTypeEnumEnum
			{
				ENUM_IN_PLANE_LOADING_2D,
				ENUM_OUT_PLANE_LOADING_2D,
				ENUM_LOADING_3D,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcAnalysisModelTypeEnum();
			IfcAnalysisModelTypeEnum( IfcAnalysisModelTypeEnumEnum e ) { m_enum = e; }
			~IfcAnalysisModelTypeEnum();
			virtual const char* classname() const { return "IfcAnalysisModelTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcAnalysisModelTypeEnum> readStepData( std::string& arg );
			IfcAnalysisModelTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

