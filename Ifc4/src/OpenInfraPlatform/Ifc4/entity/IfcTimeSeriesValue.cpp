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
#include "include/IfcTimeSeriesValue.h"
#include "include/IfcValue.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcTimeSeriesValue 
		IfcTimeSeriesValue::IfcTimeSeriesValue() { m_entity_enum = IFCTIMESERIESVALUE; }
		IfcTimeSeriesValue::IfcTimeSeriesValue( int id ) { m_id = id; m_entity_enum = IFCTIMESERIESVALUE; }
		IfcTimeSeriesValue::~IfcTimeSeriesValue() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTimeSeriesValue::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcTimeSeriesValue> other = dynamic_pointer_cast<IfcTimeSeriesValue>(other_entity);
			if( !other) { return; }
			m_ListValues = other->m_ListValues;
		}
		void IfcTimeSeriesValue::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTIMESERIESVALUE" << "(";
			writeTypeList( stream, m_ListValues, true );
			stream << ");";
		}
		void IfcTimeSeriesValue::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTimeSeriesValue::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<1 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTimeSeriesValue, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>1 ){ std::cout << "Wrong parameter count for entity IfcTimeSeriesValue, expecting 1, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readSelectList( args[0], m_ListValues, map );
		}
		void IfcTimeSeriesValue::setInverseCounterparts( shared_ptr<Ifc4Entity> )
		{
		}
		void IfcTimeSeriesValue::unlinkSelf()
		{
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
