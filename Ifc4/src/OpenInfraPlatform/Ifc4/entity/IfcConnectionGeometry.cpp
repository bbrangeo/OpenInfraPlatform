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
#include "include/IfcConnectionGeometry.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcConnectionGeometry 
		IfcConnectionGeometry::IfcConnectionGeometry() { m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::IfcConnectionGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONGEOMETRY; }
		IfcConnectionGeometry::~IfcConnectionGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionGeometry::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcConnectionGeometry> other = dynamic_pointer_cast<IfcConnectionGeometry>(other_entity);
			if( !other) { return; }
		}
		void IfcConnectionGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONGEOMETRY" << "(";
			stream << ");";
		}
		void IfcConnectionGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcConnectionGeometry::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcConnectionGeometry::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
