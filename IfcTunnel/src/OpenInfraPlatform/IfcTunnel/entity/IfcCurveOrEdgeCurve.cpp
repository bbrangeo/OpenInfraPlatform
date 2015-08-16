/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <map>
#include "../model/shared_ptr.h"
#include "../model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "include/IfcCurveOrEdgeCurve.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// TYPE IfcCurveOrEdgeCurve 
		IfcCurveOrEdgeCurve::IfcCurveOrEdgeCurve() {}
		IfcCurveOrEdgeCurve::~IfcCurveOrEdgeCurve() {}
		shared_ptr<IfcCurveOrEdgeCurve> IfcCurveOrEdgeCurve::readStepData( std::string& arg, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			// Read SELECT TYPE
			if( arg.size() == 0 ){ return shared_ptr<IfcCurveOrEdgeCurve>(); }
			if( arg[0] == '#' )
			{
				int id=atoi( arg.substr(1,arg.length()-1).c_str() );
				std::map<int,shared_ptr<IfcTunnelEntity> >::const_iterator it_entity = map.find( id );
				if( it_entity != map.end() )
				{
					shared_ptr<IfcCurveOrEdgeCurve> type_object = dynamic_pointer_cast<IfcCurveOrEdgeCurve>(it_entity->second);
					return type_object;
				}
				else
				{
					std::stringstream strs;
					strs << "Object width id " << id << " not found";
					throw IfcTunnelException( strs.str() );
				}
			}
			else if( arg.compare("$")==0 )
			{
				return shared_ptr<IfcCurveOrEdgeCurve>();
			}
			else if( arg.compare("*")==0 )
			{
				return shared_ptr<IfcCurveOrEdgeCurve>();
			}
			else
			{
				// inline arguments
				std::string keyword;
				std::string inline_arg;
				tokenizeInlineArgument( arg, keyword, inline_arg );
				std::stringstream strs;
				strs << "unhandled inline argument: " << arg << " in function IFC4::IfcCurveOrEdgeCurve::readStepData" << std::endl;
				throw IfcTunnelException( strs.str() );
			}
			return shared_ptr<IfcCurveOrEdgeCurve>();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
