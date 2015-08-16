/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/
#pragma once

#include <vector>
#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcAlignmentP6Object.h"
#include "../model/IfcAlignmentP6Model.h"
#include "../model/StatusObservable.h"

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        class IfcAlignmentReader : public StatusObservable
        {
        public:
            IfcAlignmentReader();
            ~IfcAlignmentReader();
            virtual void readStreamHeader( std::string& in, shared_ptr<IfcAlignmentModel> model ) = 0;
            virtual void readStreamData( std::string& in, std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map ) = 0;

        protected:
            IfcAlignmentModel::IfcVersion m_ifc_version;
            std::string m_file_schema;
        };
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
