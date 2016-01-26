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
#include "include/IfcCartesianPointList3D.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCartesianPointList3D 
		IfcCartesianPointList3D::IfcCartesianPointList3D() { m_entity_enum = IFCCARTESIANPOINTLIST3D; }
		IfcCartesianPointList3D::IfcCartesianPointList3D( int id ) { m_id = id; m_entity_enum = IFCCARTESIANPOINTLIST3D; }
		IfcCartesianPointList3D::~IfcCartesianPointList3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianPointList3D::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcCartesianPointList3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianPointList3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCartesianPointList3D, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readTypeOfRealList2D( args[0], m_CoordList );
		}
		void IfcCartesianPointList3D::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCartesianPointList::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianPointList3D::unlinkSelf()
		{
			IfcCartesianPointList::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
