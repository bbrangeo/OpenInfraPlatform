/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcLaborResourceTypeEnum = ENUMERATION OF	(ADMINISTRATION	,CARPENTRY	,CLEANING	,CONCRETE	,DRYWALL	,ELECTRIC	,FINISHING	,FLOORING	,GENERAL	,HVAC	,LANDSCAPING	,MASONRY	,PAINTING	,PAVING	,PLUMBING	,ROOFING	,SITEGRADING	,STEELWORK	,SURVEYING	,USERDEFINED	,NOTDEFINED);
		class IfcLaborResourceTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcLaborResourceTypeEnumEnum
			{
				ENUM_ADMINISTRATION,
				ENUM_CARPENTRY,
				ENUM_CLEANING,
				ENUM_CONCRETE,
				ENUM_DRYWALL,
				ENUM_ELECTRIC,
				ENUM_FINISHING,
				ENUM_FLOORING,
				ENUM_GENERAL,
				ENUM_HVAC,
				ENUM_LANDSCAPING,
				ENUM_MASONRY,
				ENUM_PAINTING,
				ENUM_PAVING,
				ENUM_PLUMBING,
				ENUM_ROOFING,
				ENUM_SITEGRADING,
				ENUM_STEELWORK,
				ENUM_SURVEYING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcLaborResourceTypeEnum();
			IfcLaborResourceTypeEnum( IfcLaborResourceTypeEnumEnum e ) { m_enum = e; }
			~IfcLaborResourceTypeEnum();
			virtual const char* classname() const { return "IfcLaborResourceTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLaborResourceTypeEnum> readStepData( std::string& arg );
			IfcLaborResourceTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

