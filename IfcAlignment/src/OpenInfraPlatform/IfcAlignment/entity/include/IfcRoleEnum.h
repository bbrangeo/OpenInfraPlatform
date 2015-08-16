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
		// TYPE IfcRoleEnum = ENUMERATION OF	(SUPPLIER	,MANUFACTURER	,CONTRACTOR	,SUBCONTRACTOR	,ARCHITECT	,STRUCTURALENGINEER	,COSTENGINEER	,CLIENT	,BUILDINGOWNER	,BUILDINGOPERATOR	,MECHANICALENGINEER	,ELECTRICALENGINEER	,PROJECTMANAGER	,FACILITIESMANAGER	,CIVILENGINEER	,COMMISSIONINGENGINEER	,ENGINEER	,OWNER	,CONSULTANT	,CONSTRUCTIONMANAGER	,FIELDCONSTRUCTIONMANAGER	,RESELLER	,USERDEFINED);
		class IfcRoleEnum : public IfcAlignmentP6AbstractEnum, public IfcAlignmentP6Type
		{
		public:
			enum IfcRoleEnumEnum
			{
				ENUM_SUPPLIER,
				ENUM_MANUFACTURER,
				ENUM_CONTRACTOR,
				ENUM_SUBCONTRACTOR,
				ENUM_ARCHITECT,
				ENUM_STRUCTURALENGINEER,
				ENUM_COSTENGINEER,
				ENUM_CLIENT,
				ENUM_BUILDINGOWNER,
				ENUM_BUILDINGOPERATOR,
				ENUM_MECHANICALENGINEER,
				ENUM_ELECTRICALENGINEER,
				ENUM_PROJECTMANAGER,
				ENUM_FACILITIESMANAGER,
				ENUM_CIVILENGINEER,
				ENUM_COMMISSIONINGENGINEER,
				ENUM_ENGINEER,
				ENUM_OWNER,
				ENUM_CONSULTANT,
				ENUM_CONSTRUCTIONMANAGER,
				ENUM_FIELDCONSTRUCTIONMANAGER,
				ENUM_RESELLER,
				ENUM_USERDEFINED
			};

			IfcRoleEnum();
			IfcRoleEnum( IfcRoleEnumEnum e ) { m_enum = e; }
			~IfcRoleEnum();
			virtual const char* classname() const { return "IfcRoleEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcRoleEnum> readStepData( std::string& arg );
			IfcRoleEnumEnum m_enum;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

