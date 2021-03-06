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
#include "include/IfcFailureConnectionCondition.h"
#include "include/IfcForceMeasure.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFailureConnectionCondition 
		IfcFailureConnectionCondition::IfcFailureConnectionCondition() { m_entity_enum = IFCFAILURECONNECTIONCONDITION; }
		IfcFailureConnectionCondition::IfcFailureConnectionCondition( int id ) { m_id = id; m_entity_enum = IFCFAILURECONNECTIONCONDITION; }
		IfcFailureConnectionCondition::~IfcFailureConnectionCondition() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFailureConnectionCondition::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcFailureConnectionCondition> other = dynamic_pointer_cast<IfcFailureConnectionCondition>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_TensionFailureX = other->m_TensionFailureX;
			m_TensionFailureY = other->m_TensionFailureY;
			m_TensionFailureZ = other->m_TensionFailureZ;
			m_CompressionFailureX = other->m_CompressionFailureX;
			m_CompressionFailureY = other->m_CompressionFailureY;
			m_CompressionFailureZ = other->m_CompressionFailureZ;
		}
		void IfcFailureConnectionCondition::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFAILURECONNECTIONCONDITION" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TensionFailureX ) { m_TensionFailureX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TensionFailureY ) { m_TensionFailureY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_TensionFailureZ ) { m_TensionFailureZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CompressionFailureX ) { m_CompressionFailureX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CompressionFailureY ) { m_CompressionFailureY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_CompressionFailureZ ) { m_CompressionFailureZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFailureConnectionCondition::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFailureConnectionCondition::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFailureConnectionCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcFailureConnectionCondition, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_TensionFailureX = IfcForceMeasure::readStepData( args[1] );
			m_TensionFailureY = IfcForceMeasure::readStepData( args[2] );
			m_TensionFailureZ = IfcForceMeasure::readStepData( args[3] );
			m_CompressionFailureX = IfcForceMeasure::readStepData( args[4] );
			m_CompressionFailureY = IfcForceMeasure::readStepData( args[5] );
			m_CompressionFailureZ = IfcForceMeasure::readStepData( args[6] );
		}
		void IfcFailureConnectionCondition::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcStructuralConnectionCondition::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFailureConnectionCondition::unlinkSelf()
		{
			IfcStructuralConnectionCondition::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
