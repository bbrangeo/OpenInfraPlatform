/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "model/IfcTunnelException.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        IfcTunnelException::IfcTunnelException( std::string reason )
        {
            m_reason = reason;
        }

        IfcTunnelException::IfcTunnelException( std::string reason, const char* function_name )
        {
            m_reason.append( function_name );
            m_reason.append( ": " );
            m_reason.append( reason );
        }

        IfcTunnelException::~IfcTunnelException() throw()
        {

        }

        const char* IfcTunnelException::what() const throw()
        {
            return m_reason.c_str();
        }
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform