/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/


#include <sstream>
#include <limits>
#include <map>
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "include/IfcComplexPropertyTemplateTypeEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcComplexPropertyTemplateTypeEnum 
		IfcComplexPropertyTemplateTypeEnum::IfcComplexPropertyTemplateTypeEnum() {}
		IfcComplexPropertyTemplateTypeEnum::~IfcComplexPropertyTemplateTypeEnum() {}
		void IfcComplexPropertyTemplateTypeEnum::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCCOMPLEXPROPERTYTEMPLATETYPEENUM("; }
			if( m_enum == ENUM_P_COMPLEX )
			{
				stream << ".P_COMPLEX.";
			}
			else if( m_enum == ENUM_Q_COMPLEX )
			{
				stream << ".Q_COMPLEX.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcComplexPropertyTemplateTypeEnum> IfcComplexPropertyTemplateTypeEnum::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcComplexPropertyTemplateTypeEnum>(); }
			shared_ptr<IfcComplexPropertyTemplateTypeEnum> type_object( new IfcComplexPropertyTemplateTypeEnum() );
			if( _stricmp( arg.c_str(), ".P_COMPLEX." ) == 0 )
			{
				type_object->m_enum = IfcComplexPropertyTemplateTypeEnum::ENUM_P_COMPLEX;
			}
			else if( _stricmp( arg.c_str(), ".Q_COMPLEX." ) == 0 )
			{
				type_object->m_enum = IfcComplexPropertyTemplateTypeEnum::ENUM_Q_COMPLEX;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
