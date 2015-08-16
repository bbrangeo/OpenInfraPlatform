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
#include "include/IfcCartesianPointList3D.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcCartesianPointList3D 
		IfcCartesianPointList3D::IfcCartesianPointList3D() { m_entity_enum = IFCCARTESIANPOINTLIST3D; }
		IfcCartesianPointList3D::IfcCartesianPointList3D( int id ) { m_id = id; m_entity_enum = IFCCARTESIANPOINTLIST3D; }
		IfcCartesianPointList3D::~IfcCartesianPointList3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianPointList3D::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcCartesianPointList3D> other = dynamic_pointer_cast<IfcCartesianPointList3D>(other_entity);
			if( !other) { return; }
			m_CoordList = other->m_CoordList;
		}
		void IfcCartesianPointList3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCARTESIANPOINTLIST3D" << "(";
			writeTypeOfRealList2D( stream, m_CoordList );
			stream << ");";
		}
		void IfcCartesianPointList3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCartesianPointList3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianPointList3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCartesianPointList3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList2D( args[0], m_CoordList );
		}
		void IfcCartesianPointList3D::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcCartesianPointList::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianPointList3D::unlinkSelf()
		{
			IfcCartesianPointList::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
