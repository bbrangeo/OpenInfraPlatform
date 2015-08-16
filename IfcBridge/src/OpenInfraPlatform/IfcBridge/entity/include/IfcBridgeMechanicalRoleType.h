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
		// TYPE IfcBridgeMechanicalRoleType = ENUMERATION OF (    LONGITUDINAL,    TRANSVERSAL,    COMPLETE,    NONE,    UNDEFINED);
		class IfcBridgeMechanicalRoleType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeMechanicalRoleTypeEnum
			{
				ENUM_LONGITUDINAL,
				ENUM_TRANSVERSAL,
				ENUM_COMPLETE,
				ENUM_NONE,
				ENUM_UNDEFINED
			};

			IfcBridgeMechanicalRoleType();
			IfcBridgeMechanicalRoleType( IfcBridgeMechanicalRoleTypeEnum e ) { m_enum = e; }
			~IfcBridgeMechanicalRoleType();
			virtual const char* classname() const { return "IfcBridgeMechanicalRoleType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeMechanicalRoleType> readStepData( std::string& arg );
			IfcBridgeMechanicalRoleTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

