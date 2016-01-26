/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "Ifc4Reader.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        Ifc4Reader::Ifc4Reader()
        {
            unsetProgressCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
            m_ifc_version = Ifc4Model::UNDEFINED;
        }

        Ifc4Reader::~Ifc4Reader()
        {
        }
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform