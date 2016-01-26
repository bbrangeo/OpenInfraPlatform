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
#include "include/IfcContextDependentUnit.h"
#include "include/IfcDimensionalExponents.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcUnitEnum.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcContextDependentUnit 
		IfcContextDependentUnit::IfcContextDependentUnit() { m_entity_enum = IFCCONTEXTDEPENDENTUNIT; }
		IfcContextDependentUnit::IfcContextDependentUnit( int id ) { m_id = id; m_entity_enum = IFCCONTEXTDEPENDENTUNIT; }
		IfcContextDependentUnit::~IfcContextDependentUnit() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcContextDependentUnit::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcContextDependentUnit> other = dynamic_pointer_cast<IfcContextDependentUnit>(other_entity);
			if( !other) { return; }
			m_Dimensions = other->m_Dimensions;
			m_UnitType = other->m_UnitType;
			m_Name = other->m_Name;
		}
		void IfcContextDependentUnit::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONTEXTDEPENDENTUNIT" << "(";
			if( m_Dimensions ) { stream << "#" << m_Dimensions->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_UnitType ) { m_UnitType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcContextDependentUnit::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcContextDependentUnit::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcContextDependentUnit, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcContextDependentUnit, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Dimensions, map );
			m_UnitType = IfcUnitEnum::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcContextDependentUnit::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcNamedUnit::setInverseCounterparts( ptr_self_entity );
		}
		void IfcContextDependentUnit::unlinkSelf()
		{
			IfcNamedUnit::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
