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
#include "../model/IfcBridgeObject.h"
#include "../model/IfcBridgeModel.h"
#include "../model/StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        class IfcBridgeReader : public StatusObservable
        {
        public:
            IfcBridgeReader();
            ~IfcBridgeReader();
            virtual void readStreamHeader( std::string& in, shared_ptr<IfcBridgeModel> model ) = 0;
            virtual void readStreamData( std::string& in, std::map<int,shared_ptr<IfcBridgeEntity> >& map ) = 0;

        protected:
            IfcBridgeModel::IfcVersion m_ifc_version;
            std::string m_file_schema;
        };
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform
