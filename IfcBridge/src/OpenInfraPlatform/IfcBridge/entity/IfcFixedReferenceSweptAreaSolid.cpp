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
#include "include/IfcAxis2Placement3D.h"
#include "include/IfcCurve.h"
#include "include/IfcDirection.h"
#include "include/IfcFixedReferenceSweptAreaSolid.h"
#include "include/IfcParameterValue.h"
#include "include/IfcPresentationLayerAssignment.h"
#include "include/IfcProfileDef.h"
#include "include/IfcStyledItem.h"

namespace OpenInfraPlatform
{
	namespace IfcBridge
	{
		// ENTITY IfcFixedReferenceSweptAreaSolid 
		IfcFixedReferenceSweptAreaSolid::IfcFixedReferenceSweptAreaSolid() { m_entity_enum = IFCFIXEDREFERENCESWEPTAREASOLID; }
		IfcFixedReferenceSweptAreaSolid::IfcFixedReferenceSweptAreaSolid( int id ) { m_id = id; m_entity_enum = IFCFIXEDREFERENCESWEPTAREASOLID; }
		IfcFixedReferenceSweptAreaSolid::~IfcFixedReferenceSweptAreaSolid() {}

		// method setEntity takes over all attributes from another instance of the class
		void IfcFixedReferenceSweptAreaSolid::setEntity( shared_ptr<IfcBridgeEntity> other_entity )
		{
			shared_ptr<IfcFixedReferenceSweptAreaSolid> other = dynamic_pointer_cast<IfcFixedReferenceSweptAreaSolid>(other_entity);
			if( !other) { return; }
			m_SweptArea = other->m_SweptArea;
			m_Position = other->m_Position;
			m_Directrix = other->m_Directrix;
			m_StartParam = other->m_StartParam;
			m_EndParam = other->m_EndParam;
			m_FixedReference = other->m_FixedReference;
		}
		void IfcFixedReferenceSweptAreaSolid::getStepLine( std::stringstream& stream ) const
		{
			stream << "#" << m_id << "=IFCFIXEDREFERENCESWEPTAREASOLID" << "(";
			if( m_SweptArea ) { stream << "#" << m_SweptArea->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Position ) { stream << "#" << m_Position->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_Directrix ) { stream << "#" << m_Directrix->getId(); } else { stream << "$"; }
			stream << ",";
			if( m_StartParam ) { m_StartParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_EndParam ) { m_EndParam->getStepParameter( stream ); } else { stream << "$"; }
			stream << ",";
			if( m_FixedReference ) { stream << "#" << m_FixedReference->getId(); } else { stream << "$"; }
			stream << ");";
		}
		void IfcFixedReferenceSweptAreaSolid::getStepParameter( std::stringstream& stream, bool ) const { stream << "#" << m_id; }
		void IfcFixedReferenceSweptAreaSolid::readStepData( std::vector<std::string>& args, const std::map<int,shared_ptr<IfcBridgeEntity> >& map )
		{
			const int num_args = (int)args.size();
			if( num_args<6 ){ std::stringstream strserr; strserr << "Wrong parameter count for entity IfcFixedReferenceSweptAreaSolid, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; throw IfcBridgeException( strserr.str().c_str() ); }
			#ifdef _DEBUG
			if( num_args>6 ){ std::cout << "Wrong parameter count for entity IfcFixedReferenceSweptAreaSolid, expecting 6, having " << num_args << ". Object id: " << getId() << std::endl; }
			#endif
			readEntityReference( args[0], m_SweptArea, map );
			readEntityReference( args[1], m_Position, map );
			readEntityReference( args[2], m_Directrix, map );
			m_StartParam = IfcParameterValue::readStepData( args[3] );
			m_EndParam = IfcParameterValue::readStepData( args[4] );
			readEntityReference( args[5], m_FixedReference, map );
		}
		void IfcFixedReferenceSweptAreaSolid::setInverseCounterparts( shared_ptr<IfcBridgeEntity> ptr_self_entity )
		{
			IfcSweptAreaSolid::setInverseCounterparts( ptr_self_entity );
		}
		void IfcFixedReferenceSweptAreaSolid::unlinkSelf()
		{
			IfcSweptAreaSolid::unlinkSelf();
		}
	} // end namespace IfcBridge
} // end namespace OpenInfraPlatform
