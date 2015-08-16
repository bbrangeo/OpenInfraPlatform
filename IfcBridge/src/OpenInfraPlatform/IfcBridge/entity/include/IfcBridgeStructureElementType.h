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
		// TYPE IfcBridgeStructureElementType = ENUMERATION OF (DECK,PIER,SMALL_PIER,PYLON,ARCH,LAUNCHING_NOSE,TEMPORARY_BENT,TRANSVERSE_GIRDER,STRUT,COUNTER_STRUT,CABLE,SUSPENDED_TENDON,SUSPENDER,MOBILE_FALSEWORK,STAYING_MAST,LAUNCHING_BEAM);
		class IfcBridgeStructureElementType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeStructureElementTypeEnum
			{
				ENUM_DECK,
				ENUM_PIER,
				ENUM_SMALL_PIER,
				ENUM_PYLON,
				ENUM_ARCH,
				ENUM_LAUNCHING_NOSE,
				ENUM_TEMPORARY_BENT,
				ENUM_TRANSVERSE_GIRDER,
				ENUM_STRUT,
				ENUM_COUNTER_STRUT,
				ENUM_CABLE,
				ENUM_SUSPENDED_TENDON,
				ENUM_SUSPENDER,
				ENUM_MOBILE_FALSEWORK,
				ENUM_STAYING_MAST,
				ENUM_LAUNCHING_BEAM
			};

			IfcBridgeStructureElementType();
			IfcBridgeStructureElementType( IfcBridgeStructureElementTypeEnum e ) { m_enum = e; }
			~IfcBridgeStructureElementType();
			virtual const char* classname() const { return "IfcBridgeStructureElementType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeStructureElementType> readStepData( std::string& arg );
			IfcBridgeStructureElementTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

