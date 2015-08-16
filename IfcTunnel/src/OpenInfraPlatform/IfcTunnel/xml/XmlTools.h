/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <sstream>
#include <map>
#include <vector>

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        class XmlDataContainer
        {
        public:
            std::string keyword;
            std::map<std::string, std::string> attributes;
            std::string cdata;
        };

        void findCompleteTag( const char* data, int& begin, int& end );
        int readNextXmlTag( const char* data, std::stringstream& err, XmlDataContainer& container );
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform