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
		// TYPE IfcBridgePrismaticElementType = ENUMERATION OF (UNICELLULAR_MONO_BOX_GIRDER,MULTICELLULAR_MONO_BOX_GIRDER,UNICELLULAR_MULTI_BOX_GIRDER,MULTICELLULAR_MULTI_BOX_GIRDER,DOUBLE_BEAM_RIBBED_SLAB,MULTI_BEAM_RIBBED_SLAB,MASSIVE_SECTION_ELEMENT,HOLLOW_SECTION_ELEMENT,SOLID_SLAB,HOLLOW_SLAB,SLAB_WITH_BROAD_CANTILEVER,MASTER_BEAM,LONGITUDINAL_GIRDER,RIGIDITY_BEAM,BRACING,UPPER_FLANGE,LOWER_FLANGE,UPPER_FOOTING,LOWER_FOOTING,WEB,FLOORING_SHEET,BOTTOM_SHEET,KERB_SHEET,CANTILEVER_SHEET,PAVEMENT_SHEET,AUGET,LONGITUDINAL_WEB_STIFFENER,RAKER,TRANSVERSE_GIRDER,DEFLECTER,TRANSVERSE_MEMBER,TRANSVERSE,DIAGONALE,JAMB,TENSION_MEMBER,BONDING_BAR,TRANSVERSAL_STIFFENER,STIFFENER_FOOTING,TENDON);
		class IfcBridgePrismaticElementType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgePrismaticElementTypeEnum
			{
				ENUM_UNICELLULAR_MONO_BOX_GIRDER,
				ENUM_MULTICELLULAR_MONO_BOX_GIRDER,
				ENUM_UNICELLULAR_MULTI_BOX_GIRDER,
				ENUM_MULTICELLULAR_MULTI_BOX_GIRDER,
				ENUM_DOUBLE_BEAM_RIBBED_SLAB,
				ENUM_MULTI_BEAM_RIBBED_SLAB,
				ENUM_MASSIVE_SECTION_ELEMENT,
				ENUM_HOLLOW_SECTION_ELEMENT,
				ENUM_SOLID_SLAB,
				ENUM_HOLLOW_SLAB,
				ENUM_SLAB_WITH_BROAD_CANTILEVER,
				ENUM_MASTER_BEAM,
				ENUM_LONGITUDINAL_GIRDER,
				ENUM_RIGIDITY_BEAM,
				ENUM_BRACING,
				ENUM_UPPER_FLANGE,
				ENUM_LOWER_FLANGE,
				ENUM_UPPER_FOOTING,
				ENUM_LOWER_FOOTING,
				ENUM_WEB,
				ENUM_FLOORING_SHEET,
				ENUM_BOTTOM_SHEET,
				ENUM_KERB_SHEET,
				ENUM_CANTILEVER_SHEET,
				ENUM_PAVEMENT_SHEET,
				ENUM_AUGET,
				ENUM_LONGITUDINAL_WEB_STIFFENER,
				ENUM_RAKER,
				ENUM_TRANSVERSE_GIRDER,
				ENUM_DEFLECTER,
				ENUM_TRANSVERSE_MEMBER,
				ENUM_TRANSVERSE,
				ENUM_DIAGONALE,
				ENUM_JAMB,
				ENUM_TENSION_MEMBER,
				ENUM_BONDING_BAR,
				ENUM_TRANSVERSAL_STIFFENER,
				ENUM_STIFFENER_FOOTING,
				ENUM_TENDON
			};

			IfcBridgePrismaticElementType();
			IfcBridgePrismaticElementType( IfcBridgePrismaticElementTypeEnum e ) { m_enum = e; }
			~IfcBridgePrismaticElementType();
			virtual const char* classname() const { return "IfcBridgePrismaticElementType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgePrismaticElementType> readStepData( std::string& arg );
			IfcBridgePrismaticElementTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

