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
#include "include/IfcCrossSlopePoint.h"
#include "include/IfcReal.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCrossSlopePoint 
		IfcCrossSlopePoint::IfcCrossSlopePoint() { m_entity_enum = IFCCROSSSLOPEPOINT; }
		IfcCrossSlopePoint::IfcCrossSlopePoint( int id ) { m_id = id; m_entity_enum = IFCCROSSSLOPEPOINT; }
		IfcCrossSlopePoint::~IfcCrossSlopePoint() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCrossSlopePoint::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCrossSlopePoint> other = dynamic_pointer_cast<IfcCrossSlopePoint>(other_entity);
			if( !other) { return; }
			m_SlopeInPercenatge = other->m_SlopeInPercenatge;
			m_Station = other->m_Station;
		}
		void IfcCrossSlopePoint::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCROSSSLOPEPOINT" << "(";
			if( m_SlopeInPercenatge ) { m_SlopeInPercenatge->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Station ) { m_Station->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCrossSlopePoint::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCrossSlopePoint::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCrossSlopePoint, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCrossSlopePoint, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_SlopeInPercenatge = IfcReal::readStepData( args[0] );
			m_Station = IfcReal::readStepData( args[1] );
		}
		void IfcCrossSlopePoint::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcCrossSlopePoint::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
