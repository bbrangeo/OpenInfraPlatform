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
#include "include/IfcDataOriginEnum.h"
#include "include/IfcDate.h"
#include "include/IfcLabel.h"
#include "include/IfcRecurrencePattern.h"
#include "include/IfcWorkTime.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcWorkTime 
		IfcWorkTime::IfcWorkTime() { m_entity_enum = IFCWORKTIME; }
		IfcWorkTime::IfcWorkTime( int id ) { m_id = id; m_entity_enum = IFCWORKTIME; }
		IfcWorkTime::~IfcWorkTime() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcWorkTime::setEntity( shared_ptr<Ifc4Entity> other_entity )
		{
			shared_ptr<IfcWorkTime> other = dynamic_pointer_cast<IfcWorkTime>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
			m_RecurrencePattern = other->m_RecurrencePattern;
			m_Start = other->m_Start;
			m_Finish = other->m_Finish;
		}
		void IfcWorkTime::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCWORKTIME" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RecurrencePattern ) { stream << "#" << m_RecurrencePattern->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Start ) { m_Start->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_Finish ) { m_Finish->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcWorkTime::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcWorkTime::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcWorkTime, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcWorkTime, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
			readEntityReference( args[3], m_RecurrencePattern, map );
			m_Start = IfcDate::readStepData( args[4] );
			m_Finish = IfcDate::readStepData( args[5] );
		}
		void IfcWorkTime::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcSchedulingTime::setInverseCounterparts( ptr_self_entity );
		}
		void IfcWorkTime::unlinkSelf()
		{
			IfcSchedulingTime::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
