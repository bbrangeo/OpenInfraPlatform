/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
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
#include "../IfcBridgeEntities.h"
#include "../../IfcBridge/model/UnitConverter.h"
#include "../../IfcBridge/entity/include/IfcProject.h"
#include "../../IfcBridge/entity/include/IfcGeometricRepresentationContext.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        //class IfcBridgeEntity;
        //class IfcProject;
        //class IfcGeometricRepresentationContext;
        //class UnitConverter;

        class IfcBridgeModel
        {
        public:
            IfcBridgeModel();
            ~IfcBridgeModel();

			enum IfcVersion { UNDEFINED, UNKNOWN, IFC2X, IFC2X2, IFC2X3, IFCBRIDGE, IFC2X4, IFC4 };

            const std::map<int,shared_ptr<IfcBridgeEntity> >& getMapIfcObjects() const
            {
                return m_map_entities;
            }
            void insertEntity( shared_ptr<IfcBridgeEntity> e, bool overwrite_existing = false );
            void removeEntity( shared_ptr<IfcBridgeEntity> e );
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
            std::map<int,shared_ptr<IfcBridgeEntity> >		m_map_entities;
            shared_ptr<IfcProject>							m_ifc_project;
            shared_ptr<IfcGeometricRepresentationContext>	m_geom_context_3d;
            shared_ptr<UnitConverter>						m_unit_converter;
            std::string										m_file_header;
            std::string										m_file_schema;
        };
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform