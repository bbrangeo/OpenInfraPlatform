/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "../model/shared_ptr.h"
#include "IfcRoadReader.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        class IfcStepReader : public IfcRoadReader
        {
        public:
            IfcStepReader();
            ~IfcStepReader();
            void readStreamHeader( std::string& in, shared_ptr<IfcRoadModel> model );
            void readStreamData( std::string& in, std::map<int,shared_ptr<IfcRoadEntity> >& map );
            void splitIntoStepLines( std::string& read_in, std::vector<std::string>& step_lines );
            void readStepLines( const std::vector<std::string>& step_lines, std::vector<shared_ptr<IfcRoadEntity> >& target_entity_map );
            void readEntityArguments( const std::vector<shared_ptr<IfcRoadEntity> >& vec_entities, const std::map<int,shared_ptr<IfcRoadEntity> > map_entities );
        };
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform