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
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcUnit.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcMeasureWithUnit 
		IfcMeasureWithUnit::IfcMeasureWithUnit() { m_entity_enum = IFCMEASUREWITHUNIT; }
		IfcMeasureWithUnit::IfcMeasureWithUnit( int id ) { m_id = id; m_entity_enum = IFCMEASUREWITHUNIT; }
		IfcMeasureWithUnit::~IfcMeasureWithUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcMeasureWithUnit::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcMeasureWithUnit> other = dynamic_pointer_cast<IfcMeasureWithUnit>(other_entity);
			if( !other) { return; }
			m_ValueComponent = other->m_ValueComponent;
			m_UnitComponent = other->m_UnitComponent;
		}
		void IfcMeasureWithUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCMEASUREWITHUNIT" << "(";
			if( m_ValueComponent ) { m_ValueComponent->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_UnitComponent ) { m_UnitComponent->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcMeasureWithUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcMeasureWithUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcMeasureWithUnit, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcMeasureWithUnit, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_ValueComponent = IfcValue::readStepData( args[0], map );
			m_UnitComponent = IfcUnit::readStepData( args[1], map );
		}
		void IfcMeasureWithUnit::setInverseCounterparts( shared_ptr<Ifc2x3Entity> )
		{
		}
		void IfcMeasureWithUnit::unlinkSelf()
		{
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
