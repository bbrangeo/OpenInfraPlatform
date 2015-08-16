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
#include "include/IfcLabel.h"
#include "include/IfcMonetaryUnit.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcMonetaryUnit 
		IfcMonetaryUnit::IfcMonetaryUnit() { m_entity_enum = IFCMONETARYUNIT; }
		IfcMonetaryUnit::IfcMonetaryUnit( int id ) { m_id = id; m_entity_enum = IFCMONETARYUNIT; }
		IfcMonetaryUnit::~IfcMonetaryUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMonetaryUnit::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcMonetaryUnit> other = dynamic_pointer_cast<IfcMonetaryUnit>(other_entity);
			if( !other) { return; }
			m_Currency = other->m_Currency;
		}
		void IfcMonetaryUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMONETARYUNIT" << "(";
			if( m_Currency ) { m_Currency->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMonetaryUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMonetaryUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMonetaryUnit, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcMonetaryUnit, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Currency = IfcLabel::readStepData( args[0] );
		}
		void IfcMonetaryUnit::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcMonetaryUnit::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
