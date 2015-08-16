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
		// TYPE IfcVoidingFeatureTypeEnum = ENUMERATION OF	(CUTOUT	,NOTCH	,HOLE	,MITER	,CHAMFER	,EDGE	,USERDEFINED	,NOTDEFINED);
		class IfcVoidingFeatureTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcVoidingFeatureTypeEnumEnum
			{
				ENUM_CUTOUT,
				ENUM_NOTCH,
				ENUM_HOLE,
				ENUM_MITER,
				ENUM_CHAMFER,
				ENUM_EDGE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcVoidingFeatureTypeEnum();
			IfcVoidingFeatureTypeEnum( IfcVoidingFeatureTypeEnumEnum e ) { m_enum = e; }
			~IfcVoidingFeatureTypeEnum();
			virtual const char* classname() const { return "IfcVoidingFeatureTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcVoidingFeatureTypeEnum> readStepData( std::string& arg );
			IfcVoidingFeatureTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

