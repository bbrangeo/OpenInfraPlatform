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
#include "IfcDocumentSelect.h"
#include "IfcExternalReference.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcText;
		class IfcDocumentInformation;
		class IfcRelAssociatesDocument;
		//ENTITY
		class IfcDocumentReference : public IfcDocumentSelect, public IfcExternalReference
		{
		public:
			IfcDocumentReference();
			IfcDocumentReference( int id );
			~IfcDocumentReference();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDocumentReference"; }


			// IfcExternalReference -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcURIReference>						m_Location;					//optional
			//  shared_ptr<IfcIdentifier>						m_Identification;			//optional
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcExternalReferenceRelationship> >	m_ExternalReferenceForResources_inverse;

			// IfcDocumentReference -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcText>								m_Description;				//optional
			shared_ptr<IfcDocumentInformation>				m_ReferencedDocument;		//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelAssociatesDocument> >	m_DocumentRefForObjects_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

