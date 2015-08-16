/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcSpaceHeaterTypeEnum = ENUMERATION OF	(SECTIONALRADIATOR	,PANELRADIATOR	,TUBULARRADIATOR	,CONVECTOR	,BASEBOARDHEATER	,FINNEDTUBEUNIT	,UNITHEATER	,USERDEFINED	,NOTDEFINED);
		class IfcSpaceHeaterTypeEnum : public Ifc2x3AbstractEnum, public Ifc2x3Type
		{
		public:
			enum IfcSpaceHeaterTypeEnumEnum
			{
				ENUM_SECTIONALRADIATOR,
				ENUM_PANELRADIATOR,
				ENUM_TUBULARRADIATOR,
				ENUM_CONVECTOR,
				ENUM_BASEBOARDHEATER,
				ENUM_FINNEDTUBEUNIT,
				ENUM_UNITHEATER,
				ENUM_USERDEFINED,
				ENUM_NOTDEFINED
			};

			IfcSpaceHeaterTypeEnum();
			IfcSpaceHeaterTypeEnum( IfcSpaceHeaterTypeEnumEnum e ) { m_enum = e; }
			~IfcSpaceHeaterTypeEnum();
			virtual const char* classname() const { return "IfcSpaceHeaterTypeEnum"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcSpaceHeaterTypeEnum> readStepData( std::string& arg );
			IfcSpaceHeaterTypeEnumEnum m_enum;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

