/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "Ifc2x3Exception.h"
#include "Ifc2x3Object.h"

namespace OpenInfraPlatform
{
    namespace Ifc2x3
    {
        Ifc2x3Entity::Ifc2x3Entity() : m_id(-1)
        {
        }
        Ifc2x3Entity::Ifc2x3Entity( int id ) : m_id(id)
        {
        }

        Ifc2x3Entity::~Ifc2x3Entity()
        {
        }
        void Ifc2x3Entity::setId( int id )
        {
            m_id = id;
        }

        void Ifc2x3Entity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
        {
            throw Ifc2x3Exception("Ifc2x3Entity::readStepData(), this method should be overwritten");
        }
        void Ifc2x3Entity::getStepLine( std::stringstream& stream ) const
        {
            throw Ifc2x3Exception("Ifc2x3Entity::getStepLine(), this method should be overwritten");
        }

        void Ifc2x3Entity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw Ifc2x3Exception("Ifc2x3Entity::getStepParameter(), this method should be overwritten");
        }

        void Ifc2x3Entity::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self )
        {
            throw Ifc2x3Exception("Ifc2x3Entity::setInverseCounterparts(), this method should be overwritten");
        }

        void Ifc2x3Entity::unlinkSelf()
        {
            throw Ifc2x3Exception("Ifc2x3Entity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace Ifc2x3
} // end namespace OpenInfraPlatform