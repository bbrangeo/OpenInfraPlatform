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
#include "IfcSegmentIndexSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcArcIndex = LIST [3:3] OF IfcPositiveInteger;
		class IfcArcIndex : public IfcSegmentIndexSelect, public IfcAlignmentP6Type
		{
		public:
			IfcArcIndex();
			~IfcArcIndex();
			virtual const char* classname() const { return "IfcArcIndex"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcArcIndex> readStepData( std::string& arg );
			std::vector<int> m_vec;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

