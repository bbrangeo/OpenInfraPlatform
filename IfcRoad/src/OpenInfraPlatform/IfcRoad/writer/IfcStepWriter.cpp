/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:12
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "OpenInfraPlatform/IfcRoad/model/shared_ptr.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadObject.h"
#include "OpenInfraPlatform/IfcRoad/model/IfcRoadModel.h"
#include "OpenInfraPlatform/IfcRoad/entity/include/IfcProduct.h"
#include "OpenInfraPlatform/IfcRoad/entity/include/IfcProject.h"
#include "OpenInfraPlatform/IfcRoad/writer/IfcStepWriter.h"
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iomanip>
#include <locale.h>

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        IfcStepWriter::IfcStepWriter()
        {
        }

        IfcStepWriter::~IfcStepWriter()
        {
        }

        void IfcStepWriter::writeStream( std::stringstream& stream, shared_ptr<IfcRoadModel> model )
        {
            char* current_numeric_locale = setlocale(LC_NUMERIC, nullptr);
            setlocale(LC_NUMERIC,"C");
			
            stream << model->getFileHeader().c_str();
            stream << "DATA;\n";
			stream << std::setprecision(20);
			stream << std::showpoint;
            const std::map<int,shared_ptr<IfcRoadEntity> >& map = model->getMapIfcObjects();
            std::map<int,shared_ptr<IfcRoadEntity> >::const_iterator it;
            for( it=map.begin(); it!=map.end(); ++it )
            {
                shared_ptr<IfcRoadEntity> obj = it->second;

                if( obj.use_count() < 2 )
                {
                    // entity is referenced only in model map, not by other entities
                    if( !dynamic_pointer_cast<IfcProduct>(obj) && !dynamic_pointer_cast<IfcProject>(obj) )
                    {
                        continue;
                    }
                }
                obj->getStepLine( stream );
                stream << std::endl;
            }

            stream << "ENDSEC;\nEND-ISO-10303-21;\n";

            setlocale(LC_NUMERIC, current_numeric_locale);
        }
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform
