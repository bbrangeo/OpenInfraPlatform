/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "../model/shared_ptr.h"
#include "../model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "include/IfcDateTimeSelect.h"
#include "include/IfcText.h"
#include "include/IfcMetricValueSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcMetricValueSelect 
		IfcMetricValueSelect::IfcMetricValueSelect() {}
		IfcMetricValueSelect::~IfcMetricValueSelect() {}
		shared_ptr<IfcMetricValueSelect> IfcMetricValueSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcMetricValueSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<Ifc2x3Entity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcMetricValueSelect> type_object = dynamic_pointer_cast<IfcMetricValueSelect>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw Ifc2x3Exception( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcMetricValueSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcMetricValueSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCDATETIMESELECT")== 0 )
				{
					return IfcDateTimeSelect::readStepData( inline_arg, map );
				}
				else if( keyword.compare("IFCTEXT")== 0 )
				{
					return IfcText::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC2X3::IfcMetricValueSelect::readStepData" << std::endl;
				throw Ifc2x3Exception( strs.str() );
			}
			return shared_ptr<IfcMetricValueSelect>();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
