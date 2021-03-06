/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "include/IfcElectricGeneratorTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// TYPE IfcElectricGeneratorTypeEnum 
		IfcElectricGeneratorTypeEnum::IfcElectricGeneratorTypeEnum() {}
		IfcElectricGeneratorTypeEnum::~IfcElectricGeneratorTypeEnum() {}
		void IfcElectricGeneratorTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCELECTRICGENERATORTYPEENUM("; }
			if( m_enum == ENUM_CHP )
			{
				stream << ".CHP.";
			}
			else if( m_enum == ENUM_ENGINEGENERATOR )
			{
				stream << ".ENGINEGENERATOR.";
			}
			else if( m_enum == ENUM_STANDALONE )
			{
				stream << ".STANDALONE.";
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
		shared_ptr<IfcElectricGeneratorTypeEnum> IfcElectricGeneratorTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcElectricGeneratorTypeEnum>(); }
			shared_ptr<IfcElectricGeneratorTypeEnum> type_object( new IfcElectricGeneratorTypeEnum() );
			if( _stricmp( arg.c_str(), ".CHP." ) == 0 )
			{
				type_object->m_enum = IfcElectricGeneratorTypeEnum::ENUM_CHP;
			}
			else if( _stricmp( arg.c_str(), ".ENGINEGENERATOR." ) == 0 )
			{
				type_object->m_enum = IfcElectricGeneratorTypeEnum::ENUM_ENGINEGENERATOR;
			}
			else if( _stricmp( arg.c_str(), ".STANDALONE." ) == 0 )
			{
				type_object->m_enum = IfcElectricGeneratorTypeEnum::ENUM_STANDALONE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricGeneratorTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcElectricGeneratorTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
