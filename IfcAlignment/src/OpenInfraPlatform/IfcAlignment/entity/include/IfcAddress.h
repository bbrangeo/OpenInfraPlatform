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
#include "IfcObjectReferenceSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcAddressTypeEnum;
		class IfcText;
		class IfcLabel;
		class IfcPerson;
		class IfcOrganization;
		//ENTITY
		class IfcAddress : public IfcObjectReferenceSelect, public IfcAlignmentP6Entity
		{
		public:
			IfcAddress();
			IfcAddress( int id );
			~IfcAddress();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcAddress"; }


			// IfcAddress -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcAddressTypeEnum>				m_Purpose;					//optional
			shared_ptr<IfcText>							m_Description;				//optional
			shared_ptr<IfcLabel>							m_UserDefinedPurpose;		//optional
			// inverse attributes:
			std::vector<weak_ptr<IfcPerson> >			m_OfPerson_inverse;
			std::vector<weak_ptr<IfcOrganization> >		m_OfOrganization_inverse;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

