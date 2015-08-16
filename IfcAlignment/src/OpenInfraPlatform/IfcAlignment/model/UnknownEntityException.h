/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <exception>
#include <string>

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        class UnknownEntityException : public std::exception
        {
        public:
            UnknownEntityException( std::string keyword )
            {
                m_keyword = keyword;
            }
            ~UnknownEntityException() throw() {}
            virtual const char* what() const throw()
            {
                return m_keyword.c_str();
            }
            std::string m_keyword;
        };
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform