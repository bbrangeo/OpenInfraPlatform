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
#include "include/IfcCsgSelect.h"
#include "include/IfcCsgSolid.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcCsgSolid 
		IfcCsgSolid::IfcCsgSolid() { m_entity_enum = IFCCSGSOLID; }
		IfcCsgSolid::IfcCsgSolid( int id ) { m_id = id; m_entity_enum = IFCCSGSOLID; }
		IfcCsgSolid::~IfcCsgSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCsgSolid::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcCsgSolid> other = dynamic_pointer_cast<IfcCsgSolid>(other_entity);
			if( !other) { return; }
			m_TreeRootExpression = other->m_TreeRootExpression;
		}
		void IfcCsgSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCSGSOLID" << "(";
			if( m_TreeRootExpression ) { m_TreeRootExpression->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCsgSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCsgSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCsgSolid, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCsgSolid, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TreeRootExpression = IfcCsgSelect::readStepData( args[0], map );
		}
		void IfcCsgSolid::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCsgSolid::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
