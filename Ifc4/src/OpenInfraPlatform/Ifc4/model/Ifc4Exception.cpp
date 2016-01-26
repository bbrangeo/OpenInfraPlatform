/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "model/Ifc4Exception.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        Ifc4Exception::Ifc4Exception( std::string reason )
        {
            m_reason = reason;
        }

        Ifc4Exception::Ifc4Exception( std::string reason, const char* function_name )
        {
            m_reason.append( function_name );
            m_reason.append( ": " );
            m_reason.append( reason );
        }

        Ifc4Exception::~Ifc4Exception() throw()
        {

        }

        const char* Ifc4Exception::what() const throw()
        {
            return m_reason.c_str();
        }
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform