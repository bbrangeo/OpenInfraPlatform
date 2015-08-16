/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "include/IfcEvaporativeCoolerTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcEvaporativeCoolerTypeEnum 
		IfcEvaporativeCoolerTypeEnum::IfcEvaporativeCoolerTypeEnum() {}
		IfcEvaporativeCoolerTypeEnum::~IfcEvaporativeCoolerTypeEnum() {}
		void IfcEvaporativeCoolerTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCEVAPORATIVECOOLERTYPEENUM("; }
			if( m_enum == ENUM_DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER )
			{
				stream << ".DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER.";
			}
			else if( m_enum == ENUM_DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER )
			{
				stream << ".DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER.";
			}
			else if( m_enum == ENUM_DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER )
			{
				stream << ".DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER.";
			}
			else if( m_enum == ENUM_DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER )
			{
				stream << ".DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER.";
			}
			else if( m_enum == ENUM_DIRECTEVAPORATIVEAIRWASHER )
			{
				stream << ".DIRECTEVAPORATIVEAIRWASHER.";
			}
			else if( m_enum == ENUM_INDIRECTEVAPORATIVEPACKAGEAIRCOOLER )
			{
				stream << ".INDIRECTEVAPORATIVEPACKAGEAIRCOOLER.";
			}
			else if( m_enum == ENUM_INDIRECTEVAPORATIVEWETCOIL )
			{
				stream << ".INDIRECTEVAPORATIVEWETCOIL.";
			}
			else if( m_enum == ENUM_INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER )
			{
				stream << ".INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER.";
			}
			else if( m_enum == ENUM_INDIRECTDIRECTCOMBINATION )
			{
				stream << ".INDIRECTDIRECTCOMBINATION.";
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
		shared_ptr<IfcEvaporativeCoolerTypeEnum> IfcEvaporativeCoolerTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcEvaporativeCoolerTypeEnum>(); }
			shared_ptr<IfcEvaporativeCoolerTypeEnum> type_object( new IfcEvaporativeCoolerTypeEnum() );
			if( _stricmp( arg.c_str(), ".DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_DIRECTEVAPORATIVERANDOMMEDIAAIRCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_DIRECTEVAPORATIVERIGIDMEDIAAIRCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_DIRECTEVAPORATIVESLINGERSPACKAGEDAIRCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_DIRECTEVAPORATIVEPACKAGEDROTARYAIRCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".DIRECTEVAPORATIVEAIRWASHER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_DIRECTEVAPORATIVEAIRWASHER;
			}
			else if( _stricmp( arg.c_str(), ".INDIRECTEVAPORATIVEPACKAGEAIRCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_INDIRECTEVAPORATIVEPACKAGEAIRCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".INDIRECTEVAPORATIVEWETCOIL." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_INDIRECTEVAPORATIVEWETCOIL;
			}
			else if( _stricmp( arg.c_str(), ".INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_INDIRECTEVAPORATIVECOOLINGTOWERORCOILCOOLER;
			}
			else if( _stricmp( arg.c_str(), ".INDIRECTDIRECTCOMBINATION." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_INDIRECTDIRECTCOMBINATION;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcEvaporativeCoolerTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
