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
#include "model/IfcTunnelModel.h"
#include "reader/IfcXmlReader.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		void IfcXmlReader::readStreamHeader( std::string& in, shared_ptr<IfcTunnelModel> model )
		{
			// not implemented
		}

		bool IfcXmlReader::readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<IfcTunnelObject> >& map, std::stringstream& warning )
		{
			// not implemented
			return false;
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
