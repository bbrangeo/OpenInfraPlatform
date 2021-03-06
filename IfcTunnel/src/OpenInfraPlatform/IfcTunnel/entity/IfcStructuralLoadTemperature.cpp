/*! \verbatim
*  \copyright	Copyright (c) 2014 Julian Amann. All rights reserved.
*  \date		2014-03-05 19:30
*  \author		Julian Amann <julian.amann@tum.de> (https://www.cms.bgu.tum.de/en/team/amann)
*  \brief		This file is part of the BlueFramework.
*  \endverbatim
*/

#include <sstream>
#include <limits>

#include "model/IfcTunnelException.h"
#include "reader/ReaderUtil.h"
#include "writer/WriterUtil.h"
#include "IfcTunnelEntityEnums.h"
#include "include/IfcLabel.h"
#include "include/IfcStructuralLoadTemperature.h"
#include "include/IfcThermodynamicTemperatureMeasure.h"

namespace OpenInfraPlatform
{
	namespace IfcTunnel
	{
		// ENTITY IfcStructuralLoadTemperature 
		IfcStructuralLoadTemperature::IfcStructuralLoadTemperature() { m_entity_enum = IFCSTRUCTURALLOADTEMPERATURE; }
		IfcStructuralLoadTemperature::IfcStructuralLoadTemperature( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADTEMPERATURE; }
		IfcStructuralLoadTemperature::~IfcStructuralLoadTemperature() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadTemperature::setEntity( shared_ptr<IfcTunnelEntity> other_entity )
		{
			shared_ptr<IfcStructuralLoadTemperature> other = dynamic_pointer_cast<IfcStructuralLoadTemperature>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DeltaTConstant = other->m_DeltaTConstant;
			m_DeltaTY = other->m_DeltaTY;
			m_DeltaTZ = other->m_DeltaTZ;
		}
		void IfcStructuralLoadTemperature::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADTEMPERATURE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaTConstant ) { m_DeltaTConstant->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaTY ) { m_DeltaTY->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaTZ ) { m_DeltaTZ->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadTemperature::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadTemperature::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcTunnelEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadTemperature, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcTunnelException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadTemperature, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DeltaTConstant = IfcThermodynamicTemperatureMeasure::readStepData( args[1] );
			m_DeltaTY = IfcThermodynamicTemperatureMeasure::readStepData( args[2] );
			m_DeltaTZ = IfcThermodynamicTemperatureMeasure::readStepData( args[3] );
		}
		void IfcStructuralLoadTemperature::setInverseCounterparts( shared_ptr<IfcTunnelEntity> ptr_self_entity )
		{
			IfcStructuralLoadStatic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadTemperature::unlinkSelf()
		{
			IfcStructuralLoadStatic::unlinkSelf();
		}
	} // end namespace IfcTunnel
} // end namespace OpenInfraPlatform
