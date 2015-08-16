/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "Ifc2x3Reader.h"

namespace OpenInfraPlatform
{
    namespace Ifc2x3
    {
        Ifc2x3Reader::Ifc2x3Reader()
        {
            unsetProgressCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
            m_ifc_version = Ifc2x3Model::UNDEFINED;
        }

        Ifc2x3Reader::~Ifc2x3Reader()
        {
        }
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform