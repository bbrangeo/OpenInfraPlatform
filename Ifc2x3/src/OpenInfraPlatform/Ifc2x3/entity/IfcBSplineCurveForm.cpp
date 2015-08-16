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
#include "include/IfcBSplineCurveForm.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcBSplineCurveForm 
		IfcBSplineCurveForm::IfcBSplineCurveForm() {}
		IfcBSplineCurveForm::~IfcBSplineCurveForm() {}
		void IfcBSplineCurveForm::getStepParameter( std::stringstream& stream, bool is_select_type ) const
		{
			if( is_select_type ) { stream << "IFCBSPLINECURVEFORM("; }
			if( m_enum == ENUM_POLYLINE_FORM )
			{
				stream << ".POLYLINE_FORM.";
			}
			else if( m_enum == ENUM_CIRCULAR_ARC )
			{
				stream << ".CIRCULAR_ARC.";
			}
			else if( m_enum == ENUM_ELLIPTIC_ARC )
			{
				stream << ".ELLIPTIC_ARC.";
			}
			else if( m_enum == ENUM_PARABOLIC_ARC )
			{
				stream << ".PARABOLIC_ARC.";
			}
			else if( m_enum == ENUM_HYPERBOLIC_ARC )
			{
				stream << ".HYPERBOLIC_ARC.";
			}
			else if( m_enum == ENUM_UNSPECIFIED )
			{
				stream << ".UNSPECIFIED.";
			}
			if( is_select_type ) { stream << ")"; }
		}
		shared_ptr<IfcBSplineCurveForm> IfcBSplineCurveForm::readStepData( std::string& arg )
		{
			// read TYPE
			if( arg.compare( "$" ) == 0 ) { return shared_ptr<IfcBSplineCurveForm>(); }
			shared_ptr<IfcBSplineCurveForm> type_object( new IfcBSplineCurveForm() );
			if( _stricmp( arg.c_str(), ".POLYLINE_FORM." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_POLYLINE_FORM;
			}
			else if( _stricmp( arg.c_str(), ".CIRCULAR_ARC." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_CIRCULAR_ARC;
			}
			else if( _stricmp( arg.c_str(), ".ELLIPTIC_ARC." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_ELLIPTIC_ARC;
			}
			else if( _stricmp( arg.c_str(), ".PARABOLIC_ARC." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_PARABOLIC_ARC;
			}
			else if( _stricmp( arg.c_str(), ".HYPERBOLIC_ARC." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_HYPERBOLIC_ARC;
			}
			else if( _stricmp( arg.c_str(), ".UNSPECIFIED." ) == 0 )
			{
				type_object->m_enum = IfcBSplineCurveForm::ENUM_UNSPECIFIED;
			}
			return type_object;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
