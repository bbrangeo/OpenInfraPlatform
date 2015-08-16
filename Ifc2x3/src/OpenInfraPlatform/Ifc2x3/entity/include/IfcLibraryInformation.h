/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
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
#include "../../model/Ifc2x3Object.h"
#include "IfcLibrarySelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcLabel;
		class IfcOrganization;
		class IfcCalendarDate;
		class IfcLibraryReference;
		//ENTITY
		class IfcLibraryInformation : public IfcLibrarySelect, public Ifc2x3Entity
		{
		public:
			IfcLibraryInformation();
			IfcLibraryInformation( int id );
			~IfcLibraryInformation();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcLibraryInformation"; }


			// IfcLibraryInformation -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLabel>								m_Name;
			shared_ptr<IfcLabel>								m_Version;					//optional
			shared_ptr<IfcOrganization>						m_Publisher;				//optional
			shared_ptr<IfcCalendarDate>						m_VersionDate;				//optional
			std::vector<shared_ptr<IfcLibraryReference> >	m_LibraryReference;			//optional
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

