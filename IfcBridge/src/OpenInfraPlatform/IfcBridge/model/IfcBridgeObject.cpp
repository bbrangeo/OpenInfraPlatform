/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcBridgeException.h"
#include "IfcBridgeObject.h"

namespace OpenInfraPlatform
{
    namespace IfcBridge
    {
        IfcBridgeEntity::IfcBridgeEntity() : m_id(-1)
        {
        }
        IfcBridgeEntity::IfcBridgeEntity( int id ) : m_id(id)
        {
        }

        IfcBridgeEntity::~IfcBridgeEntity()
        {
        }
        void IfcBridgeEntity::setId( int id )
        {
            m_id = id;
        }

        void IfcBridgeEntity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
        {
            throw IfcBridgeException("IfcBridgeEntity::readStepData(), this method should be overwritten");
        }
        void IfcBridgeEntity::getStepLine( std::stringstream& stream ) const
        {
            throw IfcBridgeException("IfcBridgeEntity::getStepLine(), this method should be overwritten");
        }

        void IfcBridgeEntity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw IfcBridgeException("IfcBridgeEntity::getStepParameter(), this method should be overwritten");
        }

        void IfcBridgeEntity::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self )
        {
            throw IfcBridgeException("IfcBridgeEntity::setInverseCounterparts(), this method should be overwritten");
        }

        void IfcBridgeEntity::unlinkSelf()
        {
            throw IfcBridgeException("IfcBridgeEntity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace IfcBridge
} // end namespace OpenInfraPlatform