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
#include <sstream>
#include "model/IfcTunnelModel.h"

#include "writer/IfcXmlWriter.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        IfcXmlWriter::IfcXmlWriter()
        {

        }

        IfcXmlWriter::~IfcXmlWriter()
        {

        }

        void IfcXmlWriter::writeStream( std::stringstream& stream, shared_ptr<IfcTunnelModel> model )
        {
            // not implemented
        }
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform