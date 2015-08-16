/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcTunnelException.h"
#include "IfcTunnelObject.h"

namespace OpenInfraPlatform
{
    namespace IfcTunnel
    {
        IfcTunnelEntity::IfcTunnelEntity() : m_id(-1)
        {
        }
        IfcTunnelEntity::IfcTunnelEntity( int id ) : m_id(id)
        {
        }

        IfcTunnelEntity::~IfcTunnelEntity()
        {
        }
        void IfcTunnelEntity::setId( int id )
        {
            m_id = id;
        }

        void IfcTunnelEntity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
        {
            throw IfcTunnelException("IfcTunnelEntity::readStepData(), this method should be overwritten");
        }
        void IfcTunnelEntity::getStepLine( std::stringstream& stream ) const
        {
            throw IfcTunnelException("IfcTunnelEntity::getStepLine(), this method should be overwritten");
        }

        void IfcTunnelEntity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw IfcTunnelException("IfcTunnelEntity::getStepParameter(), this method should be overwritten");
        }

        void IfcTunnelEntity::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self )
        {
            throw IfcTunnelException("IfcTunnelEntity::setInverseCounterparts(), this method should be overwritten");
        }

        void IfcTunnelEntity::unlinkSelf()
        {
            throw IfcTunnelException("IfcTunnelEntity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace IfcTunnel
} // end namespace OpenInfraPlatform