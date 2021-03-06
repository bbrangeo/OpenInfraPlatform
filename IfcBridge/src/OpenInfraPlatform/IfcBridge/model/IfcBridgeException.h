/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:10
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <exception>
#include <string>

#define __FUNC__ __FUNCTION__
#define _func_ __FUNCTION__
#define __func__ __FUNC__

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        class IfcBridgeException : public std::exception
        {
        public:
            IfcBridgeException( std::string reason );
            IfcBridgeException( std::string reason, const char* function_name );
            ~IfcBridgeException() throw();
            virtual const char* what() const throw();

            std::string m_reason;
        };
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform