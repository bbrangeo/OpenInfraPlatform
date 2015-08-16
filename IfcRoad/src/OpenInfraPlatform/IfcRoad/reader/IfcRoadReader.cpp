/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcRoadReader.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        IfcRoadReader::IfcRoadReader()
        {
            unsetProgressCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
            m_ifc_version = IfcRoadModel::UNDEFINED;
        }

        IfcRoadReader::~IfcRoadReader()
        {
        }
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform