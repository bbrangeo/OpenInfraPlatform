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
#include "Ifc4Reader.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		class IfcXmlReader : public Ifc4Reader
		{
		public:
			IfcXmlReader();
			~IfcXmlReader();
			void readStreamHeader( std::string& in, shared_ptr<Ifc4Model> model );
			bool readStreamData( std::string& in, std::string& file_schema, std::map<int,shared_ptr<Ifc4Object> >& map, std::stringstream& warning );
		};
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
