/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcRoad/model/IfcRoadException.h"
#include "OpenInfraPlatform/IfcRoad/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcRoad/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcRoad/IfcRoadEntityEnums.h"
#include "include/IfcFace.h"
#include "include/IfcOpenShell.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcOpenShell 
		IfcOpenShell::IfcOpenShell() { m_entity_enum = IFCOPENSHELL; }
		IfcOpenShell::IfcOpenShell( int id ) { m_id = id; m_entity_enum = IFCOPENSHELL; }
		IfcOpenShell::~IfcOpenShell() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcOpenShell::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcOpenShell> other = dynamic_pointer_cast<IfcOpenShell>(other_entity);
			if( !other) { return; }
			m_CfsFaces = other->m_CfsFaces;
		}
		void IfcOpenShell::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCOPENSHELL" << "(";
			writeEntityList( stream, m_CfsFaces );
			stream << ");";
		}
		void IfcOpenShell::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcOpenShell::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcOpenShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcOpenShell, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_CfsFaces, map );
		}
		void IfcOpenShell::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcConnectedFaceSet::setInverseCounterparts( ptr_self_entity );
		}
		void IfcOpenShell::unlinkSelf()
		{
			IfcConnectedFaceSet::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
