/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "model/Ifc2x3Exception.h"

namespace OpenInfraPlatform
{
    namespace Ifc2x3
    {
        Ifc2x3Exception::Ifc2x3Exception( std::string reason )
        {
            m_reason = reason;
        }

        Ifc2x3Exception::Ifc2x3Exception( std::string reason, const char* function_name )
        {
            m_reason.append( function_name );
            m_reason.append( ": " );
            m_reason.append( reason );
        }

        Ifc2x3Exception::~Ifc2x3Exception() throw()
        {

        }

        const char* Ifc2x3Exception::what() const throw()
        {
            return m_reason.c_str();
        }
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform