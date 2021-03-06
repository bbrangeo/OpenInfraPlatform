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
		// TYPE IfcTransportElementTypeEnum = ENUMERATION OF	(ELEVATOR	,ESCALATOR	,MOVINGWALKWAY	,CRANEWAY	,LIFTINGGEAR	,USERDEFINED	,NOTDEFINED);
		class IfcTransportElementTypeEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcTransportElementTypeEnumEnum
			{
				ENUM_ELEVATOR,
				ENUM_ESCALATOR,
				ENUM_MOVINGWALKWAY,
				ENUM_CRANEWAY,
				ENUM_LIFTINGGEAR,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcTransportElementTypeEnum();
			IfcTransportElementTypeEnum( IfcTransportElementTypeEnumEnum e ) { m_enum = e; }
			~IfcTransportElementTypeEnum();
			virtual const char* classname() const { return "IfcTransportElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcTransportElementTypeEnum> readStepData( std::string& arg );
			IfcTransportElementTypeEnumEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

