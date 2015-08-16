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
#include <sstream>
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadModel.h"
#include "OpenInfraPlatform/IfcRoad/writer/IfcXmlWriter.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        IfcXmlWriter::IfcXmlWriter()
        {

        }

        IfcXmlWriter::~IfcXmlWriter()
        {

        }

        void IfcXmlWriter::writeStream( std::stringstream& stream, shared_ptr<IfcRoadModel> model )
        {
            // not implemented
        }
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform