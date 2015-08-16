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
#include "include/IfcBSplineSurfaceForm.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcKnotType.h"
#include "include/IfcLogical.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcRationalBSplineSurfaceWithKnots.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcRationalBSplineSurfaceWithKnots 
		IfcRationalBSplineSurfaceWithKnots::IfcRationalBSplineSurfaceWithKnots() { m_entity_enum = IFCRATIONALBSPLINESURFACEWITHKNOTS; }
		IfcRationalBSplineSurfaceWithKnots::IfcRationalBSplineSurfaceWithKnots( int id ) { m_id = id; m_entity_enum = IFCRATIONALBSPLINESURFACEWITHKNOTS; }
		IfcRationalBSplineSurfaceWithKnots::~IfcRationalBSplineSurfaceWithKnots() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRationalBSplineSurfaceWithKnots::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcRationalBSplineSurfaceWithKnots> other = dynamic_pointer_cast<IfcRationalBSplineSurfaceWithKnots>(other_entity);
			if( !other) { return; }
			m_UDegree = other->m_UDegree;
			m_VDegree = other->m_VDegree;
			m_ControlPointsList = other->m_ControlPointsList;
			m_SurfaceForm = other->m_SurfaceForm;
			m_UClosed = other->m_UClosed;
			m_VClosed = other->m_VClosed;
			m_SelfIntersect = other->m_SelfIntersect;
			m_UMultiplicities = other->m_UMultiplicities;
			m_VMultiplicities = other->m_VMultiplicities;
			m_UKnots = other->m_UKnots;
			m_VKnots = other->m_VKnots;
			m_KnotSpec = other->m_KnotSpec;
			m_WeightsData = other->m_WeightsData;
		}
		void IfcRationalBSplineSurfaceWithKnots::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCRATIONALBSPLINESURFACEWITHKNOTS" << "(";
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
			stream << ",";
			writeIntList( stream, m_UMultiplicities );
			stream << ",";
			writeIntList( stream, m_VMultiplicities );
			stream << ",";
			writeTypeOfRealList( stream, m_UKnots );
			stream << ",";
			writeTypeOfRealList( stream, m_VKnots );
			stream << ",";
			if( m_KnotSpec ) { m_KnotSpec->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList2D( stream, m_WeightsData );
			stream << ");";
		}
		void IfcRationalBSplineSurfaceWithKnots::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRationalBSplineSurfaceWithKnots::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<13 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRationalBSplineSurfaceWithKnots, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>13 ){ std::cout << "Wrong parameter count for entity IfcRationalBSplineSurfaceWithKnots, expecting 13, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readIntValue( args[0], m_UDegree );
			readIntValue( args[1], m_VDegree );
			readEntityReferenceList2D( args[2], m_ControlPointsList, map );
			m_SurfaceForm = IfcBSplineSurfaceForm::readStepData( args[3] );
			m_UClosed = IfcLogical::readStepData( args[4] );
			m_VClosed = IfcLogical::readStepData( args[5] );
			m_SelfIntersect = IfcLogical::readStepData( args[6] );
			readIntList(  args[7], m_UMultiplicities );
			readIntList(  args[8], m_VMultiplicities );
			readTypeOfRealList( args[9], m_UKnots );
			readTypeOfRealList( args[10], m_VKnots );
			m_KnotSpec = IfcKnotType::readStepData( args[11] );
			readTypeOfRealList2D( args[12], m_WeightsData );
		}
		void IfcRationalBSplineSurfaceWithKnots::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcBSplineSurfaceWithKnots::setInverseCounterparts( ptr_self_entity );
		}
		void IfcRationalBSplineSurfaceWithKnots::unlinkSelf()
		{
			IfcBSplineSurfaceWithKnots::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
