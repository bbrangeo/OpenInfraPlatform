#pragma once

#include <string>
#include <vector>

namespace OpenInfraPlatform
{
	namespace ExpressBinding
	{
		enum class eSimpleType
		{
			Unknown,
			Real,
			Boolean,
			Binary,
			Integer,
			Number,
			Logical,
			String,
			Array,
			List,
			Set,
			Enumeration,
			Select
		};

		class Type
		{
		public:
			Type() :
				name_("Unknown"),
				type_(eSimpleType::Unknown),
				containerType_("Unknown")
			{

			}

			std::string getName() const { return name_; }
			void setName(std::string val) { name_ = val; }

			eSimpleType getSimpleType() const { return type_; }
			void setSimpleType(eSimpleType val) { type_ = val; }

			std::string getUnderlyingTypeName() const { return underlyingTypeName_; }
			void setUnderlyingTypeName(const std::string& value) { underlyingTypeName_ = value; }

			std::string getContainerType() const { return containerType_; }
			void setContainerType(const std::string& value) { containerType_ = value; }

			int getContainerCardinalityMin() const { return containerCardinalityMin_; }
			void setContainerCardinalityMin(int val) { containerCardinalityMin_ = val; }
		
			int getContainerCardinalityMax() const { return containerCardinalityMax_; }
			void setContainerCardinalityMax(int val) { containerCardinalityMax_ = val; }
	
			void setTypes(const std::vector<std::string>& types)
			{
				types_ = types;
			}

			std::vector<std::string> getTypes()
			{
				return types_;
			}
		private:
			// Simple types
			std::string name_;
			eSimpleType	type_;

			// User defined types
			std::string underlyingTypeName_;
			
			// Container (list, array) types
			std::string containerType_;
			int	containerCardinalityMin_;
			int	containerCardinalityMax_;

			// Enums
			std::vector<std::string> types_;
		};
	}
}

namespace oip
{
	using OpenInfraPlatform::ExpressBinding::eSimpleType;
	using OpenInfraPlatform::ExpressBinding::Type;
}