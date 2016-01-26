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
		// TYPE IfcTunnelSpaceEnum = ENUMERATION OF	(FULLTUNNELSPACE	,INTERIORSPACE	,ANNULARGAPSPACE	,LININGSPACE	,CLEARANCESPACE	,SERVICESPACE	,FLOORSPACE	,TRACKSPACE,RING	,USERDEFINED	,NOTDEFINED);
		class IfcTunnelSpaceEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcTunnelSpaceEnumEnum
			{
				ENUM_FULLTUNNELSPACE,
				ENUM_INTERIORSPACE,
				ENUM_ANNULARGAPSPACE,
				ENUM_LININGSPACE,
				ENUM_CLEARANCESPACE,
				ENUM_SERVICESPACE,
				ENUM_FLOORSPACE,
				ENUM_TRACKSPACE,
				ENUM_RING,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTunnelSpaceEnum();
			IfcTunnelSpaceEnum( IfcTunnelSpaceEnumEnum e ) { m_enum = e; }
			~IfcTunnelSpaceEnum();
			virtual const char* classname() const { return "IfcTunnelSpaceEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTunnelSpaceEnum> readStepData( std::string& arg );
			IfcTunnelSpaceEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

