/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <vector>
#include <map>
#include <string>
#include "model/Ifc2x3Model.h"
#include "reader/IfcXmlReader.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		void IfcXmlReader::readStreamHeader( std::string& in, shared_ptr<Ifc2x3Model> model )
		{
			// not implemented
		}

		bool IfcXmlReader::readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<Ifc2x3Object> >& map, std::stringstream& warning )
		{
			// not implemented
			return false;
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
