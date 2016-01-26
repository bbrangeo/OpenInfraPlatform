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
#include "IfcClassificationReferenceSelect.h"
#include "IfcClassificationSelect.h"
#include "IfcExternalReference.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcClassificationReferenceSelect;
		class IfcText;
		class IfcIdentifier;
		class IfcRelAssociatesClassification;
		class IfcClassificationReference;
		//ENTITY
		class IfcClassificationReference : public IfcClassificationReferenceSelect, public IfcClassificationSelect, public IfcExternalReference
		{
		public:
			IfcClassificationReference();
			IfcClassificationReference( int id );
			~IfcClassificationReference();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcClassificationReference"; }


			// IfcExternalReference -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcURIReference>								m_Location;					//optional
			//  shared_ptr<IfcIdentifier>								m_Identification;			//optional
			//  shared_ptr<IfcLabel>										m_Name;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_ExternalReferenceForResources_inverse;

			// IfcClassificationReference -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcClassificationReferenceSelect>				m_ReferencedSource;			//optional
			shared_ptr<IfcText>										m_Description;				//optional
			shared_ptr<IfcIdentifier>								m_Sort;						//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelAssociatesClassification> >	m_ClassificationRefForObjects_inverse;
			std::vector<weak_ptr<IfcClassificationReference> >		m_HasReferences_inverse;
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

