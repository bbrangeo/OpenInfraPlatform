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
#include "IfcMaterialDefinition.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcLabel;
		class IfcText;
		class IfcMaterialDefinitionRepresentation;
		class IfcMaterialRelationship;
		//ENTITY
		class IfcMaterial : public IfcMaterialDefinition
		{
		public:
			IfcMaterial();
			IfcMaterial( int id );
			~IfcMaterial();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMaterial"; }


			// IfcMaterialDefinition -----------------------------------------------------------
			// inverse attributes:
			//  std::vector<weak_ptr<IfcRelAssociatesMaterial> >				m_AssociatedTo_inverse;
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >		m_HasExternalReferences_inverse;
			//  std::vector<weak_ptr<IfcMaterialProperties> >				m_HasProperties_inverse;

			// IfcMaterial -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>											m_Name;
			shared_ptr<IfcText>											m_Description;				//optional
			shared_ptr<IfcLabel>											m_Category;					//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcMaterialDefinitionRepresentation> >	m_HasRepresentation_inverse;
			std::vector<weak_ptr<IfcMaterialRelationship> >				m_IsRelatedWith_inverse;
			std::vector<weak_ptr<IfcMaterialRelationship> >				m_RelatesTo_inverse;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

