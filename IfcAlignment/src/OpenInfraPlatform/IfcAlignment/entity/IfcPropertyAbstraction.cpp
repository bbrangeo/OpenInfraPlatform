/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcPropertyAbstraction.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcPropertyAbstraction 
		IfcPropertyAbstraction::IfcPropertyAbstraction() { m_entity_enum = IFCPROPERTYABSTRACTION; }
		IfcPropertyAbstraction::IfcPropertyAbstraction( int id ) { m_id = id; m_entity_enum = IFCPROPERTYABSTRACTION; }
		IfcPropertyAbstraction::~IfcPropertyAbstraction() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcPropertyAbstraction::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcPropertyAbstraction> other = dynamic_pointer_cast<IfcPropertyAbstraction>(other_entity);
			if( !other) { return; }
		}
		void IfcPropertyAbstraction::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCPROPERTYABSTRACTION" << "(";
			stream << ");";
		}
		void IfcPropertyAbstraction::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcPropertyAbstraction::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
		}
		void IfcPropertyAbstraction::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcPropertyAbstraction::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
