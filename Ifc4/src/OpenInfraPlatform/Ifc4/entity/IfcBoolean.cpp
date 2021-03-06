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
#include "include/IfcModulusOfRotationalSubgradeReactionSelect.h"
#include "include/IfcModulusOfSubgradeReactionSelect.h"
#include "include/IfcModulusOfTranslationalSubgradeReactionSelect.h"
#include "include/IfcRotationalStiffnessSelect.h"
#include "include/IfcSimpleValue.h"
#include "include/IfcTranslationalStiffnessSelect.h"
#include "include/IfcWarpingStiffnessSelect.h"
#include "include/IfcBoolean.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcBoolean 
		IfcBoolean::IfcBoolean() {}
		IfcBoolean::IfcBoolean( bool value ) { m_value = value; }
		IfcBoolean::~IfcBoolean() {}
		void IfcBoolean::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBOOLEAN("; }
			//supertype as attribute: bool m_value
			if( m_value == false )
			{
				stream << ".F.";
			}
			else if( m_value == true )
			{
				stream << ".T.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBoolean> IfcBoolean::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBoolean>(); }
			shared_ptr<IfcBoolean> type_object( new IfcBoolean() );
			//supertype as attribute: bool m_value
			if( _stricmp( arg.c_str(), ".F." ) == 0 )
			{
				type_object->m_value = false;
			}
			else if( _stricmp( arg.c_str(), ".T." ) == 0 )
			{
				type_object->m_value = true;
			}
			return type_object;
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
