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
		// TYPE IfcCableCarrierFittingTypeEnum = ENUMERATION OF	(BEND	,CROSS	,REDUCER	,TEE	,USERDEFINED	,NOTDEFINED);
		class IfcCableCarrierFittingTypeEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcCableCarrierFittingTypeEnumEnum
			{
				ENUM_BEND,
				ENUM_CROSS,
				ENUM_REDUCER,
				ENUM_TEE,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcCableCarrierFittingTypeEnum();
			IfcCableCarrierFittingTypeEnum( IfcCableCarrierFittingTypeEnumEnum e ) { m_enum = e; }
			~IfcCableCarrierFittingTypeEnum();
			virtual const char* classname() const { return "IfcCableCarrierFittingTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcCableCarrierFittingTypeEnum> readStepData( std::string& arg );
			IfcCableCarrierFittingTypeEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

