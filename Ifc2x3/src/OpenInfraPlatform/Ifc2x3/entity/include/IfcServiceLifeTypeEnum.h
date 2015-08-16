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
		// TYPE IfcServiceLifeTypeEnum = ENUMERATION OF	(ACTUALSERVICELIFE	,EXPECTEDSERVICELIFE	,OPTIMISTICREFERENCESERVICELIFE	,PESSIMISTICREFERENCESERVICELIFE	,REFERENCESERVICELIFE);
		class IfcServiceLifeTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcServiceLifeTypeEnumEnum
			{
				ENUM_ACTUALSERVICELIFE,
				ENUM_EXPECTEDSERVICELIFE,
				ENUM_OPTIMISTICREFERENCESERVICELIFE,
				ENUM_PESSIMISTICREFERENCESERVICELIFE,
				ENUM_REFERENCESERVICELIFE
			};

			IfcServiceLifeTypeEnum();
			IfcServiceLifeTypeEnum( IfcServiceLifeTypeEnumEnum e ) { m_enum = e; }
			~IfcServiceLifeTypeEnum();
			virtual const char* classname() const { return "IfcServiceLifeTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcServiceLifeTypeEnum> readStepData( std::string& arg );
			IfcServiceLifeTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

