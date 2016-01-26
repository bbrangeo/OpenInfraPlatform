#pragma once

#include "Entity.h"
#include "Attribute.h"
#include "Type.h"
#include <vector>

namespace OpenInfraPlatform
{
	namespace ExpressBinding
	{
		class Schema
		{
		public:
			static Schema& getInstance()
			{
				static Schema instance;
				return instance;
			}

			// Entities
			int getEntityCount() const
			{
				return static_cast<int>(entities_.size());
			}

			void addEntity(const Entity& entity)
			{	
				entities_.push_back(entity);
			}

			Entity getEntityByIndex(int index) const
			{
				return entities_[index];
			}

			// Types
		
			void addType(Type type)
			{ 
				types_.push_back(type); 
			}

			int getTypeCount() const
			{
				return static_cast<int>(types_.size());
			}

			Type getTypeByIndex(int index) const
			{
				return types_[index];
			}

			// Schema

			std::string getName() const 
			{ 
				return name_; 
			}

			void setName(std::string val) 
			{ 
				name_ = val;
			}
			
			std::vector<Entity>		entities_;
			std::vector<Type>		types_;

			std::string				name_;
		};
	}
}

namespace oip
{
	using OpenInfraPlatform::ExpressBinding::Schema;
}