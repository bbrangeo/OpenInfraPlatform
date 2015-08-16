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
		// TYPE IfcDocumentConfidentialityEnum = ENUMERATION OF	(PUBLIC	,RESTRICTED	,CONFIDENTIAL	,PERSONAL	,USERDEFINED	,NOTDEFINED);
		class IfcDocumentConfidentialityEnum : public IfcBridgeAbstractEnum, public IfcBridgeType
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
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

