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
#include "include/IfcAxis2Placement.h"
#include "include/IfcClothoid.h"
#include "include/IfcLengthMeasure.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcClothoid 
		IfcClothoid::IfcClothoid() { m_entity_enum = IFCCLOTHOID; }
		IfcClothoid::IfcClothoid( int id ) { m_id = id; m_entity_enum = IFCCLOTHOID; }
		IfcClothoid::~IfcClothoid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcClothoid::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcClothoid> other = dynamic_pointer_cast<IfcClothoid>(other_entity);
			if( !other) { return; }
			m_Position = other->m_Position;
			m_ClothoidConstant = other->m_ClothoidConstant;
		}
		void IfcClothoid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCCLOTHOID" << "(";
			if( m_Position ) { m_Position->getStepParameter( stream, true ); } else { stream << "$"; }
			stream << ",";
			if( m_ClothoidConstant ) { m_ClothoidConstant->getStepParameter( stream ); } else { stream << "$"; }
			stream << ");";
		}
		void IfcClothoid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcClothoid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<2 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcClothoid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>2 ){ std::cout << "Wrong parameter count for entity IfcClothoid, expecting 2, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			m_Position = IfcAxis2Placement::readStepData( args[0], map );
			m_ClothoidConstant = IfcLengthMeasure::readStepData( args[1] );
		}
		void IfcClothoid::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcCurve::setInverseCounterparts( ptr_self_entity );
		}
		void IfcClothoid::unlinkSelf()
		{
			IfcCurve::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
