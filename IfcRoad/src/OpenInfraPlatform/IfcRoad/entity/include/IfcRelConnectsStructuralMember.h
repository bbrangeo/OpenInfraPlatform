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
		class IfcStructuralMember;
		class IfcStructuralConnection;
		class IfcBoundaryCondition;
		class IfcStructuralConnectionCondition;
		class IfcLengthMeasure;
		class IfcAxis2Placement3D;
		//ENTITY
		class IfcRelConnectsStructuralMember : public IfcRelConnects
		{
		public:
			IfcRelConnectsStructuralMember();
			IfcRelConnectsStructuralMember( int id );
			~IfcRelConnectsStructuralMember();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelConnectsStructuralMember"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>				m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>					m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>							m_Name;						//optional
			//  shared_ptr<IfcText>							m_Description;				//optional

			// IfcRelationship -----------------------------------------------------------

			// IfcRelConnects -----------------------------------------------------------

			// IfcRelConnectsStructuralMember -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcStructuralMember>				m_RelatingStructuralMember;
			shared_ptr<IfcStructuralConnection>			m_RelatedStructuralConnection;
			shared_ptr<IfcBoundaryCondition>				m_AppliedCondition;			//optional
			shared_ptr<IfcStructuralConnectionCondition>	m_AdditionalConditions;		//optional
			shared_ptr<IfcLengthMeasure>					m_SupportedLength;			//optional
			shared_ptr<IfcAxis2Placement3D>				m_ConditionCoordinateSystem;	//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

