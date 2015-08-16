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
#include "include/IfcApproval.h"
#include "include/IfcApprovalPropertyRelationship.h"
#include "include/IfcProperty.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcApprovalPropertyRelationship 
		IfcApprovalPropertyRelationship::IfcApprovalPropertyRelationship() { m_entity_enum = IFCAPPROVALPROPERTYRELATIONSHIP; }
		IfcApprovalPropertyRelationship::IfcApprovalPropertyRelationship( int id ) { m_id = id; m_entity_enum = IFCAPPROVALPROPERTYRELATIONSHIP; }
		IfcApprovalPropertyRelationship::~IfcApprovalPropertyRelationship() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcApprovalPropertyRelationship::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcApprovalPropertyRelationship> other = dynamic_pointer_cast<IfcApprovalPropertyRelationship>(other_entity);
			if( !other) { return; }
			m_ApprovedProperties = other->m_ApprovedProperties;
			m_Approval = other->m_Approval;
		}
		void IfcApprovalPropertyRelationship::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCAPPROVALPROPERTYRELATIONSHIP" << "(";
			writeEntityList( stream, m_ApprovedProperties );
			stream << ",";
			if( m_Approval ) { stream << "#" << m_Approval->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcApprovalPropertyRelationship::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcApprovalPropertyRelationship::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcApprovalPropertyRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcApprovalPropertyRelationship, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_ApprovedProperties, map );
			readEntityReference( args[1], m_Approval, map );
		}
		void IfcApprovalPropertyRelationship::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcApprovalPropertyRelationship::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
