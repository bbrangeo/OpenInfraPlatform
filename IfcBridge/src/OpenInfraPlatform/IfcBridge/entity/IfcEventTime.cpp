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
#include "include/IfcDataOriginEnum.h"
#include "include/IfcDateTime.h"
#include "include/IfcEventTime.h"
#include "include/IfcLabel.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcEventTime 
		IfcEventTime::IfcEventTime() { m_entity_enum = IFCEVENTTIME; }
		IfcEventTime::IfcEventTime( int id ) { m_id = id; m_entity_enum = IFCEVENTTIME; }
		IfcEventTime::~IfcEventTime() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcEventTime::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcEventTime> other = dynamic_pointer_cast<IfcEventTime>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_ActualDate = other->m_ActualDate;
			m_EarlyDate = other->m_EarlyDate;
			m_LateDate = other->m_LateDate;
			m_ScheduleDate = other->m_ScheduleDate;
		}
		void IfcEventTime::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCEVENTTIME" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ActualDate ) { m_ActualDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EarlyDate ) { m_EarlyDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_LateDate ) { m_LateDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_ScheduleDate ) { m_ScheduleDate->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcEventTime::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcEventTime::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcEventTime, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcEventTime, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
			m_ActualDate = IfcDateTime::readStepData( args[3] );
			m_EarlyDate = IfcDateTime::readStepData( args[4] );
			m_LateDate = IfcDateTime::readStepData( args[5] );
			m_ScheduleDate = IfcDateTime::readStepData( args[6] );
		}
		void IfcEventTime::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSchedulingTime::setInverseCounterparts( ptr_self_entity );
		}
		void IfcEventTime::unlinkSelf()
		{
			IfcSchedulingTime::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
