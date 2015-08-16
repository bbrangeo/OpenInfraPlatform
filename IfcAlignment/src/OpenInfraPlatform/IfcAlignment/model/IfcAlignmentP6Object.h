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
	namespace IfcAlignment
	{
		enum IfcAlignmentP6EntityEnum;

		class IfcAlignmentP6Object
		{
		public:
			virtual const char* classname() const
			{
				return "IfcAlignmentObject";
			}
			virtual void getStepData( std::stringstream& ) {};
		};

		class IfcAlignmentP6Entity : public IfcAlignmentP6Object
		{
		protected:
			int m_id;

		public:
			IfcAlignmentP6Entity();
			IfcAlignmentP6Entity( int id );
			virtual ~IfcAlignmentP6Entity();
			virtual const char* classname() const
			{
				return "IfcAlignmentEntity";
			}
			virtual void getStepLine( std::stringstream& stream ) const;
			virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
			virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map );
			virtual void setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self );
			virtual void unlinkSelf();
			virtual const int getId() const
			{
				return m_id;
			}
			void setId( int id );
			std::string m_arguments;
			IfcAlignmentP6EntityEnum m_entity_enum;
		};

		//// pure abstract class to derive IFC TYPEs from
		class IfcAlignmentP6Type : public IfcAlignmentP6Object
		{
		public:
			virtual const char* classname() const
			{
				return "IfcAlignmentType";
			}
			virtual void getStepData( std::stringstream& ) {};
		};


		//// pure abstract class to derive IFC TYPEs from
		class IfcAlignmentP6AbstractSelect
		{
		public:
			virtual const char* classname() const
			{
				return "AbstractSelect";
			}
			virtual void getStepData( std::stringstream& ) {};
		};

		class IfcAlignmentP6AbstractEnum
		{
		public:
			virtual const char* classname() const
			{
				return "AbstractEnum";
			}
			virtual void getStepData( std::stringstream& ) {};
		};
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform