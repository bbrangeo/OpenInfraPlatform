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
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Model.h"
#include "OpenInfraPlatform/IfcAlignment/reader/IfcXmlReader.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		void IfcXmlReader::readStreamHeader( std::string& in, shared_ptr<IfcAlignmentModel> model )
		{
			// not implemented
		}

		bool IfcXmlReader::readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<IfcAlignmentP6Object> >& map, std::stringstream& warning )
		{
			// not implemented
			return false;
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
