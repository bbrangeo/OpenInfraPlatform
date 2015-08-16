/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Object.h"
#include "IfcSchedulingTime.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcDateTime;
		//ENTITY
		class IfcEventTime : public IfcSchedulingTime
		{
		public:
			IfcEventTime();
			IfcEventTime( int id );
			~IfcEventTime();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcEventTime"; }


			// IfcSchedulingTime -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcDataOriginEnum>				m_DataOrigin;				//optional
			//  shared_ptr<IfcLabel>							m_UserDefinedDataOrigin;	//optional

			// IfcEventTime -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDateTime>						m_ActualDate;				//optional
			shared_ptr<IfcDateTime>						m_EarlyDate;				//optional
			shared_ptr<IfcDateTime>						m_LateDate;					//optional
			shared_ptr<IfcDateTime>						m_ScheduleDate;				//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

