/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcCurveStyleFontAndScaling.h"
#include "include/IfcCurveStyleFontSelect.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveRatioMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCurveStyleFontAndScaling 
		IfcCurveStyleFontAndScaling::IfcCurveStyleFontAndScaling() { m_entity_enum = IFCCURVESTYLEFONTANDSCALING; }
		IfcCurveStyleFontAndScaling::IfcCurveStyleFontAndScaling( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLEFONTANDSCALING; }
		IfcCurveStyleFontAndScaling::~IfcCurveStyleFontAndScaling() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveStyleFontAndScaling::setEntity( shared_ptr<IfcRoadEntity> other_entity )
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
		void IfcCurveStyleFontAndScaling::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveStyleFontAndScaling, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcCurveStyleFontAndScaling, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_CurveFont = IfcCurveStyleFontSelect::readStepData( args[1], map );
			m_CurveFontScaling = IfcPositiveRatioMeasure::readStepData( args[2] );
		}
		void IfcCurveStyleFontAndScaling::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcPresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveStyleFontAndScaling::unlinkSelf()
		{
			IfcPresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
