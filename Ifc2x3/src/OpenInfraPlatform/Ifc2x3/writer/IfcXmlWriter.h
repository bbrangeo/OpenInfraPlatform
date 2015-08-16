/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "Ifc2x3Writer.h"

namespace OpenInfraPlatform
{
    namespace Ifc2x3
    {
        class IfcXmlWriter : public Ifc2x3Writer
        {
        public:
            IfcXmlWriter();
            ~IfcXmlWriter();
            virtual void writeStream( std::stringstream& stream, shared_ptr<Ifc2x3Model> model );
        };
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
