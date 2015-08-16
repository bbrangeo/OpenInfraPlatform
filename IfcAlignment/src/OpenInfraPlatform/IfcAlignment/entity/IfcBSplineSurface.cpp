/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcBSplineSurface.h"
#include "include/IfcBSplineSurfaceForm.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcLogical.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcBSplineSurface 
		IfcBSplineSurface::IfcBSplineSurface() { m_entity_enum = IFCBSPLINESURFACE; }
		IfcBSplineSurface::IfcBSplineSurface( int id ) { m_id = id; m_entity_enum = IFCBSPLINESURFACE; }
		IfcBSplineSurface::~IfcBSplineSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBSplineSurface::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcBSplineSurface> other = dynamic_pointer_cast<IfcBSplineSurface>(other_entity);
			if( !other) { return; }
			m_UDegree = other->m_UDegree;
			m_VDegree = other->m_VDegree;
			m_ControlPointsList = other->m_ControlPointsList;
			m_SurfaceForm = other->m_SurfaceForm;
			m_UClosed = other->m_UClosed;
			m_VClosed = other->m_VClosed;
			m_SelfIntersect = other->m_SelfIntersect;
		}
		void IfcBSplineSurface::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBSPLINESURFACE" << "(";
			if( m_UDegree == m_UDegree ){ stream << m_UDegree; }
			else { stream << "$"; }
			stream << ",";
			if( m_VDegree == m_VDegree ){ stream << m_VDegree; }
			else { stream << "$"; }
			stream << ",";
			writeEntityList2D( stream, m_ControlPointsList );
			stream << ",";
			if( m_SurfaceForm ) { m_SurfaceForm->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UClosed ) { m_UClosed->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_VClosed ) { m_VClosed->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_SelfIntersect ) { m_SelfIntersect->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcBSplineSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBSplineSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBSplineSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBSplineSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readIntValue( args[0], m_UDegree );
			readIntValue( args[1], m_VDegree );
			readEntityReferenceList2D( args[2], m_ControlPointsList, map );
			m_SurfaceForm = IfcBSplineSurfaceForm::readStepData( args[3] );
			m_UClosed = IfcLogical::readStepData( args[4] );
			m_VClosed = IfcLogical::readStepData( args[5] );
			m_SelfIntersect = IfcLogical::readStepData( args[6] );
		}
		void IfcBSplineSurface::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcBoundedSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBSplineSurface::unlinkSelf()
		{
			IfcBoundedSurface::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
