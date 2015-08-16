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
#include "include/IfcCrossSection.h"
#include "include/IfcRoadBody.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRoadBody 
		IfcRoadBody::IfcRoadBody() { m_entity_enum = IFCROADBODY; }
		IfcRoadBody::IfcRoadBody( int id ) { m_id = id; m_entity_enum = IFCROADBODY; }
		IfcRoadBody::~IfcRoadBody() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRoadBody::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRoadBody> other = dynamic_pointer_cast<IfcRoadBody>(other_entity);
			if( !other) { return; }
			m_CrossSections = other->m_CrossSections;
		}
		void IfcRoadBody::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCROADBODY" << "(";
			writeEntityList( stream, m_CrossSections );
			stream << ");";
		}
		void IfcRoadBody::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRoadBody::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRoadBody, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcRoadBody, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_CrossSections, map );
		}
		void IfcRoadBody::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcRoadBody::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
