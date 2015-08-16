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
		// TYPE IfcPermeableCoveringOperationEnum = ENUMERATION OF	(GRILL	,LOUVER	,SCREEN	,USERDEFINED	,NOTDEFINED);
		class IfcPermeableCoveringOperationEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcPermeableCoveringOperationEnumEnum
			{
				ENUM_GRILL,
				ENUM_LOUVER,
				ENUM_SCREEN,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcPermeableCoveringOperationEnum();
			IfcPermeableCoveringOperationEnum( IfcPermeableCoveringOperationEnumEnum e ) { m_enum = e; }
			~IfcPermeableCoveringOperationEnum();
			virtual const char* classname() const { return "IfcPermeableCoveringOperationEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcPermeableCoveringOperationEnum> readStepData( std::string& arg );
			IfcPermeableCoveringOperationEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

