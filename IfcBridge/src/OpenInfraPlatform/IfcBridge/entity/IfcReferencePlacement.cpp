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
#include "include/IfcLocalPlacement.h"
#include "include/IfcProduct.h"
#include "include/IfcReferencePlacement.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcReferencePlacement 
		IfcReferencePlacement::IfcReferencePlacement() { m_entity_enum = IFCREFERENCEPLACEMENT; }
		IfcReferencePlacement::IfcReferencePlacement( int id ) { m_id = id; m_entity_enum = IFCREFERENCEPLACEMENT; }
		IfcReferencePlacement::~IfcReferencePlacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReferencePlacement::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcReferencePlacement> other = dynamic_pointer_cast<IfcReferencePlacement>(other_entity);
			if( !other) { return; }
		}
		void IfcReferencePlacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREFERENCEPLACEMENT" << "(";
			stream << ");";
		}
		void IfcReferencePlacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReferencePlacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
		}
		void IfcReferencePlacement::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcObjectPlacement::setInverseCounterparts( ptr_self_entity );
		}
		void IfcReferencePlacement::unlinkSelf()
		{
			IfcObjectPlacement::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
