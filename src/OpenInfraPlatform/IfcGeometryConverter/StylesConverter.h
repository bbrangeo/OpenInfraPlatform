/* -*-c++-*- IfcPlusPlus - www.ifcplusplus.com  - Copyright (C) 2011 Fabian Gerold
 *
 * This library is open source and may be redistributed and/or modified under  
 * the terms of the OpenSceneGraph Public License (OSGPL) version 0.0 or 
 * (at your option) any later version.  The full license is in LICENSE file
 * included with this distribution, and on the openscenegraph.org website.
 * 
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the 
 * OpenSceneGraph Public License for more details.
*/
// visual studio
#pragma once
// unix
#ifndef STYLESCONVERTER_H
#define STYLESCONVERTER_H

#include "CarveHeaders.h"
//#include "ReaderSettings.h"
//
//#ifdef IFC4_READER
//
////using namespace BlueFramework::Ifc4;
//#endif
//
//#ifdef IFC2X3_READER
//
////using namespace OpenInfraPlatform::Ifc2x3;
//
//#endif

namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{

		class StylesConverter
		{
		public:
			StylesConverter();
			~StylesConverter();
		};

	}
}

#endif
