/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-02-15 23:00
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcBridgeException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcBridgeEntityEnums.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcReferenceCurve.h"
#include "include/IfcReferencePlacement.h"
#include "include/IfcReferencedSectionedSpine.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcReferencedSectionedSpine 
		IfcReferencedSectionedSpine::IfcReferencedSectionedSpine() { m_entity_enum = IFCREFERENCEDSECTIONEDSPINE; }
		IfcReferencedSectionedSpine::IfcReferencedSectionedSpine( int id ) { m_id = id; m_entity_enum = IFCREFERENCEDSECTIONEDSPINE; }
		IfcReferencedSectionedSpine::~IfcReferencedSectionedSpine() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcReferencedSectionedSpine::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcReferencedSectionedSpine> other = dynamic_pointer_cast<IfcReferencedSectionedSpine>(other_entity);
			if( !other) { return; }
			m_SpineCurve = other->m_SpineCurve;
			m_CrossSections = other->m_CrossSections;
			m_CrossSectionPositions = other->m_CrossSectionPositions;
		}
		void IfcReferencedSectionedSpine::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCREFERENCEDSECTIONEDSPINE" << "(";
			if( m_SpineCurve ) { stream << "#" << m_SpineCurve->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_CrossSections );
			stream << ",";
			writeEntityList( stream, m_CrossSectionPositions );
			stream << ");";
		}
		void IfcReferencedSectionedSpine::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcReferencedSectionedSpine::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcReferencedSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcReferencedSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SpineCurve, map );
			readEntityReferenceList( args[1], m_CrossSections, map );
			readEntityReferenceList( args[2], m_CrossSectionPositions, map );
		}
		void IfcReferencedSectionedSpine::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSolidModel::setInverseCounterparts( ptr_self_entity );
		}
		void IfcReferencedSectionedSpine::unlinkSelf()
		{
			IfcSolidModel::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
