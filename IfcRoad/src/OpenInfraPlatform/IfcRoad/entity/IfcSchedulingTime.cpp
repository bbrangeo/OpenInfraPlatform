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
#include "include/IfcDataOriginEnum.h"
#include "include/IfcLabel.h"
#include "include/IfcSchedulingTime.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// ENTITY IfcSchedulingTime 
		IfcSchedulingTime::IfcSchedulingTime() { m_entity_enum = IFCSCHEDULINGTIME; }
		IfcSchedulingTime::IfcSchedulingTime( int id ) { m_id = id; m_entity_enum = IFCSCHEDULINGTIME; }
		IfcSchedulingTime::~IfcSchedulingTime() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSchedulingTime::setEntity( shared_ptr<IfcRoadEntity> other_entity )
		{
			shared_ptr<IfcSchedulingTime> other = dynamic_pointer_cast<IfcSchedulingTime>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DataOrigin = other->m_DataOrigin;
			m_UserDefinedDataOrigin = other->m_UserDefinedDataOrigin;
		}
		void IfcSchedulingTime::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSCHEDULINGTIME" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DataOrigin ) { m_DataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_UserDefinedDataOrigin ) { m_UserDefinedDataOrigin->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSchedulingTime::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSchedulingTime::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSchedulingTime, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcRoadException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSchedulingTime, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DataOrigin = IfcDataOriginEnum::readStepData( args[1] );
			m_UserDefinedDataOrigin = IfcLabel::readStepData( args[2] );
		}
		void IfcSchedulingTime::setInverseCounterparts( shared_ptr<IfcRoadEntity> )
		{
		}
		void IfcSchedulingTime::unlinkSelf()
		{
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
