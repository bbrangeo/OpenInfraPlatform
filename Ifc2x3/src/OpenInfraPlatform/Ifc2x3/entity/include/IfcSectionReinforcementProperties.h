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

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		class IfcLengthMeasure;
		class IfcReinforcingBarRoleEnum;
		class IfcSectionProperties;
		class IfcReinforcementBarProperties;
		//ENTITY
		class IfcSectionReinforcementProperties : public Ifc2x3Entity
		{
		public:
			IfcSectionReinforcementProperties();
			IfcSectionReinforcementProperties( int id );
			~IfcSectionReinforcementProperties();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc2x3Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcSectionReinforcementProperties"; }


			// IfcSectionReinforcementProperties -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcLengthMeasure>								m_LongitudinalStartPosition;
			shared_ptr<IfcLengthMeasure>								m_LongitudinalEndPosition;
			shared_ptr<IfcLengthMeasure>								m_TransversePosition;		//optional
			shared_ptr<IfcReinforcingBarRoleEnum>					m_ReinforcementRole;
			shared_ptr<IfcSectionProperties>							m_SectionDefinition;
			std::vector<shared_ptr<IfcReinforcementBarProperties> >	m_CrossSectionReinforcementDefinitions;
		};
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform

