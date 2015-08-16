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

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        enum IfcTunnelEntityEnum;

        class IfcTunnelObject
        {
        public:
            virtual const char* classname() const
            {
                return "IfcTunnelObject";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class IfcTunnelEntity : public IfcTunnelObject
        {
        protected:
            int m_id;

        public:
            IfcTunnelEntity();
            IfcTunnelEntity( int id );
            virtual ~IfcTunnelEntity();
            virtual const char* classname() const
            {
                return "IfcTunnelEntity";
            }
            virtual void getStepLine( std::stringstream& stream ) const;
            virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
            virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map );
            virtual void setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self );
            virtual void unlinkSelf();
            virtual const int getId() const
            {
                return m_id;
            }
            void setId( int id );
            std::string m_arguments;
            IfcTunnelEntityEnum m_entity_enum;
        };

		//// pure abstract class to derive IFC TYPEs from
        class IfcTunnelType : public IfcTunnelObject
        {
        public:
            virtual const char* classname() const
            {
                return "IfcTunnelType";
            }
            virtual void getStepData( std::stringstream& ) {};
        };


		//// pure abstract class to derive IFC TYPEs from
        class IfcTunnelAbstractSelect
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractSelect";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class IfcTunnelAbstractEnum
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractEnum";
            }
            virtual void getStepData( std::stringstream& ) {};
        };
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform