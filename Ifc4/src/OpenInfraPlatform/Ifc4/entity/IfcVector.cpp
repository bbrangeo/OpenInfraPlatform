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
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace Ifc4
	{
		// ENTITY IfcVector 
		IfcVector::IfcVector() { m_entity_enum = IFCVECTOR; }
		IfcVector::IfcVector( int id ) { m_id = id; m_entity_enum = IFCVECTOR; }
		IfcVector::~IfcVector() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVector::setEntity( shared_ptr<Ifc4Entity> other_entity )
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
		void IfcVector::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc4Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc4Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Orientation, map );
			m_Magnitude = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcVector::setInverseCounterparts( shared_ptr<Ifc4Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVector::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc4
} // end namespace OpenInfraPlatform
