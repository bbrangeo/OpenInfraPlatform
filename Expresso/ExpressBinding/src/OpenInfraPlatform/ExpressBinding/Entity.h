#pragma once

#include "Attribute.h"

namespace OpenInfraPlatform
{
	namespace ExpressBinding
	{
		class Entity
		{
		public:
			std::string getName() const 
			{ 
				return name_; 
			}

			void setName(const std::string& value)
			{ 
				name_ = value; 
			}

			int getSubtypeCount()
			{
				return static_cast<int>(subtypes_.size());
			}

			void addSubtype(const std::string& subtype)
			{
				subtypes_.push_back(subtype);
			}

			std::string getSubtypeByIndex(const int index)
			{
				return subtypes_[index];
			}

		private:
			std::string name_;

			std::vector<std::string> subtypes_;

			std::vector<Attribute> attributes_;
		};
	}
}

namespace oip
{
	using OpenInfraPlatform::ExpressBinding::Entity;
}