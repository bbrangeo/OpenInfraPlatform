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
		// TYPE IfcSectionTypeEnum = ENUMERATION OF	(UNIFORM	,TAPERED);
		class IfcSectionTypeEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcSectionTypeEnumEnum
			{
				ENUM_UNIFORM,
				ENUM_TAPERED
			};

			IfcSectionTypeEnum();
			IfcSectionTypeEnum( IfcSectionTypeEnumEnum e ) { m_enum = e; }
			~IfcSectionTypeEnum();
			virtual const char* classname() const { return "IfcSectionTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSectionTypeEnum> readStepData( std::string& arg );
			IfcSectionTypeEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

