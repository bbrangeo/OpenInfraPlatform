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
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Object.h"
#include "IfcPropertyTemplateDefinition.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcPropertySetTemplateTypeEnum;
		class IfcIdentifier;
		class IfcPropertyTemplate;
		class IfcRelDefinesByTemplate;
		//ENTITY
		class IfcPropertySetTemplate : public IfcPropertyTemplateDefinition
		{
		public:
			IfcPropertySetTemplate();
			IfcPropertySetTemplate( int id );
			~IfcPropertySetTemplate();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcPropertySetTemplate"; }


			// IfcRoot -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcGloballyUniqueId>					m_GlobalId;
			//  shared_ptr<IfcOwnerHistory>						m_OwnerHistory;				//optional
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			//  shared_ptr<IfcText>								m_Description;				//optional

			// IfcPropertyDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelDeclares> >			m_HasContext_inverse;
			//  std::vector<weak_ptr<IfcRelAssociates> >			m_HasAssociations_inverse;

			// IfcPropertyTemplateDefinition -----------------------------------------------------------

			// IfcPropertySetTemplate -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcPropertySetTemplateTypeEnum>		m_TemplateType;				//optional
			shared_ptr<IfcIdentifier>						m_ApplicableEntity;			//optional
			std::vector<shared_ptr<IfcPropertyTemplate> >	m_HasPropertyTemplates;
			// inverse attributes:
			std::vector<weak_ptr<IfcRelDefinesByTemplate> >	m_Defines_inverse;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

