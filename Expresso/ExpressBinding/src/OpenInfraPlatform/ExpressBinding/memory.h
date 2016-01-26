#pragma once

#include <memory>
#include <string>
#include <vector>

namespace OpenInfraPlatform
{
	namespace ExpressBinding
	{
		template<typename T>
		using ReferenceCounted = std::shared_ptr<T>;
	}
}

namespace buw
{
	using OpenInfraPlatform::ExpressBinding::ReferenceCounted;
}