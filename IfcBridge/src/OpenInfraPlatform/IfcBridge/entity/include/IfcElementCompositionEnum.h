/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcElementCompositionEnum = ENUMERATION OF	(COMPLEX	,ELEMENT	,PARTIAL);
		class IfcElementCompositionEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

