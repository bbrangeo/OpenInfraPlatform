/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include "../../model/shared_ptr.h"
#include "../../model/Ifc2x3Object.h"
#include "IfcRelConnects.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcProcess;
		class IfcTimeMeasure;
		class IfcSequenceEnum;
		//ENTITY
		class IfcRelSequence : public IfcRelConnects
		{
		public:
			IfcRelSequence();
			IfcRelSequence( int id );
			~IfcRelSequence();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelSequence"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelSequence -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcProcess>						m_RelatingProcess;
			shared_ptr<IfcProcess>						m_RelatedProcess;
			shared_ptr<IfcTimeMeasure>					m_TimeLag;
			shared_ptr<IfcSequenceEnum>					m_SequenceType;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

