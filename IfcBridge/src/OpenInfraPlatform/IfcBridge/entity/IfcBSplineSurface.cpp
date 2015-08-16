/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcBSplineSurface.h"
#include "include/IfcBSplineSurfaceForm.h"
#include "include/IfcCartesianPoint.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcBSplineSurface 
		IfcBSplineSurface::IfcBSplineSurface() { m_entity_enum = IFCBSPLINESURFACE; }
		IfcBSplineSurface::IfcBSplineSurface( int id ) { m_id = id; m_entity_enum = IFCBSPLINESURFACE; }
		IfcBSplineSurface::~IfcBSplineSurface() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBSplineSurface::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
			if( m_UClosed == false ) { stream << ".F."; }
			else if( m_UClosed == true ) { stream << ".T."; }
			stream << ",";
			if( m_VClosed == false ) { stream << ".F."; }
			else if( m_VClosed == true ) { stream << ".T."; }
			stream << ",";
			if( m_SelfIntersect == false ) { stream << ".F."; }
			else if( m_SelfIntersect == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcBSplineSurface::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBSplineSurface::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcBSplineSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcBSplineSurface, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readIntValue( args[0], m_UDegree );
			readIntValue( args[1], m_VDegree );
			readEntityReferenceList2D( args[2], m_ControlPointsList, map );
			m_SurfaceForm = IfcBSplineSurfaceForm::readStepData( args[3] );
			if( _stricmp( args[4].c_str(), ".F." ) == 0 ) { m_UClosed = false; }
			else if( _stricmp( args[4].c_str(), ".T." ) == 0 ) { m_UClosed = true; }
			if( _stricmp( args[5].c_str(), ".F." ) == 0 ) { m_VClosed = false; }
			else if( _stricmp( args[5].c_str(), ".T." ) == 0 ) { m_VClosed = true; }
			if( _stricmp( args[6].c_str(), ".F." ) == 0 ) { m_SelfIntersect = false; }
			else if( _stricmp( args[6].c_str(), ".T." ) == 0 ) { m_SelfIntersect = true; }
		}
		void IfcBSplineSurface::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcBoundedSurface::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBSplineSurface::unlinkSelf()
		{
			IfcBoundedSurface::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
