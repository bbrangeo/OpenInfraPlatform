/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "IfcTunnelWriter.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        class IfcStepWriter : public IfcTunnelWriter
        {
        public:
            IfcStepWriter();
            ~IfcStepWriter();
            virtual void writeStream( std::stringstream& stream, shared_ptr<IfcTunnelModel> model );
        };
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform