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
#include "IfcPropertyTemplate.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcSimplePropertyTemplateTypeEnum;
		class IfcLabel;
		class IfcPropertyEnumeration;
		class IfcUnit;
		class IfcStateEnum;
		//ENTITY
		class IfcSimplePropertyTemplate : public IfcPropertyTemplate
		{
		public:
			IfcSimplePropertyTemplate();
			IfcSimplePropertyTemplate( int id );
			~IfcSimplePropertyTemplate();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSimplePropertyTemplate"; }


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

			// IfcPropertyTemplate -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcComplexPropertyTemplate> >	m_PartOfComplexTemplate_inverse;
			//  std::vector<weak_ptr<IfcPropertySetTemplate> >	m_PartOfPsetTemplate_inverse;

			// IfcSimplePropertyTemplate -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcSimplePropertyTemplateTypeEnum>	m_TemplateType;				//optional
			shared_ptr<IfcLabel>								m_PrimaryMeasureType;		//optional
			shared_ptr<IfcLabel>								m_SecondaryMeasureType;		//optional
			shared_ptr<IfcPropertyEnumeration>				m_Enumerators;				//optional
			shared_ptr<IfcUnit>								m_PrimaryUnit;				//optional
			shared_ptr<IfcUnit>								m_SecondaryUnit;			//optional
			shared_ptr<IfcLabel>								m_Expression;				//optional
			shared_ptr<IfcStateEnum>							m_AccessState;				//optional
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

