/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <vector>
#include <map>
#include <string>
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadModel.h"
#include "OpenInfraPlatform/IfcRoad/reader/IfcXmlReader.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		void IfcXmlReader::readStreamHeader( std::string& in, shared_ptr<IfcRoadModel> model )
		{
			// not implemented
		}

		bool IfcXmlReader::readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<IfcRoadObject> >& map, std::stringstream& warning )
		{
			// not implemented
			return false;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform
