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
		// TYPE IfcGeographicElementTypeEnum = ENUMERATION OF	(TERRAIN	,USERDEFINED	,NOTDEFINED);
		class IfcGeographicElementTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcGeographicElementTypeEnumEnum
			{
				ENUM_TERRAIN,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcGeographicElementTypeEnum();
			IfcGeographicElementTypeEnum( IfcGeographicElementTypeEnumEnum e ) { m_enum = e; }
			~IfcGeographicElementTypeEnum();
			virtual const char* classname() const { return "IfcGeographicElementTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcGeographicElementTypeEnum> readStepData( std::string& arg );
			IfcGeographicElementTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

