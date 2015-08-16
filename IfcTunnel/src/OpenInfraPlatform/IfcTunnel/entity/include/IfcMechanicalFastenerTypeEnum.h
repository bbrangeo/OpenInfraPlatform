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
		// TYPE IfcMechanicalFastenerTypeEnum = ENUMERATION OF	(ANCHORBOLT	,BOLT	,DOWEL	,NAIL	,NAILPLATE	,RIVET	,SCREW	,SHEARCONNECTOR	,STAPLE	,STUDSHEARCONNECTOR	,USERDEFINED	,NOTDEFINED);
		class IfcMechanicalFastenerTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcMechanicalFastenerTypeEnumEnum
			{
				ENUM_ANCHORBOLT,
				ENUM_BOLT,
				ENUM_DOWEL,
				ENUM_NAIL,
				ENUM_NAILPLATE,
				ENUM_RIVET,
				ENUM_SCREW,
				ENUM_SHEARCONNECTOR,
				ENUM_STAPLE,
				ENUM_STUDSHEARCONNECTOR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcMechanicalFastenerTypeEnum();
			IfcMechanicalFastenerTypeEnum( IfcMechanicalFastenerTypeEnumEnum e ) { m_enum = e; }
			~IfcMechanicalFastenerTypeEnum();
			virtual const char* classname() const { return "IfcMechanicalFastenerTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcMechanicalFastenerTypeEnum> readStepData( std::string& arg );
			IfcMechanicalFastenerTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

