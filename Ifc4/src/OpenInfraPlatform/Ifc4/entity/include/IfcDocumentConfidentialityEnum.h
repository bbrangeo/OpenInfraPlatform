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
		// TYPE IfcDocumentConfidentialityEnum = ENUMERATION OF	(PUBLIC	,RESTRICTED	,CONFIDENTIAL	,PERSONAL	,USERDEFINED	,NOTDEFINED);
		class IfcDocumentConfidentialityEnum : public Ifc4AbstractEnum, public Ifc4Type
		{
		public:
			enum IfcDocumentConfidentialityEnumEnum
			{
				ENUM_PUBLIC,
				ENUM_RESTRICTED,
				ENUM_CONFIDENTIAL,
				ENUM_PERSONAL,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcDocumentConfidentialityEnum();
			IfcDocumentConfidentialityEnum( IfcDocumentConfidentialityEnumEnum e ) { m_enum = e; }
			~IfcDocumentConfidentialityEnum();
			virtual const char* classname() const { return "IfcDocumentConfidentialityEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDocumentConfidentialityEnum> readStepData( std::string& arg );
			IfcDocumentConfidentialityEnumEnum m_enum;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

