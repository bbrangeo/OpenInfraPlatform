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
#include "include/IfcCoordinateOperation.h"
#include "include/IfcCoordinateReferenceSystem.h"
#include "include/IfcCoordinateReferenceSystemSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcCoordinateOperation 
		IfcCoordinateOperation::IfcCoordinateOperation() { m_entity_enum = IFCCOORDINATEOPERATION; }
		IfcCoordinateOperation::IfcCoordinateOperation( int id ) { m_id = id; m_entity_enum = IFCCOORDINATEOPERATION; }
		IfcCoordinateOperation::~IfcCoordinateOperation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCoordinateOperation::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcCoordinateOperation> other = dynamic_pointer_cast<IfcCoordinateOperation>(other_entity);
			if( !other) { return; }
			m_SourceCRS = other->m_SourceCRS;
			m_TargetCRS = other->m_TargetCRS;
		}
		void IfcCoordinateOperation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCOORDINATEOPERATION" << "(";
			if( m_SourceCRS ) { m_SourceCRS->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_TargetCRS ) { stream << "#" << m_TargetCRS->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCoordinateOperation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCoordinateOperation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCoordinateOperation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCoordinateOperation, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SourceCRS = IfcCoordinateReferenceSystemSelect::readStepData( args[0], map );
			readEntityReference( args[1], m_TargetCRS, map );
		}
		void IfcCoordinateOperation::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcCoordinateOperation::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
