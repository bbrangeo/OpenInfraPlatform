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
#include "include/IfcBoundedCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcBoundedCurve 
		IfcBoundedCurve::IfcBoundedCurve() { m_entity_enum = IFCBOUNDEDCURVE; }
		IfcBoundedCurve::IfcBoundedCurve( int id ) { m_id = id; m_entity_enum = IFCBOUNDEDCURVE; }
		IfcBoundedCurve::~IfcBoundedCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcBoundedCurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcBoundedCurve> other = dynamic_pointer_cast<IfcBoundedCurve>(other_entity);
			if( !other) { return; }
		}
		void IfcBoundedCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCBOUNDEDCURVE" << "(";
			stream << ");";
		}
		void IfcBoundedCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcBoundedCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcBoundedCurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcBoundedCurve::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
