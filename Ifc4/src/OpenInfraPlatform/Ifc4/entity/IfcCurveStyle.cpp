/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcBoolean.h"
#include "include/IfcColour.h"
#include "include/IfcCurveFontOrScaledCurveFontSelect.h"
#include "include/IfcCurveStyle.h"
#include "include/IfcLabel.h"
#include "include/IfcSizeSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCurveStyle 
		IfcCurveStyle::IfcCurveStyle() { m_entity_enum = IFCCURVESTYLE; }
		IfcCurveStyle::IfcCurveStyle( int id ) { m_id = id; m_entity_enum = IFCCURVESTYLE; }
		IfcCurveStyle::~IfcCurveStyle() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurveStyle::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCurveStyle> other = dynamic_pointer_cast<IfcCurveStyle>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_CurveFont = other->m_CurveFont;
			m_CurveWidth = other->m_CurveWidth;
			m_CurveColour = other->m_CurveColour;
			m_ModelOrDraughting = other->m_ModelOrDraughting;
		}
		void IfcCurveStyle::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVESTYLE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveFont ) { m_CurveFont->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveWidth ) { m_CurveWidth->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_CurveColour ) { m_CurveColour->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ModelOrDraughting ) { m_ModelOrDraughting->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCurveStyle::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurveStyle::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCurveStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcCurveStyle, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_CurveFont = IfcCurveFontOrScaledCurveFontSelect::readStepData( args[1], map );
			m_CurveWidth = IfcSizeSelect::readStepData( args[2], map );
			m_CurveColour = IfcColour::readStepData( args[3], map );
			m_ModelOrDraughting = IfcBoolean::readStepData( args[4] );
		}
		void IfcCurveStyle::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcPresentationStyle::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurveStyle::unlinkSelf()
		{
			IfcPresentationStyle::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
