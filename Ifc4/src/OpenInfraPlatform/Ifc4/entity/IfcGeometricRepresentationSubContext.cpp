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
#include "include/IfcAxis2Placement.h"
#include "include/IfcCoordinateOperation.h"
#include "include/IfcDimensionCount.h"
#include "include/IfcDirection.h"
#include "include/IfcGeometricProjectionEnum.h"
#include "include/IfcGeometricRepresentationContext.h"
#include "include/IfcGeometricRepresentationSubContext.h"
#include "include/IfcLabel.h"
#include "include/IfcPositiveRatioMeasure.h"
#include "include/IfcRepresentation.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcGeometricRepresentationSubContext 
		IfcGeometricRepresentationSubContext::IfcGeometricRepresentationSubContext() { m_entity_enum = IFCGEOMETRICREPRESENTATIONSUBCONTEXT; }
		IfcGeometricRepresentationSubContext::IfcGeometricRepresentationSubContext( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICREPRESENTATIONSUBCONTEXT; }
		IfcGeometricRepresentationSubContext::~IfcGeometricRepresentationSubContext() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeometricRepresentationSubContext::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcGeometricRepresentationSubContext> other = dynamic_pointer_cast<IfcGeometricRepresentationSubContext>(other_entity);
			if( !other) { return; }
			m_ContextIdentifier = other->m_ContextIdentifier;
			m_ContextType = other->m_ContextType;
			m_CoordinateSpaceDimension = other->m_CoordinateSpaceDimension;
			m_Precision = other->m_Precision;
			m_WorldCoordinateSystem = other->m_WorldCoordinateSystem;
			m_TrueNorth = other->m_TrueNorth;
			m_ParentContext = other->m_ParentContext;
			m_TargetScale = other->m_TargetScale;
			m_TargetView = other->m_TargetView;
			m_UserDefinedTargetView = other->m_UserDefinedTargetView;
		}
		void IfcGeometricRepresentationSubContext::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGEOMETRICREPRESENTATIONSUBCONTEXT" << "(";
			if( m_ContextIdentifier ) { m_ContextIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ContextType ) { m_ContextType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CoordinateSpaceDimension ) { m_CoordinateSpaceDimension->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Precision == m_Precision ){ stream << m_Precision; }
			else { stream << "$"; }
			stream << ",";
			if( m_WorldCoordinateSystem ) { m_WorldCoordinateSystem->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TrueNorth ) { stream << "#" << m_TrueNorth->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ParentContext ) { stream << "#" << m_ParentContext->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_TargetScale ) { m_TargetScale->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TargetView ) { m_TargetView->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedTargetView ) { m_UserDefinedTargetView->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcGeometricRepresentationSubContext::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeometricRepresentationSubContext::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<10 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGeometricRepresentationSubContext, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>10 ){ std::cout << "Wrong parameter count for entity IfcGeometricRepresentationSubContext, expecting 10, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ContextIdentifier = IfcLabel::readStepData( args[0] );
			m_ContextType = IfcLabel::readStepData( args[1] );
			m_CoordinateSpaceDimension = IfcDimensionCount::readStepData( args[2] );
			readRealValue( args[3], m_Precision );
			m_WorldCoordinateSystem = IfcAxis2Placement::readStepData( args[4], map );
			readEntityReference( args[5], m_TrueNorth, map );
			readEntityReference( args[6], m_ParentContext, map );
			m_TargetScale = IfcPositiveRatioMeasure::readStepData( args[7] );
			m_TargetView = IfcGeometricProjectionEnum::readStepData( args[8] );
			m_UserDefinedTargetView = IfcLabel::readStepData( args[9] );
		}
		void IfcGeometricRepresentationSubContext::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationContext::setInverseCounterparts( ptr_self_entity );
			shared_ptr<IfcGeometricRepresentationSubContext> ptr_self = dynamic_pointer_cast<IfcGeometricRepresentationSubContext>( ptr_self_entity );
			if( !ptr_self ) { throw Ifc4Exception( "IfcGeometricRepresentationSubContext::setInverseCounterparts: type mismatch" ); }
			if( m_ParentContext )
			{
				m_ParentContext->m_HasSubContexts_inverse.push_back( ptr_self );
			}
		}
		void IfcGeometricRepresentationSubContext::unlinkSelf()
		{
			IfcGeometricRepresentationContext::unlinkSelf();
			if( m_ParentContext )
			{
				std::vector<weak_ptr<IfcGeometricRepresentationSubContext> >& HasSubContexts_inverse = m_ParentContext->m_HasSubContexts_inverse;
				std::vector<weak_ptr<IfcGeometricRepresentationSubContext> >::iterator it_HasSubContexts_inverse;
				for( it_HasSubContexts_inverse = HasSubContexts_inverse.begin(); it_HasSubContexts_inverse != HasSubContexts_inverse.end(); ++it_HasSubContexts_inverse)
				{
					shared_ptr<IfcGeometricRepresentationSubContext> self_candidate( *it_HasSubContexts_inverse );
					if( self_candidate->getId() == this->getId() )
					{
						HasSubContexts_inverse.erase( it_HasSubContexts_inverse );
						break;
					}
				}
			}
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
