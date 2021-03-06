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
#include "IfcLibrarySelect.h"
#include "IfcExternalInformation.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcLabel;
		class IfcActorSelect;
		class IfcDateTime;
		class IfcURIReference;
		class IfcText;
		class IfcRelAssociatesLibrary;
		class IfcLibraryReference;
		//ENTITY
		class IfcLibraryInformation : public IfcLibrarySelect, public IfcExternalInformation
		{
		public:
			IfcLibraryInformation();
			IfcLibraryInformation( int id );
			~IfcLibraryInformation();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLibraryInformation"; }


			// IfcExternalInformation -----------------------------------------------------------

			// IfcLibraryInformation -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>								m_Name;
			shared_ptr<IfcLabel>								m_Version;					//optional
			shared_ptr<IfcActorSelect>						m_Publisher;				//optional
			shared_ptr<IfcDateTime>							m_VersionDate;				//optional
			shared_ptr<IfcURIReference>						m_Location;					//optional
			shared_ptr<IfcText>								m_Description;				//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcRelAssociatesLibrary> >	m_LibraryInfoForObjects_inverse;
			std::vector<weak_ptr<IfcLibraryReference> >		m_HasLibraryReferences_inverse;
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

