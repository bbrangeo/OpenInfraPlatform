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
#include "include/IfcClassification.h"
#include "include/IfcClassificationReference.h"
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcClassificationReference 
		IfcClassificationReference::IfcClassificationReference() { m_entity_enum = IFCCLASSIFICATIONREFERENCE; }
		IfcClassificationReference::IfcClassificationReference( int id ) { m_id = id; m_entity_enum = IFCCLASSIFICATIONREFERENCE; }
		IfcClassificationReference::~IfcClassificationReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClassificationReference::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcClassificationReference> other = dynamic_pointer_cast<IfcClassificationReference>(other_entity);
			if( !other) { return; }
			m_Location = other->m_Location;
			m_ItemReference = other->m_ItemReference;
			m_Name = other->m_Name;
			m_ReferencedSource = other->m_ReferencedSource;
		}
		void IfcClassificationReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLASSIFICATIONREFERENCE" << "(";
			if( m_Location ) { m_Location->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ItemReference ) { m_ItemReference->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ReferencedSource ) { stream << "#" << m_ReferencedSource->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcClassificationReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClassificationReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClassificationReference, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcClassificationReference, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Location = IfcLabel::readStepData( args[0] );
			m_ItemReference = IfcIdentifier::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
			readEntityReference( args[3], m_ReferencedSource, map );
		}
		void IfcClassificationReference::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcExternalReference::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClassificationReference::unlinkSelf()
		{
			IfcExternalReference::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
