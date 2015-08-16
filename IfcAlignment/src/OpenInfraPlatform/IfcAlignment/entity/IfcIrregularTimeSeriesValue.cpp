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
#include "include/IfcDateTime.h"
#include "include/IfcIrregularTimeSeriesValue.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcIrregularTimeSeriesValue 
		IfcIrregularTimeSeriesValue::IfcIrregularTimeSeriesValue() { m_entity_enum = IFCIRREGULARTIMESERIESVALUE; }
		IfcIrregularTimeSeriesValue::IfcIrregularTimeSeriesValue( int id ) { m_id = id; m_entity_enum = IFCIRREGULARTIMESERIESVALUE; }
		IfcIrregularTimeSeriesValue::~IfcIrregularTimeSeriesValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcIrregularTimeSeriesValue::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcIrregularTimeSeriesValue> other = dynamic_pointer_cast<IfcIrregularTimeSeriesValue>(other_entity);
			if( !other) { return; }
			m_TimeStamp = other->m_TimeStamp;
			m_ListValues = other->m_ListValues;
		}
		void IfcIrregularTimeSeriesValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCIRREGULARTIMESERIESVALUE" << "(";
			if( m_TimeStamp ) { m_TimeStamp->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeList( stream, m_ListValues, true );
			stream << ");";
		}
		void IfcIrregularTimeSeriesValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcIrregularTimeSeriesValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcIrregularTimeSeriesValue, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcIrregularTimeSeriesValue, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_TimeStamp = IfcDateTime::readStepData( args[0] );
			readSelectList( args[1], m_ListValues, map );
		}
		void IfcIrregularTimeSeriesValue::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> )
		{
		}
		void IfcIrregularTimeSeriesValue::unlinkSelf()
		{
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
