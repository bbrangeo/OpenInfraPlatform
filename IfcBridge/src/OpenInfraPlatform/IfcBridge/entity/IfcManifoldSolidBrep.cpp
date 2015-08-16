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
#include "include/IfcClosedShell.h"
#include "include/IfcManifoldSolidBrep.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcManifoldSolidBrep 
		IfcManifoldSolidBrep::IfcManifoldSolidBrep() { m_entity_enum = IFCMANIFOLDSOLIDBREP; }
		IfcManifoldSolidBrep::IfcManifoldSolidBrep( int id ) { m_id = id; m_entity_enum = IFCMANIFOLDSOLIDBREP; }
		IfcManifoldSolidBrep::~IfcManifoldSolidBrep() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcManifoldSolidBrep::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcManifoldSolidBrep> other = dynamic_pointer_cast<IfcManifoldSolidBrep>(other_entity);
			if( !other) { return; }
			m_Outer = other->m_Outer;
		}
		void IfcManifoldSolidBrep::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMANIFOLDSOLIDBREP" << "(";
			if( m_Outer ) { stream << "#" << m_Outer->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcManifoldSolidBrep::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcManifoldSolidBrep::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcManifoldSolidBrep, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcManifoldSolidBrep, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Outer, map );
		}
		void IfcManifoldSolidBrep::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcManifoldSolidBrep::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
