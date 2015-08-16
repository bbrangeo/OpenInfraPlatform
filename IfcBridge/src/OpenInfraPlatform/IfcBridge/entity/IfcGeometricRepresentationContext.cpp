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
#include "include/IfcAxis2Placement.h"
#include "include/IfcDimensionCount.h"
#include "include/IfcDirection.h"
#include "include/IfcGeometricRepresentationContext.h"
#include "include/IfcGeometricRepresentationSubContext.h"
#include "include/IfcLabel.h"
#include "include/IfcRepresentation.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcGeometricRepresentationContext 
		IfcGeometricRepresentationContext::IfcGeometricRepresentationContext() { m_entity_enum = IFCGEOMETRICREPRESENTATIONCONTEXT; }
		IfcGeometricRepresentationContext::IfcGeometricRepresentationContext( int id ) { m_id = id; m_entity_enum = IFCGEOMETRICREPRESENTATIONCONTEXT; }
		IfcGeometricRepresentationContext::~IfcGeometricRepresentationContext() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcGeometricRepresentationContext::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcGeometricRepresentationContext> other = dynamic_pointer_cast<IfcGeometricRepresentationContext>(other_entity);
			if( !other) { return; }
			m_ContextIdentifier = other->m_ContextIdentifier;
			m_ContextType = other->m_ContextType;
			m_CoordinateSpaceDimension = other->m_CoordinateSpaceDimension;
			m_Precision = other->m_Precision;
			m_WorldCoordinateSystem = other->m_WorldCoordinateSystem;
			m_TrueNorth = other->m_TrueNorth;
		}
		void IfcGeometricRepresentationContext::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCGEOMETRICREPRESENTATIONCONTEXT" << "(";
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
			stream << ");";
		}
		void IfcGeometricRepresentationContext::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcGeometricRepresentationContext::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcGeometricRepresentationContext, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcGeometricRepresentationContext, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ContextIdentifier = IfcLabel::readStepData( args[0] );
			m_ContextType = IfcLabel::readStepData( args[1] );
			m_CoordinateSpaceDimension = IfcDimensionCount::readStepData( args[2] );
			readRealValue( args[3], m_Precision );
			m_WorldCoordinateSystem = IfcAxis2Placement::readStepData( args[4], map );
			readEntityReference( args[5], m_TrueNorth, map );
		}
		void IfcGeometricRepresentationContext::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcRepresentationContext::setInverseCounterparts( ptr_self_entity );
		}
		void IfcGeometricRepresentationContext::unlinkSelf()
		{
			IfcRepresentationContext::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
