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
#include "include/IfcClosedShell.h"
#include "include/IfcFace.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcClosedShell 
		IfcClosedShell::IfcClosedShell() { m_entity_enum = IFCCLOSEDSHELL; }
		IfcClosedShell::IfcClosedShell( int id ) { m_id = id; m_entity_enum = IFCCLOSEDSHELL; }
		IfcClosedShell::~IfcClosedShell() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClosedShell::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcClosedShell::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClosedShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcClosedShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_CfsFaces, map );
		}
		void IfcClosedShell::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcConnectedFaceSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClosedShell::unlinkSelf()
		{
			IfcConnectedFaceSet::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
