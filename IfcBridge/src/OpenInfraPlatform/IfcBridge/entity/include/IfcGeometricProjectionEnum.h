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
		// TYPE IfcGeometricProjectionEnum = ENUMERATION OF	(GRAPH_VIEW	,SKETCH_VIEW	,MODEL_VIEW	,PLAN_VIEW	,REFLECTED_PLAN_VIEW	,SECTION_VIEW	,ELEVATION_VIEW	,USERDEFINED	,NOTDEFINED);
		class IfcGeometricProjectionEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcGeometricProjectionEnumEnum
			{
				ENUM_GRAPH_VIEW,
				ENUM_SKETCH_VIEW,
				ENUM_MODEL_VIEW,
				ENUM_PLAN_VIEW,
				ENUM_REFLECTED_PLAN_VIEW,
				ENUM_SECTION_VIEW,
				ENUM_ELEVATION_VIEW,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcGeometricProjectionEnum();
			IfcGeometricProjectionEnum( IfcGeometricProjectionEnumEnum e ) { m_enum = e; }
			~IfcGeometricProjectionEnum();
			virtual const char* classname() const { return "IfcGeometricProjectionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGeometricProjectionEnum> readStepData( std::string& arg );
			IfcGeometricProjectionEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

