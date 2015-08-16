/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcCurveStyleFontAndScaling.h"
#include "include/IfcCurveStyleFontSelect.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcCurveStyleFontAndScaling 
		IfcCurveStyleFontAndScaling::IfcCurveStyleFontAndScaling() { m_entity_enum = IFCCURVESTYLEFONTANDSCALING; }
		IfcCurveStyleFontAndScaling::IfcCurveStyleFontAndScaling( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLEFONTANDSCALING; }
		IfcCurveStyleFontAndScaling::~IfcCurveStyleFontAndScaling() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveStyleFontAndScaling::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcCurveStyleFontAndScaling> other = dynamic_pointer_cast<IfcCurveStyleFontAndScaling>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_CurveFont = other->m_CurveFont;
			m_CurveFontScaling = other->m_CurveFontScaling;
		}
		void IfcCurveStyleFontAndScaling::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVESTYLEFONTANDSCALING" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveFont ) { m_CurveFont->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveFontScaling ) { m_CurveFontScaling->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurveStyleFontAndScaling::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveStyleFontAndScaling::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveStyleFontAndScaling, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCurveStyleFontAndScaling, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_CurveFont = IfcCurveStyleFontSelect::readStepData( args[1], map );
			m_CurveFontScaling = IfcPositiveRatioMeasure::readStepData( args[2] );
		}
		void IfcCurveStyleFontAndScaling::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcCurveStyleFontAndScaling::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
