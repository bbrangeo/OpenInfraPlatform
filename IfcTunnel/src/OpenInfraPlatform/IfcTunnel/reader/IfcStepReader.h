/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "../model/shared_ptr.h"
#include "IfcTunnelReader.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        class IfcStepReader : public IfcTunnelReader
        {
        public:
            IfcStepReader();
            ~IfcStepReader();
            void readStreamHeader( std::string& in, shared_ptr<IfcTunnelModel> model );
            void readStreamData( std::string& in, std::map<int,shared_ptr<IfcTunnelEntity> >& map );
            void splitIntoStepLines( std::string& read_in, std::vector<std::string>& step_lines );
            void readStepLines( const std::vector<std::string>& step_lines, std::vector<shared_ptr<IfcTunnelEntity> >& target_entity_map );
            void readEntityArguments( const std::vector<shared_ptr<IfcTunnelEntity> >& vec_entities, const std::map<int,shared_ptr<IfcTunnelEntity> > map_entities );
        };
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform