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
#include "include/IfcFootingTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcFootingTypeEnum 
		IfcFootingTypeEnum::IfcFootingTypeEnum() {}
		IfcFootingTypeEnum::~IfcFootingTypeEnum() {}
		void IfcFootingTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCFOOTINGTYPEENUM("; }
			if( m_enum == ENUM_FOOTING_BEAM )
			{
				stream << ".FOOTING_BEAM.";
			}
			else if( m_enum == ENUM_PAD_FOOTING )
			{
				stream << ".PAD_FOOTING.";
			}
			else if( m_enum == ENUM_PILE_CAP )
			{
				stream << ".PILE_CAP.";
			}
			else if( m_enum == ENUM_STRIP_FOOTING )
			{
				stream << ".STRIP_FOOTING.";
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
		shared_ptr<IfcFootingTypeEnum> IfcFootingTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcFootingTypeEnum>(); }
			shared_ptr<IfcFootingTypeEnum> type_object( new IfcFootingTypeEnum() );
			if( _stricmp( arg.c_str(), ".FOOTING_BEAM." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_FOOTING_BEAM;
			}
			else if( _stricmp( arg.c_str(), ".PAD_FOOTING." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_PAD_FOOTING;
			}
			else if( _stricmp( arg.c_str(), ".PILE_CAP." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_PILE_CAP;
			}
			else if( _stricmp( arg.c_str(), ".STRIP_FOOTING." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_STRIP_FOOTING;
			}
			else if( _stricmp( arg.c_str(), ".USERDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_USERDEFINED;
			}
			else if( _stricmp( arg.c_str(), ".NOTDEFINED." ) == 0 )
			{
				type_object->m_enum = IfcFootingTypeEnum::ENUM_NOTDEFINED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
