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
		// TYPE IfcBridgeTechnologicalElementType = ENUMERATION OF (UNICELLULAR_MONO_BOX_GIRDER,MULTICELLULAR_MONO_BOX_GIRDER,UNICELLULAR_MULTI_BOX_GIRDER,MULTICELLULAR_MULTI_BOX_GIRDER,SOLID_SLAB,HOLLOW_SLAB,SLAB_WITH_BROAD_CANTILEVER,DOUBLE_BEAM_RIBBED_SLAB,MULTI_BEAM_RIBBED_SLAB,MASSIVE_SECTION_ELEMENT,HOLLOW_SECTION_ELEMENT,MARKETED_SECTION_GIRDER,RE_ASSEMBLED_SECTION_GIRDER,TRUSS,LADDER_OR_VIERENDEEL,BOW_STRING);
		class IfcBridgeTechnologicalElementType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeTechnologicalElementTypeEnum
			{
				ENUM_UNICELLULAR_MONO_BOX_GIRDER,
				ENUM_MULTICELLULAR_MONO_BOX_GIRDER,
				ENUM_UNICELLULAR_MULTI_BOX_GIRDER,
				ENUM_MULTICELLULAR_MULTI_BOX_GIRDER,
				ENUM_SOLID_SLAB,
				ENUM_HOLLOW_SLAB,
				ENUM_SLAB_WITH_BROAD_CANTILEVER,
				ENUM_DOUBLE_BEAM_RIBBED_SLAB,
				ENUM_MULTI_BEAM_RIBBED_SLAB,
				ENUM_MASSIVE_SECTION_ELEMENT,
				ENUM_HOLLOW_SECTION_ELEMENT,
				ENUM_MARKETED_SECTION_GIRDER,
				ENUM_RE_ASSEMBLED_SECTION_GIRDER,
				ENUM_TRUSS,
				ENUM_LADDER_OR_VIERENDEEL,
				ENUM_BOW_STRING
			};

			IfcBridgeTechnologicalElementType();
			IfcBridgeTechnologicalElementType( IfcBridgeTechnologicalElementTypeEnum e ) { m_enum = e; }
			~IfcBridgeTechnologicalElementType();
			virtual const char* classname() const { return "IfcBridgeTechnologicalElementType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeTechnologicalElementType> readStepData( std::string& arg );
			IfcBridgeTechnologicalElementTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

