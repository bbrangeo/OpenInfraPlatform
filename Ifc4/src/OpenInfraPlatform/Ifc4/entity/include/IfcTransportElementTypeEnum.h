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
		// TYPE IfcTransportElementTypeEnum = ENUMERATION OF	(ELEVATOR	,ESCALATOR	,MOVINGWALKWAY	,CRANEWAY	,LIFTINGGEAR	,USERDEFINED	,NOTDEFINED);
		class IfcTransportElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
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
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

