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
		// TYPE IfcFilterTypeEnum = ENUMERATION OF	(AIRPARTICLEFILTER	,COMPRESSEDAIRFILTER	,ODORFILTER	,OILFILTER	,STRAINER	,WATERFILTER	,USERDEFINED	,NOTDEFINED);
		class IfcFilterTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcFilterTypeEnumEnum
			{
				ENUM_AIRPARTICLEFILTER,
				ENUM_COMPRESSEDAIRFILTER,
				ENUM_ODORFILTER,
				ENUM_OILFILTER,
				ENUM_STRAINER,
				ENUM_WATERFILTER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcFilterTypeEnum();
			IfcFilterTypeEnum( IfcFilterTypeEnumEnum e ) { m_enum = e; }
			~IfcFilterTypeEnum();
			virtual const char* classname() const { return "IfcFilterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcFilterTypeEnum> readStepData( std::string& arg );
			IfcFilterTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

