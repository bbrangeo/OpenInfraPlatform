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
#include "../Ifc4EntityEnums.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        //enum Ifc4EntityEnum;

        class Ifc4Object
        {
        public:
            virtual const char* classname() const
            {
                return "Ifc4Object";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class Ifc4Entity : public Ifc4Object
        {
        protected:
            int m_id;

        public:
            Ifc4Entity();
            Ifc4Entity( int id );
            virtual ~Ifc4Entity();
            virtual const char* classname() const
            {
                return "Ifc4Entity";
            }
            virtual void getStepLine( std::stringstream& stream ) const;
            virtual void getStepParameter( std::stringstream& stream, bool is_select_type = false ) const;
            virtual void readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map );
            virtual void setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self );
            virtual void unlinkSelf();
            virtual const int getId() const
            {
                return m_id;
            }
            void setId( int id );
            std::string m_arguments;
            Ifc4EntityEnum m_entity_enum;
        };

		//// pure abstract class to derive IFC TYPEs from
        class Ifc4Type : public Ifc4Object
        {
        public:
            virtual const char* classname() const
            {
                return "Ifc4Type";
            }
            virtual void getStepData( std::stringstream& ) {};
        };


		//// pure abstract class to derive IFC TYPEs from
        class Ifc4AbstractSelect
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractSelect";
            }
            virtual void getStepData( std::stringstream& ) {};
        };

        class Ifc4AbstractEnum
        {
        public:
            virtual const char* classname() const
            {
                return "AbstractEnum";
            }
            virtual void getStepData( std::stringstream& ) {};
        };
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform
