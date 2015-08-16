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
#include "include/IfcDocumentInformation.h"
#include "include/IfcDocumentReference.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcDocumentReference 
		IfcDocumentReference::IfcDocumentReference() { m_entity_enum = IFCDOCUMENTREFERENCE; }
		IfcDocumentReference::IfcDocumentReference( int id ) { m_id = id; m_entity_enum = IFCDOCUMENTREFERENCE; }
		IfcDocumentReference::~IfcDocumentReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcDocumentReference::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcDocumentReference> other = dynamic_pointer_cast<IfcDocumentReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_ItemReference = other->m_ItemReference;
			m_Name = other->m_Name;
		}
		void IfcDocumentReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCDOCUMENTREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ItemReference ) { m_ItemReference->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcDocumentReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcDocumentReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcDocumentReference, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcDocumentReference, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcLabel::readStepData( args[0] );
			m_ItemReference = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcDocumentReference::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcDocumentReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
