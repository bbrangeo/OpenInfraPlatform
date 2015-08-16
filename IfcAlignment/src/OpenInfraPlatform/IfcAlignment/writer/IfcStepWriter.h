/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "IfcAlignmentWriter.h"

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        class IfcStepWriter : public IfcAlignmentWriter
        {
        public:
            IfcStepWriter();
            ~IfcStepWriter();
            virtual void writeStream( std::stringstream& stream, shared_ptr<IfcAlignmentModel> model );
        };
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform