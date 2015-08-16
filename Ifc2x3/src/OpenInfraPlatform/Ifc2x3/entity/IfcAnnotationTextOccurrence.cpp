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
#include "include/IfcAnnotationTextOccurrence.h"
#include "include/IfcLabel.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcPresentationStyleAssignment.h"
#include "include/IfcRepresentationItem.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcAnnotationTextOccurrence 
		IfcAnnotationTextOccurrence::IfcAnnotationTextOccurrence() { m_entity_enum = IFCANNOTATIONTEXTOCCURRENCE; }
		IfcAnnotationTextOccurrence::IfcAnnotationTextOccurrence( int id ) { m_id = id; m_entity_enum = IFCANNOTATIONTEXTOCCURRENCE; }
		IfcAnnotationTextOccurrence::~IfcAnnotationTextOccurrence() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcAnnotationTextOccurrence::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcAnnotationTextOccurrence> other = dynamic_pointer_cast<IfcAnnotationTextOccurrence>(other_entity);
			if( !other) { return; }
			m_Item = other->m_Item;
			m_Styles = other->m_Styles;
			m_Name = other->m_Name;
		}
		void IfcAnnotationTextOccurrence::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCANNOTATIONTEXTOCCURRENCE" << "(";
			if( m_Item ) { stream << "#" << m_Item->getId(); } else { stream << "$"; }
			stream << ",";
			writeEntityList( stream, m_Styles );
			stream << ",";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcAnnotationTextOccurrence::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcAnnotationTextOccurrence::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<3 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcAnnotationTextOccurrence, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>3 ){ std::cout << "Wrong parameter count for entity IfcAnnotationTextOccurrence, expecting 3, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Item, map );
			readEntityReferenceList( args[1], m_Styles, map );
			m_Name = IfcLabel::readStepData( args[2] );
		}
		void IfcAnnotationTextOccurrence::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcAnnotationOccurrence::setInverseCounterparts( ptr_self_entity );
		}
		void IfcAnnotationTextOccurrence::unlinkSelf()
		{
			IfcAnnotationOccurrence::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
