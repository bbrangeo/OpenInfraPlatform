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
#include "include/IfcExternalInformation.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcExternalInformation 
		IfcExternalInformation::IfcExternalInformation() { m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::IfcExternalInformation( int id ) { m_id = id; m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::~IfcExternalInformation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternalInformation::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcExternalInformation> other = dynamic_pointer_cast<IfcExternalInformation>(other_entity);
			if( !other) { return; }
		}
		void IfcExternalInformation::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEXTERNALINFORMATION" << "(";
			stream << ");";
		}
		void IfcExternalInformation::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcExternalInformation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcExternalInformation::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcExternalInformation::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
