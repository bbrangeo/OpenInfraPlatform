/*! \verbatim
*  \copyright	Copyright (c) 2015 Julian Amann. All rights reserved.
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "OpenInfraPlatform/IfcAlignment/model/IfcAlignmentP6Exception.h"
#include "OpenInfraPlatform/IfcAlignment/reader/ReaderUtil.h"
#include "OpenInfraPlatform/IfcAlignment/writer/WriterUtil.h"
#include "OpenInfraPlatform/IfcAlignment/IfcAlignmentP6EntityEnums.h"
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace IfcAlignment
	{
		// ENTITY IfcVector 
		IfcVector::IfcVector() { m_entity_enum = IFCVECTOR; }
		IfcVector::IfcVector( int id ) { m_id = id; m_entity_enum = IFCVECTOR; }
		IfcVector::~IfcVector() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVector::setEntity( shared_ptr<IfcAlignmentP6Entity> other_entity )
		{
			shared_ptr<IfcVector> other = dynamic_pointer_cast<IfcVector>(other_entity);
			if( !other) { return; }
			m_Orientation = other->m_Orientation;
			m_Magnitude = other->m_Magnitude;
		}
		void IfcVector::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCVECTOR" << "(";
			if( m_Orientation ) { stream << "#" << m_Orientation->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Magnitude ) { m_Magnitude->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcVector::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcVector::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcAlignmentP6Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcAlignmentP6Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Orientation, map );
			m_Magnitude = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcVector::setInverseCounterparts( shared_ptr<IfcAlignmentP6Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVector::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace IfcAlignment
} // end namespace OpenInfraPlatform
