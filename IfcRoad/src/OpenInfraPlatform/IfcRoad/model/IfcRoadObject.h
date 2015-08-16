/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <sstream>
#include <vector>
#include <map>
#include "../model/shared_ptr.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		enum IfcRoadEntityEnum;

		class IfcRoadObject
		{
		public:
			virtual const char* classname() const
			{
				return "IfcAlignmentObject";
			}
			virtual void getStepData( std::stringstream& ) {};
		};

		class IfcRoadEntity : public IfcRoadObject
		{
		protected:
			int m_id;

		public:
			IfcRoadEntity();
			IfcRoadEntity( int id );
			virtual ~IfcRoadEntity();
			virtual const char* classname() const
			{
				return "IfcAlignmentEntity";
			}
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self );
			virtual void unlinkSelf();
			virtual const int getId() const
			{
				return m_id;
			}
			void setId( int id );
			std::string m_arguments;
			IfcRoadEntityEnum m_entity_enum;
		};

		//// pure abstract class to derive IFC TYPEs from
		class IfcRoadType : public IfcRoadObject
		{
		public:
			virtual const char* classname() const
			{
				return "IfcAlignmentType";
			}
			virtual void getStepData( std::stringstream& ) {};
		};


		//// pure abstract class to derive IFC TYPEs from
		class IfcRoadAbstractSelect
		{
		public:
			virtual const char* classname() const
			{
				return "AbstractSelect";
			}
			virtual void getStepData( std::stringstream& ) {};
		};

		class IfcRoadAbstractEnum
		{
		public:
			virtual const char* classname() const
			{
				return "AbstractEnum";
			}
			virtual void getStepData( std::stringstream& ) {};
		};
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform