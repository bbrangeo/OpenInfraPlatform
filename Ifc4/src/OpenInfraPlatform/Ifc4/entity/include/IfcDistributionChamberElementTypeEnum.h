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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcDistributionChamberElementTypeEnum = ENUMERATION OF	(FORMEDDUCT	,INSPECTIONCHAMBER	,INSPECTIONPIT	,MANHOLE	,METERCHAMBER	,SUMP	,TRENCH	,VALVECHAMBER	,USERDEFINED	,NOTDEFINED);
		class IfcDistributionChamberElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

