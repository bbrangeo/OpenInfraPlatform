/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/
#pragma once

#include <vector>
#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelObject.h"
#include "../model/IfcTunnelModel.h"
#include "../model/StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        class IfcTunnelReader : public StatusObservable
        {
        public:
            IfcTunnelReader();
            ~IfcTunnelReader();
            virtual void readStreamHeader( std::string& in, shared_ptr<IfcTunnelModel> model ) = 0;
            virtual void readStreamData( std::string& in, std::map<int,shared_ptr<IfcTunnelEntity> >& map ) = 0;

        protected:
            IfcTunnelModel::IfcVersion m_ifc_version;
            std::string m_file_schema;
        };
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
