/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <exception>
#include "model/shared_ptr.h"
#include "IfcBridgeReader.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		class IfcXmlReader : public IfcBridgeReader
		{
		public:
			IfcXmlReader();
			~IfcXmlReader();
			void readStreamHeader( std::string& in, shared_ptr<IfcBridgeModel> model );
			bool readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<IfcBridgeObject> >& map, std::stringstream& warning );
		};
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
