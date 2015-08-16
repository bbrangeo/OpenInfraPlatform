/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <vector>
#include "shared_ptr.h"

namespace OpenInfraPlatform
{
	namespace IfcRoad
	{
		// @brief: finds the first occurrence of T in vector
		template<class T, class U>
		bool findFirstInVector( std::vector<shared_ptr<U> > vec, shared_ptr<T>& ptr )
		{
			std::vector<shared_ptr<U> >::iterator it_trim = vec.begin();
			for( ; it_trim != vec.end(); ++it_trim )
			{
				shared_ptr<U> item = *(it_trim);
				if( dynamic_pointer_cast<T>(item) )
				{
					ptr = dynamic_pointer_cast<T>(item);
					return true;
				}
			}
			return false;
		}
	} // end namespace IfcRoad
} // end namespace OpenInfraPlatform