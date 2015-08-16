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
#include "include/IfcFace.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcClosedShell 
		IfcClosedShell::IfcClosedShell() { m_entity_enum = IFCCLOSEDSHELL; }
		IfcClosedShell::IfcClosedShell( int id ) { m_id = id; m_entity_enum = IFCCLOSEDSHELL; }
		IfcClosedShell::~IfcClosedShell() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClosedShell::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcClosedShell> other = dynamic_pointer_cast<IfcClosedShell>(other_entity);
			if( !other) { return; }
			m_CfsFaces = other->m_CfsFaces;
		}
		void IfcClosedShell::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLOSEDSHELL" << "(";
			writeEntityList( stream, m_CfsFaces );
			stream << ");";
		}
		void IfcClosedShell::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClosedShell::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClosedShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcClosedShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_CfsFaces, map );
		}
		void IfcClosedShell::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcConnectedFaceSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClosedShell::unlinkSelf()
		{
			IfcConnectedFaceSet::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
