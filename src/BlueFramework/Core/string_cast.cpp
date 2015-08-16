/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

// More details
// http://codereview.stackexchange.com/questions/1205/c-string-cast-template-function

#include "string_cast.h"

#include "BlueFramework/Core/bassert.h"
#include <vector>
#include <string>
#include <cstring>
#include <cwchar>
#include <cassert>
#include <string>
#include <windows.h>

namespace BlueFramework
{
	namespace Core
	{
		namespace detail
		{
			std::wstring s2ws(const std::string& source, const eCodePage::Enum codePage)
			{
				BLUE_ASSERT(codePage == eCodePage::ACP, "Invalid code page.");
				unsigned int iCodePage = CP_ACP;

				if (source.empty())
				{
					return std::wstring();
				}

				int length = ::MultiByteToWideChar(iCodePage, 0, source.data(), source.length(), nullptr, 0);
				if (length == 0)
				{
					return std::wstring();
				}

				std::vector<wchar_t> buffer(length);
				::MultiByteToWideChar(iCodePage, 0, source.data(), source.length(), &buffer[0], length);

				return std::wstring(buffer.begin(), buffer.end());
			}
		}

		template<>
		std::wstring string_cast(const std::string& source, const eCodePage::Enum codePage)
		{
			return detail::s2ws(source, codePage);
		}
	}
}