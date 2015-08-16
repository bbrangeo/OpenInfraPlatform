/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "OpenInfraPlatform/IfcAlignment/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "include/IfcNormalisedRatioMeasure.h"
#include "include/IfcColourOrFactor.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// TYPE IfcColourOrFactor 
		IfcColourOrFactor::IfcColourOrFactor() {}
		IfcColourOrFactor::~IfcColourOrFactor() {}
		shared_ptr<IfcColourOrFactor> IfcColourOrFactor::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcColourOrFactor>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcAlignmentP6Entity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcColourOrFactor> type_object = dynamic_pointer_cast<IfcColourOrFactor>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcAlignmentP6Exception( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcColourOrFactor>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcColourOrFactor>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				if( keyword.compare("IFCNORMALISEDRATIOMEASURE")== 0 )
				{
					return IfcNormalisedRatioMeasure::readStepData( inline_arg );
				}
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcColourOrFactor::readStepData" << std::endl;
				throw IfcAlignmentP6Exception( strs.str() );
			}
			return shared_ptr<IfcColourOrFactor>();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
