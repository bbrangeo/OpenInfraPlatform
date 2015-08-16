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
#include "include/IfcCrossSectionGeometry.h"
#include "include/IfcReal.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcCrossSection 
		IfcCrossSection::IfcCrossSection() { m_entity_enum = IFCCROSSSECTION; }
		IfcCrossSection::IfcCrossSection( int id ) { m_id = id; m_entity_enum = IFCCROSSSECTION; }
		IfcCrossSection::~IfcCrossSection() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCrossSection::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcCrossSection> other = dynamic_pointer_cast<IfcCrossSection>(other_entity);
			if( !other) { return; }
			m_Station = other->m_Station;
			m_Geometry = other->m_Geometry;
		}
		void IfcCrossSection::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCROSSSECTION" << "(";
			if( m_Station ) { m_Station->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Geometry ) { stream << "#" << m_Geometry->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcCrossSection::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCrossSection::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcCrossSection, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcCrossSection, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Station = IfcReal::readStepData( args[0] );
			readEntityReference( args[1], m_Geometry, map );
		}
		void IfcCrossSection::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcCrossSection::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
