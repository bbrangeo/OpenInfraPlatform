/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
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
#include "../../model/IfcBridgeObject.h"
#include "IfcResourceObjectSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcLabel;
		class IfcText;
		class IfcConstraintEnum;
		class IfcActorSelect;
		class IfcDateTime;
		class IfcExternalReferenceRelationship;
		class IfcResourceConstraintRelationship;
		//ENTITY
		class IfcConstraint : public IfcResourceObjectSelect, public IfcBridgeEntity
		{
		public:
			IfcConstraint();
			IfcConstraint( int id );
			~IfcConstraint();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcBridgeEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcConstraint"; }


			// IfcConstraint -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>											m_Name;
			shared_ptr<IfcText>											m_Description;				//optional
			shared_ptr<IfcConstraintEnum>								m_ConstraintGrade;
			shared_ptr<IfcLabel>											m_ConstraintSource;			//optional
			shared_ptr<IfcActorSelect>									m_CreatingActor;			//optional
			shared_ptr<IfcDateTime>										m_CreationTime;				//optional
			shared_ptr<IfcLabel>											m_UserDefinedGrade;			//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcExternalReferenceRelationship> >		m_HasExternalReferences_inverse;
			std::vector<weak_ptr<IfcResourceConstraintRelationship> >	m_PropertiesForConstraint_inverse;
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform

