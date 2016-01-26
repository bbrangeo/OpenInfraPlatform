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
#include "include/IfcCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcCurve 
		IfcCurve::IfcCurve() { m_entity_enum = IFCCURVE; }
		IfcCurve::IfcCurve( int id ) { m_id = id; m_entity_enum = IFCCURVE; }
		IfcCurve::~IfcCurve() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcCurve::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcCurve> other = dynamic_pointer_cast<IfcCurve>(other_entity);
			if( !other) { return; }
		}
		void IfcCurve::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCURVE" << "(";
			stream << ");";
		}
		void IfcCurve::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcCurve::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
		}
		void IfcCurve::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcCurve::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
