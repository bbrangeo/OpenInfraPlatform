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
#include "IfcAppliedValueSelect.h"
#include "IfcMetricValueSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		class IfcValue;
		class IfcUnit;
		//ENTITY
		class IfcMeasureWithUnit : public IfcAppliedValueSelect, public IfcMetricValueSelect, public IfcAlignmentP6Entity
		{
		public:
			IfcMeasureWithUnit();
			IfcMeasureWithUnit( int id );
			~IfcMeasureWithUnit();

			// method setEntity takes over all attributes from another instance of the class
			virtual void setEntity( shared_ptr<IfcAlignmentP6Entity> other );
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const char* classname() const { return "IfcMeasureWithUnit"; }


			// IfcMeasureWithUnit -----------------------------------------------------------
			// attributes:
			shared_ptr<IfcValue>							m_ValueComponent;
			shared_ptr<IfcUnit>							m_UnitComponent;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

