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
#include "include/IfcTime.h"
#include "include/IfcTimePeriod.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcTimePeriod 
		IfcTimePeriod::IfcTimePeriod() { m_entity_enum = IFCTIMEPERIOD; }
		IfcTimePeriod::IfcTimePeriod( int id ) { m_id = id; m_entity_enum = IFCTIMEPERIOD; }
		IfcTimePeriod::~IfcTimePeriod() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcTimePeriod::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcTimePeriod> other = dynamic_pointer_cast<IfcTimePeriod>(other_entity);
			if( !other) { return; }
			m_StartTime = other->m_StartTime;
			m_EndTime = other->m_EndTime;
		}
		void IfcTimePeriod::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCTIMEPERIOD" << "(";
			if( m_StartTime ) { m_StartTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndTime ) { m_EndTime->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcTimePeriod::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcTimePeriod::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcTimePeriod, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcTimePeriod, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_StartTime = IfcTime::readStepData( args[0] );
			m_EndTime = IfcTime::readStepData( args[1] );
		}
		void IfcTimePeriod::setInverseCounterparts( shared_ptr<IfcBridgeEntity> )
		{
		}
		void IfcTimePeriod::unlinkSelf()
		{
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
