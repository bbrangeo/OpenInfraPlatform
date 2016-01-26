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
		// TYPE IfcElementCompositionEnum = ENUMERATION OF	(COMPLEX	,ELEMENT	,PARTIAL);
		class IfcElementCompositionEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcElementCompositionEnumEnum
			{
				ENUM_COMPLEX,
				ENUM_ELEMENT,
				ENUM_PARTIAL
			};

			IfcElementCompositionEnum();
			IfcElementCompositionEnum( IfcElementCompositionEnumEnum e ) { m_enum = e; }
			~IfcElementCompositionEnum();
			virtual const char* classname() const { return "IfcElementCompositionEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElementCompositionEnum> readStepData( std::string& arg );
			IfcElementCompositionEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

