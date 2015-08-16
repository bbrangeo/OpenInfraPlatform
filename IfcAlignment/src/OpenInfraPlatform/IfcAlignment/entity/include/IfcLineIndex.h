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
		// TYPE IfcLineIndex = LIST [2:?] OF IfcPositiveInteger;
		class IfcLineIndex : public IfcSegmentIndexSelect, public IfcAlignmentP6Type
		{
		public:
			IfcLineIndex();
			~IfcLineIndex();
			virtual const char* classname() const { return "IfcLineIndex"; }
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			static shared_ptr<IfcLineIndex> readStepData( std::string& arg );
			std::vector<int> m_vec;
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform

