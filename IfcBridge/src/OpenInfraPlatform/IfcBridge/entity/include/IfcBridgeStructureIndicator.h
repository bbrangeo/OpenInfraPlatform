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
		// TYPE IfcBridgeStructureIndicator = ENUMERATION OF (COMPOSITE,COATED,HOMOGENEOUS,OTHER);
		class IfcBridgeStructureIndicator : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeStructureIndicatorEnum
			{
				ENUM_COMPOSITE,
				ENUM_COATED,
				ENUM_HOMOGENEOUS,
				ENUM_OTHER
			};

			IfcBridgeStructureIndicator();
			IfcBridgeStructureIndicator( IfcBridgeStructureIndicatorEnum e ) { m_enum = e; }
			~IfcBridgeStructureIndicator();
			virtual const char* classname() const { return "IfcBridgeStructureIndicator"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeStructureIndicator> readStepData( std::string& arg );
			IfcBridgeStructureIndicatorEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

