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
		// TYPE IfcBridgeSegmentType = ENUMERATION OF (TYPICAL_SEGMENT,PIER_SEGMENT,PIECE,LIFT,ELEMENT,JAMB,PYLON_HEAD,SPAN,CANTILEVER,FINITE_ELEMENT_REFERENCE);
		class IfcBridgeSegmentType : public IfcBridgeAbstractEnum, public IfcBridgeType
		{
		public:
			enum IfcBridgeSegmentTypeEnum
			{
				ENUM_TYPICAL_SEGMENT,
				ENUM_PIER_SEGMENT,
				ENUM_PIECE,
				ENUM_LIFT,
				ENUM_ELEMENT,
				ENUM_JAMB,
				ENUM_PYLON_HEAD,
				ENUM_SPAN,
				ENUM_CANTILEVER,
				ENUM_FINITE_ELEMENT_REFERENCE
			};

			IfcBridgeSegmentType();
			IfcBridgeSegmentType( IfcBridgeSegmentTypeEnum e ) { m_enum = e; }
			~IfcBridgeSegmentType();
			virtual const char* classname() const { return "IfcBridgeSegmentType"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcBridgeSegmentType> readStepData( std::string& arg );
			IfcBridgeSegmentTypeEnum m_enum;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

