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
#include "include/IfcDistributionChamberElementTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcDistributionChamberElementTypeEnum 
		IfcDistributionChamberElementTypeEnum::IfcDistributionChamberElementTypeEnum() {}
		IfcDistributionChamberElementTypeEnum::~IfcDistributionChamberElementTypeEnum() {}
		void IfcDistributionChamberElementTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCDISTRIBUTIONCHAMBERELEMENTTYPEENUM("; }
			if( m_enum == ENUM_FORMEDDUCT )
			{
				stream << ".FORMEDDUCT.";
			}
			else if( m_enum == ENUM_INSPECTIONCHAMBER )
			{
				stream << ".INSPECTIONCHAMBER.";
			}
			else if( m_enum == ENUM_INSPECTIONPIT )
			{
				stream << ".INSPECTIONPIT.";
			}
			else if( m_enum == ENUM_MANHOLE )
			{
				stream << ".MANHOLE.";
			}
			else if( m_enum == ENUM_METERCHAMBER )
			{
				stream << ".METERCHAMBER.";
			}
			else if( m_enum == ENUM_SUMP )
			{
				stream << ".SUMP.";
			}
			else if( m_enum == ENUM_TRENCH )
			{
				stream << ".TRENCH.";
			}
			else if( m_enum == ENUM_VALVECHAMBER )
			{
				stream << ".VALVECHAMBER.";
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
		shared_ptr<IfcDistributionChamberElementTypeEnum> IfcDistributionChamberElementTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcDistributionChamberElementTypeEnum>(); }
			shared_ptr<IfcDistributionChamberElementTypeEnum> type_object( new IfcDistributionChamberElementTypeEnum() );
			if( _stricmp( arg.c_str(), ".FORMEDDUCT." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_FORMEDDUCT;
			}
			else if( _stricmp( arg.c_str(), ".INSPECTIONCHAMBER." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_INSPECTIONCHAMBER;
			}
			else if( _stricmp( arg.c_str(), ".INSPECTIONPIT." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_INSPECTIONPIT;
			}
			else if( _stricmp( arg.c_str(), ".MANHOLE." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_MANHOLE;
			}
			else if( _stricmp( arg.c_str(), ".METERCHAMBER." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_METERCHAMBER;
			}
			else if( _stricmp( arg.c_str(), ".SUMP." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_SUMP;
			}
			else if( _stricmp( arg.c_str(), ".TRENCH." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_TRENCH;
			}
			else if( _stricmp( arg.c_str(), ".VALVECHAMBER." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_VALVECHAMBER;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcDistributionChamberElementTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
