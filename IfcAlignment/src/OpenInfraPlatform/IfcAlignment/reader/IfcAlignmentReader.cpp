/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcAlignmentReader.h"

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        IfcAlignmentReader::IfcAlignmentReader()
        {
            unsetProgressCallBack();
            unsetMessageCallBack();
            unsetErrorCallBack();
            m_ifc_version = IfcAlignmentModel::UNDEFINED;
        }

        IfcAlignmentReader::~IfcAlignmentReader()
        {
        }
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform