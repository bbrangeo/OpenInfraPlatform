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
		// TYPE IfcProjectedOrTrueLengthEnum = ENUMERATION OF	(PROJECTED_LENGTH	,TRUE_LENGTH);
		class IfcProjectedOrTrueLengthEnum : public IfcTunnelAbstractEnum, public IfcTunnelType
		{
		public:
			enum IfcProjectedOrTrueLengthEnumEnum
			{
				ENUM_PROJECTED_LENGTH,
				ENUM_TRUE_LENGTH
			};

			IfcProjectedOrTrueLengthEnum();
			IfcProjectedOrTrueLengthEnum( IfcProjectedOrTrueLengthEnumEnum e ) { m_enum = e; }
			~IfcProjectedOrTrueLengthEnum();
			virtual const char* classname() const { return "IfcProjectedOrTrueLengthEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcProjectedOrTrueLengthEnum> readStepData( std::string& arg );
			IfcProjectedOrTrueLengthEnumEnum m_enum;
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

