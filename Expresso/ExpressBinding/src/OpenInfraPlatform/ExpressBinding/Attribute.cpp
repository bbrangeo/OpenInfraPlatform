#include "Attribute.h"

OpenInfraPlatform::ExpressBinding::Attribute::Attribute(const std::string& name, const std::string& comment /*= ""*/)
{
	name_ = name;
	comment_ = comment;
	cardinality_ = Cardinality::Undefined;
}