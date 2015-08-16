/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <map>
#include "shared_ptr.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        class IfcProject;

        class UnitConverter
        {
        public:
            UnitConverter();
            void setIfcProject( shared_ptr<IfcProject> project);

            double getLengthInMeterFactor()
            {
                return m_length_unit_factor;
            }

            double getAngleInRadianFactor()
            {
                return m_plane_angle_factor;
            }

        private:
            std::map<int, double> m_prefix_map;
            double m_length_unit_factor;
            double m_plane_angle_factor;
        };
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform