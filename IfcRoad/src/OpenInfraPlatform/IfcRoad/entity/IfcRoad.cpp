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
#include "include/IfcAlignment.h"
#include "include/IfcCrossSlope.h"
#include "include/IfcRoad.h"
#include "include/IfcRoadBody.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcRoad 
		IfcRoad::IfcRoad() { m_entity_enum = IFCROAD; }
		IfcRoad::IfcRoad( int id ) { m_id = id; m_entity_enum = IFCROAD; }
		IfcRoad::~IfcRoad() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcRoad::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcRoad> other = dynamic_pointer_cast<IfcRoad>(other_entity);
			if( !other) { return; }
			m_Alignment = other->m_Alignment;
			m_Body = other->m_Body;
			m_CrossSlope = other->m_CrossSlope;
		}
		void IfcRoad::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCROAD" << "(";
			if( m_Alignment ) { stream << "#" << m_Alignment->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Body ) { stream << "#" << m_Body->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_CrossSlope ) { stream << "#" << m_CrossSlope->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcRoad::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcRoad::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcRoad, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcRoad, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Alignment, map );
			readEntityReference( args[1], m_Body, map );
			readEntityReference( args[2], m_CrossSlope, map );
		}
		void IfcRoad::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcRoad::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
