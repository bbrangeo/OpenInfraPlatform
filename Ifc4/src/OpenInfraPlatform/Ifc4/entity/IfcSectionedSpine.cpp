/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the OpenInfraPlatform.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/Ifc4/model/Ifc4Exception.h"
#include "OpenInfraPlatform/Ifc4/reader/ReaderUtil.h"
#include "OpenInfraPlatform/Ifc4/writer/WriterUtil.h"
#include "OpenInfraPlatform/Ifc4/Ifc4EntityEnums.h"
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcCompositeCurve.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcSectionedSpine.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcSectionedSpine 
		IfcSectionedSpine::IfcSectionedSpine() { m_entity_enum = IFCSECTIONEDSPINE; }
		IfcSectionedSpine::IfcSectionedSpine( int id ) { m_id = id; m_entity_enum = IFCSECTIONEDSPINE; }
		IfcSectionedSpine::~IfcSectionedSpine() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSectionedSpine::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcSectionedSpine::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcSectionedSpine, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SpineCurve, map );
			readEntityReferenceList( args[1], m_CrossSections, map );
			readEntityReferenceList( args[2], m_CrossSectionPositions, map );
		}
		void IfcSectionedSpine::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSectionedSpine::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
