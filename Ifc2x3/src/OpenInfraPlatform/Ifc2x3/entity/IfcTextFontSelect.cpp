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
#include "include/IfcTextFontSelect.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// TYPE IfcTextFontSelect 
		IfcTextFontSelect::IfcTextFontSelect() {}
		IfcTextFontSelect::~IfcTextFontSelect() {}
		shared_ptr<IfcTextFontSelect> IfcTextFontSelect::readStepData( std::string& arg, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcTextFontSelect>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<Ifc2x3Entity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcTextFontSelect> type_object = dynamic_pointer_cast<IfcTextFontSelect>(it_entity->second);
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
				return shared_ptr<IfcTextFontSelect>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcTextFontSelect>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC2X3::IfcTextFontSelect::readStepData" << std::endl;
				throw Ifc2x3Exception( strs.str() );
			}
			return shared_ptr<IfcTextFontSelect>();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
