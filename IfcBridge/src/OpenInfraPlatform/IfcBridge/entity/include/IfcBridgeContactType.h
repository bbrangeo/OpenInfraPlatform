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
		// TYPE IfcBridgeContactType = ENUMERATION OF (GLUE,RIVET,CONNECTOR,WELD,RESUMPTION_OF_CONCRETE,SLIDING);
		class IfcBridgeContactType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeContactTypeEnum
			{
				ENUM_GLUE,
				ENUM_RIVET,
				ENUM_CONNECTOR,
				ENUM_WELD,
				ENUM_RESUMPTION_OF_CONCRETE,
				ENUM_SLIDING
			};

			IfcBridgeContactType();
			IfcBridgeContactType( IfcBridgeContactTypeEnum e ) { m_enum = e; }
			~IfcBridgeContactType();
			virtual const char* classname() const { return "IfcBridgeContactType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeContactType> readStepData( std::string& arg );
			IfcBridgeContactTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

