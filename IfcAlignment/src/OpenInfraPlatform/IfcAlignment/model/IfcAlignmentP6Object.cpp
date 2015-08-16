/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \date		2014-02-15 14:11
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include "IfcAlignmentP6Exception.h"
#include "IfcAlignmentP6Object.h"

namespace OpenInfraPlatform
{
    namespace IfcAlignment
    {
        IfcAlignmentP6Entity::IfcAlignmentP6Entity() : m_id(-1)
        {
        }
        IfcAlignmentP6Entity::IfcAlignmentP6Entity( int id ) : m_id(id)
        {
        }

        IfcAlignmentP6Entity::~IfcAlignmentP6Entity()
        {
        }
        void IfcAlignmentP6Entity::setId( int id )
        {
            m_id = id;
        }

        void IfcAlignmentP6Entity::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
        {
            throw IfcAlignmentP6Exception("IfcAlignmentEntity::readStepData(), this method should be overwritten");
        }
        void IfcAlignmentP6Entity::getStepLine( std::stringstream& stream ) const
        {
            throw IfcAlignmentP6Exception("IfcAlignmentEntity::getStepLine(), this method should be overwritten");
        }

        void IfcAlignmentP6Entity::getStepParameter( std::stringstream& stream, bool ) const
        {
            throw IfcAlignmentP6Exception("IfcAlignmentEntity::getStepParameter(), this method should be overwritten");
        }

        void IfcAlignmentP6Entity::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self )
        {
            throw IfcAlignmentP6Exception("IfcAlignmentEntity::setInverseCounterparts(), this method should be overwritten");
        }

        void IfcAlignmentP6Entity::unlinkSelf()
        {
            throw IfcAlignmentP6Exception("IfcAlignmentEntity::unlinkSelf(), this method should be overwritten");
        }
    } // end namespace IfcAlignment
} // end namespace OpenInfraPlatform