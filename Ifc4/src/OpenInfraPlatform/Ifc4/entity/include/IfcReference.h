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
#include "IfcAppliedValueSelect.h"
#include "IfcMetricValueSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcIdentifier;
		class IfcLabel;
		class IfcReference;
		//ENTITY
		class IfcReference : public IfcAppliedValueSelect, public IfcMetricValueSelect, public Ifc4Entity
		{
		public:
			IfcReference();
			IfcReference( int id );
			~IfcReference();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcReference"; }


			// IfcReference -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcIdentifier>					m_TypeIdentifier;			//optional
			shared_ptr<IfcIdentifier>					m_AttributeIdentifier;		//optional
			shared_ptr<IfcLabel>							m_InstanceName;				//optional
			std::vector<int >							m_ListPositions;			//optional
			shared_ptr<IfcReference>						m_InnerReference;			//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

