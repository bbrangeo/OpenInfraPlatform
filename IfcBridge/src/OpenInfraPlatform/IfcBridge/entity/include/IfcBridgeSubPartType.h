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
		// TYPE IfcBridgeSubPartType = ENUMERATION OF (LEFT_WEB,RIGHT_WEB,CENTRAL_WEB,TOP_SLAB,LOWER_SLAB,RIGHT_OVERHANG,LEFT_OVERHANG,UPPER_FLANGE_,LOWER_FLANGE,LOWER_FLOORING,UPPER_FLOORING,MORPHOLOGY_NODE,REFERENCE_FIBRE,BRANCH_WALL);
		class IfcBridgeSubPartType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeSubPartTypeEnum
			{
				ENUM_LEFT_WEB,
				ENUM_RIGHT_WEB,
				ENUM_CENTRAL_WEB,
				ENUM_TOP_SLAB,
				ENUM_LOWER_SLAB,
				ENUM_RIGHT_OVERHANG,
				ENUM_LEFT_OVERHANG,
				ENUM_UPPER_FLANGE_,
				ENUM_LOWER_FLANGE,
				ENUM_LOWER_FLOORING,
				ENUM_UPPER_FLOORING,
				ENUM_MORPHOLOGY_NODE,
				ENUM_REFERENCE_FIBRE,
				ENUM_BRANCH_WALL
			};

			IfcBridgeSubPartType();
			IfcBridgeSubPartType( IfcBridgeSubPartTypeEnum e ) { m_enum = e; }
			~IfcBridgeSubPartType();
			virtual const char* classname() const { return "IfcBridgeSubPartType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeSubPartType> readStepData( std::string& arg );
			IfcBridgeSubPartTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

