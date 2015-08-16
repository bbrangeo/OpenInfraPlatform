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
		// TYPE IfcDistributionChamberElementTypeEnum = ENUMERATION OF	(FORMEDDUCT	,INSPECTIONCHAMBER	,INSPECTIONPIT	,MANHOLE	,METERCHAMBER	,SUMP	,TRENCH	,VALVECHAMBER	,USERDEFINED	,NOTDEFINED);
		class IfcDistributionChamberElementTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcDistributionChamberElementTypeEnumEnum
			{
				ENUM_FORMEDDUCT,
				ENUM_INSPECTIONCHAMBER,
				ENUM_INSPECTIONPIT,
				ENUM_MANHOLE,
				ENUM_METERCHAMBER,
				ENUM_SUMP,
				ENUM_TRENCH,
				ENUM_VALVECHAMBER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDistributionChamberElementTypeEnum();
			IfcDistributionChamberElementTypeEnum( IfcDistributionChamberElementTypeEnumEnum e ) { m_enum = e; }
			~IfcDistributionChamberElementTypeEnum();
			virtual const char* classname() const { return "IfcDistributionChamberElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDistributionChamberElementTypeEnum> readStepData( std::string& arg );
			IfcDistributionChamberElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

