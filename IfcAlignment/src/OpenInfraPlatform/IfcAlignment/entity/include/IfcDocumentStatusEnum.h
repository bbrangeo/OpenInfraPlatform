/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcDocumentStatusEnum = ENUMERATION OF	(DRAFT	,FINALDRAFT	,FINAL	,REVISION	,NOTDEFINED);
		class IfcDocumentStatusEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcDocumentStatusEnumEnum
			{
				ENUM_DRAFT,
				ENUM_FINALDRAFT,
				ENUM_FINAL,
				ENUM_REVISION,
				ENUM_NOTDEFINED
			};

			IfcDocumentStatusEnum();
			IfcDocumentStatusEnum( IfcDocumentStatusEnumEnum e ) { m_enum = e; }
			~IfcDocumentStatusEnum();
			virtual const char* classname() const { return "IfcDocumentStatusEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcDocumentStatusEnum> readStepData( std::string& arg );
			IfcDocumentStatusEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

