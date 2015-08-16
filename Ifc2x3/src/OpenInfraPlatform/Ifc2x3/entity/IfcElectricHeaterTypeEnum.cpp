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
#include "include/IfcElectricHeaterTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcElectricHeaterTypeEnum 
		IfcElectricHeaterTypeEnum::IfcElectricHeaterTypeEnum() {}
		IfcElectricHeaterTypeEnum::~IfcElectricHeaterTypeEnum() {}
		void IfcElectricHeaterTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICHEATERTYPEENUM("; }
			if( m_enum == ENUM_ELECTRICPOINTHEATER )
			{
				stream << ".ELECTRICPOINTHEATER.";
			}
			else if( m_enum == ENUM_ELECTRICCABLEHEATER )
			{
				stream << ".ELECTRICCABLEHEATER.";
			}
			else if( m_enum == ENUM_ELECTRICMATHEATER )
			{
				stream << ".ELECTRICMATHEATER.";
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
		shared_ptr<IfcElectricHeaterTypeEnum> IfcElectricHeaterTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricHeaterTypeEnum>(); }
			shared_ptr<IfcElectricHeaterTypeEnum> type_object( new IfcElectricHeaterTypeEnum() );
			if( _stricmp( arg.c_str(), ".ELECTRICPOINTHEATER." ) == 0 )
			{
				type_object->m_enum = IfcElectricHeaterTypeEnum::ENUM_ELECTRICPOINTHEATER;
			}
			else if( _stricmp( arg.c_str(), ".ELECTRICCABLEHEATER." ) == 0 )
			{
				type_object->m_enum = IfcElectricHeaterTypeEnum::ENUM_ELECTRICCABLEHEATER;
			}
			else if( _stricmp( arg.c_str(), ".ELECTRICMATHEATER." ) == 0 )
			{
				type_object->m_enum = IfcElectricHeaterTypeEnum::ENUM_ELECTRICMATHEATER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricHeaterTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricHeaterTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
