#pragma once

#include "memory.h"

namespace OpenInfraPlatform
{
	namespace ExpressBinding
	{
		class Attribute
		{
		public:
			enum class Cardinality
			{
				Undefined,
				Single,
				Vector,
				Vector2D,
				Vector3D
			};

		//public:
			Attribute(const std::string& name, const std::string& comment = "");

		//private:
			std::string			name_;
			std::string			comment_;
			Cardinality			cardinality_;
		};

		class AttributePrimitive : public Attribute
		{
		public:
			enum class Type
			{
				String,
				Integer,
				Real
			};

		public:
			AttributePrimitive(
				const Type type, 
				const std::string& name, 
				const std::string& comment = "") :
			Attribute(name, comment), primitiveType_(type)
			{
				
			}

			virtual Type getDataType() { return primitiveType_; }

		private:
			Type				primitiveType_;
		};
	}
}

namespace oip
{
	using OpenInfraPlatform::ExpressBinding::AttributePrimitive;
}