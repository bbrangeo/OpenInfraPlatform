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
#include "include/IfcDimensionalExponents.h"
#include "include/IfcNamedUnit.h"
#include "include/IfcUnitEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcNamedUnit 
		IfcNamedUnit::IfcNamedUnit() { m_entity_enum = IFCNAMEDUNIT; }
		IfcNamedUnit::IfcNamedUnit( int id ) { m_id = id; m_entity_enum = IFCNAMEDUNIT; }
		IfcNamedUnit::~IfcNamedUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcNamedUnit::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcNamedUnit> other = dynamic_pointer_cast<IfcNamedUnit>(other_entity);
			if( !other) { return; }
			m_Dimensions = other->m_Dimensions;
			m_UnitType = other->m_UnitType;
		}
		void IfcNamedUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCNAMEDUNIT" << "(";
			if( m_Dimensions ) { stream << "#" << m_Dimensions->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_UnitType ) { m_UnitType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcNamedUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcNamedUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcNamedUnit, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcNamedUnit, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Dimensions, map );
			m_UnitType = IfcUnitEnum::readStepData( args[1] );
		}
		void IfcNamedUnit::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcNamedUnit::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
