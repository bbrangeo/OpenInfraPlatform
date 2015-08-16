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
		// TYPE IfcBridgeStructureType = ENUMERATION OF (BOX_GIRDER_BRIDGE,ARCHED_BRIDGE,SUSPENSION_BRIDGE,CABLE_STAYED_BRIDGE,GIRDER_BRIDGE,SLAB_BRIDGE,SLAB_BRIDGE_WITH_BROAD_CANTILEVER,BOW_STRING_BRIDGE,LADDER_BRIDGE,FRAMEWORK_BRIDGE,GISCLARD_BRIDGE,PORTAL_BRIDGE);
		class IfcBridgeStructureType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeStructureTypeEnum
			{
				ENUM_BOX_GIRDER_BRIDGE,
				ENUM_ARCHED_BRIDGE,
				ENUM_SUSPENSION_BRIDGE,
				ENUM_CABLE_STAYED_BRIDGE,
				ENUM_GIRDER_BRIDGE,
				ENUM_SLAB_BRIDGE,
				ENUM_SLAB_BRIDGE_WITH_BROAD_CANTILEVER,
				ENUM_BOW_STRING_BRIDGE,
				ENUM_LADDER_BRIDGE,
				ENUM_FRAMEWORK_BRIDGE,
				ENUM_GISCLARD_BRIDGE,
				ENUM_PORTAL_BRIDGE
			};

			IfcBridgeStructureType();
			IfcBridgeStructureType( IfcBridgeStructureTypeEnum e ) { m_enum = e; }
			~IfcBridgeStructureType();
			virtual const char* classname() const { return "IfcBridgeStructureType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeStructureType> readStepData( std::string& arg );
			IfcBridgeStructureTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

