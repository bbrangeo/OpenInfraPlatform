/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <exception>
#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "IfcRoadReader.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		class IfcXmlReader : public IfcRoadReader
		{
		public:
			IfcXmlReader();
			~IfcXmlReader();
			void readStreamHeader( std::string& in, shared_ptr<IfcRoadModel> model );
			bool readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<IfcRoadObject> >& map, std::stringstream& warning );
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
