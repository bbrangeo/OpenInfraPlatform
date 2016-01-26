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
#include "include/IfcIdentifier.h"
#include "include/IfcLabel.h"
#include "include/IfcReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcReference 
		IfcReference::IfcReference() { m_entity_enum = IFCREFERENCE; }
		IfcReference::IfcReference( int id ) { m_id = id; m_entity_enum = IFCREFERENCE; }
		IfcReference::~IfcReference() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReference::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcReference> other = dynamic_pointer_cast<IfcReference>(other_entity);
			if( !other) { return; }
			m_TypeIdentifier = other->m_TypeIdentifier;
			m_AttributeIdentifier = other->m_AttributeIdentifier;
			m_InstanceName = other->m_InstanceName;
			m_ListPositions = other->m_ListPositions;
			m_InnerReference = other->m_InnerReference;
		}
		void IfcReference::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREFERENCE" << "(";
			if( m_TypeIdentifier ) { m_TypeIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_AttributeIdentifier ) { m_AttributeIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_InstanceName ) { m_InstanceName->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeIntList( stream, m_ListPositions );
			stream << ",";
			if( m_InnerReference ) { stream << "#" << m_InnerReference->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcReference::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReference::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReference, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcReference, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TypeIdentifier = IfcIdentifier::readStepData( args[0] );
			m_AttributeIdentifier = IfcIdentifier::readStepData( args[1] );
			m_InstanceName = IfcLabel::readStepData( args[2] );
			readIntList(  args[3], m_ListPositions );
			readEntityReference( args[4], m_InnerReference, map );
		}
		void IfcReference::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcReference::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
