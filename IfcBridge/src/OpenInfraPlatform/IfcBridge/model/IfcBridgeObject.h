/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#pragma once

#include <sstream>
#include <vector>
#include <map>
#include "../model/shared_ptr.h"
#include "../IfcBridgeEntityEnums.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        //enum IfcBridgeEntityEnum;

        class IfcBridgeObject
        {
        public:
            virtual const char* classname() const
            {
                return "IfcBridgeObject";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class IfcBridgeEntity : public IfcBridgeObject
        {
        protected:
            int m_id;

        public:
            IfcBridgeEntity();
            IfcBridgeEntity( int id );
            virtual ~IfcBridgeEntity();
            virtual const char* classname() const
            {
                return "IfcBridgeEntity";
            }
            virtual void getStepLine( std::stringstream& stream ) const;
            virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
            virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map );
            virtual void setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self );
            virtual void unlinkSelf();
            virtual const int getId() const
            {
                return m_id;
            }
            void setId( int id );
            std::string m_arguments;
            IfcBridgeEntityEnum m_entity_enum;
        };

		//// pure abstract class to derive IFC TYPEs from
        class IfcBridgeType : public IfcBridgeObject
        {
        public:
            virtual const char* classname() const
            {
                return "IfcBridgeType";
            }
            virtual void getStepData( std::stringstream& ) {};
        };


		//// pure abstract class to derive IFC TYPEs from
        class IfcBridgeAbstractSelect
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractSelect";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class IfcBridgeAbstractEnum
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractEnum";
            }
            virtual void getStepData( std::stringstream& ) {};
        };
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform