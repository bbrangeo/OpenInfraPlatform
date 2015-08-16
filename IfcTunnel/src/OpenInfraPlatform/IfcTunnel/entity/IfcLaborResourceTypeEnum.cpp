/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../model/IfcTunnelException.h"
#include "include/IfcLaborResourceTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcLaborResourceTypeEnum 
		IfcLaborResourceTypeEnum::IfcLaborResourceTypeEnum() {}
		IfcLaborResourceTypeEnum::~IfcLaborResourceTypeEnum() {}
		void IfcLaborResourceTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCLABORRESOURCETYPEENUM("; }
			if( m_enum == ENUM_ADMINISTRATION )
			{
				stream << ".ADMINISTRATION.";
			}
			else if( m_enum == ENUM_CARPENTRY )
			{
				stream << ".CARPENTRY.";
			}
			else if( m_enum == ENUM_CLEANING )
			{
				stream << ".CLEANING.";
			}
			else if( m_enum == ENUM_CONCRETE )
			{
				stream << ".CONCRETE.";
			}
			else if( m_enum == ENUM_DRYWALL )
			{
				stream << ".DRYWALL.";
			}
			else if( m_enum == ENUM_ELECTRIC )
			{
				stream << ".ELECTRIC.";
			}
			else if( m_enum == ENUM_FINISHING )
			{
				stream << ".FINISHING.";
			}
			else if( m_enum == ENUM_FLOORING )
			{
				stream << ".FLOORING.";
			}
			else if( m_enum == ENUM_GENERAL )
			{
				stream << ".GENERAL.";
			}
			else if( m_enum == ENUM_HVAC )
			{
				stream << ".HVAC.";
			}
			else if( m_enum == ENUM_LANDSCAPING )
			{
				stream << ".LANDSCAPING.";
			}
			else if( m_enum == ENUM_MASONRY )
			{
				stream << ".MASONRY.";
			}
			else if( m_enum == ENUM_PAINTING )
			{
				stream << ".PAINTING.";
			}
			else if( m_enum == ENUM_PAVING )
			{
				stream << ".PAVING.";
			}
			else if( m_enum == ENUM_PLUMBING )
			{
				stream << ".PLUMBING.";
			}
			else if( m_enum == ENUM_ROOFING )
			{
				stream << ".ROOFING.";
			}
			else if( m_enum == ENUM_SITEGRADING )
			{
				stream << ".SITEGRADING.";
			}
			else if( m_enum == ENUM_STEELWORK )
			{
				stream << ".STEELWORK.";
			}
			else if( m_enum == ENUM_SURVEYING )
			{
				stream << ".SURVEYING.";
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
		shared_ptr<IfcLaborResourceTypeEnum> IfcLaborResourceTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcLaborResourceTypeEnum>(); }
			shared_ptr<IfcLaborResourceTypeEnum> type_object( new IfcLaborResourceTypeEnum() );
			if( _stricmp( arg.c_str(), ".ADMINISTRATION." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ADMINISTRATION;
			}
			else if( _stricmp( arg.c_str(), ".CARPENTRY." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CARPENTRY;
			}
			else if( _stricmp( arg.c_str(), ".CLEANING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CLEANING;
			}
			else if( _stricmp( arg.c_str(), ".CONCRETE." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_CONCRETE;
			}
			else if( _stricmp( arg.c_str(), ".DRYWALL." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_DRYWALL;
			}
			else if( _stricmp( arg.c_str(), ".ELECTRIC." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ELECTRIC;
			}
			else if( _stricmp( arg.c_str(), ".FINISHING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_FINISHING;
			}
			else if( _stricmp( arg.c_str(), ".FLOORING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_FLOORING;
			}
			else if( _stricmp( arg.c_str(), ".GENERAL." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_GENERAL;
			}
			else if( _stricmp( arg.c_str(), ".HVAC." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_HVAC;
			}
			else if( _stricmp( arg.c_str(), ".LANDSCAPING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_LANDSCAPING;
			}
			else if( _stricmp( arg.c_str(), ".MASONRY." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_MASONRY;
			}
			else if( _stricmp( arg.c_str(), ".PAINTING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PAINTING;
			}
			else if( _stricmp( arg.c_str(), ".PAVING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PAVING;
			}
			else if( _stricmp( arg.c_str(), ".PLUMBING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_PLUMBING;
			}
			else if( _stricmp( arg.c_str(), ".ROOFING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_ROOFING;
			}
			else if( _stricmp( arg.c_str(), ".SITEGRADING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_SITEGRADING;
			}
			else if( _stricmp( arg.c_str(), ".STEELWORK." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_STEELWORK;
			}
			else if( _stricmp( arg.c_str(), ".SURVEYING." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_SURVEYING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcLaborResourceTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
