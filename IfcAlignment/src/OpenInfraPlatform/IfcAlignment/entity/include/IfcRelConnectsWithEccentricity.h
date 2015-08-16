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
#include "IfcRelConnectsStructuralMember.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcConnectionGeometry;
		//ENTITY
		class IfcRelConnectsWithEccentricity : public IfcRelConnectsStructuralMember
		{
		public:
			IfcRelConnectsWithEccentricity();
			IfcRelConnectsWithEccentricity( int id );
			~IfcRelConnectsWithEccentricity();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcRelConnectsWithEccentricity"; }


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
			//  shared_ptr<IfcStructuralMember>				m_RelatingStructuralMember;
			//  shared_ptr<IfcStructuralConnection>			m_RelatedStructuralConnection;
			//  shared_ptr<IfcBoundaryCondition>				m_AppliedCondition;			//optional
			//  shared_ptr<IfcStructuralConnectionCondition>	m_AdditionalConditions;		//optional
			//  shared_ptr<IfcLengthMeasure>					m_SupportedLength;			//optional
			//  shared_ptr<IfcAxis2Placement3D>				m_ConditionCoordinateSystem;	//optional

			// IfcRelConnectsWithEccentricity -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcConnectionGeometry>			m_ConnectionConstraint;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

