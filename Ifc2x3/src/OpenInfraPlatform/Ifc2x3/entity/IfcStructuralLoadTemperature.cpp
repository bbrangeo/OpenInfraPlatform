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
#include "include/IfcStructuralLoadTemperature.h"
#include "include/IfcThermodynamicTemperatureMeasure.h"

namespace OpenInfraPlatform
{
	namespace Ifc2x3
	{
		// ENTITY IfcStructuralLoadTemperature 
		IfcStructuralLoadTemperature::IfcStructuralLoadTemperature() { m_entity_enum = IFCSTRUCTURALLOADTEMPERATURE; }
		IfcStructuralLoadTemperature::IfcStructuralLoadTemperature( int id ) { m_id = id; m_entity_enum = IFCSTRUCTURALLOADTEMPERATURE; }
		IfcStructuralLoadTemperature::~IfcStructuralLoadTemperature() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcStructuralLoadTemperature::setEntity( shared_ptr<Ifc2x3Entity> other_entity )
		{
			shared_ptr<IfcStructuralLoadTemperature> other = dynamic_pointer_cast<IfcStructuralLoadTemperature>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_DeltaT_Constant = other->m_DeltaT_Constant;
			m_DeltaT_Y = other->m_DeltaT_Y;
			m_DeltaT_Z = other->m_DeltaT_Z;
		}
		void IfcStructuralLoadTemperature::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSTRUCTURALLOADTEMPERATURE" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaT_Constant ) { m_DeltaT_Constant->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaT_Y ) { m_DeltaT_Y->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_DeltaT_Z ) { m_DeltaT_Z->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcStructuralLoadTemperature::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcStructuralLoadTemperature::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<Ifc2x3Entity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcStructuralLoadTemperature, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw Ifc2x3Exception( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcStructuralLoadTemperature, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			m_DeltaT_Constant = IfcThermodynamicTemperatureMeasure::readStepData( args[1] );
			m_DeltaT_Y = IfcThermodynamicTemperatureMeasure::readStepData( args[2] );
			m_DeltaT_Z = IfcThermodynamicTemperatureMeasure::readStepData( args[3] );
		}
		void IfcStructuralLoadTemperature::setInverseCounterparts( shared_ptr<Ifc2x3Entity> ptr_self_entity )
		{
			IfcStructuralLoadStatic::setInverseCounterparts( ptr_self_entity );
		}
		void IfcStructuralLoadTemperature::unlinkSelf()
		{
			IfcStructuralLoadStatic::unlinkSelf();
		}
	} // end namespace Ifc2x3
} // end namespace OpenInfraPlatform
