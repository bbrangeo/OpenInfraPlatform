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
#include "include/IfcCartesianPoint.h"
#include "include/IfcCartesianTransformationOperator3D.h"
#include "include/IfcDirection.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCartesianTransformationOperator3D 
		IfcCartesianTransformationOperator3D::IfcCartesianTransformationOperator3D() { m_entity_enum = IFCCARTESIANTRANSFORMATIONOPERATOR3D; }
		IfcCartesianTransformationOperator3D::IfcCartesianTransformationOperator3D( int id ) { m_id = id; m_entity_enum = IFCCARTESIANTRANSFORMATIONOPERATOR3D; }
		IfcCartesianTransformationOperator3D::~IfcCartesianTransformationOperator3D() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianTransformationOperator3D::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCartesianTransformationOperator3D> other = dynamic_pointer_cast<IfcCartesianTransformationOperator3D>(other_entity);
			if( !other) { return; }
			m_Axis1 = other->m_Axis1;
			m_Axis2 = other->m_Axis2;
			m_LocalOrigin = other->m_LocalOrigin;
			m_Scale = other->m_Scale;
			m_Axis3 = other->m_Axis3;
		}
		void IfcCartesianTransformationOperator3D::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCARTESIANTRANSFORMATIONOPERATOR3D" << "(";
			if( m_Axis1 ) { stream << "#" << m_Axis1->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Axis2 ) { stream << "#" << m_Axis2->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LocalOrigin ) { stream << "#" << m_LocalOrigin->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Scale ) { m_Scale->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Axis3 ) { stream << "#" << m_Axis3->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCartesianTransformationOperator3D::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCartesianTransformationOperator3D::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianTransformationOperator3D, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcCartesianTransformationOperator3D, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Axis1, map );
			readEntityReference( args[1], m_Axis2, map );
			readEntityReference( args[2], m_LocalOrigin, map );
			m_Scale = IfcReal::readStepData( args[3] );
			readEntityReference( args[4], m_Axis3, map );
		}
		void IfcCartesianTransformationOperator3D::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcCartesianTransformationOperator::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianTransformationOperator3D::unlinkSelf()
		{
			IfcCartesianTransformationOperator::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
