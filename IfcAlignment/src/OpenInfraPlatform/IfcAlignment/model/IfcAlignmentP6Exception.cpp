/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        IfcAlignmentP6Exception::IfcAlignmentP6Exception( std::string reason )
        {
            m_reason = reason;
        }

        IfcAlignmentP6Exception::IfcAlignmentP6Exception( std::string reason, const char* function_name )
        {
            m_reason.append( function_name );
            m_reason.append( ": " );
            m_reason.append( reason );
        }

        IfcAlignmentP6Exception::~IfcAlignmentP6Exception() throw()
        {

        }

        const char* IfcAlignmentP6Exception::what() const throw()
        {
            return m_reason.c_str();
        }
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform