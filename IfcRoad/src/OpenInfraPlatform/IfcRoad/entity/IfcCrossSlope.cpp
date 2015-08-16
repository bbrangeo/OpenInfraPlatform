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
#include "include/IfcCrossSlope.h"
#include "include/IfcCrossSlopePoint.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCrossSlope 
		IfcCrossSlope::IfcCrossSlope() { m_entity_enum = IFCCROSSSLOPE; }
		IfcCrossSlope::IfcCrossSlope( int id ) { m_id = id; m_entity_enum = IFCCROSSSLOPE; }
		IfcCrossSlope::~IfcCrossSlope() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCrossSlope::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCrossSlope> other = dynamic_pointer_cast<IfcCrossSlope>(other_entity);
			if( !other) { return; }
			m_CrossSlopePoint = other->m_CrossSlopePoint;
		}
		void IfcCrossSlope::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCROSSSLOPE" << "(";
			writeEntityList( stream, m_CrossSlopePoint );
			stream << ");";
		}
		void IfcCrossSlope::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCrossSlope::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCrossSlope, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcCrossSlope, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReferenceList( args[0], m_CrossSlopePoint, map );
		}
		void IfcCrossSlope::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcCrossSlope::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
