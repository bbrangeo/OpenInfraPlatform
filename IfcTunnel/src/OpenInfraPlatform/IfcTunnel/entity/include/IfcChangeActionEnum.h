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
		// TYPE IfcChangeActionEnum = ENUMERATION OF	(NOCHANGE	,MODIFIED	,ADDED	,DELETED	,NOTDEFINED);
		class IfcChangeActionEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcChangeActionEnumEnum
			{
				ENUM_NOCHANGE,
				ENUM_MODIFIED,
				ENUM_ADDED,
				ENUM_DELETED,
				ENUM_NOTDEFINED
			};

			IfcChangeActionEnum();
			IfcChangeActionEnum( IfcChangeActionEnumEnum e ) { m_enum = e; }
			~IfcChangeActionEnum();
			virtual const char* classname() const { return "IfcChangeActionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcChangeActionEnum> readStepData( std::string& arg );
			IfcChangeActionEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

