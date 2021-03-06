/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcConnectedFaceSet.h"
#include "include/IfcFaceBasedSurfaceModel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcFaceBasedSurfaceModel 
		IfcFaceBasedSurfaceModel::IfcFaceBasedSurfaceModel() { m_entity_enum = IFCFACEBASEDSURFACEMODEL; }
		IfcFaceBasedSurfaceModel::IfcFaceBasedSurfaceModel( int id ) { m_id = id; m_entity_enum = IFCFACEBASEDSURFACEMODEL; }
		IfcFaceBasedSurfaceModel::~IfcFaceBasedSurfaceModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceBasedSurfaceModel::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcFaceBasedSurfaceModel> other = dynamic_pointer_cast<IfcFaceBasedSurfaceModel>(other_entity);
			if( !other) { return; }
			m_FbsmFaces = other->m_FbsmFaces;
		}
		void IfcFaceBasedSurfaceModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACEBASEDSURFACEMODEL" << "(";
			writeEntityList( stream, m_FbsmFaces );
			stream << ");";
		}
		void IfcFaceBasedSurfaceModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceBasedSurfaceModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceBasedSurfaceModel, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcFaceBasedSurfaceModel, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_FbsmFaces, map );
		}
		void IfcFaceBasedSurfaceModel::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceBasedSurfaceModel::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
