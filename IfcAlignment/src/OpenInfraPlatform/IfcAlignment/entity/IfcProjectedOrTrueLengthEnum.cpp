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
#include "include/IfcProjectedOrTrueLengthEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcProjectedOrTrueLengthEnum 
		IfcProjectedOrTrueLengthEnum::IfcProjectedOrTrueLengthEnum() {}
		IfcProjectedOrTrueLengthEnum::~IfcProjectedOrTrueLengthEnum() {}
		void IfcProjectedOrTrueLengthEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCPROJECTEDORTRUELENGTHENUM("; }
			if( m_enum == ENUM_PROJECTED_LENGTH )
			{
				stream << ".PROJECTED_LENGTH.";
			}
			else if( m_enum == ENUM_TRUE_LENGTH )
			{
				stream << ".TRUE_LENGTH.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcProjectedOrTrueLengthEnum> IfcProjectedOrTrueLengthEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcProjectedOrTrueLengthEnum>(); }
			shared_ptr<IfcProjectedOrTrueLengthEnum> type_object( new IfcProjectedOrTrueLengthEnum() );
			if( _stricmp( arg.c_str(), ".PROJECTED_LENGTH." ) == 0 )
			{
				type_object->m_enum = IfcProjectedOrTrueLengthEnum::ENUM_PROJECTED_LENGTH;
			}
			else if( _stricmp( arg.c_str(), ".TRUE_LENGTH." ) == 0 )
			{
				type_object->m_enum = IfcProjectedOrTrueLengthEnum::ENUM_TRUE_LENGTH;
			}
			return type_object;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
