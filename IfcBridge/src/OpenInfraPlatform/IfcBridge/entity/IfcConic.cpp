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
#include "include/IfcConic.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcConic 
		IfcConic::IfcConic() { m_entity_enum = IFCCONIC; }
		IfcConic::IfcConic( int id ) { m_id = id; m_entity_enum = IFCCONIC; }
		IfcConic::~IfcConic() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConic::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcConic> other = dynamic_pointer_cast<IfcConic>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
		}
		void IfcConic::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONIC" << "(";
			if( m_Position ) { m_Position->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConic::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConic::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcConic, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Position = IfcAxis2Placement::readStepData( args[0], map );
		}
		void IfcConic::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConic::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
