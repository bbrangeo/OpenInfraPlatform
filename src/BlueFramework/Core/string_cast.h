/*! \verbatim
 *  \copyright      Copyright (c) 2015 Julian Amann. All rights reserved.
 *  \author         Julian Amann <dev@vertexwahn.de> (http://vertexwahn.de/)
 *  \brief          This file is part of the BlueFramework.
 *  \endverbatim
 */

#pragma once
#ifndef BlueFramework_Core_string_cast_449f7477_a1eb_44cd_b196_96dae465060a_h
#define BlueFramework_Core_string_cast_449f7477_a1eb_44cd_b196_96dae465060a_h

#include <string>

namespace BlueFramework
{
	namespace Core
	{
		struct eCodePage
		{
			enum Enum
			{
				ACP
			};
		};
		
		template<typename Td>
		Td string_cast(const std::string& source, const eCodePage::Enum codePage = eCodePage::ACP);

		//! Converts from the current codepage to UTF-16
		template<>
		std::wstring string_cast(const std::string& source, const eCodePage::Enum codePage);
	} // end namespace Core
} // end namespace BlueFramework

namespace buw
{
	using BlueFramework::Core::string_cast;
}

#endif // end define BlueFramework_Core_string_cast_449f7477_a1eb_44cd_b196_96dae465060a_h