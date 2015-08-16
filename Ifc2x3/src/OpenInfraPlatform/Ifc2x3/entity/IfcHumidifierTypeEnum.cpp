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
#include "include/IfcHumidifierTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcHumidifierTypeEnum 
		IfcHumidifierTypeEnum::IfcHumidifierTypeEnum() {}
		IfcHumidifierTypeEnum::~IfcHumidifierTypeEnum() {}
		void IfcHumidifierTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCHUMIDIFIERTYPEENUM("; }
			if( m_enum == ENUM_STEAMINJECTION )
			{
				stream << ".STEAMINJECTION.";
			}
			else if( m_enum == ENUM_ADIABATICAIRWASHER )
			{
				stream << ".ADIABATICAIRWASHER.";
			}
			else if( m_enum == ENUM_ADIABATICPAN )
			{
				stream << ".ADIABATICPAN.";
			}
			else if( m_enum == ENUM_ADIABATICWETTEDELEMENT )
			{
				stream << ".ADIABATICWETTEDELEMENT.";
			}
			else if( m_enum == ENUM_ADIABATICATOMIZING )
			{
				stream << ".ADIABATICATOMIZING.";
			}
			else if( m_enum == ENUM_ADIABATICULTRASONIC )
			{
				stream << ".ADIABATICULTRASONIC.";
			}
			else if( m_enum == ENUM_ADIABATICRIGIDMEDIA )
			{
				stream << ".ADIABATICRIGIDMEDIA.";
			}
			else if( m_enum == ENUM_ADIABATICCOMPRESSEDAIRNOZZLE )
			{
				stream << ".ADIABATICCOMPRESSEDAIRNOZZLE.";
			}
			else if( m_enum == ENUM_ASSISTEDELECTRIC )
			{
				stream << ".ASSISTEDELECTRIC.";
			}
			else if( m_enum == ENUM_ASSISTEDNATURALGAS )
			{
				stream << ".ASSISTEDNATURALGAS.";
			}
			else if( m_enum == ENUM_ASSISTEDPROPANE )
			{
				stream << ".ASSISTEDPROPANE.";
			}
			else if( m_enum == ENUM_ASSISTEDBUTANE )
			{
				stream << ".ASSISTEDBUTANE.";
			}
			else if( m_enum == ENUM_ASSISTEDSTEAM )
			{
				stream << ".ASSISTEDSTEAM.";
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
		shared_ptr<IfcHumidifierTypeEnum> IfcHumidifierTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcHumidifierTypeEnum>(); }
			shared_ptr<IfcHumidifierTypeEnum> type_object( new IfcHumidifierTypeEnum() );
			if( _stricmp( arg.c_str(), ".STEAMINJECTION." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_STEAMINJECTION;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICAIRWASHER." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICAIRWASHER;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICPAN." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICPAN;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICWETTEDELEMENT." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICWETTEDELEMENT;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICATOMIZING." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICATOMIZING;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICULTRASONIC." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICULTRASONIC;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICRIGIDMEDIA." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICRIGIDMEDIA;
			}
			else if( _stricmp( arg.c_str(), ".ADIABATICCOMPRESSEDAIRNOZZLE." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ADIABATICCOMPRESSEDAIRNOZZLE;
			}
			else if( _stricmp( arg.c_str(), ".ASSISTEDELECTRIC." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ASSISTEDELECTRIC;
			}
			else if( _stricmp( arg.c_str(), ".ASSISTEDNATURALGAS." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ASSISTEDNATURALGAS;
			}
			else if( _stricmp( arg.c_str(), ".ASSISTEDPROPANE." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ASSISTEDPROPANE;
			}
			else if( _stricmp( arg.c_str(), ".ASSISTEDBUTANE." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ASSISTEDBUTANE;
			}
			else if( _stricmp( arg.c_str(), ".ASSISTEDSTEAM." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_ASSISTEDSTEAM;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcHumidifierTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
