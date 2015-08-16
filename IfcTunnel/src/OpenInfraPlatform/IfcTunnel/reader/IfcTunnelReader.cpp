/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcTunnelReader.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        IfcTunnelReader::IfcTunnelReader()
        {
            unsetProgressCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
            m_ifc_version = IfcTunnelModel::UNDEFINED;
        }

        IfcTunnelReader::~IfcTunnelReader()
        {
        }
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform