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
#include "IfcBoundaryNodeCondition.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcWarpingStiffnessSelect;
		//ENTITY
		class IfcBoundaryNodeConditionWarping : public IfcBoundaryNodeCondition
		{
		public:
			IfcBoundaryNodeConditionWarping();
			IfcBoundaryNodeConditionWarping( int id );
			~IfcBoundaryNodeConditionWarping();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcBoundaryNodeConditionWarping"; }


			// IfcBoundaryCondition -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcBoundaryNodeCondition -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcTranslationalStiffnessSelect>	m_TranslationalStiffnessX;	//optional
			//  shared_ptr<IfcTranslationalStiffnessSelect>	m_TranslationalStiffnessY;	//optional
			//  shared_ptr<IfcTranslationalStiffnessSelect>	m_TranslationalStiffnessZ;	//optional
			//  shared_ptr<IfcRotationalStiffnessSelect>		m_RotationalStiffnessX;		//optional
			//  shared_ptr<IfcRotationalStiffnessSelect>		m_RotationalStiffnessY;		//optional
			//  shared_ptr<IfcRotationalStiffnessSelect>		m_RotationalStiffnessZ;		//optional

			// IfcBoundaryNodeConditionWarping -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcWarpingStiffnessSelect>		m_WarpingStiffness;			//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

