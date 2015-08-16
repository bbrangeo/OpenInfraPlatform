/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcExternalInformation.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcExternalInformation 
		IfcExternalInformation::IfcExternalInformation() { m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::IfcExternalInformation( int id ) { m_id = id; m_entity_enum = IFCEXTERNALINFORMATION; }
		IfcExternalInformation::~IfcExternalInformation() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcExternalInformation::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
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
		void IfcExternalInformation::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
		}
		void IfcExternalInformation::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcExternalInformation::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
