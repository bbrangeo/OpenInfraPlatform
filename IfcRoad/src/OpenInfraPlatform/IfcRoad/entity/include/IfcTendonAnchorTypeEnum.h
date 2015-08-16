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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcTendonAnchorTypeEnum = ENUMERATION OF	(COUPLER	,FIXED_END	,TENSIONING_END	,USERDEFINED	,NOTDEFINED);
		class IfcTendonAnchorTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcTendonAnchorTypeEnumEnum
			{
				ENUM_COUPLER,
				ENUM_FIXED_END,
				ENUM_TENSIONING_END,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTendonAnchorTypeEnum();
			IfcTendonAnchorTypeEnum( IfcTendonAnchorTypeEnumEnum e ) { m_enum = e; }
			~IfcTendonAnchorTypeEnum();
			virtual const char* classname() const { return "IfcTendonAnchorTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTendonAnchorTypeEnum> readStepData( std::string& arg );
			IfcTendonAnchorTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

