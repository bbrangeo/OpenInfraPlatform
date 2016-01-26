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
#include "../Ifc4Entities.h"
#include "../../Ifc4/entity/include/IfcGeometricRepresentationContext.h"
#include "../../Ifc4/model/UnitConverter.h"
#include "../../Ifc4/entity/include/IfcProject.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        //class Ifc4Entity;
        //class IfcProject;
        //class IfcGeometricRepresentationContext;
        //class UnitConverter;

        class Ifc4Model
        {
        public:
            Ifc4Model();
            ~Ifc4Model();

            enum IfcVersion { UNDEFINED, UNKNOWN, IFC2X, IFC2X2, Ifc4, IFC2X4, IfcRoad };

            const std::map<int,shared_ptr<Ifc4Entity> >& getMapIfcObjects() const
            {
                return m_map_entities;
            }
            void insertEntity( shared_ptr<Ifc4Entity> e, bool overwrite_existing = false );
            void removeEntity( shared_ptr<Ifc4Entity> e );
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
            std::map<int,shared_ptr<Ifc4Entity> >		m_map_entities;
            shared_ptr<IfcProject>							m_ifc_project;
            shared_ptr<IfcGeometricRepresentationContext>	m_geom_context_3d;
            shared_ptr<UnitConverter>						m_unit_converter;
            std::string										m_file_header;
            std::string										m_file_schema;
        };
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform