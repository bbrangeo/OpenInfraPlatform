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
#include "include/IfcCableCarrierFittingTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcCableCarrierFittingTypeEnum 
		IfcCableCarrierFittingTypeEnum::IfcCableCarrierFittingTypeEnum() {}
		IfcCableCarrierFittingTypeEnum::~IfcCableCarrierFittingTypeEnum() {}
		void IfcCableCarrierFittingTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCABLECARRIERFITTINGTYPEENUM("; }
			if( m_enum == ENUM_BEND )
			{
				stream << ".BEND.";
			}
			else if( m_enum == ENUM_CROSS )
			{
				stream << ".CROSS.";
			}
			else if( m_enum == ENUM_REDUCER )
			{
				stream << ".REDUCER.";
			}
			else if( m_enum == ENUM_TEE )
			{
				stream << ".TEE.";
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
		shared_ptr<IfcCableCarrierFittingTypeEnum> IfcCableCarrierFittingTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcCableCarrierFittingTypeEnum>(); }
			shared_ptr<IfcCableCarrierFittingTypeEnum> type_object( new IfcCableCarrierFittingTypeEnum() );
			if( _stricmp( arg.c_str(), ".BEND." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_BEND;
			}
			else if( _stricmp( arg.c_str(), ".CROSS." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_CROSS;
			}
			else if( _stricmp( arg.c_str(), ".REDUCER." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_REDUCER;
			}
			else if( _stricmp( arg.c_str(), ".TEE." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_TEE;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcCableCarrierFittingTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
