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
#include "include/IfcLabel.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcRatioMeasure.h"
#include "include/IfcSurfaceReinforcementArea.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcSurfaceReinforcementArea 
		IfcSurfaceReinforcementArea::IfcSurfaceReinforcementArea() { m_entity_enum = IFCSURFACEREINFORCEMENTAREA; }
		IfcSurfaceReinforcementArea::IfcSurfaceReinforcementArea( int id ) { m_id = id; m_entity_enum = IFCSURFACEREINFORCEMENTAREA; }
		IfcSurfaceReinforcementArea::~IfcSurfaceReinforcementArea() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcSurfaceReinforcementArea::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcSurfaceReinforcementArea> other = dynamic_pointer_cast<IfcSurfaceReinforcementArea>(other_entity);
			if( !other) { return; }
			m_Name = other->m_Name;
			m_SurfaceReinforcement1 = other->m_SurfaceReinforcement1;
			m_SurfaceReinforcement2 = other->m_SurfaceReinforcement2;
			m_ShearReinforcement = other->m_ShearReinforcement;
		}
		void IfcSurfaceReinforcementArea::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCSURFACEREINFORCEMENTAREA" << "(";
			if( m_Name ) { m_Name->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			writeTypeOfRealList( stream, m_SurfaceReinforcement1 );
			stream << ",";
			writeTypeOfRealList( stream, m_SurfaceReinforcement2 );
			stream << ",";
			if( m_ShearReinforcement ) { m_ShearReinforcement->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcSurfaceReinforcementArea::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcSurfaceReinforcementArea::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<4 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcSurfaceReinforcementArea, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>4 ){ std::cout << "Wrong parameter count for entity IfcSurfaceReinforcementArea, expecting 4, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Name = IfcLabel::readStepData( args[0] );
			readTypeOfRealList( args[1], m_SurfaceReinforcement1 );
			readTypeOfRealList( args[2], m_SurfaceReinforcement2 );
			m_ShearReinforcement = IfcRatioMeasure::readStepData( args[3] );
		}
		void IfcSurfaceReinforcementArea::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcStructuralLoadOrResult::setInverseCounterparts( ptr_self_entity );
		}
		void IfcSurfaceReinforcementArea::unlinkSelf()
		{
			IfcStructuralLoadOrResult::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
