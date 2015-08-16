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
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElementAssemblyTypeEnum = ENUMERATION OF	(ACCESSORY_ASSEMBLY	,ARCH	,BEAM_GRID	,BRACED_FRAME	,GIRDER	,REINFORCEMENT_UNIT	,RIGID_FRAME	,SLAB_FIELD	,TRUSS	,USERDEFINED	,NOTDEFINED);
		class IfcElementAssemblyTypeEnum : public IfcRoadAbstractEnum, public IfcRoadType
		{
		public:
			enum IfcElementAssemblyTypeEnumEnum
			{
				ENUM_ACCESSORY_ASSEMBLY,
				ENUM_ARCH,
				ENUM_BEAM_GRID,
				ENUM_BRACED_FRAME,
				ENUM_GIRDER,
				ENUM_REINFORCEMENT_UNIT,
				ENUM_RIGID_FRAME,
				ENUM_SLAB_FIELD,
				ENUM_TRUSS,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcElementAssemblyTypeEnum();
			IfcElementAssemblyTypeEnum( IfcElementAssemblyTypeEnumEnum e ) { m_enum = e; }
			~IfcElementAssemblyTypeEnum();
			virtual const char* classname() const { return "IfcElementAssemblyTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcElementAssemblyTypeEnum> readStepData( std::string& arg );
			IfcElementAssemblyTypeEnumEnum m_enum;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

