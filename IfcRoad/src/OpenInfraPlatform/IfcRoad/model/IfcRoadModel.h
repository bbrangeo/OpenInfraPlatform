/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <vector>
#include <map>
#include <string>
#include "shared_ptr.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        class IfcRoadEntity;
        class IfcProject;
        class IfcGeometricRepresentationContext;
        class UnitConverter;

        class IfcRoadModel
        {
        public:
            IfcRoadModel();
            ~IfcRoadModel();

            enum IfcVersion { UNDEFINED, UNKNOWN, IFC2X, IFC2X2, IFC2X3, IFC2X4, IFC4 };

            const std::map<int,shared_ptr<IfcRoadEntity> >& getMapIfcObjects() const
            {
                return m_map_entities;
            }
            void insertEntity( shared_ptr<IfcRoadEntity> e, bool overwrite_existing = false );
            void removeEntity( shared_ptr<IfcRoadEntity> e );
            void removeEntity( int entity_id );
            int getMaxUsedEntityId();
            shared_ptr<IfcProject> getIfcProject();
            shared_ptr<IfcGeometricRepresentationContext> getIfcGeometricRepresentationContext3D();
            std::string getFileHeader()
            {
                return m_file_header;
            }
            std::string getFileSchema()
            {
                return m_file_schema;
            }
            shared_ptr<UnitConverter> getUnitConverter()
            {
                return m_unit_converter;
            }

            void setFileHeader( std::string header );
            void setFileSchema( std::string schema );
            void setIfcProject( shared_ptr<IfcProject> project );
            void resolveInverseAttributes();
            void clearIfcModel();
            void initIfcModel();
            void resetIfcModel();
            void updateCache();
            void clearCache();
            void initFileHeader( std::string file_name );

        private:
            std::map<int,shared_ptr<IfcRoadEntity> >	m_map_entities;
            shared_ptr<IfcProject>							m_ifc_project;
            shared_ptr<IfcGeometricRepresentationContext>	m_geom_context_3d;
            shared_ptr<UnitConverter>						m_unit_converter;
            std::string										m_file_header;
            std::string										m_file_schema;
        };
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform