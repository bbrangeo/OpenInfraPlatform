/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcLibraryInformation.h"
#include "include/IfcLibraryReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcLibraryReference 
		IfcLibraryReference::IfcLibraryReference() { m_entity_enum = IFCLIBRARYREFERENCE; }
		IfcLibraryReference::IfcLibraryReference( int id ) { m_id = id; m_entity_enum = IFCLIBRARYREFERENCE; }
		IfcLibraryReference::~IfcLibraryReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcLibraryReference::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcLibraryReference> other = dynamic_pointer_cast<IfcLibraryReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_ItemReference = other->m_ItemReference;
			m_Name = other->m_Name;
		}
		void IfcLibraryReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCLIBRARYREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ItemReference ) { m_ItemReference->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcLibraryReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcLibraryReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcLibraryReference, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcLibraryReference, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcLabel::readStepData( args[0] );
			m_ItemReference = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcLibraryReference::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcLibraryReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
