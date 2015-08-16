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
#include "include/IfcFaceBound.h"
#include "include/IfcLoop.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFaceBound 
		IfcFaceBound::IfcFaceBound() { m_entity_enum = IFCFACEBOUND; }
		IfcFaceBound::IfcFaceBound( int id ) { m_id = id; m_entity_enum = IFCFACEBOUND; }
		IfcFaceBound::~IfcFaceBound() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFaceBound::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcFaceBound> other = dynamic_pointer_cast<IfcFaceBound>(other_entity);
			if( !other) { return; }
			m_Bound = other->m_Bound;
			m_Orientation = other->m_Orientation;
		}
		void IfcFaceBound::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFACEBOUND" << "(";
			if( m_Bound ) { stream << "#" << m_Bound->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Orientation == false ) { stream << ".F."; }
			else if( m_Orientation == true ) { stream << ".T."; }
			stream << ");";
		}
		void IfcFaceBound::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFaceBound::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFaceBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcFaceBound, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Bound, map );
			if( _stricmp( args[1].c_str(), ".F." ) == 0 ) { m_Orientation = false; }
			else if( _stricmp( args[1].c_str(), ".T." ) == 0 ) { m_Orientation = true; }
		}
		void IfcFaceBound::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcTopologicalRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFaceBound::unlinkSelf()
		{
			IfcTopologicalRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform