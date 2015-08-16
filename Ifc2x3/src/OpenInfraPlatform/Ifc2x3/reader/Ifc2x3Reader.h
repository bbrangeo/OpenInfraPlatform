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
#include "../model/Ifc2x3Object.h"
#include "../model/Ifc2x3Model.h"
#include "../model/StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace Ifc2x3
    {
        class Ifc2x3Reader : public StatusObservable
        {
        public:
            Ifc2x3Reader();
            ~Ifc2x3Reader();
            virtual void readStreamHeader( std::string& in, shared_ptr<Ifc2x3Model> model ) = 0;
            virtual void readStreamData( std::string& in, std::map<int,shared_ptr<Ifc2x3Entity> >& map ) = 0;

        protected:
            Ifc2x3Model::IfcVersion m_ifc_version;
            std::string m_file_schema;
        };
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
