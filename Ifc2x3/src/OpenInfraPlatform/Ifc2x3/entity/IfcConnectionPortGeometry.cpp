/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcAxis2Placement.h"
#include "include/IfcConnectionPortGeometry.h"
#include "include/IfcProfileDef.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcConnectionPortGeometry 
		IfcConnectionPortGeometry::IfcConnectionPortGeometry() { m_entity_enum = IFCCONNECTIONPORTGEOMETRY; }
		IfcConnectionPortGeometry::IfcConnectionPortGeometry( int id ) { m_id = id; m_entity_enum = IFCCONNECTIONPORTGEOMETRY; }
		IfcConnectionPortGeometry::~IfcConnectionPortGeometry() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConnectionPortGeometry::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcConnectionPortGeometry> other = dynamic_pointer_cast<IfcConnectionPortGeometry>(other_entity);
			if( !other) { return; }
			m_LocationAtRelatingElement = other->m_LocationAtRelatingElement;
			m_LocationAtRelatedElement = other->m_LocationAtRelatedElement;
			m_ProfileOfPort = other->m_ProfileOfPort;
		}
		void IfcConnectionPortGeometry::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONNECTIONPORTGEOMETRY" << "(";
			if( m_LocationAtRelatingElement ) { m_LocationAtRelatingElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_LocationAtRelatedElement ) { m_LocationAtRelatedElement->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ProfileOfPort ) { stream << "#" << m_ProfileOfPort->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConnectionPortGeometry::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConnectionPortGeometry::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConnectionPortGeometry, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcConnectionPortGeometry, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_LocationAtRelatingElement = IfcAxis2Placement::readStepData( args[0], map );
			m_LocationAtRelatedElement = IfcAxis2Placement::readStepData( args[1], map );
			readEntityReference( args[2], m_ProfileOfPort, map );
		}
		void IfcConnectionPortGeometry::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcConnectionGeometry::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConnectionPortGeometry::unlinkSelf()
		{
			IfcConnectionGeometry::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
