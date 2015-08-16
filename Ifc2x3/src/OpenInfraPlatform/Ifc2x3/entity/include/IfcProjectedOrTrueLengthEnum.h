/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcProjectedOrTrueLengthEnum = ENUMERATION OF	(PROJECTED_LENGTH	,TRUE_LENGTH);
		class IfcProjectedOrTrueLengthEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
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
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

