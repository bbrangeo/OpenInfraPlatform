/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "model/IfcBridgeException.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        IfcBridgeException::IfcBridgeException( std::string reason )
        {
            m_reason = reason;
        }

        IfcBridgeException::IfcBridgeException( std::string reason, const char* function_name )
        {
            m_reason.append( function_name );
            m_reason.append( ": " );
            m_reason.append( reason );
        }

        IfcBridgeException::~IfcBridgeException() throw()
        {

        }

        const char* IfcBridgeException::what() const throw()
        {
            return m_reason.c_str();
        }
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform