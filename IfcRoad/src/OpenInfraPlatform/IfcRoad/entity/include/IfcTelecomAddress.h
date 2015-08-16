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
#include "IfcAddress.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcLabel;
		class IfcURIReference;
		//ENTITY
		class IfcTelecomAddress : public IfcAddress
		{
		public:
			IfcTelecomAddress();
			IfcTelecomAddress( int id );
			~IfcTelecomAddress();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcRoadEntity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcTelecomAddress"; }


			// IfcAddress -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcAddressTypeEnum>				m_Purpose;					//optional
			//  shared_ptr<IfcText>							m_Description;				//optional
			//  shared_ptr<IfcLabel>							m_UserDefinedPurpose;		//optional
			// inverse attributes:
			//  std::vector<weak_ptr<IfcPerson> >			m_OfPerson_inverse;
			//  std::vector<weak_ptr<IfcOrganization> >		m_OfOrganization_inverse;

			// IfcTelecomAddress -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcLabel> >			m_TelephoneNumbers;			//optional
			std::vector<shared_ptr<IfcLabel> >			m_FacsimileNumbers;			//optional
			shared_ptr<IfcLabel>							m_PagerNumber;				//optional
			std::vector<shared_ptr<IfcLabel> >			m_ElectronicMailAddresses;	//optional
			shared_ptr<IfcURIReference>					m_WWWHomePageURL;			//optional
			std::vector<shared_ptr<IfcURIReference> >	m_MessagingIDs;				//optional
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform

