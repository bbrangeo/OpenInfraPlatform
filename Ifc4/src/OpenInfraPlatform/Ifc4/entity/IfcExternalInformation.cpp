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
#include "include/IfcExternalInformation.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcExternalInformation 
		IfcExternalInformation::IfcExternalInformation() { m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::IfcExternalInformation( int id ) { m_id = id; m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::~IfcExternalInformation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternalInformation::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcExternalInformation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcExternalInformation::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcExternalInformation::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
