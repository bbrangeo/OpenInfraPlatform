/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "IfcRelConnects.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcProcess;
		class IfcLagTime;
		class IfcSequenceEnum;
		class IfcLabel;
		//ENTITY
		class IfcRelSequence : public IfcRelConnects
		{
		public:
			IfcRelSequence();
			IfcRelSequence( int id );
			~IfcRelSequence();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelSequence"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelSequence -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProcess>						m_RelatingProcess;
			shared_ptr<IfcProcess>						m_RelatedProcess;
			shared_ptr<IfcLagTime>						m_TimeLag;					//optional
			shared_ptr<IfcSequenceEnum>					m_SequenceType;				//optional
			shared_ptr<IfcLabel>							m_UserDefinedSequenceType;	//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

