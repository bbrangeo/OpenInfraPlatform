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
		// TYPE IfcStructuralSurfaceActivityTypeEnum = ENUMERATION OF	(CONST	,BILINEAR	,DISCRETE	,ISOCONTOUR	,USERDEFINED	,NOTDEFINED);
		class IfcStructuralSurfaceActivityTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcStructuralSurfaceActivityTypeEnumEnum
			{
				ENUM_CONST,
				ENUM_BILINEAR,
				ENUM_DISCRETE,
				ENUM_ISOCONTOUR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcStructuralSurfaceActivityTypeEnum();
			IfcStructuralSurfaceActivityTypeEnum( IfcStructuralSurfaceActivityTypeEnumEnum e ) { m_enum = e; }
			~IfcStructuralSurfaceActivityTypeEnum();
			virtual const char* classname() const { return "IfcStructuralSurfaceActivityTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcStructuralSurfaceActivityTypeEnum> readStepData( std::string& arg );
			IfcStructuralSurfaceActivityTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

