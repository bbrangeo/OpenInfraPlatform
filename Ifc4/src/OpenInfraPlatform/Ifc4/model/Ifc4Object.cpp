/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "Ifc4Exception.h"
#include "Ifc4Object.h"

namespace OpenInfraPlatform
{
    namespace Ifc4
    {
        Ifc4Entity::Ifc4Entity() : m_id(-1)
        {
        }
        Ifc4Entity::Ifc4Entity( int id ) : m_id(id)
        {
        }

        Ifc4Entity::~Ifc4Entity()
        {
        }
        void Ifc4Entity::setId( int id )
        {
            m_id = id;
        }

        void Ifc4Entity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
        {
            throw Ifc4Exception("Ifc4Entity::readStepData(), this method should be overwritten");
        }
        void Ifc4Entity::getStepLine( std::stringstream& stream ) const
        {
            throw Ifc4Exception("Ifc4Entity::getStepLine(), this method should be overwritten");
        }

        void Ifc4Entity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw Ifc4Exception("Ifc4Entity::getStepParameter(), this method should be overwritten");
        }

        void Ifc4Entity::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self )
        {
            throw Ifc4Exception("Ifc4Entity::setInverseCounterparts(), this method should be overwritten");
        }

        void Ifc4Entity::unlinkSelf()
        {
            throw Ifc4Exception("Ifc4Entity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace Ifc4
} // end namespace OpenInfraPlatform