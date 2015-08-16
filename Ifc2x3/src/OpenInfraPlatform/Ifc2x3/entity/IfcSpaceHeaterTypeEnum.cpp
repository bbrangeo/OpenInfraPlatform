/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "include/IfcSpaceHeaterTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcSpaceHeaterTypeEnum 
		IfcSpaceHeaterTypeEnum::IfcSpaceHeaterTypeEnum() {}
		IfcSpaceHeaterTypeEnum::~IfcSpaceHeaterTypeEnum() {}
		void IfcSpaceHeaterTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCSPACEHEATERTYPEENUM("; }
			if( m_enum == ENUM_SECTIONALRADIATOR )
			{
				stream << ".SECTIONALRADIATOR.";
			}
			else if( m_enum == ENUM_PANELRADIATOR )
			{
				stream << ".PANELRADIATOR.";
			}
			else if( m_enum == ENUM_TUBULARRADIATOR )
			{
				stream << ".TUBULARRADIATOR.";
			}
			else if( m_enum == ENUM_CONVECTOR )
			{
				stream << ".CONVECTOR.";
			}
			else if( m_enum == ENUM_BASEBOARDHEATER )
			{
				stream << ".BASEBOARDHEATER.";
			}
			else if( m_enum == ENUM_FINNEDTUBEUNIT )
			{
				stream << ".FINNEDTUBEUNIT.";
			}
			else if( m_enum == ENUM_UNITHEATER )
			{
				stream << ".UNITHEATER.";
			}
			else if( m_enum == ENUM_USERDEFINED )
			{
				stream << ".USERDEFINED.";
			}
			else if( m_enum == ENUM_NOTDEFINED )
			{
				stream << ".NOTDEFINED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcSpaceHeaterTypeEnum> IfcSpaceHeaterTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcSpaceHeaterTypeEnum>(); }
			shared_ptr<IfcSpaceHeaterTypeEnum> type_object( new IfcSpaceHeaterTypeEnum() );
			if( _stricmp( arg.c_str(), ".SECTIONALRADIATOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_SECTIONALRADIATOR;
			}
			else if( _stricmp( arg.c_str(), ".PANELRADIATOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_PANELRADIATOR;
			}
			else if( _stricmp( arg.c_str(), ".TUBULARRADIATOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_TUBULARRADIATOR;
			}
			else if( _stricmp( arg.c_str(), ".CONVECTOR." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_CONVECTOR;
			}
			else if( _stricmp( arg.c_str(), ".BASEBOARDHEATER." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_BASEBOARDHEATER;
			}
			else if( _stricmp( arg.c_str(), ".FINNEDTUBEUNIT." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_FINNEDTUBEUNIT;
			}
			else if( _stricmp( arg.c_str(), ".UNITHEATER." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_UNITHEATER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcSpaceHeaterTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
