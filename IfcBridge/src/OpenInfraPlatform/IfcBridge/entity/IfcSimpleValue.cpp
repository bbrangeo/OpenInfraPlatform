/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "include/IfcBoolean.h"
#include "include/IfcDate.h"
#include "include/IfcDateTime.h"
#include "include/IfcDuration.h"
#include "include/IfcIdentifier.h"
#include "include/IfcInteger.h"
#include "include/IfcLabel.h"
#include "include/IfcLogical.h"
#include "include/IfcReal.h"
#include "include/IfcText.h"
#include "include/IfcTime.h"
#include "include/IfcTimeStamp.h"
#include "include/IfcValue.h"
#include "include/IfcSimpleValue.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSimpleValue 
		IfcSimpleValue::IfcSimpleValue() {}
		IfcSimpleValue::~IfcSimpleValue() {}
		shared_ptr<IfcSimpleValue> IfcSimpleValue::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcSimpleValue>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcBridgeEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcSimpleValue> type_object = dynamic_pointer_cast<IfcSimpleValue>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcBridgeException( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcSimpleValue>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcSimpleValue>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCBOOLEAN")== 0 )
				{
					return IfcBoolean::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCDATE")== 0 )
				{
					return IfcDate::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCDATETIME")== 0 )
				{
					return IfcDateTime::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCDURATION")== 0 )
				{
					return IfcDuration::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCIDENTIFIER")== 0 )
				{
					return IfcIdentifier::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCINTEGER")== 0 )
				{
					return IfcInteger::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCLABEL")== 0 )
				{
					return IfcLabel::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCLOGICAL")== 0 )
				{
					return IfcLogical::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCREAL")== 0 )
				{
					return IfcReal::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCTEXT")== 0 )
				{
					return IfcText::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCTIME")== 0 )
				{
					return IfcTime::readStepData( inline_arg );
				}
				else if( keyword.compare("IFCTIMESTAMP")== 0 )
				{
					return IfcTimeStamp::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC2X4::IfcSimpleValue::readStepData" << std::endl;
				throw IfcBridgeException( strs.str() );
			}
			return shared_ptr<IfcSimpleValue>();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
