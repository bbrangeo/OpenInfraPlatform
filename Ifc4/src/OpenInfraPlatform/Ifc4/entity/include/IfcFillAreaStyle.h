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
#include "IfcPresentationStyleSelect.h"
#include "IfcPresentationStyle.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcFillStyleSelect;
		class IfcBoolean;
		//ENTITY
		class IfcFillAreaStyle : public IfcPresentationStyleSelect, public IfcPresentationStyle
		{
		public:
			IfcFillAreaStyle();
			IfcFillAreaStyle( int id );
			~IfcFillAreaStyle();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcFillAreaStyle"; }


			// IfcPresentationStyle -----------------------------------------------------------
			// attributes:
			//  shared_ptr<IfcLabel>							m_Name;						//optional

			// IfcFillAreaStyle -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcFillStyleSelect> >	m_FillStyles;
			shared_ptr<IfcBoolean>						m_ModelorDraughting;		//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

