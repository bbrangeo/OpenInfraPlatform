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
    namespace Ifc2x3
    {
        class Ifc2x3Exception : public std::exception
        {
        public:
            Ifc2x3Exception( std::string reason );
            Ifc2x3Exception( std::string reason, const char* function_name );
            ~Ifc2x3Exception() throw();
            virtual const char* what() const throw();

            std::string m_reason;
        };
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform