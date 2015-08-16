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
#include "include/IfcSurfaceStyleElementSelect.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// TYPE IfcSurfaceStyleElementSelect 
		IfcSurfaceStyleElementSelect::IfcSurfaceStyleElementSelect() {}
		IfcSurfaceStyleElementSelect::~IfcSurfaceStyleElementSelect() {}
		shared_ptr<IfcSurfaceStyleElementSelect> IfcSurfaceStyleElementSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcSurfaceStyleElementSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcBridgeEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcSurfaceStyleElementSelect> type_object = dynamic_pointer_cast<IfcSurfaceStyleElementSelect>(it_entity->second);
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
				return shared_ptr<IfcSurfaceStyleElementSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcSurfaceStyleElementSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC2X4::IfcSurfaceStyleElementSelect::readStepData" << std::endl;
				throw IfcBridgeException( strs.str() );
			}
			return shared_ptr<IfcSurfaceStyleElementSelect>();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
