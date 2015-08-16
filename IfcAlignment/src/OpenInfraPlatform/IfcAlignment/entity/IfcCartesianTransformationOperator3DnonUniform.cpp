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
#include "include/IfcCartesianPoint.h"
#include "include/IfcCartesianTransformationOperator3DnonUniform.h"
#include "include/IfcDirection.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcReal.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcCartesianTransformationOperator3DnonUniform 
		IfcCartesianTransformationOperator3DnonUniform::IfcCartesianTransformationOperator3DnonUniform() { m_entity_enum = IFCCARTESIANTRANSFORMATIONOPERATOR3DNONUNIFORM; }
		IfcCartesianTransformationOperator3DnonUniform::IfcCartesianTransformationOperator3DnonUniform( int id ) { m_id = id; m_entity_enum = IFCCARTESIANTRANSFORMATIONOPERATOR3DNONUNIFORM; }
		IfcCartesianTransformationOperator3DnonUniform::~IfcCartesianTransformationOperator3DnonUniform() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCartesianTransformationOperator3DnonUniform::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcCartesianTransformationOperator3DnonUniform> other = dynamic_pointer_cast<IfcCartesianTransformationOperator3DnonUniform>(other_entity);
			if( !other) { return; }
			m_Axis1 = other->m_Axis1;
			m_Axis2 = other->m_Axis2;
			m_LocalOrigin = other->m_LocalOrigin;
			m_Scale = other->m_Scale;
			m_Axis3 = other->m_Axis3;
			m_Scale2 = other->m_Scale2;
			m_Scale3 = other->m_Scale3;
		}
		void IfcCartesianTransformationOperator3DnonUniform::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCARTESIANTRANSFORMATIONOPERATOR3DNONUNIFORM" << "(";
			if( m_Axis1 ) { stream << "#" << m_Axis1->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Axis2 ) { stream << "#" << m_Axis2->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_LocalOrigin ) { stream << "#" << m_LocalOrigin->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Scale ) { m_Scale->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Axis3 ) { stream << "#" << m_Axis3->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Scale2 ) { m_Scale2->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Scale3 ) { m_Scale3->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCartesianTransformationOperator3DnonUniform::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCartesianTransformationOperator3DnonUniform::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCartesianTransformationOperator3DnonUniform, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcCartesianTransformationOperator3DnonUniform, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Axis1, map );
			readEntityReference( args[1], m_Axis2, map );
			readEntityReference( args[2], m_LocalOrigin, map );
			m_Scale = IfcReal::readStepData( args[3] );
			readEntityReference( args[4], m_Axis3, map );
			m_Scale2 = IfcReal::readStepData( args[5] );
			m_Scale3 = IfcReal::readStepData( args[6] );
		}
		void IfcCartesianTransformationOperator3DnonUniform::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcCartesianTransformationOperator3D::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCartesianTransformationOperator3DnonUniform::unlinkSelf()
		{
			IfcCartesianTransformationOperator3D::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
