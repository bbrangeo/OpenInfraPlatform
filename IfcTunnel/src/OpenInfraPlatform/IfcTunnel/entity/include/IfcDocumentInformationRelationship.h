/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
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
#include "../../model/IfcTunnelObject.h"
#include "IfcResourceLevelRelationship.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		class IfcDocumentInformation;
		class IfcLabel;
		//ENTITY
		class IfcDocumentInformationRelationship : public IfcResourceLevelRelationship
		{
		public:
			IfcDocumentInformationRelationship();
			IfcDocumentInformationRelationship( int id );
			~IfcDocumentInformationRelationship();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcTunnelEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDocumentInformationRelationship"; }


			// IfcResourceLevelRelationship -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>								m_Name;						//optional
			//  shared_ptr<IfcText>								m_Description;				//optional

			// IfcDocumentInformationRelationship -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcDocumentInformation>				m_RelatingDocument;
			std::vector<shared_ptr<IfcDocumentInformation> >	m_RelatedDocuments;
			shared_ptr<IfcLabel>								m_RelationshipType;			//optional
		};
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform

