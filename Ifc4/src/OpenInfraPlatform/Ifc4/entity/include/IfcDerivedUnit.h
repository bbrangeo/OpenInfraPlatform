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
#include "IfcUnit.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcDerivedUnitElement;
		class IfcDerivedUnitEnum;
		class IfcLabel;
		//ENTITY
		class IfcDerivedUnit : public IfcUnit, public Ifc4Entity
		{
		public:
			IfcDerivedUnit();
			IfcDerivedUnit( int id );
			~IfcDerivedUnit();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<Ifc4Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcDerivedUnit"; }


			// IfcDerivedUnit -----------------------------------------------------------
			// attributes:
			std::vector<shared_ptr<IfcDerivedUnitElement> >	m_Elements;
			shared_ptr<IfcDerivedUnitEnum>					m_UnitType;
			shared_ptr<IfcLabel>								m_UserDefinedType;			//optional
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform

