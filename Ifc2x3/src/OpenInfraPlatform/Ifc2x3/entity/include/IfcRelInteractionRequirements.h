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
		class IfcCountMeasure;
		class IfcNormalisedRatioMeasure;
		class IfcSpatialStructureElement;
		class IfcSpaceProgram;
		//ENTITY
		class IfcRelInteractionRequirements : public IfcRelConnects
		{
		public:
			IfcRelInteractionRequirements();
			IfcRelInteractionRequirements( int id );
			~IfcRelInteractionRequirements();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelInteractionRequirements"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelInteractionRequirements -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcCountMeasure>					m_DailyInteraction;			//optional
			shared_ptr<IfcNormalisedRatioMeasure>		m_ImportanceRating;			//optional
			shared_ptr<IfcSpatialStructureElement>		m_LocationOfInteraction;	//optional
			shared_ptr<IfcSpaceProgram>					m_RelatedSpaceProgram;
			shared_ptr<IfcSpaceProgram>					m_RelatingSpaceProgram;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
