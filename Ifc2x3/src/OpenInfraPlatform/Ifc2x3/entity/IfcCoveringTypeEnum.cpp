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
#include "include/IfcCoveringTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcCoveringTypeEnum 
		IfcCoveringTypeEnum::IfcCoveringTypeEnum() {}
		IfcCoveringTypeEnum::~IfcCoveringTypeEnum() {}
		void IfcCoveringTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOVERINGTYPEENUM("; }
			if( m_enum == ENUM_CEILING )
			{
				stream << ".CEILING.";
			}
			else if( m_enum == ENUM_FLOORING )
			{
				stream << ".FLOORING.";
			}
			else if( m_enum == ENUM_CLADDING )
			{
				stream << ".CLADDING.";
			}
			else if( m_enum == ENUM_ROOFING )
			{
				stream << ".ROOFING.";
			}
			else if( m_enum == ENUM_INSULATION )
			{
				stream << ".INSULATION.";
			}
			else if( m_enum == ENUM_MEMBRANE )
			{
				stream << ".MEMBRANE.";
			}
			else if( m_enum == ENUM_SLEEVING )
			{
				stream << ".SLEEVING.";
			}
			else if( m_enum == ENUM_WRAPPING )
			{
				stream << ".WRAPPING.";
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
		shared_ptr<IfcCoveringTypeEnum> IfcCoveringTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCoveringTypeEnum>(); }
			shared_ptr<IfcCoveringTypeEnum> type_object( new IfcCoveringTypeEnum() );
			if( _stricmp( arg.c_str(), ".CEILING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_CEILING;
			}
			else if( _stricmp( arg.c_str(), ".FLOORING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_FLOORING;
			}
			else if( _stricmp( arg.c_str(), ".CLADDING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_CLADDING;
			}
			else if( _stricmp( arg.c_str(), ".ROOFING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_ROOFING;
			}
			else if( _stricmp( arg.c_str(), ".INSULATION." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_INSULATION;
			}
			else if( _stricmp( arg.c_str(), ".MEMBRANE." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_MEMBRANE;
			}
			else if( _stricmp( arg.c_str(), ".SLEEVING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_SLEEVING;
			}
			else if( _stricmp( arg.c_str(), ".WRAPPING." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_WRAPPING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCoveringTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
