/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include "Ifc4Writer.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        class IfcXmlWriter : public Ifc4Writer
        {
        public:
            IfcXmlWriter();
            ~IfcXmlWriter();
            virtual void writeStream( std::stringstream& stream, shared_ptr<Ifc4Model> model );
        };
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform
