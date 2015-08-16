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
 *
 * - modified by Michael Kern, September 2014
*/
// visual studio
#pragma once
// unix
#ifndef GEOMETRYSETTINGS_H
#define GEOMETRYSETTINGS_H

#include "CarveHeaders.h"

#define GEOM_TOLERANCE  0.0000001
#ifdef _DEBUG
	#define HALF_SPACE_BOX_SIZE 100
#else
	#define HALF_SPACE_BOX_SIZE 100
#endif


namespace OpenInfraPlatform
{
	namespace IfcGeometryConverter
	{

		class GeometrySettings
		{
		public:
			GeometrySettings();
			~GeometrySettings();
			int	m_num_vertices_per_circle;
			int m_min_num_vertices_per_arc;

			double m_min_colinearity;
			double m_min_delta_v;
			double m_min_normal_angle;
			double m_min_length;
			carve::csg::CSG::CLASSIFY_TYPE m_classify_type;
		};
	}
}

#endif

