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
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPlaneAngleMeasure.h"
#include "include/IfcStructuralLoadSingleDisplacement.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralLoadSingleDisplacement 
		IfcStructuralLoadSingleDisplacement::IfcStructuralLoadSingleDisplacement() { m_entity_enum = IFCSTRUCTURALLOADSINGLEDISPLACEMENT; }
		IfcStructuralLoadSingleDisplacement::IfcStructuralLoadSingleDisplacement( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADSINGLEDISPLACEMENT; }
		IfcStructuralLoadSingleDisplacement::~IfcStructuralLoadSingleDisplacement() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadSingleDisplacement::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadSingleDisplacement> other = dynamic_pointer_cast<IfcStructuralLoadSingleDisplacement>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DisplacementX = other->m_DisplacementX;
			m_DisplacementY = other->m_DisplacementY;
			m_DisplacementZ = other->m_DisplacementZ;
			m_RotationalDisplacementRX = other->m_RotationalDisplacementRX;
			m_RotationalDisplacementRY = other->m_RotationalDisplacementRY;
			m_RotationalDisplacementRZ = other->m_RotationalDisplacementRZ;
		}
		void IfcStructuralLoadSingleDisplacement::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADSINGLEDISPLACEMENT" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementX ) { m_DisplacementX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementY ) { m_DisplacementY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DisplacementZ ) { m_DisplacementZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRX ) { m_RotationalDisplacementRX->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRY ) { m_RotationalDisplacementRY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_RotationalDisplacementRZ ) { m_RotationalDisplacementRZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadSingleDisplacement::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadSingleDisplacement::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<7 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadSingleDisplacement, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>7 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadSingleDisplacement, expecting 7, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DisplacementX = IfcLengthMeasure::readStepData( args[1] );
			m_DisplacementY = IfcLengthMeasure::readStepData( args[2] );
			m_DisplacementZ = IfcLengthMeasure::readStepData( args[3] );
			m_RotationalDisplacementRX = IfcPlaneAngleMeasure::readStepData( args[4] );
			m_RotationalDisplacementRY = IfcPlaneAngleMeasure::readStepData( args[5] );
			m_RotationalDisplacementRZ = IfcPlaneAngleMeasure::readStepData( args[6] );
		}
		void IfcStructuralLoadSingleDisplacement::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcStructuralLoadStatic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadSingleDisplacement::unlinkSelf()
		{
			IfcStructuralLoadStatic::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
