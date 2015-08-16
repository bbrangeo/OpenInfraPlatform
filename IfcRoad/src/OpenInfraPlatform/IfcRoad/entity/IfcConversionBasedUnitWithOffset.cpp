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
#include "include/IfcConversionBasedUnitWithOffset.h"
#include "include/IfcDimensionalExponents.h"
#include "include/IfcExternalReferenceRelationship.h"
#include "include/IfcLabel.h"
#include "include/IfcMeasureWithUnit.h"
#include "include/IfcReal.h"
#include "include/IfcUnitEnum.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcConversionBasedUnitWithOffset 
		IfcConversionBasedUnitWithOffset::IfcConversionBasedUnitWithOffset() { m_entity_enum = IFCCONVERSIONBASEDUNITWITHOFFSET; }
		IfcConversionBasedUnitWithOffset::IfcConversionBasedUnitWithOffset( int id ) { m_id = id; m_entity_enum = IFCCONVERSIONBASEDUNITWITHOFFSET; }
		IfcConversionBasedUnitWithOffset::~IfcConversionBasedUnitWithOffset() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcConversionBasedUnitWithOffset::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcConversionBasedUnitWithOffset> other = dynamic_pointer_cast<IfcConversionBasedUnitWithOffset>(other_entity);
			if( !other) { return; }
			m_Dimensions = other->m_Dimensions;
			m_UnitType = other->m_UnitType;
			m_Name = other->m_Name;
			m_ConversionFactor = other->m_ConversionFactor;
			m_ConversionOffset = other->m_ConversionOffset;
		}
		void IfcConversionBasedUnitWithOffset::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCONVERSIONBASEDUNITWITHOFFSET" << "(";
			if( m_Dimensions ) { stream << "#" << m_Dimensions->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_UnitType ) { m_UnitType->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ConversionFactor ) { stream << "#" << m_ConversionFactor->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_ConversionOffset ) { m_ConversionOffset->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcConversionBasedUnitWithOffset::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcConversionBasedUnitWithOffset::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<5 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcConversionBasedUnitWithOffset, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>5 ){ std::cout << "Wrong parameter count for entity IfcConversionBasedUnitWithOffset, expecting 5, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Dimensions, map );
			m_UnitType = IfcUnitEnum::readStepData( args[1] );
			m_Name = IfcLabel::readStepData( args[2] );
			readEntityReference( args[3], m_ConversionFactor, map );
			m_ConversionOffset = IfcReal::readStepData( args[4] );
		}
		void IfcConversionBasedUnitWithOffset::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self_entity )
		{
			IfcConversionBasedUnit::setInverseCounterparts( ptr_self_entity );
		}
		void IfcConversionBasedUnitWithOffset::unlinkSelf()
		{
			IfcConversionBasedUnit::unlinkSelf();
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
