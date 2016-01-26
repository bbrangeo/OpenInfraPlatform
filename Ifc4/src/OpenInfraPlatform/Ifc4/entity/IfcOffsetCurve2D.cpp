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
#include "include/IfcCurve.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcLogical.h"
#include "include/IfcOffsetCurve2D.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcOffsetCurve2D 
		IfcOffsetCurve2D::IfcOffsetCurve2D() { m_entity_enum = IFCOFFSETCURVE2D; }
		IfcOffsetCurve2D::IfcOffsetCurve2D( int id ) { m_id = id; m_entity_enum = IFCOFFSETCURVE2D; }
		IfcOffsetCurve2D::~IfcOffsetCurve2D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOffsetCurve2D::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcOffsetCurve2D> other = dynamic_pointer_cast<IfcOffsetCurve2D>(other_entity);
			if( !other) { return; }
			m_BasisCurve = other->m_BasisCurve;
			m_Distance = other->m_Distance;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcOffsetCurve2D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOFFSETCURVE2D" << "(";
			if( m_BasisCurve ) { stream << "#" << m_BasisCurve->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Distance ) { m_Distance->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcOffsetCurve2D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOffsetCurve2D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOffsetCurve2D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcOffsetCurve2D, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_BasisCurve, map );
			m_Distance = IfcLengthMeasure::readStepData( args[1] );
			m_SelfIntersect = IfcLogical::readStepData( args[2] );
		}
		void IfcOffsetCurve2D::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOffsetCurve2D::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
