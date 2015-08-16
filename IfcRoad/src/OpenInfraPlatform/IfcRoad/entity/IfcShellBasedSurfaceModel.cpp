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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcShell.h"
#include "include/IfcShellBasedSurfaceModel.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcShellBasedSurfaceModel 
		IfcShellBasedSurfaceModel::IfcShellBasedSurfaceModel() { m_entity_enum = IFCSHELLBASEDSURFACEMODEL; }
		IfcShellBasedSurfaceModel::IfcShellBasedSurfaceModel( int id ) { m_id = id; m_entity_enum = IFCSHELLBASEDSURFACEMODEL; }
		IfcShellBasedSurfaceModel::~IfcShellBasedSurfaceModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcShellBasedSurfaceModel::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcShellBasedSurfaceModel> other = dynamic_pointer_cast<IfcShellBasedSurfaceModel>(other_entity);
			if( !other) { return; }
			m_SbsmBoundary = other->m_SbsmBoundary;
		}
		void IfcShellBasedSurfaceModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSHELLBASEDSURFACEMODEL" << "(";
			writeTypeList( stream, m_SbsmBoundary, true );
			stream << ");";
		}
		void IfcShellBasedSurfaceModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcShellBasedSurfaceModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcShellBasedSurfaceModel, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcShellBasedSurfaceModel, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_SbsmBoundary, map );
		}
		void IfcShellBasedSurfaceModel::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcShellBasedSurfaceModel::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
