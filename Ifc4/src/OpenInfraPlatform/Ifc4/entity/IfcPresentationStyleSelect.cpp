/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <map>
#include "OpenInfraPlatform/Ifc4/model/shared_ptr.h"
#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "include/IfcNullStyle.h"
#include "include/IfcPresentationStyleSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// TYPE IfcPresentationStyleSelect 
		IfcPresentationStyleSelect::IfcPresentationStyleSelect() {}
		IfcPresentationStyleSelect::~IfcPresentationStyleSelect() {}
		shared_ptr<IfcPresentationStyleSelect> IfcPresentationStyleSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcPresentationStyleSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<Ifc4Entity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcPresentationStyleSelect> type_object = dynamic_pointer_cast<IfcPresentationStyleSelect>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw Ifc4Exception( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcPresentationStyleSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcPresentationStyleSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCNULLSTYLE")== 0 )
				{
					return IfcNullStyle::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcPresentationStyleSelect::readStepData" << std::endl;
				throw Ifc4Exception( strs.str() );
			}
			return shared_ptr<IfcPresentationStyleSelect>();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
