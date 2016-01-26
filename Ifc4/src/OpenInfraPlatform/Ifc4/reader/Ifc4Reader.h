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
#include "../model/Ifc4Object.h"
#include "../model/Ifc4Model.h"
#include "../model/StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        class Ifc4Reader : public StatusObservable
        {
        public:
            Ifc4Reader();
            ~Ifc4Reader();
            virtual void readStreamHeader( std::string& in, shared_ptr<Ifc4Model> model ) = 0;
            virtual void readStreamData( std::string& in, std::map<int,shared_ptr<Ifc4Entity> >& map ) = 0;

        protected:
            Ifc4Model::IfcVersion m_ifc_version;
            std::string m_file_schema;
        };
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform
