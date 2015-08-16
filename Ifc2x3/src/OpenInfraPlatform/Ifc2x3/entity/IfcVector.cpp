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
#include "include/IfcDirection.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"
#include "include/IfcVector.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcVector 
		IfcVector::IfcVector() { m_entity_enum = IFCVECTOR; }
		IfcVector::IfcVector( int id ) { m_id = id; m_entity_enum = IFCVECTOR; }
		IfcVector::~IfcVector() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcVector::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
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
		void IfcVector::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcVector, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_Orientation, map );
			m_Magnitude = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcVector::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcGeometricRepresentationItem::setInverseCounterparts( ptr_self_entity );
		}
		void IfcVector::unlinkSelf()
		{
			IfcGeometricRepresentationItem::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
