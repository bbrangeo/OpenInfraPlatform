/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcRoadException.h"
#include "IfcRoadObject.h"

namespace OpenInfraPlatform
{
    namespace IfcRoad
    {
        IfcRoadEntity::IfcRoadEntity() : m_id(-1)
        {
        }
        IfcRoadEntity::IfcRoadEntity( int id ) : m_id(id)
        {
        }

        IfcRoadEntity::~IfcRoadEntity()
        {
        }
        void IfcRoadEntity::setId( int id )
        {
            m_id = id;
        }

        void IfcRoadEntity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcRoadEntity> >& map )
        {
            throw IfcRoadException("IfcAlignmentEntity::readStepData(), this method should be overwritten");
        }
        void IfcRoadEntity::getStepLine( std::stringstream& stream ) const
        {
            throw IfcRoadException("IfcAlignmentEntity::getStepLine(), this method should be overwritten");
        }

        void IfcRoadEntity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw IfcRoadException("IfcAlignmentEntity::getStepParameter(), this method should be overwritten");
        }

        void IfcRoadEntity::setInverseCounterparts( shared_ptr<IfcRoadEntity> ptr_self )
        {
            throw IfcRoadException("IfcAlignmentEntity::setInverseCounterparts(), this method should be overwritten");
        }

        void IfcRoadEntity::unlinkSelf()
        {
            throw IfcRoadException("IfcAlignmentEntity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace IfcRoad
} // end namespace OpenInfraPlatform