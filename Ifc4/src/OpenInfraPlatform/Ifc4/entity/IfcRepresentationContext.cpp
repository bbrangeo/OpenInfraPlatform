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
#include "include/IfcLabel.h"
#include "include/IfcRepresentation.h"
#include "include/IfcRepresentationContext.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcRepresentationContext 
		IfcRepresentationContext::IfcRepresentationContext() { m_entity_enum = IFCREPRESENTATIONCONTEXT; }
		IfcRepresentationContext::IfcRepresentationContext( int id ) { m_id = id; m_entity_enum = IFCREPRESENTATIONCONTEXT; }
		IfcRepresentationContext::~IfcRepresentationContext() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRepresentationContext::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcRepresentationContext> other = dynamic_pointer_cast<IfcRepresentationContext>(other_entity);
			if( !other) { return; }
			m_ContextIdentifier = other->m_ContextIdentifier;
			m_ContextType = other->m_ContextType;
		}
		void IfcRepresentationContext::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREPRESENTATIONCONTEXT" << "(";
			if( m_ContextIdentifier ) { m_ContextIdentifier->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ContextType ) { m_ContextType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRepresentationContext::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRepresentationContext::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRepresentationContext, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcRepresentationContext, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ContextIdentifier = IfcLabel::readStepData( args[0] );
			m_ContextType = IfcLabel::readStepData( args[1] );
		}
		void IfcRepresentationContext::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcRepresentationContext::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
