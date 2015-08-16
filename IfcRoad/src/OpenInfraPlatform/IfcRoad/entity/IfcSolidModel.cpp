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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcSolidModel.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcSolidModel 
		IfcSolidModel::IfcSolidModel() { m_entity_enum = IFCSOLIDMODEL; }
		IfcSolidModel::IfcSolidModel( int id ) { m_id = id; m_entity_enum = IFCSOLIDMODEL; }
		IfcSolidModel::~IfcSolidModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSolidModel::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcSolidModel> other = dynamic_pointer_cast<IfcSolidModel>(other_entity);
			if( !other) { return; }
		}
		void IfcSolidModel::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSOLIDMODEL" << "(";
			stream << ");";
		}
		void IfcSolidModel::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSolidModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
		}
		void IfcSolidModel::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSolidModel::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
