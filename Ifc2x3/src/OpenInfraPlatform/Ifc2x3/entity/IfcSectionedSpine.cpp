/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-04-26 17:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/Ifc2x3Exception.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "Ifc2x3EntityEnums.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcCompositeCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcSectionedSpine.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcSectionedSpine 
		IfcSectionedSpine::IfcSectionedSpine() { m_entity_enum = IFCSECTIONEDSPINE; }
		IfcSectionedSpine::IfcSectionedSpine( int id ) { m_id = id; m_entity_enum = IFCSECTIONEDSPINE; }
		IfcSectionedSpine::~IfcSectionedSpine() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSectionedSpine::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcSectionedSpine> other = dynamic_pointer_cast<IfcSectionedSpine>(other_entity);
			if( !other) { return; }
			m_SpineCurve = other->m_SpineCurve;
			m_CrossSections = other->m_CrossSections;
			m_CrossSectionPositions = other->m_CrossSectionPositions;
		}
		void IfcSectionedSpine::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSECTIONEDSPINE" << "(";
			if( m_SpineCurve ) { stream << "#" << m_SpineCurve->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_CrossSections );
			stream << ",";
			writeEntityList( stream, m_CrossSectionPositions );
			stream << ");";
		}
		void IfcSectionedSpine::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSectionedSpine::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SpineCurve, map );
			readEntityReferenceList( args[1], m_CrossSections, map );
			readEntityReferenceList( args[2], m_CrossSectionPositions, map );
		}
		void IfcSectionedSpine::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSectionedSpine::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
