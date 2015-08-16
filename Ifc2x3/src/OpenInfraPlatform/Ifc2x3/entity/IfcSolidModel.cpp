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
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcSolidModel.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSolidModel 
		IfcSolidModel::IfcSolidModel() { m_entity_enum = IFCSOLIDMODEL; }
		IfcSolidModel::IfcSolidModel( int id ) { m_id = id; m_entity_enum = IFCSOLIDMODEL; }
		IfcSolidModel::~IfcSolidModel() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSolidModel::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcSolidModel::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
		}
		void IfcSolidModel::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSolidModel::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
